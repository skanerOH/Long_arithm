#include "FreeHK.h"

FreeHK::FreeHK()
{

}

void FreeHK::InputValues()
{
	std::cout << "Set count of parts:" << std::endl;
	std::cin >> size;
	for (int i = 0; i < size; ++i)
	{

		std::string s = "";
		std::cout << "x mod m(" << i << ")" << "= b(" << i << ")" << std::endl;

		std::cout << "m("<<i<<")=?" << std::endl;
		std::cin >> s;
		m_vec.push_back(MyNomber(s));

		std::cout << "b("<<i<<")=?" << std::endl;
		std::cin >> s;
		b_vec.push_back(MyNomber(s));
	}
}

MyNomber FreeHK::FillMG_vec()
{
	MyNomber multed_m_vec = multed_m_vec.GetOne();
	for (int i = 0; i < size; ++i)
	{
		multed_m_vec = multed_m_vec * m_vec[i];
	}

	for (int i = 0; i < size; ++i)
	{
		MG_vec.push_back((multed_m_vec / m_vec[i]));
	}
	return multed_m_vec;
}

void FreeHK::FillML_vec()
{
	MyNomber tempo;
	for (int i = 0; i < size; ++i)
	{
		tempo = tempo.GetOne();
		while (!((tempo*MG_vec[i]) % m_vec[i] == tempo.GetOne()))
		{
			tempo = tempo + tempo.GetOne();
		}
		ML_vec.push_back(tempo);
	}
}

MyNomber FreeHK::GetResult()
{
	MyNomber multed_m_vector = FillMG_vec();
	FillML_vec();

	MyNomber x0 = x0.GetZero();
	for (int i = 0; i < size; ++i)
	{
		x0 = x0 + (b_vec[i] * (MG_vec[i] * ML_vec[i]));
	}

	return (x0 % multed_m_vector);
}