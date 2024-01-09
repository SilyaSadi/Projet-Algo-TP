#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
}

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


int main() {
    int tableau[MAX_SIZE];
    int taille;

    // Appeler la fonction pour remplir le tableau
    remplirTableauAleatoire(tableau,&taille);

    // Appeler la fonction pour afficher le tableau
    //afficherTableau(tableau, taille);
    VisualizationDuTri();
    return 0;
}