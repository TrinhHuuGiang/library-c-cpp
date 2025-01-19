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