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
	double balance;
	mystring cusName;
public:
	Account(int number, mystring name, double money);
	Account(const Account &copy);
	Account& operator=(const Account& copy);

	virtual void Deposit(double money);
	void Withdraw(double money);

	int GetNumber()const;
	mystring GetName()const;
	double GetBalance()const;

	virtual void ShowAllInfo()const;

	~Account();
};
#endif