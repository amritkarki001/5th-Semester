#include <stdio.h>
#include <string.h>

int min3(int a, int b, int c) {
    int min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return min;
}

int stringeditDP(char *str1 , char *str2, int m, int n) {
    int table[m+1][n+1];
    int i, j;

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0) {
                table[i][j] = j;
            }
            else if(j == 0) {
                table[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1];
            }
            else {
                table[i][j] = 1 + min3(table[i][j-1], table[i-1][j], table[i-1][j-1]);
            }
        }
    }

    return table[m][n];
}

int main() {
    char str1[] = "cart";
    char str2[] = "march";
    int m = strlen(str1);
    int n = strlen(str2);
    int r = stringeditDP(str1, str2, m, n);
    printf("\nMin Operations: %d\n", r);
    return 0;
}
