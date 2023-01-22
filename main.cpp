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
#include <process.h>
#include <windowsx.h>
#include <initguid.h>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <commctrl.h>
#include <wchar.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <vector>
#include <gdiplus.h>
#include <stdlib.h>

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
#include "libcurl\include\curl\curl.h"

#include "sqlite\sqlite3.h"

#include "emoji.h"

LRESULT CALLBACK leftSidebarProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK serverListProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK contentAreaProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK hoverBtnProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK editProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
bool login(bool, bool offlineMode = false);
wstring getUserAgent();
void copyText(string text);
void copyUnicodeText(wstring text);
wstring getUserName(uint64_t id);
wstring getUserNameWithDiscriminator(uint64_t id);
Gdiplus::Bitmap* getUserAvatar(uint64_t id);
void submitMessage();
void recalculateTotalMessageHeight(bool);
unsigned int DrawTextWithColorEmojis(HDC, Gdiplus::Graphics*, unsigned int, unsigned int, unsigned int, bool, unsigned char*, unsigned int, bool, SIZE*);
int UTF8ToCodepoint(unsigned char*, unsigned int*, unsigned int);
int UTF8CodepointIsEmoji(int);
void drawEmoji(Gdiplus::Graphics *GDIPlusOutputObject, int, unsigned int, unsigned int, unsigned int);
int ReadEmoji(unsigned char*, unsigned int*, unsigned int);
unsigned int GetMaxTextLengthForPixelWidth(HDC, unsigned int, wstring, unsigned int*);
void loadBitmaps();
void deleteBitmaps();
void drawServerIcon(HDC hdc, Gdiplus::Bitmap* icon, int x, int y, int roundStyle /* 0=none, 1=round, 2=hover*/);
void GetRoundRectPath(Gdiplus::GraphicsPath *pPath, Gdiplus::Rect r, int dia);
uint64_t GetSystemTimeAsUnixTime();
std::string wstring_to_utf8(const std::wstring&);
curl_socket_t my_opensocketfunc(void*, curlsocktype, struct curl_sockaddr*);
void addMessageToDataModel(uint64_t serverID, uint64_t channelID, uint64_t messageID, uint64_t authorID, string content);
void deleteMessageFromDataModel(uint64_t serverID, uint64_t channelID, uint64_t messageID);
void markChannelAsUnread(uint64_t serverID, uint64_t channelID);
void addMessageToLog(GenericValue<UTF8<>>*);
void markMessageAsDeletedInLog(GenericValue<UTF8<>>*);
int initializeTables(sqlite3*);

//Contains a font fix provided by "Christopher Janzon" on stackoverflow.com
//https://stackoverflow.com/a/17075471

#define IDM_USER_LOGIN 1
#define IDM_USER_LOGOUT 2
#define IDM_USER_PROFILE 3
#define IDM_HELP_USERGUIDE 4
#define IDM_REFRESH 5
#define IDM_SETTINGS 6
#define IDM_COPY_CHANNEL_ID 7
#define IDM_INVITE_TO_CHANNEL 8
#define IDM_NOTIFICATIONS_DEFAULT 9
#define IDM_NOTIFICATIONS_NONE 10
#define IDM_NOTIFICATIONS_ONLY_MENTIONS 11
#define IDM_NOTIFICATIONS_ALL 12
#define IDM_MUTE 13
#define IDM_MUTE_24_HOUR 14
#define IDM_MUTE_8_HOUR 15
#define IDM_MUTE_1_HOUR 16
#define IDM_MUTE_15_MINUTE 17
#define IDM_CHANNEL_MARK_AS_READ 18
#define IDM_VOICE_CHANNEL_HIDE_NAMES 19
#define IDM_VOICE_CHANNEL_INVITE 20
#define IDM_VOICE_CHANNEL_COPY_ID 21
#define IDM_CHANNEL_GROUP_COLLAPSE_UNREAD 22
#define IDM_COPY_SERVER_ID 23
#define IDM_SETTINGS_LOGGING 24

#define IDC_AUTHTOKENFIELD 7
#define IDC_MESSAGEFIELD 8

#define AUTH_TOKEN_FIELD_WIDTH 600

#define MINIMUM_WINDOW_WIDTH 985
#define MINIMUM_WINDOW_HEIGHT 480

#define DISCORD_MAX_CHARACTERS 2000
#define MESSAGE_SPACING 20

const wstring versionString = L"Talk32 (https://github.com/DoaJCBlogger/Talk32, 0.1)";

enum Page {LoginPage, MainPage};

enum MainPageSubLocation {Channel, Friends, DM, GroupDM, Explore};

Page location = LoginPage;
MainPageSubLocation sublocation = Friends;
unsigned long long selectedServer = -1;
uint64_t selectedChannel = 1052421969297018910;//-1;
unsigned int selectedChannelGroupIdx = 0;
unsigned int selectedChannelIdxWithinGroup = 0;
string selectedServerName = "";
string selectedChannelName = "";
string selectedChannelTopic = "";

struct LoggingServer {
	bool enabled;
	uint64_t id;
	wstring name;
	wstring filename;
	sqlite3 *db;
	LoggingServer():enabled(true),id(0),name(L""),filename(L""){}
};

struct ConfigObj {
	wstring authToken;
	wstring dataDir;
	bool showUserList;
	bool roundServerIcons;
	bool roundUserAvatars;
	unsigned int windowX;
	unsigned int windowY;
	unsigned int windowWidth;
	unsigned int windowHeight;
	vector<LoggingServer> loggingServers;
};

ConfigObj config;

bool offlineModeEnabled = false;

WNDPROC oldEditProc;

bool CALLBACK SetFont(HWND child, LPARAM font);
bool RectangleWidthHeight(HDC hdc, int x, int y, int w, int h);
bool RoundRectWidthHeight(HDC hdc, int x, int y, int w, int h, int rw, int rh);
void SetRectXYWidthHeight(RECT* r, long x, long y, long w, long h);
unsigned int getMessageHeight(unsigned int, string);
size_t urlWriteCallback(char*, size_t, size_t, void*);
HWND hwndMainWin, statusBar, authTokenBox, messageField, httpResponseLabel, loginBtn, hwndServerList, hwndLeftSidebar, hwndContentArea, offlineBtn;
HBRUSH windowBGBrush, mainGrayColorBrush, messageFieldBGBrush, discordBlueBtnBrush, discordBlueBtnHoverBrush, discordBlueBtnDownBrush, serverListColorBrush, sidebarColorBrush, serverListHoverColor, serverListSelectedColor;// = (HBRUSH)GetStockObject(WHITE_BRUSH);
std::string data;
std::string BearerToken;
bool BearerTokenIsValid = false;
SYSTEMTIME BearerTokenCreatedTime = {0};
SYSTEMTIME LastRequestTime = {0};

Gdiplus::Bitmap *hBmpHomeIcon;
HBITMAP hBmpExploreIcon;
HBITMAP hBmpChannelPoundSign;
HBITMAP hBmpChannelPoundSignLocked;
HBITMAP hBmpChannelPoundSignSelected;
HBITMAP hBmpChannelPoundSignLockedSelected;
HBITMAP hBmpVoiceChannelIcon;
HBITMAP hBmpVoiceChannelLockedIcon;
HBITMAP hBmpLargePoundSign;

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
HFONT userNameFont;
HFONT channelGroupNameFont;
HFONT smallHeaderFont;
HFONT smallHeaderFont500Weight;
HFONT hoverBtnFont;

COLORREF serverListColor = RGB(32, 34, 37);
COLORREF sidebarColor = RGB(47, 49, 54);
COLORREF mainGrayColor = RGB(54, 57, 63); //56, 57, 59
COLORREF discordBlueBtnColor = RGB(114, 137, 218);
COLORREF discordBlueBtnHoverColor = RGB(103, 123, 196);
COLORREF discordBlueBtnDownColor = RGB(91, 110, 174);
COLORREF channelColor = RGB(142, 146, 151);
COLORREF contentAreaHeaderBGColor = RGB(56, 57, 59);
COLORREF messageTextColor = RGB(220, 221, 222);
COLORREF deletedMessageTextColor = RGB(237, 66, 69);
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

struct Message {
	unsigned long long id;
	unsigned long long authorID;
	int messageHeight;
	string text;
	bool deleted;
};

struct ChannelItem {
	string name;
	string topic;
	uint64_t id;
	bool voiceChannel;
	bool locked;
	bool unread;
	bool hideVoiceChannelMembers;
	int notificationSetting;
	vector<Message> messages;
};

struct ChannelGroup {
	string name;
	vector<ChannelItem> channels;
	uint64_t id;
	bool IsCategory;
	bool IsExpanded;
	bool collapseUnread;
};
struct ServerListItem {
	string name;
	uint64_t id;
	bool unread;
	vector<ChannelGroup> dataModel;
	Gdiplus::Bitmap *hbmIcon;
};
struct ServerListData {
	bool leftBtnDown;
	HWND hwndScrollbar;
	int serverHoverIdx;
	long scrollPos;
	unsigned long long rightClickItemID;
	vector<ServerListItem> dataModel;
	ServerListData():hwndScrollbar(NULL),serverHoverIdx(-1){}
};

struct User {
	wstring name;
	uint64_t discriminator;
	uint64_t id;
	Gdiplus::Bitmap* hbmIcon;
};

vector<ServerListItem> globalServerIconList;
vector<User> globalUserList;
struct ContentAreaData *globalContentAreaData;
struct LeftSidebarData *globalLeftSidebarData;
CRITICAL_SECTION globalLeftSidebarDataCS;
struct ServerListData *globalServerListData;
CRITICAL_SECTION globalServerListDataCS;
vector<Message> *globalMessageList = NULL;
HDC tempHDC;
unsigned int messageWidth;

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
	unsigned long long rightClickItemID;
	vector<ChannelGroup> dataModel;
	vector<ChannelGroup> *dataModelPtr;
	LeftSidebarData():hwndScrollbar(NULL),scrollPos(0){}
};

struct ContentAreaData {
	vector<Message> messages;
	HWND hwndScrollbar;
	bool leftBtnDown;
	unsigned long scrollPos;
	unsigned long long totalContentHeight;
	int oldContentAreaWidth;
	bool shouldScrollToBottom;
	ContentAreaData():hwndScrollbar(NULL),scrollPos(0),shouldScrollToBottom(true){}
};

const string opcodes[] = {"Dispatch", "Heartbeat", "Identify", "Presence Update", "Voice State Update", "", "Resume", "Reconnect", "Request Guild Members", "Invalid Session", "Hello", "Heartbeat ACK"};

const char* tableNames[7] = {"messages", "attachments", "embeds", "users", "server", "channels", "categories"};
const char* createTableQueries[7] = {
	"CREATE TABLE IF NOT EXISTS \"messages\" (\"ID\" BIGINT NOT NULL,\"channelID\" INTEGER,\"content\" TEXT,\"messageType\" TEXT,\"timestamp\" TEXT,\"timestampEdited\" TEXT,\"authorID\" INTEGER,\"pinned\" INTEGER, \"deleted\" INTEGER, PRIMARY KEY(\"ID\", \"channelID\", \"timestampEdited\"));",
	"CREATE TABLE IF NOT EXISTS \"attachments\" (\"ID\" INTEGER UNIQUE,\"messageID\" INTEGER,\"idx\" INTEGER,\"filename\" TEXT,\"url\" TEXT,\"filesize\" INTEGER, \"deleted\" INTEGER, PRIMARY KEY(\"ID\",\"messageID\"));",
	"CREATE TABLE IF NOT EXISTS \"embeds\" (\"messageID\" TEXT,\"title\" TEXT,\"url\" TEXT,\"description\" TEXT,\"author\" TEXT,\"authorUrl\" TEXT,\"authorIconUrl\" TEXT,\"idx\" INTEGER,\"thumbnailUrl\" TEXT,PRIMARY KEY(\"messageID\",\"idx\"));",
	"CREATE TABLE IF NOT EXISTS \"users\" (\"ID\" TEXT,\"name\" TEXT,\"discriminator\" INTEGER,\"isBot\" INTEGER,\"avatarUrl\" TEXT,\"date\" TEXT,PRIMARY KEY(\"ID\",\"name\",\"discriminator\",\"avatarUrl\"));",
	"CREATE TABLE IF NOT EXISTS \"server\" (\"ID\" BIGINT NOT NULL,\"name\" TEXT,\"iconUrl\" TEXT,\"date\" TEXT,PRIMARY KEY(\"ID\",\"name\",\"iconUrl\"));",
	"CREATE TABLE IF NOT EXISTS \"channels\" (\"ID\" BIGINT NOT NULL,\"type\" TEXT,\"categoryID\" BIGINT,\"name\" TEXT,\"topic\" TEXT,\"date\" TEXT,PRIMARY KEY(\"ID\",\"categoryID\",\"name\",\"topic\"));",
	"CREATE TABLE IF NOT EXISTS \"categories\" (\"ID\" BIGINT NOT NULL,\"name\" TEXT,\"date\" TEXT,PRIMARY KEY(\"ID\",\"name\"));"
};

void heartbeatThread(void* param);
CRITICAL_SECTION discordGatewayCurlObjectCS;

struct DownloadManagerJob {
	wstring url;
	wstring outputFolder;
	wstring filename;
	boolean replace;
};
vector<DownloadManagerJob> downloadManagerJobs;
wstring downloadManagerCurrentURL;
wstring downloadManagerProgress;
CRITICAL_SECTION downloadManagerJobsCS;
CRITICAL_SECTION downloadManagerStatusCS;
bool shouldStopDownloadManager = false;
void downloadManagerThread(void* param) {
	CURL *downloadManagerCurlObject = curl_easy_init();
	if (downloadManagerCurlObject) {
		while (!shouldStopDownloadManager) {
			if (downloadManagerJobs.size() > 0) {
				FILE *file = fopen(wstring_to_utf8(wstring(downloadManagerJobs.at(0).outputFolder + downloadManagerJobs.at(0).filename)).c_str(), "wb");
				if (file) {
					curl_easy_setopt(downloadManagerCurlObject, CURLOPT_URL, wstring_to_utf8(downloadManagerJobs.at(0).url).c_str());
					curl_easy_setopt(downloadManagerCurlObject, CURLOPT_USERAGENT, wstring_to_utf8(getUserAgent()).c_str());
					curl_easy_setopt(downloadManagerCurlObject, CURLOPT_CAINFO, "cacert.pem");
					curl_easy_setopt(downloadManagerCurlObject, CURLOPT_VERBOSE, 1L);
					curl_easy_setopt(downloadManagerCurlObject, CURLOPT_WRITEDATA, file);
					CURLcode res = curl_easy_perform(downloadManagerCurlObject);
					fclose(file);
				}
				downloadManagerJobs.erase(begin(downloadManagerJobs));
			} else {
				Sleep(500);
			}
		}
	}
	curl_easy_cleanup(downloadManagerCurlObject);
}


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
CURL *curl;
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
		
		//round_user_avatars (boolean)
		iter = configDocument.FindMember("round_user_avatars");
		if (iter != configDocument.MemberEnd()) {
			config.roundUserAvatars = configDocument["round_user_avatars"].GetBool();
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
		
		//Logging servers
		iter = configDocument.FindMember("logging_servers");
		if (iter != configDocument.MemberEnd() && configDocument["logging_servers"].IsArray()) {
			Value& loggingServerArray = configDocument["logging_servers"];
			long long arraySize = loggingServerArray.Size();
			
			for (int i = 0; i < arraySize; i++) {
				LoggingServer ls;
				ls.id = configDocument["logging_servers"][i]["id"].GetUint64();
				ls.name = utf8_to_wstring(configDocument["logging_servers"][i]["name"].GetString());
				string loggingServerFilename = configDocument["logging_servers"][i]["filename"].GetString();
				ls.filename = utf8_to_wstring(loggingServerFilename);
				
				int rc = sqlite3_open(loggingServerFilename.c_str(), &ls.db);
				if (rc) {
					cout << endl << "Error while opening database: " << sqlite3_errmsg(ls.db);
				} else {
					initializeTables(ls.db);
				}
				//cout << endl << ls.id << ", " << wstring_to_utf8(ls.name) << ", " << wstring_to_utf8(ls.filename);
				config.loggingServers.push_back(ls);
			}
		}
	}

	return true;
}

