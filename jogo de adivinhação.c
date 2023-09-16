//Clara de Lima Adriano


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int chute;
int tentativas = 0;
bool acertos = false;
int pontos = 1000;

int main()
{
    srand(time(NULL));
    int numero_certo = rand() % 100; 

    printf("----------------------------------------\n");
    printf("|       ADIVINHAÇÃO DE NÚMEROS         |\n");
    printf("----------------------------------------\n");

    while (acertos == false && tentativas < 10) 
    {
        printf("Chute um numero: ");
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Nao pode chutar numero negativo!\n");
        }
        else
        {
            tentativas++;

            if (chute == numero_certo)
            {
                printf("Voce acertou.\n");
                printf("pontos: %d\n", pontos);
                acertos = true;
            }
            else
            {
                printf("ERROU!!\n");
                if (chute < numero_certo)
                {
                    printf("Numero chutado menor\n");
                    pontos -= (numero_certo - chute) / 2;
                }
                else
                {
                    printf("Numero chutado maior\n");
                    pontos -= (chute - numero_certo) / 2;
                }
                printf("Tentativas restantes: %d\n", 10 - tentativas);
            }
        }
    }

    if (tentativas == 10 && !acertos)
    {
        printf("Voce excedeu o limite de tentativas. O numero certo era: %d\n", numero_certo);
    }

    return 0;
}
