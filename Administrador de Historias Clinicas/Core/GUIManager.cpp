#include <cassert>

#include "GUIManager.h"
#include "StateMachine.h"

GUIManager* GUIManager::mInstance = nullptr;

GUIManager* GUIManager::getInstance()
{
	if (mInstance == nullptr) {
		mInstance = new GUIManager();
	}
	return mInstance;
}

GUIManager::GUIManager()
{
}