void saveConfig() {
	return;
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
	d.AddMember(L"round_user_avatars", config.roundUserAvatars, allocator);

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
	
	GenericValue<UTF16<> > loggingServers(kArrayType);
	for (auto ls = begin(config.loggingServers); ls != end(config.loggingServers); ++ls) {
		GenericDocument<UTF16<> > loggingServer;
		loggingServer.SetObject();
		Document::AllocatorType& allocator3 = loggingServer.GetAllocator();
		loggingServer.AddMember(L"id", ls->id, allocator3);
		loggingServer.AddMember(L"name", StringRef(ls->name), allocator3);
		loggingServer.AddMember(L"filename", StringRef(ls->filename), allocator3);
		loggingServers.PushBack(loggingServer, allocator3);
	}
	d.AddMember(L"logging_servers", loggingServers, allocator);

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


curl_socket_t sock;

curl_socket_t my_opensocketfunc(void *clientp, curlsocktype purpose, struct curl_sockaddr *address){
	return sock=socket(address->family, address->socktype, address->protocol);
}

ofstream logFile;
int heartbeat_interval = 30000;
bool shouldStopHeartbeats = false;
bool APIIsLoggedIn = false;
uintptr_t heartbeatThreadHandle = NULL;
string resume_gateway_url = "wss://gateway.discord.gg/?v=10&encoding=json";
string session_id;
uint64_t latestDiscordSequenceNumber = 0;
char* websocketFragment = NULL;
unsigned long websocketFragmentSize = 0;
unsigned long websocketFragmentCurrentIdx = 0;
unsigned long receivedWebsocketFramesWithinFragment = 0;
bool heartbeatThreadIsActive = false;
static size_t websocketCallback(void *data, size_t size, size_t nmemb, void *userp) {
	size_t realsize = size * nmemb;
	logFile.write((char*)data, realsize);
	std::string str = "Received WebSocket data (";
	str += std::to_string((long long)realsize);
	str += " bytes): ";
	str += string((char*)data, realsize);
	logFile << endl << str;
	
	curl_ws_frame* frameInfo = curl_ws_meta(curl);
	//cout << endl << "flags=" << frameInfo->flags << ", offset=" << frameInfo->offset << " (actual offset " << websocketFragmentCurrentIdx << "), bytesleft=" << frameInfo->bytesleft;
	if (receivedWebsocketFramesWithinFragment == 0) {
		free(websocketFragment);
		websocketFragment = (char*)malloc(realsize + frameInfo->bytesleft);
		websocketFragmentSize = realsize + frameInfo->bytesleft;
		//cout << endl << "WebSocket fragment size: " << websocketFragmentSize;
	}
	memcpy(websocketFragment + websocketFragmentCurrentIdx, data, realsize);
	//cout << endl << "Copied " << realsize << " bytes to offset " << websocketFragmentCurrentIdx;
	if (frameInfo->bytesleft > 0) {
		//This is a partial fragment so we have to just add it to the existing data
		receivedWebsocketFramesWithinFragment++;
		websocketFragmentCurrentIdx += realsize;
		return realsize;
	}
	
	Document responseJSON;
	logFile << endl << "About to parse JSON data: " << string((char*)websocketFragment, websocketFragmentSize);
	
	//For some reason, Discord sometimes sends invalid JSON data with multiple objects like this: {}{}
	int objectStart = 0;
	int objectEnd = 0;
	int curlyBrackets = 0;
	while (objectStart < websocketFragmentSize) {
		for (int i = objectStart; i < websocketFragmentSize; i++) {
			if (websocketFragment[i] == '{') {
				curlyBrackets++;
			} else if (websocketFragment[i] == '}') {
				curlyBrackets--;
			}
			if (curlyBrackets == 0) {
				objectEnd = i;
				logFile << endl << "curlyBrackets is 0 at index " << i;
				break;
			}
		}
		
		responseJSON.Parse(string((char*)websocketFragment + objectStart, (objectEnd - objectStart) + 1/*websocketFragmentSize*/).c_str());
		logFile << endl << "JSON object: " << string((char*)websocketFragment + objectStart, (objectEnd - objectStart) + 1);
		if (responseJSON.HasParseError()) {
			/*wstring error_msg = L"Error parsing config file (at position ";
			long long offset = (unsigned)responseJSON.GetErrorOffset();
			error_msg += to_wstring(offset);
			error_msg += L"): ";
			error_msg += utf8_to_wstring(GetParseError_En(responseJSON.GetParseError()));*/
			cout << endl << "Error while parsing WebSocket data";
			return realsize;
		}

		if (!responseJSON.IsObject()) {
			cout << endl << "Error parsing WebSocket data: root element must be an object";
			return realsize;
		}
		
		rapidjson::Value::ConstMemberIterator iter = responseJSON.FindMember("op");
		if (iter == responseJSON.MemberEnd()) {
			cout << endl << "Could not find \"op\" element";
			return realsize;
		}
		int op = responseJSON["op"].GetInt();
		cout << endl << "op=" << op;
		if (op >= 0 && op <= 11) cout << " (" << opcodes[op] << ")";
		
		string t = "";
		if (iter != responseJSON.MemberEnd()) {
			switch(op) {
				case 0: //Dispatch
					{
						//This includes things like READY and MESSAGE_CREATE
						t = responseJSON["t"].GetString();
						if (responseJSON["s"].IsUint64()) latestDiscordSequenceNumber = responseJSON["s"].GetUint64();
						if (t.compare("READY") == 0) {
							//Save "resume_gateway_url" and "session_id" so we can resume if we get disconnected
							APIIsLoggedIn = true;
							resume_gateway_url = responseJSON["d"]["resume_gateway_url"].GetString();
							session_id = responseJSON["d"]["session_id"].GetString();
							cout << endl << "resume_gateway_url=" << resume_gateway_url;
							cout << endl << "session_id=" << session_id;
							
							//Load the servers and channels
							if (responseJSON["d"]["guilds"].IsArray()) {
								//Clear the channel list
								//Lock the data model so we the UI thread doesn't try to draw it
								EnterCriticalSection(&globalServerListDataCS);
								cout << endl << "Entered the critical section";
								globalLeftSidebarData->dataModel.clear();
								Value& guildsArray = responseJSON["d"]["guilds"];
								long long guildsArraySize = guildsArray.Size();
								ServerListItem server;
								ChannelGroup cg;
								ChannelGroup defaultCG;
								ChannelItem c;
								cg.IsExpanded = true;
								cg.IsCategory = true;
								cg.collapseUnread = false;
								defaultCG.IsExpanded = true;
								defaultCG.IsCategory = true;
								defaultCG.collapseUnread = false;
								defaultCG.name = "Text Channels";
								c.unread = false;
								c.locked = false;
								c.hideVoiceChannelMembers = false;
								c.notificationSetting = 0;
								uint64_t categoryID;
								int channelType;
								int channelsArraySize;
								//Iterate over servers
								for (int h = 0; h < guildsArraySize; h++) {
									Value& guildObject = guildsArray[h];
									server.id = stoull(guildObject["id"].GetString());
									server.name = guildObject["name"].GetString();
									server.unread = false;
									if (!guildObject["icon"].IsNull()) {
										server.hbmIcon = new Gdiplus::Bitmap(wstring(localAppDataPath + L"cache\\server_icons\\" + utf8_to_wstring(guildObject["icon"].GetString()) + L".png").c_str(), false);
									} else {
										server.hbmIcon = new Gdiplus::Bitmap(wstring(localAppDataPath + L"cache\\server_icons\\null.png").c_str(), false);;
									}
									
									channelsArraySize = guildObject["channels"].Size();
									cg.channels.clear();
									//Iterate over the channel objects to get the categories
									for (int i = 0; i < channelsArraySize; i++) {
										//Skip objects that aren't categories
										channelType = guildObject["channels"][i]["type"].GetInt();
										
										//Add channels with no category to a default category
										if ((channelType == 0 /* GUILD_TEXT */ || channelType == 2 /* GUILD_VOICE */) && guildObject["channels"][i].FindMember("parent_id") == guildObject["channels"][i].MemberEnd()) {
											c.id = stoull(guildObject["channels"][i]["id"].GetString(), NULL, 10);
											c.name = guildObject["channels"][i]["name"].GetString();
											c.topic = (guildObject["channels"][i].FindMember("topic") != guildObject["channels"][i].MemberEnd() && !guildObject["channels"][i]["topic"].IsNull()) ? guildObject["channels"][i]["topic"].GetString() : string("");
											c.voiceChannel = (channelType == 2);
											defaultCG.channels.push_back(c);
											continue;
										}
										
										if (guildObject["channels"][i]["type"].GetInt() != 4) continue;
										categoryID = stoull(guildObject["channels"][i]["id"].GetString());
										cg.id = categoryID;
										cg.name = guildObject["channels"][i]["name"].GetString();
										//Iterate over the channel objects to get the channels
										for (int j = 0; j < channelsArraySize; j++) {
											channelType = guildObject["channels"][j]["type"].GetInt();
											if ((guildObject["channels"][j].FindMember("parent_id") == guildObject["channels"][j].MemberEnd() || !guildObject["channels"][j]["parent_id"].IsString() || stoull(guildObject["channels"][j]["parent_id"].GetString(), NULL, 10) != categoryID) || (channelType != 0 /* GUILD_TEXT */ && channelType != 2 /* GUILD_VOICE */)) continue;
											c.id = stoull(guildObject["channels"][j]["id"].GetString(), NULL, 10);
											c.name = guildObject["channels"][j]["name"].GetString();
											c.topic = (guildObject["channels"][j].FindMember("topic") != guildObject["channels"][j].MemberEnd() && !guildObject["channels"][j]["topic"].IsNull()) ? guildObject["channels"][j]["topic"].GetString() : string("");
											c.voiceChannel = (channelType == 2);
											cg.channels.push_back(c);
										} //for (int j = 0; j < channelsArraySize; j++) {
										server.dataModel.push_back(cg);
										cg.channels.clear();
									} //for (int i = 0; i < channelsArraySize; i++) {
									if (!defaultCG.channels.empty()) server.dataModel.push_back(defaultCG);
									globalServerListData->dataModel.push_back(server);
									defaultCG.channels.clear();
									server.dataModel.clear();
								}
								//Unlock the data model
							LeaveCriticalSection(&globalServerListDataCS);
							}
						} else if (t.compare("MESSAGE_CREATE") == 0) {
							//cout << endl << "MESSAGE_CREATE: \"" << responseJSON["d"]["content"].GetString() << "\"";
							uint64_t serverID = (responseJSON["d"].FindMember("guild_id") != responseJSON["d"].MemberEnd() && responseJSON["d"]["guild_id"].IsString() ? stoull(responseJSON["d"]["guild_id"].GetString()) : -1);
							uint64_t channelID = stoull(responseJSON["d"]["channel_id"].GetString());
							//Save the message to a database if the user is logging the server it's from
							addMessageToLog(&responseJSON["d"]);
							if (channelID == selectedChannel) {
								//Add the message to the current data model if the channel is selected
								addMessageToDataModel(serverID, channelID, stoull(responseJSON["d"]["id"].GetString()), stoull(responseJSON["d"]["author"]["id"].GetString()), responseJSON["d"]["content"].GetString());
								
							} else {
								//If the message is for a channel that isn't selected, then we should just mark it as unread
								//The message will be loaded anyway with the POST request when the user clicks it
								markChannelAsUnread(serverID, channelID);
							}
							recalculateTotalMessageHeight(true);
						} else if (t.compare("MESSAGE_DELETE") == 0) {
							markMessageAsDeletedInLog(&responseJSON["d"]);
							uint64_t serverID = (responseJSON["d"].FindMember("guild_id") != responseJSON["d"].MemberEnd() && responseJSON["d"]["guild_id"].IsString() ? stoull(responseJSON["d"]["guild_id"].GetString()) : -1);
							deleteMessageFromDataModel(serverID, stoull(responseJSON["d"]["channel_id"].GetString()), stoull(responseJSON["d"]["id"].GetString()));
						} else if (t.compare("MESSAGE_UPDATE") == 0) {
							uint64_t serverID = (responseJSON["d"].FindMember("guild_id") != responseJSON["d"].MemberEnd() && responseJSON["d"]["guild_id"].IsString() ? stoull(responseJSON["d"]["guild_id"].GetString()) : -1);
							uint64_t channelID = stoull(responseJSON["d"]["channel_id"].GetString());
							//Save the message to a database if the user is logging the server it's from
							addMessageToLog(&responseJSON["d"]);
							//recalculateTotalMessageHeight(true);
						}
						InvalidateRect(hwndLeftSidebar, NULL, TRUE);
						InvalidateRect(hwndContentArea, NULL, TRUE);
					}
					break;
				case 1: //Heartbeat
					{
						//If Discord requested a heartbeat then we need to send one
						size_t sent;
						EnterCriticalSection(&discordGatewayCurlObjectCS);
						string heartbeatObject = "{\"op\":1,\"d\":" + (latestDiscordSequenceNumber >= 0 ? to_string(latestDiscordSequenceNumber) : string("null")) + "}";
						curl_ws_send(curl, heartbeatObject.c_str(), heartbeatObject.length(), &sent, 4096, CURLWS_TEXT);
						LeaveCriticalSection(&discordGatewayCurlObjectCS);
					}
					break;
				case 7: //Reconnect
					{
						//We need to reconnect
						size_t sent;
						cout << endl << "Sending op 1000 to close the connection";
						EnterCriticalSection(&discordGatewayCurlObjectCS);
						string json = "{\"op\":1000,\"d\":" + (latestDiscordSequenceNumber >= 0 ? to_string(latestDiscordSequenceNumber) : string("null")) + "}";
						curl_ws_send(curl, json.c_str(), json.length(), &sent, 4096, CURLWS_TEXT);
						LeaveCriticalSection(&discordGatewayCurlObjectCS);
						cout << endl << "Sent op 1000";
						//Stop the heartbeat thread
						shouldStopHeartbeats = true;
						cout << endl << "Waiting for the heartbeat thread to stop";
						while (heartbeatThreadIsActive) {}
						cout << endl << "Heartbeat thread stopped";
						/*shouldStopHeartbeats = false;
						heartbeatThreadHandle = _beginthread(heartbeatThread, 0, NULL);*/
						return CURL_WRITEFUNC_ERROR;
					}
					break;
				case 9: //Invalid session
					cout << endl << "Invalid session";
					session_id = "";
					return CURL_WRITEFUNC_ERROR;
					break;
				case 10: //Hello
					//Start the heartbeat thread
					iter = responseJSON.FindMember("d");
					if (iter != responseJSON.MemberEnd() && responseJSON["d"]["heartbeat_interval"].IsInt()) {
						heartbeat_interval = responseJSON["d"]["heartbeat_interval"].GetInt();
						cout << endl << "Setting heartbeat_interval to " << heartbeat_interval;
					}
					shouldStopHeartbeats = false;
					heartbeatThreadHandle = _beginthread(heartbeatThread, 0, NULL);
					break;
				case 11: //Heartbeat ACK
					if (!APIIsLoggedIn) {
						//Log in after the first heartbeat acknowledgment
						size_t sent = 0;
						string json = "";
						if (session_id.empty()) {
							json = "{\"op\": 2, \"d\": {\"properties\": {\"os\": \"windows\", \"browser\": \"" + wstring_to_utf8(getUserAgent()) + "\", \"device\": \"" + wstring_to_utf8(getUserAgent()) + "\"}, \"compress\": false, \"large_threshold\": 250, \"intents\": 3276799, \"token\": \"" + wstring_to_utf8(config.authToken) + "\"}}";
						} else {
							json = "{\"op\": 6, \"d\": {\"token\": \"" + wstring_to_utf8(config.authToken) + "\", \"session_id\": \"" + session_id + "\", \"seq\": " + to_string(latestDiscordSequenceNumber) + "}}";
						}
						EnterCriticalSection(&discordGatewayCurlObjectCS);
						curl_ws_send(curl, json.c_str(), json.length(), &sent, 4096, CURLWS_TEXT);
						LeaveCriticalSection(&discordGatewayCurlObjectCS);
					}
					break;
			}
		}
		objectStart = objectEnd + 1;
	}
	
	receivedWebsocketFramesWithinFragment = 0;
	websocketFragmentCurrentIdx = 0;
	return realsize;
}

void websocketThread(void* param) {
	logFile = ofstream("C:\\users\\777\\documents\\ws.log", ios::binary);
	curl = curl_easy_init();
	//struct curl_slist *slist=NULL;
	if (curl) {
		cout << endl << "Curl initialization worked.";
		/*logFile = ofstream("C:\\users\\777\\documents\\curl.log", ios::binary);
		if (!logFile) {
			MessageBox(NULL, L"Could not open log file", L"Error", MB_OK | MB_ICONERROR);
		}*/
		
		curl_easy_setopt(curl, CURLOPT_URL, resume_gateway_url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERAGENT, wstring_to_utf8(getUserAgent()).c_str());
		curl_easy_setopt(curl, CURLOPT_OPENSOCKETFUNCTION, my_opensocketfunc);
		curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, websocketCallback);
		while (true) {
			CURLcode res = curl_easy_perform(curl);
			//LeaveCriticalSection(&discordGatewayCurlObjectCS);
			cout << endl << "Discord gateway disconnected";
			APIIsLoggedIn = false;
			shouldStopHeartbeats = true;
			while (heartbeatThreadIsActive) {}
			shouldStopHeartbeats = false;
			cout << endl << "Reconnecting to Discord gateway";
			Sleep(5000);
		}
		//curl_easy_cleanup(curl);
		//logFile.close();
	}
	//MessageBoxA(NULL, "Exiting WebSocket thread", "", MB_OK);
}

