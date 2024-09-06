#pragma once
#include <iostream>
#include <Vector>
#include <iomanip>

#include "clsCurrency.h"
#include "clsScreen.h"


class clsListCurrenciesScreen : protected clsScreen
{


	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}


public:

	static void ShowListCurrenciesScreen()
	{
		

		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string Subject = "\t   (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(Title, Subject);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\t\tThere is No Currencies In the System!";
		}
		else
		{
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrency(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

