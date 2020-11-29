#include<stdio.h>
#include<cs50.h>

int main(void)
{  
    int n;
    //To make the user to give numbers between 1 & 8
    do
    {
       
        n = get_int("Height ");
     
    }
    while (n < 1 || n > 8);
   
    //for displaying rows and columns
    for (int i = 1; i <= n ; i++)
    {   
        
        for (int j = 1; j <= n; j++)
        { 
            if (j <= n - i)
            {
             
                printf(" "); 
               
            }
           
           
            else
            {
               
                printf("#");
           
            }
           
            //Checking whether to bring the curzor to the next line
            if (j == n)
            
            {   
                
                //To bring the curzor to the next line
                printf("\n");
                
            }     
        }   
     
    }
    

}
