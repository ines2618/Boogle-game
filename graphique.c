#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>


#ifndef __GRAPH__
#include "graphique.h"
#endif



EtatJeu init_etatjeu(){
    EtatJeu jeu = {.nb_tentatives = 4 , .score = 0};
    return jeu;
}



void couleur_fenetre(int nb_colonnes, int nb_lignes) {
    attron(COLOR_PAIR(1));
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            mvprintw(j, i, " ");
        }
    }
    attroff(COLOR_PAIR(1));
}




void dessine_grille(Grille *g){
    attron(COLOR_PAIR(2));
    for (int i = 0; i < g->lines; i++) {
        for (int j = 0; j < g->cols; j++) {
            mvprintw(LINES/2 + j - 4, COLS/2 + 2*i - 4 ,"%c",g->grille[j][i]);
            mvprintw(j, i*2+1, " ");
        }
    }
    attroff(COLOR_PAIR(2));
}




void affiche_case_surbrillance(Case c , Grille *g,int color){
    attron(COLOR_PAIR(color));
        mvprintw((LINES/2 + c.lines) - 4, (COLS/2 + 2*c.cols) - 4 ,"%c",g->grille[c.lines][c.cols]);
    attroff(COLOR_PAIR(color));
}




void affiche_etat_jeu(EtatJeu jeu){
    attron(COLOR_PAIR(2));
    attron(A_BOLD);
        mvprintw(LINES - 5,COLS/2 - 4,"Score : %d",jeu.score);
        mvprintw(LINES - 3,COLS/2 - 13,"Nombre de tentatives restante: %d",jeu.nb_tentatives);
    attron(COLOR_PAIR(2));
    attroff(A_BOLD);
}





//nous donne la prochaine case à atteindre lors de l'appui sur les touches direcionnels
//changer le nom de la fonction pas ouf
Case fleche_directionelle(Case pos_actuelle,int touche){
    Case new = pos_actuelle;
    switch (touche)
    {
    
    case KEY_LEFT: new.cols -= 1;
        break;
    
    case KEY_RIGHT: new.cols += 1;
        break;
    
    case KEY_DOWN: new.lines += 1; 
        break;
    
    case KEY_UP: new.lines -= 1; 
        break;
    
    case 'z': new.cols -= 1; //diagonale haut gauche
              new.lines -= 1;
            break;

    case 'r' :  new.cols += 1; //diagonale haut droite
                new.lines -= 1;
            break;


    case 'v': new.lines += 1; //diagonale bas droit
              new.cols += 1;
            break;

    case 'x': new.cols -= 1; //diagonal bas gauche
              new.lines += 1;
            break;
   
    default:
        break;
    }

    return new;
}




int dans_grille(Grille *g , Case pos){
    return (0 <= pos.lines  && pos.lines < g->lines) && (0 <= pos.cols  && pos.cols < g->cols);
}




void affiche_surbrillance_case_selectionne(Pile *p,Grille *g){
    Cellule *tmp = p->premier;

    for( ; tmp ; tmp = tmp->next){
        affiche_case_surbrillance(tmp->c,g,4);
    }
}



void affiche_mot_selectionne(int lines , int cols,char *mot){
    assert(mot != NULL);
    attron(COLOR_PAIR(2));
        mvprintw(cols,lines,"Mot selectioné : %s",mot);
    attroff(COLOR_PAIR(2));
}


void interface_graphique(Grille *g,EtatJeu jeu){
    Case pos_default = {0,0};
    couleur_fenetre(LINES,COLS);
    dessine_grille(g);
    affiche_case_surbrillance(pos_default,g,3);
    affiche_etat_jeu(jeu);
}




void interface_fin_jeu(EtatJeu jeu){
    couleur_fenetre(LINES,COLS);
    attron(COLOR_PAIR(2));
    attron(A_BOLD);
        mvprintw(LINES/2,COLS/2 -5 , "Score : %d",jeu.score);
    attroff(COLOR_PAIR(2));
    attroff(A_BOLD);

}

