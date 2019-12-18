// Long_arifm_L1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "MyNomber.h"
#include "FreeHK.h"
#include "CryptoAlgo.h"
#include <iostream>

void PrintHelp()
{
	std::cout << std::endl;
	std::cout << "Available options:" << std::endl;
	std::cout << "	+ -> additing" << std::endl;
	std::cout << "	- -> substruction " << std::endl;
	std::cout << "	* -> multiplication" << std::endl;
	std::cout << "	/ -> division" << std::endl;
	std::cout << "	% -> reminder of division" << std::endl;
	std::cout << "	^ -> power" << std::endl;
	std::cout << "	^% -> power`s reminder of division" << std::endl;
	std::cout << "	sqrt -> square root" << std::endl;
	std::cout << "	sys -> solve system" << std::endl;
	std::cout << "	help -> show it again" << std::endl;
}

void MenuL1()
{
	static const std::string sqrt = "sqrt";
	static const std::string sys = "sys";
	static const std::string help = "help";
	static const std::string pres = "res";
	std::cout << "Welcome" << std::endl;
	PrintHelp();
	std::string s = "";
	MyNomber res = MyNomber();
	MyNomber a;
	MyNomber b;
	MyNomber c;
	res = res.GetZero();
	while (true)
	{
		std::cout << ">";
		std::cin >> s;
		if ((s[0] == '^' && s[1] == '%'))
		{
			std::cout << "(a^b)%c=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::string third;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			int b;
			std::cin >> b;
			std::cout << std::endl;
			std::cout << "c=";
			std::cin >> third;
			std::cout << std::endl;
			a = MyNomber(first);
			c = MyNomber(third);

			res = res.GetModOfPow(a, b, c);
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}
		else if ((s[0] == '+'))
		{
			std::cout << "a+b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			std::string second;
			std::cin >> second;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			if (second == pres)
				b = res;
			else
				b = MyNomber(second);
			res = a + b;
			std::cout << a.ToString() << std::endl;
			std::cout << b.ToString() << std::endl;
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s[0] == '-'))
		{
			std::cout << "a-b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			std::string second;
			std::cin >> second;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			if (second == pres)
				b = res;
			else
				b = MyNomber(second);
			res = a - b;
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s[0] == '*'))
		{
			std::cout << "a*b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			std::string second;
			std::cin >> second;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			if (second == pres)
				b = res;
			else
				b = MyNomber(second);
			res = a * b;
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s[0] == '/'))
		{
			std::cout << "a div b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			std::string second;
			std::cin >> second;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			if (second == pres)
				b = res;
			else
				b = MyNomber(second);
			res = a / b;
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s[0] == '%'))
		{
			std::cout << "a mod b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			std::string second;
			std::cin >> second;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			if (second == pres)
				b = res;
			else
				b = MyNomber(second);
			res = a % b;
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s[0] == '^'))
		{
			std::cout << "a^b=Result" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			std::cout << "b=";
			int b;
			std::cin >> b;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			res = a.GetPow(b);
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s == sqrt))
		{
			std::cout << "[a]=Result^2" << std::endl;
			std::cout << "a=";
			std::string first;
			std::cin >> first;
			std::cout << std::endl;
			if (first == pres)
				a = res;
			else
				a = MyNomber(first);
			res = a.GetSquareRoot();
			std::cout << "Rsult=" << res.ToString() << std::endl;
		}

		else if ((s == sys))
		{
			FreeHK freehk = FreeHK();
			freehk.InputValues();

			std::cout << "Result=" << freehk.GetResult().ToString() << std::endl;

		}

		else if ((s == help))
		{
			PrintHelp();
		}

		else
		{
			std::cout << "Unknown input!";
			PrintHelp();
		}
	}
	//std::cout <<res.ToString()<<std::endl;

	FreeHK freehk = FreeHK();
	freehk.InputValues();

	std::cout << freehk.GetResult().ToString() << std::endl;
}

int main()
{
	CryptoAlgo algo = CryptoAlgo();

	std::cout << "a=";
	std::string first;
	std::cin >> first;
	std::cout << std::endl;
	std::cout << "b=";
	std::string second;
	std::cin >> second;

	MyNomber a = MyNomber(first);
	MyNomber b = MyNomber(second);
	std::cout << algo.Solovei(a,b) << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