//Continuously send heartbeats to keep the connection open
void heartbeatThread(void* param) {
	heartbeatThreadIsActive = true;
	stringstream heartbeatObject;
	size_t sent;
	int seconds;
	while (!shouldStopHeartbeats) {
		//Send the heartbeat immediately the first time
		//The official documentation says,
		//"Upon receiving the Hello event, your app should wait heartbeat_interval * jitter where jitter is any random value between 0 and 1, then send its first Heartbeat (opcode 1) event."
		seconds = heartbeat_interval / 1000;
		heartbeatObject.str(string());
		heartbeatObject.clear();
		heartbeatObject << "{\"op\":1,\"d\":";
		if (latestDiscordSequenceNumber >= 0) {
			heartbeatObject << latestDiscordSequenceNumber;
		} else {
			heartbeatObject << "null";
		}
		heartbeatObject << "}";
		while (!TryEnterCriticalSection(&discordGatewayCurlObjectCS) && !shouldStopHeartbeats) {}
		if (!shouldStopHeartbeats) curl_ws_send(curl, heartbeatObject.str().c_str(), heartbeatObject.str().length(), &sent, 4096, CURLWS_TEXT);
		LeaveCriticalSection(&discordGatewayCurlObjectCS);
		for (int i = 0; i < seconds && !shouldStopHeartbeats; i++) Sleep(1000);
	}
	heartbeatThreadIsActive = false;
	cout << endl << "Exiting heartbeat thread";
}

static int sqlite3Callback(void *unused, int argc, char **argv, char **azColName) {return 0;}

