/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_SIZE 100

void remplirTableauAleatoire(int tableau[], int *taille) {
    // Demander à l'utilisateur de donner la taille du tableau
    printf("Veuillez entrer la taille du tableau (max %d) : ", MAX_SIZE);
    scanf("%d", taille);

    // Vérifier que la taille est valide
    if (*taille <= 0 || *taille > MAX_SIZE) {
        printf("Taille invalide. Utilisation de la taille par défaut.\n");
        *taille = 10; // Taille par défaut
    }

    // Remplir le tableau avec des valeurs aléatoires
    srand(time(NULL));
    for (int i = 0; i < *taille; ++i) {
        tableau[i] = rand() % 100; // Valeurs aléatoires entre 0 et 99
    }
}

void afficherTableau(int tableau[], int taille) {
    const int screenWidth = 1200;
    const int screenHeight = 450;

    // Initialiser Raylib
    InitWindow(screenWidth, screenHeight, "Affichage de tableau avec Raylib");

    // Boucle principale
    while (!WindowShouldClose()) {
        // Effacer l'écran
        BeginDrawing();
        ClearBackground(RAYWHITE);
      // Hauteur fixe pour tous les rectangles
       const int hauteurFixe = 50;
        // Dessiner le tableau avec des carrés
        for (int i = 0; i < taille; ++i) {
            // Calculer la position verticale centrée en fonction de la hauteur fixe
            int yPos = screenHeight / 2 - hauteurFixe / 2;
           // Dessiner un carré à la position i * 60 + 10 en X, centré verticalement à yPos
        // La largeur du carré est de 50 pixels, la hauteur est fixée à hauteurFixe
    DrawRectangle(i * 60 + 10, yPos, 50, hauteurFixe, RED);
               // Dessiner le texte avec la valeur du tableau[i] au centre du carré
     DrawText(TextFormat("%d", tableau[i]), i * 60 + 30, yPos + 10, 20, WHITE);
}

        EndDrawing();
    }
    
    
     // Fermer la fenêtre à la fin de l'affichage
    CloseWindow();
}/*
int main() {
    const int screenWidth = 1200;
    const int screenHeight = 450;

    // Initialiser Raylib
    InitWindow(screenWidth, screenHeight, "Affichage de tableau avec Raylib");

    // Déclaration des variables
    int tableau[MAX_SIZE];
    int taille;
    int valeurRecherchee;
    int indiceTrouve = -1;

    // Remplir le tableau avec des valeurs aléatoires
    remplirTableauAleatoire(tableau, &taille);

    // Boucle principale
    while (!WindowShouldClose()) {
        // Effacer l'écran
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Afficher le tableau
        afficherTableau(tableau, taille);

        // Demander à l'utilisateur de saisir la valeur à rechercher
        if (IsKeyPressed(KEY_ENTER)) {
            printf("Veuillez entrer la valeur à rechercher : ");
            scanf("%d", &valeurRecherchee);
            indiceTrouve = rechercherValeur(tableau, taille, valeurRecherchee);
        }

        // Animer la recherche en changeant la couleur du rectangle contenant la valeur recherchée
        if (indiceTrouve != -1) {
            DrawRectangle(indiceTrouve * 60 + 10, screenHeight / 2 - 25, 50, 50, GREEN);
        }

        EndDrawing();
    }

    // Fermer la fenêtre à la fin de l'affichage
    CloseWindow();

    return 0;
}
*/
//fonction de tri

