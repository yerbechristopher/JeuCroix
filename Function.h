#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define nbligne 10
#define nbcolonne 10
#define nbobstacle 25
#define TempsDeRepos 200

#define vieMAX 1000
#define vieMIN 10

#define NiveauMax 100

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

int vie = vieMAX;
int Niveau = 0;

/*fonction pour permettre le reaffichage sans multiplier les grilles sous windows */
void Norep(int x,int y){

#ifdef _WIN32
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C);
#endif
    // trouver alternative hors Windows.
}

/* Fonction pour initialiser la grille avec des '.' */
void initGrille(char grille[nbligne][nbcolonne],int x,int y){
    int i, j;

    for (i=0;i<nbligne;i++)
     {
        for (j=0;j<nbcolonne;j++)
        {
             grille[i][j]='.';
        }
     }

}

/* Fonction pour lire la grille */
void Afficher(char grille[nbligne][nbcolonne],int x,int y){
    int i, j;
    Norep(0,0);
    for(i=0;i<nbligne;i++){
        for(j=0;j<nbcolonne;j++){
                if (i==x && j==y)
                printf("X ");
                else
            printf("%c ",grille[i][j]);
        }
        printf("\n");
    }
    printf("\n \t ****  Vos Vie : %d ****\n",vie);
    printf("\n \t ****  Niveau : %d ****\n",Niveau);
}


/*Nous allons ici placer des obstacles aléatoirement sur la grille */
int obst(char grille[nbligne][nbcolonne]){
    int i=0, x=0, y=0;

    while(i<nbobstacle){
        x=rand() %nbligne;
        y=rand() %nbcolonne;

        if (grille[x][y] == '.'){
            grille[x][y] = 'O';
        }
        i++;
    }
}

/*On pose une sortie S pour changer de niveau*/
void poserSortie(char grille[nbligne][nbcolonne]){
  int x=0, y=0;
   x=rand() %nbligne;
   y=rand() %nbcolonne;

   if (grille[x][y] == '.')
            grille[x][y] = 'S';

}


/*On va tester la présence d'un obstacle, si il y'a un O on va sortir de la fonction sinon on incremente le pas*/
void TesterMove(char grille[nbligne][nbcolonne],int* x,int* y,int pasX,int pasY){

    if (grille[*x+pasX][*y+pasY]=='O')
        {
         vie = vie -1;
         return;
        }
    if (*x+pasX <0 || *y+pasY <0)
        return;
    if (*x+pasX > (nbligne -1) || *y+pasY > (nbcolonne -1))
        return;
    if (grille[*x+pasX][*y+pasY]=='S')
              {
                lancerJeu(grille,0,0);
                Niveau = Niveau +1 ;
                vie = vie + 100;
              }
    if (vie <= 0 || Niveau == NiveauMax)
    {

        printf("Vous avez assez joue pour aujourd'hui \n \t ***BYE*** \n ");
        exit(0);
    }

    (*x)+=pasX;
    (*y)+=pasY;
}


/*recueillir information clavier */
int MyGetch(){

#ifdef _WIN32
    return getch();
#endif
// trouver alternative hors Windows.
}

/* Fonction pour déplacer la croix*/
int deplacementavectouche(char grille[nbligne][nbcolonne],int touche,int x,int y){
    touche = 0;
    while(touche !=27) // la touche ECHAP
    {
        Afficher(grille,x,y);
        touche = MyGetch();
        switch(touche)
        {
        case 'q':
            TesterMove(grille,&x,&y,0,-1);
            break;
        case 'd':
            TesterMove(grille,&x,&y,0,1);
            break;
        case 'z':
            TesterMove(grille,&x,&y,-1,0);
            break;
        case 's':
            TesterMove(grille,&x,&y,1,0);
        default:
            break;
        }
    }

}

/* Fonction pour déplacer la croix*/

int deplacementaleatoire(char grille[nbligne][nbcolonne],int touche,int x,int y){
    touche = 0;
    int toucheprec=2;
    while(touche!=27) // la touche ECHAP
    {
        Afficher(grille,x,y);
        touche = rand()%4;
        if(touche!=toucheprec)
        {

        switch(touche)
        {
        case 0:
            TesterMove(grille,&x,&y,0,-1);
            break;
        case 1:
            TesterMove(grille,&x,&y,0,1);
            break;
        case 2:
            TesterMove(grille,&x,&y,-1,0);
            break;
        case 3:
            TesterMove(grille,&x,&y,1,0);
        default:
            break;
        }
        toucheprec = touche ;
        Sleep(TempsDeRepos); // pause pour ralentir la boucle
        }
    }
}


void lancerJeu(char grille[nbligne][nbcolonne],int x,int y)
{

    initGrille(grille, x, y);
    poserSortie(grille);
    obst(grille);
}

/*
void RelancerJeu(char grille[nbligne][nbcolonne])
{
    if (vie == 0 || Niveau == 10)
    {
        char rep;
        printf("voulez vous recommencer ? 'o' pour continuer ou 'n' pour sortir\n");
        scanf("%c", &rep);
        if(rep=='o')
        {
        vie = 10 ;
        Niveau = 0;
        lancerJeu(grille,0,0);
        }
        else
            exit(0);
    }
}
*/


