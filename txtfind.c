#include "txtfind.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define LINES 250
int getLine(char s[])
{
    int countChars = 0;

    char input;

    while ((input = getchar()) != '\n' && input != EOF && countChars < LINE)
    {

        s[countChars] = input;

        countChars++;
    }
    if (input != EOF)
    {
        s[countChars] = '\0';
    }
    return countChars;
}

//Done!
int getword(char w[])
{
    memset(w,0,30);
    int countChars = 0;
    char input;
    do
    {
        input = getchar();
        //printf("%c\n",input);
        switch (input)
        {
        case ' ':
            if(countChars > 0)
            {
                w[countChars] = '\0';
            }
            return countChars;
        case '\t':
            if(countChars > 0)
            {
                w[countChars] = '\0';
            }
            return countChars;
        case '\n':           
            if(countChars > 0)
            {
                w[countChars] = '\0';
            }
            return countChars;
        case EOF:
            if(countChars > 0)
            {
                w[countChars] = '\0';
                return countChars;
            }else
            {
                return -1;
            }
            
        default:           
            w[countChars] = input;
            ++countChars;
        }
    } while (input != EOF && countChars < WORD);

    // if ((input == EOF || input == ' ' || input == '\t' || input == '\n') && countChars > 0)
    // {
    //     w[countChars] = '\0';
    //     return countChars;
    // }
    // else if ((input == EOF) && (countChars == 0))
    // {
    //     return -1;
    // }
    // while (((input = getchar()) != '\n') && (input != EOF) && (input != '\t') && (input != ' '))
    // {
    //     w[countChars] = input;
    //     countChars++;
    // }
    // //printf("Before: %s\n", w);
    // if (input != EOF)
    // {
    //     w[countChars] = '\0';
    // }
    // // else if (input == EOF && countChars == 0)
    // // {
    // //     countChars = -1;
    // // }
    // //printf("%s\n", w);
    // //printf("%d\n",countChars);
    return countChars;
}

//Check if str2 c= str1
//Done!
int substring(char *str1, char *str2)
{
    int ans = 0, equals = 1;
    for (int i = 0; str1[i] != '\0'; ++i)
    {
        if (str1[i] == str2[0])
        {
            for (int j = 0; str2[j] != '\0'; ++j)
            {
                if (str1[i + j] != str2[j])
                {
                    equals = 0;
                    break;
                }
            }
            if (equals == 1)
            {
                ans = 1;
                break;
            }
            else
            {
                equals = 1;
            }
        }
    }
    return ans;
}

int similar(char *s, char *t, int n)
{

    int len1 = strlen(s), len2 = strlen(t);

    if (len1 < len2)
    {

        return 0;
    }

    else if (len1 - n != len2)
    {

        return 0;
    }

    char *p1 = s, *p2 = t;

    while (*p1 != '\0')
    {

        if (*p1 == *p2)
        {

            p1++;

            p2++;
        }

        else
        {

            p1++;

            n--;
        }
    }

    return n == 0;
}

void print_lines(char *str)
{
    char buff[LINE] = {0};
    int tmp = 0;
    int counter = 0;
    while (counter < LINES)
    {
        if ((tmp = getLine(buff)) > 0)
        {

            if (substring(buff, str) == 1)
            {
                for (int i = 0; i < tmp; ++i)
                {
                    printf("%c", buff[i]);
                }
                printf("\n");
            }
        }
        ++counter;
    }
}

void print_similar_words(char *str)
{
    char buff[WORD] = {0}; //WORD+1
    int tmp = 0;
    while ((tmp = getword(buff)) != -1)
    { 
        if (tmp > 0)
        {
            
            if (similar(buff, str, 0) == 1 || similar(buff, str, 1) == 1)
            {
                for (int i = 0; i < tmp; ++i)
                {
                    printf("%c", buff[i]);
                }
                printf("\n");
            }
        }

    }
}