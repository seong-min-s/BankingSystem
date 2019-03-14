#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
const int LEN_NAME = 20;
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public :
	Account(int number, char *name, double money) : accID(number), balance(money){
		this->cusName = new char[strlen(name)+1];//�����䱸���� : ��������� ���ڿ� �����͸� ���ϰ�, ���� �Ҵ��� ���·� �����ؾ� �Ѵ�.
		strcpy(this->cusName, name);
	}
	Account(const Account &copy) :accID(copy.accID),balance(copy.balance){
		this->cusName = new char[strlen(copy.cusName)+1];
		strcpy(cusName, copy.cusName);
	}
	~Account() {
		delete[]cusName;
	}
	bool SetBalance(int COMMAND, double amount);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	void ShowAllInfo()const;
};
class AccountHandler {
public:
	const static int LEN_NAME = 20;
	static int numberOfguest;
	static Account *account[100];
public:
	static void ShowMenu();      //�޴� ���
	static void CreateAccount(); //���� ����
	static void DepositAccount();//��     ��
	static void WithdrawMoney(); //��     ��
	static void Display();		  //�ܾ� ��ȸ
};

