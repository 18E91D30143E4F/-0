#include <iostream>
#include <cstdint>
#include <string>

std::string ConvertToNumeralSystem(int Number, int P)
{
	std::string res = "";

	if (P > 1 && P < 10)
	{
		do
		{
			res = std::to_string(Number % P) + res;
			Number /= P;
		} while (Number > 0);
	}
	else
	{
		res = "Основание системы счисления p должно быть больше 1 и меньше 10.";
	}
	return res;
}

std::string ConvertToNumeralSystemRec(int Number, int P, std::string Result)
{
	if (!(P > 1 && P < 10))
	{
		return "Основание системы счисления p должно быть больше 1 и меньше 10.";
	}

	Result = std::to_string(Number % P) + Result;
	Number /= P;
	if (Number <= 0)
	{
		return Result;
	}
	else
	{
		return ConvertToNumeralSystemRec(Number, P, Result);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int Number;
	int P;

	std::cout << "Введите число:" << std::endl;
	std::cin >> Number;
	std::cout << "Введите систему счисления" << std::endl;
	std::cin >> P;

	std::cout << "Итерационная функция: " << Number << "(10) -> " << ConvertToNumeralSystem(Number, P) << "(" + std::to_string(P) + ")" << std::endl;
	std::cout << "Рекурсивная функция: " << Number << "(10) -> " << ConvertToNumeralSystemRec(Number, P, "") << "(" + std::to_string(P) + ")" << std::endl;

	system("pause");

	return 0;
}