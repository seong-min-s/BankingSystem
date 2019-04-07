#pragma once
#include "BankingSystem.h"
class HightCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HightCreditAccount(int number, char *name, double money, float ratio, int grade);
	bool Deposit(double amount);
	int GetExtraInterest(float interest);
	void ShowAllInfo()const;
};

HightCreditAccount::HightCreditAccount(int number, char *name, double money, float ratio, int special) : NormalAccount(number, name, money, ratio), specialRate(special) {}
bool HightCreditAccount::Deposit(double money)
{
	return NormalAccount::Deposit(money)*Account::Deposit(GetExtraInterest(grade / 100.0));
}
int HightCreditAccount::GetExtraInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void HightCreditAccount::ShowAllInfo()const
{
	std::cout << "신용계좌" << "_등급 :" << grade << std::endl;
	Account::ShowAllInfo();
}