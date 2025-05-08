// g++ -std=c++0x ./_006_conclusion.cpp -o ./build/_006_conclusion.out
// ./build/_006_conclusion.out

// C++
#include <iostream>
#include <string>

using namespace std;

// C
#include <stdlib.h>
#include <stdio.h>


/** ========================================================
 * Classes
 ======================================================== */
// new/ delete ...
class _alloc_mem
{
private:
    /* data */
public:
    _alloc_mem(/* args */);
    ~_alloc_mem();
};



// static member
class _static_mem
{
private:
    /* data */
public:
    _static_mem(/* args */);
    ~_static_mem();

    static int i; // define outside the class
    void mod_i(int new_i);

};


// template
template <typename T1, typename T2, typename T3>
class _template_var
{
private:
    T1 a;
    T2 b;
    T3 c;
public:
    _template_var(T1 a, T2 b, T3 c);
    ~_template_var();
    void print_values();
};


// operator overload
class _operator_overload
{
private:
    int val;
public:
    _operator_overload(int v = 0);
    ~_operator_overload();

    _operator_overload operator+(const _operator_overload& other)
    {
        return _operator_overload(this->val + other.val);
    }

    int get_val() { return val; }
};


// Polymorphism
class _A_class
{
public:
    _A_class() { cout << "Construct A\n"; }
    virtual ~_A_class() { cout << "Destruct A\n"; }
    virtual void virtual_func() { cout << "A::virtual_func()\n"; }
};


class _B_class : public _A_class
{
public:
    _B_class() { cout << "Construct B\n"; }
    ~_B_class() { cout << "Destruct B\n"; }
    void virtual_func() override { cout << "B::virtual_func()\n"; }
};





/** ========================================================
 * Prototypes
 ======================================================== */



/** ========================================================
 * Code
 ======================================================== */
int main()
{
    int ret = 0;

    // alloc mem
    cout << "====================================\n";
    cout << "Alloc memory with 'calloc' then 'new'\n";

    cout << "Calloc ...\n";
    _alloc_mem* _alloc_1 = (_alloc_mem*)calloc(1, sizeof(_alloc_mem));

    if(_alloc_1 == NULL)
    {
        ret = 1;
        // goto wrong_state; // <- can't jump over _alloc_mem* _alloc_2
                          // :) yeah using return
                          // or we reshape code, bring all declare variable on top of scope
        
        return ret;

    }


    cout << "New ...\n";
    _alloc_mem* _alloc_2 = new _alloc_mem;

    if(_alloc_2 == nullptr)
    {
        free(_alloc_1);

        ret = 2;
        // goto wrong_state;

        return ret;
    }

    cout << "\n\nDeleting memory with 'calloc' then 'new'\n\n";

    cout << "Calloc - deleting ...\n";
    free(_alloc_1);
    cout << "Calloc - deleted !\n\n";

    cout << "New - deleting ...\n";
    delete(_alloc_2);
    cout << "New - deleted !\n";


    // static member
    {
        cout << "====================================\n";
        cout << "Static in class\n";

        _static_mem _stc_1;
        _static_mem _stc_2;

        cout<< "- Class:   static_value = [" << _static_mem::i << "]\n";
        cout<< "- Object1: static_value = [" << _stc_1.i << "]\n";
        cout<< "- Object2: static_value = [" << _stc_1.i << "]\n";

        int new_i = 10;
        _stc_1.mod_i(new_i);
        cout << "Object1 modified static_value = ["<< new_i <<"]\n";
        cout<< "- Class:   static_value = [" << _static_mem::i << "]\n";
        cout<< "- Object1: static_value = [" << _stc_1.i << "]\n";
        cout<< "- Object2: static_value = [" << _stc_1.i << "]\n";
        

        cout << "\nCleaning ...\n";
    }


    // template
    {   
        cout << "====================================\n";
        cout << "Template in class\n";
    
        _template_var<int, float, string> t_var(1, 1.5, "hello");

        t_var.print_values();
        cout << "\nCleaning ...\n";
    }


    // operator
    {
        cout << "====================================\n";
        cout << "Operator Overload\n";
        
        cout << "op1: default 0\n";
        cout << "op2: set 5\n";
        _operator_overload op1;
        _operator_overload op2(5);
        _operator_overload op3 = op1 + op2;
    
        cout << "Result of op1 + op2 = " << op3.get_val() << "\n";
    }



    // polymorphism 
    cout << "====================================\n";
    cout << "Polymorphism\n";

    _A_class* a = new _B_class();  // base pointer, derived object
    a->virtual_func();
    delete a;    


    return 0;

    // jump out variable prohibited in c++
// wrong_state:
//     return ret;

}



/** ========================================================
 * Def class
 ======================================================== */

_alloc_mem::_alloc_mem(/* args */)
{
    cout<<"[Succes] new object _alloc_mem\n";
}

_alloc_mem::~_alloc_mem()
{
    cout<<"[Succes] delete object _alloc_mem\n";
}


_static_mem::_static_mem(/* args */)
{
    cout<<"[Succes] new object _static_mem\n";
}

_static_mem::~_static_mem()
{
    cout<<"[Succes] delete object _static_mem\n";
}

int _static_mem::i = 0;

void _static_mem::mod_i(int new_i)
{
    this->i = new_i;
}

template <typename T1, typename T2, typename T3>
_template_var<T1,T2,T3>::_template_var(T1 a, T2 b, T3 c)
{
    this->a = a;
    this->b = b;
    this->c = c;

    cout<<"[Succes] new object _template_var\n";
}

template <typename T1, typename T2, typename T3>
_template_var<T1,T2,T3>::~_template_var()
{
    cout<<"[Succes] delete object _template_var\n";
}

template <typename T1, typename T2, typename T3>
void _template_var<T1,T2,T3>::print_values()
{
    cout<<"a = ["<<this->a<<"]\n";
    cout<<"b = ["<<this->b<<"]\n";
    cout<<"c = ["<<this->c<<"]\n";
}

_operator_overload::_operator_overload(int v)  // no re - define default value
{
    this->val = v; 
}

_operator_overload::~_operator_overload()
{
}


