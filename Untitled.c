#include <stdio.h>

int main() {
    printf("Введите число a:\n");
    float a = 0, b = 0, c = 0;
    while (scanf ("%f", &a) != 1 || scanf ("%f", &b) != 1 || scanf ("%f", &c) != 1) {
        printf("Введенное не число. Вводите заново: ");
        while(getchar() != '\n');
    }
}