int initializeTables(sqlite3 *db) {
	char *zErrMsg = 0;
	int rc;
	
	for (int i = 0; i < 7; i++) {
		rc = sqlite3_exec(db, createTableQueries[i], sqlite3Callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {cout << endl << "Error while creating table \"" << tableNames[i] << "\": " << zErrMsg; return 1;}
	}
	return 0;
}

int /*WINAPI WinM*/main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	memset(emojiIsLoaded, 0, (EMOJI_COUNT / 8) + ((EMOJI_COUNT % 8) != 0 ? 1 : 0));
	globalLeftSidebarData = new LeftSidebarData();
	InitializeCriticalSection(&discordGatewayCurlObjectCS);
	InitializeCriticalSection(&globalLeftSidebarDataCS);
	InitializeCriticalSection(&globalServerListDataCS);
	globalServerListData = new ServerListData();
	/*DownloadManagerJob dmj;
	dmj.url = L"https://cdn.discordapp.com/icons/807245652072857610/dc1ae5f4eaa70301d97a4e530d3099e1.png";
	dmj.filename = L"test.png";
	dmj.outputFolder = L"C:\\Users\\777\\Documents\\";
	dmj.replace = true;
	downloadManagerJobs.push_back(dmj);*/
	_beginthread(downloadManagerThread, 0, NULL);
	
	/*sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc) {
		cout << endl << "Error while opening database: " << sqlite3_errmsg(db);
	} else {
		initializeTables(db);
	}
	sqlite3_close(db);*/
	
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
	
	//Create the temporary DC
	tempHDC = CreateCompatibleDC(NULL);
	
	INITCOMMONCONTROLSEX iccx;
	iccx.dwSize=sizeof(INITCOMMONCONTROLSEX);
	iccx.dwICC=0;
	InitCommonControlsEx(&iccx);

	Gdiplus::GdiplusStartupInput gPSI;
	ULONG_PTR gPT;
	Gdiplus::GdiplusStartup(&gPT, &gPSI, NULL);
	loadBitmaps();

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
	messageFieldBGBrush = CreateSolidBrush(RGB(64, 68, 75));
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

	delete globalServerListData;
	DeleteCriticalSection(&globalServerListDataCS);
	DeleteCriticalSection(&globalLeftSidebarDataCS);
	DeleteCriticalSection(&discordGatewayCurlObjectCS);
	delete globalLeftSidebarData;
	deleteBitmaps();
	Gdiplus::GdiplusShutdown(gPT);
	DeleteDC(tempHDC);
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
			hBmpExploreIcon = (HBITMAP) LoadImageW(NULL, L"img\\explore_icon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSign = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignLocked = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignSelected = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_selected.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpChannelPoundSignLockedSelected = (HBITMAP) LoadImageW(NULL, L"img\\channel_pound_sign_locked_selected.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpVoiceChannelIcon = (HBITMAP) LoadImageW(NULL, L"img\\voice.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpVoiceChannelLockedIcon = (HBITMAP) LoadImageW(NULL, L"img\\voice_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			hBmpLargePoundSign = (HBITMAP) LoadImageW(NULL, L"img\\large_pound_sign.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

			
			//Load fonts
			AddFontResourceEx(L"fonts\\Roboto-Regular.ttf", FR_PRIVATE, NULL);
			AddFontResourceEx(L"fonts\\Roboto-Thin.ttf", FR_PRIVATE, NULL);
			
			authTokenPromptFont = CreateFont(30, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			authTokenBoxFont = CreateFont(20, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			smallInfoFont = CreateFont(18, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto Thin");
			channelNameFont = CreateFont(18, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
			userNameFont = CreateFont(19, 0, 0, 0, 400, false, false, 0, 0, 0, 0, 0, 0, L"Roboto");
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
				
				case IDM_SETTINGS_LOGGING:
					{
						
					}
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
			DeleteObject(messageFieldBGBrush);
			DeleteObject(mainGrayColorBrush);
			DeleteObject(windowBGBrush);
			DeleteObject(discordBlueBtnDownBrush);
			DeleteObject(discordBlueBtnHoverBrush);
			DeleteObject(discordBlueBtnBrush);

			//Delete images
			DeleteObject(hBmpExploreIcon);
			DeleteObject(hBmpChannelPoundSign);
			DeleteObject(hBmpChannelPoundSignLocked);
			DeleteObject(hBmpChannelPoundSignSelected);
			DeleteObject(hBmpChannelPoundSignLockedSelected);
			DeleteObject(hBmpVoiceChannelIcon);
			DeleteObject(hBmpVoiceChannelLockedIcon);
			DeleteObject(hBmpLargePoundSign);
		
			//Delete fonts
			DeleteObject(hoverBtnFont);
			DeleteObject(authTokenPromptFont);
			DeleteObject(authTokenBoxFont);
			DeleteObject(channelGroupNameFont);
			DeleteObject(userNameFont);
			DeleteObject(channelNameFont);
			DeleteObject(smallInfoFont);
			DeleteObject(smallHeaderFont);
			DeleteObject(smallHeaderFont500Weight);
			RemoveFontResourceEx(L"fonts\\Roboto-Thin.ttf", FR_PRIVATE, NULL);
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
		
		//Start the Discord gateway thread
		_beginthread(websocketThread, 0, NULL);
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
	if (false && offlineMode) {
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
			wstring iconFilename; //For some reason the channel icons don't show up unless we create this variable outside of the loop.
			for (int i = 0; i < arraySize; i++) {
				//shouldAddEntry = true;
				server = serverArray[i];//.GetUint64();

				//Get the title
				if (!(server.HasMember("title") && server["title"].IsString())) continue;
				sli.name = /*utf8_to_wstring(*/server["title"].GetString()/*)*/;

				//Get the id
				if (!(server.HasMember("id") && server["id"].IsUint64())) continue;
				sli.id = server["id"].GetUint64();

				//Get the icon
				if (server.HasMember("icon") && server["icon"].IsString()) {
					iconFilename = cacheDir + L"\\" + to_wstring(sli.id) + L"\\" + utf8_to_wstring(server["icon"].GetString());
					sli.hbmIcon = new Gdiplus::Bitmap(iconFilename.c_str(), false);
				} else {
					sli.hbmIcon = NULL;
				}
				
				globalServerIconList.push_back(sli);
			}
			server.FindMember("id");
		}
		
		//Get the user list
		//users [array of users]
		iter = cacheDocument.FindMember("users");
		if (iter != cacheDocument.MemberEnd() && cacheDocument["users"].IsArray()) {
			Value& userArray = cacheDocument["users"];
			long long arraySize = userArray.Size();
			Value user;

			//bool shouldAddEntry;
			globalUserList.clear();
			User u;
			Gdiplus::Color serverListBG; //TODO: possibly change this
			serverListBG.SetFromCOLORREF(serverListColor);
			wstring iconFilename;
			for (int i = 0; i < arraySize; i++) {
				//shouldAddEntry = true;
				user = userArray[i];//.GetUint64();

				//Get the name
				if (!(user.HasMember("name") && user["name"].IsString())) continue;
				u.name = utf8_to_wstring(user["name"].GetString());
				
				//Get the discriminator
				if (!(user.HasMember("discriminator") && user["discriminator"].IsUint64())) continue;
				u.discriminator = user["discriminator"].GetUint64();

				//Get the id
				if (!(user.HasMember("id") && user["id"].IsUint64())) continue;
				u.id = user["id"].GetUint64();

				//Get the avatar
				if (user.HasMember("avatar") && user["avatar"].IsString()) {
					iconFilename = cacheDir + L"\\users\\" + to_wstring(u.id) + L"\\" + utf8_to_wstring(user["avatar"].GetString());
					u.hbmIcon = new Gdiplus::Bitmap(iconFilename.c_str(), false);
				} else {
					u.hbmIcon = NULL;
				}
				
				globalUserList.push_back(u);
			}
			user.FindMember("id");
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
	//Lock the data model so it can't be modified by the gateway thread
	EnterCriticalSection(&globalServerListDataCS);
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HGDIOBJ originalGDIObj;
	
	LeftSidebarData* pData = globalLeftSidebarData;//(LeftSidebarData*)GetWindowLongPtr(wnd, 0);
	
	POINT mousePosition;
	
	wchar_t windowName[255];
	
	long long pds;
	
	CREATESTRUCT *cs;

	switch (msg) {
		case WM_NCCREATE:
			LeaveCriticalSection(&globalServerListDataCS);
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
			pData->hwndScrollbar = CreateWindowExW(NULL, L"SCROLLBAR",L"", WS_CHILD | SBS_VERT | WS_VISIBLE, r.right, 50, 15, height - 50, wnd, (HMENU)NULL, (HINSTANCE)GetWindowLong(wnd, GWL_HINSTANCE), NULL);
			int w = r.right - r.left;
			MoveWindow(pData->hwndScrollbar, r.right - 15, 50, 15, height - 50, TRUE);

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
		break;
		case WM_PAINT:
			if (globalLeftSidebarData->dataModelPtr != NULL) {
				hdc = BeginPaint(wnd, &ps);
				Gdiplus::Graphics GDIPlusOutputObject(hdc);
				GDIPlusOutputObject.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
				originalGDIObj = SelectObject(hdc, GetStockObject(DC_PEN));
				
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				//FillRect(hdc, &r, serverListColorBrush);

				MoveWindow(pData->hwndScrollbar, r.right - 15, 50, 15, h - 50, TRUE);

				//Redraw the entire list
				{
					//SelectObject(hdc, authTokenBoxFont);
					SetBkColor(hdc, sidebarColor);
					SelectObject(hdc, channelNameFont);

					//Draw the server name
					SetTextColor(hdc, RGB(255, 255, 255));
					RECT textRect;
					textRect.left = 18;
					textRect.top = 19;
					textRect.right = 18 + 182 + 15;
					//ExtTextOut(hdc, 18, 19, NULL, NULL, selectedServerName.c_str(), selectedServerName/*str*/.length(), NULL);
					//DrawText(hdc, selectedServerName.c_str(), selectedServerName.length(), &textRect, DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS);
					DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, textRect.left, textRect.top, (textRect.right - textRect.left), false, (unsigned char*)selectedServerName.c_str(), selectedServerName.length(), false, NULL);
					
					//Draw the line under the server name
					SetDCPenColor(hdc, RGB(37,37,39));
					MoveToEx(hdc, 0, 49, NULL);
					LineTo(hdc, w, 49);
					SetDCPenColor(hdc, RGB(44,46,50));
					MoveToEx(hdc, 0, 50, NULL);
					LineTo(hdc, w, 50);

					//Draw the down arrow beside the server name
					SetDCPenColor(hdc, RGB(213,214,215));
					MoveToEx(hdc, 227, 23, NULL);
					LineTo(hdc, 232, 28);
					MoveToEx(hdc, 226, 23, NULL);
					LineTo(hdc, 231, 28);
					MoveToEx(hdc, 231, 28, NULL);
					LineTo(hdc, 237, 22);
					MoveToEx(hdc, 232, 28, NULL);
					LineTo(hdc, 238, 22);

					//Draw the channels
					unsigned int channelGroupCount = pData->dataModelPtr->size();
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
					for (unsigned int i = 0; i < pData->dataModelPtr->size() && !shouldStopSearchingForStartPosition; i++) {
						startingChannelGroup = i;
						pixels += 32;
						shouldStopSearchingForStartPosition = (pixels >= pData->scrollPos);
						startingChannelWithinGroup = -1;
						if (pData->dataModelPtr->at(i).IsExpanded) {
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size() && !shouldStopSearchingForStartPosition; j++) {
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
							SelectObject(hdc, sidebarColorBrush);
							SetDCPenColor(hdc, sidebarColor);
							SetBkColor(hdc, sidebarColor);
							Rectangle(hdc, 0, (idx * 32) + 50, 232, (idx * 32) + 50 + 32 + 32);
							
							//ExtTextOut(hdc, 12, (idx * 32) + 50 + 7 + 8, NULL, NULL, pData->dataModel.at(i).name.c_str(), pData->dataModel.at(i).name.length(), NULL);
							DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, 12, (idx * 32) + 50 + 7 + 8, 223, false, (unsigned char*)pData->dataModelPtr->at(i).name.c_str(), pData->dataModelPtr->at(i).name.length(), false, NULL);
							
							//Draw the sideways or down-facing arrow beside the channel group
							if (pData->dataModelPtr->at(i).IsExpanded) {
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
							if (!pData->dataModelPtr->at(i).IsExpanded) {
								startingChannelWithinGroup = -1;
								continue;
							}
						}
						

						//Don't draw channels in a collapsed channel group
						if (!pData->dataModelPtr->at(i).IsExpanded) continue;

						//Draw the channels
						SelectObject(hdc, channelNameFont);
						for (unsigned int j = startingChannelWithinGroup; j < pData->dataModelPtr->at(i).channels.size(); j++) {
							//Don't keep drawing past the bottom of the list
							if (((idx * 32) + 50) > h) {
								shouldStopDrawingChannels = true;
								break;
							}

							//Draw the channel name
							SetTextColor(hdc, pData->dataModelPtr->at(i).channels.at(j).unread ? RGB(255, 255, 255) : channelColor);
							
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
							
							//ExtTextOut(hdc, 42, (idx * 32) + 50 + 7, NULL, NULL, pData->dataModel.at(i).channels.at(j).name.c_str(), pData->dataModel.at(i).channels.at(j).name.length(), NULL);
							DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, 42, (idx * 32) + 50 + 7, 178, false, (unsigned char*)pData->dataModelPtr->at(i).channels.at(j).name.c_str(), pData->dataModelPtr->at(i).channels.at(j).name.length(), false, NULL);

							//Draw the channel icon
							/*hBmpChannelPoundSign;
							hBmpChannelPoundSignLocked;
							hBmpChannelPoundSignSelected;
							hBmpChannelPoundSignLockedSelected;
							hBmpVoiceChannelIcon;
							hBmpVoiceChannelLockedIcon;*/
							
							if (pData->selectedChannelID == pData->dataModelPtr->at(i).channels.at(j).id) {
								//The channel is selected
							} else {
								//The channel is not selected
								if (pData->dataModelPtr->at(i).channels.at(j).locked) {
									//The channel is locked but not selected
									if (pData->dataModelPtr->at(i).channels.at(j).voiceChannel) {
										//The channel is a locked voice channel but is not selected
										channelIcon = hBmpVoiceChannelLockedIcon;
									} else {
										//The channel is a locked text channel but is not selected
										channelIcon = hBmpChannelPoundSignLocked;
									}
								} else {
									//The channel is unlocked and not selected
									if (pData->dataModelPtr->at(i).channels.at(j).voiceChannel) {
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
							if (pData->dataModelPtr->at(i).channels.at(j).unread) {
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
			LeaveCriticalSection(&globalServerListDataCS);
			return 0;
		break;
		case WM_LBUTTONDOWN:
			pData->leftBtnDown = true;
			//InvalidateRect(wnd, NULL, TRUE);
		break;
		case WM_LBUTTONUP:
			if (pData->dataModelPtr == NULL) break;
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
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_COPY_SERVER_ID, L"Copy ID");
					TrackPopupMenu(hRightClickMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
					DestroyMenu(hRightClickMenu);
				} else {
					//We need to find out what item the user clicked
					int actualHoverIdx = pData->hoverIdx + (pData->scrollPos >> 5) + ((pData->scrollPos & 0x1f) == 0 ? 0 : 1); /* ((pData->scrollPos & 0x1f) == 0 ? 0 : 1) is needed to fix an off-by-1 error when the user changes the window height and then collapses and tries to expand a group after scrolling to a position that is not a multiple of 32. */
					
					//If the user clicked a channel group, then expand or collapse it.
					unsigned int itemIdx = -1;
					for (unsigned int i = 0; i < pData->dataModelPtr->size(); i++) {
						itemIdx++;
						if (itemIdx == actualHoverIdx) {
							pData->dataModelPtr->at(i).IsExpanded = !pData->dataModelPtr->at(i).IsExpanded;
							
							//Re-calculate the scrollbar size
							unsigned int totalItems = 0;
							for (unsigned int i = 0; i < pData->dataModelPtr->size(); i++) {
								totalItems++;
								if (pData->dataModelPtr->at(i).IsExpanded) 
									for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) totalItems++;
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
						//If the user clicked a channel then open it.
						if (pData->dataModelPtr->at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
								itemIdx++;
								if (itemIdx == actualHoverIdx) {
									if (!pData->dataModelPtr->at(i).channels.at(j).voiceChannel) {
										//The user clicked a text channel
										selectedChannel = pData->dataModelPtr->at(i).channels.at(j).id;
										selectedChannelGroupIdx = i;
										selectedChannelIdxWithinGroup = j;
										selectedChannelName = pData->dataModelPtr->at(i).channels.at(j).name;
										selectedChannelTopic = pData->dataModelPtr->at(i).channels.at(j).topic;
										globalMessageList = &(pData->dataModelPtr->at(i).channels.at(j).messages);

										//Update the content area
										InvalidateRect(hwndContentArea, NULL, TRUE);
									} else {
										//The user clicked a voice channel
									}
									shouldStopSearchingForClickedItem = true;
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
		case WM_RBUTTONUP:
			if (pData->dataModelPtr == NULL) break;
			//pData->leftBtnDown = false;
			//InvalidateRect(wnd, NULL, TRUE);
			{
				//pData->leftBtnDown = false;
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				POINT mousePosition;
				mousePosition.x = xPos;
				mousePosition.y = yPos;
				ClientToScreen(wnd, &mousePosition);

				wstring p = L"";
				if (yPos < 50) {
					//The user right-clicked in the server name area
					HMENU hRightClickMenu = CreatePopupMenu();
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Boost");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Mark As Read");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Invite People");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Notification Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Privacy Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Change Nickname");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Leave Server");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_COPY_SERVER_ID, L"Copy ID");
					TrackPopupMenu(hRightClickMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
					DestroyMenu(hRightClickMenu);
				} else {
					//We need to find out what item the user right-clicked
					int actualHoverIdx = pData->hoverIdx + (pData->scrollPos >> 5) + ((pData->scrollPos & 0x1f) == 0 ? 0 : 1); /* ((pData->scrollPos & 0x1f) == 0 ? 0 : 1) is needed to fix an off-by-1 error when the user changes the window height and then collapses and tries to expand a group after scrolling to a position that is not a multiple of 32. */
					
					//If the user right-clicked a channel group, then show a context menu.
					unsigned int itemIdx = -1;
					for (unsigned int i = 0; i < pData->dataModelPtr->size(); i++) {
						itemIdx++;
						if (itemIdx == actualHoverIdx) {
							//The user right-clicked a channel group
							pData->rightClickItemID = pData->dataModelPtr->at(i).id;
							HMENU hMenu = CreatePopupMenu();
							HMENU hMenuMuteChannel = CreatePopupMenu();
							HMENU hMenuNotificationSettings = CreatePopupMenu();
							AppendMenuW(hMenu, MF_STRING, IDM_CHANNEL_MARK_AS_READ, L"Mark As Read");
							
							AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_15_MINUTE, L"For 15 Minutes");
							AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_1_HOUR, L"For 1 Hour");
							AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_8_HOUR, L"For 8 Hours");
							AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_24_HOUR, L"For 24 Hours");
							AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE, L"Until I turn it back on");
							AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hMenuMuteChannel, L"Mute Category");
							
							AppendMenuW(hMenu, MF_STRING, IDM_CHANNEL_GROUP_COLLAPSE_UNREAD, L"Collapse Category");
							CheckMenuItem(hMenu, IDM_CHANNEL_GROUP_COLLAPSE_UNREAD, pData->dataModelPtr->at(i).collapseUnread ? MF_CHECKED : MF_UNCHECKED);

							AppendMenuW(hMenu, MF_STRING, IDM_COPY_CHANNEL_ID, L"Copy ID");
							TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
							
							DestroyMenu(hMenuNotificationSettings);
							DestroyMenu(hMenuMuteChannel);
							DestroyMenu(hMenu);
							//Stop the loop
							break;
						}
						//If the user right-clicked a channel then show a context menu
						if (pData->dataModelPtr->at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
								itemIdx++;
								if (itemIdx == actualHoverIdx) {
									pData->rightClickItemID = pData->dataModelPtr->at(i).channels.at(j).id;
									if (!pData->dataModelPtr->at(i).channels.at(j).voiceChannel) {
										//The user right-clicked a text channel
										/*selectedChannel = pData->dataModel.at(i).channels.at(j).id;
										selectedChannelGroupIdx = i;
										selectedChannelIdxWithinGroup = j;
										selectedChannelName = pData->dataModel.at(i).channels.at(j).name;*/
										
										//ClientToScreen(wnd, &mousePosition);
										HMENU hMenu = CreatePopupMenu();
										HMENU hMenuMuteChannel = CreatePopupMenu();
										HMENU hMenuNotificationSettings = CreatePopupMenu();
										AppendMenuW(hMenu, MF_STRING, IDM_CHANNEL_MARK_AS_READ, L"Mark As Read");
										
										AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_15_MINUTE, L"For 15 Minutes");
										AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_1_HOUR, L"For 1 Hour");
										AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_8_HOUR, L"For 8 Hours");
										AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE_24_HOUR, L"For 24 Hours");
										AppendMenuW(hMenuMuteChannel, MF_STRING, IDM_MUTE, L"Until I turn it back on");
										AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hMenuMuteChannel, L"Mute Channel");
										
										AppendMenuW(hMenuNotificationSettings, MF_STRING, IDM_NOTIFICATIONS_DEFAULT, L"Use Server Default");
										AppendMenuW(hMenuNotificationSettings, MF_STRING, IDM_NOTIFICATIONS_ALL, L"All Messages");
										AppendMenuW(hMenuNotificationSettings, MF_STRING, IDM_NOTIFICATIONS_ONLY_MENTIONS, L"Only @mentions");
										AppendMenuW(hMenuNotificationSettings, MF_STRING, IDM_NOTIFICATIONS_NONE, L"Nothing");
										
										int notificationSetting;
										switch (pData->dataModelPtr->at(i).channels.at(j).notificationSetting) {
											case 3:
												notificationSetting = IDM_NOTIFICATIONS_NONE;
											break;
											case 2:
												notificationSetting = IDM_NOTIFICATIONS_ONLY_MENTIONS;
											break;
											case 1:
												notificationSetting = IDM_NOTIFICATIONS_ALL;
											break;
											case 0:
											default:
												notificationSetting = IDM_NOTIFICATIONS_DEFAULT;
											break;
										}
										CheckMenuRadioItem(hMenuNotificationSettings, IDM_NOTIFICATIONS_DEFAULT, IDM_NOTIFICATIONS_NONE, notificationSetting, MF_BYCOMMAND);
										AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hMenuNotificationSettings, L"Notification Settings");
										
										AppendMenuW(hMenu, MF_STRING, IDM_INVITE_TO_CHANNEL, L"Invite People");
										AppendMenuW(hMenu, MF_STRING, IDM_COPY_CHANNEL_ID, L"Copy ID");
										TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
										
										DestroyMenu(hMenuNotificationSettings);
										DestroyMenu(hMenuMuteChannel);
										DestroyMenu(hMenu);
									} else {
										//The user right-clicked a voice channel
										HMENU hMenu = CreatePopupMenu();
										
										AppendMenuW(hMenu, MF_STRING, IDM_VOICE_CHANNEL_HIDE_NAMES, L"Hide Names");
										AppendMenuW(hMenu, MF_STRING, IDM_VOICE_CHANNEL_INVITE, L"Invite People");
										AppendMenuW(hMenu, MF_STRING, IDM_VOICE_CHANNEL_COPY_ID, L"Copy ID");
										CheckMenuItem(hMenu, IDM_VOICE_CHANNEL_HIDE_NAMES, pData->dataModelPtr->at(i).channels.at(j).hideVoiceChannelMembers ? MF_CHECKED : MF_UNCHECKED);
										TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, mousePosition.x, mousePosition.y, 0, wnd, NULL);
										
										DestroyMenu(hMenu);
									}
									
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
			if (pData->dataModelPtr == NULL) break;
			{
				RECT r;
				GetClientRect(wnd, &r);
				int w = r.right - r.left;
				int h = r.bottom - r.top;
				MoveWindow(pData->hwndScrollbar, r.right - 15, 50, 15, h - 50, TRUE);

				unsigned int totalItems = 0;
				for (unsigned int i = 0; i < pData->dataModelPtr->size(); i++) {
					totalItems++;
					if (pData->dataModelPtr->at(i).IsExpanded) 
						for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) totalItems++;
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
			if (pData->dataModelPtr == NULL) break;
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
				LeaveCriticalSection(&globalServerListDataCS);
				return 0;
			}
		case WM_COMMAND:
			if (pData->dataModelPtr == NULL) break;
			switch(LOWORD(wParam)) {
				case IDM_VOICE_CHANNEL_HIDE_NAMES:
				{
					for (unsigned int i = 0; i < pData->dataModelPtr->size(); i++) {
						if (pData->dataModelPtr->at(i).id == pData->rightClickItemID) {
							//The user right-clicked a channel group
							
							//Stop the loop
							break;
						}
						if (pData->dataModelPtr->at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
							}
						}
					}
				}
				break;
				case IDM_CHANNEL_MARK_AS_READ:
				{
					bool shouldStop = false;
					for (unsigned int i = 0; i < pData->dataModelPtr->size() && !shouldStop; i++) {
						if (pData->dataModelPtr->at(i).id == pData->rightClickItemID) {
							//The user wants to mark a channel group as read
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
								pData->dataModelPtr->at(i).channels.at(j).unread = false;
							}
							
							//Redraw the list
							InvalidateRect(hwndLeftSidebar, NULL, TRUE);
							UpdateWindow(hwndLeftSidebar);
							
							//Stop the loop
							break;
						}
						if (pData->dataModelPtr->at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
								if (pData->dataModelPtr->at(i).channels.at(j).id == pData->rightClickItemID) {
									//The user wants to mark a channel as read
									pData->dataModelPtr->at(i).channels.at(j).unread = false;
									
									//Redraw the list
									InvalidateRect(hwndLeftSidebar, NULL, TRUE);
									UpdateWindow(hwndLeftSidebar);
									
									//Stop the loop
									shouldStop = true;
									break;
								}
							}
						}
					}
				}
				case IDM_COPY_CHANNEL_ID:
				{
					bool shouldStop = false;
					for (unsigned int i = 0; i < pData->dataModelPtr->size() && !shouldStop; i++) {
						if (pData->dataModelPtr->at(i).id == pData->rightClickItemID) {
							//The user wants to copy the ID of a channel group
							copyText(to_string((long long)pData->dataModelPtr->at(i).id));
							
							//Stop the loop
							break;
						}
						if (pData->dataModelPtr->at(i).IsExpanded) {
							bool shouldStopSearchingForClickedItem = false;
							for (unsigned int j = 0; j < pData->dataModelPtr->at(i).channels.size(); j++) {
								if (pData->dataModelPtr->at(i).channels.at(j).id == pData->rightClickItemID) {
									//The user wants to copy the ID of a channel
									copyText(to_string((long long)pData->dataModelPtr->at(i).channels.at(j).id));
									
									//Stop the loop
									shouldStop = true;
									break;
								}
							}
						}
					}
				}
				break;
				case IDM_COPY_SERVER_ID:
				{
					if (selectedServer != -1) copyText(to_string((long long)selectedServer));
				}
				break;
			}
		default:
			LeaveCriticalSection(&globalServerListDataCS);
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	//Unlock the data model
	LeaveCriticalSection(&globalServerListDataCS);
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

LRESULT CALLBACK serverListProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	EnterCriticalSection(&globalServerListDataCS);
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
			pData = globalServerListData;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);
			pData->scrollPos = 0;
			/*{
				ServerListItem sli;
				for (long long i = 0; i < globalServerIconList.size(); i++) {
					sli.id = globalServerIconList.at(i).id;
					sli.name = globalServerIconList.at(i).name;
					sli.unread = globalServerIconList.at(i).unread;
					sli.hbmIcon = globalServerIconList.at(i).hbmIcon;
					pData->dataModel.push_back(sli);
				}
			}*/
			
			LeaveCriticalSection(&globalServerListDataCS);
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
					delete it->hbmIcon;
				}
			}
			LeaveCriticalSection(&globalServerListDataCS);
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
					//Erase the icon area
					Rectangle(hdc, 0, 8, 12 + 48, 8 + 48);

					int roundStyle = 0;
					if (pData->serverHoverIdx == 0) {
						roundStyle = 2;
					} else {
						roundStyle = (config.roundServerIcons ? 1 : 0);
					}

					drawServerIcon(hdc, hBmpHomeIcon, 12, 8, roundStyle);
				}

				//Draw the server icons
				unsigned int itemCount = pData->dataModel.size();
				RECT tmp;
				int itemsToDraw = (h / 56) + 1;
				int startIdx = (pData->scrollPos / 56) - 1;
				if (startIdx == -1) startIdx = 0;
				bool drawExploreIcon = false;
				if ((startIdx + itemsToDraw) >= pData->dataModel.size() - 1) {
					itemsToDraw = (pData->dataModel.size() - startIdx);
					drawExploreIcon = true;
				}
				itemsToDraw++;//TODO: the server list draws all but the last icon

				int i = 0;
				wstring wst;
				for (unsigned int j = startIdx; (j < startIdx + itemsToDraw) && (j < pData->dataModel.size()); j++) {
					//Erase the icon area
					SelectObject(hdc, serverListColorBrush);
					SetDCPenColor(hdc, serverListColor);
					Rectangle(hdc, 0, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8, 12 + 48, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8 + 48);

					//Draw the half circle if the server is marked unread
					if (pData->dataModel.at(j).unread) {
						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						Ellipse(hdc, -4, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8 + 20, 4, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8 + 20 + 8);
					}

					//Draw the rounded white thing on the left if the mouse is over this icon
					//The ternary operator was used for an off-by-one issue when the scrollbar isn't at the top
					//It might be better to just subtract 1 no matter what
					int roundStyle = 0;
					if ((pData->serverHoverIdx != -1 && j == pData->serverHoverIdx - 1/* + (pData->scrollPos == 0 ? -1 : 0)*/) || (pData->dataModel.at(j).id == selectedServer) /* If the server is selected, then it should use the hover style */) {
						roundStyle = 2;
					} else {
						roundStyle = (config.roundServerIcons ? 1 : 0);
					}
					//Draw the icon
					drawServerIcon(hdc, pData->dataModel.at(j).hbmIcon, 12, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8, roundStyle);
					
					//If the server is selected, then we need to draw a white rounded rectangle on the left
					if (pData->dataModel.at(j).id == selectedServer) {
						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						RoundRect(hdc, -4, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8 + 14 - 10, 4, ((i + (pData->scrollPos < 56 ? 1 : 0)) * 56) + 8 + 14 + 20 + 10, 6, 6);
					}
					
					i++;
				}

				//Draw the Explore icon
				if (drawExploreIcon) {
					SelectObject(iconHDC, hBmpExploreIcon);
					GetObject(hBmpExploreIcon, sizeof(bmp), &bmp);
					//Erase the icon area
					SelectObject(hdc, serverListColorBrush);
					SetDCPenColor(hdc, serverListColor);
					Rectangle(hdc, 0, ((i+(pData->scrollPos >= 56 ? 0 : 1)) * 56) + 8, 12 + 48, ((i+(pData->scrollPos >= 56 ? 0 : 1)) * 56) + 8 + 48);

					BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, iconHDC, 0, 0, SRCCOPY);
					if (pData->serverHoverIdx == pData->dataModel.size() + 1) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, roundRectMaskDC, 0, 0, SRCAND);

						SelectObject(hdc, GetStockBrush(WHITE_BRUSH));
						SetDCPenColor(hdc, RGB(255, 255, 255));
						RoundRect(hdc, -4, ((i+(pData->scrollPos >= 56 ? 0 : 1)) * 56) + 8 + 14, 4, ((i+(pData->scrollPos >= 56 ? 0 : 1)) * 56) + 8 + 14 + 20, 6, 6);
					} else if (config.roundServerIcons) {
						BitBlt(maskedIconDC, 0, 0, bmp.bmWidth, bmp.bmHeight, maskDC, 0, 0, SRCAND);
					}

					BitBlt(hdc, 12, ((i+(pData->scrollPos >= 56 ? 0 : 1)) * 56) + 8, bmp.bmWidth, bmp.bmHeight, config.roundServerIcons ? maskedIconDC : iconHDC, 0, 0, SRCPAINT);
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
				LeaveCriticalSection(&globalServerListDataCS);
				return 0;
			}
		break;
		case WM_MOUSEMOVE:
			{
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				int oldHoverIdx = pData->serverHoverIdx;

				unsigned int topIconIdx = (pData->scrollPos / 56);// + (yPos % 56 != 0 ? 0 : 1); //The index of the icon at the top of the server list
				unsigned int relativeHoverIdx = (yPos / 56);
				//TODO: (possibly fixed) fix the bug in which moving the scrollbar thumb causes the hover index to be 1 less than the actual index
				if (pData->scrollPos < 56 && pData->scrollPos % 56 != 0) {
					//relativeHoverIdx--;
				} else if (pData->scrollPos % 56 != 0) {
					//relativeHoverIdx++;
				}
				unsigned int absoluteHoverIdx = topIconIdx + relativeHoverIdx;
				int hoverIdx = (xPos < 12 || xPos > 59 || yPos % 56 < 8 || absoluteHoverIdx > pData->dataModel.size() + 1) ? -1 : absoluteHoverIdx;
				pData->serverHoverIdx = hoverIdx;

				if (hoverIdx == -1 || hoverIdx > pData->dataModel.size() + 1) {
					SetCursor(LoadCursor(0, IDC_ARROW));
				} else {
					SetCursor(LoadCursor(0, IDC_HAND));
				}

				if (oldHoverIdx != pData->serverHoverIdx) {
					RECT r;
					GetClientRect(wnd, &r);
					r.right -= 15;
					InvalidateRect(wnd, &r, FALSE);
				}
				LeaveCriticalSection(&globalServerListDataCS);
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
			LeaveCriticalSection(&globalServerListDataCS);
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

				unsigned int topIconIdx = (pData->scrollPos / 56); //The index of the icon at the top of the server list
				unsigned int relativeClickedIdx = (yPos / 56) + (yPos > 0 ? 1 : 0);
				unsigned int absoluteClickedIdx = topIconIdx + relativeClickedIdx;
				
				//It's possible for pData->serverHoverIdx to contain an index past the end of the list.

				if (pData->serverHoverIdx == 0) {
					MessageBox(NULL, L"Home", L"", MB_OK);
				} else if (pData->serverHoverIdx == pData->dataModel.size() + 1) {
					MessageBox(NULL, L"Explore Public Servers", L"", MB_OK);
				} else if (pData->serverHoverIdx <= pData->dataModel.size()) {
					//MessageBox(NULL, pData->dataModel.at(pData->serverHoverIdx - 1).name.c_str(), L"", MB_OK);
					selectedServer = pData->dataModel.at(pData->serverHoverIdx - 1).id;
					selectedServerName = pData->dataModel.at(pData->serverHoverIdx - 1).name;
					
					EnterCriticalSection(&globalLeftSidebarDataCS);
					//globalLeftSidebarData->dataModel.clear();
					for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel); ++it) {
						if (it->id == selectedServer) {
							globalLeftSidebarData->dataModelPtr = &(it->dataModel);
							break;
						}
					}
					LeaveCriticalSection(&globalLeftSidebarDataCS);
					
					//Redraw the server list
					InvalidateRect(hwndServerList, NULL, TRUE);
					UpdateWindow(hwndServerList);
					
					//Redraw the left sidebar
					InvalidateRect(hwndLeftSidebar, NULL, TRUE);
					UpdateWindow(hwndLeftSidebar);
				}
				//p = to_wstring((long long)pData->serverHoverIdx);
			}
		break;
		case WM_RBUTTONUP:
			{
				//Handle right clicks
				mousePosition.x = GET_X_LPARAM(lParam);
				mousePosition.y = GET_Y_LPARAM(lParam);
				//Only create a context menu for server icons (don't create one for Home or Explore)
				if (pData->serverHoverIdx > 0 && pData->serverHoverIdx <= pData->dataModel.size()) {
					pData->rightClickItemID = pData->dataModel.at(pData->serverHoverIdx - 1).id;
					
					HMENU hRightClickMenu = CreatePopupMenu();
					ClientToScreen(hwndMainWin, &mousePosition);
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Mark as read");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Invite People");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Server Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Notification Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Privacy Settings");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Change Nickname");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_REFRESH, L"Leave Server");
					AppendMenuW(hRightClickMenu, MF_STRING, IDM_COPY_SERVER_ID, L"Copy ID");
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
				
				if (h >= (pData->dataModel.size() + 2) * 56) pData->scrollPos = 0;

				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;
				si.nMin = 0;
				si.nMax = (pData->dataModel.size() + 3/*1*/) * 56;
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
					si.nPos = (si.nTrackPos / 56) * 56;
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
				LeaveCriticalSection(&globalServerListDataCS);
				return 0;
			}
		break;
		case WM_COMMAND:
			{
				switch(LOWORD(wParam)) {
					case IDM_COPY_SERVER_ID:
					{
						//We have to search for the server by ID rather than retrieving it by its index,
						//because the server could have disappeared from the list in the time between
						//right-clicking it and clicking Copy ID.
						for (unsigned int i = 0; i < pData->dataModel.size(); i++) {
							if (pData->dataModel.at(i).id == pData->rightClickItemID) {
								copyText(to_string((long long)pData->dataModel.at(i).id));
								break;
							}
						}
					}
					break;
				}
			}
		break;
		default:
			LeaveCriticalSection(&globalServerListDataCS);
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	LeaveCriticalSection(&globalServerListDataCS);
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
			globalContentAreaData = pData;
			SetWindowLongPtr(wnd, 0, (LONG_PTR)pData);
			pData->scrollPos = 0;
			pData->totalContentHeight = 0;
			/*{
				Message m;
				m.messageHeight = -1;
				
				m.authorID = 336697008356327444;
				m.id = 1;
				m.text = 1061838579795505162;
				m.deleted = false;
				m.text = "Hello from Ripcord to Talk32 on Windows XP.";
				pData->messages.push_back(m);
				
				m.authorID = 115110682399080453;
				m.id = 826573208504369182;
				m.text = "hiii 👋";
				pData->messages.push_back(m);
				
				m.authorID = 580427633351720961;
				m.id = 776250970556334090;
				m.text = "D:";
				pData->messages.push_back(m);
				
				m.authorID = 156948140510019586;
				m.id = 776250656700891167;
				m.text = "😳so you wanna kiss me @fern. ? 😳and then fall in love and we can be dates on dating and date and then you wanna meet each other’s parents... we decide to then get married! we will have a destination marriage in iceland and our honeymoon will be in a cute [hotel] and we will [passionately hug] on a large heartshaped bed and i will become pregnant and when we go to the hospital to check the gender we will find out that its TWINS! one boy and one girl 😱. We name one something basic like jenny and the other one something like theodorkus! I decided its time that we move to a more quiet town and it starts stressing us out and i start drinking and we fall into a loveless marriage and you will start cheating on me with a coworker. One night i will stay up waiting for you to come home... when you get home it is 4 am and i yell at you asking where you’ve been and you tell me you’ve been with your [girlfriend] and that you no longer love me and want to leave me! i start crying and throwing my wine at you. you get angry and hit me, i am shocked, i stare at you and walk upstairs and lie down in bed. you then decide its best to sleep on the couch and call your coworker to talk about the incident. i start walking downstairs to apologize and hear you, you start snickering and tell your new lover that i am a crazy [woman]! OUT OF RAGE I RUN TO THE KITCHEN FOR A KNIFE!! You hear me and turn around confused. I grab the knife and you run over to stop me, you grab me and try to console me and when you try to take the knife i stab you in the neck multiple times! I start crying more and remember the phone, she was listening... i hang up and start shaking. and then she calls the cops and i go to prison :(";
				pData->messages.push_back(m);
				
				m.authorID = 226733221499371521;
				m.id = 776250578384060457;
				m.text = "Why did you rat out traka";
				pData->messages.push_back(m);
				
				m.authorID = 196483655453900801;
				m.id = 776242881698070588;
				m.text = "do you think the authorities got traka? he really was spilling secrets, and i did put in an FBI tip...";
				pData->messages.push_back(m);
				
				m.authorID = 545703069783031828;
				m.id = 776234616586502175;
				m.text = "[image]";
				pData->messages.push_back(m);
				
				m.authorID = 115110682399080453;
				m.id = 776226754125234227;
				m.text = "Went to the future.or somrttjkng";
				pData->messages.push_back(m);
				
				m.authorID = 115110682399080453;
				m.id = 776226712107220992;
				m.text = "Teskaplex probably lile";
				pData->messages.push_back(m);
				
				m.authorID = 580427633351720961;
				m.id = 776224643500605441;
				m.text = "Sarah died in vain";
				pData->messages.push_back(m);
				
				m.authorID = 580427633351720961;
				m.id = 776224643500605441;
				m.text = "Trakaplex died for our sins";
				pData->messages.push_back(m);
			}*/
			
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
			MoveWindow(pData->hwndScrollbar, r.right - 15, 48, 15, h - 48, TRUE);

			/*SCROLLINFO si = {0};
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
			si.nMin = 0;
			si.nMax = 10000;
			si.nPage = h;
			si.nPos = 10000;
			si.nTrackPos = 0;
			SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);*/
			
			//Create the message field
			messageField = CreateWindowW(L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 72, h - 36, w - (72 + 15), 20, wnd, (HMENU)IDC_MESSAGEFIELD, NULL, NULL);
			SendMessage(messageField, WM_SETFONT, (LPARAM)userNameFont, true);
			SetWindowLongPtr(messageField, GWLP_WNDPROC, (LONG_PTR)editProc);
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
				SIZE textSize;
				GetClientRect(wnd, &r);
				int width = r.right - r.left;
				int height = r.bottom - r.top;
				HDC iconHDC;
				BITMAP bmp;
				Gdiplus::Bitmap *userIcon;
				Gdiplus::Graphics GDIPlusOutputObject(hdc);
				GDIPlusOutputObject.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
				Gdiplus::ImageAttributes attrs;
				iconHDC = CreateCompatibleDC(hdc);

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
				
				//Set up masking
				HDC maskDC = CreateCompatibleDC(NULL);
				HDC maskedIconDC = CreateCompatibleDC(hdc);
				HBITMAP roundMaskBmp = CreateCompatibleBitmap(maskDC, 40, 40);
				HBITMAP maskedIconBmp = CreateCompatibleBitmap(hdc, 40, 40);
				SetBkColor(maskDC, RGB(0, 0, 0));
				SetDCPenColor(maskDC, RGB(255, 255, 255));
				SelectObject(maskDC, GetStockBrush(WHITE_BRUSH));
				SelectObject(maskDC, roundMaskBmp);
				SelectObject(maskedIconDC, maskedIconBmp);

				RECT _40x40;
				_40x40.left = 0;
				_40x40.top = 0;
				_40x40.right = 41;
				_40x40.bottom = 41;
				FillRect(maskDC, &_40x40, GetStockBrush(BLACK_BRUSH));
				Ellipse(maskDC, 0, 0, 40, 40);
				
				unsigned int textY = height - 24; //The "- 24" keeps the lowest message from ending up behind message field
				messageWidth = width - 146;
				unsigned int messageHeight;
				//unsigned long long totalContentHeight = 0;
				wstring username;
				long offScreenContentHeight = (pData->totalContentHeight - (height - (48 + 48)));
				long pixelsToAdd = offScreenContentHeight - pData->scrollPos;
				wstring debugStr = L"content height=" + to_wstring((long long)pData->totalContentHeight) + L", scrollPos=" + to_wstring((long long)pData->scrollPos);
				//MessageBox(NULL, debugStr.c_str(), L"", MB_OK);
				bool addOnce = false;
				Gdiplus::Rect avatarRect;
				if (globalMessageList != NULL) {
					for (auto it = globalMessageList->begin(); it != globalMessageList->end(); it++) {
						if (pixelsToAdd > 450/*65*/) { //Using 450 instead of 65 prevents taller messages from disappearing when scrolling up. This number might need to be higher for taller messages so it would be best to use a formula instead
							pixelsToAdd -= it->messageHeight;
							continue;
						}
						if (!addOnce) {
							textY += pixelsToAdd;
							addOnce = true;
						}
						
						messageHeight = it->messageHeight;//getMessageHeight(messageWidth, it->text);
						//it->messageHeight = messageHeight;
						//totalContentHeight += messageHeight + 25;
						textY -= messageHeight;
						
						textRect.top = textY;
						textRect.bottom = textY + messageHeight;
						
						//Draw the text
						SetTextColor(hdc, it->deleted ? deletedMessageTextColor : messageTextColor);
						SelectObject(hdc, smallInfoFont);
						//DrawText(hdc, it->text.c_str(), it->text.length(), &textRect, DT_WORDBREAK | DT_EDITCONTROL);
						DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, textRect.left, textRect.top, (textRect.right - textRect.left), true, (unsigned char*)it->text.c_str(), it->text.length(), false, NULL);
						
						//Don't bother drawing anything else if the current message is at the top.
						if (textY < 48) break;
						
						//Draw the username
						textY -= 22;
						SetTextColor(hdc, RGB(255, 255, 255)); //TODO: draw username with the right color
						SelectObject(hdc, userNameFont);
						username = getUserNameWithDiscriminator(it->authorID);
						ExtTextOut(hdc, textRect.left, textY, NULL, NULL, username.c_str(), username.length(), NULL);
						
						//Draw the avatar
						userIcon = getUserAvatar(it->authorID);
						if (userIcon) {
							Gdiplus::Rect dest(16, (textY - 1), 40, 40);
							if (config.roundUserAvatars) {
								Gdiplus::GraphicsPath *gp = new Gdiplus::GraphicsPath();
								gp->AddEllipse(16, (textY - 1), 40, 40);
								GDIPlusOutputObject.SetClip(gp);
								delete gp;
							}
							GDIPlusOutputObject.DrawImage(userIcon, dest);
							GDIPlusOutputObject.ResetClip();
						}
					}
				}
				
				//Draw the header
				unsigned int channelHeaderX = 50;
				SetDCPenColor(hdc, mainGrayColor);
				SetBkColor(hdc, mainGrayColor);
				SelectObject(hdc, mainGrayColorBrush);
				Rectangle(hdc, 0, 0, width, 48);
				//Draw the pound sign
				SelectObject(iconHDC, hBmpLargePoundSign);
				BitBlt(hdc, 18, 15, 20, 18, iconHDC, 0, 0, SRCCOPY);
				//Draw the channel name
				SelectObject(hdc, channelNameFont);
				SetTextColor(hdc, RGB(255, 255, 255));
				//ExtTextOut(hdc, 50, 15, NULL, NULL, selectedChannelName.c_str(), selectedChannelName.length(), NULL);
				textRect.left = 50;
				textRect.top = 15;
				textRect.bottom = 35;
				textRect.right = (width - 15) - 225;
				//DrawText(hdc, selectedChannelName.c_str(), selectedChannelName.length(), &textRect, DT_SINGLELINE | DT_WORDBREAK | DT_NOPREFIX | DT_END_ELLIPSIS | DT_CALCRECT);
				DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, textRect.left, textRect.top, (textRect.right - textRect.left), false, (unsigned char*)selectedChannelName.c_str(), selectedChannelName.length(), true, &textSize);
				channelHeaderX += textSize.cx/*(textRect.right - textRect.left)*/ + 16;
				//DrawText(hdc, selectedChannelName.c_str(), selectedChannelName.length(), &textRect, DT_SINGLELINE | DT_WORDBREAK | DT_NOPREFIX | DT_END_ELLIPSIS);
				DrawTextWithColorEmojis(hdc, &GDIPlusOutputObject, textRect.left, textRect.top, (textRect.right - textRect.left), false, (unsigned char*)selectedChannelName.c_str(), selectedChannelName.length(), false, NULL);
				//Draw the 24-pixel vertical gray line after the channel name
				SetDCPenColor(hdc, RGB(66,69,74));
				MoveToEx(hdc, channelHeaderX, 12, NULL);
				LineTo(hdc, channelHeaderX, 36);
				//Draw the channel topic
				SelectObject(hdc, smallInfoFont);
				SetTextColor(hdc, RGB(185,187,190));
				channelHeaderX += 16;
				textRect.left = channelHeaderX;
				textRect.right = (width - (15 + 225));
				DrawText(hdc, utf8_to_wstring(selectedChannelTopic).c_str(), utf8_to_wstring(selectedChannelTopic).length(), &textRect, DT_SINGLELINE | DT_WORDBREAK | DT_NOPREFIX | DT_END_ELLIPSIS);
				
				//Draw the text field at the bottom
				//44 px for the text field
				//4 px of padding under it
				//48 px total
				SetDCPenColor(hdc, RGB(64, 68, 75));
				SelectObject(hdc, messageFieldBGBrush);
				RoundRectWidthHeight(hdc, 16, height - 48, width - (25 + 16), 44, 16, 16);
				
				//Update the scrollbar
				/*pData->totalContentHeight = totalContentHeight;
				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE;// | SIF_POS;
				//si.nMin = 0;
				si.nMax = totalContentHeight;
				si.nPage = height - 48;
				//si.nPos = 10000;
				//si.nTrackPos = 0;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);*/
				DeleteObject(maskedIconBmp);
				DeleteObject(roundMaskBmp);
				DeleteDC(maskedIconDC);
				DeleteDC(maskDC);
				DeleteDC(iconHDC);
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
				messageWidth = w - 146;
				//Only recalculate the total message height if the width changed
				if (w != pData->oldContentAreaWidth) {
					recalculateTotalMessageHeight(false);
					pData->oldContentAreaWidth = w;
				}
				MoveWindow(pData->hwndScrollbar, r.right - 15, 48, 15, h - 48, TRUE);
				
				//Move the message field
				MoveWindow(messageField, 72, h - 36, w - (72 + 15 + 15 /* the extra 15 is needed because we didn't subtract 15 from the width like we did when the field was created */), 20, TRUE);

				SCROLLINFO si = {0};
				GetScrollInfo(pData->hwndScrollbar, SB_CTL, &si);
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
				si.nMin = 0;
				//MessageBox(NULL, wstring(L"WM_SIZE, si.nMax=" + to_wstring((long long)si.nMax)).c_str(), L"", MB_OK);
				si.nPage = h - (48 + 48); //48px for the header and 48px for the message field
				si.nMax = pData->totalContentHeight;
				si.nPos = (pData->shouldScrollToBottom ? (si.nMax - si.nPage) - 1 : si.nPos);
				//si.nTrackPos = (pData->shouldScrollToBottom ? si.nMax : 0) - 1;
				pData->scrollPos = si.nPos;//(pData->shouldScrollToBottom ? si.nMax : 0) - 1;
				SetScrollInfo(pData->hwndScrollbar, SB_CTL, &si, true);
				//MessageBox(NULL, wstring(L"si.nPos=" + to_wstring((long long)si.nPos)).c_str(), L"", MB_OK);
			}
		break;
		case WM_VSCROLL:
			//TODO: scroll smoothly when dragging the scroll box
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
					si.nPos -= 40;//1;
					break;

					// User clicked the bottom arrow.
				case SB_LINEDOWN:
					si.nPos += 40;//1;
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
					si.nPos = (si.nTrackPos > ((si.nTrackPos / 10) * 10) ? si.nMax : ((si.nTrackPos / 10) * 10));
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
					r.top += 48; //Don't scroll the header
					r.bottom -= 48; //Don't scroll the message field
					ScrollWindow(wnd, 0, 40 * (yPos - si.nPos), &r, &r);
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
		case WM_CTLCOLOREDIT:
			if ((HWND)lParam == messageField) {
				hdc = (HDC)wParam;

				//Background when typing
				SetBkColor(hdc, RGB(64, 68, 75));
				SetTextColor(hdc, RGB(200, 200, 200));

				//Background when empty
				SetDCBrushColor(hdc, RGB(64, 68, 75));
				return (LRESULT)GetStockObject(DC_BRUSH);
			}
		break;
		case WM_DESTROY:
			DestroyWindow(messageField);
			return 0;
		break;
		default:
			return DefWindowProcW(wnd, msg, wParam, lParam);
	}
	return DefWindowProcW(wnd, msg, wParam, lParam);
}

