#ifndef _ACCOUNT_EXCEPTION_H
#define _ACCOUNT_EXCEPTION_H
#include "BankingSystem.h"
class AccountException
{
private:

public:
	virtual void What() = 0;
};

class DepositException : public AccountException
{
private:
	double balance;
public:
	DepositException(int m):balance(m){}
	void What()
	{
		cout << "입력된 금액 : " << balance << "<0보다 작은 금액>" << endl;
		cout << "재입력해주세요." << endl;
	}
};
class WithdrawException : public AccountException
{
private:
	double balance;
public:
	WithdrawException(int m) :balance(m) {}
	void What()
	{
		cout << "입력된 금액 : " << balance << "<잔액부족>" << endl;
		cout << "재입력해주세요." << endl;
	}
};
#endif
