### References
- C++ - [HackerRank](https://www.hackerrank.com/)
- [vector](https://cplusplus.com/reference/vector/vector/)
- [string](https://cplusplus.com/reference/string/)

### Topic 
- [Basic data types]()
- [Vector|Variable size array]
- [String| a class about string](#string)
- [Stringstream| Help parse string to number, char, string ... or reverse write multiple type to a string]
- []

#### String
- [Topic](#topic)
  ```cpp
    #include <string>
    #include <iostream>
    using namespace std;

    // incode
      // normal string/ ASCII
    string a = "abc", b="defg";

      // Wide string / Unicode
      // L"" is wchar > char, using represent Unicode character
    wstring c = L"Xin chào", d = L"Tạm biệt";

      // size
    int size_a = a.size(), size_b = b.size();

      // concatenate 
    string ab = a+' '+b;  
    wstring cd = c+L' '+d;

      // output
    cout <<"This is string a and b: " << ab << endl;
    wcout <<L"This is wstring c and d: " << cd << endl;

  ```
