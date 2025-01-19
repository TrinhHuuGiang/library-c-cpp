/*
- using: bash or anothers terminal support
- go to: src/_1_class
- build command: g++ -std=c++0x _001_basic_class.cpp -o ./build/_001_basic_class.out
- run command: ./build/_001_basic_class.out
*/

#include <stdio.h>

class example_class {
    int a;
    int b;
    int c;

    public:
    example_class(int a = 0, int b = 0, int c = 0)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void print_abc()
    {
        printf("a=%d,b=%d,c=%d", this->a,this->b,this->c);
    }
};

int main()
{
    example_class A(1,2,3); // i want a = 1 , b = 2, c = 3
    A.print_abc();

    fflush(stdin);
    printf("\npress any key to end");
    getchar();
    return 0;
}