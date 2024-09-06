#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"



class clsLoginRegisterRecordsScreen : protected clsScreen
{
private:

	static void _PrintLogInRegisterLine(clsUser::stRegisterLogInRecord LogInData)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LogInData.DateTime;
		cout << "| " << setw(20) << left << LogInData.UserName;
		cout << "| " << setw(20) << left << LogInData.Password;
		cout << "| " << setw(10) << left << LogInData.Permissions;

	}



public:

	static void ShowLoginRegisterRecordsScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector<clsUser::stRegisterLogInRecord> vLogInRegisterRecords = clsUser::GetRegisterLogInList();

		string Title = "\t  Login Register List Screen";
		string Subject = "\t    (" + to_string(vLogInRegisterRecords.size()) + ") Record(s).";
		_DrawScreenHeader(Title, Subject);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(35) << left << "Date / Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vLogInRegisterRecords.size() == 0)
		{
			cout << "\t\t\t\tNo Records Available In the System!";
		}
		else
		{
			for (clsUser::stRegisterLogInRecord& Record : vLogInRegisterRecords)
			{
				_PrintLogInRegisterLine(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}

};

