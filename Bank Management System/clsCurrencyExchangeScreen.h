#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
	enum enCurrencyMenueOptions 
	{eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short ReadCurrencyOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");

		return Choice;
	}
	
	static void _GoBackToCurrencyMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nThe List Currencies will be here.\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nThe Find Currency will be here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nThe Update Rate will be here.\n";
		clsUpdateRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nThe Currency Calculator will be here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _PerformCurrencyExchangeOption(short Option)
	{
		switch (Option)
		{

		case enCurrencyMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case enCurrencyMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case enCurrencyMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case enCurrencyMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		}

		case enCurrencyMenueOptions::eMainMenue:
		{

		}

		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{

		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		_DrawScreenHeader("Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeOption(ReadCurrencyOption());
	}
};

