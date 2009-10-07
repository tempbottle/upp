topic "SysInfo function reference";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,0#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_}%EN-US 
[s0;%- [*R6 SysInfo]&]
[s0; &]
[s0; &]
[ {{10000@1 [s0; [* Running files and commands]]}}&]
[s3; &]
[s5;:GetExtExecutable`(const String`):%- [_^String^ String]_[* GetExtExecutable]([@(0.0.255) c
onst]_[_^String^ String]_[*@3 ext])&]
[s2; Gets the program that will open by default the files with extension 
[%-*@3 ext].&]
[s0; &]
[s0; -|[/ Example:]&]
[s0; [/ -|GetExtExecutable(`"html`") `-> `"Firefox.exe`"]&]
[s3; &]
[s4;%- &]
[s5;:LaunchFile`(const String`):%- [@(0.0.255) bool]_[* LaunchFile]([@(0.0.255) const]_[_^String^ S
tring]_[*@3 file])&]
[s2; Opens the file [%-*@3 file ]with the adecuated program defined 
in the OS by default.&]
[s0; &]
[s0; [/ -|Example:]&]
[s0; [/ -|LaunchFile(`"c:`\`\My spreadsheet.txt`"). It will open default 
program (probably Notepad) with document `"My spreadsheet.txt`".]&]
[s3; &]
[s0; &]
[ {{10000@1 [s0; [* Obtaining special folders]]}}&]
[s0;%- &]
[s5;:GetDesktopFolder`(`):%- [_^String^ String]_[* GetDesktopFolder]()&]
[s2; Gets the default Desktop folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetProgramsFolder`(`):%- [_^String^ String]_[* GetProgramsFolder]()&]
[s2; Gets the default programs folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetAppDataFolder`(`):%- [_^String^ String]_[* GetAppDataFolder]()&]
[s2; Gets the default application data folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetMusicFolder`(`):%- [_^String^ String]_[* GetMusicFolder]()&]
[s2; Gets the default music files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetPicturesFolder`(`):%- [_^String^ String]_[* GetPicturesFolder]()&]
[s2; Gets the default picture files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetVideoFolder`(`):%- [_^String^ String]_[* GetVideoFolder]()&]
[s2; Gets the default video files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetPersonalFolder`(`):%- [_^String^ String]_[* GetPersonalFolder]()&]
[s2; Gets the default personal files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetTemplatesFolder`(`):%- [_^String^ String]_[* GetTemplatesFolder]()&]
[s2; Gets the default templates files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetDownloadFolder`(`):%- [_^String^ String]_[* GetDownloadFolder]()&]
[s2; Gets the default file download folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetRootFolder`(`):%- [_^String^ String]_[* GetRootFolder]()&]
[s2; Gets the default root folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetTempFolder`(`):%- [_^String^ String]_[* GetTempFolder]()&]
[s2; Gets the default temp files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetOsFolder`(`):%- [_^String^ String]_[* GetOsFolder]()&]
[s2; Gets the default operating system files folder path.&]
[s3;%- &]
[s4;%- &]
[s5;:GetSystemFolder`(`):%- [_^String^ String]_[* GetSystemFolder]()&]
[s2; Gets the default system files folder path.&]
[s3;%- &]
[s0; &]
[ {{10000@1 [s0; [* Hardware, BIOS, OS and Distro info]]}}&]
[s0;%- &]
[s5;:GetSystemInfo`(String`&`,String`&`,String`&`,int`&`):%- [@(0.0.255) void]_[* GetSyst
emInfo]([_^String^ String]_`&[*@3 manufacturer], [_^String^ String]_`&[*@3 productName], 
[_^String^ String]_`&[*@3 version], [@(0.0.255) int]_`&[*@3 numberOfProcessors])&]
[s2; Returns hardware information including computer [%-*@3 manufacturer, 
] [%-*@3 productName, ] [%-*@3 version ]and [%-*@3 numberOfProcessors].&]
[s3; &]
[s4;%- &]
[s5;:GetBiosInfo`(String`&`,Date`&`):%- [@(0.0.255) void]_[* GetBiosInfo]([_^String^ String
]_`&[*@3 biosVersion], [_^Date^ Date]_`&[*@3 biosReleaseDate])&]
[s2; Returns bios information including [%-*@3 biosVersion] and [%-*@3 biosReleaseDate].&]
[s3; &]
[s4;%- &]
[s5;:GetProcessorInfo`(int`,String`&`,String`&`,String`&`,int`&`):%- [@(0.0.255) bool]_
[* GetProcessorInfo]([@(0.0.255) int]_[*@3 number], [_^String^ String]_`&[*@3 vendor], 
[_^String^ String]_`&[*@3 identifier], [_^String^ String]_`&[*@3 architecture], 
[@(0.0.255) int]_`&[*@3 speed])&]
[s2; Returns information about the different cpu cores.&]
[s2; [%-*@3 number] is the core number to get the information&]
[s2; [%-*@3 vendor] is the core vendor&]
[s2; [%-*@3 identifier] is the core identifier&]
[s2; [%-*@3 architecture] is the core architecture (32, 64)&]
[s2; [%-*@3 speed].is the core speed in MHz.&]
[s0; &]
[s4;%- &]
[s5;:GetCpuSpeed`(`):%- [@(0.0.255) int]_[* GetCpuSpeed]()&]
[s2; Gets the real time main CPU speed in MHz.&]
[s0; -|This data is directly calculated by the function.&]
[s3; &]
[s4;%- &]
[s5;:GetVideoInfo`(Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`):%- [@(0.0.255) b
ool]_[* GetVideoInfo]([_^Array^ Array]_<[_^Value^ Value]>_`&[*@3 name], 
Array_<Value>_`&[*@3 description], Array_<Value>_`&[*@3 videoProcessor], 
Array_<Value>_`&[*@3 ram], Array_<Value>_`&[*@3 videoMode])&]
[s2; If true gets information about video systems installed:&]
[s2; [%-*@3 name] is the video system name&]
[s2; [%-*@3 description] is the video description&]
[s2; [%-*@3 videoProcessor] is the processor used&]
[s2; [%-*@3 ram ]is the available memory in the video hardware in Mb&]
[s2; [%-*@3 videoMode] is the video mode actually selected including 
screen resolution and number of colors&]
[s3; &]
[s4;%- &]
[s5;:GetPackagesInfo`(Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`,Array`<Value`>`&`):%- [@(0.0.255) b
ool]_[* GetPackagesInfo]([_^Array^ Array]_<[_^Value^ Value]>_`&[*@3 name], 
Array_<Value>_`&[*@3 version], Array_<Value>_`&[*@3 vendor], Array_<Value>_`&[*@3 insta
llDate], Array_<Value>_`&[*@3 caption], Array_<Value>_`&[*@3 description], 
Array_<Value>_`&[*@3 state])&]
[s2; If true gets information about installed software:&]
[s2;%- [*@3 name]&]
[s2;%- [*@3 version]&]
[s2;%- [*@3 vendor]&]
[s2;%- [*@3 installDate]&]
[s2; [%-*@3 caption] is a summary of the software description&]
[s2;%- [*@3 description]&]
[s2; [%-*@3 state] is the status of the software. Values are:&]
[s0; -|-|`- `"Bad Configuration`"&]
[s0; -|-|`- `"Invalid Argument`"&]
[s0; -|-|`- `"Unknown Package`"&]
[s0; -|-|`- `"Advertised`"&]
[s0; -|-|`- `"Absent`"&]
[s0; -|-|`- `"Ok`"&]
[s3; &]
[s4;%- &]
[s5;:GetMemoryInfo`(int`&`,uint64`&`,uint64`&`,uint64`&`,uint64`&`,uint64`&`,uint64`&`):%- [@(0.0.255) b
ool]_[* GetMemoryInfo]([@(0.0.255) int]_`&[*@3 memoryLoad], [_^uint64^ uint64]_`&[*@3 total
Phys], [_^uint64^ uint64]_`&[*@3 freePhys], [_^uint64^ uint64]_`&[*@3 totalPageFile], 
[_^uint64^ uint64]_`&[*@3 freePageFile], [_^uint64^ uint64]_`&[*@3 totalVirtual], 
[_^uint64^ uint64]_`&[*@3 freeVirtual])&]
[s2; Gets information about the system memory:&]
[s2; [%-*@3 memoryLoad ]is the percent of memory in use&]
[s2; [%-*@3 totalPhys ]is the total physical memory&]
[s2; [%-*@3 freePhys] is the free physical memory&]
[s2; [%-*@3 totalPageFile ]is the total paging file&]
[s2; [%-*@3 freePageFile ]is the free paging file&]
[s2; [%-*@3 totalVirtual ]is the total virtual memory&]
[s2; [%-*@3 freeVirtual ]is the free virtual memory.&]
[s3; &]
[s4;%- &]
[s5;:GetOsInfo`(String`&`,String`&`,String`&`,String`&`,String`&`,String`&`,String`&`):%- [@(0.0.255) b
ool]_[* GetOsInfo]([_^String^ String]_`&[*@3 kernel], [_^String^ String]_`&[*@3 kerVersion],
 [_^String^ String]_`&[*@3 kerArchitecture], [_^String^ String]_`&[*@3 distro], 
[_^String^ String]_`&[*@3 distVersion], [_^String^ String]_`&[*@3 desktop], 
[_^String^ String]_`&[*@3 deskVersion])&]
[s2; Gets many information to identify the operating system and Desktop 
where the application is being run. &]
[s2; [%-*@3 kernel]: Kernel name&]
[s2; [%-*@3 kerVersion]: Kernel version&]
[s2; [%-*@3 kerArchitecture]: Kernel architecture&]
[s2; [%-*@3 distro]: Distro name&]
[s2; [%-*@3 distVersion]: Distro version&]
[s2; [%-*@3 desktop]: Desktop manager name&]
[s2; [%-*@3 deskVersion].: Desktop manager version&]
[s3; &]
[s4;%- &]
[s5;:GetDesktopManagerNew`(`):%- [_^String^ String]_[* GetDesktopManagerNew]()&]
[s2; A more complete version of GetDesktopManager() based on GetOsInfo().&]
[s0; &]
[s4;%- &]
[s5;:GetDriveList`(`):%- [_^Array^ Array]<[_^String^ String]>_[* GetDriveList]()&]
[s2; Returns an array with the paths to all drives, internal or external, 
identified in the system.&]
[s3;%- &]
[s4;%- &]
[s5;:GetDriveSpace`(String`,uint64`&`,uint64`&`,uint64`&`):%- [@(0.0.255) bool]_[* GetDri
veSpace]([_^String^ String]_[*@3 drive], [_^uint64^ uint64]_`&[*@3 freeBytesUser], 
[_^uint64^ uint64]_`&[*@3 totalBytesUser], [_^uint64^ uint64]_`&[*@3 totalFreeBytes])&]
[s2; Gets [%-*@3 drive] space.&]
[s2; [%-*@3 freeBytesUser]: Amount of free bytes available to the user&]
[s2; [%-*@3 totalBytesUser]: Size of drive visible for the user&]
[s2; [%-*@3 totalFreeBytes]: Amount of free bytes.&]
[s0; -|Returns false if drive is not mounted or it is not accessible&]
[s3; &]
[s4;%- &]
[s5;:GetDriveInformation`(String`,String`&`,String`&`,int`&`,String`&`):%- [@(0.0.255) b
ool]_[* GetDriveInformation]([_^String^ String]_[*@3 drive], [_^String^ String]_`&[*@3 type
], [_^String^ String]_`&[*@3 volume], [@(0.0.255) int]_`&[*@3 maxName], 
[_^String^ String]_`&[*@3 fileSystem])&]
[s2; Gets [%-*@3 drive] information&]
[s2;%- [*@3 type]: Gets the type of the drive.&]
[s2;%- Available types are `"Hard`", `"Network`", `"Optical`", `"RAM`", 
`"Removable`".&]
[s2;%- [*@3 volume]: Gets the name of the drive&]
[s2;%- [*@3 maxName]: Gets the maximum length permitted for a file name&]
[s2;%- [*@3 fileSystem]: Gets the drive formatting system.&]
[s0; -|Returns false if drive is not mounted or it is not accessible&]
[s3; &]
[s4;%- &]
[s5;:GetCompilerInfo`(String`&`,int`&`,String`&`):%- [@(0.0.255) void]_[* GetCompilerInfo
]([_^String^ String]_`&[*@3 name], [@(0.0.255) int]_`&[*@3 version], 
[_^String^ String]_`&[*@3 date])&]
[s2; Returns compiling information, like compiler [%-*@3 name, ]compiler 
[%-*@3 version] and program compilation [%-*@3 date].&]
[s3; &]
[s4;%- &]
[s5;:GetBatteryStatus`(bool`&`,int`&`,int`&`):%- [@(0.0.255) bool]_[* GetBatteryStatus]([@(0.0.255) b
ool]_`&[*@3 discharging], [@(0.0.255) int]_`&[*@3 percentage], [@(0.0.255) int]_`&[*@3 rema
iningMin])&]
[s2; Gets battery information like if it is [%-*@3 discharging] or 
connected to the grid, [%-*@3 percentage] of charging where 100% 
means full charge, and number of expected computer running minutes 
in [%-*@3 remainingMin].&]
[s0; -|Returns true if the values got are valid.&]
[s3; &]
[s4;%- &]
[s5;:GetBatteryInfo`(bool`&`):%- [@(0.0.255) bool]_[* GetBatteryInfo]([@(0.0.255) bool]_`&[*@3 p
resent]_)&]
[s2; Gets if battery is [%-*@3 present ]or not.&]
[s0; -|Returns true if the values got are valid.&]
[s3; &]
[s4;%- &]
[s5;:OpenCDTray`(`):%- [@(0.0.255) void]_[* OpenCDTray]()&]
[s2; Ejects CD/DVD tray.&]
[s3; &]
[s4;%- &]
[s5;:CloseCDTray`(`):%- [@(0.0.255) void]_[* CloseCDTray]()&]
[s2; Closes CD/DVD tray if possible&]
[s3;@(0.0.255)%- &]
[ {{10000@1 [s0; [* Process handling]]}}&]
[s3;%- &]
[s5;:GetWindowsList`(Array`<long`>`&`,Array`<long`>`&`,Array`<String`>`&`,Array`<String`>`&`,Array`<String`>`&`):%- [@(0.0.255) v
oid]_[* GetWindowsList]([_^Array^ Array]<[@(0.0.255) long]>_`&[*@3 wid], 
[_^Array^ Array]<[@(0.0.255) long]>_`&[*@3 pid], [_^Array^ Array]<[_^String^ String]>_`&[*@3 n
ame], [_^Array^ Array]<[_^String^ String]>_`&[*@3 fileName], [_^Array^ Array]<[_^String^ St
ring]>_`&[*@3 title])&]
[s2; Gets arrays with handles to all the opened windows with additional 
info as:&]
[s2; [%-*@3 wid]: Handle to the the window&]
[s2; [%-*@3 pid]: Handle to the process that manages the window&]
[s2; [%-*@3 name]: Window name&]
[s2; [%-*@3 fileName]: Window process program file name&]
[s2; [%-*@3 title]: Window title (caption)&]
[s3; &]
[s4;%- &]
[s5;:GetWindowsList`(`):%- [_^Array^ Array]<[@(0.0.255) long]>_[* GetWindowsList]()&]
[s2; Gets an array with handles to all the opened windows.&]
[s3;%- &]
[s4;%- &]
[s5;:GetProcessList`(Array`<long`>`&`,Array`<String`>`&`):%- [@(0.0.255) bool]_[* GetProc
essList]([_^Array^ Array]<[@(0.0.255) long]>_`&[*@3 pid], [_^Array^ Array]<[_^String^ Strin
g]>_`&[*@3 pNames])&]
[s2; Gets arrays with handles to all the opened processes [%-*@3 pid 
]and process names [%-*@3 pNames].&]
[s3; &]
[s4;%- &]
[s5;:GetProcessList`(`):%- [_^Array^ Array]<[@(0.0.255) long]>_[* GetProcessList]()&]
[s2; Gets an array with handles to all the opened processes&]
[s3;%- &]
[s4;%- &]
[s5;:GetProcessName`(long`):%- [_^String^ String]_[* GetProcessName]([@(0.0.255) long]_[*@3 p
id])&]
[s2; Returns the process name for a process with handle [%-*@3 pid].&]
[s3; &]
[s4;%- &]
[s5;:GetProcessFileName`(long`):%- [_^String^ String]_[* GetProcessFileName]([@(0.0.255) lo
ng]_[*@3 processID])&]
[s2; Gets the program file name of a process with handle [%-*@3 processID].&]
[s3; &]
[s4;%- &]
[s5;:GetProcessIdFromWindowCaption`(String`,bool`):%- [@(0.0.255) long]_[* GetProcessIdFr
omWindowCaption]([_^String^ String]_[*@3 windowCaption], [@(0.0.255) bool]_[*@3 exactMatc
h]_`=_[@(0.0.255) false])&]
[s2;%- [%% Gets the process handle of a program with a window with 
title ][*@3 windowCaption.]&]
[s2;%- [%% If ][*@3 exactMatch][%% .is true it only returns the process 
handle of a process with a window title that is equal to ][*@3 windowCaption. 
][%% If it is false then the handle is returned if only part of 
the window title matches with ][*@3 windowCaption.]&]
[s3; &]
[s4;%- &]
[s5;:GetWindowIdFromCaption`(String`,bool`):%- [@(0.0.255) long]_[* GetWindowIdFromCaptio
n]([_^String^ String]_[*@3 windowCaption], [@(0.0.255) bool]_[*@3 exactMatch]_`=_[@(0.0.255) f
alse])&]
[s2;%- [%% Gets the window handle of a program with a window with title 
][*@3 windowCaption.]&]
[s2;%- [%% If ][*@3 exactMatch][%% .is true it only returns the process 
handle of a process with a window title that is equal to ][*@3 windowCaption. 
][%% If it is false then the handle is returned if only part of 
the window title matches with ][*@3 windowCaption.]&]
[s3; &]
[s4;%- &]
[s5;:GetProcessIdFromWindowId`(long`):%- [@(0.0.255) long]_[* GetProcessIdFromWindowId]([@(0.0.255) l
ong]_[*@3 wid])&]
[s2;%- [%% Returns the process handle of a program with window handle 
][*@3 wid.]&]
[s3; &]
[s4;%- &]
[s5;:GetWindowIdFromProcessId`(long`):%- [@(0.0.255) long]_[* GetWindowIdFromProcessId]([@(0.0.255) l
ong]_[*@3 pid])&]
[s2;%- [%% Returns the window handle of a program with process handle 
][*@3 pid.]&]
[s3; &]
[s4;%- &]
[s5;:ProcessTerminate`(long`,int`):%- [@(0.0.255) bool]_[* ProcessTerminate]([@(0.0.255) lo
ng]_[*@3 pid], [@(0.0.255) int]_[*@3 timeout]_`=_[@3 500])&]
[s2;%- [%% Ends the program with handle ][*@3 pid.]&]
[s2; If after asking the process to end [%-*@3 timeout ]is over, it 
will kill the process by different means in order of increasing 
`"aggressivity`".&]
[s0; -|For example in Posix it will send the process first a SIGTERM, 
if the process does not stop it will send a SIGKILL, and if the 
process remains running it will simply call WindowKill() to do 
the dirty job.&]
[s3; &]
[s4;%- &]
[s5;:GetProcessPriority`(long`):%- [@(0.0.255) int]_[* GetProcessPriority]([@(0.0.255) long
]_[*@3 pid])&]
[s2; Gets the process priority of the process with handle [%-*@3 pid] 
as a number from 0 (minimum) to 10 (maximum), if possible.&]
[s3; &]
[s4;%- &]
[s5;:SetProcessPriority`(long`,int`):%- [@(0.0.255) bool]_[* SetProcessPriority]([@(0.0.255) l
ong]_[*@3 pid], [@(0.0.255) int]_[*@3 priority])&]
[s2; Sets the process priority to [%-*@3 priority ]of the process with 
handle [%-*@3 pid] as a number from 0 (minimum) to 10 (maximum), 
if possible.&]
[s3; &]
[s4;%- &]
[s5;:ProcessExists`(long`):%- [@(0.0.255) bool]_[* ProcessExists]([@(0.0.255) long]_[*@3 pid])
&]
[s2; Returns true if a process with handle [%-*@3 pid ]exists.&]
[s4;%- &]
[s5;:GetProcessId`(`):%- [@(0.0.255) long]_[* GetProcessId]()&]
[s2; Gets actual running process handle.&]
[s3;%- &]
[s4;%- &]
[s5;:Shutdown`(String`):%- [@(0.0.255) bool]_[* Shutdown]([_^String^ String]_[*@3 action])&]
[s2; Tries to logoff, reboot or shutdown the actual running session.&]
[s0; -|Actual valid [%-*@3 action ]values are `"logoff`", `"reboot`" 
and `"shutdown`".&]
[s3; &]
[s0; &]
[ {{10000@1 [s0; [* Windows handling]]}}&]
[s0; &]
[s5;:Window`_GetRect`(long`,long`&`,long`&`,long`&`,long`&`):%- [@(0.0.255) bool]_[* Wind
ow`_GetRect]([@(0.0.255) long]_[*@3 windowId], [@(0.0.255) long]_`&[*@3 left], 
[@(0.0.255) long]_`&[*@3 top], [@(0.0.255) long]_`&[*@3 right], [@(0.0.255) long]_`&[*@3 bott
om])&]
[s2; Giving this function the [%-*@3 windowId], it returns the window 
location in the screen in [%-*@3 left], [%-*@3 top], [%-*@3 right] 
and [%-*@3 bottom].&]
[s0; -|Returns true if the values got are valid.&]
[s3; &]
[s4;%- &]
[s5;:Window`_SetRect`(long`,long`,long`,long`,long`):%- [@(0.0.255) void]_[* Window`_SetR
ect]([@(0.0.255) long]_[*@3 windowId], [@(0.0.255) long]_[*@3 left], 
[@(0.0.255) long]_[*@3 top], [@(0.0.255) long]_[*@3 right], [@(0.0.255) long]_[*@3 bottom])&]
[s2; Giving this function the [%-*@3 windowId], it sets the window 
location in the screen in [%-*@3 left], [%-*@3 top], [%-*@3 right] 
and [%-*@3 bottom].&]
[s2; -|Returns true if the window is relocated correctly..&]
[s0; &]
[ {{10000@1 [s0; [* Mouse and keyboard handling]]}}&]
[s3; &]
[s5;:Mouse`_GetPos`(long`&`,long`&`):%- [@(0.0.255) bool]_[* Mouse`_GetPos]([@(0.0.255) lon
g]_`&[*@3 x], [@(0.0.255) long]_`&[*@3 y])&]
[s2; Gets the mouse position [%-*@3 x, y].in screen pixels where upper 
left corner is (0, 0).&]
[s0; -|Returns true if the operation has been done successfully.&]
[s3; &]
[s4;%- &]
[s5;:Mouse`_SetPos`(long`,long`,long`):%- [@(0.0.255) bool]_[* Mouse`_SetPos]([@(0.0.255) l
ong]_[*@3 x], [@(0.0.255) long]_[*@3 y], [@(0.0.255) long]_[*@3 windowId])&]
[s2; Sets the mouse position to [%-*@3 x] [%-*@3 y] referenced to the 
upper left vertex of window with window handle [%-*@3 windowId].&]
[s0; -|Returns true if the operation has been done successfully.&]
[s3; &]
[s4;%- &]
[s5;:Mouse`_LeftClick`(`):%- [@(0.0.255) void]_[* Mouse`_LeftClick]()&]
[s2; Simulates by software a mouse click with the left button as 
if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Mouse`_MiddleClick`(`):%- [@(0.0.255) void]_[* Mouse`_MiddleClick]()&]
[s2; Simulates by software a mouse click with the middle button as 
if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Mouse`_RightClick`(`):%- [@(0.0.255) void]_[* Mouse`_RightClick]()&]
[s2; Simulates by software a mouse click with the right button as 
if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Mouse`_LeftDblClick`(`):%- [@(0.0.255) void]_[* Mouse`_LeftDblClick]()&]
[s2; Simulates by software a mouse double click with the left button 
as if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Mouse`_MiddleDblClick`(`):%- [@(0.0.255) void]_[* Mouse`_MiddleDblClick]()&]
[s2; Simulates by software a mouse double click with the middle button 
as if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Mouse`_RightDblClick`(`):%- [@(0.0.255) void]_[* Mouse`_RightDblClick]()&]
[s2; Simulates by software a mouse double click with the right button 
as if it would have been done with the mouse.&]
[s3;%- &]
[s4;%- &]
[s5;:Keyb`_SendKeys`(String`,long`,long`):%- [@(0.0.255) void]_[* Keyb`_SendKeys]([_^String^ S
tring]_[*@3 text], [@(0.0.255) long]_[*@3 finalDelay]_`=_[@3 100], [@(0.0.255) long]_[*@3 del
ayBetweenKeys]_`=_[@3 50])&]
[s2; Simulates by software a text entered using the keyboard as if 
it would have been entered with the keyboard.&]
[s2; To really simulate manual key typing the function lets to enter 
delays between keys and after entering the text.&]
[s2; [%-*@3 text]: Is the text to be entered&]
[s2; [%-*@3 finalDelay]: Is the delay in ms that is forced after entering 
text&]
[s2; [%-*@3 delayBetweenKeys]: Is the delay in ms that is forced between 
text keys.&]
[s3; &]
[s4;%- &]
[s5;:GetKeyLockStatus`(bool`&`,bool`&`,bool`&`):%- [@(0.0.255) void]_[* GetKeyLockStatus](
[@(0.0.255) bool]_`&[*@3 caps], [@(0.0.255) bool]_`&[*@3 num], [@(0.0.255) bool]_`&[*@3 scrol
l])&]
[s2; Gets the status of keys [%-*@3 caps ]lock,  [%-*@3 num ]lock and 
[%-*@3 scroll] [%-*@3  ]lock.&]
[s3; &]
[s4;%- &]
[s5;:SetKeyLockStatus`(bool`,bool`,bool`):%- [@(0.0.255) void]_[* SetKeyLockStatus]([@(0.0.255) b
ool]_[*@3 caps], [@(0.0.255) bool]_[*@3 num], [@(0.0.255) bool]_[*@3 scroll])&]
[s2; Sets the status of keys [%-*@3 caps ]lock,  [%-*@3 num ]lock and 
[%-*@3 scroll] [%-*@3  ]lock.&]
[s3; &]
[ {{10000@1 [s0; [* Screen recording]]}}&]
[s3; &]
[s5;:Snap`_Desktop`(String`):%- [@(0.0.255) bool]_[* Snap`_Desktop]([_^String^ String]_[*@3 f
ileName])&]
[s2; Saves the desktop in [%-*@3 fileName].as an image file.&]
[s0; -|Allowed formats are:&]
[s0; -|-|`- Posix: .xwd&]
[s0; -|-|`- Windows: .bmp&]
[s3; &]
[s4;%- &]
[s5;:Snap`_DesktopRectangle`(String`,int`,int`,int`,int`):%- [@(0.0.255) bool]_[* Snap`_D
esktopRectangle]([_^String^ String]_[*@3 fileName], [@(0.0.255) int]_[*@3 left], 
[@(0.0.255) int]_[*@3 top], [@(0.0.255) int]_[*@3 width], [@(0.0.255) int]_[*@3 height])&]
[s2; Saves a rectangle of the desktop defined by [%-*@3 left], [%-*@3 top], 
[%-*@3 width ]and [%-*@3 height].in [%-*@3 fileName] as an image file.&]
[s0; -|Allowed formats are:&]
[s0; -|-|`- Posix: .xwd&]
[s0; -|-|`- Windows: .bmp&]
[s3; &]
[s4;%- &]
[s5;:Snap`_Window`(String`,long`):%- [@(0.0.255) bool]_[* Snap`_Window]([_^String^ String]_
[*@3 fileName], [@(0.0.255) long]_[*@3 handle])&]
[s2; Saves a window defined by its [%-*@3 handle] in [%-*@3 fileName] 
as an image file.&]
[s0; -|Allowed formats are:&]
[s0; -|-|`- Posix: .xwd&]
[s0; -|-|`- Windows: .bmp&]
[s3; &]
[s4;%- &]
[s5;:Record`_Desktop`(String`,int`,int`,bool`):%- [@(0.0.255) bool]_[* Record`_Desktop]([_^String^ S
tring]_[*@3 fileName], [@(0.0.255) int]_[*@3 duration], [@(0.0.255) int]_[*@3 secsFrame]_`=
_[@3 1], [@(0.0.255) bool]_[*@3 viewMouse]_`=_[@(0.0.255) true])&]
[s2; Records the desktop activity in [%-*@3 fileName] as a video file 
of [%-*@3 duration] in seconds with [%-*@3 secsFrame] seconds between 
frames and recording also mouse movement if [%-*@3 viewMouse].is 
true.&]
[s0; -|Allowed formats are:&]
[s0; -|-|`- Windows: Uncompressed .avi &]
[s3; &]
[s4;%- &]
[s5;:Record`_DesktopRectangle`(String`,int`,int`,int`,int`,int`,int`,bool`):%- [@(0.0.255) b
ool]_[* Record`_DesktopRectangle]([_^String^ String]_[*@3 fileName], 
[@(0.0.255) int]_[*@3 duration], [@(0.0.255) int]_[*@3 left], [@(0.0.255) int]_[*@3 top], 
[@(0.0.255) int]_[*@3 width], [@(0.0.255) int]_[*@3 height], [@(0.0.255) int]_[*@3 secsFrame]_
`=_[@3 1], [@(0.0.255) bool]_[*@3 viewMouse]_`=_[@(0.0.255) true])&]
[s2; Records the desktop activity in the rectangle defined by [%-*@3 left], 
[%-*@3 top], [%-*@3 width ]and [%-*@3 height]. in [%-*@3 fileName] as 
a video file of [%-*@3 duration] in seconds with [%-*@3 secsFrame] 
seconds between frames and recording also mouse movement if [%-*@3 viewMouse].is 
true.&]
[s0; -|Allowed formats are:&]
[s2; -|-|`- Windows: Uncompressed .avi&]
[s3; &]
[s4;%- &]
[s5;:Record`_Window`(String`,int`,long`,int`,bool`):%- [@(0.0.255) bool]_[* Record`_Windo
w]([_^String^ String]_[*@3 fileName], [@(0.0.255) int]_[*@3 duration], 
[@(0.0.255) long]_[*@3 handle], [@(0.0.255) int]_[*@3 secsFrame]_`=_[@3 1], 
[@(0.0.255) bool]_[*@3 viewMouse]_`=_[@(0.0.255) true])&]
[s2; Records the activity of a window defined by its [%-*@3 handle] 
in [%-*@3 fileName] as a video file of [%-*@3 duration] in seconds 
with [%-*@3 secsFrame] seconds between frames and recording also 
mouse movement if [%-*@3 viewMouse].is true.&]
[s0; -|Allowed formats are:&]
[s2; -|-|`- Windows: Uncompressed .avi&]
[s3; &]
[ {{10000@1 [s0; [* Miscellaneous functions]]}}&]
[s0; &]
[s5;:LoadFile`_Safe`(String`):%- [_^String^ String]_[* LoadFile`_Safe]([_^String^ String]_[*@3 f
ileName])&]
[s2; Same as LoadFile([%-*@3 fileName]) but it works in Posix for files 
automatically generated by the OS.&]
[s0; &]
[s0; U`+`+ LoadFile() functions prior to loading the file into a 
String, get the length of the file to dimension the String that 
will get the file. This is not valid for OS generated virtual 
files where the file length returned by the OS is 0 (for example 
files under folder /proc)&]
[s0; &]
[s0; LoadFile`_Safe() just get the file bytes returned by the OS 
until the file end.&]
[s3; &]
[s4;%- &]
[s5;:FileToTrashBin`(const char`*`):%- [@(0.0.255) void]_[* FileToTrashBin]([@(0.0.255) con
st]_[@(0.0.255) char]_`*[*@3 path])&]
[s2; Deletes file [%-*@3 path].by sending it to the Trash Bin.&]
[s3; &]
[s4;%- &]
[s5;:TrashBinGetCount`(`):%- [_^int64^ int64]_[* TrashBinGetCount]()&]
[s2; Returns the number of items (files and directories) located 
in the Trash Bin.&]
[s3;%- &]
[s4;%- &]
[s5;:TrashBinClear`(`):%- [@(0.0.255) void]_[* TrashBinClear]()&]
[s2; Removes all the items (files and directories) located in the 
Trash Bin.&]
[s3;%- &]
[s4;%- &]
[s5;:SetDesktopWallPaper`(const char`*`):%- [@(0.0.255) void]_[* SetDesktopWallPaper]([@(0.0.255) c
onst]_[@(0.0.255) char]_`*[*@3 path])&]
[s2; Sets [%-*@3 path].file as desktop wallpaper. Supports Gnome, Kde 
v3 and Windows desktops.&]
[s0; &]
[s0;i150;O0; In Gnome, [%-*@3 path] has to be .png&]
[s0;i150;O0; In Kde, [%-*@3 path] has to be .png, .gif or .jpg&]
[s0;i150;O0; In Windows, [%-*@3 path] has to be .bmp&]
[s0; &]
[s0; If [%-*@3 path].is empty, the desktop wallpaper is removed. &]
[s0; &]
[s4;%- &]
[s5;:FileCat`(const char`*`,const char`*`):%- [@(0.0.255) bool]_[* FileCat]([@(0.0.255) con
st]_[@(0.0.255) char]_`*[*@3 file], [@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 appendFile])
&]
[s2; Appends at the end of [%-*@3 file] the contents of file [%-*@3 appendFile]. 
[%-*@3 file] will be modified and [%-*@3 appendFile ]remains unchanged.&]
[s0; -|Returns true if the operations has been done succesfully.&]
[s3;%- &]
[s4;%- &]
[s5;:Replace`(String`,String`,String`):%- [_^String^ String]_[* Replace]([_^String^ String]_
[*@3 str], [_^String^ String]_[*@3 find], [_^String^ String]_[*@3 replace])&]
[s2; Returns the resulting String obtained by replacing in [%-*@3 str] 
String [%-*@3 find] with [%-*@3 replace ]all the times that [%-*@3 find 
]appears in [%-*@3 str].&]
[s3; &]
[s4;%- &]
[s5;:FormatLong`(long`):%- [_^String^ String]_[* FormatLong]([@(0.0.255) long]_[*@3 a])&]
[s2; Returns the long number [%-*@3 a ]converted into a String.&]
[s0; &]
[s4;%- &]
[s5;:Sign`(T`):%- [@(0.0.255) template]_<[@(0.0.255) class]_[*@4 T]>_[@(0.0.255) int]_[* Sign](
[*@4 T]_[*@3 a])&]
[s2; Returns&]
[s2;i150;O0;  `+1 if [%-*@3 a]. is positive&]
[s2;i150;O0; 0 if [%-*@3 a] is 0 and &]
[s2;i150;O0; `-1 if [%-*@3 a] is negative.&]
[s3; &]
[s4;%- &]
[s5;:GetUpperFolder`(String`):%- [_^String^ String]_[* GetUpperFolder]([_^String^ String]_[*@3 f
olderName])&]
[s2; Returns the name of the upper folder over [%-*@3 folderName].&]
[s3; &]
[s4;%- &]
[s5;:SecondsToString`(double`,bool`):%- [_^String^ String]_[* SecondsToString]([@(0.0.255) d
ouble]_[*@3 seconds], [@(0.0.255) bool]_[*@3 decimals]_`=_[@(0.0.255) false])&]
[s2; Converts an amount of [%-*@3 seconds] to a String formatted as 
HH:MM:SS.&]
[s0; -|If [%-*@3 decimals ]it includes decimals in seconds&]
[s0; -|It is opposite to StringToSeconds()&]
[s3; &]
[s4;%- &]
[s5;:StrToTime`(struct Time`&`,const char`*`):%- [@(0.0.255) const]_[@(0.0.255) char]_`*[* S
trToTime]([@(0.0.255) struct]_[_^Time^ Upp`::Time][@(0.0.255) `&]_[*@3 d], 
[@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 s])&]
[s2;%- Scans a string for a Time. Order of day, month and year is 
specified using SetDateScan. In place of month both number and 
text is accepted `- text must match abbreviated or full name 
of month.&]
[s0;%- -|Similar to StrToDate() but including both date and time.&]
[s2;%- [*@3 d]-|Found time.&]
[s2;%- [*@3 s]-|String to scan.&]
[s2;%- Return value-|NULL if no time is found in [*@3 s] or pointer 
to character right after the date.&]
[s3; &]
[s4;%- &]
[s5;:StringToSeconds`(String`):%- [@(0.0.255) double]_[* StringToSeconds]([_^String^ String
]_[*@3 str])&]
[s2; It converts a String [%-*@3 str ]formatted as HH:MM:SS to a returned 
amount of seconds.&]
[s0; -|It is opposite to SecondsToString()&]
[s3; &]
[s4;%- &]
[s5;:BytesToString`(uint64`):%- [_^String^ String]_[* BytesToString]([_^uint64^ uint64]_[*@3 b
ytes])&]
[s2; Converts an amount of [%-*@3 bytes ]to a short String.&]
[s3; &]
[s4;%- &]
[s5;:DoEvents`(`):%- [@(0.0.255) void]_[* DoEvents]()&]
[s2; A ProcessEvents just for old Visual Basic programmers.&]
[s3; &]
[s4;%- &]
[s5;:SearchFile`(String`,String`,String`):%- [_^Array^ Array]<[_^String^ String]>_[* Search
File]([_^String^ String]_[*@3 dir], [_^String^ String]_[*@3 condFile], 
[_^String^ String]_[*@3 text]_`=_`"`")&]
[s2; Returns an Array of Strings containing the file names with full 
path of the files under folder [%-*@3 dir] that comply with condition 
(with wildcards) [%-*@3 condFile] and that contain inside the text 
[%-*@3 text].&]
[s0; ]