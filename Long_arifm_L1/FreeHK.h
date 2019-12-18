#pragma once
#include "MyNomber.h"
#include <iostream>

class FreeHK
{
private:
	std::vector<MyNomber> b_vec;
	std::vector<MyNomber> m_vec;
	std::vector<MyNomber> MG_vec;
	std::vector<MyNomber> ML_vec;
	int size;

	MyNomber FillMG_vec(); //returns m(0)*m(1)*....*m(size-1)
	void FillML_vec();
public:
	FreeHK();
	void InputValues();
	MyNomber GetResult();
};
