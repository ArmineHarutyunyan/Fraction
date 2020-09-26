#include "Fraction.h"


Fraction::Fraction(int p_, int q_) : p(p_), q(q_) {}

Fraction::Fraction(const  Fraction& f) : p(f.p), q(f.q) {}

std::ostream& operator<<(std::ostream& os, const Fraction& fr)
{
	os << fr.p << "/" << fr.q << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fr)
{
	is >> fr.p >> fr.q;
	return is;
}


Fraction Fraction::operator=(const Fraction& fr)
{
	p = fr.p;
	q = fr.q;
	return *this;
}

bool Fraction::operator==(const Fraction& fr)
{
	return p * fr.q == q * fr.p;
}

bool Fraction::operator>(const Fraction& fr)
{
	return p * fr.q > q * fr.p;
}

bool Fraction::operator<(const Fraction& fr)
{
	return p * fr.q < q * fr.p;
}

void Fraction::reduction(Fraction& fr)
{
	int divider = std::min(fr.p, fr.q);
	for(; divider > 1; --divider)
	{
		if(fr.p % divider == 0 && fr.q % divider == 0)
		{
			fr.p /= divider;
			fr.q /= divider;
		}
	}
}

Fraction Fraction::operator+(int num)
{
	Fraction result(p + q * num, q);
	reduction(result);
	return result;
}

Fraction Fraction::operator+(const Fraction& fr)
{
	Fraction sum;
	sum.q = q * fr.q;
	sum.p = p * fr.q + q * fr.p;
	reduction(sum);
	return sum;
}

Fraction Fraction::operator-(const Fraction& fr)
{
	Fraction result;
	result.q = q * fr.q;
	result.p = p * fr.q - q * fr.p;
	reduction(result);
	return result;
}

Fraction Fraction::operator*(const Fraction& fr)
{
	Fraction result;
	result.p = p * fr.p;
	result.q = q * fr.q;
	reduction(result);
	return result;
}

Fraction Fraction::operator/(const Fraction& fr)
{
	Fraction result;
	result.q = q * fr.p;
	result.p = p * fr.q;
	reduction(result);
	return result;
}

Fraction Fraction::operator++()
{
    p += q;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction result(*this);
    p += q;
	return result;
}

void Fraction::operator+=(const Fraction& fr)
{
	if(q == fr.q)
		p += fr.p;
	else
	{
		p = (p * fr.q + q * fr.p);
		q *= fr.q;
	}
	reduction(*this);
}

void Fraction::operator-=(const Fraction& fr)
{
	if(q == fr.q)
		p -= fr.p;
	else
	{
		p = (p * fr.q - q * fr.p);
        q *= fr.q;
    }
    reduction(*this);
}

void Fraction::operator*=(const Fraction& fr)
{
	p *= fr.p;
	q *= fr.q;
	reduction(*this);
}

void Fraction::operator/=(const Fraction& fr)
{
	q *= fr.p;
	p *= fr.q;
	reduction(*this);
}
