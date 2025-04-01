#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }
    Complex operator+(const Complex &c)
    {
        real = real + c.real;
        imag = imag + c.imag;
        return *this;
    }

    Complex operator-(const Complex &c)
    {
        real = real - c.real;
        imag = imag - c.imag;
        return *this;
    }

    Complex operator*(const Complex &c)
    {
        real = real * c.real - imag * c.imag;
        imag = real * c.imag + imag * c.real;
        return *this;
    }

    Complex operator/(const Complex &c)
    {
        real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
        return *this;
    }

    Complex operator=(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << "(" << c.real << "," << c.imag << ")";
        return os;
    }

private:
    double real, imag;
};

int
main()
{
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;
    cout << c3 << " " << c4 << " " << c5 << " " << c6 << endl;
    return 0;
}