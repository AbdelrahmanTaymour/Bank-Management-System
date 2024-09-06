#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		string Username, Password;

		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYou are locked after 3 failed Trails.\n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		enMode::Login;
		clsMainScreen::ShowMainMenue();
		return true;
	}


public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}



};

