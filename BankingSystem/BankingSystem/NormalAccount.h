#pragma once
#include "BankingSystem.h"
class NormalAccount : public Account {
private:
	float interest;
public:
	NormalAccount(int number, char *name, double money, float ratio);
	bool Deposit(double amount);
	int GetDepositInterest(float interest);
	void ShowAllInfo()const;
};

NormalAccount::NormalAccount(int number, char *name, double money, float ratio) : Account(number, name, money), interest(ratio)
{ }
bool NormalAccount::Deposit(double money)
{
	return Account::Deposit(money)*Account::Deposit(GetDepositInterest(this->interest));
}
int  NormalAccount::GetDepositInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void NormalAccount::ShowAllInfo()const {
	std::cout << "보통계좌 입니다." << std::endl;
	Account::ShowAllInfo();
}