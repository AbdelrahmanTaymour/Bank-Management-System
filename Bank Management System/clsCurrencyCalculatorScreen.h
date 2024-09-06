#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not fount, Choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		return Currency1;
	}

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
			cout << AmountInUSD << " USD" << endl;
			return;
		}
		else
		{
			float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
			
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
			cout <<  AmountInCurrencyTo << CurrencyTo.CurrencyCode() << endl;
			
			return;
		}
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		
		char Continue = 'Y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}

	}


};

