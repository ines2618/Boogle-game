#ifndef __GRILLE__
#include "Grille.h"
#endif

#ifndef __ENSMOT__
#include "EnsembleMots.h"
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int nb_occurences_tab_1dim(char lettre, char *tab) {
    int nb_occur = 0;

    for (int i = 0; i < 100; i++) {
        if (tab[i] == lettre) {
            nb_occur++;
        }
    }
    return nb_occur;
}

int nb_occurences_tab_2dim(char lettre, Grille *g) {
    int nb_occur = 0;

    for (int i = 0; i < g->lines; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grille[i][j] == lettre) {
                nb_occur++;
            }
        }
    }
    return nb_occur;
}

void test_lettre_probabilite() {
    char tab[100];
    lettre_probabilite(tab);

    int nb_occur_A = nb_occurences_tab_1dim('A', tab);
    assert(nb_occur_A == 7);

    int nb_occur_B = nb_occurences_tab_1dim('B', tab);
    assert(nb_occur_B == 2);

    int nb_occur_C = nb_occurences_tab_1dim('C', tab);
    assert(nb_occur_C == 3);

    int nb_occur_D = nb_occurences_tab_1dim('D', tab);
    assert(nb_occur_D == 4);

    int nb_occur_E = nb_occurences_tab_1dim('E', tab);
    assert(nb_occur_E == 11);

    int nb_occur_F = nb_occurences_tab_1dim('F', tab);
    assert(nb_occur_F == 2);

    int nb_occur_G = nb_occurences_tab_1dim('G', tab);
    assert(nb_occur_G == 2);

    int nb_occur_H = nb_occurences_tab_1dim('H', tab);
    assert(nb_occur_H == 5);

    int nb_occur_I = nb_occurences_tab_1dim('I', tab);
    assert(nb_occur_I == 7);

    int nb_occur_J = nb_occurences_tab_1dim('J', tab);
    assert(nb_occur_J == 1);
}

void test_init_grille() {
    int lines = 10;
    int cols = 10;
    Grille *grille = init_grille(lines, cols);

    assert(grille != NULL);
    assert(grille->grille != NULL);
    assert(grille->cols == cols);
    assert(grille->lines == lines);

    // cas ou on passe des dim invalides

    int dim_lines = 2;
    int dim_cols = -1;

    Grille *grill = init_grille(dim_lines, dim_cols);
    assert(grill == NULL);
}

void test_load_grille_alea() {
    srand(time(NULL));
    char lettre[100];
    lettre_probabilite(lettre);

    // on regarde si la generation est reussi en genérant plusieurs grilles différentes
    Grille *g_1 = init_grille(4, 4);
    load_grille_alea(g_1, lettre);

    //int nb_occurences_E = nb_occurences_tab_2dim('E', g_1);
    int nb_occurences_J = nb_occurences_tab_2dim('J', g_1);
    int nb_occurences_H = nb_occurences_tab_2dim('H', g_1);

    //assert((0.11 * 16) - 0.1 <= nb_occurences_E && nb_occurences_E <= (0.11 * 16) + 0.1); 
    assert((0.01 * 16) - 0.1 <= nb_occurences_J && nb_occurences_J <= (0.01 * 16) + 0.1);
    assert((0.05 * 16) - 0.1 <= nb_occurences_H && nb_occurences_H <= (0.05 * 16) + 0.1);

    Grille *g_2 = init_grille(16, 16);
    load_grille_alea(g_2, lettre);

    int nb_occurences_E_2 = nb_occurences_tab_2dim('E', g_2);
    int nb_occurences_J_2 = nb_occurences_tab_2dim('J', g_2);
    int nb_occurences_H_2 = nb_occurences_tab_2dim('H', g_2);
    int nb_occurences_B = nb_occurences_tab_2dim('B', g_2);
    int nb_occurences_N = nb_occurences_tab_2dim('N', g_2);

    assert((0.11 * (16 * 16)) - 0.1 <= nb_occurences_E_2 && nb_occurences_E_2 <= (0.11 * (16 * 16)) + 0.1);
    assert((0.01 * (16 * 16)) - 0.1 <= nb_occurences_J_2 && nb_occurences_J_2 <= (0.01 * (16 * 16)) + 0.1);
    assert((0.05 * (16 * 16)) - 0.1 <= nb_occurences_H_2 && nb_occurences_H_2 <= (0.05 * (16 * 16)) + 0.1);
    assert((0.02 * (16 * 16)) - 0.1 <= nb_occurences_B && nb_occurences_H <= (0.02 * (16 * 16)) + 0.1);
    assert((0.07 * (16 * 16)) - 0.1 <= nb_occurences_N && nb_occurences_H <= (0.07 * (16 * 16)) + 0.1);
}

