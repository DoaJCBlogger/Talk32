del talk32.exe
del main.obj
del talk32.pdb
cl.exe /c /EHsc /MD main.cpp
link.exe /RELEASE /NODEFAULTLIB:LIBCMT /INCREMENTAL:NO /NOLOGO -subsystem:console,5.01 kernel32.lib libcurl\lib\libcurl_a.lib OpenSSL\lib\libcrypto.lib OpenSSL\lib\libssl.lib zlib\zlibstat.lib ws2_32.lib mswsock.lib advapi32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib -out:talk32.exe main.obj kernel32.lib  ws2_32.lib mswsock.lib advapi32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib shell32.lib comctl32.lib libcurl\lib\libcurl_a.lib sqlite3.lib Htmlhelp.lib gdiplus.lib ws2_32.lib winmm.lib wldap32.lib crypt32.lib
mt.exe -nologo -manifest "talk32.exe.manifest" -outputresource:"talk32.exe;#1"