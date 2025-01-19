/*
- using: bash or anothers terminal support
- go to: src/_0_tutorial
- build command: g++ -std=c++0x _004_template.cpp -o ./build/_004_template
- run command: ./build/_004_template
*/
#include<stdio.h>

// define
template <class T1, class T2, class T>
T function_name(T1 para1, T2 para2)
{
    return (T)(para1 + para2); // if T1 can plus T2
}

// using
int main()
{
    int a;
    float b, c;

    printf("input a - int ,b - float:\n");
    scanf("%d %f", &a,&b);

    c = function_name<int, float, int>(a,b); // return (int)(int + float)
    printf("(float)c = (int) (a + b) = %f\nPress any key to exit", c);

    // exit
    fflush(stdin);
    getchar();
    fflush(stdin);
    return 0;
}