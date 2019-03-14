#include "dec.h"
int main()
{
	int comm = 0;
	while (1) {
		std::cin >> comm; //ask question
		switch (comm) {
		case CREATE:
			//Create Account
			AccountHandler::CreateAccount();
			break;
		case DEPOSIT:
			//Save Money
			AccountHandler::DepositAccount();
			break;
		case WITHDRAW:
			//Withdraw Money
			AccountHandler::WithdrawMoney();
			break;
		case DISPLAY:
			//Display All accounts
			AccountHandler::Display();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "illegal selection.." << std::endl;
		}
	}

	return 0;
}