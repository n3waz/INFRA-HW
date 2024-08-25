/**

 * Criado em 25 de Agosto 2024
 * Autor: Luan Kato
 * Questão 1 - 25/08/2024 02:05

**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void binario(int decimal);
void octal(int decimal);
void hexadecimal(int decimal);
void BCD(int decimal);

int main()
{
    int numero;

    printf("Insira um numero de base 10: ");
    scanf("%d", &numero);

    binario(numero);
    octal(numero);
    hexadecimal(numero);
    BCD(numero);

    return 0;
}

void binario(int decimal)
{
    char resultado[32];
    int indice = 0;

    if (decimal == 0)
    {
        printf("Numero Binario de 0: 0\n\n");
    }
    else
    {
        printf("Convertendo %d para Binario: \n", decimal);
        while (decimal > 0)
        {
            printf("Decimal: %d, Decimal %% 2 = %d\n", decimal, decimal % 2);
            resultado[indice] = decimal % 2;
            indice++;
            decimal /= 2;
        }
        printf("Binario: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%d", resultado[i]);
        }
    }
    printf("\n\n");
}

void octal(int decimal)
{
    char resultado[32];
    int indice = 0;

    if (decimal == 0)
    {
        printf("Octal de 0: 0\n\n");
    }
    else
    {
        printf("Convertendo %d para Octal: \n", decimal);
        while (decimal > 0)
        {
            printf("Decimal: %d, Decimal %% 8 = %d\n", decimal, decimal % 8);
            resultado[indice] = decimal % 8;
            indice++;
            decimal /= 8;
        }
        printf("Octal: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%d", resultado[i]);
        }
    }
    printf("\n\n");
}

void hexadecimal(int decimal)
{
    char resultado[32];
    int indice = 0;

    if (decimal == 0)
    {
        printf("Numero Hexadecimal de 0: 0\n\n");
    }
    else
    {
        printf("Convertendo %d para Hexadecimal: \n", decimal);
        while (decimal > 0)
        {
            int resto = decimal % 16;
            if (resto < 10)
            {
                resultado[indice] = resto + '0';
            }
            else
            {
                resultado[indice] = resto + 'A' - 10;
            }
            printf("Decimal %d, Decimal %% 16 = %d, Resto em Hexadecimal: %c\n", decimal, resto, resultado[indice]);
            indice++;
            decimal /= 16;
        }
        printf("Hexadecimal: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", resultado[i]);
        }
    }
    printf("\n\n");
}

void BCD(int decimal)
{
    char resultado[32];
    int indice = 0;

    if (decimal == 0)
    {
        printf("Número Decimal de 0 em BCD: 0000\n\n");
    }
    else
    {
        printf("Convertendo %d para BCD: \n", decimal);
        while (decimal > 0)
        {
            int digito = decimal % 10;
            decimal /= 10;

            printf("Digito decimal: %d, Digito decimal %% 10 = %d\n", digito, digito);
            for (int i = 3; i >= 0; i--)
            {
                resultado[indice * 4 + i] = (digito >> i) & 1;
            }
            indice++;
        }
        printf("BCD: ");
        for (int i = indice * 4 - 1; i >= 0; i--)
        {
            printf("%d", resultado[i]);
        }
        printf("\n\n");
    }
}