unsigned int getMessageHeight(unsigned int width, string message) {
	/*RECT textRect;
	textRect.left = 0;
	textRect.top = 0;
	textRect.right = width;*/
	SIZE sz;
	//DrawText(tempHDC, message.c_str(), message.length(), &textRect, DT_WORDBREAK | DT_EDITCONTROL | DT_CALCRECT);
	DrawTextWithColorEmojis(tempHDC, NULL, 0, 0, width, true, (unsigned char*)message.c_str(), message.length(), true, &sz);
	
	unsigned int height = sz.cy;//textRect.bottom - textRect.top;
	if (height < 40) height = 40;
	height += MESSAGE_SPACING;
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
				} else if (wnd == messageField) {
					submitMessage();
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
	HMENU hSettingsMenu = CreateMenu();
	HMENU hHelpMenu = CreateMenu();
	
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_LOGIN, L"Log in");
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_LOGOUT, L"Log out");
	AppendMenuW(hUserMenu, MF_STRING, IDM_USER_PROFILE, L"User profile");
	
	AppendMenuW(hSettingsMenu, MF_STRING, IDM_SETTINGS_LOGGING, L"Logging");
	
	AppendMenuW(hHelpMenu, MF_STRING, IDM_HELP_USERGUIDE, L"User Guide");
	
	AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hUserMenu, L"User");
	AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hSettingsMenu, L"Settings");
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

