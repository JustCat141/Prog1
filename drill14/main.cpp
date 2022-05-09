#include "std_lib_facilities.h"

class B1{
public:
    virtual void vf()
    {
        cout << "B1::fv()" << endl;
    }    
    void f()
    {
        cout << "B1::f()" << endl;
    } 
    virtual void pvf()
    {
        cout << "B1::pvf()" << endl;
    }
};

class D1 : public B1{
public:
    virtual void vf() override
    {
        cout << "D1::fv()" << endl;
    }    
    void f()
    {
        cout << "D1::f()" << endl;
    }
};

class D2 : public D1
{
    public:
    void pvf() override
    {
        cout << "D2:pvf()" << endl;
    }
};

class B2
{
    public:
    virtual void pvf()
    {
        cout << "B2:pvf()" << endl;
    }
};

class D21 : public B2
{
    public:
    string asd = "help";
    void pvf() override
    {
        cout << asd << endl;
    }
};

class D22 : public B2 {
    public:
    int i = 8347;
    void pvf() override 
    { 
        cout << i << '\n'; 
    }
};

void f(B2& b)
{
    b.pvf();
}

int main()
{
    B1 b1;
    b1.f();
    b1.vf();

    D1 d1;
    d1.f();
    d1.vf();

    //B1& b1ref {d1}; ??????

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21;
    f(d21);

    D22 d22;
    f(d22);

    return 0;
}