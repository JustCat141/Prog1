#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void function(const char* p,const int x)
{
    printf("p is %s and x is %i\n",p,x);
}

int main()
{
    // 1
    printf("Hello World!\n");

    // 2
    char hello[] = "Hello";
    char world[] = "World!";
    printf("%s %s\n",hello,world);

    // Másik variáció
    //char* _hello = "Hello";
    //char* _world = "World!";
    //printf("%s %s\n",_hello,_world);

    // 3
    function("macska",20);
    function("Chad",-18);
    function("0",0);
}