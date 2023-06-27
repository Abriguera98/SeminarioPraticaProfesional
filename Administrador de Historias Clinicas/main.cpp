#include "Core/StateMachine.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    StateMachine* mStateMachine = StateMachine::getInstance();

    mStateMachine->run();

}