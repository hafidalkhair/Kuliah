#include <stdio.h>
#include <conio.h>

int main() {
	int i, j;
	
	static int A[8][8] = {
		{0, 1, 1, 1, 1, 1, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 0, 0, 0, 0, 1, 0},
		{1, 1, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 8; j++) {
			if (A[i][j]) {
				putchar('\xDB');
			} else {
				putchar(' ');
			}
		}
		puts("");
	}
	getch();
}

