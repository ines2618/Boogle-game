#ifndef __ENSMOT__

#define __ENSMOT__

#include <stdio.h>

typedef struct _ensemblemots
{
    char *ens_mots[370103];
}EnsembleMots;



/// @brief Fonction qui ajoutera les mots du fichier 1 par 1 dans un ensemble de mots
/// @param ens 
/// @param fichier 
/// return 0 si il y'a eu un problème , 1 sinon
int load_fichier(EnsembleMots *ens , FILE *fichier);


/// @brief fonction qui effectue une recherche la presénce d'un mot dans l'ensemble (par dicotomie)
/// @param ens 
/// @param mot 
/// @return 1 si le mot est présent , 0 sinon
int recherche_mot(EnsembleMots *ens ,char * m);


/// @brief fonction qui libère l'ensemble mots
/// @param ens 
void free_ensemblemots(EnsembleMots *ens);


#endif

