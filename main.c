#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.h"





int main()
{
    int touche = 0;
    int absJoueur,ordJoueur;
    //on initialise les coordonnées du joueur X
    absJoueur = ordJoueur = 0;

    char grille[nbligne][nbcolonne];

    srand(time(NULL));

    /* on initialise la grille de jeu */
    lancerJeu(grille,absJoueur, ordJoueur);
    /*Afficher(grille,absJoueur, ordJoueur);*/
    deplacementavectouche(grille,touche,absJoueur,ordJoueur);
    //deplacementaleatoire(grille,touche,absJoueur,ordJoueur);

    return 0;
}
