#include "CryptoAlgo.h"
#include <iostream>

CryptoAlgo::CryptoAlgo()
{
	MyNomber t = MyNomber("2");
	Two = t;
	One = t.GetOne();
	Zero = t.GetZero();
	MyNomber k = MyNomber("3");
	Three = k;
}

MyNomber CryptoAlgo::NCD(MyNomber first, MyNomber second)
{
	while (!(first==second))
	{
		if (first == first.GetZero())
		{
			return second;
		}
		else if (second == second.GetZero())
		{
			return first;
		}
		else if (first > second)
		{
			first = first % second;
		}
		else
		{
			second = second % first;
		}
	}
	return first;
}

int CryptoAlgo::Yakobi(MyNomber a, MyNomber b)
{
	MyNomber Five = MyNomber("5");
	MyNomber Four = MyNomber("4");
	MyNomber Eight = MyNomber("8");
	if (!(NCD(a, b) == One))
		return 0;

	int r = 1;

	if (a < Zero)
	{
		a = a.ToNeg();
		if ((b%Four) == Three)
		{
			r = -r;
		}
	}
	while (!(a == Zero))
	{
		int t = 0;
		while (a.IsEven())
		{
			t++;
			a = a / Two;
		}
		if (t %2==1)
		{
			if ((b%Eight) == Three || (b%Eight) == Five)
			{
				r = -r;
			}
		}

		if ((a%Four) == Three && (b%Four) == Three)
		{
			r = -r;
		}
		MyNomber c = MyNomber();
		c = a;
		a = b % c;
		b = c;
	}
	if (b == One)
		return r;
	return 0;
}

int CryptoAlgo::Leshandr(MyNomber a, MyNomber b)
{
	return Yakobi(a, b);
}

bool CryptoAlgo::Solovei(MyNomber a, MyNomber k)
{
	a = a.Mod();
	if (a < Three)
		return false;
	else if (a.IsEven())
		return true;

	MyNomber nm1 = a - One;
	MyNomber nm12 = nm1 / Two;
	if (k < Zero)
		k.ToNeg();
	if (k > nm1)
		k = nm1;

	for (MyNomber t = Two; t < k || t==k; t=t+One) {
		int j = Yakobi(t, a);
		MyNomber powmod = t.GetModOfPow(nm12, a);
		MyNomber other = NCD(a, t);
		std::cout << j << "  " <<other.ToString()<<"  "<<powmod.ToString()<< std::endl;
		if (NCD(a,t)>One || !(MyNomber(j) == t.GetModOfPow(nm12, a))) 
		{
			return true;
		}
	}

	return false;
}