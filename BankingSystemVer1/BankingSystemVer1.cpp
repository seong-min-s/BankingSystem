#include "dec_fun.h"

int main()
{
	int comm = 0;

	while(1){
		ShowMenu();
		std::cin >> comm; //ask question
		switch (comm) {
		case CREATE:
			//Create Account
			CreateAccount();
			break;
		case DEPOSIT:
			//Save Money
			DepositAccount();
			break;
		case WITHDRAW:
			//Withdraw Money
			WithdrawMoney();
			break;
		case DISPLAY:
			//Display All accounts
			Display();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "illegal selection.." << std::endl;
		}
	}

	return 0;
}