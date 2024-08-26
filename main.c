/**

 * Criado em 25 de Agosto 2024
 * Autor: Luan Kato
 * Questão 1 - 25/08/2024 02:05
 * Questão 2 - 26/08/2024 11:57

**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

void binario(int decimal);
void octal(int decimal);
void hexadecimal(int decimal);
void BCD(int decimal);
void complemento_a2(int numero);

int main()
{
    int numero, caso, escolha;
    int numero_real;

    while (caso != 0)
    {
        printf("Bem vindo a Calculadora de Conversao!\n\n");
        printf("Alternativas de Conversao Disponiveis:\n[1] - Binario, Octal, Hexadecimal e BCD\n[2] - Complemento a 2 (16bits)\n");
        printf("[3] - Float e Double\n");
        printf("Escolha uma alternativa: ");
        scanf("%d", &caso);
        printf("\n");
        Sleep(500);
        if (caso == 1)
        {
            printf("Escolha o tipo de Conversao Desejada:\n[0] - Binario\n[1] - Octal\n[2] - Hexadecimal\n[3] - BCD\n");

            printf("Insira a opcao: ");
            scanf("%d", &escolha);
            Sleep(500);

            if (escolha == 0)
            {
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                binario(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 1)
            {
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                octal(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 2)
            {
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                hexadecimal(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 3)
            {
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                BCD(numero);

                printf("Obrigado!");
                break;
            }
        }
        if (caso == 2)
        {
            printf("Insira um numero inteiro de base 10: ");
            scanf("%d", &numero_real);
            Sleep(500);
            complemento_a2(numero_real);

            printf("Obrigado!");
            break;
        }
        if (caso == 3)
        {
            printf("Trabalhando nisso!");
            Sleep(500);
            break;
        }
    }

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
            Sleep(500);
        }

        Sleep(500);
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

    Sleep(500);
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
            Sleep(500);
        }
        Sleep(500);
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
            Sleep(500);
        }
        Sleep(500);
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
            Sleep(500);
        }
        Sleep(500);
        printf("BCD: ");
        for (int i = indice * 4 - 1; i >= 0; i--)
        {
            printf("%d", resultado[i]);
        }
        printf("\n\n");
    }
}

void complemento_a2(int numero)
{
    char resultado[16];
    int indice = 0;

    if (numero == 0)
    {
        printf("Complemento a 2 de 0 = 0");
    }
    if (numero > 0)
    {
        printf("Convertendo %d para Binario:\n", numero);
        while (numero > 0)
        {
            printf("Decimal: %d, Decimal %% 2 = %d\n", numero, numero % 2);
            resultado[indice] = numero % 2 + '0';
            indice++;
            numero /= 2;
            Sleep(500);
        }

        Sleep(500);
        printf("\nBinario sem Complemento a 2: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", resultado[i]);
        }
        printf("\n");

        Sleep(500);

        printf("\nBinario em Complemento a 1:\n");
        for (int i = 0; i < indice; i++)
        {
            if (resultado[i] == '0')
            {
                resultado[i] = '1';
            }
            else
            {
                resultado[i] = '0';
            }
            printf("Complemento a 1 passo %d: %c\n", i + 1, resultado[i]);
        }

        Sleep(500);
        // Mostrando Resultado do Complemento a 1
        printf("\nResultado em Complemento a 1: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", resultado[i]);
        }
        printf("\n");

        Sleep(500);

        printf("\nIniciando Complemento a 2 ->\n");
        Sleep(500);

        int carry = 1;
        for (int i = 0; i < indice; i++)
        {
            if (resultado[i] == '1' && carry == 1)
            {
                resultado[i] = '0';
            }
            else if (resultado[i] == '0' && carry == 1)
            {
                resultado[i] = '1';
                carry = 0;
            }
            printf("Complemento a 2 passo %d: %c\n", i + 1, resultado[i]);
            Sleep(500);
        }

        if (carry == 1)
        {
            resultado[indice] = '1';
            indice++;
        }

        Sleep(500);

        printf("\nBinario com Complemento a 2: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", resultado[i]);
        }
    }
    printf("\n\n");
}
