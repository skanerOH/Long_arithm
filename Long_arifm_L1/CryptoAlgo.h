#pragma once
#include "MyNomber.h"

class CryptoAlgo
{
public:
	CryptoAlgo();

	MyNomber Zero;
	MyNomber One;
	MyNomber Two;
	MyNomber Three;

	MyNomber NCD(MyNomber first, MyNomber second);

	int Yakobi(MyNomber first, MyNomber second);

	int Leshandr(MyNomber a, MyNomber b);

	bool Solovei(MyNomber a, MyNomber k);
};
