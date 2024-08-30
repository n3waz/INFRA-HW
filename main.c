/**

 * Criado em 25 de Agosto 2024
 * Autor: Luan Kato
 * Questão 1 - 25/08/2024 02:05
 * Questão 2 - 26/08/2024 11:57
 * Questão 3 - 29/08/2024 22:15

**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>

typedef union
{
    float Float;
    uint32_t bits;
} FloatUnion;

typedef union
{
    double Double;
    uint64_t bits;
} DoubleUnion;

void binario(int decimal);
void octal(int decimal);
void hexadecimal(int decimal);
void BCD(int decimal);

void complemento_a2(int numero);

void imprimir_formatado(uint64_t valor, int bits, int posicao_espacos[], int cont_espacos);
void imprimir_bits_float(float num);
void imprimir_bits_double(double num);

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

                Sleep(500);
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

                Sleep(500);
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

                Sleep(500);
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

                Sleep(500);
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

            Sleep(500);
            printf("Obrigado!");
            break;
        }
        if (caso == 3)
        {
            float float_flutuante;
            double double_flutuante;

            printf("Digite um valor Float: ");
            scanf("%f", &float_flutuante);
            printf("Digite um valor Double: ");
            scanf("%lf", &double_flutuante);

            Sleep(500);
            imprimir_bits_float(float_flutuante);

            Sleep(500);
            imprimir_bits_double(double_flutuante);

            Sleep(500);
            printf("Obrigado!");
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

void imprimir_formatado(uint64_t valor, int bits, int posicao_espacos[], int cont_espacos)
{
    int espaco_atual = 0;
    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (valor >> i) & 1);
        if (espaco_atual < cont_espacos && (bits - 1) == posicao_espacos[espaco_atual])
        {
            printf(" ");
            espaco_atual++;
        }
    }
}

void imprimir_bits_float(float num)
{
    FloatUnion unifloat;
    unifloat.Float = num;

    uint32_t sinal = (unifloat.bits >> 31) & 1;
    uint32_t expoente = (unifloat.bits >> 23) & 0xFF;
    uint32_t fracao = unifloat.bits & 0x7FFFFF;
    int32_t vies_expoente = expoente - 127;

    printf("\nNumero Float: %f\n", num);

    printf("\nConvertendo para Binario...\n\n");
    Sleep(500);

    printf("Bits: ");
    int posicoes_espaco[] = {1, 9};
    imprimir_formatado(unifloat.bits, 32, posicoes_espaco, 2);

    printf("\nVerificando se eh positivo ou negativo...\n\n");
    Sleep(500);

    printf("\nSinal: %u\n", sinal);

    printf("\nCalculando Expoente...\n\n");
    Sleep(500);

    printf("Expoente: ");
    imprimir_formatado(expoente, 8, NULL, 0);
    printf("\nExpoente com vies: %d\n", vies_expoente);

    printf("\nValor Flutuante completo...\n\n");
    Sleep(500);

    printf("Fracao: ");
    imprimir_formatado(fracao, 23, NULL, 0);
    printf("\n\n");
}

void imprimir_bits_double(double num)
{
    DoubleUnion unidouble;
    unidouble.Double = num;

    uint64_t sinal = (unidouble.bits >> 63) & 1;
    uint64_t expoente = (unidouble.bits >> 52) & 0xFF;
    uint64_t fracao = unidouble.bits & 0xFFFFFFFFFFFFF;
    uint32_t vies_expoente = expoente - 1021;

    Sleep(500);

    printf("\nNumeroDouble: %lf\n", num);

    printf("\nConvertendo para Binario...\n\n");
    Sleep(500);

    printf("Bits: ");
    int posicoes_espacos[] = {1, 12};
    imprimir_formatado(unidouble.bits, 64, posicoes_espacos, 2);

    printf("\nVerificando se eh positivo ou negativo...\n\n");
    Sleep(500);

    printf("\nSinal: %llf\n", sinal);

    printf("\nCalculando Expoente...\n\n");
    Sleep(500);

    printf("Expoente: ");
    imprimir_formatado(expoente, 11, NULL, 0);
    printf("\nExpoente com Vies: %d\n", vies_expoente);

    printf("\nValor Flutuante completo...\n\n");
    Sleep(500);

    printf("Fracao: ");
    imprimir_formatado(fracao, 52, NULL, 0);
    printf("\n\n");
}