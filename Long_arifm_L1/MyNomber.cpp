#include "MyNomber.h"
#include <iostream>

MyNomber::MyNomber()
{
	isPositive = true;
}

MyNomber::MyNomber(int t)
{
	if (t < 0)
	{
		this->isPositive = false;
		t = -t;
		this->value.push_back(t);
		t = t / this->base;
		if (t != 0)
			this->value.push_back(t);
	}
	else
	{
		this->isPositive = true;
		this->value.push_back(t);
		t = t / this->base;
		if (t != 0)
			this->value.push_back(t);
	}
}

MyNomber::MyNomber(std::vector<int64_t> t_value, bool t_isPositive)
{
	std::vector <int64_t> value =t_value;
	isPositive = t_isPositive;
}

MyNomber::MyNomber(std::string t)
{
	try {
		int i = t.length() - 1;
		int64_t c = 0;
		int counter = 0;
		while (i >= 0 && t[i] != '-' && t[i] != '+')
		{
			c = c + (static_cast<int32_t>(t[i] - '0'))*pow(10, counter);
			counter++;
			if (counter == 8)
			{
				this->value.push_back(c);
				c = 0;
				counter = 0;
			}
			--i;
		}
		if (c != 0)
			this->value.push_back(c);
		this->isPositive = true;
		if (i == 0)
		{
			if (t[i] == '-') this->isPositive = false;
			else if (t[i] == '+') this->isPositive = true;
			else throw("unknown symbol");
		}
	}
	catch (std::string a)
	{
		std::cout << "Input error:" << a << std::endl;
	}
}


MyNomber MyNomber::Mod()
{
	MyNomber res = MyNomber(*this);
	res.isPositive = true;
	return res;
}

MyNomber MyNomber::ToNeg()
{
	this->isPositive = !(this->isPositive);
	return (*this);
}

MyNomber MyNomber::GetZero()
{
	MyNomber res = MyNomber();
	res.value.push_back(0);
	return res;
}

MyNomber MyNomber::GetOne()
{
	MyNomber res = MyNomber();
	res.value.push_back(1);
	return res;
}

MyNomber MyNomber::Plus(MyNomber first, MyNomber second)
{
	int64_t tempo_sum = 0;
	int64_t transfer_val = 0;
	int min_size = 0;

	if (first.value.size() < second.value.size())
	{
		min_size = first.value.size();
	}
	else
	{
		min_size = second.value.size();
	}

	MyNomber res;

	for (int i = 0; i < min_size; ++i)
	{
		tempo_sum = first.value[i] + second.value[i] + transfer_val;
		transfer_val = tempo_sum / first.base;

		res.value.push_back((tempo_sum % first.base));
	}

	if (first.value.size() < second.value.size())
	{
		for (int i = min_size; i < second.value.size(); ++i)
		{
			res.value.push_back(second.value[i] + transfer_val);
			transfer_val = 0;
		}
	}
	else
	{
		if (first.value.size() == second.value.size())
		{
			if (transfer_val == 1) res.value.push_back(transfer_val);
		}
		else
		{
			for (int i = min_size; i < first.value.size(); ++i)
			{
				res.value.push_back(first.value[i] + transfer_val);
				transfer_val = 0;
			}
		}
	}

	return res;
}

MyNomber MyNomber::Minus(MyNomber higher, MyNomber lower)
{
	MyNomber res;
	for (int i = 0; i < lower.value.size(); ++i)
	{
		if (higher.value[i] - lower.value[i] >= 0)
		{
			res.value.push_back(higher.value[i] - lower.value[i]);
		}
		else
		{
			higher.value[i + 1]--;
			res.value.push_back(higher.base + higher.value[i] - lower.value[i]);
		}
	}
	for (int i = lower.value.size(); i < higher.value.size(); i++)
	{
		res.value.push_back(higher.value[i]);
	}
	while (res.value[res.value.size() - 1] == 0 && res.value.size()>1)
	{
		res.value.pop_back();
	}
	return res;
}

