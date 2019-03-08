#include "dec.h"
using namespace COMMAND_CONSIST;
int main()
{
	int comm = 0;
	BankingSystem *bs = new BankingSystem;
	while (1) {
		bs->ShowMenu();
		std::cin >> comm; //ask question
		switch (comm) {
		case CREATE:
			//Create Account
			bs->CreateAccount();
			break;
		case DEPOSIT:
			//Save Money
			bs->DepositAccount();
			break;
		case WITHDRAW:
			//Withdraw Money
			bs->WithdrawMoney();
			break;
		case DISPLAY:
			//Display All accounts
			bs->Display();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "illegal selection.." << std::endl;
		}
	}

	return 0;
}