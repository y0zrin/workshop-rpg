#include "console.h"

#include <iostream>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

void setupConsole()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

std::string readLine()
{
#ifdef _WIN32
    // コンソールから読むときは、ワイド文字で読んでから UTF-8 に直す（日本語の名前も読めるように）
    HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(input, &mode))
    {
        wchar_t buffer[256];
        DWORD count = 0;
        if (!ReadConsoleW(input, buffer, 255, &count, nullptr))
        {
            return "";
        }
        std::wstring wide(buffer, count);
        while (!wide.empty() && (wide.back() == L'\n' || wide.back() == L'\r'))
        {
            wide.pop_back();
        }
        int size = WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), static_cast<int>(wide.size()), nullptr, 0, nullptr, nullptr);
        std::string text(size, '\0');
        WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), static_cast<int>(wide.size()), text.data(), size, nullptr, nullptr);
        return text;
    }
#endif
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void waitEnter()
{
    std::cout << "\n（Enter で終わります）";
    readLine();
}
