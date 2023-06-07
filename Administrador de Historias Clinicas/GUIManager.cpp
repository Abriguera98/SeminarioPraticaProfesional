#include <cassert>

#include "GUIManager.h"
#include "StateMachine.h"

static TCHAR szWindowClass[] = _T("SistemaDeGestionDeHistoriasClinicas");

static TCHAR szTitle[] = _T("Sistema de Gestion de Historias Clinicas");

GUIManager* GUIManager::mInstance = nullptr;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

GUIManager* GUIManager::getInstance(HINSTANCE& hInstance)
{
	if (mInstance == nullptr) {
		mInstance = new GUIManager(hInstance);
	}
	return mInstance;
}

HWND* GUIManager::setIdle()
{
    HWND* hWnd = new HWND;
    *hWnd = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 100,
        NULL,
        NULL,
        *mHInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return nullptr;
    }

    return hWnd;
}

GUIManager::GUIManager(HINSTANCE& hInstance)
{
    WNDCLASSEX* wcex = new WNDCLASSEX();

    wcex->cbSize = sizeof(WNDCLASSEX);
    wcex->style = CS_HREDRAW | CS_VREDRAW;
    wcex->lpfnWndProc = OnMessage;
    wcex->cbClsExtra = 0;
    wcex->cbWndExtra = 0;
    wcex->hInstance = hInstance;
    wcex->hIcon = LoadIcon(wcex->hInstance, IDI_APPLICATION);
    wcex->hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex->hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex->lpszMenuName = NULL;
    wcex->lpszClassName = szWindowClass;
    wcex->hIconSm = LoadIcon(wcex->hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);
    }

    // Store instance handle in our global variable
    mHInstance = &hInstance;
}
