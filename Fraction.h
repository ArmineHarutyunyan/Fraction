#pragma once
#include <iostream>

class Fraction
{
	public:
		Fraction() {}
		Fraction(int p, int q); 
		Fraction(const  Fraction& f);
		friend std::ostream& operator<<(std::ostream& os, const Fraction& fr);
		friend std::istream& operator>>(std::istream& is, Fraction& fr);
		Fraction operator=(const Fraction& fr);
		bool operator==(const Fraction& fr);
		bool operator>(const Fraction& fr);
		bool operator<(const Fraction& fr);
		void reduction(Fraction& fr);
		Fraction operator+(const Fraction& fr);
		Fraction operator-(const Fraction& fr);
		Fraction operator*(const Fraction& fr);
		Fraction operator/(const Fraction& fr);
		Fraction operator++();
		Fraction operator++(int);
		void operator+=(const Fraction& fr);
		void operator-=(const Fraction& fr);
		void operator*=(const Fraction& fr);
		void operator/=(const Fraction& fr);
		Fraction operator+(int n);

	private:
		int p;
		int q;
};
