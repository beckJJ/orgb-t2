#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);
    for (int i = 2; i <= n; i++) {
        int d = 0;
        for (int j = 1; j <= i; j++) {
            if (!(i % j)) {
                d++;
            }
        }
        if (d == 2) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}