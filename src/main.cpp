//PLATFORM GLOBALS
#include "paradox_lib.h"
#include "platform.h"
static bool running = true;

//PLATFORM FUNCTIONS
bool platform_create_window(int width,int height,char* title);
void platform_update_window();

//WINDOWS PLATFORM
#ifdef _WIN32
#include "win32_platform.cpp"
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