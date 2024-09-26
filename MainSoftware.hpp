#ifndef MAINSOFTWARE_HPP
#define MAINSOFTWARE_HPP



#include <cstdint>
#include "resource.h"



#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



const uint16_t SCREEN_WIDTH  = GetSystemMetrics(SM_CXSCREEN);
const uint16_t SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);



void drawFrame(HDC hdc)
{

}



#endif /* !MAINSOFTWARE_HPP */