#include <stdio.h>
#include "model.h"

/*
========================================
Report Module

Responsible for displaying formatted
service records in the console.
========================================
*/

void printReport(Atendimento a[], int n)
{

    printf("\n=== ATTENDANCE LIST ===\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s | %s | %s | %.2f\n",
               a[i].cliente,
               a[i].data,
               a[i].servico,
               a[i].valor);
    }
}

/* =========================
   Export for Excel (CSV)
========================= */
void exportSummaryCSV(Atendimento a[], int n)
{

    FILE *file = fopen("analysis.csv", "w");

    if (!file)
    {
        printf("Error creating export file\n");
        return;
    }

    fprintf(file, "range,count\n");

    int low = 0, medium = 0, high = 0;

    for (int i = 0; i < n; i++)
    {

        int r = getRange(a[i].valor);

        if (r == 0)
            low++;
        else if (r == 1)
            medium++;
        else
            high++;
    }

    fprintf(file, "Low,%d\n", low);
    fprintf(file, "Medium,%d\n", medium);
    fprintf(file, "High,%d\n", high);

    fclose(file);

    printf("\nCSV export created: analysis.csv\n");
}