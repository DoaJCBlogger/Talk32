/*
	Talk32: A lightweight unofficial Discord client
	Copyright © 2020 Designing on a juicy cup

	Talk32 is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#define UNICODE

#include <windows.h>
#include <windowsx.h>
#include <initguid.h>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <commctrl.h>
#include <wchar.h>
#include <string>
#include <iostream>
#include <fstream>
#include <codecvt>
#include <vector>
#include <gdiplus.h>

using namespace std;

//Maybe do this for shlobj
//define _WIN32_IE=0x500

#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"
#include "rapidjson/prettywriter.h"
using namespace rapidjson;

#define CURL_STATICLIB
#include "curl\builds\libcurl-vc-x86-release-static-ssl-static-zlib-static-ipv6-sspi\include\curl\curl.h"

LRESULT CALLBACK leftSidebarProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK serverListProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK contentAreaProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK hoverBtnProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK editProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
bool login(bool, bool offlineMode = false);

//Contains a font fix provided by "Christopher Janzon" on stackoverflow.com
//https://stackoverflow.com/a/17075471

#define IDM_USER_LOGIN 1
#define IDM_USER_LOGOUT 2
#define IDM_USER_PROFILE 3
#define IDM_HELP_USERGUIDE 4
#define IDM_REFRESH 5
#define IDM_SETTINGS 6

#define IDC_AUTHTOKENFIELD 7

#define AUTH_TOKEN_FIELD_WIDTH 600

#define MINIMUM_WINDOW_WIDTH 985
#define MINIMUM_WINDOW_HEIGHT 480

enum Page {LoginPage, MainPage};

enum MainPageSubLocation {Channel, Friends, DM, GroupDM, Explore};

Page location = LoginPage;
MainPageSubLocation sublocation = Friends;
unsigned long long selectedServer = -1;
unsigned long long selectedChannel = -1;
unsigned int selectedChannelGroupIdx = 0;
unsigned int selectedChannelIdxWithinGroup = 0;
wstring selectedChannelName = L"";

struct ConfigObj {
	wstring authToken;
	wstring dataDir;
	bool showUserList;
	bool roundServerIcons;
	unsigned int windowX;
	unsigned int windowY;
	unsigned int windowWidth;
	unsigned int windowHeight;
};

ConfigObj config;

bool offlineModeEnabled = false;

WNDPROC oldEditProc;

bool CALLBACK SetFont(HWND child, LPARAM font);
bool RectangleWidthHeight(HDC hdc, int x, int y, int w, int h);
bool RoundRectWidthHeight(HDC hdc, int x, int y, int w, int h, int rw, int rh);
void SetRectXYWidthHeight(RECT* r, long x, long y, long w, long h);
unsigned int getMessageHeight(HDC, unsigned int, wstring);
size_t urlWriteCallback(char*, size_t, size_t, void*);
HWND hwndMainWin, statusBar, authTokenBox, httpResponseLabel, loginBtn, hwndServerList, hwndLeftSidebar, hwndContentArea, offlineBtn;
HBRUSH windowBGBrush, mainGrayColorBrush, discordBlueBtnBrush, discordBlueBtnHoverBrush, discordBlueBtnDownBrush, serverListColorBrush, sidebarColorBrush, serverListHoverColor, serverListSelectedColor;// = (HBRUSH)GetStockObject(WHITE_BRUSH);
std::string data;
std::string BearerToken;
bool BearerTokenIsValid = false;
SYSTEMTIME BearerTokenCreatedTime = {0};
SYSTEMTIME LastRequestTime = {0};

HBITMAP hBmpHomeIcon;
HBITMAP hBmpExploreIcon;
HBITMAP hBmpChannelPoundSign;
HBITMAP hBmpChannelPoundSignLocked;
HBITMAP hBmpChannelPoundSignSelected;
HBITMAP hBmpChannelPoundSignLockedSelected;
HBITMAP hBmpVoiceChannelIcon;
HBITMAP hBmpVoiceChannelLockedIcon;

RECT YouTubeLogoTopBarRect;
RECT locationBarRect;
RECT searchBarRect;
RECT searchBtnRect;
RECT header3BarsRect;
RECT headerHomeLinkRect;
RECT headerTrendingLinkRect;
RECT headerSubscriptionsLinkRect;

bool homeHeaderLinkHover = false;
bool homeHeaderLinkSelected = true;
bool trendingHeaderLinkHover = false;
bool trendingHeaderLinkSelected = false;
bool subscriptionsHeaderLinkHover = false;
bool subscriptionsHeaderLinkSelected = false;

int smallHeaderTextHeight = 0;
HFONT authTokenPromptFont;
HFONT authTokenBoxFont;
HFONT smallInfoFont;
HFONT channelNameFont;
HFONT channelGroupNameFont;
HFONT smallHeaderFont;
HFONT smallHeaderFont500Weight;
HFONT hoverBtnFont;

COLORREF serverListColor = RGB(32, 34, 37);
COLORREF sidebarColor = RGB(47, 49, 54);
COLORREF mainGrayColor = RGB(54, 57, 63);
COLORREF discordBlueBtnColor = RGB(114, 137, 218);
COLORREF discordBlueBtnHoverColor = RGB(103, 123, 196);
COLORREF discordBlueBtnDownColor = RGB(91, 110, 174);
COLORREF channelColor = RGB(142, 146, 151);
COLORREF messageTextColor = RGB(220, 221, 222);
wstring localAppDataPath;
wstring configFilePath;

int scrollPosition = 0;
unsigned int contentAreaWidth;

struct HoverBtnData {
	bool mouseIsOver;
	bool leftBtnDown;
	wstring text;
	HoverBtnData():mouseIsOver(false),leftBtnDown(false),text(L""){}
};

struct ServerListItem {
	wstring name;
	uint64_t id;
	bool unread;
	HBITMAP hbmIcon;
};
struct ServerListData {
	bool leftBtnDown;
	HWND hwndScrollbar;
	int serverHoverIdx;
	long scrollPos;
	vector<ServerListItem> dataModel;
	ServerListData():hwndScrollbar(NULL),serverHoverIdx(-1){}
};

struct ChannelItem {
	wstring name;
	unsigned long long id;
	bool voiceChannel;
	bool locked;
	bool unread;
};

struct ChannelGroup {
	wstring name;
	vector<ChannelItem> channels;
	unsigned long long id;
	bool IsCategory;
	bool IsExpanded;
};

vector<ServerListItem> globalServerIconList;

/*struct LeftSidebarItem {
	wstring name;
	bool unread;
};*/
struct LeftSidebarData {
	bool mouseIsOver;
	bool leftBtnDown;
	HWND hwndScrollbar;
	wstring serverName;
	long scrollPos;
	int selectedIdx;
	int hoverIdx;
	unsigned long long selectedChannelID;
	vector<ChannelGroup> dataModel;
	LeftSidebarData():hwndScrollbar(NULL),scrollPos(0){}
};

struct Message {
	unsigned long long id;
	unsigned long long authorID;
	int messageHeight;
	wstring text;
};

struct ContentAreaData {
	vector<Message> messages;
	HWND hwndScrollbar;
	bool leftBtnDown;
	long scrollPos;
	unsigned long long totalContentHeight;
	ContentAreaData():hwndScrollbar(NULL),scrollPos(0){}
};

void drawAuthPage(HDC hdc, int w, int h) {
	//Save a backup of the original GDI object
	HGDIOBJ originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));

	//Draw the gray background
	SelectObject(hdc, windowBGBrush);
	SetDCPenColor(hdc, RGB(255,255,255));
	SetBkColor(hdc, mainGrayColor);

	SelectObject(hdc, authTokenPromptFont);
	COLORREF originalTextColor = SetTextColor(hdc, RGB(255, 255, 255));
	int centerW = w >> 1;
	int centerH = h >> 1;

	int authTextPromptX = centerW - 210;
	int authTextPromptY = centerH - 150;
	ExtTextOut(hdc, authTextPromptX, authTextPromptY, NULL, NULL, L"Please provide an authorization token", 37, NULL);

	int authTokenBoxX = centerW - (AUTH_TOKEN_FIELD_WIDTH / 2);
	int authTokenBoxY = authTextPromptY + 50;
	RoundRectWidthHeight(hdc, authTokenBoxX - 7, authTokenBoxY - 8, AUTH_TOKEN_FIELD_WIDTH + 16, 36, 8, 8);

	SetWindowPos(authTokenBox, HWND_TOPMOST, authTokenBoxX, authTokenBoxY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	ShowWindow(authTokenBox, SW_SHOW);

	SetWindowPos(loginBtn, HWND_TOPMOST, authTokenBoxX - 7 + (AUTH_TOKEN_FIELD_WIDTH - 85), authTokenBoxY + 40, 100, 36, SWP_NOSIZE | SWP_NOZORDER);
	SetWindowPos(offlineBtn, HWND_TOPMOST, authTokenBoxX - 7 + (AUTH_TOKEN_FIELD_WIDTH - 85) - 135, authTokenBoxY + 40, 125, 36, SWP_NOSIZE | SWP_NOZORDER);

	//Print the instructions for finding the auth token
	SelectObject(hdc, smallInfoFont);
	SetTextColor(hdc, RGB(255,255,255));
	int textX = authTokenBoxX - 7;
	int textY = authTokenBoxY + 100;
	ExtTextOut(hdc, textX, textY, NULL, NULL, L"To find your authorization token (Chrome/Opera/Discord app),", 60, NULL);
	textY += 20;
	ExtTextOut(hdc, textX, textY, NULL, NULL, L"1. Sign in to Discord if you haven't already", 44, NULL);
	textY += 20;
	ExtTextOut(hdc, textX, textY, NULL, NULL, L"2. Press Ctrl+Shift+I", 21, NULL);
	textY += 20;
	ExtTextOut(hdc, authTokenBoxX - 7, textY, NULL, NULL, L"3. Open the Network tab and click \"XHR\"", 39, NULL);
	textY += 20;
	ExtTextOut(hdc, authTokenBoxX - 7, textY, NULL, NULL, L"4. Click any entry under \"Name\" and open the \"Headers\" tab on the right", 71, NULL);
	textY += 20;
	ExtTextOut(hdc, authTokenBoxX - 7, textY, NULL, NULL, L"5. Scroll down to the \"authorization\" entry under \"Request Headers\"", 67, NULL);
	textY += 20;
	ExtTextOut(hdc, authTokenBoxX - 7, textY, NULL, NULL, L"6. Copy and paste the random characters into the field above", 60, NULL);

	SelectObject(hdc, originalGDIObj);
}

void drawMainPage(HDC hdc, int w, int h) {
	//Save a backup of the original GDI object
	HGDIOBJ originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));

	//Draw the gray background
	SelectObject(hdc, windowBGBrush);
	SetDCPenColor(hdc, RGB(255,255,255));
	SetBkColor(hdc, mainGrayColor);
	
	SelectObject(hdc, authTokenPromptFont);
	COLORREF originalTextColor = SetTextColor(hdc, RGB(255, 255, 255));
	
	//The main page has 4 sections from left to right: server icon list, left sidebar, content area, and right sidebar
	//The server icon list width is 72 px + 15 px for the scrollbar
	//The left sidebar width is 240 px + 15 px for the scrollbar
	//The right sidebar is 240 px when viewing a channel and 420 px in the Friends list
	//The content area which takes up the remaining space
	
	contentAreaWidth = w - (72 + 15 + 240 + 15);
	if (sublocation == Friends) {
		contentAreaWidth -= 420;
	} else if ((sublocation == Channel || sublocation == GroupDM) && config.showUserList) {
		contentAreaWidth -= 240;
	}

	SelectObject(hdc, originalGDIObj);
}

//Copied from user 毕晓峰 on StackOverflow
//https://stackoverflow.com/a/35644947
// convert UTF-8 string to wstring
std::wstring utf8_to_wstring(const std::string& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}
// convert wstring to UTF-8 string
std::string wstring_to_utf8(const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}

