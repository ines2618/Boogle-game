#ifndef __GRAPH__
#define __GRAPH__


#ifndef __GRILLE__
#include "Grille.h"
#endif

#ifndef __PILE__
#include "Pile.h"
#endif


/// @brief affiche un fond blanc
/// @param nb_colonnes 
/// @param nb_lignes 
void couleur_fenetre(int nb_colonnes, int nb_lignes);



/// @brief fonction affichant la grille 
/// @param g 
void dessine_grille(Grille *g);



/// @brief fonction qui affiche l'etat du jeu : score , nb_tentatives restantes
/// @param jeu 
void affiche_etat_jeu(EtatJeu jeu);



/// @brief affiche la case en surbillance
/// @param c case
/// @param g grille
/// @param color couleur qui variera en fonction de si la case a été sélectioné ou non
void affiche_case_surbrillance(Case c , Grille *g,int color);



/// @brief fonction qui affiche le mot selectioné
/// @param lines 
/// @param cols 
/// @param mot 
void affiche_mot_selectionne(int lines , int cols,char *mot);



/// @brief fonction qui determine les cases adjacentes à une case en fonction des touches pressé
/// touche 'z' pour diagonale haut gauche , 'r' : diagonale haut droite , 'v' : diagonale bas droite ,'x' : diagonale bas gauche
/// @param pos_actuelle 
/// @param touche 
/// @return la case adjacentes
Case fleche_directionelle(Case pos_actuelle,int touche);


/// @brief affiche les cases qui ont été precèdement sélectioné par le joueur
/// @param p 
/// @param g 
void affiche_surbrillance_case_selectionne(Pile *p,Grille *g);


/// @brief fonction qui teste si une case est dans la grille
/// @param g 
/// @param pos 
/// @return 
int dans_grille(Grille *g , Case pos);

/// @brief fonction recapitulatif affichant : le fond , la grille , l'etat du jeu...
void interface_graphique(Grille *g,EtatJeu jeu);


/// @brief affiche le score lorsque la partie est terminé
/// @param jeu 
void interface_fin_jeu(EtatJeu jeu);

#endif