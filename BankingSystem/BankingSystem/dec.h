#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
namespace INTEREST_GRADE{
	enum {
		A = 107,
		B = 104,
		C = 102
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
	bool Deposit(double money);
	bool Withdraw(double money);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	void ShowAllInfo()const;
};
class NormalAccount : public Account {
private:
	float interest;
public:
	NormalAccount(int number, char *name, double money, float ratio);
	virtual bool SetBalance(int COMMAND, double amount);

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

