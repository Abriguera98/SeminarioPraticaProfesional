#include <cassert>

#include "StateMachine.h"

StateMachine* StateMachine::mInstance = nullptr;

StateMachine::StateMachine(HINSTANCE& hInstance, int nCmdShow)
	:mState(State::eInitializing), mCmdShow(nCmdShow)
{
	mGUIManager = GUIManager::getInstance(hInstance);
}

void StateMachine::setWaiting(bool waiting)
{
	mWaiting = waiting;
}

StateMachine* StateMachine::getInstance(HINSTANCE& hInstance, int nCmdShow)
{
	if (mInstance == nullptr)
	{
		mInstance = new StateMachine(hInstance, nCmdShow);
	}
	return mInstance;
}

StateMachine* StateMachine::getInstance()
{
	//SHOULD NEVER USE UNLESS THERE ALREADY IS AN INSTANCE
	assert(mInstance);
	return mInstance;
}

void StateMachine::run()
{
	while (mState != State::eExit)
	{
		doStep();
		getNextStep();
	}
}

void StateMachine::doStep()
{
	HWND* hWnd = nullptr;
	switch (mState)
	{
		case eInitializing:
			hWnd = mGUIManager->setIdle();
			ShowWindow(*hWnd, mCmdShow);
			UpdateWindow(*hWnd);
			break;
		case eShowWelcomeScreen:
			break;
		case eWaiting:
			// Main message loop:
			MSG msg;
			mWaiting = true;
			while (GetMessage(&msg, NULL, 0, 0) && mWaiting)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			break;
		case eExit:
			break;
	}
}

void StateMachine::getNextStep()
{
	switch (mState)
	{
	case eInitializing:
		mState = eWaiting;
		break;
	case eShowWelcomeScreen:
		break;
	case eWaiting:
		mState = eExit;
		break;
	case eExit:
		break;
	}
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - Post a quit message and return
LRESULT CALLBACK OnMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");
	StateMachine* mStateMachine = StateMachine::getInstance();

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		mStateMachine->setWaiting(false);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}