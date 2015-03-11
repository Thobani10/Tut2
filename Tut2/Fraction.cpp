//THOBANI MABASO(212535063)


#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;
int gcd(int, int);

class fraction
{
	friend fraction operator+(fraction, fraction);
	friend fraction operator-(fraction, fraction);
	friend fraction operator*(fraction, fraction);
	friend fraction operator/(fraction, fraction);
	friend ostream &operator<<(ostream&, const fraction &);
	friend istream &operator>>(istream&, fraction &);
public:
	fraction();
	int num;
	int den;
private:
};

fraction::fraction()
{
	num = den = 0;
}

// Overloading Addition 
fraction operator+(fraction  f1, fraction f2)
{
	fraction temp;
	if (f1.den == f2.den)
	{
		temp.num = f1.num + f2.num;
		temp.den = f1.den;
	}
	else if (f1.den != f2.den)
	{
		temp.num = (f1.num*f2.den) + (f2.num*f1.den);
		temp.den = f1.den*f2.den;
	}
	return temp;
}

//Overloading subraction 
fraction operator-(fraction  f1, fraction f2)
{
	fraction temp;
	if (f1.den == f2.den)
	{
		temp.num = f1.num - f2.num;
		temp.den = f1.den;
	}
	else if (f1.den != f2.den)
	{
		temp.num = (f1.num*f2.den) - (f2.num*f1.den);
		temp.den = f1.den*f2.den;
	}
	return temp;
}

//OverLoading multiplication 
fraction operator*(fraction  f1, fraction f2)
{
	fraction temp;
	temp.num = f1.num * f2.num;
	temp.den = f1.den * f2.den;
	return temp;
}

//Overloading Division 
fraction operator/(fraction  f1, fraction f2)
{
	fraction temp;
	temp.num = f1.num * f2.den;
	temp.den = f1.den * f2.num;
	return temp;
}


ostream &operator<< (ostream &output, const fraction &frac)
{
	int x = gcd(frac.num, frac.den);
	output << frac.num / x << "/" << frac.den / x << endl;
	return output;
}

istream &operator>>(istream &input, fraction &frac)
{
	input >> setw(1) >> frac.num;
	input.ignore();
	input >> setw(1) >> frac.den;
	return input;
}

int main()
{
	fraction t1, t2, tA, tS, tM, tD;


	cout << "Enter fraction1 in the form of a/b :\n";
	cin >> t1;

	cout << "Enter fraction2 in the form of a/b :\n";
	cin >> t2;

	cout << "\nAddition:\n";
	tA = t1 + t2;
	cout << tA << endl;
	cout << "Subtraction:\n";
	tS = t1 - t2;
	cout << tS << endl;

	cout << "Multiplication:\n";
	tM = t1 * t2;
	cout << tM << endl;

	cout << "Division\n";
	tD = t1 / t2;
	cout << tD << endl;
	system("pause");
	return 0;
}

int gcd(int x, int y)
{
	int c = x % y;
	while (c != 0)
	{
		x = y;
		y = c;
		c = x % y;
	}
	system("pause");
	return y;
}

