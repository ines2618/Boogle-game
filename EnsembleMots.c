#ifndef __ENSMOT__
#include "EnsembleMots.h"
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int load_fichier(EnsembleMots *ens , FILE* fichier){
    int i = 0;

    if(!fichier){
        //printf("Fichier introuvale \n");
        return 0;
    }
    char mot[70]; //on suppose que les mots font au plus 70 caractères

    while (fscanf(fichier,"%s",mot) != EOF)
    {   
        char *mot_lu = (char *)malloc(sizeof(char) *70);
        strcpy(mot_lu,mot);
        ens->ens_mots[i] = mot_lu;
    
        i++;
    }
    
    return 1;
}


int recherche_mot(EnsembleMots *ens, char *mot) {
    assert(mot != NULL && *mot != '\0');

    int i, j, middle;
    i = 0;
    j = 370103 - 1; 

    while (i <= j) {
        middle = (i + j) / 2;

        if (strcmp(ens->ens_mots[middle], mot) == 0) {
            return 1;
        } else if (strcmp(ens->ens_mots[middle], mot) > 0) {
            j = middle - 1;
        } else {
            i = middle + 1;
        }
    }
    return 0;
}



void affiche_fichier(EnsembleMots ens){
    for(int i = 0 ; i < 370103 ; i++){
        printf("%s \n", ens.ens_mots[i]);
    }
}

void free_ensemblemots(EnsembleMots *ens){
    for(int i = 0 ; i < 370103 ; i++){
        free(ens->ens_mots[i]);
    }
}


