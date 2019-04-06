/*
클래스 이름 : Account
클래스 유형 : Entity Class
*/
#pragma once
#include "dec.h"
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public:
	Account(int number, char *name, double money);
	Account(const Account &copy);
	~Account();
	bool SetBalance(int COMMAND, double amount);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	void ShowAllInfo()const;
};