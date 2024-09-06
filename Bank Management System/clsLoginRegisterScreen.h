#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsLoginScreen.h"
#include "clsRegister.h"

class clsLoginRegisterScreen
{
public:
	static bool ShowLoginRegisterScreen()
	{
		system("cls");

		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << "[1] Login Screen";
		cout << "\n\n\t\t\t\t\t  " << "[2] Register Screen";
		cout << "\n\t\t\t\t\t______________________________________\n\n";

		cout << "\n\nEnter your Choice : ";
		int Choice = clsInputValidate::ReadShortNumberBetween(1, 2,"Invalid Choice. Plase Enter [1] to Login or [2] for Register: ");

		if (Choice == 1)
			return clsLoginScreen::ShowLoginScreen();
		else
			return clsRegisterScreen::ShowRegisterScreen();
	}
};

