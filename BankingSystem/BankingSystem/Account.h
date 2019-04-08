/*
클래스 이름 : Account
클래스 유형 : Entity Class
*/
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public:
	Account(int number, char *name, double money);
	Account(const Account &copy);
	
	virtual bool Deposit(double money);
	bool Withdraw(double money);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	virtual void ShowAllInfo()const;
	~Account();
};
#endif