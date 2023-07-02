#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#ifndef __GRAPH__
#include "graphique.h"
#endif


#ifndef __PILE__
#include "Pile.h"
#endif

#ifndef __GRILLE__
#include "Grille.h"
#endif


#ifndef __ENSMOTS__
#include "EnsembleMots.h"
#endif




int main(){
    srand(time(NULL));
    int i = 0;
    int dim;
    int touche;
    EnsembleMots ens;
    FILE *fichier = fopen("Mots","r");
    if(!load_fichier(&ens,fichier)){
        exit(EXIT_FAILURE);
    }


    Pile p;
    Grille *g = init_grille(5,5);
    Mot_choisi mot = {.tab = {0} , .curlen = 0};
    Mot_choisi reinit = {.tab = {0} , .curlen = 0};
    EtatJeu jeu = {.nb_tentatives = 4, .score = 0};
    Save s = {.curlen = 0};

    Case pos_init = {0,0};
    Case pos_default = {0,0};
    Case next_pos;

    char lettre[100];
    lettre_probabilite(lettre);
    load_grille_alea(g,lettre);

        
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    init_pair(3,COLOR_YELLOW,COLOR_BLUE);
    init_pair(4,COLOR_YELLOW,COLOR_CYAN); //couleur case selectionné
    init_pair(5,COLOR_RED,COLOR_CYAN);


    interface_graphique(g,jeu);

    while (jeu.nb_tentatives != 0)
    {
        touche = getch();

        
        next_pos = fleche_directionelle(pos_init,touche);
        
        if(dans_grille(g,next_pos)){
            affiche_case_surbrillance(pos_init,g,2);
            pos_init = next_pos;
        }

        affiche_case_surbrillance(pos_init,g,3);

        case_choisi(touche,g,pos_init,&p);

        affiche_surbrillance_case_selectionne(&p,g);

        if(touche == '\n'){
        
            rempli_tableau(&p,&mot,g);
            
            if(mot.tab[0] != '\0'){ //il faut verifier que l'utilisateur n'a pas appuyé sur entré sans avoir selectionné une lettre
                inverser_mot(mot.tab);
        
                if(est_valide_mot(&ens,mot.tab) && !recherche(&s,mot.tab)){
        
                    score(mot.tab,&jeu);
                    ajout_tab(&s,mot.tab);
                }
                else{
            
                    jeu.nb_tentatives--;
                }
                
    
                //reinitialisation du mot 
                mot = reinit;
            
                //reinitialisation graphique
                affiche_etat_jeu(jeu);
                dessine_grille(g);
                affiche_case_surbrillance(pos_default,g,3);
    
                pos_init = pos_default;
        
                refresh();
            }

        }

        if(touche == 'q'){
            break;
        }

        refresh();
    }

    interface_fin_jeu(jeu);
    getch();
    endwin();
    
    return 0;
}