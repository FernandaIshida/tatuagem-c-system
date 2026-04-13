#ifndef MODEL_H
#define MODEL_H

/*
========================================
Data Model

Defines the core structure used in the system.
========================================
*/

typedef struct
{
    char cliente[50];
    char data[11];
    char servico[30];
    float valor;
} Atendimento;

int loadCSV(Atendimento a[], int max);

void printReport(Atendimento a[], int n);
void exportSummaryCSV(Atendimento a[], int n);

void calculateStats(Atendimento a[], int n);
void calculateProbability(Atendimento a[], int n);
void showInsights(Atendimento a[], int n);

int getRange(float value);

#endif