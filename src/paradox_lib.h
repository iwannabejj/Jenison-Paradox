#pragma once
#include <stdio.h>
#ifdef _WIN32
#define DEBUG_BREAK() __debugbreak()
#endif
//Logging
enum TextColor
{
    TEXT_COLOR_BLACK,
    TEXT_COLOR_RED,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_MAGENTA,
    TEXT_COLOR_CYAN,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_BRIGHT_BLACK,
    TEXT_COLOR_BRIGHT_RED,
    TEXT_COLOR_BRIGHT_GREEN,
    TEXT_COLOR_BRIGHT_YELLOW,
    TEXT_COLOR_BRIGHT_BLUE,
    TEXT_COLOR_BRIGHT_MAGENTA,
    TEXT_COLOR_BRIGHT_CYAN,
    TEXT_COLOR_BRIGHT_WHITE,
    TEXT_COLOR_COUNT
};

template <typename... Args>
void _log(char* prefix, char* msg, TextColor textcolor, Args... args)
{
    static char* TextColorTable[TEXT_COLOR_COUNT] =
    {
        "\x1b[30m", //Black
        "\x1b[31m", //Red
        "\x1b[32m", //Green
        "\x1b[33m", //Yellow
        "\x1b[34m", //Blue
        "\x1b[35m", //Magenta
        "\x1b[36m", //Cyan
        "\x1b[37m", //White
        "\x1b[90m", //Bright Black
        "\x1b[91m", //Bright Red
        "\x1b[92m", //Bright Green
        "\x1b[93m", //Bright Yellow
        "\x1b[94m", //Bright Blue
        "\x1b[95m", //Bright Magenta
        "\x1b[96m", //Bright Cyan
        "\x1b[97m", //Bright White
    };

    char formatBuffer[8192] = {};
    sprintf(formatBuffer, "%s %s %s \033[0m", TextColorTable[textcolor], prefix, msg);

    char textBuffer[8192] = {};
    sprintf(textBuffer, formatBuffer, args...);

    puts(textBuffer);
}

#define SM_TRACE(msg,...) _log("TRACE: ", msg, TEXT_COLOR_GREEN, ##__VA_ARGS__);
#define SM_WARN(msg,...) _log("WARN: ", msg, TEXT_COLOR_YELLOW, ##__VA_ARGS__);
#define SM_ERROR(msg,...) _log("ERROR: ", msg, TEXT_COLOR_RED, ##__VA_ARGS__);

#define SM_ASSERT(x,msg,...)            \
{                                       \
    if (!(x))                           \
    {                                   \
        SM_ERROR(msg, ##__VA_ARGS__);   \
        DEBUG_BREAK();                  \
        SM_ERROR("ASSERTION HIT!")      \
    }                                   \
}
//
// Logging
//