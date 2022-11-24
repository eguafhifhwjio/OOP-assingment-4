// All concepts
#include <iostream>
using namespace std;
// Class,Objects,Constructor and Destructor
class Demo
{
private:
    int x;

public:
    Demo()
    {
        x = 0;
        cout << "\nConstructor called!";
    }
    void get()
    {
        cout << "\nEnter value :";
        cin >> x;
    }
    void put()
    {
        cout << "\nValue at Object: " << x;
    }
    ~Demo()
    {
        cout << "\nDestructor called!";
    }
};
// Operator overloading
class Operator
{
private:
    int x;

public:
    void get()
    {
        cout << "\nEnter value :";
        cin >> x;
    }
    Operator operator+(Operator &o)
    {
        Operator temp;
        temp.x = x + o.x;
        return temp;
    }
    void put()
    {
        cout << "\nValue: " << x;
    }
};
// Function Overloading
void fun(int a)
{
    cout << "\nThis is function with one parameter : " << a;
}
void fun(int a, int b)
{
    cout << "\nThis is function with two parameters : " << a << " " << b;
}
// Friend functions
class Friend
{
private:
    int x;

public:
    void get()
    {
        cout << "\nEnter value :";
        cin >> x;
    }
    void put()
    {
        cout << "\nValue: " << x;
    }
    friend void swap(Friend &a, Friend &b);
};
void swap(Friend &a, Friend &b)
{
    int t;
    t = a.x;
    a.x = b.x;
    b.x = t;
}
// Inheritance,Virtual Base Class & Virtual Function
class Base
{
protected:
    int x;

public:
    Base()
    {
        x = 5;
    }
    virtual void put() = 0;
};
class A : virtual public Base
{
protected:
    int a;

public:
    void get()
    {
        cout << "\nEnter value :";
        cin >> a;
    }
    void put()
    {
        cout << "\nAdded Value at Object: " << (a + x);
    }
};
class B : virtual public Base
{
protected:
    int b;

public:
    void get()
    {
        cout << "\nEnter value :";
        cin >> b;
    }
    void put()
    {
        cout << "\nAdded Value at Object: " << (b + x);
    }
};
class C : public A, public B
{
protected:
    int c;

public:
    void get()
    {
        cout << "\nEnter three values :";
        cin >> a >> b >> c;
    }
    void put()
    {
        cout << "\nAdded Value at Object: " << (a + b + c + x);
    }
};
// Template Class
template <class T>
class Template
{
private:
    T a, b;

public:
    void get()
    {
        cout << "\nEnter two values :";
        cin >> a >> b;
    }
    void put()
    {
        cout << "\nAdded Value : " << (a + b);
    }
};
// Exception Handling
void division()
{
    int a, b;
    cout << "\nEnter numerator :";
    cin >> a;
    cout << "\nEnter denominator :";
    cin >> b;
    try
    {
        if (b == 0)
            throw 'A';
        else
            cout << "\nResult of division: " << (a / b);
    }
    catch (char k)
    {
        cout << "\nError!...Divisioon not possible if denominator is 0";
    }
}
// Main
int main()
{
    int c, x;
    while (1)
    {
        cout << "\n\n********** MENU **********\n\n";
        cout << "\n1.To demonstrate class,objects,constructors and destructors";
        cout << "\n2.To add data of two objects using operator overloading";
        cout << "\n3.To demonstrate function overloading";
        cout << "\n4.To swap private data of two objects using friend function";
        cout << "\n5.To demonstrate inheritance,virtual base class,virtual functions";
        cout << "\n6.To add two integer and float variables using twemplate class";
        cout << "\n7.To carry out division of integers using exception handling";
        cout << "\n8.Exit";
        cout << "\n\nEnter choice: ";
        cin >> c;
        if (c == 1)
        {
            Demo obj;
            obj.get();
            obj.put();
        }
        else if (c == 2)
        {
            Operator o1, o2, o3;
            cout << "\nData of Object 1:";
            o1.get();
            cout << "\nData of Object 2:";
            o2.get();
            o3 = o1 + o2;
            cout << "\nData in Object 3:";
            o3.put();
        }
        else if (c == 3)
        {
            fun(4);
            fun(3, 5);
        }
        else if (c == 4)
        {
            Friend f1, f2;
            cout << "\nObject 1:";
            f1.get();
            cout << "\nObject 2:";
            f2.get();
            swap(f1, f2);
            cout << "\nAfter swaping:";
            cout << "\nObject 1:";
            f1.put();
            cout << "\nObject 2:";
            f2.put();
        }
        else if (c == 5)
        {
            A a1;
            B b1;
            C c1;
            cout << "\nObject of A:";
            a1.get();
            a1.put();
            cout << "\nObject of B:";
            b1.get();
            b1.put();
            cout << "\nObject of C:";
            c1.get();
            c1.put();
        }
        else if (c == 6)
        {
            Template<int> t1;
            Template<float> fl1;
            cout << "\nInteger Variables:";
            t1.get();
            t1.put();
            cout << "\nFloat Variables:";
            fl1.get();
            fl1.put();
        }
        else if (c == 7)
        {
            division();
        }
        else if (c == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\nWrong Choice!";
        }
    }
    return 0;
}
