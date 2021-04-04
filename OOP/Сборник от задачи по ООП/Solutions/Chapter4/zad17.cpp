#include <iostream.h>

class Base 
{
public:
    Base()
    {
        cout << "Base\n";
    }

    virtual void f()
    {
        cout << "Base::f()\n";	
        g();	// ��������� �)
        h(); 	// ��������� �)
    }

    virtual void g()
    {
        cout << "Base::g()\n";
    }

    void h()
    {
        cout << "Base::h()\n";
    }

    ~Base()
    { 
        cout << "Base::~Base()\n";
    }
};

class Der1 : public Base 
{
public:
    Der1()
    {
        cout << "Der1\n";
    }

    void g()
    {
        cout << "Der1::g()\n";
    }

    void h()
    {
        cout << "Der1::h()\n";
    }

    virtual ~Der1()
    {
        cout << "Der1::~Der1()\n";
    }
};

class Der2 : public Der1
{
public:
    void f()
    {
        cout << "Der2::f()\n";	
        g();	// ��������� �)
        h();	// ��������� �)
    }

    void h()
    {
        cout << "Der2::h()\n";
    }

    ~Der2()
    {
        cout << "Der2::~Der2()\n";
    }
};

int main()	
{
    Der1 d1; 	             // �)
    Der2 d2;	              // �)
    Base *bp = new Der2;	  // �)
    Der1 *d1p = new Der2;	 // �)
    bp->f();	              // ��������� �)
                           // �)
    bp->h();	              // ��������� �)
                           // �)
    d1p->f();
                           // ��������� �)
                           // �)
    d1p->h();
                           // ��������� �)
                           // �)
    d1.f();	               // �)
    d1.h();	               // �)
    d2.f();	               // �)
    d2.h();	               // �)
    delete bp;	            // �)
    delete d1p;	           // �)
				return 0;														// �)
} 	                        
