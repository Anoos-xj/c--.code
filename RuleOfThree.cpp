#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    char *name;

public:
    // 构造函数：分配内存
    Student(const char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // 析构函数：释放内存
    ~Student() { delete[] name; }

    // 拷贝构造函数：深拷贝
    Student(const Student &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // 拷贝赋值运算符：释放旧内存 + 深拷贝
    Student &operator=(const Student &other)
    {
        if (this != &other)
        {                  // 防止自赋值
            delete[] name; // 释放旧资源
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }
};

int main()
{
    Student s1("Alice");
    Student s2 = s1; // 拷贝构造函数
    Student s3("Bob");
    s3 = s1; // 拷贝赋值运算符
    return 0;
}