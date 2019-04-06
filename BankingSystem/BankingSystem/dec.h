#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
namespace CREDIT_GRADE{
	enum {
		A = 7,
		B = 4,
		C = 2
	};
}
namespace ACCOUNT_TYPE {
	enum {
		ONLY_DEPOSIT = 0,
		NORMAL = 1,
		HIGHCREDIT = 2
	};
}
/*
	Ŭ���� �̸� : Account
	Ŭ���� ���� : Entity Class
*/
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public :
	Account(int number, char *name, double money);
	Account(const Account &copy);
	~Account();
	//virtual bool SetBalance(int COMMAND, double amount);
	virtual bool Deposit(double money);
	bool Withdraw(double money);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	virtual void ShowAllInfo()const;
};
class NormalAccount : public Account {
private:
	float interest;
public:
	NormalAccount(int number, char *name, double money, float ratio);
	bool Deposit(double amount);
	int GetDepositInterest(float interest);
	void ShowAllInfo()const;
};
class HightCreditAccount : public NormalAccount{
private:
	int specialRate;
public:
	HightCreditAccount(int number, char *name, double money, float ratio, int grade);
	bool Deposit(double amount);
	int GetExtraInterest(float interest);
	void ShowAllInfo()const;
};
/*
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : Control Class
*/
class AccountHandler {
public:
	const static int LEN_NAME = 20;
	static int numberOfguest;
	Account *account[100];
	~AccountHandler();
public:
	void ShowMenu() const;      //�޴� ���
	void CreateAccount(); //���� ����
	void DepositAccount();//��     ��
	void WithdrawMoney(); //��     ��
	void Display() const;		  //�ܾ� ��ȸ
};

