#include <stdio.h>
#include "model.h"

/*
Module: Statistics (stats.c)

Purpose:
Provides statistical analysis and insights over
tattoo studio service data loaded from CSV.

Features:
- Descriptive statistics (min, max, mean)
- Empirical probability distribution
- Business insights based on revenue patterns
*/

void calculateStats(Atendimento a[], int n)
{

    if (n == 0)
    {
        printf("No data available\n");
        return;
    }

    float sum = 0;
    float min = a[0].valor;
    float max = a[0].valor;

    for (int i = 0; i < n; i++)
    {

        sum += a[i].valor;

        if (a[i].valor < min)
            min = a[i].valor;

        if (a[i].valor > max)
            max = a[i].valor;
    }

    printf("\n=== BASIC STATISTICS ===\n");
    printf("Min value: %.2f\n", min);
    printf("Max value: %.2f\n", max);
    printf("Mean: %.2f\n", sum / n);
}

int getRange(float value)
{

    if (value <= 300)
        return 0; // low
    else if (value <= 600)
        return 1; // medium
    else
        return 2; // high
}

void calculateProbability(Atendimento a[], int n)
{

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

    printf("\n=== PROBABILITY BY RANGE ===\n");

    printf("Low (<=300): %.2f%%\n", (low * 100.0) / n);
    printf("Medium (<=600): %.2f%%\n", (medium * 100.0) / n);
    printf("High (>600): %.2f%%\n", (high * 100.0) / n);
}

void showInsights(Atendimento a[], int n)
{

    if (n == 0)
    {
        printf("No data available\n");
        return;
    }

    float sum = 0;
    float min = a[0].valor;
    float max = a[0].valor;

    int low = 0, medium = 0, high = 0;

    for (int i = 0; i < n; i++)
    {

        sum += a[i].valor;

        if (a[i].valor < min)
            min = a[i].valor;
        if (a[i].valor > max)
            max = a[i].valor;

        int r = getRange(a[i].valor);

        if (r == 0)
            low++;
        else if (r == 1)
            medium++;
        else
            high++;
    }

    float mean = sum / n;

    printf("\n====================================\n");
    printf("        BUSINESS INSIGHTS\n");
    printf("====================================\n");

    printf("Total records: %d\n", n);
    printf("Revenue range: %.2f - %.2f\n", min, max);
    printf("Average ticket: %.2f\n", mean);

    printf("\n--- Distribution by value range ---\n");
    printf("Low (<=300):     %.2f%%\n", (low * 100.0) / n);
    printf("Medium (<=600):  %.2f%%\n", (medium * 100.0) / n);
    printf("High (>600):     %.2f%%\n", (high * 100.0) / n);

    printf("\n--- Interpretation ---\n");

    if (mean > 500)
        printf("High revenue pattern detected.\n");
    else if (mean > 300)
        printf("Moderate revenue pattern detected.\n");
    else
        printf("Low revenue pattern detected.\n");

    printf("====================================\n\n");
}