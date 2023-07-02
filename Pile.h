#ifndef __PILE__
#define __PILE__


typedef struct _case
{
    int lines;
    int cols;
}Case;


typedef struct _cell
{
    Case c;
    struct _cell *next;
}Cellule;


typedef struct _pile
{
    Cellule *premier; //adresse de clui qui se trouve tout en haut
}Pile;



Cellule * alloue_cell(Case c);

Pile * init_pile(Case c);

void empiler(Pile *p, Case c);


/// @brief renvoie l'element depiler qui sera une lettre
/// @param p 
/// @return 
Case depiler(Pile *p);


void affiche_pile(Pile p);


#endif