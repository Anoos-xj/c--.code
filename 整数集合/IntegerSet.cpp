#include "IntegerSet.h"

using std::cout;
using std::endl;

IntegerSet::IntegerSet()
{
    for (int i = 0; i < 101; i++)
    {
        set[i] = 0;
    }
}

IntegerSet::IntegerSet(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        set[arr[i]] = 1;
    }
}

IntegerSet::~IntegerSet()
{
}

IntegerSet &IntegerSet::unionOfSets(IntegerSet s1, IntegerSet s2)
{
    for (int i = 0; i < 101; i++)
    {
        if (s1.set[i] == 1 || s2.set[i] == 1)
        {
            set[i] = 1;
        }
        else
        {
            set[i] = 0;
        }
    }
    return *this;
}

IntegerSet &IntegerSet::intersectionOfSets(IntegerSet s1, IntegerSet s2)
{
    for (int i = 0; i < 101; i++)
    {
        if (s1.set[i] == 1 && s2.set[i] == 1)
        {
            set[i] = 1;
        }
        else
        {
            set[i] = 0;
        }
    }
    return *this;
}

bool IntegerSet::validEntry(int x)
{
    if (x < 0 || x > 100)
    {
        cout << "Invalid Entry" << endl;
        exit(0);
    }
    if (set[x] == 0)
    {
        cout << "element not in set" << endl;
        return false;
    }
        
    else
        return true;
}

void IntegerSet::insertElement(int x)
{
    if (validEntry(x))
        cout << "element already in set" << endl;
    else
        set[x] = 1;
}

void IntegerSet::deleteElement(int x)
{
    if (validEntry(x))
        set[x] = 0;
    else
        cout << "element not in set" << endl;
}

void IntegerSet::printSet()
{
    for (int i = 0; i < 101; i++)
    {
        if (set[i] == 1)
            cout << i << " ";
    }
    cout << endl;
}

bool IntegerSet::isEqualTo(IntegerSet s1, IntegerSet s2)
{
    for (int i = 0; i < 101; i++)
    {
        if (s1.set[i] != s2.set[i])
            return false;
    }
    return true;
}