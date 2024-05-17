del talk32.exe
del main.obj
del talk32.pdb
clang-cl.exe /c /EHsc /MD /Z7 -Wno-everything main.cpp
link.exe /DEBUG /NODEFAULTLIB:LIBCMT /INCREMENTAL:NO /NOLOGO /PDB:talk32.pdb -subsystem:console,5.01 kernel32.lib libcurl\lib\libcurl_a.lib OpenSSL\lib\libcrypto.lib OpenSSL\lib\libssl.lib zlib\zlibstat.lib cryptopp890\Win32\Output\Release\cryptlib.lib ws2_32.lib mswsock.lib advapi32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib -out:talk32.exe main.obj kernel32.lib  ws2_32.lib mswsock.lib advapi32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib shell32.lib comctl32.lib libcurl\lib\libcurl_a.lib sqlite3.lib Htmlhelp.lib gdiplus.lib ws2_32.lib winmm.lib wldap32.lib crypt32.lib
mt.exe -nologo -manifest "talk32.exe.manifest" -outputresource:"talk32.exe;#1"