#include "Core/StateMachine.h"

// Stored instance handle for use in Win32 API calls such as FindResource
HINSTANCE hInst;

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    StateMachine* mStateMachine = StateMachine::getInstance(hInstance, nCmdShow);
    mStateMachine->run();
    return 0;
}
