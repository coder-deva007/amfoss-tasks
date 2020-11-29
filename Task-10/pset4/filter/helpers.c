#include "helpers.h"
#include<stdio.h>
#include<math.h>
#include<cs50.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg, d = 0;
    int in;
    //To get each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Finding average
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            if ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) % 3 != 0)
            {
                
                image[i][j].rgbtBlue = avg + 1;
                image[i][j].rgbtGreen = avg + 1;
                image[i][j].rgbtRed = avg + 1;
            }
            else
            {
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;
                image[i][j].rgbtRed = avg;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sRed, sGreen, sBlue;
    //To get each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Calculating sepia pixel value using this formula
            sRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            sGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            sBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            //Checking whether it is greater than 255
            if (sRed > 255)
            {
                sRed = 255;
            }    
            if (sGreen > 255)
            {
                sGreen = 255;
            }
            if (sBlue > 255)
            {
                sBlue = 255;
            }
            image[i][j].rgbtRed = round(sRed);
            image[i][j].rgbtGreen = round(sGreen);
            image[i][j].rgbtBlue = round(sBlue);
        } 
    }    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp, mid = (width - 1) / 2, beg, end;
    //To get each pixel
    for (int i = 0; i < height; i++)
    {
        for (beg = 0, end = width - 1; beg <= mid; beg++, end--)
        {
            //Swapping each first pixel value with corresponding last pixel value
            temp = image[i][beg].rgbtRed;
            image[i][beg].rgbtRed = image[i][end].rgbtRed;
            image[i][end].rgbtRed = temp;
                
            temp = image[i][beg].rgbtGreen;
            image[i][beg].rgbtGreen = image[i][end].rgbtGreen;
            image[i][end].rgbtGreen = temp;
                 
            temp = image[i][beg].rgbtBlue;
            image[i][beg].rgbtBlue = image[i][end].rgbtBlue;
            image[i][end].rgbtBlue = temp;
        }
        
        
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Declaring a struct
    RGBTRIPLE dupimage[height][width];
    int i, j;
    //To get each pixel
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Copying it to the new variables
            dupimage[i][j].rgbtRed = image[i][j].rgbtRed;
            dupimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            dupimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    //To get each pixel
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //To check first row
            if (i == 0)
            {
                //To check first pixel
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i + 1][j].rgbtRed + dupimage[i][j + 1].rgbtRed + dupimage[i + 1][j + 1].rgbtRed) / 4);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i + 1][j].rgbtGreen + dupimage[i][j + 1].rgbtGreen + dupimage[i + 1][j + 1].rgbtGreen) / 4);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i + 1][j].rgbtBlue + dupimage[i][j + 1].rgbtBlue + dupimage[i + 1][j + 1].rgbtBlue) / 4);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i + 1][j].rgbtRed + dupimage[i][j - 1].rgbtRed + dupimage[i + 1][j - 1].rgbtRed) / 4);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i + 1][j].rgbtGreen + dupimage[i][j - 1].rgbtGreen + dupimage[i + 1][j - 1].rgbtGreen) / 4);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i + 1][j].rgbtBlue + dupimage[i][j - 1].rgbtBlue + dupimage[i + 1][j - 1].rgbtBlue) / 4);
                }
                else 
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i][j - 1].rgbtRed + dupimage[i][j + 1].rgbtRed + dupimage[i + 1][j - 1].rgbtRed + dupimage[i + 1][j].rgbtRed + dupimage[i + 1][j + 1].rgbtRed) / 6);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i][j - 1].rgbtGreen + dupimage[i][j + 1].rgbtGreen + dupimage[i + 1][j - 1].rgbtGreen + dupimage[i + 1][j].rgbtGreen + dupimage[i + 1][j + 1].rgbtGreen) / 6);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i][j - 1].rgbtBlue + dupimage[i][j + 1].rgbtBlue + dupimage[i + 1][j - 1].rgbtBlue + dupimage[i + 1][j].rgbtBlue + dupimage[i + 1][j + 1].rgbtBlue) / 6);
                    
                }
            }
            //To check last row
            else if (i == height - 1)
            {
                if(j == 0)
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i - 1][j].rgbtRed + dupimage[i - 1][j + 1].rgbtRed + dupimage[i][j + 1].rgbtRed) / 4);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j + 1].rgbtGreen + dupimage[i][j + 1].rgbtGreen) / 4);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j + 1].rgbtBlue + dupimage[i][j + 1].rgbtBlue) / 4);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i][j - 1].rgbtRed + dupimage[i - 1][j - 1].rgbtRed + dupimage[i - 1][j].rgbtRed) / 4);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j - 1].rgbtGreen + dupimage[i - 1][j].rgbtGreen) / 4);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j - 1].rgbtBlue + dupimage[i - 1][j].rgbtBlue) / 4);
                }
                else 
                {
                    image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i][j - 1].rgbtRed + dupimage[i - 1][j - 1].rgbtRed + dupimage[i - 1][j].rgbtRed + dupimage[i - 1][j + 1].rgbtRed + dupimage[i][j + 1].rgbtRed) / 6);
                    image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i][j - 1].rgbtGreen + dupimage[i - 1][j - 1].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j + 1].rgbtGreen + dupimage[i][j + 1].rgbtGreen) / 6);
                    image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i][j - 1].rgbtBlue + dupimage[i - 1][j - 1].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j + 1].rgbtBlue + dupimage[i][j + 1].rgbtBlue) / 6);
                    
                }
            }
            //To check first column
            else if (j == 0 && i > 0 && i < height - 2)
            {
                image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i - 1][j].rgbtRed + dupimage[i - 1][j + 1].rgbtRed + dupimage[i][j + 1].rgbtRed + dupimage[i + 1][j + 1].rgbtRed + dupimage[i + 1][j].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j + 1].rgbtGreen + dupimage[i][j + 1].rgbtGreen + dupimage[i + 1][j + 1].rgbtGreen + dupimage[i + 1][j].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j + 1].rgbtBlue + dupimage[i][j + 1].rgbtBlue + dupimage[i + 1][j + 1].rgbtBlue + dupimage[i + 1][j].rgbtBlue) / 6);
            }
            //To check last column
            else if (j == width - 1 && i > 0 && i < height - 2)
            {
                image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i - 1][j].rgbtRed + dupimage[i - 1][j - 1].rgbtRed + dupimage[i][j - 1].rgbtRed + dupimage[i + 1][j - 1].rgbtRed + dupimage[i + 1][j].rgbtRed) / 6);
                image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j - 1].rgbtGreen + dupimage[i][j - 1].rgbtGreen + dupimage[i + 1][j - 1].rgbtGreen + dupimage[i + 1][j].rgbtGreen) / 6);
                image[i][j].rgbtBlue = round((float)(dupimage[i][j].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j - 1].rgbtBlue + dupimage[i][j - 1].rgbtBlue + dupimage[i + 1][j - 1].rgbtBlue + dupimage[i + 1][j].rgbtBlue) / 6);
            }
            //For middle pixels
            else
            {
                image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtRed + dupimage[i - 1][j - 1].rgbtRed + dupimage[i - 1][j].rgbtRed + dupimage[i - 1][j + 1].rgbtRed + dupimage[i][j + 1].rgbtRed + dupimage[i + 1][j + 1].rgbtRed + dupimage[i + 1][j].rgbtRed + dupimage[i + 1][j - 1].rgbtRed + dupimage[i][j - 1].rgbtRed) / 9);
                image[i][j].rgbtGreen = round((float)(dupimage[i][j].rgbtGreen + dupimage[i - 1][j - 1].rgbtGreen + dupimage[i - 1][j].rgbtGreen + dupimage[i - 1][j + 1].rgbtGreen + dupimage[i][j + 1].rgbtGreen + dupimage[i + 1][j + 1].rgbtGreen + dupimage[i + 1][j].rgbtGreen + dupimage[i + 1][j - 1].rgbtGreen + dupimage[i][j - 1].rgbtGreen) / 9);
                image[i][j].rgbtRed = round((float)(dupimage[i][j].rgbtBlue +dupimage[i - 1][j - 1].rgbtBlue + dupimage[i - 1][j].rgbtBlue + dupimage[i - 1][j + 1].rgbtBlue + dupimage[i][j + 1].rgbtBlue + dupimage[i + 1][j + 1].rgbtBlue + dupimage[i + 1][j].rgbtBlue + dupimage[i + 1][j - 1].rgbtBlue + dupimage[i][j - 1].rgbtBlue) / 9);
               
            }
        }
        
    }    
    
    return;
}