void triInsertion(int tableau[], int n, bool croissant) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = tableau[i];
        j = i - 1;

        if (croissant) {
            while (j >= 0 && tableau[j] > key) {
                tableau[j + 1] = tableau[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && tableau[j] < key) {
                tableau[j + 1] = tableau[j];
                j = j - 1;
            }
        }
        tableau[j + 1] = key;
    }
}
void VisualizationDuTri() {
    int tableau[MAX_SIZE];
    int taille;
    bool croissant = true;

    InitWindow(800, 600, "Sorting Visualization with Table");
    SetTargetFPS(60);

    remplirTableauAleatoire(tableau, &taille);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            if (CheckCollisionPointRec((Vector2){mouseX, mouseY}, (Rectangle){10, 10, 150, 40})) {
                croissant = true;
                triInsertion(tableau, taille, croissant);
            } else if (CheckCollisionPointRec((Vector2){mouseX, mouseY}, (Rectangle){170, 10, 150, 40})) {
                croissant = false;
                triInsertion(tableau, taille, croissant);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(10, 10, 150, 70, LIGHTGRAY);
        DrawText("tri croissant", 20, 20, 20, BLACK);

        DrawRectangle(170, 10, 180, 70, LIGHTGRAY);
        DrawText("tri decroissant", 180, 20, 20, BLACK);

        const int hauteurFixe = 50;
        for (int i = 0; i < taille; ++i) {
           
            int yPos = 500 - hauteurFixe;
            DrawRectangle(i * 60 + 10, yPos, 50, hauteurFixe, RED);
            DrawText(TextFormat("%d", tableau[i]), i * 60 + 30, yPos + 10, 20, WHITE);
        }

        EndDrawing();
    }
                                             
    CloseWindow();
}
/*void insertion(int tableau[], int *n, int valeur, int position) {
    // Vérifier si la position est valide
    if (position < 0 || position > *n) {
        printf("Position invalide. L'insertion n'a pas été effectuée.\n");
        return;
    }

    // Décaler les éléments pour faire de la place pour la nouvelle valeur
    for (int i = *n - 1; i >= position; i--) {
        tableau[i + 1] = tableau[i];
    }

    // Insérer la nouvelle valeur à la position spécifiée
    tableau[position] = valeur;

    // Incrémenter la taille du tableau
    (*n)++;
}

void insertionAnimation(int tableau[], int *n, int valeur, int position) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Insertion Animation with Raylib");

    // Délai en millisecondes pour chaque étape de l'animation
    int delay = 5000;

    int i;

    // Dessiner le tableau initial
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (i = 0; i < *n; ++i) {
        DrawRectangle(i * 60 + 10, screenHeight / 2 - 20, 50, 40, RED);
        DrawText(TextFormat("%d", tableau[i]), i * 60 + 30, screenHeight / 2 - 10, 20, BLACK);
    }
    EndDrawing();

    // Attendre avant de commencer l'animation
    sleep(delay);

    // Délai pour déplacer les éléments vers la droite avant l'insertion
    for (i = *n - 1; i >= position; i--) {
        // ... (partie inchangée)
    }

    // Insérer la nouvelle valeur
    tableau[position] = valeur;
    (*n)++;

    // Attendre que l'utilisateur appuie sur Entrée pour fermer la fenêtre
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
    }

    CloseWindow();
}

void suppression(int tableau[], int *n, int val) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (tableau[i] == val) {
            for (j = i; j < *n - 1; j++) {
                tableau[j] = tableau[j + 1];
            }

            (*n)--;
            break;
        }
    }
}

void visualisationsuppression(int tableau[], int *n, int val) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Suppression Animation with Raylib");

    int j, k;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (k = 0; k < *n; ++k) {
        DrawRectangle(k * 60 + 10, screenHeight / 2 - 20, 50, 40, RED);
        DrawText(TextFormat("%d", tableau[k]), k * 60 + 30, screenHeight / 2 - 10, 20, BLACK);
    }

    DrawText(TextFormat("Valeur à supprimer : %d", val), 10, 10, 20, BLACK);
   

    for (k = 0; k < *n; ++k) {
        DrawRectangle(k * 60 + 10, screenHeight / 2 - 20, 50, 40, RED);
        DrawText(TextFormat("%d", tableau[k]), k * 60 + 30, screenHeight / 2 - 10, 20, BLACK);
    }

    DrawRectangle(j * 60 + 10, screenHeight / 2 - 20, 50, 40, GREEN);
    DrawText("Suppression effectuée", 10, 40, 20, BLACK);

    EndDrawing();
    sleep(1000 * 5);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
    }

    CloseWindow();
}*/