/*****************************/

void test_alloue_cell() {
    Case c = {1, 2};
    Cellule *cell = alloue_cell(c);
    assert(cell != NULL);
    assert(cell->c.lines == 1);
    assert(cell->c.cols == 2);
    assert(cell->next == NULL);
    free(cell);
}

void test_init_pile() {
    Case c = {1, 2};
    Pile *pile = init_pile(c);
    assert(pile != NULL);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 1);
    assert(pile->premier->c.cols == 2);
    assert(pile->premier->next == NULL);
    free(pile->premier);
    free(pile);
}

void test_empiler() {
    Case c1 = {1, 2};
    Pile *pile = init_pile(c1);
    assert(pile != NULL);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 1);
    assert(pile->premier->c.cols == 2);
    assert(pile->premier->next == NULL);

    Case c2 = {3, 4};
    empiler(pile, c2);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 3);
    assert(pile->premier->c.cols == 4);
    assert(pile->premier->next != NULL);
    assert(pile->premier->next->c.lines == 1);
    assert(pile->premier->next->c.cols == 2);
    assert(pile->premier->next->next == NULL);

    free(pile->premier->next);
    free(pile->premier);
    free(pile);
}

void test_depiler() {
    Case c1 = {1, 2};
    Pile *pile = init_pile(c1);
    assert(pile != NULL);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 1);
    assert(pile->premier->c.cols == 2);
    assert(pile->premier->next == NULL);

    Case c2 = {3, 4};
    empiler(pile, c2);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 3);
    assert(pile->premier->c.cols == 4);
    assert(pile->premier->next != NULL);
    assert(pile->premier->next->c.lines == 1);
    assert(pile->premier->next->c.cols == 2);
    assert(pile->premier->next->next == NULL);

    Case dernier = depiler(pile);
    assert(dernier.lines == 3);
    assert(dernier.cols == 4);
    assert(pile->premier != NULL);
    assert(pile->premier->c.lines == 1);
    assert(pile->premier->c.cols == 2);
    assert(pile->premier->next == NULL);

    dernier = depiler(pile);
    assert(dernier.lines == 1);
    assert(dernier.cols == 2);
    assert(pile->premier == NULL);

    dernier = depiler(pile);
    assert(dernier.lines == -1);
    assert(dernier.cols == -1);

    free(pile);
}

void test_maj_vers_min() {
    char mot[] = "HELLO";
    maj_vers_min(mot);
    assert(strcmp(mot, "hello") == 0);

    char mot2[] = "WORLD";
    maj_vers_min(mot2);
    assert(strcmp(mot2, "world") == 0);
}

void test_est_adjacent() {
    int nb_lignes_grille = 3;
    int nb_cols_grille = 3;

    Case c1 = {1, 1};
    Case c2 = {0, 0};
    assert(est_adjacent(c1, c2, nb_lignes_grille, nb_cols_grille) == 1);

    Case c3 = {0, 1};
    assert(est_adjacent(c1, c3, nb_lignes_grille, nb_cols_grille) == 1);

    Case c4 = {0, 2};
    assert(est_adjacent(c1, c4, nb_lignes_grille, nb_cols_grille) == 1);

    Case c5 = {1, 0};
    assert(est_adjacent(c1, c5, nb_lignes_grille, nb_cols_grille) == 1);

    Case c6 = {1, 2};
    assert(est_adjacent(c1, c6, nb_lignes_grille, nb_cols_grille) == 1);

    Case c7 = {2, 0};
    assert(est_adjacent(c1, c7, nb_lignes_grille, nb_cols_grille) == 1);

    Case c8 = {2, 1};
    assert(est_adjacent(c1, c8, nb_lignes_grille, nb_cols_grille) == 1);

    Case c9 = {2, 2};
    assert(est_adjacent(c1, c9, nb_lignes_grille, nb_cols_grille) == 1);

    Case c10 = {3, 3};
    assert(est_adjacent(c1, c10, nb_lignes_grille, nb_cols_grille) == 0);
}

