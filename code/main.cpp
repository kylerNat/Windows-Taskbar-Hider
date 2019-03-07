#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    #define start_menu_class "Windows.UI.Core.CoreWindow"
    
    HWND taskbar_hwnd = 0;
    char class_name[sizeof(start_menu_class)+2]; //+2 so there is room for the null char and an extraneous char
    
    MSG msg;

    #define update_time 16
    #define refresh_time 5000
    
    for(int i = 0;;Sleep(update_time),
            i = (i+1) % (refresh_time/update_time))
    {
        if(i == 0) taskbar_hwnd = FindWindow("Shell_TrayWnd", 0);
        
        HWND foreground_window = GetForegroundWindow();
        GetClassName(foreground_window, class_name, sizeof(class_name));
        bool show = (foreground_window == 0
                     || foreground_window == taskbar_hwnd //taskbar is active
                     || (strcmp(class_name, start_menu_class) == 0)) //class name matches start menu class name
            || GetKeyState(VK_LWIN)>>1 //TODO: read list of keys from file for user configurabiity
            || GetKeyState(VK_RWIN)>>1;
        ShowWindow(taskbar_hwnd, show ? SW_SHOWMAXIMIZED : SW_HIDE);
    }
    
    return 0;
}
 
