# content:
- [overload function](#overload)
- [template function](#template)
<hr>

# Overload
- In C++, two different functions can have the same name if their parameters are different;  
either because they have a different number of parameters, or because any of  
their parameters are of a different type.  
- Overloaded functions may have the same definition.  
```Cpp
int function_1(){ /*content*/ }
int function_1(int a){ /*content*/ }
int function_1(int a, int b){ /*content*/ }
int function_1(int a, char b){ /*content*/ }

```
<br>

- Note that a function cannot be overloaded only by its return type. At least  
one of its parameters must have a different type.  
```Cpp
int function_1(){ /*content*/ }
// float function_1(){ /*content*/ }  <= this function can't overload
```
<hr>

# Template
In-case overloaded function have the same definition we can using 'template' to define  
type of parameter input and value return dynamically. [sample code](_004_template.cpp)  
- Simple explanation:  
```Cpp
// define
template <class T1, class T2, class T>
T function_name(T1 para1, T2 para2)
{
    return (T)(para1 + para2); // if T1 can plus T2
}

// using
int main()
{
    int a, b;
    float c;
    a = function_name<int, float, int>(b,c);
    return 0;
}
```
