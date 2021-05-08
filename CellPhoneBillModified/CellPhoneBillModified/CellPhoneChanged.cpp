// Brian Ahrens
// Assignment # 2 Cell Phone Bill Exercise  
// This can calcuate a bill for regular or premium services
// with Extra Credit
// 11/4/ 16
// Dr. Westcott
// pg 259 # 14 a and b


#include <iostream>
#include <iomanip>

using namespace std;

// named constant for regular service limit amount
const double  RegularServiceAmount = 10.00; //  The base regular fee
const double AmountDueSirCharge = .20;  // charge rate when minutes >50
const double FreeMinutes = 50;        // variable to store free minutes amount
const double  MaxFreeMinutes = 50;  // variable to store  the max free minutes 


// named constant for premium service limit amount
const double PremiumServiceAmount = 25.00; // The base premium fee
const double FreeDayMinutes = 75;     // variable to store free day minutes limit
const double FreeNightMinutes = 100;
const double DayCharge = .01;
const double NightCharge = .05;
const double  MaxFreeDayMinutes = 75;
const double  MaxFreeNightMinutes = 100;

int main()
{// start of program 

	int AccountNumber; // number for account
	char AccountType; // asks for the account type R, r, P or p
	int Minutes;     // Asks for the # of minutes used ( for regular service )
	int DayMinutes;  // Asks day minutes ( for premium service ) 
	int NightMinutes; // Asks night minutes ( for premium service ) 
	double AmountDue; // Variable for the amount due 
	bool restart = true;  // this variable is needed to restart the loop
	char response; // variable used to continue the loop or not

	cout << fixed << showpoint;
	cout << setprecision(2);   //  format currency properly

	while (restart == true)
	{ // start of loop

		cout << " Enter the account number " << endl;
		cout << " and the type of account ( enter R or r)" << endl; // Asks user to input the acct #
		cout << " for regular , for premium ( enter P or p ) " << endl;  // asks user for the type of acct   
		cin >> AccountNumber >> AccountType;  // input the information asked



		switch (AccountType)
		{// start of switch
		case 'R':
		case 'r':

			cout << " Enter The minutes used " << endl; // asks user the # of minutes used
			cin >> Minutes;

			if (Minutes <= MaxFreeMinutes)  // executes if the input is 50 or less for minutes 

				AmountDue = RegularServiceAmount;

			else  // paired with the above if , executes if the input is greater than 50 for minutes

				AmountDue = RegularServiceAmount + (Minutes - FreeMinutes) * AmountDueSirCharge; // A formula if the minutes go over 50

			cout << "-------------------------------------------------------------------------------------------" << endl; // art work
			cout << "-------------------------------------------------------------------------------------------" << endl; // fancy
			cout << "The bill information for account number " << AccountNumber; // print bill
			cout << " Regular Service " << " for " << Minutes << endl;  // for regular
			cout << " minutes is $  " << AmountDue << endl;  
			break;

		case 'P':
		case 'p':

			cout << " Enter the day and night minutes used " << endl;  // Asks the user to input day and night minutes
			cout << " Day minutes are minutes used from 6:00 AM to 6:00 PM " << endl;
			cout << " Night minutes are minutes used from 6:00 PM to 6:00 AM " << endl;
			cin >> DayMinutes >> NightMinutes;

			AmountDue = PremiumServiceAmount;// standard amount if the user is <= 75 or 100 for each type of minute

			if (DayMinutes > MaxFreeDayMinutes)
				AmountDue = PremiumServiceAmount + (DayMinutes - FreeDayMinutes)* DayCharge; // A formula if the day minutes go over 75


			if (NightMinutes > MaxFreeNightMinutes)
				AmountDue = PremiumServiceAmount + (NightMinutes - FreeNightMinutes)* NightCharge; // A formula if the night minutes go over 100



			cout << "-------------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------------" << endl;
			cout << " The bill information for  account number " << AccountNumber;
			cout << " Premium Service " << " for " << DayMinutes + NightMinutes << endl; // print bill
			cout << " minutes is $ " << AmountDue << endl; // for premium

			break;

		default:
			cout << " Invalid character Please try again " << endl; //  exceuted if input an invalid character for service type such as 'f'

		}// end of this switch
	


		cout << " Would you like to perform another transaction ? " //asks user
			<< endl;
		cout << " enter Y or y for yes" << endl; // if they want to make another 
		cout << "enter N or n for no " << endl;  // transaction
		cin >> response;

		switch (response) // loop for contiuning 
		{ // start of switch
		case 'y':
		case 'Y':
			restart = true; // this will continue the loop
			break;

		case 'n':
		case 'N':
			restart = false; // this will end the loop
			cout << "Have a nice day " << endl;
			break;

		default:
			cout << "Invalid response " << endl;

		}// end  of switch
	} // end of loop




			cin.get(); // used to hold output on the screen so it can be read
			cin.get();

			return 0;
		} // end program
	