void test_case_choisi() {
    Grille g;
    g.lines = 3;
    g.cols = 3;

    Pile p;
    p.premier = NULL;

    Case pos_act = {1, 1};

    case_choisi(' ', &g, pos_act, &p);
    assert(p.premier != NULL);
    assert(p.premier->c.lines == 1);
    assert(p.premier->c.cols == 1);
    assert(p.premier->next == NULL);

    Case pos_act2 = {0, 0};
    case_choisi(' ', &g, pos_act2, &p);
    assert(p.premier != NULL);
    assert(p.premier->c.lines == 0);
    assert(p.premier->c.cols == 0);
    assert(p.premier->next != NULL);
    assert(p.premier->next->c.lines == 1);
    assert(p.premier->next->c.cols == 1);
    assert(p.premier->next->next == NULL);

    case_choisi('a', &g, pos_act2, &p);
    assert(p.premier != NULL);
    assert(p.premier->c.lines == 1);
    assert(p.premier->c.cols == 1);
    assert(p.premier->next == NULL);

    case_choisi('a', &g, pos_act2, &p);
    assert(p.premier == NULL);

    free(p.premier);
}

void test_rempli_tableau() {
    Grille g;
    g.lines = 3;
    g.cols = 3;
    g.grille = (char **)malloc(sizeof(char *) * g.lines);
    for (int i = 0; i < g.lines; i++) {
        g.grille[i] = (char *)malloc(sizeof(char) * g.cols);
    }
    g.grille[0][0] = 'a';
    g.grille[0][1] = 'b';
    g.grille[0][2] = 'c';
    g.grille[1][0] = 'd';
    g.grille[1][1] = 'e';
    g.grille[1][2] = 'f';
    g.grille[2][0] = 'g';
    g.grille[2][1] = 'h';
    g.grille[2][2] = 'i';

    Pile p;
    p.premier = NULL;

    Case pos_act = {1, 1};
    empiler(&p, pos_act);

    Case pos_act2 = {0, 0};
    empiler(&p, pos_act2);

    Mot_choisi mot;
    mot.curlen = 0;

    rempli_tableau(&p, &mot, &g);
    assert(strcmp(mot.tab, "ae") == 0);

    for (int i = 0; i < g.lines; i++) {
        free(g.grille[i]);
    }
    free(g.grille);
}

void test_inverser_mot() {
    char mot[] = "bonjour";

    inverser_mot(mot);

    assert(strcmp(mot, "ruojnob") == 0);
}

void test_score() {
    EtatJeu etat;
    etat.score = 0;

    score("test", &etat);

    assert(etat.score == 4);

    etat.score = 0;

    score("te", &etat);

    assert(etat.score == 0);
}

void test_ajout_tab() {
    Save s;
    s.curlen = 0;

    int res = ajout_tab(&s, "test");

    assert(res == 1);
    assert(s.curlen == 1);
    assert(strcmp(s.save[0], "test") == 0);
}

void test_recherche() {
    Save s;
    s.curlen = 0;

    ajout_tab(&s, "test");

    int res = recherche(&s, "test");

    assert(res == 1);

    res = recherche(&s, "autre");

    assert(res == 0);
}

void test_load_fichier(){
    FILE *fichier = fopen("Mots","r");
    EnsembleMots ens;
    load_fichier(&ens,fichier);

    assert(load_fichier(&ens,fichier) == 1);
    assert(strcmp(ens.ens_mots[0],"a") == 0);
    assert(strcmp(ens.ens_mots[1],"aa") == 0);
    assert(strcmp(ens.ens_mots[2],"aaa") == 0);

    assert(strcmp(ens.ens_mots[3],"aah") == 0);
    assert(strcmp(ens.ens_mots[4],"aahed") == 0);
    assert(strcmp(ens.ens_mots[5],"aahing") == 0);

    //cas ou le fichier est nul 
    FILE *n = NULL;
    load_fichier(&ens,n);
    assert(load_fichier(&ens,n) == 0);

}



void test_recherche_mot(){
    FILE *fichier = fopen("Mots","r");
    EnsembleMots ens;
    load_fichier(&ens,fichier);

    assert(recherche_mot(&ens,"a") == 1);
    assert(recherche_mot(&ens,"abaca") == 1);
    assert(recherche_mot(&ens,"acanthotic") == 1);
    assert(recherche_mot(&ens,"zjndjndjd") == 0);
    assert(recherche_mot(&ens,"duibfe") == 0);

}



int main(void) {
    test_alloue_cell();
    test_init_pile();
    test_empiler();
    test_depiler();
    test_maj_vers_min();
    test_est_adjacent();
    test_case_choisi();
    test_rempli_tableau();
    test_load_fichier();
    test_recherche_mot();
}