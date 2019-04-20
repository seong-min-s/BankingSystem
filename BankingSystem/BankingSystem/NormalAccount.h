#ifndef _NORMAL_H
#define _NORMAL_H
#include "Account.h"
#include "mystring.h"
class NormalAccount : public Account {
private:
	float interest;
public:
	NormalAccount(int number,mystring name, double money, float ratio) : Account(number, name, money), interest(ratio) {};
	void Deposit(double amount)
	{
		Account::Deposit(amount);
		Account::Deposit(GetDepositInterest(this->interest));
	}
	int GetDepositInterest(float interest)
	{
		return Account::GetBalance()*interest;
	}
	void ShowAllInfo()const {
		std::cout << "보통계좌 입니다." << std::endl;
		Account::ShowAllInfo();
	}
};
#endif