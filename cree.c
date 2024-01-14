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


void insertion(int tableau[], int *n, int valeur, int position) {
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
    suppression(tableau, n, val);

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
}
int main() {
    int tableau[MAX_SIZE];
    int taille;
    int valeur=7;
    int position=4;

    // Appeler la fonction pour remplir le tableau
    remplirTableauAleatoire(tableau,&taille);

    // Appeler la fonction pour afficher le tableau
    //afficherTableau(tableau, taille);
    VisualizationDuTri();
    insertionAnimation(tableau,&taille,valeur,position);
    visualisationsuppression(tableau,&taille,valeur);
    
    return 0;
}