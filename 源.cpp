#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::sort;
using std::string;
using std::vector;

class Product
{
public:
	Product()
	{
	}
	Product(string a, string b, double c) : label(a), name(b), val(c) {}
	void SetLabel(string a)
	{
		label = a;
	}
	void SetName(string b)
	{
		name = b;
	}
	void SetVal(double c)
	{
		val = c;
	}

	string GetLabel()
	{
		return label;
	}
	string GetName()
	{
		return name;
	}
	double GetVal()
	{
		return val;
	}

private:
	string label, name;
	double val;
};
int lowercmp(Product a, Product b)
{
	double vala = a.GetVal(), valb = b.GetVal();
	return vala < valb;
}

int uppercmp(Product a, Product b)
{
	double vala = a.GetVal(), valb = b.GetVal();
	return vala > valb;
}

int diccmp(Product a, Product b)
{
	string x = a.GetName();
	string y = b.GetName();
	int len = min(x.length(), y.length());
	for (int i = 0; i < len; i++)
	{
		if (x[i] - '0' < y[i] - '0')
			return 1;
		if (x[i] - '0' > y[i] - '0')
			return 0;
	}
	return x.length() <= y.length();
}

class ShoppingCart
{
public:
	ShoppingCart(Product a)
	{
		idx = 0;
		AddProduct(a);
	}

	void AddProduct(Product a)
	{
		member[++idx] = a;
	}
	void LowerSortByVal()
	{
		for (int i = 1; i <= idx; i++)
			for (int j = 1; j <= idx - i; j++)
				if (!lowercmp(member[j], member[j + 1]))
				{
					Product tmp = member[j];
					member[j] = member[j + 1];
					member[j + 1] = tmp;
				}
	}
	void UpperSortByVal()
	{
		for (int i = 1; i <= idx; i++)
			for (int j = 1; j <= idx - i; j++)
				if (!uppercmp(member[j], member[j + 1]))
				{
					Product tmp = member[j];
					member[j] = member[j + 1];
					member[j + 1] = tmp;
				}
	}
	void SortByDic()
	{
		for (int i = 1; i <= idx; i++)
			for (int j = 1; j <= idx - i; j++)
				if (!diccmp(member[j], member[j + 1]))
				{
					Product tmp = member[j];
					member[j] = member[j + 1];
					member[j + 1] = tmp;
				}
	}

	void DisPlay()
	{
		for (int i = 1; i <= idx; i++)
			cout << member[i].GetLabel() << " " << member[i].GetName() << " " << member[i].GetVal() << endl;
	}

private:
	Product member[30];
	int idx;
};

int main()
{
	Product a("a", "aaa", 5), b("b", "aab", 3), c("c", "abb", 4.5);
	ShoppingCart d(a);
	d.AddProduct(b), d.AddProduct(c);
	d.UpperSortByVal();
	d.DisPlay();
	d.LowerSortByVal();
	d.DisPlay();
	d.SortByDic();
	d.DisPlay();
	return 0;
}
