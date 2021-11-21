//Referencia
//https://www.skellainnovations.com/round-robin-algorithm-in-os/
#include<iostream>
#include<conio.h>
using namespace std;



 
int at[50], bt[50], ct[50]={0}, qt, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt, wt;
float att, awt;
void SearchStack01(int pnt,int tm){
    for(int x=pnt+1;x<5;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }
}

void SearchStack02(int pnt, int tm){
    for(int x=pnt+1;x<5;x++){
       
       int fl=0;
       for(int y=0;y<noe;y++){
          if(rqi[y]==x+1){
             fl++;}}
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }
}

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}


int main(int argc, char *argv[]){
cout << "----------- Round Robin  ----------" << endl;
cout<<  "-----------------------------------"<<endl;
	
int numereoproc;//numero de processo
string nome;//nome do processo

cout<<"Digite o Nome do processos :";
cin>>nome;

cout << "-----------------------------------" << endl;
cout<<"Digite os Numero de processos :";
cin>>numereoproc;

cout << "-----------------------------------" << endl;
if (numereoproc>5){
	cout<<"Nao foi possivel  ";
	return 0;
}
else
{
// repeticao de valores para o processo tempo de chegada e tempo de cpu 
for(int x=0;x<numereoproc;x++){
cout<<"\n--------------Processo"<<x+1<<"-------------- ";
   
    cout<<"\nTempo de Chegada=";
    cin>>at[x];
    cout << "Tempo de CPU=";
    cin>>bt[x];
    btm[x]=bt[x];}
cout<<"----------------------------------------";
//Valor do quantum
cout<<"\nDigite o valor do quantum:";
cin>>qt;
cout<<"----------------------------------------" << endl;
}


do{
    if(flg==0){
       st=at[0];
       
       if(btm[0]<=qt){
          tm=st+btm[0];
          btm[0]=0;
          SearchStack01(pnt,tm);}
       else{
          btm[0]=btm[0]-qt;
          tm=st+qt;
          SearchStack01(pnt,tm);
          AddQue(pnt);}
    }
 
    else{
       pnt=rqi[0]-1;
       st=tm;
       
       for(int x=0;x<noe && noe!=1;x++){
          rqi[x]=rqi[x+1];}
       noe--;
       
       if(btm[pnt]<=qt){
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          SearchStack02(pnt, tm);
          AddQue(pnt);}
    }

    
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }

   flg++;
 

}while(noe!=0);
/*
tempo de chegada = T.C.
tempo de cpu     = Cpu.
Turnaround       = TT.
tempo de espera  = Wt.
*/
//---------------------------------------
 //Tabela dos Processos
cout<<"\n\nPROCESSO\tT.C\t Cpu\t TT\t WT\n";
for(int x=0;x<numereoproc;x++){
    tt=ct[x]-at[x];
    wt=tt-bt[x];
    cout<<"P"<<x+1<<"               "<<at[x]<<" \t "<<bt[x]<<" \t "<<tt<<" \t "<<wt<<"\n";
    awt=awt+wt;
    att=att+tt;
}

cout<<"-------------------------------------------------"<<endl;
cout<<"\nNome do Processo     :"<<nome <<endl;
cout<<"\nTurnaround Medio     :"<< att/numereoproc << endl;
cout<<"\nTempo de espera medio:"<< awt/numereoproc << endl;
cout<<"-------------------------------------------------"<<endl;
}

