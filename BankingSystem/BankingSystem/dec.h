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
		name = new char[20];//�����䱸���� : ��������� ���ڿ� �����͸� ���ϰ�, ���� �Ҵ��� ���·� �����ؾ� �Ѵ�.
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
