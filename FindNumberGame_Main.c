#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#define DIM 4
#define MAX_MOSSE 3 //DEFAULT=10...Numero massimo di mosse da fare per vincere..altrimenti perdi
#define false 0
#define true 1


void riempiVettore(int* v);
int* controlloNumeri(int *esatta,int *tentativo);
int getDimensionVector(int *vc);


void main(){
    int toFind[DIM]; //sequenza da INDOVINARE
    int mySek[DIM]; // sequenza scelta dal giocatore
    int nMosse=0;
    int i,j;//i=puntatore toFind  -  j=puntatore seqUt;
    int k;//usata in generazione sequenza casuale
    
    int* esitoCheck;
    
    
    //GRAFICA INIZIALE
    printf("|---------------------------------------------------------------|\n");
    printf("|         |-|-|-> XXXX - TROVA LA COMBINAZIONE! <-|-|-|         |\n");
    printf("|_______________________________________________________________|\n");
    printf("|     ::::::::|POWERED BY: Felicetti Davide©        |::::::::   |\n");
    printf("|     ::::::::|CREATED:    Thursday, 6 October 2016 |::::::::   |\n");
    printf("|---------------------------------------------------------------|\n");
    printf("|/***-- REGOLE DEL GIOCO:                                       |\n");
    printf("|+-- Obiettivo                                                  |\n");
    printf("|Trova la combinazione vincente.                                |\n");
    printf("|                                                               |\n");
    printf("|+-- Come funziona                                              |\n");
    printf("|Utilizzando UNA SOLA VOLTA i numeri da 1 a 9, crea una         |\n");
    printf("|combinazione di 4 cifre che verrà confrontata con quella creata|\n");
    printf("|dal sistema.                                                   |\n");
    printf("|Hai solo 10 mosse per indovinare le 4 cifre e le loro esatte   |\n");
    printf("|posizioni nella sequenza creata.                               |\n");
    printf("|                                                               |\n");    
    printf("|Esempio: COMBINAZIONE VINCENTE   TUA COMBINAZIONE    ESITO     |\n");
    printf("|         ---------------------   ----------------  --------    |\n");
    printf("|CASO 1:  |      [1234]        |  |   [1324]     | |NON ESATTA| |\n");
    printf("|CASO 2:  |      [1234]        |  |   [1234]     | |  ESATTA  | |\n");
    printf("|         ----------------------  ---------------- ------------ |\n");
    printf("|                                                               |\n");
    printf("|Legenda Post Confronto Combinazioni:                           |\n");
    printf("|'POSIZIONE CORRETTA'=>  Valore e posizione di un numero della  |\n");
    printf("|                        tua sequenza esatti.                   |\n");
    printf("|'POSIZIONE SBAGLIATA'=> Valore corretto, ma non la posizione.  |\n");
    printf("|                                                               |\n");
    printf("|RICORDA: Hai un numero di tentativi limitato.                  |\n");
    printf("|                                                               |\n");
    printf("|Buona Fortuna                                                  |\n");    
    printf("|---------------------------------------------------------------|\n");
    
      
    
    
    
    
    
    char risposta[5];
    printf("Iniziare una nuova partita?(si/no)\n");
    scanf("%s",risposta);
    if( strcmp("no",risposta)==0 || strcmp("NO",risposta)==0 || strcmp("nO",risposta)==0 || strcmp("No",risposta)==0){
        printf("Partita annullata...\n");
        exit(1);
    }
   
    else{   
        printf("-------------------> INIZIA LA SFIDA! <---------------------\n");
        printf("Creazione sequenza da indovinare. Attendere pochi secondi...\n");
        
        for(i=0;i<4;i++){
            int ok=false;
            while(!ok){
                srand(time(NULL));
                toFind[i]=rand()%9+1;
                ok=true;
                for(k=0;k<i;k++){
                    if(toFind[i]==toFind[k])
                        ok=false;       
                
                }
           }
        } 
        
        //EFFETTO GRAFICO CREAZIONE SEQUENZA DA INDOVINARE..
        int m;
        for(m=0;m<5;m++){
            printf(".\n");
            sleep(1);
        }
        
        /*Da togliere
        int b;
        printf("[");
        for(b=0;b<DIM;b++)
            printf("%d ",toFind[b]);
        printf("]\n\n");*/
            
        printf("Sequenza creata: proponi la tua sequenza!\n\n");
   
    
    //RIEMPI mySek FINO A QUANDO NON TROVI SEQUENZA toFind o raggiungi MAX_MOSSE
    
    //----------------CREAZIONE SEQUENZA DA INDOVINARE E MIA SEQUENZA (fine)------------------------------
       
            
           
       while(nMosse<MAX_MOSSE){
      
            if(nMosse==MAX_MOSSE-1)
                printf("***** ATTENTO: ultimo tentativo! *****\n");
           
                         
            riempiVettore(mySek);
        
        
            esitoCheck=controlloNumeri(toFind,mySek);
            nMosse++;       
            
        
            int numeriPresentiPosOk=esitoCheck[0];
            int numeriPresentiPosWrong=esitoCheck[1];
            int dim;
            
        
            dim=getDimensionVector(esitoCheck);
            int q;
            printf("SEQUENZA PROPOSTA: [");
            for(q=0;q<DIM;q++)
                printf("%d ",mySek[q]);
            printf("]\nESITO CONTROLLO:\n\tPOSIZIONE CORRETTA: %d\tPOSIZIONE SBAGLIATA: %d\t\t[Tentativo n.%d]\n\n",numeriPresentiPosOk,numeriPresentiPosWrong,nMosse);
            
            if(numeriPresentiPosOk==4){
                char mosseStringa[10];
                
                printf("\n\n");
                printf("|===============================================================|\n");
                printf("|_-_-_-_-_-_-_-_-_-_-_-_- VITTORIA _-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
                printf("|                                                               |\n");
                if(nMosse==1)
                    strcpy(mosseStringa,"mossa");
                else
                    strcpy(mosseStringa,"mosse");
                printf("|Complimenti hai vinto in %d %s.                              |\n",nMosse,mosseStringa);
                printf("|_______________________________________________________________|\n");
                
                exit(1);
            }
        }//fine while
        
               
            printf("|---------------------------------------------------------------|\n");
            printf("|+++++++++++++++++++++++++ GAME OVER +++++++++++++++++++++++++++|\n");
            printf("|_______________________________________________________________|\n");
        
            //STAMPA SEQUENZA DA INDOVINARE
            printf("SEQUENZA CORRETTA: [");
            int p;
            for(p=0;p<DIM;p++)
                printf("%d",toFind[p]);
            printf("]\n");
       
    }
    
    
    free(esitoCheck);
    
}//FINE MAIN


//------------------- FUNZIONI AUSILIARIE------------------------------------


void riempiVettore(int *v){
    
    int num,size,i;
    
        size=0;
        printf("INSERISCI I TUOI NUMERI\n");
        do{
            //printf("Inserisci un numero..\n");
            scanf("%d",&num);
            if(num!=0 && (num>=1 && num<=9) && size<DIM){
                v[size]=num;
                size++;               
            }         
            
        }while(num!=0 && (num>=1 && num<=9) && size<DIM); 

}








// BLOCCO SUCCESSIVO CORRETTO
//controlloSequenza SENZA MALLOC
int* controlloNumeri(int *esatta,int *tentativo){
    
    int *res;
    int i,j; //j=vettore esatta & i=vettore tentativo
    
    int k=0; //indica la reale dimensione di *res;
    
    
    for(i=0;i<4;i++){//tentativo
        for(j=0;j<4;j++){//esatta
            int numAt=tentativo[i];
            if(esatta[j]==numAt){
                (k)++;
            }             
        }//fine for j
    }//fine for di i
    
    /* I 2 FOR:  restituiscono esattamente quanti numeri sono stati indovinati senza però
    *        specificare se in pos corretta o sbagliata
    * 
    */
    
    //printf("Numeri presi: %d\n",k);
    //return k;
    
    
    
    //******** QUANTITA NUMERI PRESI CORRETTI
    
    
    res=(int*)malloc(sizeof(int)* 3);
    
    
    int posCorretta=0;
    int posScorretta=0;
    int numAssenti=0;
    
    for(i=0;i<4;i++){//CICLO ESTERNO SU TENTATIVO
        for(j=0;j<4;j++){
            if(tentativo[i]==esatta[j] && j==i){//stessa posizione
               posCorretta++;
            }
            else if(tentativo[i]==esatta[j] && j!=i){
                posScorretta++;
            }           
        }//FINE CICLO INTERNO(esattaCombinazione)
    }
    
   // printf("CORRETTI: %d - POS SCORRETTA: %d\n",posCorretta,posScorretta);
    
    
   res[0]=posCorretta;
   res[1]=posScorretta;
   res[2]=numAssenti;
   return res; 
     
}


int getDimensionVector(int *vc){//OK
    return sizeof(vc)/sizeof(vc[0]);   
}