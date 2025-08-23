# Overloading operators
The purpose of operator overload is to make objects from either `struct` or `class` able to interact with each other through mathematical operators  


<hr>

- List of all the operators that can be overloaded:  
    ```note
    +  -  *  /  %  ^  &  |  ~  !
    =  <  >  += -= *= /= %= ^= &= |=
    << >> >>= <<= == != <= >=
    && || ++ -- , ->* ->
    () [] -> new delete new[] delete[]
    ```

- The syntax:
    `type operator sign (parameters) { /*... body ...*/ }`
    [Example](https://cplusplus.com/doc/tutorial/templates/)  

- With a is an object of class(or struct) A, b is an object of class (or struct) B, an operator can overload as a member class, or non-member function:
    |Expession| Member function |  Operator|  Non-member function|
    |-|-|-|-|
    |@a| ret_type A::operator@() | `+` `-` `*` `&` `!` `~` `++` `--`| operator@(A)|
    |a@| ret_type A::operator@(int) | `++` `--`| operator@(A,int) |
    |a@b| ret_type A::operator@(B) | `+` `-` `*` `/` `%` `^` `&` `\|` `<` `>` `==` `!=` `<=` `>=` `<<` `>>` `&&` `\|\|` `,` `=` `+=` `-=` `*=` `/=` `%=` `^=` `&=` `\|=` `<<=` `>>=` `[]` | operator@(A,B) |
    |a(b,c,..)| ret_type A::operator()(B,C...) | `()`|x|
    |a->b| ret_type A::operator->() | `->` |x|
    |(TYPE) a| 	A::operator TYPE() | (TYPE) |x|

    - with `(TYPE)a` is casting expreassion alway return TYPE, other overload return `ret_type`
    - `a(a,b,...)` function operator, `a->b` point operator, `(TYPE)a` alway need a base object `a`, it bind and handle by `this` of `a` so they can't be `non-member`.
    - when an operator declare as non-member function, they only access private member if declare is [friend](./_003_friend_inherit.md)