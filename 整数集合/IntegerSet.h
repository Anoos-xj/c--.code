#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <iostream>
class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(int[], int); // 0~size-1
    ~IntegerSet();
    void insertElement(int);
    void deleteElement(int);
    bool validEntry(int);
    void printSet();
    IntegerSet &unionOfSets(IntegerSet, IntegerSet);
    IntegerSet &intersectionOfSets(IntegerSet, IntegerSet);
    bool isEqualTo(IntegerSet, IntegerSet);

private:
    int set[101];
};

#endif // INTEGERSET_H