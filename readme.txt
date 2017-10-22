Rien ne vaut un petit ReadMe.txt


Pour ce programme, il existe 2 versions une avec les touches utilisateurs pour se deplacer (Q S D Z)et l'autre avec le déplacement aléatoire .
A chaque fois que la croix va toucher un endroit marquer d'une case 'O', elle va perdre un point de vie, ces derniers sont réglables dans le fichier function.h en tant que #define vieMAX. (vieMIN servait a tester les fonction d'arret utiliser avec exit(0)')
Le nombre d'obstacle, la taille du tableau et le nombre de niveau maximum sont aussi réglables dans les headers.

Dans le fichier des fonctions, on peut retrouver les fonctions NoRep et MyGetch, la première sert a l'actualisation de la console et ainsi ne pas avoir plusieurs grille , la seconde sert à repoertorier les touches utilisateurs dans la fonction des deplacements avec touches.
Ps : il y'a quelques peu de chances que ces fonctions ne marchent que sous windows, le cas écheant, il faudra mettre ces 2 fonctions en commentaires pour utiliser le programme sous linux et il faudra trouver une solution pour le rafraichissement de console.
Pour activer le deplacement avec touches, il y'a juste a aller dans le main.c et mettre deplacementaleatoire() en commentaire puis deplacementavectouche() en fonction valide et vice versa.


Je penses avoir fait le tour du programme, bonne compilation.
