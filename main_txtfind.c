#include <stdio.h>
#include "txtfind.h"
#define WORD 30
#define LINE 256
#define ONE 1

int main()
{   
    char _chosen_word[WORD] = {0};
    char tmp;
    int i = 0;
    while((scanf("%c",&tmp) == 1) && i < WORD)
    {
        if(tmp != ' ')
        {
            _chosen_word[i] = tmp;
            ++i;
        }
        else
        {
            break;
        }      
    }
    scanf("%c", &tmp);
    if(tmp == 'a')
    {
        getchar(); // \n in the first row
        getchar();// \n in the second row
        print_lines(_chosen_word);
    }
    else if(tmp == 'b')
    {
        getchar(); // \n in the first row
        getchar();// \n in the second row
        print_similar_words(_chosen_word);
    }
    return 0;
}