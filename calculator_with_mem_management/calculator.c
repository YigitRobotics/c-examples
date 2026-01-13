#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../defines/colors.h"

struct values {
    long long num1;
    long long num2;
    char operation[9];
};

struct values g_values;

void add() {
    printf(ANSI_COLOR_BLUE "Enter 2 numbers: ");
    scanf("%lld %lld", &g_values.num1, &g_values.num2);
    
    long long *result = malloc(sizeof(long long));

    if (!result) {
        printf(ANSI_COLOR_RED "malloc error!");
        exit(EXIT_FAILURE);
    }

    *result = g_values.num1 + g_values.num2;
    printf(ANSI_COLOR_CYAN "memory address: ");
    printf(ANSI_COLOR_MAGENTA "%p", result);
    printf(ANSI_COLOR_CYAN "%s", "\nvalue: ");
    printf(ANSI_COLOR_MAGENTA "%lld", *result);
    free(result);
    result = NULL; // The code is protected against use-after-free vulnerabilities.
}

void subtract() {
    printf(ANSI_COLOR_BLUE "Enter 2 numbers: ");
    scanf("%lld %lld", &g_values.num1, &g_values.num2);
    
    long long *result = malloc(sizeof(long long));

    if (!result) {
        printf(ANSI_COLOR_RED "malloc error!");
        exit(EXIT_FAILURE);
    }

    *result = g_values.num1 - g_values.num2;
    printf(ANSI_COLOR_CYAN "memory address: ");
    printf(ANSI_COLOR_MAGENTA "%p", result);
    printf(ANSI_COLOR_CYAN "%s", "\nvalue: ");
    printf(ANSI_COLOR_MAGENTA "%lld", *result);
    free(result);
    result = NULL; // The code is protected against use-after-free vulnerabilities.
}

void multiply() {
    printf(ANSI_COLOR_BLUE "Enter 2 numbers: ");
    scanf("%lld %lld", &g_values.num1, &g_values.num2);
    
    long long *result = malloc(sizeof(long long));

    if (!result) {
        printf(ANSI_COLOR_RED "malloc error!");
        exit(EXIT_FAILURE);
    }

    *result = g_values.num1 * g_values.num2;
    printf(ANSI_COLOR_CYAN "memory address: ");
    printf(ANSI_COLOR_MAGENTA "%p", result);
    printf(ANSI_COLOR_CYAN "%s", "\nvalue: ");
    printf(ANSI_COLOR_MAGENTA "%lld", *result);
    free(result);
    result = NULL; // The code is protected against use-after-free vulnerabilities.
}

void divide() {
    printf(ANSI_COLOR_BLUE "Enter 2 numbers: ");
    scanf("%lld %lld", &g_values.num1, &g_values.num2);

    if (g_values.num2 == 0) {
        printf(ANSI_COLOR_RED "Division by zero!");
        return;
    }
    
    long long *result = malloc(sizeof(long long));

    if (!result) {
        printf(ANSI_COLOR_RED "malloc error!");
        return;
    }

    *result = g_values.num1 / g_values.num2;
    printf(ANSI_COLOR_CYAN "memory address: ");
    printf(ANSI_COLOR_MAGENTA "%p", result);
    printf(ANSI_COLOR_CYAN "%s", "\nvalue ");
    printf(ANSI_COLOR_MAGENTA "%lld", *result);
    free(result);
    result = NULL; // The code is protected against use-after-free vulnerabilities.
}

int main() {
    int res_subtr;
    int restop;
    int res_div;
    int res_mult;

    printf("Select any operation: ");
    scanf("%9s", g_values.operation);

    res_subtr = strcmp(g_values.operation, "subtract");
    restop = strcmp(g_values.operation, "add");
    res_mult = strcmp(g_values.operation, "multiply");
    res_div = strcmp(g_values.operation, "divide");

    if (res_subtr == 0) {
        subtract();
    }
    if (res_div == 0) {
        divide();
    }
    if (restop == 0) {
        add();
    }
    if (res_mult == 0) {
        multiply();
    }
    return 0;
}