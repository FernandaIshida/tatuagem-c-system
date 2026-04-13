#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

int readCSV(Atendimento a[], int max)
{

    FILE *file = fopen("data/atendimentos_tattoo_jan_mar_2026.csv", "r");
    if (!file)
        return 0;

    char linha[200];
    int count = 0;

    fgets(linha, sizeof(linha), file); // cabeçalho

    while (fgets(linha, sizeof(linha), file) && count < max)
    {

        char *token;

        token = strtok(linha, ",");
        strcpy(a[count].cliente, token);

        token = strtok(NULL, ",");
        strcpy(a[count].data, token);

        token = strtok(NULL, ",");
        strcpy(a[count].servico, token);

        token = strtok(NULL, ",");
        a[count].valor = atof(token);

        count++;
    }

    fclose(file);
    return count;
}

void report(Atendimento a[], int n)
{

    float total = 0;

    for (int i = 0; i < n; i++)
    {
        total += a[i].valor;
    }

    printf("\n=== RELATORIO ===\n");
    printf("Total: %d\n", n);
    printf("Faturamento: %.2f\n", total);
    printf("Media: %.2f\n", total / n);
}

int main()
{

    Atendimento dados[100];

    int n = readCSV(dados, 100);

    printf("=== ATENDIMENTOS ===\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s | %s | %s | %.2f\n",
               dados[i].cliente,
               dados[i].data,
               dados[i].servico,
               dados[i].valor);
    }

    report(dados, n);

    return 0;
}