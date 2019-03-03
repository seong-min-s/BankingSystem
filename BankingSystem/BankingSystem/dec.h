#pragma once
#include <iostream>
typedef struct guest_info {
	int number;
	char name[20];
	double left;
}guest_info;
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, INQUIRE, EXIT };
void CreateAccount();
void DepositAccount();
void WithdrawMoney();
void Display();
void ShowMenu();
