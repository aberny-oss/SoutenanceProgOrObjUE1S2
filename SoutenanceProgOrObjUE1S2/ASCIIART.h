#pragma once
#include <iostream>
#include "Manager.h"
#include "Input.h"
class ASCIIART
{
private:
	Manager<Input>& inputManager; // référence vers ton manager

public:

	ASCIIART(Manager<Input>& mgr) : inputManager(mgr) {}

	void ARTConsoleMenu(int action);
	void ARTPersoMenu();
};

