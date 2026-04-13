#include <stdio.h>
#include "model.h"

int main()
{

    Atendimento dados[100];

    int n = loadCSV(dados, 100);

    if (n == 0)
    {
        printf("No data loaded.\n");
        return 1;
    }

    printReport(dados, n);

    calculateStats(dados, n);

    calculateProbability(dados, n);

    showInsights(dados, n);

    exportSummaryCSV(dados, n);

    return 0;
}