
# Note:
- In this topics we will distinguish and clarify issues through C++ programming examples:

# Content
- Common problems:
    - [Manage life cycle]()
    - [Dynamic allocation](#dynamic-allocation)
    - [static in class](#static-in-class)
    - [template](#template)
    - [operator overloading in class](#operator-overloading-in-class)
    - [lambda expression](#lambda-expression)
    - [extern C](#extern-c)
- OOP:
    - [Encapsulation](#encapsulation)
    - [Inheritance](#inheritance)
    - [Polymorphism](#polymorphism)
    - [Abstraction](#abstraction)

## Problems
### Manage variable `life cycle`
- Different mechanism:
    - `C`:
        + The compiler simply creates stack space for any `variable` or `function pointer`
        + When a `variable` goes out of scope, its memory is `automatically freed`.
        + Jumping with `goto` is generally allowed—even over variable declarations—because C does not have constructors or destructors that need to be called explicitly.
    - `C++`:
        + C++ introduces `constructors` and `destructors` for objects.
        + When a variable like `int a = 10;` or an object like `MyClass obj;` is declared, the compiler inserts code to `construct` and `destruct` that object.
        + If you use goto to jump over such a declaration, C++ cannot guarantee the constructor ran—yet the destructor might still be called later, leading to undefined behavior.
        + Therefore, C++ forbids jumping over variable.

### Using `new/delete` instead of `calloc/free`
1. `calloc/free` need `#define <stdlib.h>`
2. `calloc/free` only allocate new memory for `class` and never auto call `initial function`. 
    - `malloc` doesn't invoke the constructor of the object, while `new` in C++ does.

### `static` in class
- A `static` variable in a class is shared among all instances of that class.
- A `static` method cannot access non-static members of the class directly.
- The purpose of using `static` for class methods or variables is that we can interact  
  with these entities without creating an object.
    - In fact, we can simply call `ClassName::staticMethod` or `ClassName::staticVariable`.
    - Example:
    ```cpp
    class MyClass {
    public:
        static int count;
        MyClass() { count++; }
        static void printCount() { std::cout << "Count: " << count << std::endl; }
    };

    int MyClass::count = 0;
    ```


### `template`
- Templates in C++ provide a way to create generic functions and classes that can work with any data type.

Example of a template function:
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << std::endl;    // Works with int
    std::cout << add(3.5, 2.2) << std::endl;  // Works with double
}
```

### `operator overloading`
- Operator overloading allows you to define the behavior of operators for user-defined types.

Example of operator overloading:
```cpp
class Complex {
public:
    int real, imag;
    Complex(int r, int i) : real(r), imag(i) {}
    
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};
```

### `lambda expression`
- Lambda expressions provide a concise way to define anonymous functions in C++.

Example of a lambda function:
```cpp
auto add = [](int a, int b) -> int { return a + b; };
std::cout << add(2, 3) << std::endl;
```

### `extern C`
- `extern "C"` is used to tell the C++ compiler to treat the following code as C code for linkage purposes. This is useful when you want to interface C++ with C libraries.

Example:
```cpp
#ifndef MY_C_API_H
#define MY_C_API_H

#ifdef __cplusplus // << note for C++ this is C file, do not Overload any function, and ignore if C
extern "C" {
#endif

void cFunction1();
void cFunction2();

#ifdef __cplusplus
}
#endif

#endif // MY_C_API_H

```

## Object oriented programming properties
### Encapsulation
- Encapsulation is the practice of bundling data (attributes) and the methods (functions) that operate on the data into a single unit, or class.
- It helps in restricting direct access to some of an object's components, which can prevent accidental modification of data.

Example:
```cpp
class Person {
private:
    std::string name;
    int age;
    
public:
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};
```

### Inheritance
- Inheritance allows a class (child class) to inherit properties and behaviors (methods) from another class (parent class).
- It promotes code reuse and makes it easier to manage and extend functionality.

Example:
```cpp
class Animal {
public:
    void speak() { std::cout << "Animal speaks" << std::endl; }
};

class Dog : public Animal {
public:
    void speak() { std::cout << "Dog barks" << std::endl; }
};
```

### Polymorphism
- Polymorphism allows for using a single interface to represent different types of objects, and the correct method is called at runtime depending on the object type.
- This is typically implemented using `virtual` functions.

Example:
```cpp
class Base {
public:
    virtual void speak() { std::cout << "Base speaks" << std::endl; }
};

class Derived : public Base {
public:
    void speak() override { std::cout << "Derived speaks" << std::endl; }
};

Base* b = new Derived();
b->speak();  // Outputs "Derived speaks"
```

### Abstraction
- Abstraction is the concept of hiding the complex implementation details and showing only the necessary features of an object.
- In C++, this is achieved using classes and interfaces (abstract classes).
- A `virtual function ` with no define of `=0` is called `Pure virtual function`
- A class have at least 1 `virtual funtion` if called `Abstract class`
- So `Abtraction` is a type of `Polimorphism`

Example:
```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle" << std::endl; }
};
```

