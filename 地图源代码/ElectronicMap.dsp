# Microsoft Developer Studio Project File - Name="ElectronicMap" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ElectronicMap - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ElectronicMap.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ElectronicMap.mak" CFG="ElectronicMap - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ElectronicMap - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ElectronicMap - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ElectronicMap - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "ElectronicMap - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ElectronicMap - Win32 Release"
# Name "ElectronicMap - Win32 Debug"
# Begin Group "Include"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\..\..\..\Program Files\Microsoft Visual Studio\VC98\Include\BASETSD.H"
# End Source File
# Begin Source File

SOURCE=.\bubbleSort.h
# End Source File
# Begin Source File

SOURCE=.\delect.h
# End Source File
# Begin Source File

SOURCE=.\header.h
# End Source File
# Begin Source File

SOURCE=.\insert.h
# End Source File
# Begin Source File

SOURCE=.\myexit.h
# End Source File
# Begin Source File

SOURCE=.\qsort.h
# End Source File
# Begin Source File

SOURCE=.\quickSort.h
# End Source File
# Begin Source File

SOURCE=.\readf.h
# End Source File
# Begin Source File

SOURCE=.\readfile.h
# End Source File
# Begin Source File

SOURCE=.\readnewfile.h
# End Source File
# Begin Source File

SOURCE=.\searchfind.h
# End Source File
# Begin Source File

SOURCE=.\sort.h
# End Source File
# Begin Source File

SOURCE=.\struct.h
# End Source File
# Begin Source File

SOURCE=.\update.h
# End Source File
# Begin Source File

SOURCE=.\write.h
# End Source File
# End Group
# Begin Group "Update"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\delect.c
# End Source File
# Begin Source File

SOURCE=.\insert.c
# End Source File
# Begin Source File

SOURCE=.\update.c
# End Source File
# Begin Source File

SOURCE=.\write.c
# End Source File
# End Group
# Begin Group "Search"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\searchfind.c
# End Source File
# End Group
# Begin Group "Readfile"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\readf.c
# End Source File
# Begin Source File

SOURCE=.\readfile.c
# End Source File
# Begin Source File

SOURCE=.\readnewfile.c
# End Source File
# End Group
# Begin Group "Sort"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bubbleSort.c
# End Source File
# Begin Source File

SOURCE=.\qsort.c
# End Source File
# Begin Source File

SOURCE=.\quickSort.c
# End Source File
# Begin Source File

SOURCE=.\sort.c
# End Source File
# End Group
# Begin Group "Exit"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\myexit.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\ElectronicMap.c
# End Source File
# End Target
# End Project
