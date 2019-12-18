#pragma once
#include "pch.h"
#include <vector>
#include <string>

class MyNomber
{
private:
	std::vector<int64_t> value;
	bool isPositive;
	const int64_t base = 100000000;

	MyNomber Plus(MyNomber first, MyNomber second);
	MyNomber Minus(MyNomber higher, MyNomber lower);
	int CompareTwo(MyNomber first, MyNomber second);
	MyNomber Mult(MyNomber first, MyNomber second);
	MyNomber Mult(MyNomber first, int32_t second);
	int64_t DivOneIter(MyNomber first, MyNomber second, MyNomber& ost);
	MyNomber Div(MyNomber first, MyNomber second);
	MyNomber Ost(MyNomber first, MyNomber second);
	MyNomber SqRoot(MyNomber first);
public:
	MyNomber();
	MyNomber(std::string inp);
	MyNomber(int t);
	MyNomber(std::vector<int64_t> t_value, bool t_isPositive);

	//~MyNomber();

	MyNomber Mod();
	MyNomber ToNeg();
	MyNomber GetZero();
	MyNomber GetOne();

	bool operator >(MyNomber other);
	bool operator <(MyNomber other);
	bool operator ==(MyNomber other);
	bool IsEven();

	MyNomber operator = (MyNomber other);
	MyNomber operator + (MyNomber other);
	MyNomber operator - (MyNomber other);
	MyNomber operator * (MyNomber other);
	MyNomber operator / (MyNomber other);
	MyNomber operator % (MyNomber other);

	MyNomber GetSquareRoot();
	MyNomber GetPow(int64_t val);
	MyNomber GetModOfPow(MyNomber first, int64_t second, MyNomber third);
	MyNomber GetModOfPow(MyNomber second, MyNomber third);

	std::string ToString();
};
