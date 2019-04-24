// Brian Ahrens
// Banking Project using the do while loop
// This program also utilizes user defined functions for the mathematical transactions
// 4/11/18
// IT 1104

#include <iostream>
#include <string>
using namespace std;

// function names and parameters 
double depositFirstTimeBalance(double, double);
double depositBalance(double, double);
double withdrawBalance(double, double);
double olderBalance(double);
double withdrawlFirstTimeBalance(double);

const double startingBalance = 2000;
int main()
{
	string accountNum;
	double currentBalance = 0, previousBalance, deposit, withdraw;
	int choice, attempt = 0;
	char response;


	cout << "Welcome to SFC Bank. Please enter your account number" << endl;
	cin >> accountNum;

	do {
		cout << "Select the action you'd like to do." << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdrawal" << endl;
		cout << "3. Balance Inquiry" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "1. Deposit" << endl;
			cout << "Please enter the amount you'd like to deposit." << endl;
			cin >> deposit;

			if (attempt == 0)// this if statement is used if the user makes a deposit for the FIRST time 
			{

				// call function depositFirstTimeBalance
				currentBalance = depositFirstTimeBalance(startingBalance, deposit);


				cout << " Deposit" << endl;
				cout << "Account Number: " << accountNum << endl;
				cout << "Previous balance: $" << startingBalance << endl;
				cout << "Amount Deposited:  $" << deposit << endl;
				cout << "Current balance: $ " << currentBalance << endl;
				attempt++; // this will get the user out of this if statement for future transactions

			}
			else// else if the user SUCESSFULLY made a PREVIOUS deposit OR withdraw
			{
				// call function previous balance
				previousBalance = olderBalance(currentBalance);
				// call function deposit Balance 
				currentBalance = depositBalance(deposit, currentBalance);

				cout << " Deposit" << endl;
				cout << "Account Number: " << accountNum << endl;
				cout << "Previous balance: $" << previousBalance << endl;
				cout << "Amount Deposited:$ " << deposit << endl;
				cout << "Current balance: $ " << currentBalance << endl;
				attempt++;
			}



			break;

		case 2:
			cout << "2. Withdraw" << endl;
			cout << "Please enter the amount you'd like to withdraw." << endl;
			cin >> withdraw;


		
				if (attempt == 0)// this if statement is used if the user makes a withdraw for the FIRST time 
				{
					if (withdraw > startingBalance)// this if statement is used if the user wants to deposit more money than they have 
						cout << " You don't have enough cash to withdraw" << endl;

					else// ELSE make the withdraw
					{
						// call function first time withdraw balance
						currentBalance = withdrawBalance(startingBalance, withdraw);

						cout << " Withdraw" << endl;
						cout << "Account Number: " << accountNum << endl;
						cout << "Previous Balance: $" << startingBalance << endl;
						cout << "Amount Withdrawn:  $" << withdraw << endl;
						cout << "Current balance: $ " << currentBalance << endl;
						attempt++;
					}
				}

				else  // else if the user SUCESSFULLY made a PREVIOUS deposit OR withdraw
				{
					if (withdraw > currentBalance) // this if statement is used if the user wants to deposit more money than they have 
						cout << " You don't have enough cash to withdraw" << endl;

					else// ELSE make the withdraw
					{
						// call function previous balance
						previousBalance = olderBalance(currentBalance);

						// call function with draw balance
						currentBalance = withdrawBalance(previousBalance, withdraw);

						cout << " Withdraw" << endl;
						cout << "Account Number: " << accountNum << endl;
						cout << "Previous Balance: $" << previousBalance << endl;
						cout << "Amount Withdrawn:  $" << withdraw << endl;
						cout << "Current balance: $ " << currentBalance << endl;

					}
				}

			


			break;

		case 3:
			cout << "3. Balance Inquiry" << endl;

			if (attempt == 0) {
				cout << "Balance Inquiry" << endl;
				cout << " Account Number " << accountNum << endl;
				cout << "Current balance: $ " << startingBalance << endl;

			}
			else
			{
				cout << "Balance Inquiry" << endl;
				cout << " Account Number " << accountNum << endl;
				cout << "Current balance: $ " << currentBalance << endl;
			}

			break;

		case 4:
			cout << "You have now exited." << endl;
			cout << "Thank you for banking with us." << endl;
			response = 'B';// this makes the loop stop
			break;

		default:
			cout << "Invalid entry. Please try again." << endl;
			response = 'y';


		} // close of switch case
		if (choice != 4) // this code will execute if the user does not pick exit
		{
			cout << " Would you like to make another transaction ? " << endl;
			cout << " If so, please enter Y or y for yes " << endl;
			cout << " If not, please enter any other key " << endl;
			cin >> response;
			if ((response != 'y') && (response != 'Y'))
			{
				cout << "You have now exited." << endl;
				cout << "Thank you for banking with us." << endl;
			}
		}
	} while ((response == 'Y') || (response == 'y'));// end of for loop 


	cin.get();
	cin.get();
	return 0;
}
double olderBalance(double c) { // a function that overwrites the previous balance  from the current one
	double newBalance;
	newBalance = c;
	return newBalance;
}
double depositFirstTimeBalance(double a, double b) { // a function that adds money from a deposit when depositing for the first time
	int sum;
	sum = startingBalance + b;

	return sum;
}
double depositBalance(double d, double e) { // a function that adds money from a deposit
	int sum;

	sum = d + e;

	return sum;
}
double withdrawlFirstTimeBalance(double h) { // a function that subtracts money from a withdraw when withdrawing for the first time
	int diffrence;
	diffrence = startingBalance - h;

	return diffrence;
}
double withdrawBalance(double f, double g) {// a function that subtracts money from a withdrawel
	int diffrence;

	diffrence = f - g;
	return diffrence;
}
