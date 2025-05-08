# content
- [friend function](#friend-function)
- [friend class](#friend-class)
- [inheritance class](#inheritance-class)
<hr>

# Friend function
- Hàm friend là một hàm bình thường được khai báo và định nghĩa bên ngoài nhưng được khai báo thêm bên trong một lớp (class). Hàm friend có thể truy cập tất cả các thành phần private và protected của class nhưng không thuộc về class đó.  
- Hàm friend không là thành phần của class, nên không có con trỏ tự động truy cập `this`.  
- Dùng khi cần truy cập dữ liệu private/protected từ bên ngoài.  
- Cách khai báo:  
    ``` Cpp
    class MyClass
    {
        private:
            int privateData;
        public:
            MyClass(int value) : privateData(value) {}
            friend void displayPrivateData(const MyClass& obj); // Hàm friend
    };

    void displayPrivateData(const MyClass& obj)
    {
        std::cout << "Private Data: " << obj.privateData << std::endl;
    }
    ```

# Friend class
- Lớp friend cho phép một class truy cập tất cả các thành phần private/protected của lớp khác.  
- Sử dụng lớp friend khi hai lớp có quan hệ rất gần gũi, cần trao đổi dữ liệu trực tiếp.  
- Lớp friend không có khái niệm 2 chiều và bắc cầu nên:  
    - Ví dụ C là friend của B, B là friend của A  
    - lớp friend B có thể truy cập vào lớp A nhưng không thể ngược lại.  
    - Lớp friend C không thể truy cập vào lớp A vì không phải là friend của A.  
- Cách khai báo:  
    ```Cpp
    class ClassA
    {
        private:
            int secretData;
        public:
            ClassA(int value) : secretData(value) {}
            friend class ClassB; // ClassB là friend of class A
    };

    class ClassB
    {
        public:
            void displaySecret(ClassA& obj) {
                std::cout << "Secret Data: " << obj.secretData << std::endl;
            }
    };
    ```
<hr>

# Inheritance class (Chỉ áp dụng lên public và protected)
- **Lưu ý:** Các thành viên `private` trong lớp cha `không bao giờ có mặt trong lớp con`. Lớp con không thể truy cập trực tiếp vào các thành viên private của lớp cha, dù cho kiểu kế thừa có là gì đi nữa.

- `Public inheritance`: Các thành viên `public` và `protected` của lớp `cha` sẽ được giữ nguyên quyền truy cập trong lớp con. Lớp con có thể truy cập các thành viên này.  
- `Protected inheritance`: Các thành viên `public` và `protected` của lớp `cha` sẽ trở thành `protected` trong lớp con. Các thành viên này sẽ không thể truy cập từ bên ngoài lớp con, nhưng vẫn có thể truy cập trong lớp con và các lớp con của nó.  
- `Private inheritance`: Các thành viên `public` và `protected` của lớp `cha` sẽ trở thành `private` trong lớp con, và không thể truy cập từ bên ngoài lớp con.


- Cú pháp:  
    ```Cpp
    class public_Derived : public Base
    {
    // Các thành viên và phương thức của lớp con
    };

    class protected_Derived : protected Base
    {
    // Các thành viên và phương thức của lớp con
    };

    class private_Derived : private Base
    {
    // Các thành viên và phương thức của lớp con
    };
    ```