wstring getUserAgent() {
	//Build the user-agent string
	//We want to do it here instead of during startup because it doesn't support Windows 2000.
	DWORD windowsVersion = GetVersion();
	DWORD majorVersion, minorVersion;
	majorVersion = (DWORD)(LOBYTE(LOWORD(windowsVersion)));
	minorVersion = (DWORD)(HIBYTE(LOWORD(windowsVersion)));
	
	wstring userAgent = versionString + L" (Windows NT ";
	userAgent += to_wstring((long long)majorVersion) + L"." + to_wstring((long long)minorVersion);
	
	SYSTEM_INFO systemInfo;
	GetNativeSystemInfo(&systemInfo);
	
	switch (systemInfo.wProcessorArchitecture) {
		case 0:
			userAgent += L" x86)";
			break;
		case 9:
			userAgent += L" x64)";
			break;
		case 5:
			userAgent += L" ARM)";
			break;
		case 12:
			userAgent += L" ARM64)";
			break;
		case 6:
			userAgent += L" Itanium)";
			break;
		case 0xffff:
		default:
			userAgent += L", unknown architecture)";
			break;
	}
	
	return userAgent;
}

void copyText(string text) {
	//Copied from user Judge Maygarden (https://stackoverflow.com/users/1491/judge-maygarden) on StackOverflow
	//https://stackoverflow.com/a/1264179
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, text.length() + 1);
	memcpy(GlobalLock(hMem), text.c_str(), text.length() + 1);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	GlobalFree(hMem);
}

void copyUnicodeText(wstring text) {
	//Copied from user Judge Maygarden (https://stackoverflow.com/users/1491/judge-maygarden) on StackOverflow
	//https://stackoverflow.com/a/1264179
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, (text.length() + 1) * sizeof(wchar_t));
	memcpy(GlobalLock(hMem), text.c_str(), (text.length() + 1) * sizeof(wchar_t));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	GlobalFree(hMem);
}

wstring getUserName(uint64_t id) {
	for (unsigned int i = 0; i < globalUserList.size(); i++) {
		if (globalUserList.at(i).id == id) return globalUserList.at(i).name;
	}
	return L"Unknown user " + to_wstring((long long)id);
}

wstring getUserNameWithDiscriminator(uint64_t id) {
	for (unsigned int i = 0; i < globalUserList.size(); i++) {
		if (globalUserList.at(i).id == id) return globalUserList.at(i).name + L" #" + to_wstring((long long)globalUserList.at(i).discriminator);
	}
	return L"Unknown user " + to_wstring((long long)id);
}

Gdiplus::Bitmap* getUserAvatar(uint64_t id) {
	for (unsigned int i = 0; i < globalUserList.size(); i++) {
		if (globalUserList.at(i).id == id) return globalUserList.at(i).hbmIcon;
	}
	return NULL;
}

void submitMessage() {
	WCHAR buffer[DISCORD_MAX_CHARACTERS];
	if (!GetWindowText(messageField, buffer, DISCORD_MAX_CHARACTERS)) {
		//MessageBox(NULL, to_wstring((long long)globalContentAreaData->scrollPos).c_str(), L"", MB_OK);
		return;
	}
	
	GenericDocument<UTF8<> > d;
	d.SetObject();
	Document::AllocatorType& allocator = d.GetAllocator();
	d.AddMember("content", StringRef(wstring_to_utf8(wstring(buffer)).c_str()), allocator);
	StringBuffer strbuf;
	rapidjson::Writer< StringBuffer, UTF8<> > writer(strbuf);
	d.Accept(writer);
	string json = strbuf.GetString();
	
	
	
	//RedrawWindow(hwndContentArea, NULL, NULL, NULL);
	//InvalidateRect(hwndContentArea, NULL, true);
	
	SetWindowText(messageField, L"");
}

void recalculateTotalMessageHeight(bool addLastMessageHeight) {
	unsigned long long totalContentHeight = 0;
	if (globalMessageList == NULL) return;
	unsigned int topMessageHeight, bottomMessageHeight;
	unsigned int idx = 0;
	for (auto i = globalMessageList->begin(); i != globalMessageList->end(); i++) {
		topMessageHeight = getMessageHeight(messageWidth, i->text.c_str());
		if (idx == 0) bottomMessageHeight = topMessageHeight;
		i->messageHeight = topMessageHeight;
		//MessageBox(NULL, to_wstring((long long)topMessageHeight).c_str(), L"", MB_OK);
		totalContentHeight += topMessageHeight;
		idx++;
	}
	totalContentHeight += (topMessageHeight*3); //TODO: fix the issue where the content area is partially filled, new messages are added, and it becomes impossible to scroll to the top one
	globalContentAreaData->totalContentHeight = totalContentHeight;// + (topMessageHeight*3);

	//Update the scrollbar
	SCROLLINFO si = {0};
	GetScrollInfo(globalContentAreaData->hwndScrollbar, SB_CTL, &si);
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_RANGE | (addLastMessageHeight ? SIF_POS : 0);
	si.nMax = totalContentHeight;
	if (addLastMessageHeight) {
		si.nPos += topMessageHeight;
		globalContentAreaData->scrollPos += topMessageHeight;
	}
	SetScrollInfo(globalContentAreaData->hwndScrollbar, SB_CTL, &si, true);
	//MessageBox(NULL, L"Done resizing scrollbar", L"", MB_OK);
	if (addLastMessageHeight) {
		RECT r;
		GetClientRect(hwndContentArea, &r);
		r.top += 48;
		r.bottom -= 48;
		r.right -= 15;
		ScrollWindow(hwndContentArea, 0, -topMessageHeight, &r, &r);
	}
	InvalidateRect(hwndContentArea, NULL, FALSE);
}

