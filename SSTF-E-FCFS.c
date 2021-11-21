/* - Trabalho de escalonamento de Disco -
   Universidade Estadual de Minas Gerais - UEMG - Passos
    Sistema de Informacao 
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//i   = variavel do loop
//j   = variavel do loop
//sum = resultado final
//n   = e cilindros que igual a 200
//pos = Cilindro inicial onde a cabeça de leitura/escrita vai iniciar
//trc = trilhas que deseja percorrer
//ind = varavel para usa no loop j
 //==============================///=======================================
void SSTF(){//função sstf

int i,j,sum=0,n,pos,trc,ind;
 n=41;
 printf("==============================SSTF=====================================\n");
 printf("Insira a posicao da cabeca:");
 scanf("%d",&pos);
 printf("Digite o numero de trilhas que deseja percorrer: ");
 scanf("%d",&trc);
 if(trc>10){
	printf(" Maximo de requisicoes: 10 acesso\n");
	 system("pause");
	 system("cls");
	
 }
 else
 {
 
 int ar[trc]; 
 printf("Insira os elementos da fila do disco :\n ");
 for(i=0;i<trc;i++)
     scanf("%d",&ar[i],"\n\n");
 
 
 for(i=0;i<trc;i++)
 {
 	int st = 1000;
 	for(j=0;j<trc;j++)
 	{
 	    if((abs(pos-ar[j])) == st)
 	    {
 	    	if(ar[j]>ar[ind])
 			    ind =j;
		    else
 			    ind =ind;  
		 }
 	   
 		if( (abs(pos-ar[j])) < st && st>0)
 		{
 			st=abs(pos-ar[j]);
 			ind =j;
    	}
	 }
   
   
    pos=ar[ind];
    ar[ind]=10000;
   
    printf ( " % d " , pos,"\n");//Ordem de acesso ao disco conforme o escalonamento
    sum+=st;	
		 
 }
 
 printf("  \nTempo de busca e % d unidades \n",sum);
 
 printf("==============================******==================================\n"); 
 }
 }
 //==============================///=======================================
 void FCFS(){//função fcfs
	 int i,sum=0,n,pos,trc;
	 n=200;
 printf("==============================FCFS=====================================\n");
 printf("Insira a posicao da cabeca:");
 scanf("%d",&pos);
 printf("Digite o número de trilhas que deseja percorrer:");
 scanf("%d",&trc);
 
 if(trc>10){
	printf(" Maximo de requisicoes: 10 acesso\n");
	 system("pause");
	 system("cls");
	
 }else{

 int ar[trc],tmp[trc];  
 printf("Insira os elementos da fila do disco:\n");
 
 for(i=0;i<trc;i++)
 {
     scanf("%d",&ar[i],"\n");
 
     tmp[i]=pos-ar[i];
        
if(tmp[i]<0)
   tmp[i]=ar[i]-pos;
      
	 pos=ar[i];
	 
     sum=sum+tmp[i];
     
 }
  
for(i=0;i<trc;i++)
 {
     printf(" %d ",ar[i],"  \n");//Ordem de acesso ao disco conforme o escalonamento
 }
 printf("   \nTempo de busca e % d unidades\n ",sum);
 printf("==============================******==================================\n"); 
 
 }
 }
 //==============================///=======================================
int main()
{
	
int opcao;
inicio:

printf("\n---------------------------------------------------------------------\n");
printf("-----------------Trabalho Escalonamento de Disco---------------------\n");
printf("---------------------------------------------------------------------\n");
printf("----------------Disco Tem 200 cilindros (0 ate 199)------------------\n");
printf("---------------------------------------------------------------------\n");
printf("===============================Menu==================================\n");
//menu
printf("1-SSFT\n");
printf("2-FCFS\n");
printf("3-SAIR\n");

printf("Escolha umas da opcao : \n");
 scanf("%d",&opcao);
  
    switch (opcao) {
    case 1:
        system("cls");//limpar 
        SSTF();//função
        break;
    case 2:
         system("cls");
        FCFS();
       
        break;
    case 3:
        
        exit(0);//sair
        break;
    default:
    	system("cls");
        printf("voce deve escolher uma opcao valida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        printf("-------------------------------------------------------\n");
        system("pause");
        goto inicio;//volta para o inicio do menu
    }
	 
 goto inicio;//volta ao inicio 
}