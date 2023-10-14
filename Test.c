#include <stdio.h>
#include <string.h>



int main()
{
    printf("\n");

    // char a = ' ';
    // char b = ' ';
    // char c = ' ';
    // char d = ' ';

    // char arr[] = {' ', ' ', ' ', ' ', '\0'};
    // int len = strlen(arr);


    // for(int i = 0; i < len; i++)
    // {
    //     if(i == 1)
    //     {
    //         arr[i] = 'X';
    //     }
    //     if(i == 3)
    //     {
    //         arr[i] = 'O';
    //     }

    //     if (arr[i] == ' ')
    //     {
    //         printf("arr[%d] is Empty\n", i);
    //     }
        
    //     // printf("Content of arr[%d] = %c\n", i, arr[i]);
    // }

    //New code
    char num[3][4] = {{'1', '2', '3', '\0'}, {'4', '5', '6', '\0'}, {'7', '8', '9', '\0'}};
    
    // int i = 0;
    // int j = 0;
    int k = 0;
    int l = 1;
    int m = 2;
    int n = 2;
    for(int i = 0; i < 3; i++)
    {
        //run through row 1 - 3
        for(int j = 0; j < 3; j++)
        {
            // //run through row 1
            // if(i == 0)
            // {
            //     printf("num(Row 1)[%d][%d] = %c\n", i, j, num[i][j]);
            // }

            // //run through row 1
            // if(i == 1)
            // {
            //     printf("num(Row 2)[%d][%d] = %c\n", i, j, num[i][j]);
            // }

            // //run through row 1
            // if(i == 2)
            // {
            //     printf("num(Row 3)[%d][%d] = %c\n", i, j, num[i][j]);
            // }
            
        }

        //run through column 1
        // printf("num[%d][%d] = %c\n", i, k, num[i][k]);

        //run through column 2
        // printf("num[%d][%d] = %c\n", i, l, num[i][l]);  

        //run through column 3
        // printf("num[%d][%d] = %c\n", i, m, num[i][m]);  


        //run through left diagonal (top to bottom)
        // printf("num[%d][%d] = %c\n", i, i, num[i][i]);

        //run through right diagonal(top to bottom)
        printf("num[%d][%d] = %c\n", i, n, num[i][n]);

        // increment variable "n"
        n--;
    }

    // printf("Length = %d\n", len);

    // for(int i = 0; i < )
    

    return(0);
    printf("\n");
}