bool fileExists(LPCWSTR filename) {
	DWORD attr = GetFileAttributes(filename);
	return ((attr != INVALID_FILE_ATTRIBUTES) && !(attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool folderExists(LPCWSTR foldername) {
	DWORD attr = GetFileAttributes(foldername);
	return ((attr != INVALID_FILE_ATTRIBUTES) && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool loadOrCreateConfig() {
	TCHAR szPath[MAX_PATH];
	if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath))) {
		MessageBox(NULL, L"Error: could not call SHGetFolderPath for the local appdata folder.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}
	localAppDataPath = wstring(szPath);
	if (localAppDataPath.at(localAppDataPath.length() - 1) != '\\') localAppDataPath += L"\\";
	localAppDataPath += L"Talk32\\";
	config.dataDir = localAppDataPath;
	configFilePath = localAppDataPath + L"\\config.json";
	
	bool shouldCreateConfigFile = true;
	if (folderExists(localAppDataPath.c_str())) {
		//The data folder already exists
		shouldCreateConfigFile = !fileExists(configFilePath.c_str());
	} else {
		//The data folder doesn't exist yet
		if (!SUCCEEDED(CreateDirectory(localAppDataPath.c_str(), NULL))) {
			wstring error_msg = L"Error: could not create data directory at ";
			error_msg += localAppDataPath;
			MessageBox(NULL, error_msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
			return false;
		}
	}
	
	if (shouldCreateConfigFile) {
		ofstream configFile(configFilePath.c_str(), ios::binary);
		if (!configFile) {
			wstring error_msg = L"Error: could not create config file at ";
			error_msg += configFilePath;
			MessageBox(NULL, error_msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
			return false;
		}
		char c[2] = {'{', '}'};
		configFile.write(c, 2);
		configFile.close();
	} else {
		//Load the config file
		ifstream configFile(configFilePath.c_str(), ios::binary);
		if (!configFile) {
			wstring error_msg = L"Error: could not load config file at ";
			error_msg += configFilePath;
			MessageBox(NULL, error_msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
			return false;
		}
		
		string configJsonStr((istreambuf_iterator<char>(configFile)), istreambuf_iterator<char>());
		Document configDocument;
		configDocument.Parse(configJsonStr.c_str());
		if (configDocument.HasParseError()) {
			wstring error_msg = L"Error parsing config file (at position ";
			long long offset = (unsigned)configDocument.GetErrorOffset();
			error_msg += to_wstring(offset);
			error_msg += L"): ";
			error_msg += utf8_to_wstring(GetParseError_En(configDocument.GetParseError()));
			MessageBox(NULL, error_msg.c_str(), L"", MB_OK);
			return true;
		}

		if (!configDocument.IsObject()) {
			MessageBox(NULL, L"Error parsing config file: root element must be an object.", L"", MB_OK);
			return true;
		}

		//Get the config options from the JSON document

		//token (string)
		rapidjson::Value::ConstMemberIterator iter = configDocument.FindMember("token");
		if (iter != configDocument.MemberEnd()) {
			config.authToken = utf8_to_wstring(configDocument["token"].GetString());
		}

		//showUserList (boolean)
		iter = configDocument.FindMember("showUserList");
		if (iter != configDocument.MemberEnd()) {
			config.showUserList = configDocument["showUserList"].GetBool();
		}

		//round_server_icons (boolean)
		iter = configDocument.FindMember("round_server_icons");
		if (iter != configDocument.MemberEnd()) {
			config.roundServerIcons = configDocument["round_server_icons"].GetBool();
		}

		//Window position (array of x,y,w,h)
		iter = configDocument.FindMember("window_pos");
		if (iter != configDocument.MemberEnd() && configDocument["window_pos"].IsArray()) {
			Value& positionArray = configDocument["window_pos"];
			long long arraySize = positionArray.Size();
			if (arraySize >= 1) config.windowX = configDocument["window_pos"][0].GetUint64();
			if (arraySize >= 2) config.windowY = configDocument["window_pos"][1].GetUint64();
			if (arraySize >= 3) config.windowWidth = configDocument["window_pos"][2].GetUint64();
			if (arraySize >= 4) config.windowHeight = configDocument["window_pos"][3].GetUint64();

			//Validate the window size so it can't go below the minimum
			if (config.windowWidth < MINIMUM_WINDOW_WIDTH) config.windowWidth = MINIMUM_WINDOW_WIDTH;
			if (config.windowHeight < MINIMUM_WINDOW_HEIGHT) config.windowHeight = MINIMUM_WINDOW_HEIGHT;
		}

		configFile.close();
	}

	return true;
}

void saveConfig() {
	TCHAR szPath[MAX_PATH];
	if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath))) {
		MessageBox(NULL, L"Error: could not call SHGetFolderPath for the local appdata folder.", L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	localAppDataPath = wstring(szPath);
	if (localAppDataPath.at(localAppDataPath.length() - 1) != '\\') localAppDataPath += L"\\";
	localAppDataPath += L"Talk32\\";
	configFilePath = localAppDataPath + L"\\config.json";

	GenericDocument<UTF16<> > d;
	d.SetObject();
	Document::AllocatorType& allocator = d.GetAllocator();

	d.AddMember(L"token", StringRef(config.authToken), allocator);
	d.AddMember(L"showUserList", config.showUserList, allocator);
	d.AddMember(L"round_server_icons", config.roundServerIcons, allocator);

	RECT r;
	if (GetWindowRect(hwndMainWin, &r)) {
		config.windowX = r.left;
		config.windowY = r.top;
		config.windowWidth = r.right - r.left;
		config.windowHeight = r.bottom - r.top;
	}

	GenericValue<UTF16<> > windowPos(kArrayType);
	Value::AllocatorType allocator2;
	windowPos.PushBack(config.windowX, allocator2);
	windowPos.PushBack(config.windowY, allocator2);
	windowPos.PushBack(config.windowWidth, allocator2);
	windowPos.PushBack(config.windowHeight, allocator2);

	d.AddMember(L"window_pos", windowPos, allocator2);

	StringBuffer strbuf;
	rapidjson::Writer< StringBuffer, UTF16<> > writer(strbuf);
	//rapidjson::PrettyWriter< PrettyWriter, UTF16<> >(writer);
	d.Accept(writer);

	string json = strbuf.GetString();

	ofstream configFile(configFilePath.c_str(), ios::binary);
	if (!configFile) {
		wstring error_msg = L"Error: could not open config file for writing at ";
		error_msg += configFilePath;
		MessageBox(NULL, error_msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	configFile.write(json.c_str(), json.length());
	configFile.close();
}

void callable(const std::string str) {
	MessageBoxA(NULL, str.c_str(), "", MB_OK);
}

curl_socket_t sock;

curl_socket_t my_opensocketfunc(void *clientp, curlsocktype purpose, struct curl_sockaddr *address){
	return sock=socket(address->family, address->socktype, address->protocol);
}

struct memory {
   char *response;
   size_t size;
};
ofstream logFile;
static size_t cb(void *data, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	logFile.write((char*)data, realsize);
	std::string str = "Just wrote websocket data (";
	str += std::to_string((long long)realsize);
	str += " bytes): ";
	str += (char*)data;
	MessageBoxA(NULL, str.c_str(), "Error", MB_OK | MB_ICONERROR);

	return realsize;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	/*CURL *curl = curl_easy_init();
	struct curl_slist *slist=NULL;
	if (curl) {
		MessageBoxA(NULL, "Curl initialization worked.","",MB_OK);
		logFile = ofstream("C:\\users\\777\\documents\\curl.log", ios::binary);
		if (!logFile) {
			MessageBox(NULL, L"Could not open log file", L"Error", MB_OK | MB_ICONERROR);
		}
		
		slist = curl_slist_append(NULL, "HTTP/1.1 101 WebSocket Protocol Handshake");
		slist = curl_slist_append(slist, "Upgrade: WebSocket");
		slist = curl_slist_append(slist, "Connection: Upgrade");
		slist = curl_slist_append(slist, "Sec-WebSocket-Version: 13");
		slist = curl_slist_append(slist, "Sec-WebSocket-Key: x3JJHMbDL1EzLkh9GBhXDw==");
		
		curl_easy_setopt(curl, CURLOPT_URL, "https://gateway.discord.gg/?v=8&encoding=json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
		curl_easy_setopt(curl, CURLOPT_OPENSOCKETFUNCTION, my_opensocketfunc);
		curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
		//curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, my_func);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
		CURLcode res = curl_easy_perform(curl);
		std::string r = "Discord websocket transfer #1 complete. CURLcode was ";
		r += curl_easy_strerror(res);
		MessageBoxA(NULL, r.c_str(), "", MB_OK);
		curl_easy_cleanup(curl);
		logFile.close();
	}*/
	
	//Initialize the config struct
	config.authToken = L"";
	config.showUserList = true;
	config.roundServerIcons = true;
	config.windowX = 150;
	config.windowY = 150;
	config.windowWidth = 1248;
	config.windowHeight = 892;

	//Load the config file
	if (!loadOrCreateConfig()) return -1;
	if (config.authToken.length() > 0) {
		location = MainPage;
	}
	
	INITCOMMONCONTROLSEX iccx;
	iccx.dwSize=sizeof(INITCOMMONCONTROLSEX);
	iccx.dwICC=0;
	InitCommonControlsEx(&iccx);

	Gdiplus::GdiplusStartupInput gPSI;
	ULONG_PTR gPT;
	Gdiplus::GdiplusStartup(&gPT, &gPSI, NULL);

	MSG  msg ;
	WNDCLASS wc = {0};
	wc.lpszClassName = TEXT("Talk32Mainwin");
	wc.hInstance     = hInstance ;
	windowBGBrush = CreateSolidBrush(mainGrayColor);
	wc.hbrBackground = windowBGBrush;
	wc.lpfnWndProc   = WndProc ;
	//wc.hCursor       = LoadCursor(0, IDC_ARROW);
	RegisterClass(&wc);
	
	serverListColorBrush = CreateSolidBrush(serverListColor);
	sidebarColorBrush = CreateSolidBrush(sidebarColor);
	serverListHoverColor = CreateSolidBrush(RGB(52,55,60));
	serverListSelectedColor = CreateSolidBrush(RGB(57,60,67));
	mainGrayColorBrush = CreateSolidBrush(mainGrayColor);
	discordBlueBtnBrush = CreateSolidBrush(discordBlueBtnColor);
	discordBlueBtnHoverBrush = CreateSolidBrush(discordBlueBtnHoverColor);
	discordBlueBtnDownBrush = CreateSolidBrush(discordBlueBtnDownColor);
	//Register custom control classes
	WNDCLASSW hoverBtnClass = {0};
	hoverBtnClass.lpszClassName = L"DiscordButton";
	hoverBtnClass.hbrBackground = mainGrayColorBrush;
	hoverBtnClass.style = CS_GLOBALCLASS | CS_VREDRAW | CS_HREDRAW;
	hoverBtnClass.lpfnWndProc = hoverBtnProc;
	hoverBtnClass.hCursor = LoadCursor(0, IDC_HAND);
	hoverBtnClass.cbWndExtra = sizeof(HoverBtnData*);
	RegisterClassW(&hoverBtnClass);

	WNDCLASSW serverListClass = {0};
	serverListClass.lpszClassName = L"ServerList";
	serverListClass.hbrBackground = serverListColorBrush;
	serverListClass.style = CS_GLOBALCLASS | CS_VREDRAW;
	serverListClass.lpfnWndProc = serverListProc;
	serverListClass.hCursor = LoadCursor(0, IDC_ARROW);
	serverListClass.cbWndExtra = sizeof(ServerListData*);
	RegisterClassW(&serverListClass);
	
	WNDCLASSW leftSidebarClass = {0};
	leftSidebarClass.lpszClassName = L"LeftSidebar";
	leftSidebarClass.hbrBackground = sidebarColorBrush;
	leftSidebarClass.style = CS_GLOBALCLASS | CS_VREDRAW;
	leftSidebarClass.lpfnWndProc = leftSidebarProc;
	leftSidebarClass.hCursor = LoadCursor(0, IDC_ARROW);
	leftSidebarClass.cbWndExtra = sizeof(LeftSidebarData*);
	RegisterClassW(&leftSidebarClass);

	WNDCLASSW contentAreaClass = {0};
	contentAreaClass.lpszClassName = L"ContentArea";
	contentAreaClass.hbrBackground = mainGrayColorBrush;
	contentAreaClass.style = CS_GLOBALCLASS | CS_VREDRAW;
	contentAreaClass.lpfnWndProc = contentAreaProc;
	contentAreaClass.hCursor = LoadCursor(0, IDC_ARROW);
	contentAreaClass.cbWndExtra = sizeof(ContentAreaData*);
	RegisterClassW(&contentAreaClass);
	
	hwndMainWin = CreateWindowW(wc.lpszClassName, L"Talk32 (Unofficial Client for Discord)", WS_OVERLAPPEDWINDOW | WS_VISIBLE, config.windowX, config.windowY, config.windowWidth, config.windowHeight, 0, 0, hInstance, 0);

	/*if (location == LoginPage) {
		//If we're on the auth page, create the text field and login button
		authTokenBox = CreateWindowW(L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 233, 15, AUTH_TOKEN_FIELD_WIDTH, 20, hwndMainWin, (HMENU)IDC_AUTHTOKENFIELD, NULL, NULL);
		oldEditProc = (WNDPROC)SetWindowLongPtr(authTokenBox, GWLP_WNDPROC, (LONG_PTR)editProc);
		ShowWindow(authTokenBox, SW_HIDE);
		//SendMessage(authTokenBox, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), (LPARAM)1);
		SendMessage(authTokenBox, WM_SETFONT, (WPARAM)authTokenBoxFont, (LPARAM)1);
		
		loginBtn = CreateWindowExW(NULL, L"DiscordButton", L"Log In", WS_CHILD | WS_VISIBLE, 10, 10, 100, 40, hwndMainWin, (HMENU)1, NULL, NULL);
		//ShowWindow(loginBtn, SW_HIDE);
	} else */if (location != LoginPage && config.authToken.length() != 0) {
		login(false);
	}

	while( GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Gdiplus::GdiplusShutdown(gPT);
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwndMainWin, UINT msg, WPARAM wParam, LPARAM lParam) {
	RECT windowRect;
	static RECT scrollAreaRect;
	int width, height;
	HDC hdc;
	HWND hctrlWnd;
	PAINTSTRUCT ps;
	HPEN h_LightGray_Pen, hOldPen;
	HGDIOBJ originalGDIObj;
	static HBRUSH authTokenBoxColor;
	HMENU hRightClickMenu;
	bool windowRectIsValid = false;

	BITMAP bmp;
	HDC bmpHDC;
	LPMINMAXINFO lpMMI;
	
	//Making these static prevents odd drawing errors in WM_PAINT
	static int IBMPlexSansLFHeight, locationBoxX, locationBoxWidth, authTokenBoxX, authTokenBoxWidth;
	static int statusBarParts[3] = {0, 0, 0};
	static POINT mousePosition;
	
	//Header elements
	static HFONT IBMPlexSans;
	
	const unsigned int postWidth = 640;
	const unsigned int rightSidebarWidth = 312;
	unsigned int leftRightPadding;
	unsigned int postToSidebarSpacing = 25;
	unsigned int headerHeight = 49;
	unsigned int postHeight, postY;
	
	switch(msg) {
		case WM_CREATE:
			//Create controls
			
			//Status bar
			statusBar = CreateWindowW(STATUSCLASSNAME, L"Not connected", WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0, hwndMainWin, (HMENU)2 /* change later */, (HINSTANCE)GetWindowLong(hwndMainWin, GWL_HINSTANCE), NULL);
			
			//Create menu bar
			AddMenus(hwndMainWin);
			
			//Load UI elements
			hBmpHomeIcon = (HBITMAP) LoadImageW(NULL, L"img\\home_icon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpExploreIcon = (HBITMAP) LoadImageW(NULL, L"img\\explore_icon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSign = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignLocked = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignSelected = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_selected.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignLockedSelected = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_locked_selected.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpVoiceChannelIcon = (HBITMAP) LoadImageW(NULL, L"img\\voice.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpVoiceChannelLockedIcon = (HBITMAP) LoadImageW(NULL, L"img\\voice_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

			
			//Load fonts
			AddFontResourceEx(L"fonts\\Roboto-Regular.ttf", FR_PRIVATE, NULL);
			AddFontResourceEx(L"fonts\\Roboto-Thin.ttf", FR_PRIVATE, NULL);
			
			authTokenPromptFont = CreateFont(30, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			authTokenBoxFont = CreateFont(20, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			smallInfoFont = CreateFont(18, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto Thin");
			channelNameFont = CreateFont(18, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			channelGroupNameFont = CreateFont(13, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			hoverBtnFont = CreateFont(18, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
		
			if (location == LoginPage) {
				//If we're on the auth page, create the text field and login button
				authTokenBox = CreateWindowW(L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 233, 15, AUTH_TOKEN_FIELD_WIDTH, 20, hwndMainWin, (HMENU)IDC_AUTHTOKENFIELD, NULL, NULL);
				oldEditProc = (WNDPROC)SetWindowLongPtr(authTokenBox, GWLP_WNDPROC, (LONG_PTR)editProc);
				ShowWindow(authTokenBox, SW_HIDE);
				
				loginBtn = CreateWindowExW(NULL, L"DiscordButton", L"Log In", WS_CHILD | WS_VISIBLE, 10, 10, 100, 40, hwndMainWin, (HMENU)1, NULL, NULL);
				offlineBtn = CreateWindowExW(NULL, L"DiscordButton", L"Offline Mode", WS_CHILD | WS_VISIBLE, 60, 10, 125, 40, hwndMainWin, (HMENU)1, NULL, NULL);
			} else if (location != LoginPage && config.authToken.length() != 0) {
				login(false);
			}

			//Apply the correct (non-bold) font to all the UI elements
			EnumChildWindows(hwndMainWin, (WNDENUMPROC)SetFont, (LPARAM)GetStockObject(DEFAULT_GUI_FONT));
			
			//Set the default cursor
			SetCursor(LoadCursor(0, IDC_ARROW));
		break;

		case WM_SIZE:
		{
			windowRectIsValid = GetWindowRect(hwndMainWin, &windowRect);
			RECT r;
			GetClientRect(hwndMainWin, &r);
			int w, h;
			w = r.right - r.left;
			h = r.bottom - r.top;

			//Resize the server list
			MoveWindow(hwndServerList, 0, 0, 72 + 15, h - 22, TRUE);
			
			//Resize the left sidebar
			MoveWindow(hwndLeftSidebar, 72 + 15 + 1, 0, 240 + 15, h - 22, TRUE);
			
			//Resize the content area
			contentAreaWidth = w - (240 + 15 + 72 + 15 + 1) - (config.showUserList ? 240 : 0);
			MoveWindow(hwndContentArea, 240 + 15 + 72 + 15 + 1, 0, contentAreaWidth, h - 22, TRUE);
			
			//Resize the status bar
			SendMessage(statusBar, WM_SIZE, 0, 0);
			if (windowRectIsValid) {
				statusBarParts[0] = 100;
				statusBarParts[1] = 200;
				statusBarParts[2] = 300;
				SendMessage(statusBar, SB_SETPARTS, 3, (LPARAM)&statusBarParts);
				InvalidateRect(hwndMainWin, NULL, true);
			}
			//This is necessary to redraw the auth page when the window is resized on Windows XP
			UpdateWindow(hwndMainWin);
			//RedrawWindow(hwndServerList, NULL, NULL, NULL);
		}
			
		break;
		
		case WM_GETMINMAXINFO:
			lpMMI = (LPMINMAXINFO)lParam;
			//Minimum window width is 985x480
			lpMMI->ptMinTrackSize.x = MINIMUM_WINDOW_WIDTH;
			lpMMI->ptMinTrackSize.y = MINIMUM_WINDOW_HEIGHT;
		break;
		
		case WM_MOUSEWHEEL:
			{
				POINT pt;
				pt.x = GET_X_LPARAM(lParam);
				pt.y = GET_Y_LPARAM(lParam);
				ScreenToClient(hwndMainWin, &pt);
				int xPos = pt.x;
				int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
				//long long f = xPos;
				//MessageBox(NULL, to_wstring(f).c_str(),L"",MB_OK);

				//Only scroll the child window that the cursor is over
				if (xPos <= (72 + 15)) {
					if (zDelta > 0) {
						SendMessage(hwndServerList, WM_VSCROLL, (WPARAM)(SB_LINEUP & 0xffff), NULL);
					} else {
						SendMessage(hwndServerList, WM_VSCROLL, (WPARAM)(SB_LINEDOWN & 0xffff), NULL);
					}
				} else if (xPos > 87 && xPos <= (87 + 240 + 15)) {
					if (zDelta > 0) {
						SendMessage(hwndLeftSidebar, WM_VSCROLL, (WPARAM)(SB_LINEUP & 0xffff), NULL);
					} else {
						SendMessage(hwndLeftSidebar, WM_VSCROLL, (WPARAM)(SB_LINEDOWN & 0xffff), NULL);
					}
				} else if (xPos > (87 + 240 + 15) && xPos <= (87 + 240 + 15 + contentAreaWidth)) {
					if (zDelta > 0) {
						SendMessage(hwndContentArea, WM_VSCROLL, (WPARAM)(SB_LINEUP & 0xffff), NULL);
					} else {
						SendMessage(hwndContentArea, WM_VSCROLL, (WPARAM)(SB_LINEDOWN & 0xffff), NULL);
					}
				}
				return 0;
			}
		break;
		
		case WM_ERASEBKGND:
		case WM_PAINT:
		{
			//Get the window dimensions
			if (!GetWindowRect(hwndMainWin, &windowRect)) break;
			RECT r;
			GetClientRect(hwndMainWin, &r);
			width = r.right - r.left;
			height = r.bottom - r.top;

			hdc = BeginPaint(hwndMainWin, &ps);
			originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
			
			//Draw the auth page by default if there's no auth token
			if (location == LoginPage/*config.authToken.length() == 0*/) {
				drawAuthPage(hdc, width, height);
			} else {
				drawMainPage(hdc, width, height);
			}

			//Cleanup once the paint operation is done
			DeleteObject(authTokenBoxColor);
			SelectObject(hdc, originalGDIObj);
			EndPaint(hwndMainWin, &ps);
		}
		break;

		case WM_COMMAND:
			//Handle the menu commands
			switch(LOWORD(wParam)) {
				case IDM_USER_LOGIN:
				break;
				
				case IDM_USER_LOGOUT:
				break;
				
				case IDM_USER_PROFILE:
				break;
				
				case IDM_HELP_USERGUIDE:
				break;
			}
		break;

		case WM_DESTROY:
			//Save the configuration
			saveConfig();

			DeleteObject(serverListHoverColor);
			DeleteObject(serverListSelectedColor);
			DeleteObject(sidebarColorBrush);
			DeleteObject(serverListColorBrush);
			DeleteObject(mainGrayColorBrush);
			DeleteObject(windowBGBrush);
			DeleteObject(discordBlueBtnDownBrush);
			DeleteObject(discordBlueBtnHoverBrush);
			DeleteObject(discordBlueBtnBrush);

			//Delete images
			DeleteObject(hBmpHomeIcon);
			DeleteObject(hBmpExploreIcon);
			DeleteObject(hBmpChannelPoundSign);
			DeleteObject(hBmpChannelPoundSignLocked);
			DeleteObject(hBmpChannelPoundSignSelected);
			DeleteObject(hBmpChannelPoundSignLockedSelected);
			DeleteObject(hBmpVoiceChannelIcon);
			DeleteObject(hBmpVoiceChannelLockedIcon);
		
			//Delete fonts
			DeleteObject(hoverBtnFont);
			DeleteObject(authTokenPromptFont);
			DeleteObject(authTokenBoxFont);
			DeleteObject(channelGroupNameFont);
			DeleteObject(channelNameFont);
			DeleteObject(smallInfoFont);
			DeleteObject(smallHeaderFont);
			DeleteObject(smallHeaderFont500Weight);
			RemoveFontResourceEx(L"fonts\\Roboto-Regular.ttf", FR_PRIVATE, NULL);
			
			PostQuitMessage(0);
		break;
		
		case WM_CTLCOLORSTATIC:
			hctrlWnd = (HWND)lParam;
		
			//Make sure the text background matches the window background
			return (LRESULT)windowBGBrush;
		break;
		
		case WM_CTLCOLOREDIT:
			hctrlWnd = (HWND)lParam;

			if (hctrlWnd == authTokenBox) {
				hdc = (HDC)wParam;

				//Background when typing
				SetBkColor(hdc, mainGrayColor);
				SetTextColor(hdc, RGB(200, 200, 200));

				//Background when empty
				SetDCBrushColor(hdc, mainGrayColor);
				return (LRESULT)GetStockObject(DC_BRUSH);
			}
		break;
	}
	return DefWindowProc(hwndMainWin, msg, wParam, lParam);
}

bool login(bool clearAuthPage, bool offlineMode) {
	if (!offlineMode && config.authToken.length() == 0) {
		int authTokenLength = GetWindowTextLength(authTokenBox);
		if (!offlineMode && authTokenLength == 0) {
			MessageBox(NULL, L"You have to provide an authorization token.", L"", MB_OK);
			return false;
		}
		TCHAR authTokenTChar[1024];
		GetWindowText(authTokenBox, authTokenTChar, 1024);
		config.authToken = wstring(authTokenTChar);
	}

	wstring cacheDir = config.dataDir + L"cache\\";
	if (!folderExists(cacheDir.c_str())) {
		MessageBox(NULL, L"Error: no cache folder", L"", MB_OK);
		return false;
	}

	wstring cacheJson = cacheDir + L"cache.json";
	if (!fileExists(cacheJson.c_str())) {
		MessageBox(NULL, L"Error: cache.json is missing", L"", MB_OK);
		return false;
	}

	//Set the location so we don't keep repainting the auth page
	location = MainPage;
	offlineModeEnabled = offlineMode;

	//Add "Offline mode" to the status bar
	if (offlineMode) {
		SendMessage(statusBar,SB_SETTEXT, 0, (LPARAM)std::wstring(L"Offline mode").c_str());
	}

	//Load the data model if offline mode is enabled
	if (offlineMode) {
		//Load cache.json from the cache folder in the local appdata subfolder
		ifstream offlineJsonFile(cacheJson.c_str(), ios::binary);
		if (!offlineJsonFile) {
			wstring error_msg = L"Error: could not load cache file at ";
			error_msg += cacheJson;
			MessageBox(NULL, error_msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
			return false;
		}
		
		string cacheJsonStr((istreambuf_iterator<char>(offlineJsonFile)), istreambuf_iterator<char>());
		Document cacheDocument;
		cacheDocument.Parse(cacheJsonStr.c_str());
		if (cacheDocument.HasParseError()) {
			wstring error_msg = L"Error parsing cache file (at position ";
			long long offset = (unsigned)cacheDocument.GetErrorOffset();
			error_msg += to_wstring(offset);
			error_msg += L"): ";
			error_msg += utf8_to_wstring(GetParseError_En(cacheDocument.GetParseError()));
			MessageBox(NULL, error_msg.c_str(), L"", MB_OK);
			return true;
		}

		if (!cacheDocument.IsObject()) {
			MessageBox(NULL, L"Error parsing cache file: root element must be an object.", L"", MB_OK);
			return true;
		}

		//Get the server list from the JSON document
		//servers [array of servers]
		rapidjson::Value::ConstMemberIterator iter = cacheDocument.FindMember("servers");
		if (iter != cacheDocument.MemberEnd() && cacheDocument["servers"].IsArray()) {
			Value& serverArray = cacheDocument["servers"];
			long long arraySize = serverArray.Size();
			Value server;

			//bool shouldAddEntry;
			globalServerIconList.clear();
			ServerListItem sli;
			sli.unread = false;
			Gdiplus::Color serverListBG;
			serverListBG.SetFromCOLORREF(serverListColor);
			for (int i = 0; i < arraySize; i++) {
				//shouldAddEntry = true;
				server = serverArray[i];//.GetUint64();

				//Get the title
				if (!(server.HasMember("title") && server["title"].IsString())) continue;
				sli.name = utf8_to_wstring(server["title"].GetString());

				//Get the id
				if (!(server.HasMember("id") && server["id"].IsUint64())) continue;
				sli.id = server["id"].GetUint64();

				//Get the icon
				if (server.HasMember("icon") && server["icon"].IsString()) {
					wstring iconFilename = cacheDir + L"\\" + to_wstring(sli.id) + L"\\" + utf8_to_wstring(server["icon"].GetString());
					Gdiplus::Bitmap bmp(iconFilename.c_str(), false);
					bmp.GetHBITMAP(serverListBG, &sli.hbmIcon);
				} else {
					sli.hbmIcon = NULL;
				}
				
				globalServerIconList.push_back(sli);
			}
			server.FindMember("id");
		}
	}

	//Clear the auth page if necessary
	if (clearAuthPage) {
		DestroyWindow(authTokenBox);
		DestroyWindow(loginBtn);
		DestroyWindow(offlineBtn);
	}
	//Create the sections of the main page from left to right

	//Server list
	RECT r;
	GetClientRect(hwndMainWin, &r);
	unsigned int width = r.right - r.left;
	unsigned int height = r.bottom - r.top;
	hwndServerList = CreateWindowExW(NULL, L"ServerList", L"Servers", WS_CHILD | WS_VISIBLE, 0, 0, 72 + 15, height - 22, hwndMainWin, (HMENU)1, NULL, NULL);

	//Left sidebar
	hwndLeftSidebar = CreateWindowExW(NULL, L"LeftSidebar", L"Channels", WS_CHILD | WS_VISIBLE, 72 + 15 + 1, 0, 240 + 15, height - 22, hwndMainWin, (HMENU)1, NULL, NULL);

	//Content area
	contentAreaWidth = width - (240 + 15 + 72 + 15 + 1) - (config.showUserList ? 240 : 0);
	hwndContentArea = CreateWindowExW(NULL, L"ContentArea", L"Messages", WS_CHILD | WS_VISIBLE, 240 + 15 + 72 + 15 + 1, 0, contentAreaWidth, height - 22, hwndMainWin, (HMENU)1, NULL, NULL);
	
	//loginBtn = CreateWindowExW(NULL, L"DiscordButton", L"Log In", WS_CHILD | WS_VISIBLE, 10, 10, 100, 40, hwndMainWin, (HMENU)1, NULL, NULL);

	return true;
}

LRESULT CALLBACK leftSidebarProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HGDIOBJ originalGDIObj;
	
	LeftSidebarData* pData = (LeftSidebarData*)GetWindowLongPtr(wnd, 0);
	
	POINT mousePosition;
	
	wchar_t windowName[255];
	
	long long pds;
	
	CREATESTRUCT *cs;

	switch (msg) {
		case WM_NCCREATE:
			pData = new LeftSidebarData();
			if (pData == NULL) return FALSE;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);
			{
				pData->serverName = L"The Hive Mind";

				ChannelGroup cg;
				ChannelItem c;
				cg.name = L"CHAT...";
				c.name = L"swarm only";
				c.unread = false;
				c.locked = true;
				c.voiceChannel = true;
				cg.IsExpanded = true;
				cg.channels.push_back(c);

				c.name = L"soldiers only";
				c.unread = false;
				cg.channels.push_back(c);
				
				c.name = L"colony only";
				c.unread = false;
				cg.channels.push_back(c);
				
				c.name = L"all roles";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"General";
				c.unread = false;
				c.locked = false;
				cg.channels.push_back(c);
				
				c.name = L"Coding";
				c.unread = false;
				c.locked = false;
				cg.channels.push_back(c);
				
				c.name = L"Gaming";
				c.unread = false;
				c.locked = false;
				cg.channels.push_back(c);
				
				c.name = L"afk";
				c.unread = false;
				c.locked = false;
				cg.channels.push_back(c);

				pData->dataModel.push_back(cg);


				cg.channels.clear();

				cg.name = L"MISC...";
				c.name = L"lobby";
				c.unread = true;
				c.locked = false;
				c.voiceChannel = false;
				cg.channels.push_back(c);

				c.name = L"introduce-yourself";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"swarm-only";
				c.unread = false;
				c.locked = true;
				cg.channels.push_back(c);

				c.name = L"soldier-only";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"colony-only";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"general";
				c.unread = false;
				c.locked = false;
				cg.channels.push_back(c);

				c.name = L"videos";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"pics";
				c.unread = false;
				cg.channels.push_back(c);

				c.name = L"voip";
				c.unread = false;
				cg.channels.push_back(c);
				pData->dataModel.push_back(cg);
				
				cg.channels.clear();

				cg.name = L"HACKERSPACE";
				c.name = L"hackerspace";
				c.unread = true;
				c.locked = false;
				c.voiceChannel = false;
				cg.channels.push_back(c);

				c.name = L"hackerspace";
				c.unread = false;
				c.voiceChannel = true;
				cg.channels.push_back(c);
				pData->dataModel.push_back(cg);
				
				cg.channels.clear();
				
				cg.name = L"AREAS OF INTEREST...";
				c.name = L"hardware";
				c.unread = false;
				c.locked = false;
				c.voiceChannel = false;
				cg.channels.push_back(c);
				
				c.name = L"software";
				cg.channels.push_back(c);
				c.name = L"programming";
				cg.channels.push_back(c);
				c.name = L"operating-systems";
				cg.channels.push_back(c);
				c.name = L"networking";
				cg.channels.push_back(c);
				c.name = L"web";
				cg.channels.push_back(c);
				c.name = L"security";
				cg.channels.push_back(c);
				c.name = L"blockchain";
				cg.channels.push_back(c);
				c.name = L"electronics";
				cg.channels.push_back(c);
				c.name = L"micro-controllers";
				cg.channels.push_back(c);
				c.name = L"control-systems";
				cg.channels.push_back(c);
				c.name = L"engineering";
				cg.channels.push_back(c);
				c.name = L"robotics";
				cg.channels.push_back(c);
				c.name = L"radio";
				cg.channels.push_back(c);
				c.name = L"remote-control";
				cg.channels.push_back(c);
				c.name = L"cnc";
				cg.channels.push_back(c);
				c.name = L"laser-cutting";
				cg.channels.push_back(c);
				c.name = L"3d-printing";
				cg.channels.push_back(c);
				c.name = L"space";
				cg.channels.push_back(c);
				c.name = L"art-and-design";
				cg.channels.push_back(c);
				c.name = L"food-and-drink";
				cg.channels.push_back(c);
				pData->dataModel.push_back(cg);
			}
			
			return TRUE;
		break;
		case WM_CREATE:
		{
			RECT r;
			GetClientRect(wnd, &r);
			int height = r.bottom - r.top;
			r.top += 50;
			//r.bottom -= 25;
			r.right -= 15;
			pData->hwndScrollbar = CreateWindowExW(NULL, L"SCROLLBAR",L"", WS_CHILD | SBS_VERT | WS_VISIBLE, r.right, 0, 15, height, wnd, (HMENU)NULL, (HINSTANCE)GetWindowLong(wnd, GWL_HINSTANCE), NULL);
			int w = r.right - r.left;
			MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, height, TRUE);

			unsigned int totalItems = 0;
			for (unsigned int i = 0; i < pData->dataModel.size(); i++) {
				totalItems++;
				if (pData->dataModel.at(i).IsExpanded) 
					for (unsigned int j = 0; j < pData->dataModel.at(i).channels.size(); j++) totalItems++;
			}
			SCROLLINFO si = {0};
			GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE;
			si.nMin = 0;
			si.nMax = ((totalItems + 2) * 32);
			si.nPage = height - 50;
			si.nPos = 0;
			si.nTrackPos = 0;
			SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
		}
		break;
		case WM_NCDESTROY:
			if (pData != NULL) delete pData;
			return 0;
		break;
		case WM_PAINT:
			{
				hdc = BeginPaint(wnd, &ps);
				originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
				
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				//FillRect(hdc, &r, serverListColorBrush);

				MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

				//Redraw the entire list
				{
					//SelectObject(hdc, authTokenBoxFont);
					SetBkColor(hdc, sidebarColor);
					SelectObject(hdc, channelNameFont);

					//Draw the server name
					SetTextColor(hdc, RGB(255, 255, 255));
					ExtTextOut(hdc, 18, 19, NULL, NULL, pData->serverName.c_str(), pData->serverName/*str*/.length(), NULL);
					
					//Draw the line under the server name
					SetDCPenColor(hdc, RGB(37,37,39));
					MoveToEx(hdc, 0, 49, NULL);
					LineTo(hdc, w, 49);
					SetDCPenColor(hdc, RGB(44,46,50));
					MoveToEx(hdc, 0, 50, NULL);
					LineTo(hdc, w, 50);

					//Draw the down arrow beside the server name
					SetDCPenColor(hdc, RGB(213,214,215));
					MoveToEx(hdc, 212, 23, NULL);
					LineTo(hdc, 217, 28);
					MoveToEx(hdc, 211, 23, NULL);
					LineTo(hdc, 216, 28);
					MoveToEx(hdc, 216, 28, NULL);
					LineTo(hdc, 222, 22);
					MoveToEx(hdc, 217, 28, NULL);
					LineTo(hdc, 223, 22);

					//Draw the channels
					unsigned int channelGroupCount = pData->dataModel.size();
					int idx = 0;
					bool shouldStopDrawingChannels = false;
					BITMAP bmp;
					HDC iconHDC;
					HBITMAP channelIcon;
					iconHDC = CreateCompatibleDC(hdc);
					
					//Get the starting position
					unsigned int startingChannelGroup = 0;
					unsigned int startingChannelWithinGroup = -1;
					bool shouldStopSearchingForStartPosition = false;
					unsigned int pixels = -32;//If this starts at 0 then the left sidebar will ignore the first downward tick of the scroll wheel.
					for (unsigned int i = 0; i < pData->dataModel.size() && !shouldStopSearchingForStartPosition; i++) {
						startingChannelGroup = i;
						pixels += 32;
						shouldStopSearchingForStartPosition = (pixels >= pData->scrollPos);
						startingChannelWithinGroup = -1;
						if (pData->dataModel.at(i).IsExpanded) {
							for (unsigned int j = 0; j < pData->dataModel.at(i).channels.size() && !shouldStopSearchingForStartPosition; j++) {
								startingChannelWithinGroup = j;
								pixels += 32;
								shouldStopSearchingForStartPosition = (pixels >= pData->scrollPos);
							}
						}
					}

					for (unsigned int i = startingChannelGroup; (i < channelGroupCount) && !shouldStopDrawingChannels; i++) {
						if (startingChannelWithinGroup == -1) {
							//Draw the channel group/category name
							SetTextColor(hdc, pData->hoverIdx == idx ? RGB(255, 255, 255) : channelColor);
							SetDCPenColor(hdc, sidebarColor);
							SetBkColor(hdc, sidebarColor);
							SelectObject(hdc, channelGroupNameFont);
							
							//Clear any background that may have been drawn before
							//serverListHoverColor, serverListSelectedColor
							SetDCPenColor(hdc, sidebarColor);
							SelectObject(hdc, sidebarColorBrush);
							SetDCPenColor(hdc, sidebarColor);
							SetBkColor(hdc, sidebarColor);
							Rectangle(hdc, 0, (idx * 32) + 50, 232, (idx * 32) + 50 + 32 + 32);
							
							ExtTextOut(hdc, 12, (idx * 32) + 50 + 7 + 8, NULL, NULL, pData->dataModel.at(i).name.c_str(), pData->dataModel.at(i).name.length(), NULL);
							
							//Draw the sideways or down-facing arrow beside the channel group
							if (pData->dataModel.at(i).IsExpanded) {
								//Draw the down-facing arrow
								SetDCPenColor(hdc, pData->hoverIdx == idx ? RGB(188,188,190) : RGB(125,128,133));
								MoveToEx(hdc, 4, (idx * 32) + 50 + 15 + 5, NULL);
								LineTo(hdc, 7, (idx * 32) + 50 + 15 + 3 + 5);
								MoveToEx(hdc, 7, (idx * 32) + 50 + 15 + 2 + 5, NULL);
								LineTo(hdc, 10, (idx * 32) + 50 + 15 - 1 + 5);
							} else {
								//Draw the right-facing arrow
								SetDCPenColor(hdc, pData->hoverIdx == idx ? RGB(188,188,190) : RGB(125,128,133));
								MoveToEx(hdc, 5, (idx * 32) + 50 + 15 + 5 - 2, NULL);
								LineTo(hdc, 8, (idx * 32) + 50 + 15 + 3 + 5 - 2);
								MoveToEx(hdc, 5, (idx * 32) + 50 + 15 + 2 + 5 + 1, NULL);
								LineTo(hdc, 8, (idx * 32) + 50 + 15 - 1 + 5 + 1);
							}
							
							idx++;
							startingChannelWithinGroup = 0;
							
							//Because this group is collaped, we don't want to draw the channels
							if (!pData->dataModel.at(i).IsExpanded) {
								startingChannelWithinGroup = -1;
								continue;
							}
						}
						

						//Don't draw channels in a collapsed channel group
						if (!pData->dataModel.at(i).IsExpanded) continue;

						//Draw the channels
						SelectObject(hdc, channelNameFont);
						for (unsigned int j = startingChannelWithinGroup; j < pData->dataModel.at(i).channels.size(); j++) {
							//Don't keep drawing past the bottom of the list
							if (((idx * 32) + 50) > h) {
								shouldStopDrawingChannels = true;
								break;
							}

							//Draw the channel name
							SetTextColor(hdc, pData->dataModel.at(i).channels.at(j).unread ? RGB(255, 255, 255) : channelColor);
							
							//Draw the hover or selection background, if necessary
							//Clear any background that may have been drawn before
							//serverListHoverColor, serverListSelectedColor
							SetDCPenColor(hdc, sidebarColor);
							SelectObject(hdc, sidebarColorBrush);
							SetDCPenColor(hdc, sidebarColor);
							SetBkColor(hdc, sidebarColor);
							Rectangle(hdc, 0, (idx * 32) + 50, 232, (idx * 32) + 50 + 32 + 32);

							if (pData->hoverIdx == idx) {
								SetDCPenColor(hdc, RGB(52,55,60));
								SetBkColor(hdc, RGB(52,55,60));
								SelectObject(hdc, serverListHoverColor);
								SetTextColor(hdc, RGB(220,221,222));
								//Rectangle(hdc, 15, (idx * 32) + 50 + 32, 232, (idx * 32) + 50 + 32 + 32);
								RoundRectWidthHeight(hdc, 15, (idx * 32) + 50, 217, 32, 8, 8);
							}
							
							ExtTextOut(hdc, 42, (idx * 32) + 50 + 7, NULL, NULL, pData->dataModel.at(i).channels.at(j).name.c_str(), pData->dataModel.at(i).channels.at(j).name.length(), NULL);

							//Draw the channel icon
							/*hBmpChannelPoundSign;
							hBmpChannelPoundSignLocked;
							hBmpChannelPoundSignSelected;
							hBmpChannelPoundSignLockedSelected;
							hBmpVoiceChannelIcon;
							hBmpVoiceChannelLockedIcon;*/
							
							if (pData->selectedChannelID == pData->dataModel.at(i).channels.at(j).id) {
								//The channel is selected
							} else {
								//The channel is not selected
								if (pData->dataModel.at(i).channels.at(j).locked) {
									//The channel is locked but not selected
									if (pData->dataModel.at(i).channels.at(j).voiceChannel) {
										//The channel is a locked voice channel but is not selected
										channelIcon = hBmpVoiceChannelLockedIcon;
									} else {
										//The channel is a locked text channel but is not selected
										channelIcon = hBmpChannelPoundSignLocked;
									}
								} else {
									//The channel is unlocked and not selected
									if (pData->dataModel.at(i).channels.at(j).voiceChannel) {
										//The channel is an unlocked voice channel and is not selected
										channelIcon = hBmpVoiceChannelIcon;
									} else {
										//The channel is an unlocked text channel and is not selected
										channelIcon = hBmpChannelPoundSign;
									}
								}
							}
							SelectObject(iconHDC, channelIcon);
							GetObject(hBmpHomeIcon, sizeof(bmp), &bmp);
							BitBlt(hdc, 20, (idx * 32) + 50 + 1 + 7, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
							
							//Draw the half circle if the server is marked unread
							if (pData->dataModel.at(i).channels.at(j).unread) {
								SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
								SetDCPenColor(hdc, RGB(255, 255, 255));
								Ellipse(hdc, -4, (idx * 32) + 50 + 5 + 7, 4, (idx * 32) + 50 + 5 + 8 + 7);
							}
							
							idx++;
						}
						startingChannelWithinGroup = -1; // We have to set this or only the first channel group will be drawn.
					}
					
					//If the last channel group is collapsed, we need to erase the spaces that should now be empty
					SetDCPenColor(hdc, sidebarColor);
					SelectObject(hdc, sidebarColorBrush);
					SetDCPenColor(hdc, sidebarColor);
					SetBkColor(hdc, sidebarColor);
					while (((idx * 32) + 50) <= h) {
						Rectangle(hdc, 0, (idx * 32) + 50, 232, (idx * 32) + 50 + 32 + 32);
						idx++;
					}
					
					//We have to delete the icon device context or the wrong icons will be drawn if the window is minimized and restored.
					DeleteDC(iconHDC);
				}
				SelectObject(hdc, originalGDIObj);
				EndPaint(wnd, &ps);
			}
		break;
		case WM_MOUSEMOVE:
			{
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				POINT mousePosition;
				mousePosition.x = xPos;
				mousePosition.y = yPos;
				int oldHoverIdx = pData->hoverIdx;
				if (mousePosition.y >= 50) {
					pData->hoverIdx = ((mousePosition.y - 50) >> 5); // >>5 divides by 32
				} else {
					pData->hoverIdx = -1;
				}
				if (oldHoverIdx != pData->hoverIdx) InvalidateRect(wnd, NULL, TRUE);
			}
			
		break;
		case WM_MOUSELEAVE:
			pData->mouseIsOver = false;
			//InvalidateRect(wnd, NULL, TRUE);
			return 0;
		break;
		case WM_LBUTTONDOWN:
			pData->leftBtnDown = true;
			//InvalidateRect(wnd, NULL, TRUE);
		break;
		case WM_LBUTTONUP:
			pData->leftBtnDown = false;
			//InvalidateRect(wnd, NULL, TRUE);
			{
				pData->leftBtnDown = false;
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				POINT mousePosition;
				mousePosition.x = xPos;
				mousePosition.y = yPos;

				wstring p = L"";
				if (yPos < 50) {
					//The user clicked in the server name area
					HMENU hRightClickMenu = CreatePopupMenu();
					ClientToScreen(wnd, &mousePosition);
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Boost");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Mark As Read");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Invite People");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Notification Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Privacy Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Change Nickname");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Leave Server");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Copy ID");
					TrackPopupMenu(hRightClickMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
					DestroyMenu(hRightClickMenu);
				} else {
					//We need to find out what item the user clicked
					int actualHoverIdx = pData->hoverIdx + (pData->scrollPos >> 5) + ((pData->scrollPos & 0x1f) == 0 ? 0 : 1); /* ((pData->scrollPos & 0x1f) == 0 ? 0 : 1) is needed to fix an off-by-1 error when the user changes the window height and then collapses and tries to expand a group after scrolling to a position that is not a multiple of 32. */
					
					//If the user clicked a channel group, then expand or collapse it.
					unsigned int itemIdx = -1;
					for (unsigned int i = 0; i < pData->dataModel.size(); i++) {
						itemIdx++;
						if (itemIdx == actualHoverIdx) {
							pData->dataModel.at(i).IsExpanded = !pData->dataModel.at(i).IsExpanded;
							
							//Re-calculate the scrollbar size
							unsigned int totalItems = 0;
							for (unsigned int i = 0; i < pData->dataModel.size(); i++) {
								totalItems++;
								if (pData->dataModel.at(i).IsExpanded) 
									for (unsigned int j = 0; j < pData->dataModel.at(i).channels.size(); j++) totalItems++;
							}
							RECT r;
							GetClientRect(wnd, &r);
							int h = r.bottom - r.top;
							SCROLLINFO si = {0};
							GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
							si.cbSize = sizeof(SCROLLINFO);
							si.fMask = SIF_RANGE | SIF_PAGE;
							si.nMin = 0;
							si.nMax = ((totalItems + 2) * 32);
							si.nPage = h - 50;
							
							// Scroll to the top if the list is small enough to fully fit in the window when a channel group is collapsed
							//This solves the issue where the list is still scrolled down, maintaining its position, while the scrollbar "thumb" is updated to take up the full scrollbar, making it impossible to scroll up.
							if (((totalItems + 2) * 32) <= h - 50) {
								si.nPos = 0;
								pData->scrollPos = 0;
							}
							
							//si.nTrackPos = 0;
							SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);

							//Stop the loop
							break;
						}
						if (pData->dataModel.at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModel.at(i).channels.size(); j++) {
								itemIdx++;
								if (itemIdx == actualHoverIdx) {
									selectedChannel = pData->dataModel.at(i).channels.at(j).id;
									selectedChannelGroupIdx = i;
									selectedChannelIdxWithinGroup = j;
									selectedChannelName = pData->dataModel.at(i).channels.at(j).name;
								}
							}
							if (shouldStopSearchingForClickedItem) break;
						}
					}
					InvalidateRect(wnd, NULL, FALSE); //TODO: Optimize this so items that were scrolled and are still fully visible aren't redrawn.
					//UpdateWindow(wnd);
					//TODO: resize scrollbar when a group is expanded or collapsed.
					//RedrawWindow(wnd, NULL, NULL, RDW_UPDATENOW);
				}
			}
		break;
		case WM_SIZE:
			{
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

				unsigned int totalItems = 0;
				for (unsigned int i = 0; i < pData->dataModel.size(); i++) {
					totalItems++;
					if (pData->dataModel.at(i).IsExpanded) 
						for (unsigned int j = 0; j < pData->dataModel.at(i).channels.size(); j++) totalItems++;
				}
				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;
				si.nMin = 0;
				si.nMax = ((totalItems + 2) * 32);// + 50;
				si.nPage = h - 50;
				si.nPos = 0;
				si.nTrackPos = 0;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
			}
		break;
		case WM_VSCROLL:
			//Copied from "Rita Han - MSFT" on StackOverflow
			//https://stackoverflow.com/a/62038422
			{
				// Get all the vertical scroll bar information.
				SCROLLINFO si = {0};
				si.cbSize = sizeof(si);
				si.fMask = SIF_ALL;
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// Save the position for comparison later on.
				int yPos = si.nPos;
				switch (LOWORD(wParam))
				{
					// User clicked the top arrow.
				case SB_LINEUP:
					si.nPos -= 32;//1;
					break;

					// User clicked the bottom arrow.
				case SB_LINEDOWN:
					si.nPos += 32;//1;
					break;

					// User clicked the scroll bar shaft above the scroll box.
				case SB_PAGEUP:
					si.nPos -= si.nPage;
					break;

					// User clicked the scroll bar shaft below the scroll box.
				case SB_PAGEDOWN:
					si.nPos += si.nPage;
					break;

					// User dragged the scroll box.
				case SB_THUMBTRACK:
					si.nPos = (si.nTrackPos == si.nMax) ? si.nMax : ((si.nTrackPos >> 5) << 5); //Snap to a 32-pixel boundary
					//TODO: Try to allow the scrollbar to go fully to the bottom
					break;

				default:
					break;
				}

				// Set the position and then retrieve it.  Due to adjustments
				// by Windows it may not be the same as the value set.
				si.fMask = SIF_POS;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, TRUE);
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// If the position has changed, scroll window and update it.
				if (si.nPos != yPos)
				{
					RECT r;
					GetClientRect(wnd, &r);
					r.top += 50;
					//r.bottom -= 25;*/
					r.right -= 15;
					ScrollWindow(wnd, 0, 32 * (yPos - si.nPos), &r, &r);
					InvalidateRect(wnd, &r, FALSE); //TODO: Optimize this so items that were scrolled and are still visible aren't redrawn.
					//UpdateWindow(wnd);
					pData->scrollPos = si.nPos;
				}
				return 0;
			}
		default:
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

LRESULT CALLBACK serverListProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HGDIOBJ originalGDIObj;
	
	ServerListData* pData = (ServerListData*)GetWindowLongPtr(wnd, 0);
	
	POINT mousePosition;
	
	wchar_t windowName[255];
	
	long long pds;
	
	CREATESTRUCT *cs;

	switch (msg) {
		case WM_NCCREATE:
			pData = new ServerListData();
			if (pData == NULL) return FALSE;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);
			pData->scrollPos = 0;
			{
				ServerListItem sli;
				for (long long i = 0; i < globalServerIconList.size(); i++) {
					sli.id = globalServerIconList.at(i).id;
					sli.name = globalServerIconList.at(i).name;
					sli.unread = globalServerIconList.at(i).unread;
					sli.hbmIcon = globalServerIconList.at(i).hbmIcon;
					pData->dataModel.push_back(sli);
				}
			}
			
			return TRUE;
		break;
		case WM_CREATE:
		{
			RECT r;
			GetClientRect(wnd, &r);
			int height = r.bottom - r.top;
			r.top += 50;
			r.right -= 15;
			pData->hwndScrollbar = CreateWindowExW(NULL, L"SCROLLBAR",L"", WS_CHILD | SBS_VERT | WS_VISIBLE, r.right, 0, 15, height, wnd, (HMENU)NULL, (HINSTANCE)GetWindowLong(wnd, GWL_HINSTANCE), NULL);
			int w = r.right - r.left;
			int h = height;
			MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

			SCROLLINFO si = {0};
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
			si.nMin = 0;
			si.nMax = (pData->dataModel.size() + 2/*1*/) * 56;
			si.nPage = h;
			si.nPos = 0;
			si.nTrackPos = 0;
			SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
		}
		break;
		case WM_NCDESTROY:
			{
				//Release the server icon bitmaps
				for (vector<ServerListItem>::iterator it = pData->dataModel.begin(); it != pData->dataModel.end(); ++it) {
					DeleteObject(it->hbmIcon);
				}
				if (pData != NULL) delete pData;
			}
			return 0;
		break;
		case WM_PAINT:
			hdc = BeginPaint(wnd, &ps);
			originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
			{
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				//FillRect(hdc, &r, serverListColorBrush);
			
				//Each icon is a 48x48 circle with 8 px of spacing between each one

				//Redraw the entire list
				BITMAP bmp;
				HDC iconHDC;
				iconHDC = CreateCompatibleDC(hdc);

				//Set up masking
				HDC maskDC = CreateCompatibleDC(NULL);
				HDC roundRectMaskDC = CreateCompatibleDC(NULL);
				HDC maskedIconDC = CreateCompatibleDC(hdc);
				HBITMAP roundMaskBmp = CreateCompatibleBitmap(maskDC, 48, 48);
				HBITMAP roundRectMaskBmp = CreateCompatibleBitmap(roundRectMaskDC, 48, 48);
				HBITMAP maskedIconBmp = CreateCompatibleBitmap(hdc, 48, 48);
				SetBkColor(maskDC, RGB(0, 0, 0));
				SetDCPenColor(maskDC, RGB(255, 255, 255));
				SelectObject(maskDC, GetStockBrush(WHITE_BRUSH));
				SelectObject(maskDC, roundMaskBmp);
				SelectObject(maskedIconDC, maskedIconBmp);

				SetBkColor(roundRectMaskDC, RGB(0, 0, 0));
				SetDCPenColor(roundRectMaskDC, RGB(255, 255, 255));
				SelectObject(roundRectMaskDC, GetStockBrush(WHITE_BRUSH));
				SelectObject(roundRectMaskDC, roundRectMaskBmp);
				RECT _48x48;
				_48x48.left = 0;
				_48x48.top = 0;
				_48x48.right = 49;
				_48x48.bottom = 49;
				FillRect(maskDC, &_48x48, GetStockBrush(BLACK_BRUSH));
				Ellipse(maskDC, 0, 0, 48, 48);

				FillRect(roundRectMaskDC, &_48x48, GetStockBrush(BLACK_BRUSH));
				RoundRect(roundRectMaskDC, 0, 0, 48, 48, 20, 20);

				//Draw the Home icon
				SelectObject(hdc, serverListColorBrush);
				SetDCPenColor(hdc, serverListColor);
				if (pData->scrollPos / 56 == 0) { //If the list is scrolled to the top
					SelectObject(iconHDC, hBmpHomeIcon);
					GetObject(hBmpHomeIcon, sizeof(bmp), &bmp);
					//BitBlt(hdc, 12, 8, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
					//Use the rounded rectangle mask and draw the rounded white thing on the left if the mouse is over this icon

					//Erase the icon area
					Rectangle(hdc, 0, 8, 12 + 48, 8 + 48);

					if (pData->serverHoverIdx == 0) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, roundRectMaskDC, 0, 0, SRCAND);

						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						RoundRect(hdc, -4, 8 + 14, 4, 8 + 14 + 20, 6, 6);
					} else if (config.roundServerIcons) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, maskDC, 0, 0, SRCAND);
					}

					BitBlt(hdc, 12, 8, bmp.bmWidth, bmp.bmHeight, config.roundServerIcons ? maskedIconDC : iconHDC, 0, 0, SRCPAINT);
				}

				//Draw the server icons
				//They need to be masked
				unsigned int itemCount = pData->dataModel.size();
				RECT tmp;
				int itemsToDraw = (h / 56) + 1;
				int startIdx = pData->scrollPos / 56;
				bool drawExploreIcon = false;
				if ((startIdx + itemsToDraw) >= pData->dataModel.size() - 1) {
					itemsToDraw = (pData->dataModel.size() - startIdx);
					drawExploreIcon = true;
				}
				itemsToDraw++;//TODO: the server list draws all but the last icon

				int i = 0;
				wstring wst;
				for (unsigned int j = startIdx; (j < startIdx + itemsToDraw) && (j < pData->dataModel.size()); j++) {
					SelectObject(iconHDC, pData->dataModel.at(j).hbmIcon);
					GetObject(pData->dataModel.at(j).hbmIcon, sizeof(bmp), &bmp);
					StretchBlt(maskedIconDC, 0, 0, 48, 48, iconHDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

					//Erase the icon area
					SelectObject(hdc, serverListColorBrush);
					SetDCPenColor(hdc, serverListColor);
					Rectangle(hdc, 0, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8, 12 + 48, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8 + 48);

					//Draw the half circle if the server is marked unread
					if (pData->dataModel.at(j).unread) {
						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						Ellipse(hdc, -4, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8 + 20, 4, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8 + 20 + 8);
					}

					//Use the rounded rectangle mask and draw the rounded white thing on the left if the mouse is over this icon
					//The ternary operator is needed for an off-by-one issue when the scrollbar isn't at the top
					if (pData->serverHoverIdx != -1 && j == pData->serverHoverIdx + (pData->scrollPos == 0 ? -1 : 0)) {
						BitBlt(maskedIconDC, 0, 0, 48, 48, roundRectMaskDC, 0, 0, SRCAND);

						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						RoundRect(hdc, -4, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8 + 14, 4, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8 + 14 + 20, 6, 6);
					}
					else if (config.roundServerIcons) {
						BitBlt(maskedIconDC, 0, 0, 48, 48, maskDC, 0, 0, SRCAND);
					}
					BitBlt(hdc, 12, ((i + (startIdx == 0 ? 1 : 0)) * 56) + 8, 48, 48, /*config.roundServerIcons ? */maskedIconDC/* : iconHDC*/, 0, 0, SRCPAINT); //The ternary expression for y is the spacing for the Home icon

					i++;
				}

				//Draw the Explore icon
				if (drawExploreIcon) {
					SelectObject(iconHDC, hBmpExploreIcon);
					GetObject(hBmpExploreIcon, sizeof(bmp), &bmp);
					//Erase the icon area
					SelectObject(hdc, serverListColorBrush);
					SetDCPenColor(hdc, serverListColor);
					Rectangle(hdc, 0, ((i+1) * 56) + 8, 12 + 48, ((i+1) * 56) + 8 + 48);

					BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
					if (pData->serverHoverIdx == pData->dataModel.size() + 1) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, roundRectMaskDC, 0, 0, SRCAND);

						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						RoundRect(hdc, -4, ((i+1) * 56) + 8 + 14, 4, ((i+1) * 56) + 8 + 14 + 20, 6, 6);
					} else if (config.roundServerIcons) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, maskDC, 0, 0, SRCAND);
					}

					BitBlt(hdc, 12, ((i+1) * 56) + 8, bmp.bmWidth, bmp.bmHeight, config.roundServerIcons ? maskedIconDC : iconHDC, 0, 0, SRCPAINT);
				}

				DeleteObject(maskedIconBmp);
				DeleteObject(roundMaskBmp);
				DeleteObject(roundRectMaskBmp);
				DeleteDC(maskedIconDC);
				DeleteDC(roundRectMaskDC);
				DeleteDC(maskDC);
				DeleteDC(iconHDC);
				SelectObject(hdc, originalGDIObj);
				EndPaint(wnd, &ps);
				return 0;
			}
		break;
		case WM_MOUSEMOVE:
			{
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				int oldHoverIdx = pData->serverHoverIdx;

				unsigned int topIconIdx = pData->scrollPos / 56; //The index of the icon at the top of the server list
				unsigned int relativeHoverIdx = yPos / 56;
				unsigned int absoluteHoverIdx = topIconIdx + relativeHoverIdx;
				int hoverIdx = (xPos < 12 || xPos > 59 || yPos % 56 < 8) ? -1 : absoluteHoverIdx;
				pData->serverHoverIdx = hoverIdx;

				if (hoverIdx == -1) {
					SetCursor(LoadCursor(0, IDC_ARROW));
				} else {
					//TODO: Don't use the hand icon for empty server icon spaces
					SetCursor(LoadCursor(0, IDC_HAND));
				}

				if (oldHoverIdx != pData->serverHoverIdx) {
					RECT r;
					GetClientRect(wnd, &r);
					r.right -= 15;
					InvalidateRect(wnd, &r, FALSE);
				}
				return 0;
			}
		break;
		case WM_MOUSELEAVE:
			{
				pData->serverHoverIdx = -1;

				RECT r;
				GetClientRect(wnd, &r);
				r.right -= 15;
				InvalidateRect(wnd, &r, FALSE);
			}
			return 0;
		break;
		case WM_LBUTTONDOWN:
			pData->leftBtnDown = true;
			//InvalidateRect(wnd, NULL, TRUE);
		break;
		case WM_LBUTTONUP:
			{
				pData->leftBtnDown = false;
				//InvalidateRect(wnd, NULL, TRUE);
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				//No part of server icons occurs in x values from 0-11 and 60-71
				//if (xPos < 12 || xPos > 59) return 0;

				unsigned int topIconIdx = pData->scrollPos / 56; //The index of the icon at the top of the server list
				unsigned int relativeClickedIdx = yPos / 56;
				unsigned int absoluteClickedIdx = topIconIdx + relativeClickedIdx;

				wstring p = L"";
				p = to_wstring((long long)pData->serverHoverIdx);
				
				//The user clicked an icon if pData->serverHoverIdx != -1
				//It's possible for pData->serverHoverIdx to contain an index past the end of the list.
				MessageBox(NULL, p.c_str(), L"", MB_OK);
			}
		break;
		case WM_RBUTTONUP:
			{
				//Handle right clicks
				mousePosition.x = GET_X_LPARAM(lParam);
				mousePosition.y = GET_Y_LPARAM(lParam);
				if (pData->serverHoverIdx != -1) {
					HMENU hRightClickMenu = CreatePopupMenu();
					ClientToScreen(hwndMainWin, &mousePosition);
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Mark as read");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Invite People");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Notification Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Privacy Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Change Nickname");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Leave Server");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Copy ID");
					if (!offlineModeEnabled) AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Add to Cache");
					TrackPopupMenu(hRightClickMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
					DestroyMenu(hRightClickMenu);
				}
			}
		break;
		case WM_SIZE:
			//MessageBox(NULL, L"wm_size called on server list", L"", MB_OK);
			{
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;
				si.nMin = 0;
				si.nMax = (pData->dataModel.size() + 2/*1*/) * 56;
				si.nPage = h;
				si.nPos = 0;
				si.nTrackPos = 0;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
			}
		break;
		case WM_VSCROLL:
			//Copied from "Rita Han - MSFT" on StackOverflow
			//https://stackoverflow.com/a/62038422
			{
				// Get all the vertical scroll bar information.
				SCROLLINFO si = {0};
				si.cbSize = sizeof(si);
				si.fMask = SIF_ALL;
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// Save the position for comparison later on.
				int yPos = si.nPos;
				switch (LOWORD(wParam))
				{
					// User clicked the top arrow.
				case SB_LINEUP:
					si.nPos -= 56;//1;
					break;

					// User clicked the bottom arrow.
				case SB_LINEDOWN:
					si.nPos += 56;//1;
					break;

					// User clicked the scroll bar shaft above the scroll box.
				case SB_PAGEUP:
					si.nPos -= si.nPage;
					break;

					// User clicked the scroll bar shaft below the scroll box.
				case SB_PAGEDOWN:
					si.nPos += si.nPage;
					break;

					// User dragged the scroll box.
				case SB_THUMBTRACK:
					si.nPos = si.nTrackPos;
					break;

				default:
					break;
				}

				// Set the position and then retrieve it.  Due to adjustments
				// by Windows it may not be the same as the value set.
				si.fMask = SIF_POS;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, TRUE);
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// If the position has changed, scroll window and update it.
				if (si.nPos != yPos)
				{
					RECT r;
					GetClientRect(wnd, &r);
					r.right -= 15;
					ScrollWindow(wnd, 0, 56 * (yPos - si.nPos), &r, &r);
					InvalidateRect(wnd, &r, FALSE); //TODO: Optimize this so items that were scrolled and are still visible aren't redrawn.
					//UpdateWindow(wnd);
					pData->scrollPos = si.nPos;
					long long t;
					t = si.nPos;
				}
				return 0;
			}
		break;
		case WM_COMMAND:
			{
				switch(LOWORD(wParam)) {

				}
			}
		break;
		default:
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

LRESULT CALLBACK contentAreaProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HGDIOBJ originalGDIObj;
	
	ContentAreaData* pData = (ContentAreaData*)GetWindowLongPtr(wnd, 0);
	
	POINT mousePosition;
	
	wchar_t windowName[255];
	
	long long pds;
	
	CREATESTRUCT *cs;

	switch (msg) {
		case WM_NCCREATE:
			pData = new ContentAreaData();
			if (pData == NULL) return FALSE;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);
			pData->scrollPos = 0;
			pData->totalContentHeight = 0;
			{
				Message m;
				m.messageHeight = -1;
				
				m.authorID = 580427633351720961;
				m.id = 776250970556334090;
				m.text = L"D:";
				pData->messages.push_back(m);
				
				m.authorID = 226733221499371521;
				m.id = 776250656700891167;
				m.text = L"Schmitty more like Snitchtty";
				pData->messages.push_back(m);
				
				m.authorID = 226733221499371521;
				m.id = 776250578384060457;
				m.text = L"Why did you rat out traka";
				pData->messages.push_back(m);
				
				m.authorID = 196483655453900801;
				m.id = 776242881698070588;
				m.text = L"do you think the authorities got traka? he really was spilling secrets, and i did put in an FBI tip...";
				pData->messages.push_back(m);
				
				m.authorID = 545703069783031828;
				m.id = 776234616586502175;
				m.text = L"[image]";
				pData->messages.push_back(m);
				
				m.authorID = 115110682399080453;
				m.id = 776226754125234227;
				m.text = L"Went to the future.or somrttjkng";
				pData->messages.push_back(m);
				
				m.authorID = 115110682399080453;
				m.id = 776226712107220992;
				m.text = L"Teskaplex probably lile";
				pData->messages.push_back(m);
				
				m.authorID = 580427633351720961;
				m.id = 776224643500605441;
				m.text = L"Sarah died in vain";
				pData->messages.push_back(m);
				
				m.authorID = 580427633351720961;
				m.id = 776224643500605441;
				m.text = L"Trakaplex died for our sins";
				pData->messages.push_back(m);
			}
			
			return TRUE;
		break;
		case WM_CREATE:
		{
			RECT r;
			GetClientRect(wnd, &r);
			int height = r.bottom - r.top;
			r.top += 50;
			r.right -= 15;
			pData->hwndScrollbar = CreateWindowExW(NULL, L"SCROLLBAR",L"", WS_CHILD | SBS_VERT | WS_VISIBLE, r.right, 0, 15, height, wnd, (HMENU)NULL, (HINSTANCE)GetWindowLong(wnd, GWL_HINSTANCE), NULL);
			int w = r.right - r.left;
			int h = height;
			MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

			SCROLLINFO si = {0};
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
			si.nMin = 0;
			si.nMax = 10000;
			si.nPage = h;
			si.nPos = 10000;
			si.nTrackPos = 0;
			SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
		}
		break;
		/*case WM_NCDESTROY:
			{
				//Release the server icon bitmaps
				for (vector<ServerListItem>::iterator it = pData->dataModel.begin(); it != pData->dataModel.end(); ++it) {
					DeleteObject(it->hbmIcon);
				}
				if (pData != NULL) delete pData;
			}
			return 0;
		break;*/
		case WM_PAINT:
			hdc = BeginPaint(wnd, &ps);
			originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
			{
				RECT r, textRect;
				GetClientRect(wnd, &r);
				int width = r.right - r.left;
				int height = r.bottom - r.top;
				
				//Set up the font
				SetBkColor(hdc, mainGrayColor);
				SelectObject(hdc, smallInfoFont);
				//SetTextColor(hdc, RGB(255, 255, 255));
				//wstring msg2 = utf8_to_wstring("Night guys! I always love you, someone out there in the world cares for you \r\n,and needs you. You have a dream don’t give up now, later, or anytime soon follow YOUR dreams and do what YOU want too. Not what everybody else is doing be the odd one out, because one day you are going to be the moon in the sky at night, while the others who wanted to follow everyone else are the little stars. Stay true to yourself NIGht!!");
				//wstring msg2 = L"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD";
				textRect.left = 73;
				textRect.top = 15;
				textRect.right = 73 + (width - 146);
				/*textRect.bottom = 50;
				DrawText(hdc, msg2.c_str(), msg2.length(), &textRect, DT_WORDBREAK | DT_EDITCONTROL | DT_CALCRECT);
				wstring msg = L"Left=";
				msg += to_wstring((long long)textRect.left);
				msg += L", Right=";
				msg += to_wstring((long long)textRect.right);
				msg += L", Top=";
				msg += to_wstring((long long)textRect.top);
				msg += L", Bottom=";
				msg += to_wstring((long long)textRect.bottom);
				msg += L", Width=";
				msg += to_wstring((long long)(textRect.right - textRect.left));
				msg += L", Height=";
				msg += to_wstring((long long)(textRect.bottom - textRect.top));
				MessageBox(NULL, msg.c_str(), L"", MB_OK);*/
				//textRect.left = 73;
				//textRect.top = 15;
				//textRect.right = 73 + (width - 146);
				//textRect.bottom = 100;
				
				unsigned int textY = height;
				unsigned int messageWidth = width - 146;
				unsigned int messageHeight;
				unsigned int messageSpacing = 20;
				unsigned long long totalContentHeight = 0;
				for (unsigned int i = 0; i < pData->messages.size(); i++) {
					messageHeight = getMessageHeight(hdc, messageWidth, pData->messages.at(i).text);
					pData->messages.at(i).messageHeight = messageHeight + messageSpacing;
					totalContentHeight += messageHeight + messageSpacing + 25;
					textY -= messageHeight + messageSpacing;
					
					textRect.top = textY;
					textRect.bottom = textY + messageHeight;
					
					//Draw the text
					SetTextColor(hdc, messageTextColor);
					DrawText(hdc, pData->messages.at(i).text.c_str(), pData->messages.at(i).text.length(), &textRect, DT_WORDBREAK | DT_EDITCONTROL);
					
					//Don't bother drawing anything else if the current message is at the top.
					if (textY < 0) break;
					
					//Draw the username
					textY -= 25;
					SetTextColor(hdc, RGB(255, 255, 255)); //TODO: draw username with the right color
					ExtTextOut(hdc, textRect.left, textY, NULL, NULL, to_wstring((long long)pData->messages.at(i).authorID).c_str(), to_wstring((long long)pData->messages.at(i).authorID).length(), NULL);
				}
				
				//Update the scrollbar
				pData->totalContentHeight = totalContentHeight;
				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;// | SIF_POS;
				//si.nMin = 0;
				si.nMax = totalContentHeight;
				si.nPage = height;
				//si.nPos = 10000;
				//si.nTrackPos = 0;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
			}
			SelectObject(hdc, originalGDIObj);
			EndPaint(wnd, &ps);
			return 0;
		break;
		case WM_MOUSEMOVE:
			{
				
			}
		break;
		case WM_MOUSELEAVE:
			{
				
			}
			return 0;
		break;
		case WM_LBUTTONDOWN:
			pData->leftBtnDown = true;
			//InvalidateRect(wnd, NULL, TRUE);
		break;
		case WM_LBUTTONUP:
			{
				
			}
		break;
		case WM_RBUTTONUP:
			{
				
			}
		break;
		case WM_SIZE:
			//MessageBox(NULL, L"wm_size called on content area", L"", MB_OK);
			{
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				MoveWindow(pData->hwndScrollbar, r.right - 15, 0, 15, h, TRUE);

				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;
				si.nMin = 0;
				si.nMax = pData->totalContentHeight;
				si.nPage = h;
				//si.nPos = 10000;
				si.nTrackPos = 0;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
			}
		break;
		case WM_VSCROLL:
			//Copied from "Rita Han - MSFT" on StackOverflow
			//https://stackoverflow.com/a/62038422
			{
				// Get all the vertical scroll bar information.
				SCROLLINFO si = {0};
				si.cbSize = sizeof(si);
				si.fMask = SIF_ALL;
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// Save the position for comparison later on.
				int yPos = si.nPos;
				switch (LOWORD(wParam))
				{
					// User clicked the top arrow.
				case SB_LINEUP:
					si.nPos -= 75;//1;
					break;

					// User clicked the bottom arrow.
				case SB_LINEDOWN:
					si.nPos += 75;//1;
					break;

					// User clicked the scroll bar shaft above the scroll box.
				case SB_PAGEUP:
					si.nPos -= si.nPage;
					break;

					// User clicked the scroll bar shaft below the scroll box.
				case SB_PAGEDOWN:
					si.nPos += si.nPage;
					break;

					// User dragged the scroll box.
				case SB_THUMBTRACK:
					si.nPos = si.nTrackPos;
					break;

				default:
					break;
				}

				// Set the position and then retrieve it.  Due to adjustments
				// by Windows it may not be the same as the value set.
				si.fMask = SIF_POS;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, TRUE);
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);

				// If the position has changed, scroll window and update it.
				if (si.nPos != yPos)
				{
					RECT r;
					GetClientRect(wnd, &r);
					r.right -= 15;
					ScrollWindow(wnd, 0, 75 * (yPos - si.nPos), &r, &r);
					InvalidateRect(wnd, &r, FALSE); //TODO: Optimize this so items that were scrolled and are still visible aren't redrawn.
					//UpdateWindow(wnd);
					pData->scrollPos = si.nPos;
				}
				return 0;
			}
		break;
		case WM_COMMAND:
			{
				switch(LOWORD(wParam)) {

				}
			}
		break;
		default:
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

unsigned int getMessageHeight(HDC hdc, unsigned int width, wstring message) {
	RECT textRect;
	textRect.left = 0;
	textRect.top = 0;
	textRect.right = width;
	DrawText(hdc, message.c_str(), message.length(), &textRect, DT_WORDBREAK | DT_EDITCONTROL | DT_CALCRECT);
	
	unsigned int height = textRect.bottom - textRect.top;
	if (height < 40) height = 40;
	return height;
}

LRESULT CALLBACK hoverBtnProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HGDIOBJ originalGDIObj;
	
	HoverBtnData* pData = (HoverBtnData*)GetWindowLongPtr(wnd, 0);
	
	POINT mousePosition;
	
	wchar_t windowName[255];
	
	long long pds;
	
	CREATESTRUCT *cs;

	switch (msg) {
		case WM_NCCREATE:
			pData = new HoverBtnData();
			if (pData == NULL) return FALSE;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);

			cs = (CREATESTRUCT*)lParam;
			if (cs->lpszName != NULL) pData->text = wstring(cs->lpszName);

			return TRUE;
		break;
		case WM_CREATE:
			pds = GetWindowText(wnd, windowName, 255);
		break;
		case WM_NCDESTROY:
			if (pData != NULL) delete pData;
			return 0;
		break;
		case WM_PAINT:
			hdc = BeginPaint(wnd, &ps);
			originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
			
			GetClientRect(wnd, &rect);
			
			if (pData->mouseIsOver && !(pData->leftBtnDown)) {
				SelectObject(hdc, discordBlueBtnHoverBrush);
				SetDCPenColor(hdc, discordBlueBtnHoverColor);
				SetBkColor(hdc, discordBlueBtnHoverColor);
			} else if (pData->leftBtnDown) {
				SelectObject(hdc, discordBlueBtnDownBrush);
				SetDCPenColor(hdc, discordBlueBtnDownColor);
				SetBkColor(hdc, discordBlueBtnDownColor);
			} else {
				SelectObject(hdc, discordBlueBtnBrush);
				SetDCPenColor(hdc, discordBlueBtnColor);
				SetBkColor(hdc, discordBlueBtnColor);
			}
			
			RoundRectWidthHeight(hdc, rect.left, rect.top, rect.left + (rect.right - rect.left), rect.top + (rect.bottom - rect.top), 10, 10);
			
			SetTextColor(hdc, RGB(255,255,255));
			SelectObject(hdc, hoverBtnFont);
			{
				SIZE sz;
				GetTextExtentPoint32(hdc, pData->text.c_str(), pData->text.length(), &sz);
				int textWidth = sz.cx;
				int btnWidth = rect.right - rect.left;
				ExtTextOut(hdc, rect.left + (btnWidth >> 1) - (textWidth >> 1), rect.top + 11, NULL, NULL, pData->text.c_str(), pData->text.length(), NULL);
			}
			
			SelectObject(hdc, originalGDIObj);
			EndPaint(wnd, &ps);
		break;
		case WM_MOUSEMOVE:
			if (!(pData->mouseIsOver)) {
				pData->mouseIsOver = true;
				TRACKMOUSEEVENT tme = { sizeof(tme) };
				tme.dwFlags = TME_LEAVE;
				tme.hwndTrack = wnd;
				TrackMouseEvent(&tme);
				InvalidateRect(wnd, NULL, TRUE);
			}
		break;
		case WM_MOUSELEAVE:
			pData->mouseIsOver = false;
			InvalidateRect(wnd, NULL, TRUE);
			return 0;
		break;
		case WM_LBUTTONDOWN:
			pData->leftBtnDown = true;
			InvalidateRect(wnd, NULL, TRUE);
		break;
		case WM_LBUTTONUP:
			pData->leftBtnDown = false;
			InvalidateRect(wnd, NULL, TRUE);
			if (wnd == loginBtn) login(true);
			if (wnd == offlineBtn) login(true, true);
		break;
		case WM_SETTEXT:
			pData->text = wstring((wchar_t* )lParam);
		break;
		case WM_GETTEXT:
			return (LRESULT)pData->text.c_str();
		break;
		case WM_GETTEXTLENGTH:
			return (LRESULT)pData->text.length();
		break;
		default:
			//Disable beeping on enter by checking if VK_RETURN was sent with the WM_CHAR message and returning 0
			if (wParam == VK_RETURN) return 0;
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

//Copied from user W.B.
//https://stackoverflow.com/a/15711391
LRESULT CALLBACK editProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_KEYDOWN:
			switch (wParam) {
				case VK_RETURN:
				if (wnd == authTokenBox) {
					login(true);
				}
				return 0;
				break;  //or return 0; if you don't want to pass it further to def proc
				//If not your key, skip to default:
			}
		default:
			//Disable beeping on enter by checking if VK_RETURN was sent with the WM_CHAR message and returning 0
			if (wParam == VK_RETURN) return 0;
			return CallWindowProc(oldEditProc, wnd, msg, wParam, lParam);
	}
	return 0;
}

