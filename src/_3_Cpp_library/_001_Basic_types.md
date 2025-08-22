### References
- C++ - [HackerRank](https://www.hackerrank.com/)
- [vector](https://cplusplus.com/reference/vector/vector/)
- [string](https://cplusplus.com/reference/string/)

---

### Topic 
- [Basic data types]()
- [Vector|Variable size array]
  - Include `vector`
- [String| a class about string](#string)
  - Include `string`
- [Stringstream| Help parse string to number, char, string ... or reverse write multiple type to a string](#stringstream)
  - Include `sstream` 


---

#### Vector
- Vector is data structure quite similar with array but the size can change by dynamic allocate memory.
  - Disadvantage is time consuming when append new value to Vector array at time it full, reallocate and copy old array to new one is slower then other structure like `list` (linked list).
    - So the size of Vector table sometime larger than necessary for reserve
  - Advantage the time access to value is O(n) like `array` because using `index`
  - `Iterator` and `Reverse iterator` are special pointer (pseudo pointer) design for several container in C++ include `vector`
    - `.begin()` return iterator point to beginning
    - `.end()` return iterator point pass to end
      - that mean C++ design range for inter is : `[ begin element, end element +1]`
      - and special when `empty vector`, `.end()` have the same point to `.begin()`
        ```cpp
          vector<int>::iterator it = vector_X.begin();
          for(it; it != vector_X.end(); it++)
          { 
            // do something with current vector element by *it   
          }
        ```
    - `.rbegin()` and `.rend()` support reverse return value point `end element and begin element` using for convenience reverse browse vector.

    - Vector still using index like array to access value but iterator is more flexible, it still exist in other container like `list`
  - Method clear vector to empty `.clear()` auto call destructor for elemet
    - Note that element `pointer` do not has a destructor so must browse and delete by hand before `.clear()` else leak memory.
    - `.shrink_to_fit()` method should use to mimimize vector after `clear` for save memory

  - some method operate data on vector:
    - fast handle `pushback`, `popback`
    - handle by `iterator` not use reverse iterator: `insert`, `erase`
      - note the iterator do not point out of range `[begin, end)`
      - note erase by parameter a range `[a,b)`
- Some common method: [see example](./_001_vector_example.cpp)

---

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
- Some common method:
  1. find a string/char inside
    ```cpp
      string a = "..b..";
      int b = a.find('b'); // return string::npos (-1) if not found, else position start char/ string
      if(b != string::pos)
        cout<< "Found char"<< endl;
    ```
  2. Cut string
    ```cpp
      string b = a.substr(0, string::npos); // replace 0 with start position, 
                                            // string::npos auto cut until end string
                                            // - replace it by size want to cut
    ```
---

#### Stringstream
- [Topic](#topic)
- String stream has a bit similar with `scanf` handle input or `fprintf` handle output with different format.
- Require `sstream`
  - Init stream require an initial value
    ```cpp
    stringstream ss("");
    ```
  - Using operator `>>` to parse, and `blank` (' ', '\n', '\t' ...) to separate.
    - we use 2 method `.eof()` and `.fail()` to check `EOF reached` or `FAIL when read` after read.
    - we use `.clear()` method to clean above flag if them are set before read. 
    - When parse the cursor get will count up point to next value to read.
    - To move `get` cursor to origin or a position `.seekg(0)`/`.seekg(pos)`
  - Using operator `<<` to write to stream
    - To move `put` cursor use `.seekp(pos)`
  - Print a `stringstream` need convert to string method `.str()` before using `cout`
  - Note that overload function `.str(constr string& n_string)` will using to delete `old string` and replace by `n_string`


- Syntax input to `string stream`
  ```cpp
  #include <sstream>
  #include <string>
  #include <iostream>
  using namespace std;
  //incode
  stringstream ss("");

  // write to stream
  ss<< "456" << ' ' << "abc" << ' ' <<",123";

  // parse
  int a1, a2; string c; char d;

  ss>>a1>>c>>d>>a2;
  
  cout<< "String stream:[" << ss.str() << "]\n";
  cout<< "Parse: a1 ["<<a1<<']\t';
  cout<< "c ["<<c<<']\t';
  cout<< "d ["<<d<<']\t';
  cout<< "a2 ["<<a2<<']\n';
  ```

