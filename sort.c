// Programa que gera um vetor "aleatório" e ordena-o com shellsort e sequencia de knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void inicia_knuth(int *h, int *exp, int tam_vec)
{
    int i = 0;

    while (*h <= tam_vec) {
        *h += pow(3, i);
        i++;
    }
    *exp = i-1;
}

int atualiza_knuth(int exp)
{
    int i, inc = 0;
    for (i = 0; i <= exp; i++) {
        inc += pow(3, i);
    }
    return inc;
}

/* Funcao para realizar a ordenacao por Shellsort, com base na sequencia de Knuth. */
void shellsort_knuth(int *vec, int tam_vec)
{
    int h = 0, h_inicial, expoente = 0;
    inicia_knuth(&h, &expoente, tam_vec);
    h_inicial = h;
    while (h > 0) {
        for (int i = h; i < tam_vec; i++) {
            int aux = vec[i];

            int j;
            for (j = i - h; ((j >= 0) && (vec[j] > aux)); j -= h) {
                vec[j+h] = vec[j];
            }
            vec[j+h] = aux;
        }
        expoente--;

        h = atualiza_knuth(expoente); 
    }
}


int main(int argc, char *argv[])
{
    if (!argv[1]) {
        return 1;
    }
    int tam_vec = atoi(argv[1]);
    int *vec = calloc(tam_vec,sizeof(int));

    srand(0xdeadbeef); // usar sempre a mesma seed
    for (int i = 0; i < tam_vec; i++) {
        vec[i] = rand();
        printf("%d ", vec[i]);
    }
    printf("\n\n");

    shellsort_knuth(vec, tam_vec);

    for (int i = 0; i < tam_vec; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
    return 0;
}