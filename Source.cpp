#include<Windows.h> //DWORD
#include <iostream>
#include <string>
#include <psapi.h> //EnumProcessModules
#include <VersionHelpers.h>
#include <atlstr.h> // CString
#include <WinUser.h>
#include <errno.h>

#define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ)
#define STRING_SIZE 255

/*
    Disclaimer : This program uses Multy Bit Character Set.
    It needs to be specified in Project > Proprieties > advenced > Character Set

    Thanks to CasualGamer for the base code <3
*/

void    SplashScreen(HANDLE & hConsole)
{
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 20);
    std::cout   << "@@@@@@@   @@@  @@@   @@@@@@   @@@@@@@    @@@@@@   @@@  @@@      @@@@@@   " << std::endl
                << "@@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@     @@@@@@@@  " << std::endl
                << "@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@          @@@  " << std::endl
                << "!@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@         @!@   " << std::endl
                << "@!@  !@!  @!@  !@!  @!@  !@!  @!@!!@!   @!@!@!@!  @!@!@!@!        !!@    " << std::endl
                << "!@!  !!!  !@!  !!!  !@!  !!!  !!@!@!    !!!@!!!!  !!!@!!!!       !!:     " << std::endl
                << "!!:  !!!  :!:  !!:  !!:  !!!  !!: :!!   !!:  !!!  !!:  !!!      !:!      " << std::endl
                << ":!:  !:!   ::!!:!   :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!     :!:       " << std::endl
                << " :::: ::    ::::    ::::: ::  ::   :::  ::   :::  ::   :::     :: :::::  " << std::endl
                << ":: :  :      :       : :  :    :   : :   :   : :   :   : :     :: : :::  " << std::endl << std::endl;
    /*SetConsoleTextAttribute(hConsole, 7);*/

    //for (int k = 1; k < 255; k++)
    //{
    //    // pick the colorattribute k you want
    //    SetConsoleTextAttribute(hConsole, k);
    //    std::cout << k << " I want to be nice today!" << std::endl;
    //}
}

BOOL    InjectDLL(LPCSTR DLL_PATH, DWORD ProcessID)
{
    LPVOID LoadLibAddy, RemoteString;

    if (!ProcessID)
        return false;

    HANDLE Proc = OpenProcess(CREATE_THREAD_ACCESS, FALSE, ProcessID);

    if (!Proc)
    {
        std::cout << "OpenProcess() failed: " << GetLastError() << std::endl;
        return false;
    }

    LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

    RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(DLL_PATH) + 1, MEM_COMMIT, PAGE_READWRITE);
    WriteProcessMemory(Proc, RemoteString, (LPVOID)DLL_PATH, strlen(DLL_PATH) + 1, NULL);
    CreateRemoteThread(Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, RemoteString, NULL, NULL);
    std::cout << "Success" << std::endl;
    CloseHandle(Proc);

    return true;
}

BOOL    CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
    DWORD       dwThreadId, dwProcessId;
    HINSTANCE   hInstance;
    char        name[STRING_SIZE];

    if (!hWnd)
        return TRUE;        // Not a window
    if (!::IsWindowVisible(hWnd))
        return TRUE;        // Not visible
    if (!SendMessage(hWnd, WM_GETTEXT, sizeof(name), (LPARAM)name))
        return TRUE;        // No window title
    hInstance = (HINSTANCE)GetWindowLong(hWnd, -6);   // GWL_HINSTANCE = -6
    dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
    std::cout << "PID: " << dwProcessId << '\t' << name << '\t' << std::endl;
    return TRUE;
}

void    UnloadDLL(LPCSTR lib, DWORD pid)
{
    std::cout << "Not implemented yet :o" << std::endl;
    //std::cout << "unloading dll";
    //FreeLibrary((HMODULE)LoadLibAddy);    // not working for 32bit softs
}

int     main(int argc, char** argv)
{
    DWORD   pid;
    bool    unload;
    HANDLE hConsole;

    if (argc > 1 && !std::strcmp(argv[1], "-u"))
        unload = true;
    else
        unload = false;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SplashScreen(hConsole);

    if (argc == 2 + unload)
    {
        std::cout << "Available Targets:\n\/*n" << std::endl;
        EnumWindows(EnumWindowsProc, NULL);
        std::cout << "\nPick Target ProcessID" << std::endl;
        std::cin >> pid;
    }
    else if (argc == 3 + unload)
    {
       char*       end;

        errno = 0;
        pid = std::strtol(argv[2 + unload], &end, 10);
        if (errno == ERANGE || *end != NULL)
        {
            std::cerr << "Error : wrong PID" << std::endl;
            return (2);
        }
    }
    else
    {
        //std::cerr << "Error : Usage : ./Dvorah2 [FLAG : -u] <dll_path> [OPTION : PID]" << std::endl;
        //std::cerr << "          -u  : unload the dll from the target after pressing enter" << std::endl;
        std::cerr << "Error : Usage : ./Dvorah2 <dll_path> [OPTION : PID]" << std::endl;
        std::cerr << "          PID : avoid the search and inject directly to the targeted PID" << std::endl << std::endl;
        SetConsoleTextAttribute(hConsole, 7);
        return (1);
    }

    InjectDLL(argv[1 + unload], pid);

    if (unload)
        UnloadDLL(argv[1 + unload], pid);
    
    SetConsoleTextAttribute(hConsole, 7);
    return (0);
}
