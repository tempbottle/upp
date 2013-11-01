topic "SDL install";
[ $$0,0#00000000000000000000000000000000:Default]
[a83;*R6 $$1,0#31310162474203024125188417583966:caption]
[{_}%EN-US 
[s1; [+184 SDL install]&]
[s0; [2 SDL is easy and safe to install.]&]
[s0; &]
[s0; [* In Linux]&]
[s0;2 &]
[s0; [2 Install package libsdl1.2`-dev.]&]
[s0;2 &]
[s0;2 &]
[s0; [* In Windows]&]
[s0;2 &]
[s0; [*2 Safe way]&]
[s0;#2 &]
[s0;# [2 Download ][^https`:`/`/sourceforge`.net`/projects`/upp`/files`/GPL`-sources`/SDL`%20plugin`_LGPL`.7z`/download^2 S
DL][2  from U`+`+ Sourceforge following the link. They include 
.dll, .lib, .a, .h and source code for recent versions.]&]
[s0;#2 &]
[s0;# [2 Copy the downloaded folders in upp folder. You will get a 
folder structure like this:]&]
[s0;# [2 drive:`\upp`\plugin`_LGPL`\SDL]&]
[s0;2 &]
[s0; [2 In Setup/Build Methods menu include the next folders:]&]
[s0;%- &]
[ {{3371:3564:3065 [s0;= [2 PATH `- executable directories]]
:: [s0;= [2 INCLUDE directories]]
:: [s0;= [2 LIB directories]]
:: [s0; [2 drive:`\upp]]
:: [s0; [2 drive:`\upp`\plugin`_LGPL`\SDL`\include]]
:: [s0; [2 drive:`\upp`\plugin`_LGPL`\SDL`\lib]]}}&]
[s0;2 &]
[s0;2 &]
[s0; [*2 Medium/Hard]&]
[s0;2 &]
[s0; [2 Download binaries/prebuilt packages from ][^http`:`/`/www`.libsdl`.org`/download`-1`.2`.php^2 h
ere][2 .]&]
[s0;2 &]
[s0;i150;O0; [2 http://www.libsdl.org/release/SDL`-devel`-1.2.14`-VC8.zip]&]
[s0;i150;O0; [2 http://www.libsdl.org/release/SDL`-devel`-1.2.14`-mingw32.tar.gz]&]
[s0;2 &]
[s0; [2 unzip the stuff into 2 separate locations, e.g]&]
[s0;2 &]
[s0; [2 C:`\SDL`-devel`-1.2.14`-VC8`\SDL`-1.2.14]&]
[s0; [2 C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14]&]
[s0;2 &]
[s0; [2 the build methods need to access those respective folders]&]
[s0;2 &]
[s0; [2 MSC build method, add to]&]
[s0;2 &]
[s0; [2 PATH: C:`\SDL`-devel`-1.2.14`-VC8`\SDL`-1.2.14`\lib]&]
[s0; [2 INCLUDE: C:`\SDL`-devel`-1.2.14`-VC8`\SDL`-1.2.14`\include]&]
[s0; [2 LIB: C:`\SDL`-devel`-1.2.14`-VC8`\SDL`-1.2.14`\lib]&]
[s0;2 &]
[s0; [2 MINGW/TDMGCC build method, add to]&]
[s0;2 &]
[s0; [2 PATH: C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14`\lib]&]
[s0; [2 -|-|C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14`\bin]&]
[s0; [2 INCLUDE: C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14`\include]&]
[s0; [2 LIB: C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14`\lib]&]
[s0; [2 -|-|C:`\SDL`-devel`-1.2.14`-mingw32`\SDL`-1.2.14`\bin]&]
[s0;2 &]
[s0; [2 the MSC libraries only come in shared linkage flavor, while 
the mingw flavor can be linked both shared and staticly.]&]
[s0; [2 the mingw SDL.dll.a is needed for static linkage and has got 
that weired name. who knows why. the SDL.dll comes in bin folder, 
thats why double folder specification is needed fir MINGW build 
method]&]
[s0;2 &]
[s0; [2 the WinMain`@16 compile problem for mingw (google for it) makes 
the change of lib link order obligatory, thats why mingw32 is 
specified explicitly last. this makes the ]&]
[s0; [2 WINAPI WinMain(...) `{ return main(); `}]&]
[s0; [2 hack obsolete and enables the native usage of SDL means to 
handle entry point.]&]
[s0; [2 SDL redefines your own main to be SDL`_main (see SDL.h), and 
provides own main. ]&]
[s0; [2 the signature is critical.it must be]&]
[s0; [2 int main(int argc, char`* argv`[`]);]&]
[s0;2 &]
[s0;2 ]