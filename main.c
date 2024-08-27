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
void ponto_flutuante(double numero);

int main()
{
    int caso, escolha;

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
                int numero;
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                binario(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 1)
            {
                int numero;
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                octal(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 2)
            {
                int numero;
                printf("Insira um numero inteiro natural de base 10: ");
                scanf("%d", &numero);
                Sleep(500);
                hexadecimal(numero);

                printf("Obrigado!");
                break;
            }
            if (escolha == 3)
            {
                int numero;
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
            int numero;
            printf("Insira um numero inteiro de base 10: ");
            scanf("%d", &numero);
            Sleep(500);
            complemento_a2(numero);

            printf("Obrigado!");
            break;
        }
        if (caso == 3)
        {
            double numero_flutuante;
            printf("Insira um numero para ponto flutuante: ");
            scanf("%lf", &numero_flutuante);
            Sleep(500);
            ponto_flutuante(numero_flutuante);
            break;
        }
    }

    return 0;
}

void binario(int decimal)
{
    char binario[32];
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
            binario[indice] = decimal % 2;
            indice++;
            decimal /= 2;
            Sleep(500);
        }

        Sleep(500);
        printf("Binario: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%d", binario[i]);
        }
    }
    printf("\n\n");
}

void octal(int decimal)
{
    char octal[32];
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
            octal[indice] = decimal % 8;
            indice++;
            decimal /= 8;
            Sleep(500);
        }
        Sleep(500);
        printf("Octal: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%d", octal[i]);
        }
    }
    printf("\n\n");
}

void hexadecimal(int decimal)
{
    char hexadecimal[32];
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
                hexadecimal[indice] = resto + '0';
            }
            else
            {
                hexadecimal[indice] = resto + 'A' - 10;
            }
            printf("Decimal %d, Decimal %% 16 = %d, Resto em Hexadecimal: %c\n", decimal, resto, hexadecimal[indice]);
            indice++;
            decimal /= 16;
            Sleep(500);
        }
        Sleep(500);
        printf("Hexadecimal: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", hexadecimal[i]);
        }
    }
    printf("\n\n");
}

void BCD(int decimal)
{
    char bcd[32];
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
                bcd[indice * 4 + i] = (digito >> i) & 1;
            }
            indice++;
            Sleep(500);
        }
        Sleep(500);
        printf("BCD: ");
        for (int i = indice * 4 - 1; i >= 0; i--)
        {
            printf("%d", bcd[i]);
        }
        printf("\n\n");
    }
}

void complemento_a2(int numero)
{
    char comp_a2[16]; 
    int indice = 0;
    int isNegative = 0;
    int temp_num;

    if (numero == 0)
    {
        printf("Complemento a 2 de 0 = 0\n");
        return;
    }
    else if (numero < 0)
    {
        isNegative = 1;
        temp_num = -numero;
    }
    else
    {
        temp_num = numero;
    }

    printf("Convertendo %d para Binario:\n", numero);
    while (temp_num > 0)
    {
        printf("Decimal: %d, Decimal %% 2 = %d\n", temp_num, temp_num % 2);
        comp_a2[indice] = temp_num % 2 + '0';
        indice++;
        temp_num /= 2;
        Sleep(500);
    }

    // Completa os bits restantes com '0' se necessário para 16 bits
    for (int i = indice; i < 16; i++)
    {
        comp_a2[i] = '0';
    }
    indice = 16;

    printf("\nBinario sem Complemento a 2: ");
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%c", comp_a2[i]);
    }
    printf("\n");

    Sleep(500);

    // Se o número for negativo, calcular complemento a 2
    if (isNegative)
    {
        printf("\nBinario em Complemento a 1:\n");
        for (int i = 0; i < indice; i++)
        {
            if (comp_a2[i] == '0')
            {
                comp_a2[i] = '1';
            }
            else
            {
                comp_a2[i] = '0';
            }
            printf("Complemento a 1 passo %d: %c\n", i + 1, comp_a2[i]);
            Sleep(500);
        }

        Sleep(500);

        // Mostrando Resultado do Complemento a 1
        printf("\nResultado em Complemento a 1: ");
        for (int i = indice - 1; i >= 0; i--)
        {
            printf("%c", comp_a2[i]);
        }
        printf("\n");

        Sleep(500);

        printf("\nIniciando Complemento a 2 ->\n");
        Sleep(500);

        int carry = 1;
        for (int i = 0; i < indice; i++)
        {
            if (comp_a2[i] == '1' && carry == 1)
            {
                comp_a2[i] = '0';
            }
            else if (comp_a2[i] == '0' && carry == 1)
            {
                comp_a2[i] = '1';
                carry = 0;
            }
            printf("Complemento a 2 passo %d: %c\n", i + 1, comp_a2[i]);
            Sleep(500);
        }

        if (carry == 1 && indice < 16)
        {
            comp_a2[indice] = '1';
            indice++;
        }
    }

    Sleep(500);

    printf("\nBinario com Complemento a 2: ");
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%c", comp_a2[i]);
    }
    printf("\n\n");
}

void ponto_flutuante(double numero)
{
    double parte_decimal, parte_inteira;
    int inteiro = (int)parte_inteira;
    int binario[32];
    int i = 0;
    int digitos = 0;

    parte_decimal = modf(numero, &parte_inteira); // Separador da parte Inteira e Decimal

    printf("Convertendo %.0f para Binario: \n", parte_inteira);
    Sleep(500);

    if (inteiro == 0)
    {
        printf("0");
        return;
    }

    while (inteiro > 0)
    {
        printf("Decimal: %d, Decimal %% 2 = %d\n", inteiro, inteiro % 2);
        binario[i] = inteiro % 2;
        inteiro = inteiro / 2;
        i++;
    }

    Sleep(500);
    printf("Binario: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binario[j]);
    }
    printf("\nConvertendo a Parte Fracionaria: \n");
    Sleep(500);

    while (parte_decimal != 0 && digitos < 16)
    {
        parte_decimal *= 10;
        parte_decimal = modf(parte_decimal, &parte_inteira);
        digitos++;
    }

    char formato[10];
    snprintf(formato, sizeof(formato), "%%.%df", digitos);

    while (parte_decimal != 0.0 && digitos-- > 0)
    {
        printf("Fracionario: ");
        printf(formato, parte_decimal);
        printf("\n");
        parte_decimal *= 2;
        if (parte_decimal >= 1)
        {
            printf("1");
            parte_decimal -= 1;
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}
