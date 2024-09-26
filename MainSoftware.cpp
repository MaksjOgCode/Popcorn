#include "framework.h"
#include "MainSoftware.hpp"




/*--------------------------------------------------------------------------------------------------------------*/
int APIENTRY wWinMain( _In_     HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance,
                       _In_     LPWSTR    lpCmdLine,
                       _In_     int       nCmdShow  )
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    /* TODO: */

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_POPCORN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
        return FALSE;

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_POPCORN));

    MSG msg;

    /* Main message loop: */
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
/*--------------------------------------------------------------------------------------------------------------*/
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_POPCORN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = CreateSolidBrush(RGB(0, 0, 0) );
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_POPCORN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
/*--------------------------------------------------------------------------------------------------------------*/
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; /* Store instance handle in our global variable: */

   DWORD dwStyle = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX | WS_VISIBLE;

   RECT windowRect = { 0, 0, 320 * 3, 200 * 3};
   AdjustWindowRectEx(&windowRect, dwStyle, FALSE, 0);

   uint16_t window_width  = windowRect.right - windowRect.left;
   uint16_t window_height = windowRect.bottom - windowRect.top;

   uint16_t x_pos = (SCREEN_WIDTH - window_width) / 2;
   uint16_t y_pos = (SCREEN_HEIGHT - window_height) / 2;

   HWND hWnd = CreateWindowEx( 0,
                               szTitle,
                               L"Popcorn",
                               dwStyle,
                               x_pos, y_pos,
                               windowRect.right - windowRect.left,
                               windowRect.bottom - windowRect.top,
                               nullptr,
                               nullptr,
                               hInstance,
                               nullptr );

   if ( hWnd == 0 )
      return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
/*--------------------------------------------------------------------------------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
      int wmId = LOWORD(wParam);
      switch (wmId)
      {
      case IDM_ABOUT:
          DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
          break;


      case IDM_EXIT:
          DestroyWindow(hWnd);
          break;


      default:
          return DefWindowProc(hWnd, message, wParam, lParam);
      }
    }
    break;


    case WM_PAINT:
    {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hWnd, &ps);

      drawFrame(hdc);
      /* Paint this: */

      EndPaint(hWnd, &ps);
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;


    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
/*--------------------------------------------------------------------------------------------------------------*/
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;


    case WM_COMMAND:
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
      {
          EndDialog(hDlg, LOWORD(wParam));
          return (INT_PTR)TRUE;
      }
    break;
    }

    return (INT_PTR)FALSE;
}
/*--------------------------------------------------------------------------------------------------------------*/