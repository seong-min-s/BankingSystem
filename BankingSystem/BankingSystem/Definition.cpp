#include "dec.h"//함수 또는 변수정의

void Account::CreateAccount(int number, char* name)
{
	strcpy(this->name, name);
	this->number = number;
}
int Account::GetAccountNumber()
{
	return this->number;
}
char* Account::GetAccountName()
{
	return this->name;
}
double Account::GetAccountBanlance() {
	return this->left;
}
bool Account::DepositAccount(int money) {
	if (money < 0) {
		return false;
	}else {
		this->left=+money;
	}
}
bool Account::WithdrawAccount(int money) {
	if (money < 0) {
		return false;
	}
	else {
		this->left=-money;
	}
}
void BankingSystem::CreateAccount() {
	int number;
	char name[20];
	numberOfAccount++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;
	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;
	account[numberOfAccount].CreateAccount(number, name);
}
void BankingSystem::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfAccount; i++)
	{
		if (account[i].GetAccountNumber() == temp_number)
		{
			if(account[i].DepositAccount(temp_money))
				break;
			else {
				std::cout << "error <deposit>" << std::endl;
			}
		}
	}
	std::cout << "입금 완료" << std::endl;
}
void BankingSystem::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "출금 액 :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfAccount; i++)
	{
		if (account[i].GetAccountNumber() == temp_number)
		{
			if (account[i].WithdrawAccount(temp_money))
				break;
			else {
				std::cout << "error <withdraw>" << std::endl;
			}
		}
	}
	std::cout << "출금 완료" << std::endl;
}
void BankingSystem::Display() 
{
	for (int i = 0; i <= numberOfAccount; i++)
	{
		std::cout << "이름 :" << account[i].GetAccountName() << std::endl;
		std::cout << "계좌 번호 :" << account[i].GetAccountNumber() << std::endl;
		std::cout << "잔액 :" << account[i].GetAccountBanlance()<< std::endl;
		std::cout << std::endl;
	}
}
void BankingSystem::ShowMenu()
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
/*
고객 계좌정보 구조체 정보
typedef struct guest_info{
	int number;
	char name[20];
	int left;
}guest_info;
*/