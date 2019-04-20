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
		cout << "�Էµ� �ݾ� : " << balance << "<0���� ���� �ݾ�>" << endl;
		cout << "���Է����ּ���." << endl;
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
		cout << "�Էµ� �ݾ� : " << balance << "<�ܾ׺���>" << endl;
		cout << "���Է����ּ���." << endl;
	}
};
#endif
