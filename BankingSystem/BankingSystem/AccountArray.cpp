#include "BankingSystem.h"
#include "AccountArray.h"

AccountArray::AccountArray() :arr_size(LEN_NAME)
{
	Acc_arr = new Account_ptr[LEN_NAME];
}
Account_ptr& AccountArray::operator[](int index)
{
	if (index >= arr_size || index < 0) {
		fprintf(stderr, "범위에 벗어난 값 입니다.");
		exit(1);
	}
	return this->Acc_arr[index];
}
Account_ptr AccountArray::operator[](int index) const
{
	if (index >= arr_size || index < 0) {
		//fprintf(stderr, "범위에 벗어난 값 입니다.");
		//exit(1);
	}
	return this->Acc_arr[index];
}
AccountArray::~AccountArray()
{
	delete[]Acc_arr;
}
