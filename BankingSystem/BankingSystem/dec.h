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
	~Account() {
		delete[]cusName;
	}
	bool SetBalance(int COMMAND, double amount);
	int GetNumber();
	char* GetName();
	double GetBalance();
	void ShowAllInfo();
};
void ShowMenu();      //�޴� ���
void CreateAccount(); //���� ����
void DepositAccount();//��     ��
void WithdrawMoney(); //��     ��
void Display();		  //�ܾ� ��ȸ