int rechercheSeq(int tableau[], int taille) {
    /*int elementToSearch ;*/
    // Affiche le tableau initial
    
    int elementToSearch=0;
   

    // Affiche un champ de saisie pour l'élément à rechercher
    DrawText("Entrez l'élément à rechercher:", 10, 10, 20, BLACK);
   // DrawText(TextFormat("%d", elementToSearch), 10, 40, 20, BLACK);
 
   // Attend que l'utilisateur entre l'élément
    elementToSearch = GetKeyPressed();

    // Parcours du tableau pour trouver l'élément
    for (int i = 0; i < taille; ++i) {
        if (tableau[i] == elementToSearch) {
            // Retourne la position de l'élément s'il est trouvé
           // drawArray(tableau, taille, i, i);
            return i;
        }
    }

    // Retourne -1 si l'élément n'est pas trouvé
    return -1;
}
// Déclaration des fonctions pour chaque bouton
void bouton1();
void bouton2();
void bouton3();
void bouton4();

int main(){

   // int elementToSearch=0;
    // Initialisation de la fenêtre Raylib
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Menu avec Raylib");

    // Définition des dimensions et positions des boutons
    Rectangle boutonRect1 = { 50, 50, 200, 50 };
    Rectangle boutonRect2 = { 50, 120, 200, 50 };
    Rectangle boutonRect3 = { 50, 190, 200, 50 };
    Rectangle boutonRect4 = { 50, 260, 200, 50 };
    
    // Création d'un tableau d'entiers pour l'exemple
    int tableau[MAX_SIZE];
    int taille;

    // Boucle principale
    while (!WindowShouldClose()) {
        // Mise à jour

        // Dessin
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Dessin des boutons
        DrawRectangleRec(boutonRect1,BLUE);
        DrawRectangleRec(boutonRect2, BLUE);
        DrawRectangleRec(boutonRect3, BLUE);
        DrawRectangleRec(boutonRect4, BLUE);
          
        // Affichage du texte sur les boutons
        DrawText("Tri ", boutonRect1.x + 10, boutonRect1.y + 10, 20, WHITE);
        DrawText("Rechercher", boutonRect2.x + 10, boutonRect2.y + 10, 20, WHITE);
        DrawText("suppression", boutonRect3.x + 10, boutonRect3.y + 10, 20, WHITE);
        DrawText("Insertion", boutonRect4.x + 10, boutonRect4.y + 10, 20, WHITE);

        // Gestion des clics sur les boutons
        if (CheckCollisionPointRec(GetMousePosition(), boutonRect1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            VisualizationDuTri();
        }
        if (CheckCollisionPointRec(GetMousePosition(), boutonRect2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
           int res= rechercheSeq(int tableau[], int taille);

           
        }
        if (CheckCollisionPointRec(GetMousePosition(), boutonRect3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            /*visualisationsuppression( tableau, &taille,int  valeur);*/
        }
        if (CheckCollisionPointRec(GetMousePosition(), boutonRect4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
           /* insertionAnimation( tableau,&taille,valeur,int  position);*/
        }
       
        EndDrawing();
    }

    // Fermeture de la fenêtre
    CloseWindow();

    return 0;
}

// Définition des fonctions pour chaque bouton
void bouton1(int tableau[], int *taille) {
    VisualizationDuTri();
}



void bouton2(int tableau[], int *taille ) {
    int resultat= rechercheSeq(tableau, taille);
}
    
void bouton3() {
     /* visualisationsuppression( int tableau, &taille, int valeur);*/
}

void bouton4() {
   // insertionAnimation( int tableau,&taille, int valeur, int position);
}
