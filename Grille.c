#ifndef __GRILLE__
#include "Grille.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>



//cette fonction aura un test qui comptera le nombre d'occurence de chaque lettre lors de la géneration
void lettre_probabilite(char *lettre){

    int i = 0;
    int cmpt = 0;

    for(i = 0 ; i < 11 ; i++){
        lettre[cmpt] = 'E';
        cmpt++;
    }

    for(i = 0 ; i < 8 ; i++){
        lettre[cmpt] = 'T';
        cmpt++;
    }

     for(i = 0 ; i < 7 ; i++){
        lettre[cmpt] = 'A';
        cmpt++;
    }

    
     for(i = 0 ; i < 7 ; i++){
        lettre[cmpt] = 'I';
        cmpt++;
    }

    
    for(i = 0 ; i < 7 ; i++){
        lettre[cmpt] = 'N';
        cmpt++;
    }

    for(i = 0 ; i < 7 ; i++){
        lettre[cmpt] = 'O';
        cmpt++;
    }

     for(i = 0 ; i < 7 ; i++){
        lettre[cmpt] = 'S';
        cmpt++;
    }


    for(i = 0 ; i < 6 ; i++){
        lettre[cmpt] = 'R';
        cmpt++;
    }


    for(i = 0 ; i < 5 ; i++){
        lettre[cmpt] = 'H';
        cmpt++;
    }

    for(i = 0; i < 4 ; i++){
        lettre[cmpt] = 'D';
        cmpt++;
    }

    for(i = 0 ; i < 4 ; i++){
        lettre[cmpt] = 'L';
        cmpt++;
    }

    for(i = 0 ; i < 3 ; i++){
        lettre[cmpt] = 'C';
        cmpt++;
    }


    for(i = 0 ; i < 3 ; i++){
        lettre[cmpt] = 'M';
        cmpt++;
    }

    for(i = 0 ; i < 3 ; i++){
        lettre[cmpt] = 'U';
        cmpt++;
    }


    for(i = 0 ; i < 2 ; i++){
        lettre[cmpt] = 'B';
        cmpt++;
    }

    for(i = 0 ; i < 2 ; i++){
        lettre[cmpt] = 'F';
        cmpt++;
    }

     for(i = 0 ; i < 2 ; i++){
        lettre[cmpt] = 'G';
        cmpt++;
    }

    for(i = 0 ; i < 2 ; i++){
        lettre[cmpt] = 'P';
        cmpt++;
    }

     for(i = 0 ; i < 2 ; i++){
        lettre[cmpt] = 'W';
        cmpt++;
    }

     for(i = 0 ; i < 2  ; i++){
        lettre[cmpt] = 'Y';
        cmpt++;
    }
    
    lettre[cmpt] = 'J';
    cmpt++;

    lettre[cmpt] = 'K';
    cmpt++;
     
    lettre[cmpt] = 'Q';
    cmpt++;

    
    lettre[cmpt] = 'V';
    cmpt++;


    lettre[cmpt] = 'X';
    cmpt++;


    lettre[cmpt] = 'Z';
    cmpt++;
}


//jeu de test qui verifiera si la grille a bien été alloué ...
Grille * init_grille(int lines , int cols){
    if(lines < 0 || cols < 0){
        return NULL;
    }
    Grille * grille = (Grille *)malloc(sizeof(grille));
    if(grille == NULL){
        return NULL;
    }
    grille->grille = (char **)malloc(sizeof(char *)*lines);  

    if(grille->grille == NULL){
        return NULL;
    }
    for(int i = 0 ; i < cols ; i++){
        grille->grille[i] = (char *)malloc(sizeof(char));
        if(grille->grille[i] == NULL){
            free(grille->grille[i]);
            return NULL;
        }
    }

    grille->cols = cols;
    grille->lines = lines;

    return grille;

}


