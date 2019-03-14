#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
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
	bool SetBalance(int COMMAND, double amount);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
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

