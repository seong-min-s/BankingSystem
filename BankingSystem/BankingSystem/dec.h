#pragma once
#include <iostream>
#include <cstring>
namespace COMMAND_CONSIST {
	enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, INQUIRE, EXIT };
}
class Account {
private :
	int number;
	char *name;
	double left;
public :
	Account(){
		number = 0;
		left = 0;
		name = new char[20];
		std::cout << "Account 持失切 持失"<<std::endl;
	}
	void CreateAccount(int number, char* name);
	int GetAccountNumber();
	char* GetAccountName();
	double GetAccountBanlance();
	bool DepositAccount(int money);
	bool WithdrawAccount(int money);
	/*
		Account(const int &number, char *name):number(number),name(name){
		left = 0;
		std::cout << "Account 持失切 持失"<<std::endl;
	}*/
};
class BankingSystem {
private :
	Account *account;
	int numberOfAccount;
public :
	BankingSystem() {
		account = new Account[100];
		this->numberOfAccount = 0;
		std::cout << "BankingSystem 持失切 持失" << std::endl;
	}
	void CreateAccount();
	void DepositAccount();
	void WithdrawMoney();
	void Display();
	void ShowMenu();
};
