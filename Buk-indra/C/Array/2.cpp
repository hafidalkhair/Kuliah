#include <stdio.h>

int main()
{
    int i, j, k;
    static int data_huruf[2][8][8] = {
        {{0, 1, 1, 1, 1, 1, 0, 0},
         {0, 1, 0, 0, 0, 1, 0, 0},
         {1, 1, 1, 1, 1, 1, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}},

        {{1, 0, 0, 0, 0, 1, 0, 0},
         {1, 1, 1, 1, 1, 1, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {1, 1, 0, 0, 0, 0, 1, 0},
         {1, 1, 1, 1, 1, 1, 1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}}
    };

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 8; k++)
            {
                if (data_huruf[i][j][k])
                    putchar('\xDB');
                else
                    putchar(' '); // Menambahkan spasi di sini
            }
            puts(""); // Menambahkan baris baru di sini
        }
        puts("");
    }

    return 0; // Mengganti getch() dengan return 0
}

