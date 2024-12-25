#include <cstring>
#include <iostream>

using std::cout;
using std::string;

class test
{
public:
    test(string a) : name(a) {}
    void settest(string a)
    {
        name = a;
    }
    string gettest()
    {
        return name;
    }

private:
    string name;
};

int main()
{
    string b;
    string a = "anoos.xj";
    test t(a);
    b = t.gettest();
    cout << b;
}