int MyNomber::CompareTwo(MyNomber first, MyNomber second)
{
	if (first.isPositive > second.isPositive) return 1;
	if (first.isPositive < second.isPositive) return -1;

	if (first.isPositive)
	{
		if (first.value.size() > second.value.size()) return 1;
		if (first.value.size() < second.value.size()) return -1;

		for (int i = first.value.size() - 1; i >= 0; --i)
		{
			if (first.value[i] > second.value[i]) return 1;
			if (first.value[i] < second.value[i]) return -1;
		}

		return 0;
	}
	else
	{
		if (first.value.size() > second.value.size()) return -1;
		if (first.value.size() < second.value.size()) return 1;

		for (int i = first.value.size() - 1; i >= 0; --i)
		{
			if (first.value[i] > second.value[i]) return -1;
			if (first.value[i] < second.value[i]) return 1;
		}

		return 0;
	}
}

MyNomber MyNomber::Mult(MyNomber first, MyNomber second)
{
	MyNomber res = MyNomber();
	for (int i = 0; i < (first.value.size() + second.value.size()+1); ++i)
	{
		res.value.push_back(0);
	}
	int64_t tempo = 0;

	for (int i = 0; i < first.value.size(); ++i)
	{
		for (int j = 0; j < second.value.size(); ++j)
		{
			tempo = (res.value[i + j] + first.value[i] * second.value[j]);
			res.value[i + j + 1] += tempo / first.base;
			res.value[i + j] = tempo % first.base;
		}
	}


	while (res.value.size()>1 && res.value[res.value.size() - 1] == 0)
		res.value.pop_back();


	return res;
}

MyNomber MyNomber::Mult(MyNomber first, int32_t second)
{
	//second>0!!!
	MyNomber res = MyNomber();
	for (int i = 0; i < (first.value.size() + 2); ++i)
	{
		res.value.push_back(0);
	}
	int64_t tempo = 0;

	for (int i = 0; i < first.value.size(); ++i)
	{
		tempo = (res.value[i] + first.value[i] * second);
		res.value[i + 1] += tempo / first.base;
		res.value[i] = tempo % first.base;
	}


	while (res.value.size() > 0 && res.value[res.value.size() - 1] == 0)
		res.value.pop_back();


	return res;
}

int64_t MyNomber::DivOneIter(MyNomber first, MyNomber second, MyNomber& ost)
{
	uint32_t Up = first.base;
	uint32_t Down = 0;

	while (Up - Down > 1)
	{
		ost = Mult(second, (Up + Down) / 2);
		if (CompareTwo(first, ost) < 0)
			Up = (Up + Down) / 2;
		else Down = (Up + Down) / 2;
	}

	ost = Mult(second, (Up + Down) / 2);
	ost = Minus(first, ost);

	return Down;
}

MyNomber MyNomber::Div(MyNomber first, MyNomber second)
{
	MyNomber res = MyNomber();
	MyNomber tempo = MyNomber();
	MyNomber ost = MyNomber();

	int i = first.value.size();
	int nullCounter = 0;

	while (i > 0)
	{
		while (CompareTwo(tempo, second) < 0 && i > 0)
		{
			i--;
			nullCounter++;
			tempo.value.insert(tempo.value.begin(), first.value[i]);
		}
		for (int j=1;j<nullCounter; j++)
			res.value.insert(res.value.begin(), 0);
		nullCounter = 0;
		res.value.insert(res.value.begin(), DivOneIter(tempo, second, ost));
		while (ost.value.size() > 0 && ost.value[ost.value.size() - 1] == 0)
			ost.value.pop_back();
		tempo = ost;
	}
	
	while (res.value[res.value.size() - 1] == 0 && res.value.size() > 1)
	{
		res.value.pop_back();
	}

	return res;
}

