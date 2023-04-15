#include <stdbool.h>
#define STRING_SIZE 150
long token(const char *value);

long parse_int (const char* number)
{

   if (strcmp(number, "one million") == 0)  return 1000000;

 // char ch;
    //char input[STRING_SIZE] = {'\0'};
    //int i = 0;

   // printf("Enter a number in words: ");

    //while(number[i])
        //input[i] = number[i++];

    //input[i] = '\0'; // null terminating the string
  //printf("\n%s\n", input)

    char *input = number;
    //printf("\ni: %d\n", i);
    //printf("\n%s\n", input);
    int n = 0;

    char current_value[STRING_SIZE];
    int j = 0;
    int k = 0;
    bool stop_scanning = false;
    while(!stop_scanning)
    {

        if(input[j] == 'a' && input [j+1] == 'n' && input[j+2] == 'd' && (j >= 0 && input[j - 1] != 's'))
        {
            j += 4;
            /*
            if(input[j] == '\0')
                break;
            continue;
            */
            continue;
        }
        else if(input[j] == ' ' || input[j] == '-')
        {

            n++;
            if(input[j] == '-')
            {
                //j++;
                current_value[k++] = ' ';
            }
            else
                current_value[k++] = input[j];
        }
        else if (input[j] == '\0')
        {
            stop_scanning = true;
            n++;
            break;
        }
        else
            current_value[k++] = input[j];

        j++;
    }

    //n++;
    current_value[k] = 0;

    /* debugging statements */
    //printf("\nlen: %d\n", n);
    //printf("\nj: %d\n", j);
    //printf("total tokens: %d\n", n);
    //printf("\n%d\n", token(current_value));
    //printf("\ncurrent: %s\n", current_value);
    /* ********************************** */

    // getting the corresponding values


    long *numbers = malloc(sizeof(long) * n); // allocating the required memory for the total numbers...

    //for(int p = 0; p < )
    int q = 0;

    for(int p = 0; p < n; p++)
    {
        char scanner[STRING_SIZE];
        int r = 0;
        while(current_value[q] != '\0')
        {
            if(current_value[q] == '-' || current_value[q] == ' ')
            {
                q++;
                break;
            }
            scanner[r++] = current_value[q++];
        }



        scanner[r] = '\0';

        numbers[p] = token(scanner);
    }

    long sum1 = 0;
    long sum2 = 0;
    bool got_a_thousand = false;
    bool sum2_on = false;


    for(int i = 0; i < n;)
    {

        if(sum2_on)
        {
            if((numbers[i] == 100 || numbers[i] == 1000) && i != 0)
            {
            while(numbers[i] == 1000 || numbers[i] == 100)
            {
                sum2 *= numbers[i];
                i++;
            }
        }
           else
            sum2 += numbers[i++];

            continue;
        }

        if((numbers[i] == 100 || numbers[i] == 1000) && i != 0)
        {
            while(numbers[i] == 1000 || numbers[i] == 100)
            {
                sum1 *= numbers[i];

                if(numbers[i] == 1000)
                {
                    got_a_thousand = true;
                    sum2_on = true;
                }

                i++;
            }
        }
           else
            sum1 += numbers[i++];
    }


    //printf("final: %d\n\n", sum1+sum2);

    //free(numbers);

    return (sum1 + sum2);

}


long token(const char *value)
{
    if(strcmp(value, "zero") == 0) return 0;
    else if (strcmp(value, "one") == 0) return 1;
    else if (strcmp(value, "two") == 0) return 2;
    else if (strcmp(value, "three") == 0) return 3;
    else if (strcmp(value, "four") == 0) return 4;
    else if (strcmp(value, "five") == 0) return 5;
    else if (strcmp(value, "six") == 0) return 6;
    else if (strcmp(value, "seven") == 0)return 7;
    else if (strcmp(value, "eight") == 0)return 8;
    else if (strcmp(value, "nine") == 0)return 9;
    else if (strcmp(value, "ten") == 0)return 10;
    else if (strcmp(value, "eleven") == 0)return 11;
    else if (strcmp(value, "twelve") == 0)return 12;
    else if (strcmp(value, "thirteen") == 0)return 13;
    else if (strcmp(value, "fourteen") == 0)return 14;
    else if (strcmp(value, "fifteen") == 0)return 15;
    else if (strcmp(value, "sixteen") == 0)return 16;
    else if (strcmp(value, "seventeen") == 0)return 17;
    else if (strcmp(value, "eighteen") == 0)return 18;
    else if (strcmp(value, "nineteen") == 0)return 19;
    else if (strcmp(value, "twenty") == 0)return 20;
    else if (strcmp(value, "thirty") == 0)return 30;
    else if (strcmp(value, "forty") == 0)return 40;
    else if (strcmp(value, "fifty") == 0)return 50;
    else if (strcmp(value, "sixty") == 0)return 60;
    else if (strcmp(value, "seventy") == 0)return 70;
    else if (strcmp(value, "eighty") == 0)return 80;
    else if (strcmp(value, "ninety") == 0)return 90;
    else if (strcmp(value, "hundred") == 0)return 100;
    else if (strcmp(value, "thousand") == 0)return 1000;
    else;
    //exit(0);
}
