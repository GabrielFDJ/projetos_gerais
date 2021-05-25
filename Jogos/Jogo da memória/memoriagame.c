#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#define TAM 10

void imprime(int vetorA[10]);
void trocarvalor_imprime(int vetorA[TAM],int vetorP[TAM],int casa[], int cont);
void modifica(int modificados[TAM], int casa[2],int vetorA[TAM],int vetorP[TAM],int aux);

int main()
{
    int i, fim = 0,siga = 0,cont = 0,contgeral = 0;
    int vetorP[TAM] = {1,3,2,4,3,5,1,2,4,5};
    int vetorA[TAM];
    int modificados[TAM];
    int casa[2] = {0,0};
    int verific = -1;
    int aux;  
    

    printf("\nBem vindo ao jogo da memoria\n");
    printf("\nConsidere as posicoes de 1 a 10\n");
    for(i=0;i<TAM;i++)
    {
        vetorA[i] = 0;
        modificados[i] = 0;
        printf("%d",vetorA[i]);
        if(i<TAM-1)
            printf("-");
    }
    
    while(!fim)
    {
        while(!siga)
        {
            printf("\nQual a posicao que deseja mostrar ? \n");
            scanf("%d",&casa[cont]);
                                        
            if(casa[cont] < 1 || casa[cont] > 10)
            {                
                printf("\nPosicao invalida tente novamente");
                sleep(1);
                system("cls");
                imprime(vetorA);
                printf("\n");
                break;
            }
            else    
            {                               
                    system("cls");
                    casa[cont]--;                
                    trocarvalor_imprime(vetorA,vetorP,casa,cont);
                    cont++;
                    if(cont==2)
                    {
                        if(vetorA[casa[0]] == vetorA[casa[1]])
                        {
                            if(modificados[casa[0]] > 0 || modificados[casa[1]] > 0)
                            {            
                                modifica(modificados, casa, vetorA, vetorP, aux);                       
                                cont = 0;                 
                                printf("\nNumeros ja encontrados\n");
                                sleep(2);
                                system("cls");
                                trocarvalor_imprime(vetorA,vetorP,casa,cont);
                            }
                            else
                            {                                                         
                                modificados [casa[0]] = 1;
                                modificados [casa[1]] = 1;
                                contgeral+=cont;
                                cont = 0; 
                                printf("\nVoce acertou\n");
                                sleep(1);
                                system("cls");
                                trocarvalor_imprime(vetorA,vetorP,casa,cont);
                            }                                                   
                        }
                        else    
                        {
                            modifica(modificados, casa,vetorA,vetorP,aux);                                
                            cont = 0;
                            printf("\nVoce ERROU Tente novamente em 2 segundos");
                            sleep(2);
                            system("cls");
                            imprime(vetorA);                         
                        }
                        if(contgeral == TAM)
                        {
                            printf("\n\nParabens voce VENCEU o jogo \n by : GABRIEL FERREIRA\n");
                            fim=1;
                            break; 
                        } 
                        for(i=0;i<2;i++)
                        {                       
                            casa[i] = 0;
                        }        
                    }
            }    
        }     
    }  
        
    printf("\n");
    system("pause");
    return 0;
}
      
void imprime(int vetorA[10]){
    printf("\nBem vindo ao jogo da memoria\n");
    for(int i=0;i<TAM;i++)
    {
        printf("%d",vetorA[i]);
        if(i<TAM-1)
            printf("-");
    }

}                
               
void trocarvalor_imprime(int vetorA[TAM],int vetorP[TAM],int casa[], int cont){
    int i;
    printf("\nBem vindo ao jogo da memoria\n");
    for(i=0;i<TAM;i++)
    {
    if(i == casa[cont])
        vetorA[i] = vetorP[i];
    printf("%d",vetorA[i]);
    if(i<TAM-1)
        printf("-");
    }
}

void modifica(int modificados[TAM], int casa[2],int vetorA[TAM],int vetorP[TAM],int aux){
    if(modificados[casa[0]] > 0)
        vetorA[casa[0]] = vetorP[casa[0]]; 
    else
    {                            
        aux = casa[0];
        vetorA[aux] = 0;
    }
    if(modificados[casa[1]] > 0)
        vetorA[casa[1]] = vetorP[casa[1]];
    else
    {
        aux = casa[1];
        vetorA[aux] = 0;        
    }
}