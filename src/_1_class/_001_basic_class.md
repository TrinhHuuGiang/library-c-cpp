# content
- [Class](#class)
- [Constructor function](#constructor)
- [Destructor function](#destructor)

<hr>

# Class
- A class is an extension of a data structure. It can contain variables, data structures, and functions.  
- Syntax:  
```Cpp
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names; // Optional: List of initialized objects
```

- A class has three types of access specifiers: private, public, and protected.  
    - `private` members of a class are accessible only from within other members of the same class (or from their "friends").  
    - `protected` members are accessible from other members of the same class (or from their "friends"), but also from members of their derived/inherited classes.  
    - Finally, `public` members are accessible from anywhere where the object is visible.  
    ```Cpp
    class example_class {
      int a; // a is private by default

      protected: // b and function_1 is protected
        char b;
        int function_1(); // declare content in another scope

      public:  // c is public
        float c;

      private:  // d is private
        double d;
    };
    ```
- Default, any member that is declared before any other access specifier has `private` access automatically  
- Sometime, we use the `scope operator '::'` to define content for function declared in class by syntax:
  ```Cpp
  int example_class::function_1() { /*content*/}
  ```
<hr>

# Constructor
- To avoid undefined results, variables, structures in the class can be initialized to values ​​before they are used.  
- This `constructor` function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.  
- [Example](_001_basic_class.cpp)  
<hr>

# Destructor
- A destructor is a special function automatically called when an object is destroyed.  
- It is used to release resources (e.g., memory, file handles) acquired by the object.  
- Name: `~class_name()` (no return type, no arguments).  
- Only one destructor per class.  
- Syntax:  
  ```cpp
  class class_name {
  public:
      ~class_name() {
          // Cleanup code
      }
  };
  ```