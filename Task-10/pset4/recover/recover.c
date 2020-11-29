#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<cs50.h>



//eliminate magic numbers
#define JAR 512

//making a struct
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Useage ./recover image name\n");
        return 1;
    }

    //filename
    char *card = argv[1];

    // open input file
    FILE *raw_data = fopen(card, "r");

    if (raw_data == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", card);
        return 2;
    }

    //buffer array
    BYTE buffer[JAR];

    //to count recovered img number
    int counter;
    counter = 0;

    //file pointer i'll be writing to
    FILE *img;

    //name of jpeg is stored in this array 000.jpg\0
    char picha[8];

    while (fread(buffer, sizeof(buffer), 1, raw_data) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                //close the already open file
                fclose(img);

                //name outfile using sprintf
                sprintf(picha, "%03d.jpg", counter);
                counter = +1;

                //open newfile for writing
                img = fopen(picha, "w");

                // Write to outfile
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            if (counter == 0)
            {
                //name outfile using sprintf
                sprintf(picha, "%03d.jpg", counter);
                counter = +1;

                //open newfile for writing
                img = fopen(picha, "w");

                // Write to outfile
                fwrite(buffer, sizeof(buffer), 1, img);
            }



        }
        else if (counter > 0)
        {

            fwrite(buffer, sizeof(buffer), 1, img);
        }


    }


    fclose(img);
    fclose(raw_data);
    //success
    return 0;

}