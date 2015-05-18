#include <stdio.h>
#include <stdlib.h>
#include "studente.h"
#include "funzioni.h"
#include <string.h>

int main(int argc, char** argv) {
    int fineInput;
    int i;
    int dimensioneMaschi=2;
    int dimensioneFemmine=dimensioneMaschi;
    int maschiInseriti;
    int femmineInserite;
    
    FILE *MAS;
    FILE *FEM;
    
    studente temp;
    studente *maschi;
    maschi=(studente*)malloc(dimensioneMaschi*sizeof (studente));
    studente *femmine;
    femmine=(studente*)malloc(dimensioneFemmine*sizeof (studente));
    maschiInseriti=0;
    femmineInserite=0;
    i=1;
    do {
        printf("Studente %d:\n", i);
        temp = inserimento();
        if (temp.sesso!=0) {
            temp.sesso=1;
            maschi[maschiInseriti]=temp;
            maschiInseriti++;
            if (maschiInseriti==dimensioneMaschi){
                maschi=rialloca(maschi, dimensioneMaschi);
                dimensioneMaschi*=2;
            }
            
        }        
        else {
            femmine[femmineInserite]=temp;
            femmineInserite++;
            if (femmineInserite==dimensioneFemmine){
                femmine=rialloca(femmine, dimensioneFemmine);
                dimensioneFemmine*=2;
            }
        }
        i++;
        printf("Vuoi inserire un altro studente? (0-No / 1-Si): ");
        scanf("%d", &fineInput);
      
    }while (fineInput!=0);
    maschi=ordina(maschi,maschiInseriti);
    MAS=fopen("maschi.csv", "w");
    if(MAS==NULL){
        fprintf(stderr,"Impossibile aprire il file maschi.csv .");
        exit(1);
    }
    fprintf(MAS,"Studente;Nome;Cognome;Classe;Sesso;Eta'\n");
    for(i=0;i<maschiInseriti;i++){
        fprintf(MAS,"%d;%s;%s;%s;%d;%d;\n",i+1,
            maschi[i].nome,
            maschi[i].cognome,
            maschi[i].classe,
            maschi[i].sesso,
            maschi[i].eta);
    }
    fclose(MAS);
    free(maschi);
    
    femmine=ordina(femmine,femmineInserite);
    FEM=fopen("femmine.csv", "w");
    if(FEM==NULL){
        fprintf(stderr,"Impossibile aprire il file femmine.csv .");
        exit(1);
    }
    fprintf(FEM,"Studente;Nome;Cognome;Classe;Sesso;Eta'\n");
    for(i=0;i<maschiInseriti;i++){+
        fprintf(FEM,"%d;%s;%s;%s;%d;%d;\n",i+1,
            femmine[i].nome,
            femmine[i].cognome,
            femmine[i].classe,
            femmine[i].sesso,
            femmine[i].eta);
    }
    fclose(FEM);
    free(femmine);
    return (EXIT_SUCCESS);
}
