#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("hello, world\n");
    
    //Assigning string value in name
    string name = get_string("What is your name\n");
    
    printf("Hello, %s\n", name);
}
