#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

/*
========================================
CSV Reader Module

Responsible for loading and parsing
service data from CSV files.
========================================
*/

int loadCSV(Atendimento a[], int max)
{

    FILE *file = fopen("data/atendimentos_tattoo_jan_mar_2026.csv", "r");

    if (!file)
    {
        printf("Error opening CSV file\n");
        return 0;
    }

    char linha[200];
    int count = 0;

    fgets(linha, sizeof(linha), file); // ignore header

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