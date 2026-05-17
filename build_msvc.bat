del talk32.exe
del main.obj
del talk32.pdb
cl.exe /c /EHsc /MD main.cpp
link.exe /RELEASE /NODEFAULTLIB:LIBCMT /LTCG /INCREMENTAL:NO /NOLOGO -subsystem:windows,5.01 kernel32.lib libcurl\lib\libcurl.lib wolfssl\Release\Win32\wolfssl.lib zlib\zs.lib cryptopp890\Win32\Output\Release\cryptlib.lib ws2_32.lib mswsock.lib advapi32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib zstd\libzstd_static.lib -out:talk32.exe main.obj shell32.lib comctl32.lib sqlite3.lib Htmlhelp.lib gdiplus.lib winmm.lib wldap32.lib crypt32.lib
mt.exe -nologo -manifest "talk32.exe.manifest" -outputresource:"talk32.exe;#1"