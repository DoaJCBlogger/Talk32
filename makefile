#This file is part of Talk32, a lightweight unofficial Discord client
#Copyright © 2020 Designing on a juicy cup
#
#Talk32 is free software; you can redistribute it and/or
#modify it under the terms of the GNU General Public License
#as published by the Free Software Foundation; either version 2
#of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

!include <win32.mak>

Proj = talk32

LinkObjs = main.obj

all: $(Proj).exe

$(Proj).obj: main.cpp
	$(cc) $(cflags) $(cvars) $(cdebug) main.cpp

$(Proj).exe: $(LinkObjs)
	$(link) $(linkdebug) $(guiflags) -out:$@ $(LinkObjs) $(guilibs) shell32.lib comctl32.lib OpenSSL_1.1.1b_winxp_x86\lib\libcrypto.lib OpenSSL_1.1.1b_winxp_x86\lib\libssl.lib zlib-1.2.11\contrib\vstudio\vc10\x86\ZlibStatRelease\zlibstat.lib curl\builds\libcurl-vc-x86-release-static-ssl-static-zlib-static-ipv6-sspi\lib\libcurl_a.lib gdiplus.lib ws2_32.lib winmm.lib wldap32.lib
	mt.exe -nologo -manifest "$(Proj).exe.manifest" -outputresource:"$(Proj).exe;#1"

clean:
	-if exist main.obj del main.obj
	-if exist $(Proj).exe del $(Proj).exe
	-if exist $(Proj).pdb del $(Proj).pdb
	-if exist vc60.pdb del vc60.pdb
