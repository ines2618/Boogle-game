# Boogle-game

**Introduction**
The objective of this practical work was to implement the game of Boggle using coding. Throughout the practical work, we had to apply the reflection, analysis, and management techniques that we learned during the sessions.

**Implementation**

The project is divided into 3 modules:

   The "EnsembleMots" module is responsible for reading the file containing all the words and storing them in a static array.

    
     The "Grille" module handles random generation of the game board, word search in the word set to validate user-entered words via the graphical interface. This module contains a structure named "Save" which allows us to save the previously validated words by the player to prevent them from validating the same word repeatedly for maximum points.
   
      
   The "Graphique" module is responsible for displaying the entire interface (game board, score, etc.).
  During the course, an additional module was added to address a major issue in this practical work:
 
  
How to retrieve and delete each validated letter from the user in the correct order?
To address this issue, we used the Stack data structure, which allows us to push each validated letter onto the stack in the order they are entered by the    user.


The only "drawback" of this structure is that when we pop the stack, we obtain the word in reverse order. However, this is easily rectified using the       "inverser_mot()" function (see grille.h).

Finally, user input will be blocked if the desired cell to be validated is not adjacent to the previous one. This is indicated by a cell not being colored when the enter key is pressed.

Key Guide:
- "z" for top-left diagonal
- "r" for top-right diagonal
- "v" for bottom-right diagonal
- "x" for bottom-left diagonal
- Arrow keys for other directions

To compile the project, simply execute the "make boogle" command.

--------------------------------------------------------------------------------------------------------------------------------------------------------------

**French version**

Jeu du boogle

**Introduction**


L’objectif de ce TP a été de nous faire coder le jeu du Boggle.
Au cours de ce TP , nous avons dû mettre en œuvre ,les techniques de réflexion , d’analyse et de gestion que l’on a appris tout au long des séances.

**Implémentation**

Le projet est découpé en 3 modules :

Module EnsembleMots qui se charge de lire le fichier contenant tous les mots et de les stocker dans un tableau statique.


Module Grille qui s’occupe de tout ce qui est génération aléatoire du terrain , recherche de mot dans l’ensemble de mots afin de voir si un mot validé par l’utilisateur via l’interface graphique est valide , ce module contient une structure nommé Save comme son nom l’indique cette structure nous permettra d’effectuer une sauvegarde des mots précédemment validés par le joueur afin de vérifier si ce dernier ne valide pas le même mot encore et encore afin d’avoir un maximum de point.

Module graphique qui s’occupera d’afficher toute l’interface (grille , score ...)

Un module s’est ajouté en cours de route , une des problématiques majeurs de ce TP a été :
Comment faire pour récupérer chacune des lettres validées par l’utilisateur dans le bon ordre mais également de les supprimer ?
Pour répondre à cette problématique, nous avons utilisé la structure de Pile qui nous permet comme son nom l’indique d’empiler chacune des cases que l’utilisateur a validées et ainsi pour rajouter dans l’ordre les lettres validées par l’utilisateur.
Le seule « défaut » de cette structure est que lorsque l’on dépile la pile nous obtenons le mot à l’envers ., mais cela est vite rectifiable via la fonction inverser_mot() (cf grille.h)
  
Finalement , la saisie de l’utilisateur sera bloqué si la case qu’il souhaite validé n’est pas adjacente à l’avant dernière , cela se traduira par une case qui ne sera pas coloré lors de l’appuie sur entré.
Guide touche :
- z pour diagonale haut gauche
- r : diagonale haut droite
- v : diagonale bas droite
- x: diagonale bas gauche
- Flèche haut, bas , gauche , droite pour les autres directions

Finalement il vous suffira d’exécuter la commande "make boogle" afin de compiler le projet .

  
