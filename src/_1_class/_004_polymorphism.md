- [see more](https://cplusplus.com/doc/tutorial/polymorphism/)



# Virtual Functions in C++

1. Purpose of `virtual`:
- Used in inheritance to enable runtime polymorphism.
- Allows calling derived class methods through base class pointers or references.

2. Syntax:
class Base {
public:
    virtual void display();  // Virtual function
};

3. Without `virtual`:
- Base class method is not overridden properly when accessed via base pointer.
- Always calls the base version.

4. With `virtual`:
- Enables polymorphism.
- Calls the appropriate derived class method based on the actual object type.

5. Polymorphism:
- Achieved using virtual functions.
- Allows code to `work on base class` interface `while` behaving `according to derived class type`.
- Example:
    - We something declare lots of virtual `method` in `base class` then define what `method` do in `derived class`, it help 1 function can dynamicaly in runtime.
    ``` cpp
    #include <iostream>
    using namespace std;

    class Base {
    public:
        virtual void speak() { cout << "Base speaking\n"; }
    };

    class Derived : public Base {
    public:
        void speak() override { cout << "Derived speaking\n"; }
    };

    int main() {
        Base* obj = new Derived();
        obj->speak();  // Output: "Derived speaking"
        delete obj;
    }

    ```

6. Destructor (`~`) as `virtual`:
- If deleting derived object through base class pointer, destructor must be virtual.
- Prevents memory/resource leaks.

Example:
class Base {
public:
    virtual ~Base() { std::cout << "Base destroyed\n"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived destroyed\n"; }
};

Base* obj = new Derived();
delete obj;  // Calls both destructors if virtual

7. Summary:

| Concept            | With `virtual`              | Without `virtual`          |
|-------------------|-----------------------------|----------------------------|
| Method Overriding | Calls derived method         | Calls base method only     |
| Destructor        | Destroys derived + base      | Destroys base only (leak)  |
