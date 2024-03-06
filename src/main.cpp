//PLATFORM GLOBALS
static bool running = true;
#include "paradox_lib.h"
//PLATFORM FUNCTIONS
bool platform_create_window(int width,int height,char* title);
void platform_update_window();

//WINDOWS PLATFORM
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

//Windows Global
static HWND window;

//PLATFORM IMPLEMENTATIONS

LRESULT CALLBACK windows_windows_callback(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (uMsg)
    {
        case WM_CLOSE:
        {
            running = false;
            break;
        }
        default:
        {
            result = DefWindowProcA(window, uMsg, wParam, lParam);
            break;
        }
    }

    return result;
}
bool platform_create_window(int width, int height, char* title)
{   
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;
    wc.lpfnWndProc = windows_windows_callback;


    if(!RegisterClassA(&wc))
    {
    return false;
    }
    

    int dwStyle = WS_OVERLAPPEDWINDOW;
    HWND window = CreateWindowExA
    (   0,
        title,
        title,
        dwStyle,
        100,
        100,
        width,
        height,
        NULL,
        NULL,
        instance,
        NULL);
    
    if(window == false)
    {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window()
{
    MSG msg;

    while (PeekMessageA(&msg,window,0,0,PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
#endif
int main()
{

    platform_create_window(1280,720,"Jenison Paradox");
    while(running)
    {
        //update
        platform_update_window();

        

    return 0;
}
 