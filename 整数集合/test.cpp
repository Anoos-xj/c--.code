#include "IntegerSet.h"

using std::cout;
using std::endl;

int main()
{
    cout << "hello world" << endl;
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    IntegerSet s1(arr1, 5);
    IntegerSet s2(arr2, 5);
    IntegerSet s3;
    s3.unionOfSets(s1, s2);
    s3.printSet();
    s3.intersectionOfSets(s1, s2);
    s3.printSet();

    s1.insertElement(11);
    s1.printSet();
    s1.deleteElement(11);
    s1.printSet();

    if (s3.isEqualTo(s1, s2))
    {
        cout << "s1 is equal to s2" << endl;
    }
    else
    {
        cout << "s1 is not equal to s2" << endl;
    }

    return 0;
}