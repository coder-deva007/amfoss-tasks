#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>


int main(void)
{
    
    float index = 0, x;
    float L = 0, S = 0, l = 0, w = 0, s = 0;
    
    //Accepting string
    string text = get_string("TEXT: ");
    
    //Reading each character from the string
    for (int i = 0 ; text[i] != '\0'; i++)
    {   
        //Checking whether it is an alphabet
        if (isalpha(text[i]))
        {
            l++;
        }
        
        //Checking whether it is a space
        if (text[i] == ' ')
        {
            w++;
        }
        
        //Checking whether it '.' or '!' or '?'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
        
        
    
        
    }
    w++;
    L = (l * 100) / w;
    S = (s * 100) / w;
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    x = round(index);
    
    //Checking the grade
    if (x >= 1 && x <= 16)
    {
        printf("\nGrade %.0f\n", x);
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    
    

}