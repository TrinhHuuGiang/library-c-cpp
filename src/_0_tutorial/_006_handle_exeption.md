### Reference
- [exaption handling video](https://www.youtube.com/watch?v=TkEIU1ZH0zw)

### Try - throw - catch
- This method has a bit similar with `if - else` but flexible in operation range:
    - `if-else` need handle exeption in `if` `else if` and `else`
    - But `throw` , `catch` more flexibale while:
        - `throw` has to exist in a `try` scope, each time `thow` something, the `catch` support `try` handle it:
            - if not any `catch` match with `something` that `thow` send the program will crash.
            - else program continue run after `catch code` handle it
        ``` cpp
        try // largest scope
        {
            int a = 0;
            int b = 10;

            if(a == 0)
            {
                throw (float) 0;
            }
        }
        catch(int& a)// int
        {
            cout<<"Int: "<< a <<endl;
        }
        catch(float& a)// float
        {
            cout<<"Float:"<< a <<endl;
        }
        catch(class_defined& )
        {
            ...
        }
        ```
        - Note:
            - each catch has to right order and throw will browse from high to low
            - each catch has to queuing after try like above template
            - a `throw` generate by a `function` maybe thow out of scope funtion and `catch` by a outside `try`, so by default `throw` create a copy `object/variable` before it delete by stack.
        