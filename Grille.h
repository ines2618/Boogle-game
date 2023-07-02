#ifndef __GRILLE__
#define __GRILLE__

#ifndef __ENSMOTS__
#include "EnsembleMots.h"
#endif

#ifndef __PILE__
#include "Pile.h"
#endif

#define NB_MAX_MOT 100 //on considera que le joueur ne devinera que 20 en 1 partie


typedef struct _grille
{
    int lines; //dimension de la grille
    int cols; 
    char ** grille;
}Grille;


//structure dans laquel nous stockerons le mot choisi par l'utilisateur
typedef struct _mot_choisi
{
    char tab[70]; //on considère qu'un mot ne fait pas plus de 70 caractères
    int curlen;
}Mot_choisi;



typedef struct _jeu
{
    int score;
    int nb_tentatives;
}EtatJeu;


typedef struct _save
{
    char *save[NB_MAX_MOT];
    int curlen;
}Save;




/// @brief fonction qui génere un tableau contenant les lettres nb fois leur proba
/// @param lettre 
void lettre_probabilite(char *lettre);


/// @brief fonction qui initialise une grille
/// @param lines nombre de lignes
/// @param cols nombre de colonnes
/// @return un pointeur sur une grille initialisé
Grille * init_grille(int lines , int cols);


/// @brief un lettreleau contenant les mots selon leur probaibilités d'apparition
/// @param taille_max 
/// @return un lettreleau statique de taille 100
char * mot_probabilite(int taille_max);


/// @brief fonction qui tire un nombre entre 1 et 100 et extrait 
//le mot contenu dans le lettreleau des lettres
/// @param g qui est une grille
void load_grille_alea(Grille *g, char *lettre);

/// @brief Pour passer un mot contenant des majuscules en minuscules
/// @param mot 
void maj_vers_min(char *mot);



/// @brief teste si un mot est valide c'est à dire si il est contenu dans le dictionnaire
/// @param ens 
/// @param mot 
/// @return 1 si le mot est valide , 0 sinon
int est_valide_mot(EnsembleMots *ens , char *mot);


/// @brief affiche la grille 
/// @param g 
void affiche_grille(Grille *g);

/// @brief fonction qui ajoute une coordonnées dans la pile lorsque l'utilisateur appuie sur espace , depile si appuie sur touche 'a' 
/// @param touche 
/// @param g 
/// @param pos_act 
/// @param p 
void case_choisi(int touche,Grille *g,Case pos_act,Pile *p);


/// @brief renvoie si les cases sont adjacentes
/// @param c1 
/// @param c2 
/// @return 1 si case adjacentes , 0 sinon
int est_adjacent(Case c1, Case c2, int nb_lignes_grille, int nb_cols_grille);

/// @brief 
/// @param p 
/// @param mot 
/// @param g 
void rempli_tableau(Pile *p,Mot_choisi *mot,Grille *g);

/// @brief fonction qui inverse un mot , utile lorsque l'on depile la pile contenant les lettres validées par l'utilisateur
/// @param mot 
void inverser_mot(char* mot);

/// @brief calcule le score comme donné dans l'enoncé
/// @param mot 
/// @param etat 
void score(char *mot,EtatJeu *etat);

/// @brief ajoute un mot dans un tableau
/// @param s 
/// @param mot 
/// @return 1 si l'ajout s'est bien passé , 0 sinon
int ajout_tab(Save *s, char *mot);

/// @brief fonction recherchant un mot dans un tableau 
/// @param s 
/// @param mot 
/// @return 1 si le mot est présent , 0 sinon
int recherche(Save *s ,char *mot);



#endif