MyNomber MyNomber::Ost(MyNomber first, MyNomber second)
{
	MyNomber res = MyNomber();
	MyNomber tempo = MyNomber();
	MyNomber ost = MyNomber();

	int i = first.value.size();
	int nullCounter = 0;

	while (i > 0)
	{
		while (CompareTwo(tempo, second) < 0 && i > 0)
		{
			i--;
			nullCounter++;
			tempo.value.insert(tempo.value.begin(), first.value[i]);
		}
		for (int j = 1; j < nullCounter; j++)
			res.value.insert(res.value.begin(), 0);
		nullCounter = 0;
		res.value.insert(res.value.begin(), DivOneIter(tempo, second, ost));
		while (ost.value.size() > 0 && ost.value[ost.value.size() - 1] == 0)
			ost.value.pop_back();
		tempo = ost;
	}

	while (res.value[res.value.size() - 1] == 0 && res.value.size() > 1)
	{
		res.value.pop_back();
	}

	if (ost.value.size() == 0)
		ost.value.push_back(0);

	return ost;
}

MyNomber MyNomber::SqRoot(MyNomber first)
{
	MyNomber res = MyNomber();
	for (int i = 0; i < (first.value.size() / 2 + 1); ++i)
		res.value.push_back(0);
	for (int i = res.value.size() - 1; i >= 0; --i)
	{
		int64_t Up = first.base;
		int64_t Down = 0;
		while (Up - Down > 1)
		{
			res.value[i] = (Up + Down) / 2;
			if (CompareTwo(first, Mult(res, res)) < 0)
				Up = (Up + Down) / 2;
			else Down= (Up + Down) / 2;
		}
		res.value[i] = (Up + Down) / 2;
	}

	while (res.value[res.value.size() - 1] == 0 && res.value.size() > 1)
	{
		res.value.pop_back();
	}

	return res;
}

MyNomber MyNomber::operator + (MyNomber other)
{
	if (this->isPositive && other.isPositive)
	{
		return Plus(*this, other);
	}
	if (this->isPositive && !other.isPositive)
	{
		if (CompareTwo((*this), other.Mod()) > 0)
		{
			return (Minus(*this, other.Mod()));
		}
		else
		{
			return (Minus(other.Mod(), (*this)).ToNeg());
		}
	}
	if (!this->isPositive && other.isPositive)
	{
		if (CompareTwo((*this), other.Mod()) > 0)
		{
			return (Minus((*this).Mod(), other.Mod())).ToNeg();
		}
		else
		{
			return (Minus(other, (*this).Mod()));
		}
	}
	if (!this->isPositive && !other.isPositive)
	{
		return (Plus(*this, other).ToNeg());
	}
	return MyNomber();
}

bool MyNomber::operator > (MyNomber other)
{
	if (CompareTwo(*this, other) > 0)
		return true;
	return false;
}

bool MyNomber::operator < (MyNomber other)
{
	if (CompareTwo(*this, other) < 0)
		return true;
	return false;
}

bool MyNomber::operator == (MyNomber other)
{
	if (CompareTwo(*this, other) == 0)
		return true;
	return false;
}

MyNomber MyNomber::operator = (MyNomber other)
{
	this->value = other.value;
	this->isPositive = other.isPositive;
	return *this;
}

std::string MyNomber::ToString()
{
	std::string res = "";
	std::string s = "";
	for (int i = 0; i < this->value.size(); ++i)
	{
		s = std::to_string(this->value[i]);
		while (s.length() < 8)
			s = "0" + s;
		res = s+','+ res;
	}
	res.erase(res.length()-1, 1);

	if (!(this->isPositive))
		res = "-" + res;

	return res;
}

MyNomber MyNomber::operator - (MyNomber other)
{
	if (this->isPositive && other.isPositive)
	{
		if (CompareTwo(*this, other) > 0)
		{
			return Minus(*this, other);
		}
		else if (CompareTwo(*this, other)<0)
		{
			return (Minus(other, *this)).ToNeg();
		}
		else
		{
			return GetZero();
		}
	}

	if (this->isPositive && !other.isPositive)
	{
		return Plus(*this, other.ToNeg());
	}

	if (!this->isPositive && other.isPositive)
	{
		return (Plus((*this).ToNeg(), other)).ToNeg();
	}

	if (!this->isPositive && !other.isPositive)
	{
		if (CompareTwo(other, *this) > 0)
		{
			return (Minus(*this, other)).ToNeg();
		}
		else if (CompareTwo(other, *this) < 0)
		{
			return (Minus(other, *this));
		}
		else
		{
			return GetZero();
		}
	}
}

