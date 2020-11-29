#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    int f = 0, g = 0, h = 0, r = 0, x = 0, y = 1;
    h = atoi(argv [1]);
    
    //Checking argc
    if (argc != 2 || !h)
    {
        f = 1;
    }
    else 
    {
        

                
        //Checking whether number is positive         
        if (h >= 0)
        {
                
                
                
        }
           
        else
        {
                
            f = 1;
        }
        
    }
    
    //checking for wrong input
    if (f == 1)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        
        string str = get_string("plaintext:  ");
        
        
        if (h > 26)
        {
            g = h;
            int i = 0;
            while (y)
            {
                r = g % 26;
                g = g % 26;
                y = g / 26;
            }
        }
        else 
        {
            r = h;
        }
        for (int i = 0; str[i] != '\0'; i++)
        {
            //Checking whether it is an alphabet
            if (isalpha(str[i]))
            {
                //Checking for lowercase
                if (islower(str[i]))
                {
                    str[i] = toupper(str[i]);
                    x = str[i];
                    str[i] = str[i] + r;
                    if ((r + x) > 90)
                    {
                        str[i] = str[i] + 6;
                        str[i] = tolower(str[i]);
                    }
                    else
                    {
                        str[i] = tolower(str[i]);
                    }
                }
                else
                {
                    x = str[i];
                    str[i] = str[i] + r;
                    if ((r + x) > 90)
                    {
                        str[i] = str[i] + 6;
                        str[i] = toupper(str[i]);
                    }
                }     
            }
        }
    
        printf("ciphertext:  %s\n", str);    
    }
}