#include <stdio.h>
#include <stdlib.h>

int main(){

    char input = 0;
    int sair = 0;
    int opcao = 0;
    int num = 0;
    int quant = 0;
    int aux = 0;

    printf("\n");
    //printf("\nPressione ENTER para iniciar o jogo....");
    while(!sair)
    {
        printf("\nPressione ENTER para iniciar o jogo....");
        scanf("%c",&input);
        if(input == 0x0A){
            printf("\n");            
            break;
        }

    }

    sair = 0;
    printf("\n#########################\n");
    printf("\n###### MENTALISTA #######\n");
    printf("\n#########################\n");

    //gerando número aleatório entre 1 e 100
    num = rand() % 100;
    
    while(!sair)
    {
        if(quant == 0)
            printf("\nChute um numero entre 1 e 100\n");
        printf("\nResposta : ");
        scanf("%d",&opcao);
        printf("\n");

        if(opcao < num)
        {
            printf("\nO numero que esta na minha mente eh MAIOR que %d , tente novamente\n",opcao);
            quant++;
        }    
        else if(opcao > num)
        {
           printf("\nO numero que esta na minha mente eh MENOR que %d , tente novamente\n",opcao);
           quant++;     
        }   
        else  
        {          
            printf("\nParabens!!! Voce acertou o numero era : %d !!!\n", num);
            printf("\nO seu numero de tentativas foi de : %d\n", quant);

            printf("\nDeseja jogar novamente ? Digite 1 para sim e outro numero para sair : \n");
            scanf("%d",&aux);

            if(aux == 1)
            {
                opcao = 0; 
                quant = 0;
                aux = 0;
                system("cls");
            }

            else
            {
                printf("\nTem certeza que deseja SAIR ? Digite 0 . Caso deseje retornar digite outro numero : ");
                scanf("%d",&aux);

                if(aux == 0)
                {
                    printf("\nFim de jogo...\n");
                    sair = 1;
                }
                else
                {
                    quant = 0;
                    aux = 0;             
                    system("cls");
                }
            }
            
            
        }
        
    }
}