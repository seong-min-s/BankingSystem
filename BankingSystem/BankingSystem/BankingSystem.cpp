#include "BankingSystem.h"
int main()
{
	AccountHandler handler;
	int comm = 0;
	while (1) {
		handler.ShowMenu();
		std::cin >> comm; //ask question
		switch (comm) {
		case CREATE:
			//Create Account
			handler.CreateAccount();
			break;
		case DEPOSIT:
			//Save Money
			handler.DepositAccount();
			break;
		case WITHDRAW:
			//Withdraw Money
			handler.WithdrawMoney();
			break;
		case DISPLAY:
			//Display All accounts
			handler.Display();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "illegal selection.." << std::endl;
		}
	}

	return 0;
}