MyNomber MyNomber::operator * (MyNomber other)
{
	if (this->isPositive == other.isPositive)
	{
		return Mult(*this, other);
	}
	else
	{
		return (Mult(*this, other)).ToNeg();
	}
}

MyNomber MyNomber::operator / (MyNomber other)
{
	if (other == GetZero())
	{
		std::cout << "0 Dividing(((((((((" << std::endl;
		return GetOne().ToNeg();
	}
	if (CompareTwo(Mod(),other.Mod())<0)
		return GetZero();
	if (CompareTwo(Mod(), other.Mod()) == 0 && this->isPositive == other.isPositive)
		return GetOne();
	if (CompareTwo(Mod(), other.Mod()) == 0 && this->isPositive != other.isPositive)
		return (GetOne()).ToNeg();
	if (this->isPositive==other.isPositive)
		return Div((*this).Mod(), other.Mod());
	else return Div((*this).Mod(), other.Mod()).ToNeg();
}

MyNomber MyNomber::operator % (MyNomber other)
{
	if (other == GetZero())
	{
		std::cout << "0 Dividing(((((((((" << std::endl;
		return GetOne().ToNeg();
	}
	if (other < GetZero())
	{
		std::cout << "???";
		return GetOne().ToNeg();
	}
	if (CompareTwo((*this).Mod(), other.Mod())<0)
	{
		if (this->isPositive)
			return (*this);
		else
		{
			return (Minus(other, (*this).Mod()));
		}
	}
	if (this->isPositive)
	{
		return Ost(*this, other);
	}
	else
	{
		MyNomber res=(Minus(other, Ost(*this, other)));
		if (CompareTwo(res, other) == 0) return (GetZero());
		else return res;
	}
}

MyNomber MyNomber::GetSquareRoot()
{
	if (CompareTwo((*this), GetZero()) < 0)
	{
		std::cout << "Unexpected: sqrt of negative value(((";
		return GetOne().ToNeg();
	}
	return SqRoot(*this);
}

MyNomber MyNomber::GetPow(int64_t val)
{
	MyNomber res = GetOne();
	MyNomber tempo = (*this);

	if (val == 0) return GetOne();

	int t = val;
	while (t > 0)
	{
		if (t%2==1) res = Mult(res, tempo);
		tempo = Mult(tempo, tempo);
		t /= 2;
	}

	if (val % 2 == 1 && !(this->isPositive))
		return res.ToNeg();
	return res;
}

MyNomber MyNomber::GetModOfPow(MyNomber first, int64_t second, MyNomber third)
{
	MyNomber res = GetOne();
	MyNomber tempo = first;

	if (second == 0) return GetOne();

	int t = second;
	while (t > 0)
	{
		if (t % 2 == 1) res = Ost(Mult(res, Ost(tempo, third)), third);
		tempo = Mult(Ost(tempo, third), Ost(tempo, third));
		t /= 2;
	}

	return Ost(res,third);
}

MyNomber MyNomber::GetModOfPow(MyNomber second, MyNomber third)
{
	MyNomber zero = this->GetZero();
	MyNomber res = GetOne();
	MyNomber tempo = (*this);

	if (second == 0) return GetOne();

	MyNomber t = second;
	MyNomber two = MyNomber("2");
	MyNomber one = this->GetOne();
	while (t > zero)
	{
		if ((t % two) == one) res = Ost(Mult(res, Ost(tempo, third)), third);
		tempo = Mult(Ost(tempo, third), Ost(tempo, third));
		t =t/two;
	}

	return Ost(res, third);
}

bool MyNomber::IsEven()
{
	if (this->value[0] % 2 == 0)
		return true;
	else return false;
}

