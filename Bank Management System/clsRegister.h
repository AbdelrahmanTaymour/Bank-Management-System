#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

class clsRegisterScreen : protected clsScreen
{
private:
	static bool _Register()
	{
		system("cls");

		clsAddNewUserScreen::ShowAddNewUserScreen();
		CurrentUser.RegisterLogIn();
		enMode::Login;

		cout << "\n\nDone. Please Press any key to go to Main Screen...\n\n";
		system("pause>0");
		clsMainScreen::ShowMainMenue();
		return true;
	}


public:
	static bool ShowRegisterScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  [1] Register Screen");
		return _Register();
	}
};

