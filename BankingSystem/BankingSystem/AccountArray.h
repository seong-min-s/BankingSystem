#ifndef _ACCOUNTARRAY_H_
#define _ACCOUNTARRAY_H_

#include "Account.h"
typedef Account* Account_ptr;
class AccountArray
{
private:
	Account_ptr *Acc_arr;
	int arr_size;
	AccountArray(const Account_ptr& copy) {}
	AccountArray& operator=(const Account_ptr& copy) {}
public:
	AccountArray();
	Account_ptr& operator[](int index);
	Account_ptr operator[](int index) const;
	~AccountArray();
};
#endif