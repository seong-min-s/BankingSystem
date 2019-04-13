/*
클래스 이름 : Account
클래스 유형 : Entity Class
*/
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include "mystring.h"
class Account {
private:
	int accID;
	mystring cusName;
	double balance;
public:
	Account() :accID(0), balance(0) { cusName = "null"; };
	Account(int number, mystring name, double money);
	Account(const Account &copy);
	Account& operator=(const Account& copy);

	virtual bool Deposit(double money);
	bool Withdraw(double money);

	int GetNumber()const;
	mystring GetName()const;
	double GetBalance()const;

	virtual void ShowAllInfo()const;

	~Account();
};
#endif