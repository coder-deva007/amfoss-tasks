#include<stdio.h>
#include<cs50.h>

int main(void)
{   
    int s = 0, i, a, b, c, d, e = 0, f = 0, g;
    long n;
    
    //To execute this first and then checking whether to repeat
    do 
    {
        n = get_long("Number: ");
        a = 0;
        b = 0;
        i = 1;
    }
    while (n < 0);
        
    //Repeat this till n becomes o
    while (n)
    { 
        //Checking i is even or odd
        if (i % 2 != 0)
        { 
            c = n % 10;
            a = c + a;
        }
        else
        {    
            d = 2*(n % 10);
            g = d/2;
            if(d/10 >= 1)
            { 
                f = 0;
                while(d)
                {
                    e = d%10;
                    f = f + e;
                    d = d/10;
                }
                    
                d = f;
                
                    
            }
            b = b + d;
        }
        n = n/10;
        i++;
            
    }
         
    s = a + b;
    d = d / 2;

    //Checking whether it is valid or not
    if (s % 10 == 0)
    { 
    
        if (i % 2 == 0)
        { 
          
            if (c == 3)
            { 
                if ((g * 2) / 10 == 1)
                {
                    if(g == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                
                else
                {
                    if (d == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    
                }
                
            }
            else if (c == 4)
            {
                if ((g * 2) / 10 == 1)
                {
                    if(g == 0 || g == 1 || g == 2)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                   
                }
                else
                {
                    if (d == 0 || d == 1 || d == 2)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    
                }
                
                
            }
            else if (c == 5)
            {
                if ((g * 2) / 10 ==1)
                {
                    if(g == 1 || g == 2 || g == 3 || g == 4 || g == 5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                
                else
                {
                    if (d == 1 || d == 2 || d == 3 || d == 4 || d == 5 )
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    
                }
                
            }
        }    
        else
        {       
            if ((g * 2) / 10 == 1)
            {
                
            
                if (g == 3)
                {
                    
                    if (c == 7) 
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else if (g == 4)
                {
                    if (c == 0 || c == 1 || c == 2) 
                   {
                       printf("VISA\n");
                   }
                   else
                   {
                       printf("INVALID\n");
                   }
                  
                }
                else if (g == 5)
                {
                    if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5) 
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                  
                }
            
            }
            
            else
            {
                if (d == 3)
                {
                    if (c == 7) 
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                   
                }
                else if (d == 4)
                {
                    if (c == 0 || c == 1 || c == 2) 
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                   
                }
                else if (d == 5)
                {
                    if(c == 1 || c == 2 || c == 3 || c == 4 || c == 5) 
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
        
                  
                }
                
            }
        
        
        }
        
    }    
    
    
    //Printing if invalid
    if (s % 10 != 0 || i < 14)
    {
        printf("INVALID\n");
    }
        
     
}