#pragma once
#include <iostream>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, INQUIRE, EXIT };
class Account {
private:
	int number;
	char *name;
	double balance;
public :
	Account() {
		name = new char[20];//문제요구사항 : 멤버변수로 문자열 포인터를 지니고, 동적 할당의 형태로 구현해야 한다.
	}
	~Account() {
		delete[]name;
	}
	bool InitAccount(int number, char *name, double balance);
};
void CreateAccount();
void DepositAccount();
void WithdrawMoney();
void Display();
void ShowMenu();
