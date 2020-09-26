#include "Fraction.h"


int main()
{
	Fraction f1(5, 6);
	std::cout << f1;
	Fraction f2;
	std::cin >> f2;
	f2 *= f1;
	std::cout << f2;
}
