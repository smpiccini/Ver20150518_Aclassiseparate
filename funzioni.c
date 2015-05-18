#include <stdio.h>
#include <stdlib.h>
#include "studente.h"
#include "funzioni.h"
#include <string.h>

studente inserimento(){
    studente alunno;
        printf("Nome: ");
        scanf("\n%[^\n]", alunno.nome);
        printf("Cognome: ");
        scanf("\n%[^\n]", alunno.cognome);
        printf("Classe: ");
        scanf("\n%[^\n]", alunno.classe);
        printf("Sesso(1-Maschio / 0-Femmina): ");
        scanf("%d", &alunno.sesso);
        printf("Eta': ");
        scanf("%d", &alunno.eta);
        return alunno;
}

studente* rialloca(studente* elencoDaAllocare, int dimensioneCorrente){
    int i;
    studente *nuovoElenco;
    
    nuovoElenco=(studente*)malloc(2*dimensioneCorrente*sizeof(studente));
    for (i=0;i<dimensioneCorrente;i++){
        nuovoElenco[i]=elencoDaAllocare[i];
    }
        free(elencoDaAllocare);
        return nuovoElenco;
}

studente* ordina(studente*elenco, int dimensione){    //proff l'algoritmo di ordinamento c'è, ora perché non modifica MINIMAMENTE l'array di record non lo so, non ho fatto in tempo.
    studente *temp;
    temp=(studente*)malloc(sizeof(studente));
    int i,j;
    int min;
    for(i=0;i<dimensione-1;i++){
        min=i;
        for(j=i+1;j<dimensione;j++){
            if(strcmp(elenco[j].cognome,elenco[j].cognome)<0){
                min=j;
            }
        }
        if(min!=i){
            *temp=elenco[min];
            elenco[min]=elenco[i];
            elenco[i]=*temp;
        }
    }
    free(temp);
    return elenco;
}