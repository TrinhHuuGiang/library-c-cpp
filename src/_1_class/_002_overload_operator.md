# Overloading operators
The purpose of operator overload is to make objects from the class able to interact with each other through mathematical operators  
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