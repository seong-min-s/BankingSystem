#ifndef BOUNDACHECKARRA_H
#define BOUNDACHECKARRA_H
#include"BankingSystem.h"
template <typename T>
class BoundCheckArray {
private:
	int len;
	T *arr;
	BoundCheckArray(const BoundCheckArray &copy)
	{};
	BoundCheckArray& operator=(const BoundCheckArray &ref)
	{};
public:
	BoundCheckArray();
	BoundCheckArray(int n);
	T& operator[] (int idx);
	T operator[] (int idx) const;

	int GetLength() const;
	~BoundCheckArray();
};
template <typename T>
BoundCheckArray<T>::BoundCheckArray()
{
	arr = new T[LEN_NAME];
}
template <typename T>
BoundCheckArray<T>::BoundCheckArray(int n) : len(n)
{
	arr = new T[n];
}
template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 && idx >= LEN_NAME) {
		fprintf(stderr, "index error\n");
		exit(1);
	}
	return arr[idx];
}
template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
	return arr[idx];
}
template <typename T>
int BoundCheckArray<T>::GetLength() const
{
	return len;
}
template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}
#endif