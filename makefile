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
#linkdebug = /RELEASE

all: $(Proj).exe

$(Proj).obj:
	$(cc) $(cdebug) $(cflags) $(cvarsdll) main.cpp

$(Proj).exe: $(LinkObjs)
	$(link) $(linkdebug) $(guilflags) $(guilibsdll) -out:$@ $(LinkObjs) $(guilibs) shell32.lib comctl32.lib libcurl\lib\libcurl_a.lib gdiplus.lib ws2_32.lib winmm.lib wldap32.lib crypt32.lib
	mt.exe -nologo -manifest "$(Proj).exe.manifest" -outputresource:"$(Proj).exe;#1"

clean:
	-if exist main.obj del main.obj
	-if exist $(Proj).exe del $(Proj).exe
	-if exist $(Proj).pdb del $(Proj).pdb
	-if exist vc60.pdb del vc60.pdb