unsigned int DrawTextWithColorEmojis(HDC hdc, Gdiplus::Graphics *GDIPlusOutputObject, unsigned int x, unsigned int y, unsigned int width, /*TODO: height*/ bool multiline, unsigned char *string, unsigned int bytes, bool calculateOnly, SIZE *textSize) {
	//wstring_convert<codecvt_utf8<wchar_t>> cv;
	wstring tmp;
	unsigned char *ptr = string;
	RECT r;
	SIZE s;
	int isEmoji;
	bool shouldAdd4PxSpacing = false;
	GetTextExtentPoint32(hdc, L"A", 1, &s);
	unsigned int lineHeight = s.cy;
	unsigned int charSizeInBytes;
	int codepoint;
	unsigned int relativeX, relativeY;
	relativeX = relativeY = 0;
	//Pass-through anything that isn't a recognized emoji
	//"string" is a UTF-8 byte array.
	
	//This will be simple if only 1 line is required.
	if (!multiline) {
		r.right = x + width;
		r.top = y;
		r.bottom = y + lineHeight;

		//Find any emojis and get the width of the text before/between them
		unsigned int i, textSectionStartIdx, textSectionEndIdx; //"i" is specified in UTF-8 codepoints and the other 2 are bytes
		i = textSectionStartIdx = 0;
		while (bytes > 0 && relativeX < width) {
			codepoint = UTF8ToCodepoint(ptr, &charSizeInBytes, bytes);
			//MessageBox(NULL, wstring(L"Successful codepoint=" + to_wstring((long long)codepoint)+L", char bytes=" + to_wstring((long long)charSizeInBytes) + L", remaining bytes=" + to_wstring((long long)bytes)).c_str(), L"", MB_OK);
			if (codepoint < 0) {
				codepoint = 63; //An ASCII question mark. This is not a recognized emoji so increase the length of the text section
				tmp += ((wchar_t)codepoint);
			} else {
				//MessageBox(NULL, wstring(L"About to check isEmoji with codepoint " + to_wstring((long long)codepoint)).c_str(), L"", MB_OK);
				//isEmoji = UTF8CodepointIsEmoji(codepoint);
				//Get the specific emoji variant
				isEmoji = ReadEmoji(ptr, &charSizeInBytes, bytes);
				//MessageBox(NULL, wstring(L"codepoint=" + to_wstring((long long)codepoint) + L", isEmoji=" + to_wstring((long long)isEmoji) + L", size=" + to_wstring((long long)charSizeInBytes)).c_str(), L"", MB_OK);
				if (isEmoji >= 0) {
					//Draw the preceding text, if any, and then the emoji
					//textSectionEndIdx = i;
					if (tmp.length() > 0/*(textSectionEndIdx - textSectionStartIdx) > 0*/) {
						//Draw the text
						if (shouldAdd4PxSpacing) relativeX += 4;
						r.left = x + relativeX;
						//tmp = cv.from_bytes((const char*)(ptr + textSectionStartIdx), (const char*)(ptr + textSectionEndIdx + 1));
						if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
						GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
						relativeX += s.cx;
						//MessageBox(NULL, tmp.c_str(), L"", MB_OK);
						tmp.clear();
						shouldAdd4PxSpacing = true;
					}
					//Draw the emoji
					//drawEmoji(HDC hdc, unsigned char *ptr, int initialEmojiIdx, unsigned int x, unsigned int y, unsigned int size, unsigned int *charSizeInBytes, unsigned int maxBytes)
					//if (shouldAdd4PxSpacing) relativeX += 4;
					if (!calculateOnly) drawEmoji(GDIPlusOutputObject, isEmoji, x + relativeX, y, lineHeight);
					//ptr += charSizeInBytes;
					relativeX += lineHeight;
					shouldAdd4PxSpacing = true;
				} else {
					//The character was not a recognized emoji so increase the length of the text section
					tmp += ((wchar_t)codepoint);
					//textSectionEndIdx = i;
				}
			}
			ptr += charSizeInBytes;
			bytes -= charSizeInBytes;
			i++;
		}
		
		//Draw any remaining text
		if (relativeX < width && tmp.length() > 0/*(textSectionEndIdx - textSectionStartIdx) > 0*/) {
			//Draw the text
			//if (shouldAdd4PxSpacing) relativeX += 4;
			r.left = x + relativeX;
			//tmp = cv.from_bytes((const char*)(ptr + textSectionStartIdx), (const char*)(ptr + textSectionEndIdx + 1));
			if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
			GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
			if (s.cy > lineHeight) lineHeight = s.cy;
			if (textSize != NULL) {
				textSize->cx = relativeX + s.cx;
				textSize->cy = lineHeight;
			}
			//MessageBox(NULL, tmp.c_str(), L"", MB_OK);
			tmp.clear();
		}
		
		return 0;//height;
	}
	
	//We need to go word by word
	//Sentences will be broken at word boundaries when they are too long to fit on 1 line
	//Words that are too long will start on a new line and be broken as needed
	unsigned int wordStartByte, wordEndByte;
	wordStartByte = wordEndByte = 0;
	bool lineStart = true;
	bool shouldDisregardLineBreak = false; //This is to prevent double line breaks for Windows newline character pairs
	unsigned int maxChars, textWidth, totalHeight;
	totalHeight = lineHeight;
	//Loop until we find the end of a word
	while (bytes > 0) {
		codepoint = UTF8ToCodepoint(ptr, &charSizeInBytes, bytes);
		if (codepoint < 0) {
			codepoint = 63; //An ASCII question mark. This is not a recognized emoji so increase the length of the text section
			tmp += ((wchar_t)codepoint);
		} else if (codepoint == 10 || codepoint == 13) {
			if (!shouldDisregardLineBreak) {
				y += lineHeight;
				totalHeight += lineHeight;
				relativeX = 0;
				lineStart = true;
				shouldDisregardLineBreak = true;
			} else {
				shouldDisregardLineBreak = false;
			}
		} else if (codepoint == 32 || codepoint == 45) {
			//Draw a word since we reached a space or hyphen
			//Check if the word can fit on the current line
			if (codepoint == 45) tmp += L"-";
			GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
			//MessageBox(NULL, wstring(tmp + L", width=" + to_wstring((long long)s.cx) + L", limit=" + to_wstring((long long)(width - relativeX))).c_str(), L"", MB_OK);
			if (s.cx > (width - relativeX)) {
				//The word won't fit on the current line
				if (lineStart) {
					//If this is the first word on the current line, then the word needs to be broken
					//maxChars = GetMaxTextLengthForPixelWidth(hdc, width, tmp, &textWidth);
					//Start printing the word and breaking it as needed
					while (!tmp.empty()) {
						relativeX = 0;
						maxChars = GetMaxTextLengthForPixelWidth(hdc, width - relativeX, tmp, &textWidth);
						r.left = x + relativeX;
						r.top = y;
						r.bottom = y + lineHeight;
						r.right = x + width;
						if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), maxChars, NULL);
						if (tmp.length() == maxChars) break;
						y += lineHeight;
						totalHeight += lineHeight;
						tmp = tmp.substr(maxChars, wstring::npos);
					}
					tmp = (wchar_t)codepoint;
					relativeX = textWidth;
					//MessageBox(NULL, wstring(L"relativeX=" + to_wstring((long long)relativeX)).c_str(), L"", MB_OK);
					lineStart = false;
				} else {
					//If this is not the first word on the current line,
					//		and the word will fit on a single line, then we need to go to the next line
					//		and the word will not fit on a single line, then we should break it starting on the current line
					//MessageBox(NULL, wstring(L"tmp.at(0)="+to_wstring((long long)tmp.at(0))).c_str(), L"", MB_OK);
					if (s.cx > width) {
						//Start printing the word and breaking it as needed
						while (!tmp.empty()) {
							maxChars = GetMaxTextLengthForPixelWidth(hdc, width - relativeX, tmp, &textWidth);
							r.left = x + relativeX;
							r.top = y;
							r.bottom = y + lineHeight;
							r.right = x + width;
							if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), maxChars, NULL);
							if (tmp.length() == maxChars) break;
							y += lineHeight;
							totalHeight += lineHeight;
							relativeX = 0;
							tmp = tmp.substr(maxChars, wstring::npos);
						}
						relativeX = textWidth;
						lineStart = false;
					} else {
						if (tmp.length() > 1 && tmp.at(0) == 32) {
							//TODO: handle multiple contiguous spaces
							tmp = tmp.substr(1, wstring::npos);
							GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
						}
						y += lineHeight;
						totalHeight += lineHeight;
						relativeX = 0;
						
						r.left = x + relativeX;
						r.top = y;
						r.bottom = y + lineHeight;
						r.right = x + width;
						if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
						relativeX += s.cx;
						lineStart = false;
						tmp = (wchar_t)codepoint;
					}
					
					
					
					/*//Check if the word will fit now
					if (s.cx > (width - relativeX)) {
						//The word still won't fit so it has to be broken
						
					} else {
						//The word will fit on a new line
						r.left = x + relativeX;
						r.top = y;
						r.bottom = y + lineHeight;
						r.right = x + width;
						ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
						relativeX += s.cx;
						lineStart = false;
						tmp = (wchar_t)codepoint;
					}*/
				}
			} else {
				//The word will fit on the current line
				//MessageBox(NULL, wstring(L"\""+tmp + L"\"").c_str(), L"", MB_OK);
				r.left = x + relativeX;
				r.top = y;
				r.bottom = y + lineHeight;
				r.right = x + width;
				if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
				relativeX += s.cx;
				lineStart = false;
				tmp = (wchar_t)codepoint;
			}
		} else {
			isEmoji = ReadEmoji(ptr, &charSizeInBytes, bytes);
			if (isEmoji >= 0) {
				//Draw the emoji
				//Don't get into an infinite loop if the emoji is wider than the max paragraph width
				if (!tmp.empty()) {
					//If this is not the first word on the current line,
					//		and the word will fit on a single line, then we need to go to the next line
					//		and the word will not fit on a single line, then we should break it starting on the current line
					GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
					if (s.cx > (width - relativeX)) {
						//Start printing the word and breaking it as needed
						y += lineHeight;
						totalHeight += lineHeight;
						relativeX = 0;
						//lineStart = true;
						while (!tmp.empty()) {
							maxChars = GetMaxTextLengthForPixelWidth(hdc, width - relativeX, tmp, &textWidth);
							r.left = x + relativeX;
							r.top = y;
							r.bottom = y + lineHeight;
							r.right = x + width;
							if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), maxChars, NULL);
							if (tmp.length() == maxChars) break;
							y += lineHeight;
							totalHeight += lineHeight;
							relativeX = 0;
							tmp = tmp.substr(maxChars, wstring::npos);
						}
						relativeX = textWidth;
						lineStart = false;
					} else {
						//y += lineHeight;
						//relativeX = 0;
						
						r.left = x + relativeX;
						r.top = y;
						r.bottom = y + lineHeight;
						r.right = x + width;
						if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
						relativeX += s.cx;
						//lineStart = false;
					}
				}
				tmp.clear();
				
				if (lineHeight > (width - relativeX)) {
					//The emoji won't fit on this line
					relativeX = 0;
					y += lineHeight;
					totalHeight += lineHeight;
				}
				if (!calculateOnly) drawEmoji(GDIPlusOutputObject, isEmoji, x + relativeX, y, lineHeight);
				relativeX += lineHeight;
				lineStart = false;
			} else {
				tmp += ((wchar_t)codepoint);
			}
		}
		ptr += charSizeInBytes;
		bytes -= charSizeInBytes;
	}
	
	//Draw any remaining text
	//The text that remains is guaranteed to be a single word without emojis
	GetTextExtentPoint32(hdc, tmp.c_str(), tmp.length(), &s);
	//MessageBox(NULL, wstring(tmp + L", width=" + to_wstring((long long)s.cx) + L", limit=" + to_wstring((long long)(width - relativeX))).c_str(), L"", MB_OK);
	if (s.cx > (width - relativeX)) {
		//The word won't fit on the current line
		if (lineStart) {
			//If this is the first word on the current line, then the word needs to be broken
			//maxChars = GetMaxTextLengthForPixelWidth(hdc, width, tmp, &textWidth);
			//Start printing the word and breaking it as needed
			while (!tmp.empty()) {
				relativeX = 0;
				maxChars = GetMaxTextLengthForPixelWidth(hdc, width - relativeX, tmp, &textWidth);
				r.left = x + relativeX;
				r.top = y;
				r.bottom = y + lineHeight;
				r.right = x + width;
				if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), maxChars, NULL);
				if (tmp.length() == maxChars) break;
				y += lineHeight;
				totalHeight += lineHeight;
				tmp = tmp.substr(maxChars, wstring::npos);
			}
			tmp = (wchar_t)codepoint;
			relativeX = textWidth;
			//MessageBox(NULL, wstring(L"relativeX=" + to_wstring((long long)relativeX)).c_str(), L"", MB_OK);
			lineStart = false;
		} else {
			//If this is not the first word on the current line,
			//		and the word will fit on a single line, then we need to go to the next line
			//		and the word will not fit on a single line, then we should break it starting on the current line
			if (s.cx > width) {
				//Start printing the word and breaking it as needed
				while (!tmp.empty()) {
					maxChars = GetMaxTextLengthForPixelWidth(hdc, width - relativeX, tmp, &textWidth);
					r.left = x + relativeX;
					r.top = y;
					r.bottom = y + lineHeight;
					r.right = x + width;
					if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), maxChars, NULL);
					if (tmp.length() == maxChars) break;
					y += lineHeight;
					totalHeight += lineHeight;
					relativeX = 0;
					tmp = tmp.substr(maxChars, wstring::npos);
				}
				relativeX = textWidth;
				lineStart = false;
			} else {
				y += lineHeight;
				totalHeight += lineHeight;
				relativeX = 0;
				
				r.left = x + relativeX;
				r.top = y;
				r.bottom = y + lineHeight;
				r.right = x + width;
				if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
				relativeX += s.cx;
				lineStart = false;
				tmp = (wchar_t)codepoint;

				lineStart = false;
			}
			
			
			
			/*//Check if the word will fit now
			if (s.cx > (width - relativeX)) {
				//The word still won't fit so it has to be broken
				
			} else {
				//The word will fit on a new line
				r.left = x + relativeX;
				r.top = y;
				r.bottom = y + lineHeight;
				r.right = x + width;
				ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
				relativeX += s.cx;
				lineStart = false;
				tmp = (wchar_t)codepoint;
			}*/
		}
	} else {
		//The word will fit on the current line
		//MessageBox(NULL, tmp.c_str(), L"", MB_OK);
		r.left = x + relativeX;
		r.top = y;
		r.bottom = y + lineHeight;
		r.right = x + width;
		if (!calculateOnly) ExtTextOut(hdc, r.left, y, ETO_CLIPPED, &r, tmp.c_str(), tmp.length(), NULL);
		relativeX += s.cx;
		lineStart = false;
		tmp = (wchar_t)codepoint;
	}
	
	if (textSize != NULL) {
		textSize->cx = width; //TODO: return the actual width if the text required only 1 line
		textSize->cy = totalHeight + lineHeight;
	}
	
	/*for (unsigned int i = 0; i < bytes; i++) {
		isEmoji = ReadEmoji(ptr, &charSizeInBytes, bytes);
		ptr += charSizeInBytes;
		bytes -= charSizeInBytes;
		if (isEmoji >= 0) {
			//We need to stop drawing text and draw an emoji
		} else {
			//Add the non-emoji character to the string and draw it
		}
	}*/
	
	return 0;
}

int ReadEmoji(unsigned char *byteArray, unsigned int *charLength, unsigned int maxBytes) {
	//Check if byteArray points to an emoji character
	unsigned char *ptr = byteArray;
	unsigned int _charLength;
	int tmp = UTF8ToCodepoint(byteArray, &_charLength, maxBytes);
	int isEmoji = UTF8CodepointIsEmoji(tmp);
	//MessageBox(NULL, wstring(L"isEmoji=" + to_wstring((long long)isEmoji)).c_str(), L"", MB_OK);
	*charLength = _charLength;
	if (isEmoji < 0) return isEmoji;
	unsigned int firstCodepoint = emojiCodepoints[isEmoji][0];
	
	//Check if this is an emoji with modifiers
	//Check down first
	int emojiIdx = isEmoji;
	ptr += _charLength;
	maxBytes -= _charLength;
	int bestFullMatchIdx = -1;//isEmoji;
	unsigned int _emojiCodepointCount;
	unsigned int decodedCodepoints = 1;
	unsigned int codepoints[8]; //Emojis can have up to 8 codepoints
	unsigned int cumulativeCodepointBytes[8];
	codepoints[0] = firstCodepoint;
	cumulativeCodepointBytes[0] = _charLength;
	
	//Try to find a match. Read additional codepoints if necessary
	//Find the beginning of the list of variants of the first character since
	//the binary search used in UTF8CodepointIsEmoji() could have returned an item
	//in the middle of a group of emojis with modifiers.
	while (emojiIdx > 0 && emojiCodepoints[emojiIdx - 1][0] == firstCodepoint) emojiIdx--;
	//emojiIdx++; //Increment this because there's no need to check the first variant
	
	//emojiIdx now has the index of the 2nd variant of the emoji we're trying to match
	bool mismatch;
	bool failedToLoadCodepoints = false;
	unsigned int failedCodepointCount;
	int codepoint;
	unsigned int matchedCodepoints;
	unsigned int highestMatchedCodepoints = 0;
	while (emojiCodepoints[emojiIdx][0] == firstCodepoint) {
		//Find out how many codepoints are needed for this emoji variant
		_emojiCodepointCount = emojiCodepointCount[emojiIdx];

		//Don't bother checking this variant if we're too close to the end of the string
		//For example, an 8-codepoint emoji and only 3 remaining bytes
		if (failedToLoadCodepoints && _emojiCodepointCount >= failedCodepointCount) {
			emojiIdx++;
			continue;
		}
		
		//Load more codepoints if necessary
		if (_emojiCodepointCount > decodedCodepoints) {
			for (unsigned int i = decodedCodepoints; i < 8; i++) {
				//UTF8ToCodepoint(unsigned char* byteArray, unsigned int *charLength, unsigned int maxBytes)
				codepoint = UTF8ToCodepoint(ptr, &_charLength, maxBytes);
				if (codepoint < 0) {
					failedToLoadCodepoints = true;
					failedCodepointCount = i;
					break;
				}
				codepoints[i] = codepoint;
				decodedCodepoints++;
				ptr += _charLength;
				maxBytes -= _charLength;
				cumulativeCodepointBytes[i] = cumulativeCodepointBytes[i - 1] + _charLength;
			}
		}
		
		//Continue if we couldn't load enough codepoints
		if (_emojiCodepointCount > decodedCodepoints) {
			emojiIdx++;
			continue;
		}
		
		//Compare the loaded codepoints to the current emoji variant
		mismatch = false;
		matchedCodepoints = 1;
		for (unsigned int i = 1; i < _emojiCodepointCount; i++) {
			if (codepoints[i] != emojiCodepoints[emojiIdx][i]) {
				mismatch = true;
				break;
			} else {
				matchedCodepoints++;
			}
		}
		if (!mismatch) {
			if (matchedCodepoints > highestMatchedCodepoints) {
				highestMatchedCodepoints = matchedCodepoints;
				*charLength = cumulativeCodepointBytes[highestMatchedCodepoints - 1];
				bestFullMatchIdx = emojiIdx;
			}
		}

		emojiIdx++;
	}
	wstring debug = L"ReadEmoji("+utf8_to_wstring(string((char*)byteArray))+L"), consumed "+to_wstring((long long)*charLength)+L" bytes, returning "+to_wstring((long long)bestFullMatchIdx);
	//MessageBox(NULL, debug.c_str(), L"", MB_OK);
	return bestFullMatchIdx;
}