void SetRectXYWidthHeight(RECT* r, long x, long y, long w, long h) {
	r->left = x;
	r->top = y;
	r->right = x + w;
	r->bottom = y + h;
}

bool RectangleWidthHeight(HDC hdc, int x, int y, int w, int h) {
	return Rectangle(hdc, x, y, x+w, y+h);
}

bool RoundRectWidthHeight(HDC hdc, int x, int y, int w, int h, int rw, int rh) {
	return RoundRect(hdc, x, y, x+w, y+h, rw, rh);
}

void AddMenus(HWND hwndMainWin) {
	HMENU hMenuBar = CreateMenu();
	HMENU hUserMenu = CreateMenu();
	HMENU hHelpMenu = CreateMenu();
	
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_LOGIN, L"Log in");
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_LOGOUT, L"Log out");
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_PROFILE, L"User profile");
	
	AppendMenuW(hHelpMenu, MF_STRING, IDM_HELP_USERGUIDE, L"User Guide");
	
	AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hUserMenu, L"User");
	AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hHelpMenu, L"Help");
	SetMenu(hwndMainWin, hMenuBar);
}

size_t urlWriteCallback(char* buf, size_t size, size_t nmemb, void* up) {
	int actualSize = size * nmemb;
	for (int c = 0; c < actualSize; c++) {
		data.push_back(buf[c]);
	}
	return actualSize;
}

bool CALLBACK SetFont(HWND child, LPARAM font){
	if (child == authTokenBox) {
		SendMessage(child, WM_SETFONT, (LPARAM)authTokenBoxFont, true);
	} else {
		SendMessage(child, WM_SETFONT, font, true);
	}
	return true;
}