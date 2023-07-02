#include "Pile.h"


#include <stdio.h>
#include <stdlib.h>




Cellule * alloue_cell(Case c){
    Cellule * new = (Cellule *)malloc(sizeof(Cellule));
    if(!new){
        return NULL;
    }
    new->c = c;
    new->next = NULL;

    return new;
}


Pile * init_pile(Case c){
    Pile *new_pile = (Pile *)malloc(sizeof(Pile));
    Cellule *cell = alloue_cell(c);
    if(!new_pile || !cell){
        return NULL;
    }
    new_pile->premier = cell;

    return new_pile;
}



void empiler(Pile *p, Case c){
    Cellule * nouveau = alloue_cell(c);
    if(!p){
        p = init_pile(c);
        return ;
    }
    nouveau->next = p->premier;
    p->premier = nouveau;
}




Case depiler(Pile *p){
    Case dernier = {-1,-1}; //ne pas oublier de tester si le dernier n'est pas egale à ca
    if(!p){
        //mot vide y'a rien à depiler
        return dernier;
    }
    Cellule *tmp = p->premier;

    if(tmp && p->premier){
        dernier = tmp->c;
        p->premier = tmp->next;
    }
    return dernier;
}




void affiche_pile(Pile p){
    Cellule *tmp = p.premier;

    for( ; tmp ; tmp = tmp->next){
        printf("%d , %d" , tmp->c.lines , tmp->c.cols);
    }
    printf("\n");
}


// <int main(){
//     Pile *new_pi = NULL;
//     Case c = { 0,0};
//     Case d = { 0,1};
//     Case e = { 0,2};
//     Case f = { 0,3};
//     Case g = { 0,4};
//     Case h = { 0,5};
//     empiler(new_pi,c);
//     empiler(new_pi,d);
//     empiler(new_pi,e);
//     // empiler(new_pi,'R');
//     // empiler(new_pi,'S');
//     // empiler(new_pi,'T');
//     // depiler(new_pi);
//     // depiler(new_pi);
//     // depiler(new_pi);
//     // depiler(new_pi);
//     // depiler(new_pi);
//     // depiler(new_pi);
//     // depiler(new_pi);

//     affiche_pile(*new_pi);

//     return 0;
// }>