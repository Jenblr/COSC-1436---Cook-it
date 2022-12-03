// COSC 1436 - FoodX Version II.cpp : Defines the entry point for the application.

#include "pch.h"
#include "framework.h"
#include "COSC 1436 - FoodX Version II.h"
#include "mainfunction.h"
#include <windows.h>
#include <tchar.h>

using namespace std;

#define MAX_LOADSTRING 100
#define AFRICA_BUTTON 1
#define NORTH_AMERICA_BUTTON 2
#define ASIA_BUTTON 3
#define EUROPE_BUTTON 4
#define LATIN_AMERICA_BUTTON 5
#define BEEF_BUTTON 6

// Global Variables:
HINSTANCE hInst, hIstance;                             // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND Logo;                                      // Window handle = contains part of logo image insertion
HBITMAP bitmap, hLogoImage;                     // Allows insertion of images
HDC localDC;

void AddControls(HWND);
void InsertImage();
void displayDialog(HWND);
void registerDialogClass(HINSTANCE);


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProcedure(HWND, UINT, WPARAM, LPARAM);

// ************************************************************************************
// The main function for a windows application, just like a regular C++ app           *
// NOTE : APIENTRY is an alias (the same) as WINPAI                                   *
// ************************************************************************************
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
   

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_COSC1436FOODXVERSIONII, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);
  

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    registerDialogClass(hInstance);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COSC1436FOODXVERSIONII));

    MSG msg;

    // Main message loop:
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



// *******************************************
//  FUNCTION: MyRegisterClass()              *
//                                           *
//  PURPOSE: Registers the window class.     *
// *******************************************
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_COSC1436FOODXVERSIONII));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_COSC1436FOODXVERSIONII);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
  

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

    // Manipulates windows size upon launch
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, 0, 1350, 800, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   // Tells Windows to make the window visible
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//*********************************************************
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)         *
//                                                        *
//  PURPOSE: Processes messages sent for the main window. *
//                                                        *
//  WM_CREATE   - contains info about window              *
//  WM_COMMAND  - process the application menu            *
//  WM_PAINT    - Paint the main window                   *
//  WM_DESTROY  - post a quit message and return          *
//                                                        *
//*********************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Welcome to Cook It! Our application's purpose is to provide meal recipes based on regional cravings and dietary needs . Please begin by choosing a region below.");
    

    switch (message)
    {
	case WM_CREATE:
	{
            // Calls to void function
			InsertImage();
            AddControls(hWnd);
            
	}
		break;
    // When a control is pressed, this allows us to define what happens
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            // Below are cases when regional buttons are pressed = dialog window pops up
            case AFRICA_BUTTON:
            {
                MessageBoxW(nullptr, L"Below are African recipes. Please choose a protein to obtain recipes.\n\n", L"African Recipes", MB_DEFBUTTON1);
                
            }
            	break;
			case NORTH_AMERICA_BUTTON:
                MessageBoxW(nullptr, L"Below are North American recipes. Please choose a protein to obtain recipes.", L"North American Recipes", MB_DEFBUTTON2);
				break;
			case ASIA_BUTTON:
                MessageBoxW(nullptr, L"Below are Asian recipes. Please choose a protein to obtain recipes.", L"Asian Recipes", MB_DEFBUTTON3);
				break;
			case EUROPE_BUTTON:
                MessageBoxW(nullptr, L"Below are European recipes. Please choose a protein to obtain recipes.", L"European Recipes", MB_DEFBUTTON4);
				break;
			case LATIN_AMERICA_BUTTON:
                MessageBoxW(nullptr, L"Below are Latin American recipes. Please choose a protein to obtain recipes.", L"Latin American Recipes", MB_DEFBUTTON1);
				break;

            // Menu cases
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

			HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            TextOut(hdc,
                150, 5,
                greeting, _tcslen(greeting));
            EndPaint(hWnd, &ps);
        }
        break;
    // App processes quit when x at top right is clicked 
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    // Takes care of remaining messages after quit that are no longer processing
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box under "Help" menu.
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

// Controls what's on the front page
//CreateWindowW(L"Button", L"Beef", WS_VISIBLE | WS_CHILD, 150, 600, 100, 100, hWnd, (HMENU)BEEF_BUTTON, NULL, NULL);
void AddControls(HWND hWnd)
{
    // Region buttons
    CreateWindowW(L"Button", L"Africa", WS_VISIBLE | WS_CHILD, 150, 600, 100, 100, hWnd, (HMENU)AFRICA_BUTTON, NULL, NULL );
    CreateWindowW(L"Button", L"North America", WS_VISIBLE | WS_CHILD, 370, 600, 100, 100, hWnd, (HMENU)NORTH_AMERICA_BUTTON, NULL, NULL);
    CreateWindowW(L"Button", L"Asia", WS_VISIBLE | WS_CHILD, 600, 600, 100, 100, hWnd, (HMENU)ASIA_BUTTON, NULL, NULL);
    CreateWindowW(L"Button", L"Europe", WS_VISIBLE | WS_CHILD, 830, 600, 100, 100, hWnd, (HMENU)EUROPE_BUTTON, NULL, NULL);
    CreateWindowW(L"Button", L"Latin America", WS_VISIBLE | WS_CHILD, 1050, 600, 100, 100, hWnd, (HMENU)LATIN_AMERICA_BUTTON, NULL, NULL, NULL);

    // Protein buttons
   

    // Logo image
    Logo = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 160, 50, 100, 100, hWnd, NULL, NULL, NULL);
    SendMessageW(Logo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
}

// Allows program to pull image
// Remember to resize image to 32bitdepth using iconfx 
void InsertImage()
{
    hLogoImage = (HBITMAP)LoadImageW(NULL, L"CookITLogo.bmp", IMAGE_BITMAP, 1000, 500, LR_LOADFROMFILE); // Defaulted image size from 0,0 

}

LRESULT CALLBACK DialogProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lParam);
	}
}

void registerDialogClass(HINSTANCE hIstance)
{
	WNDCLASSEXW dialog = { 0 };

	dialog.lpfnWndProc = DialogProcedure;
	dialog.hInstance = hIstance;
	dialog.hCursor = LoadCursor(nullptr, IDC_ARROW);
	dialog.hbrBackground = (HBRUSH)COLOR_WINDOW;
	dialog.lpszClassName = L"myDialogClass";


	RegisterClassExW(&dialog);
}

void displayDialog(HWND hWnd)
{

    HWND hDlg = CreateWindowW(L"myDialogClass", L"Dialog", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 1000, 1000, 500, 500, hWnd, NULL, NULL, NULL);
}

	