int UTF8CodepointIsEmoji(int codepoint) {
	//Use a binary search instead of a linear search since this has to run for every visible emoji every time the screen is painted.
	//The worst case time complexity for a binary search is O(log n) which is much better than O(n) for a linear search
	if (codepoint < MIN_EMOJI || codepoint > MAX_EMOJI) return -1;
	unsigned int lowerBound, midpoint, upperBound;
	lowerBound = 0;
	upperBound = EMOJI_COUNT - 1;
	const unsigned int *ptr;
//int cycle=0;
	while (true) {
		midpoint = (lowerBound + upperBound) >> 1;
		ptr	= emojiCodepoints[midpoint];
		//MessageBox(NULL, wstring(L"UTF8CodepointIsEmoji() Attempt #"+to_wstring((long long)cycle)+L": lower="+to_wstring((long long)lowerBound)+L", mid="+to_wstring((long long)midpoint)+L", upper="+to_wstring((long long)upperBound)+L", target="+to_wstring((long long)codepoint)).c_str(), L"", MB_OK);
		if ((lowerBound >= upperBound/* || lowerBound == midpoint*/) && (*ptr) != codepoint) break;
		if ((*ptr) == codepoint) {
			//MessageBox(NULL, wstring(L"Codepoint " + to_wstring((long long)codepoint) + L" is an emoji with index " + to_wstring((long long)midpoint)).c_str(), L"", MB_OK);
			return midpoint;
		} else if ((*ptr) > codepoint) {
			upperBound = midpoint - 1;
		} else if ((*ptr) < codepoint) {
			lowerBound = midpoint + 1;
		}//cycle++;
	}

	return -1;
}

int UTF8ToCodepoint(unsigned char* byteArray, unsigned int *charLength, unsigned int maxBytes) {
	wstring debug = L"UTF8ToCodepoint operating on starting byte " + to_wstring((long long)*byteArray) + L" with " + to_wstring((long long)maxBytes) + L" bytes remaining";
	//MessageBox(NULL, debug.c_str(), L"", MB_OK);
	//Returns the codepoint, or -1 if there was an error.
	//charLength will contain the number of bytes consumed.
	unsigned char* ptr = byteArray;
	*charLength = 0;
	unsigned long retVal = 0;
	if ((*byteArray) & 0x80) {
		//This is a character greater than 127
		//Get the number of bytes
		if (((*byteArray) >> 3) == 0x1e) {
			//4 bytes
			if (maxBytes < 4) {*charLength = maxBytes; return -1;}
			retVal = (*ptr++) & 0x7;
			maxBytes--;
			(*charLength)++;
			if (((*ptr) >> 6) != 0x2) {*charLength = 1; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
			maxBytes--;
			(*charLength)++;
			if (((*ptr) >> 6) != 0x2) {*charLength = 2; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
			maxBytes--;
			(*charLength)++;
			if (((*ptr) >> 6) != 0x2) {*charLength = 3; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
			(*charLength)++;
		} else if (((*byteArray) >> 4) == 0xe) {
			//3 bytes
			if (maxBytes < 3) {*charLength = maxBytes; return -1;}
			retVal = (*ptr++) & 0xf;
			maxBytes--;
			(*charLength)++;
			if (((*ptr) >> 6) != 0x2) {*charLength = 1; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
			maxBytes--;
			(*charLength)++;
			if (((*ptr) >> 6) != 0x2) {*charLength = 2; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
			(*charLength)++;
		} else if (((*byteArray) >> 5) == 0x6) {
			//2 bytes
			if (maxBytes < 2) {*charLength = maxBytes; return -1;}
			retVal = (*ptr++) & 0x1f;
			maxBytes--;
			if (((*ptr) >> 6) != 0x2) {*charLength = 1; return -1;}
			retVal = (retVal << 6) | ((*ptr++) & 0x3f);
		} else {
			//Error
			*charLength = 1;
			return -1;
		}
	} else {
		//This is a character between 0 and 127 inclusive
		//MessageBox(NULL, L"Returning an ASCII byte", L"", MB_OK);
		(*charLength) = 1;
		//MessageBox(NULL, wstring(L"Returning ASCII byte " + to_wstring((long long)*byteArray)).c_str(), L"", MB_OK);
		return (int)(*byteArray);
	}
	return retVal;
}

void drawEmoji(Gdiplus::Graphics *GDIPlusOutputObject, int emojiIdx, unsigned int x, unsigned int y, unsigned int size) {
	bool emojiIsInMemory = emojiIsLoaded[emojiIdx / 8] & (1 << (7 - (emojiIdx % 8)));
	if (!emojiIsInMemory) {
		string filename = ".\\img\\emojis\\";
		filename += emojiFilenames[emojiIdx];
		filename += ".png";
		emojiBitmaps[emojiIdx] = new Gdiplus::Bitmap(utf8_to_wstring(filename).c_str(), false);
		emojiIsLoaded[emojiIdx / 8] |= (1 << (7 - (emojiIdx % 8)));
	}
	Gdiplus::Rect emojiRect(x, y, size, size);
	GDIPlusOutputObject->DrawImage(emojiBitmaps[emojiIdx], emojiRect);
}

unsigned int GetMaxTextLengthForPixelWidth(HDC hdc, unsigned int width, wstring str, unsigned int *outputWidth) {
	SIZE s;
	//Check if the text will fit as-is
	GetTextExtentPoint32(hdc, str.c_str(), str.length(), &s);
	if (s.cx <= width) {
		*outputWidth = s.cx;
		return str.length();
	}
	
	//Use a method similar to a binary search to find the maximum number of characters from this string that will fit in the width
	unsigned int max, oldMax, oldMax2/*, cycle*/;
	max = str.length() >> 1;
	oldMax = str.length();
	//cycle = 0;
	do {
		GetTextExtentPoint32(hdc, str.c_str(), max, &s);
		//MessageBox(NULL, wstring(L"GetMaxTextLength Attempt #" + to_wstring((long long)cycle + 1) + L": \""+str+L"\", width="+to_wstring((long long)width)+L", s.cx="+to_wstring((long long)s.cx)+L", max="+to_wstring((long long)max)+L", oldMax="+to_wstring((long long)oldMax)).c_str(), L"", MB_OK);
		if (s.cx > width) {
			oldMax = max;
			oldMax2 = max;
			max >>= 1;
		} else if (s.cx < width) {
			oldMax2 = max;
			max = (max + oldMax) >> 1;
		} else {
			*outputWidth = s.cx;
			return max;
		}
		//cycle++;
	} while (max != oldMax2);
	//MessageBox(NULL, wstring(L"cycles="+to_wstring((long long)cycle)+L", max characters="+to_wstring((long long)max)).c_str(), L"", MB_OK);
	*outputWidth = s.cx;
	return max;
}

void loadBitmaps() {
	hBmpHomeIcon = new Gdiplus::Bitmap(L"img\\home_icon.bmp", false);
}

void deleteBitmaps() {
	delete hBmpHomeIcon;
}

void drawServerIcon(HDC hdc, Gdiplus::Bitmap* icon, int x, int y, int roundStyle /* 0=none, 1=round, 2=hover*/) {
	if (icon) {
		Gdiplus::Bitmap *userIcon;
		Gdiplus::Graphics GDIPlusOutputObject(hdc);
		GDIPlusOutputObject.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
		Gdiplus::ImageAttributes attrs;

		Gdiplus::Rect iconRect;
		Gdiplus::Rect dest(x, y, 48, 48);
		if (roundStyle > 0) {
			Gdiplus::GraphicsPath *gp = new Gdiplus::GraphicsPath();
			if (roundStyle == 1) {
				gp->AddEllipse(x, y, 48, 48);
			} else if (roundStyle == 2) {
				GetRoundRectPath(gp, Gdiplus::Rect(x, y, 48, 48), 20);
			}
			GDIPlusOutputObject.SetClip(gp);
			delete gp;
		}
		GDIPlusOutputObject.DrawImage(icon, dest);
	}
}

//Copied from user Zeus on StackOverflow
//https://stackoverflow.com/a/67055964/6040033
void GetRoundRectPath(Gdiplus::GraphicsPath *pPath, Gdiplus::Rect r, int dia) {
    // diameter can't exceed width or height
    if(dia > r.Width)    dia = r.Width;
    if(dia > r.Height)    dia = r.Height;

    // define a corner 
    Gdiplus::Rect Corner(r.X, r.Y, dia, dia);

    // begin path
    pPath->Reset();

    // top left
    pPath->AddArc(Corner, 180, 90);    

    // tweak needed for radius of 10 (dia of 20)
    if(dia == 20)
    {
        Corner.Width += 1; 
        Corner.Height += 1; 
        r.Width -=1; r.Height -= 1;
    }

    // top right
    Corner.X += (r.Width - dia - 1);
    pPath->AddArc(Corner, 270, 90);    
    
    // bottom right
    Corner.Y += (r.Height - dia - 1);
    pPath->AddArc(Corner,   0, 90);    
    
    // bottom left
    Corner.X -= (r.Width - dia - 1);
    pPath->AddArc(Corner,  90, 90);

    // end path
    pPath->CloseFigure();
}

uint64_t GetSystemTimeAsUnixTime() {
   //Get the number of seconds since January 1, 1970 12:00am UTC
   //Code released into public domain; no attribution required.

   const uint64_t UNIX_TIME_START = 0x019DB1DED53E8000; //January 1, 1970 (start of Unix epoch) in "ticks"
   const uint64_t TICKS_PER_SECOND = 10000000; //a tick is 100ns

   FILETIME ft;
   GetSystemTimeAsFileTime(&ft); //returns ticks in UTC

   //Copy the low and high parts of FILETIME into a LARGE_INTEGER
   //This is so we can access the full 64-bits as an Int64 without causing an alignment fault
   LARGE_INTEGER li;
   li.LowPart  = ft.dwLowDateTime;
   li.HighPart = ft.dwHighDateTime;
 
   //Convert ticks since 1/1/1970 into seconds
   return (li.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND;
}

void addMessageToDataModel(uint64_t serverID, uint64_t channelID, uint64_t messageID, uint64_t authorID, string content) {
	cout << endl << "addMessageToDataModel(server " << serverID << ", channel " << channelID << ", message " << messageID << ", authorID " << authorID;
	ServerListItem *server = NULL;
	Message m;
	m.id = messageID;
	m.authorID = authorID;
	m.text = content;
	m.deleted = false;
	/*if (serverID != -1) {
		//We can speed this up if we know the server ID
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel) && !foundServer; ++it) {
			if (it->id == serverID) {
				server = &(*it);
				break;
			}
		}
	} else */{
		//We have to do an exhaustive search for the channel
		bool foundChannel = false;
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel) && !foundChannel; ++it) { //Servers
			cout << endl << "server " << it->id;
			for (auto it2 = begin(it->dataModel); it2 != end(it->dataModel) && !foundChannel; ++it2) { //Categories
				cout << endl << "\tcategory " << it2->id;
				for (auto it3 = begin(it2->channels); it3 != end(it2->channels) && !foundChannel; ++it3) { //Channels
					cout << endl << "\t\tchannel " << it3->id;
					if (it3->id == channelID) {
						cout << endl << "\t\t\tAdding message";
						it3->messages.push_back(m);
						recalculateTotalMessageHeight(true);
						foundChannel = true;
					}
				}
			}
		}
	}
}

void deleteMessageFromDataModel(uint64_t serverID, uint64_t channelID, uint64_t messageID) {
	ServerListItem *server = NULL;
	/*if (serverID != -1) {
		//We can speed this up if we know the server ID
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel); ++it) {
			if (it->id == serverID) {
				server = &(*it);
				break;
			}
		}
	} else */{
		//We have to do an exhaustive search for the channel
		bool foundMessage = false;
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel) && !foundMessage; ++it) { //Servers
			for (auto it2 = begin(it->dataModel); it2 != end(it->dataModel) && !foundMessage; ++it2) { //Categories
				for (auto it3 = begin(it2->channels); it3 != end(it2->channels) && !foundMessage; ++it3) { //Channels
					for (auto it4 = begin(it3->messages); it4 != end(it3->messages) && !foundMessage; ++it4) { //Messages
						if (it4->id == channelID) {
							cout << endl << "\t\t\tDeleting message";
							it4->deleted = true;
							foundMessage = true;
						}
					}
				}
			}
		}
	}
}

void markChannelAsUnread(uint64_t serverID, uint64_t channelID) {
	ServerListItem *server = NULL;
	/*if (serverID != -1) {
		//We can speed this up if we know the server ID
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel); ++it) {
			if (it->id == serverID) {
				server = &(*it);
				break;
			}
		}
	} else */{
		//We have to do an exhaustive search for the channel
		bool foundChannel = false;
		for (auto it = begin(globalServerListData->dataModel); it != end(globalServerListData->dataModel) && !foundChannel; ++it) { //Servers
			for (auto it2 = begin(it->dataModel); it2 != end(it->dataModel) && !foundChannel; ++it2) { //Categories
				for (auto it3 = begin(it2->channels); it3 != end(it2->channels) && !foundChannel; ++it3) { //Channels
					if (it3->id == channelID) {
						it3->unread = true;
						foundChannel = true;
					}
				}
			}
		}
	}
}

void addMessageToLog(GenericValue<UTF8<>> *messageJSON) {
	//Skip messages without content
	if ((*messageJSON).FindMember("content") == (*messageJSON).MemberEnd()) return;
	//Check if the user is logging this server
	for (auto it = begin(config.loggingServers); it != end(config.loggingServers); ++it) {
		if (it->id == stoull((*messageJSON)["guild_id"].GetString())) {
			cout << endl << "Logging message \"" << (*messageJSON)["content"].GetString() << "\"";
			sqlite3_stmt *stmt;
			string query = "INSERT OR IGNORE INTO messages(ID, messageType, channelID, content, timestamp, timestampEdited, authorID, pinned) VALUES(?,?,?,?,?,?,?,?);";
			sqlite3_prepare_v2(it->db, query.c_str(), query.length(), &stmt, NULL);
			sqlite3_bind_int64(stmt, 1, stoull((*messageJSON)["id"].GetString()));
			int type = (*messageJSON)["type"].GetInt();
			string typeString = to_string((long long)type);
			if (type == 0) {
				typeString = "Default";
			} else if (type == 6) {
				typeString = "ChannelPinnedMessage";
			}
			sqlite3_bind_text(stmt, 2, typeString.c_str(), typeString.length(), SQLITE_STATIC);
			sqlite3_bind_int64(stmt, 3, stoull((*messageJSON)["channel_id"].GetString()));
			string content = (*messageJSON)["content"].GetString();
			sqlite3_bind_text(stmt, 4, content.c_str(), content.length(), SQLITE_STATIC);
			sqlite3_bind_text(stmt, 5, string(((*messageJSON)["timestamp"]).GetString()).c_str(), string(((*messageJSON)["timestamp"]).GetString()).length(), SQLITE_STATIC);
			if ((*messageJSON).FindMember("edited_timestamp") != (*messageJSON).MemberEnd() && !(*messageJSON)["edited_timestamp"].IsNull()) {
				sqlite3_bind_text(stmt, 6, string(((*messageJSON)["edited_timestamp"]).GetString()).c_str(), string(((*messageJSON)["edited_timestamp"]).GetString()).length(), SQLITE_STATIC);
			} else {
				sqlite3_bind_null(stmt, 6);
			}
			sqlite3_bind_int64(stmt, 7, stoull((*messageJSON)["author"]["id"].GetString()));
			sqlite3_bind_int(stmt, 8, (*messageJSON)["pinned"].GetBool() ? 1 : 0);
			sqlite3_step(stmt);
			
			break;
		}
	}
}

void markMessageAsDeletedInLog(GenericValue<UTF8<>> *messageJSON) {
	//Check if the user is logging this server
	for (auto it = begin(config.loggingServers); it != end(config.loggingServers); ++it) {
		if (it->id == stoull((*messageJSON)["guild_id"].GetString())) {
			cout << endl << "Deleting message " << (*messageJSON)["id"].GetString() << "";
			sqlite3_stmt *stmt;
			string query = "UPDATE messages SET deleted=1 WHERE ID=?;";
			sqlite3_prepare_v2(it->db, query.c_str(), query.length(), &stmt, NULL);
			sqlite3_bind_int64(stmt, 1, stoull((*messageJSON)["id"].GetString()));
			sqlite3_step(stmt);
			
			break;
		}
	}
}