void load_grille_alea(Grille *g, char *lettre){
    int alea;

    for(int i = 0 ; i < g->lines ; i++){
        for(int j = 0 ; j < g->cols ; j++){
            alea = rand()%100;
            g->grille[i][j] = lettre[alea];
        }
    }

}



void affiche_lettre(char *lettre){
    for(int i = 0 ; i < 100 ; i++){
        printf("%c " , lettre[i]);
        if (i == 20){
            printf("\n");
        }
    }
}



void affiche_grille(Grille *g){
    for(int i = 0 ; i < g->cols ; i++){
        for (int j = 0 ; j < g->lines ; j++){
            printf("%c " , g->grille[i][j]);
        }
        printf("\n");
    }
}




void maj_vers_min(char *mot){
    if(mot){
        for(int i = 0 ; i < strlen(mot) ; i++){
            mot[i] = tolower(mot[i]);
        }
    }
}



int est_valide_mot(EnsembleMots *ens , char *mot){
    maj_vers_min(mot);
    if(!recherche_mot(ens,mot)){
        return 0;
    }
    return 1;

}

int valeur_absolue(int x){
    return x > 0 ? x : -x;
}


int est_adjacent(Case c1, Case c2, int nb_lignes_grille, int nb_cols_grille) {
    if (c1.lines < 0 || c1.lines >= nb_lignes_grille || c1.cols < 0 || c1.cols >= nb_cols_grille ||
        c2.lines < 0 || c2.lines >= nb_lignes_grille || c2.cols < 0 || c2.cols >= nb_cols_grille) {
        return 0;
    }
    return ((c2.cols == c1.cols - 1) && (c2.lines == c1.lines - 1)) ||
           ((c2.cols == c1.cols) && (c2.lines == c1.lines - 1)) ||
           ((c2.cols == c1.cols + 1) && (c2.lines == c1.lines - 1)) ||
           ((c2.cols == c1.cols - 1) && (c2.lines == c1.lines)) ||
           ((c2.cols == c1.cols + 1) && (c2.lines == c1.lines)) ||
           ((c2.cols == c1.cols - 1) && (c2.lines == c1.lines + 1)) ||
           ((c2.cols == c1.cols) && (c2.lines == c1.lines + 1)) ||
           ((c2.cols == c1.cols + 1) && (c2.lines == c1.lines + 1));
}


void case_choisi(int touche, Grille *g, Case pos_act, Pile *p) {
    if (touche == ' ' && (!p->premier || est_adjacent(p->premier->c, pos_act, g->lines, g->cols))) {
        empiler(p, pos_act);
    } else if (touche == 'a') {
        depiler(p);
    }
}




void rempli_tableau(Pile *p,Mot_choisi *mot,Grille *g){
    Cellule *tmp = p->premier;
    Case c;
    
    for(; tmp ; tmp = tmp->next){
        c = depiler(p);
        if(c.cols != -1 && c.lines != -1){
            mot->tab[mot->curlen++] = g->grille[c.lines][c.cols];
        }
    }
    mot->tab[mot->curlen] = '\0';
}



void inverser_mot(char* mot){
    int i;
    for (i = 0; i < strlen(mot)/2; i++) {
        char temp = mot[i];
        mot[i] = mot[strlen(mot)-1-i];
        mot[strlen(mot)-1-i] = temp;
    }
}



void score(char *mot,EtatJeu *etat){

    if(strlen(mot) >= 3){
        etat->score += 2 << (strlen(mot) - 3);
    }
    else{ 
        etat->score += 0;
    }
}


int ajout_tab(Save *s, char *mot){
    assert(mot != NULL);
    if(s->curlen == NB_MAX_MOT){
        return 0; //depassement du nb_max de mots 
    }
    s->save[s->curlen] = mot;
    s->curlen++;

    return 1;
}


int recherche(Save *s ,char *mot){
    assert(mot);
    for(int i = 0; i < s->curlen ; i++){
        if(strcmp(s->save[i] ,mot) == 0){
            return 1;
        }
    }
    return 0;
}

