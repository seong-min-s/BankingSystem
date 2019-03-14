#include "dec.h"//함수 또는 변수정의

int AccountHandler::numberOfguest = -1;
Account::Account(int number, char *name, double money) : accID(number), balance(money) {
	this->cusName = new char[strlen(name) + 1];//문제요구사항 : 멤버변수로 문자열 포인터를 지니고, 동적 할당의 형태로 구현해야 한다.
	strcpy(this->cusName, name);
}
Account::Account(const Account &copy) :accID(copy.accID), balance(copy.balance) {
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
Account::~Account() {
	delete[]cusName;
}
bool Account::SetBalance(int COMMAND, double amount)
{
	if (amount < 0) {
		return false;
	}
	if (COMMAND == DEPOSIT)
	{
		this->balance += amount;
	}
	else if (COMMAND == WITHDRAW) {
		this->balance -= amount;
	}
	return true;
}
int Account::GetNumber() const
{
	return accID;
}
char* Account::GetName() const//이름을 얻는 과정에서 오류발생
{
	return this->cusName;
}
double Account::GetBalance()const
{
	return this->balance;
}
void Account::ShowAllInfo() const
{
	std::cout << "이    름 : " << cusName << std::endl;
	std::cout << "계좌번호 : " << accID << std::endl;
	std::cout << "잔    액 : " << balance << std::endl;
}

void AccountHandler::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 번호 :(이름 아님)" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 금액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber()== temp_number)
		{
			account[i]->SetBalance(DEPOSIT, temp_money);
			std::cout << "입금 완료" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "출금 액 :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber() == temp_number)
		{
			account[i]->SetBalance(WITHDRAW, temp_money);
			std::cout << "출금 완료" << std::endl;
			break;
		}
	}
}
void AccountHandler::Display() const
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		account[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void AccountHandler::CreateAccount() {
	int number, balance;
	char name[LEN_NAME];
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;
	account[numberOfguest] = new Account(number, name, balance);
}
void AccountHandler::ShowMenu() const
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccountHandler::numberOfguest; i++) {
		delete[i]account;
	}
}