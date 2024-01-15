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
#define MAX_ELEMENTS 100
#define MAX_ELEMENTS 100
/*
// Structure pour le tableau
typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} Array;

// Fonctions pour les opérations sur le tableau
void trierTableauCroissant(Array *arr);
void trierTableauDecroissant(Array *arr);
int chercherValeur(Array *arr, int valeur);
void ajouterElement(Array *arr, int element);
void supprimerElement(Array *arr, int index);

// Fonction pour afficher une fenêtre de saisie de texte
char *ShowTextInputBox(int posX, int posY, const char *title, const char *message, const char *defaultValue);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialisation du tableau
    Array tableau = {{9, 5, 2, 7, 1}, 5};

    // Initialisation de raylib
    InitWindow(screenWidth, screenHeight, "Interface Graphique avec raylib");

    while (!WindowShouldClose()) {
        // Mise à jour

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Bouton 1 : Tri croissant du tableau
            if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){10, 10, 120, 40})) {
                trierTableauCroissant(&tableau);
            }

            // Bouton 2 : Tri décroissant du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){140, 10, 160, 40})) {
                trierTableauDecroissant(&tableau);
            }

            // Bouton 3 : Ajout d'un élément au tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){310, 10, 120, 40})) {
                char *input = ShowTextInputBox(10, 100, "Ajouter", "Entrez la valeur à ajouter:", "");
                if (input[0] != '\0') {
                    int nouvelElement = atoi(input);
                    ajouterElement(&tableau, nouvelElement);
                }
                free(input); // Libérer la mémoire allouée par ShowTextInputBox
            }

            // Bouton 4 : Suppression d'un élément du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){440, 10, 120, 40})) {
                char *input = ShowTextInputBox(10, 100, "Supprimer", "Entrez l'indice à supprimer:", "");
                if (input[0] != '\0') {
                    int indexSuppression = atoi(input);
                    supprimerElement(&tableau, indexSuppression);
                }
                free(input); // Libérer la mémoire allouée par ShowTextInputBox
            }

            // Bouton 5 : Recherche d'une valeur dans le tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){570, 10, 160, 40})) {
                char *input = ShowTextInputBox(10, 100, "Rechercher", "Entrez la valeur à rechercher:", "");
                if (input[0] != '\0') {
                    int valeurRecherchee = atoi(input);
                    int index = chercherValeur(&tableau, valeurRecherchee);
                    if (index != -1) {
                        // La valeur a été trouvée à l'indice index
                    } else {
                        // La valeur n'a pas été trouvée dans le tableau
                    }
                }
                free(input); // Libérer la mémoire allouée par ShowTextInputBox
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dessiner les boutons
        DrawRectangle(10, 10, 120, 40, BLUE);
        DrawText("Tri Croissant", 20, 20, 20, WHITE);

        DrawRectangle(140, 10, 160, 40, RED);
        DrawText("Tri Décroissant", 150, 20, 20, WHITE);

        DrawRectangle(310, 10, 120, 40, GREEN);
        DrawText("Ajouter", 320, 20, 20, WHITE);

        DrawRectangle(440, 10, 120, 40, PURPLE);
        DrawText("Supprimer", 450, 20, 20, WHITE);

        DrawRectangle(570, 10, 160, 40, ORANGE);
        DrawText("Rechercher", 580, 20, 20, WHITE);

        // Dessiner le tableau
        DrawText("Tableau:", 10, 70, 20, BLACK);
        for (int i = 0; i < tableau.size; i++) {
            DrawText(TextFormat("%d ", tableau.data[i]), 10 + i * 40, 100, 20, BLACK);
        }

        EndDrawing();
    }

    // Fermer raylib
    CloseWindow();

    return 0;
}


// Fonction pour trier le tableau en ordre croissant
void trierTableauCroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour trier le tableau en ordre décroissant
void trierTableauDecroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] < arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour chercher une valeur dans le tableau
int chercherValeur(Array *arr, int valeur) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == valeur) {
            return i; // La valeur a été trouvée à l'indice i
        }
    }
    return -1; // La valeur n'a pas été trouvée dans le tableau
}

// Fonction pour ajouter un élément au tableau
void ajouterElement(Array *arr, int element) {
    if (arr->size < MAX_ELEMENTS) {
        arr->data[arr->size++] = element;
    }
}

// Fonction pour supprimer un élément du tableau à un indice donné
void supprimerElement(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        // Décaler les éléments vers la gauche à partir de l'indice
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    }
}

// Fonction pour afficher une fenêtre de saisie de texte
char *ShowTextInputBox(int posX, int posY, const char *title, const char *message, const char *defaultValue) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    char *inputText = malloc(sizeof(char) * 256);

    // Initialisation de raylib pour la fenêtre de saisie de texte
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            CloseWindow();
            break;
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Afficher le message et la zone de saisie de texte
        DrawText(message, posX, posY, 20, BLACK);
        DrawText(defaultValue, posX, posY + 30, 20, DARKGRAY);
        DrawRectangleLines(posX, posY + 30, 200, 30, GRAY);

        EndDrawing();
    }

    // Copier la valeur saisie par l'utilisateur
    strcpy(inputText, defaultValue);

    return inputText;
}*/
/*
#define MAX_ELEMENTS 100

// Structure pour le tableau
typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} Array;

// Fonctions pour les opérations sur le tableau
void trierTableauCroissant(Array *arr);
void trierTableauDecroissant(Array *arr);
int chercherValeur(Array *arr, int valeur);
void ajouterElement(Array *arr, int element);
void supprimerElement(Array *arr, int index);

// Fonction pour afficher une fenêtre de saisie de texte
void ShowTextInputBox(char *title, char *message, char *defaultValue);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialisation du tableau
    Array tableau = {{9, 5, 2, 7, 1}, 5};

    // Initialisation de raylib
    InitWindow(screenWidth, screenHeight, "Interface Graphique avec raylib");

    while (!WindowShouldClose()) {
        // Mise à jour

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Bouton 1 : Tri croissant du tableau
            if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){10, 10, 120, 40})) {
                trierTableauCroissant(&tableau);
            }

            // Bouton 2 : Tri décroissant du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){140, 10, 160, 40})) {
                trierTableauDecroissant(&tableau);
            }

            // Bouton 3 : Ajout d'un élément au tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){310, 10, 120, 40})) {
                ShowTextInputBox("Ajouter", "Entrez la valeur à ajouter:", "");
                if (TextLength != 0) {
                    int nouvelElement = atoi(GetText());
                    ajouterElement(&tableau, nouvelElement);
                }
            }

            // Bouton 4 : Suppression d'un élément du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){440, 10, 120, 40})) {
                ShowTextInputBox("Supprimer", "Entrez l'indice à supprimer:", "");
                if (TextLength != 0) {
                    int indexSuppression = atoi(GetText());
                    supprimerElement(&tableau, indexSuppression);
                }
            }

            // Bouton 5 : Recherche d'une valeur dans le tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){570, 10, 160, 40})) {
                ShowTextInputBox("Rechercher", "Entrez la valeur à rechercher:", "");
                if (TextLength != 0) {
                    int valeurRecherchee = atoi(GetText());
                    int index = chercherValeur(&tableau, valeurRecherchee);
                    if (index != -1) {
                        // La valeur a été trouvée à l'indice index
                    } else {
                        // La valeur n'a pas été trouvée dans le tableau
                    }
                }
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dessiner les boutons
        DrawRectangle(10, 10, 120, 40, BLUE);
        DrawText("Tri Croissant", 20, 20, 20, WHITE);

        DrawRectangle(140, 10, 160, 40, RED);
        DrawText("Tri Décroissant", 150, 20, 20, WHITE);

        DrawRectangle(310, 10, 120, 40, GREEN);
        DrawText("Ajouter", 320, 20, 20, WHITE);

        DrawRectangle(440, 10, 120, 40, PURPLE);
        DrawText("Supprimer", 450, 20, 20, WHITE);

        DrawRectangle(570, 10, 160, 40, ORANGE);
        DrawText("Rechercher", 580, 20, 20, WHITE);

        // Dessiner le tableau
        DrawText("Tableau:", 10, 70, 20, BLACK);
        for (int i = 0; i < tableau.size; i++) {
            DrawText(TextFormat("%d ", tableau.data[i]), 10 + i * 40, 100, 20, BLACK);
        }

        EndDrawing();
    }

    // Fermer raylib
    CloseWindow();

    return 0;
}

// Fonction pour trier le tableau en ordre croissant
void trierTableauCroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour trier le tableau en ordre décroissant
void trierTableauDecroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] < arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour chercher une valeur dans le tableau
int chercherValeur(Array *arr, int valeur) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == valeur) {
            return i; // La valeur a été trouvée à l'indice i
        }
    }
    return -1; // La valeur n'a pas été trouvée dans le tableau
}

// Fonction pour ajouter un élément au tableau
void ajouterElement(Array *arr, int element) {
    if (arr->size < MAX_ELEMENTS) {
        arr->data[arr->size++] = element;
    }
}

// Fonction pour supprimer un élément du tableau à un indice donné
void supprimerElement(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        // Décaler les éléments vers la gauche à partir de l'indice
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    }
}

// Fonction pour afficher une fenêtre de saisie de texte
void ShowTextInputBox(char *title, char *message, char *defaultValue) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    char buffer[256] = "";

    // Initialisation de raylib pour la fenêtre de saisie de texte
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            strcpy(defaultValue, buffer);
            break;
        }

        // Mise à jour de la saisie de texte
        int key = GetKeyPressed();
        if (key > 0) {
            int len = strlen(buffer);
            if (key == KEY_BACKSPACE) {
                if (len > 0) {
                    buffer[len - 1] = '\0';
                }
            } else if (len < 255) {
                buffer[len] = (char)key;
                buffer[len + 1] = '\0';
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Afficher le message et la zone de saisie de texte
        DrawText(message, 10, 50, 20, BLACK);
        DrawRectangle(10, 80, 200, 30, GRAY);
        DrawText(buffer, 20, 85, 20, DARKGRAY);

        EndDrawing();
    }

    // Fermer la fenêtre de saisie de texte
    CloseWindow();
}*/








/*#define MAX_ELEMENTS 100

// Structure pour le tableau
typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} Array;

// Variable globale pour stocker la saisie de texte
char inputText[256] = "";

// Fonctions pour les opérations sur le tableau
void trierTableauCroissant(Array *arr);
void trierTableauDecroissant(Array *arr);
int chercherValeur(Array *arr, int valeur);
void ajouterElement(Array *arr, int element);
void supprimerElement(Array *arr, int index);

// Fonction pour afficher une fenêtre de saisie de texte
void ShowTextInputBox(char *title, char *message, char *defaultValue);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialisation du tableau
    Array tableau = {{9, 5, 2, 7, 1}, 5};

    // Initialisation de raylib
    InitWindow(screenWidth, screenHeight, "Interface Graphique avec raylib");

    while (!WindowShouldClose()) {
        // Mise à jour

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Bouton 1 : Tri croissant du tableau
            if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){10, 10, 120, 40})) {
                trierTableauCroissant(&tableau);
            }

            // Bouton 2 : Tri décroissant du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){140, 10, 160, 40})) {
                trierTableauDecroissant(&tableau);
            }

            // Bouton 3 : Ajout d'un élément au tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){310, 10, 120, 40})) {
                ShowTextInputBox("Ajouter", "Entrez la valeur à ajouter:", "");
                if (inputText[0] != '\0') {
                    int nouvelElement = atoi(inputText);
                    ajouterElement(&tableau, nouvelElement);
                }
            }

            // Bouton 4 : Suppression d'un élément du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){440, 10, 120, 40})) {
                ShowTextInputBox("Supprimer", "Entrez l'indice à supprimer:", "");
                if (inputText[0] != '\0') {
                    int indexSuppression = atoi(inputText);
                    supprimerElement(&tableau, indexSuppression);
                }
            }

            // Bouton 5 : Recherche d'une valeur dans le tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){570, 10, 160, 40})) {
                ShowTextInputBox("Rechercher", "Entrez la valeur à rechercher:", "");
                if (inputText[0] != '\0') {
                    int valeurRecherchee = atoi(inputText);
                    int index = chercherValeur(&tableau, valeurRecherchee);
                    if (index != -1) {
                        // La valeur a été trouvée à l'indice index
                    } else {
                        // La valeur n'a pas été trouvée dans le tableau
                    }
                }
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dessiner les boutons
        DrawRectangle(10, 10, 120, 40, BLUE);
        DrawText("Tri Croissant", 20, 20, 20, WHITE);

        DrawRectangle(140, 10, 160, 40, RED);
        DrawText("Tri Décroissant", 150, 20, 20, WHITE);

        DrawRectangle(310, 10, 120, 40, GREEN);
        DrawText("Ajouter", 320, 20, 20, WHITE);

        DrawRectangle(440, 10, 120, 40, PURPLE);
        DrawText("Supprimer", 450, 20, 20, WHITE);

        DrawRectangle(570, 10, 160, 40, ORANGE);
        DrawText("Rechercher", 580, 20, 20, WHITE);

        // Dessiner le tableau
        DrawText("Tableau:", 10, 70, 20, BLACK);
        for (int i = 0; i < tableau.size; i++) {
            DrawText(TextFormat("%d ", tableau.data[i]), 10 + i * 40, 100, 20, BLACK);
        }

        EndDrawing();
    }

    // Fermer raylib
    CloseWindow();

    return 0;
}

// Fonction pour trier le tableau en ordre croissant
void trierTableauCroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour trier le tableau en ordre décroissant
void trierTableauDecroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] < arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour chercher une valeur dans le tableau
int chercherValeur(Array *arr, int valeur) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == valeur) {
            return i; // La valeur a été trouvée à l'indice i
        }
    }
    return -1; // La valeur n'a pas été trouvée dans le tableau
}

// Fonction pour ajouter un élément au tableau
void ajouterElement(Array *arr, int element) {
    if (arr->size < MAX_ELEMENTS) {
        arr->data[arr->size++] = element;
    }
}

// Fonction pour supprimer un élément du tableau à un indice donné
void supprimerElement(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        // Décaler les éléments vers la gauche à partir de l'indice
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    }
}

// Fonction pour afficher une fenêtre de saisie de texte
void ShowTextInputBox(char *title, char *message, char *defaultValue) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialisation de raylib pour la fenêtre de saisie de texte
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    strcpy(inputText, defaultValue);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }

        // Mise à jour de la saisie de texte
        int key = GetKeyPressed();
        if (key > 0) {
            int len = strlen(inputText);
            if (key == KEY_BACKSPACE) {
                if (len > 0) {
                    inputText[len - 1] = '\0';
                }
            } else if (len < 255) {
                inputText[len] = (char)key;
                inputText[len + 1] = '\0';
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Afficher le message et la zone de saisie de texte
        DrawText(message, 10, 50, 20, BLACK);
        DrawRectangle(10, 80, 200, 30, GRAY);
        DrawText(inputText, 20, 85, 20, DARKGRAY);

        EndDrawing();
    }

    // Fermer la fenêtre de saisie de texte
    CloseWindow();
}*/
#define MAX_ELEMENTS 100

// Structure pour le tableau
typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} Array;

// Fonctions pour les opérations sur le tableau
void trierTableauCroissant(Array *arr);
void trierTableauDecroissant(Array *arr);
int chercherValeur(Array *arr, int valeur);
void ajouterElement(Array *arr, int element);
void supprimerElement(Array *arr, int index);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialisation du tableau
    Array tableau = {{9, 5, 2, 7, 1}, 5};

    // Initialisation de raylib
    InitWindow(screenWidth, screenHeight, "Interface Graphique avec raylib");

    while (!WindowShouldClose()) {
        // Mise à jour

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Bouton 1 : Tri croissant du tableau
            if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){10, 10, 120, 40})) {
                trierTableauCroissant(&tableau);
            }

            // Bouton 2 : Tri décroissant du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){140, 10, 160, 40})) {
                trierTableauDecroissant(&tableau);
            }

            // Bouton 3 : Ajout d'un élément au tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){310, 10, 120, 40})) {
                int nouvelElement = 15; // Vous pouvez changer cette valeur
                ajouterElement(&tableau, nouvelElement);
            }

            // Bouton 4 : Suppression d'un élément du tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){440, 10, 120, 40})) {
                int indexSuppression = 2; // Vous pouvez changer cette valeur
                supprimerElement(&tableau, indexSuppression);
            }

            // Bouton 5 : Recherche d'une valeur dans le tableau
            else if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){570, 10, 160, 40})) {
                int valeurRecherchee = 15; // Vous pouvez changer cette valeur
                int index = chercherValeur(&tableau, valeurRecherchee);
                if (index != -1) {
                    // La valeur a été trouvée à l'indice index
                } else {
                    // La valeur n'a pas été trouvée dans le tableau
                }
            }
        }

        // Dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dessiner les boutons
        DrawRectangle(10, 10, 120, 40, BLUE);
        DrawText("Tri Croissant", 20, 20, 20, WHITE);

        DrawRectangle(140, 10, 160, 40, RED);
        DrawText("Tri Décroissant", 150, 20, 20, WHITE);

        DrawRectangle(310, 10, 120, 40, GREEN);
        DrawText("Ajouter", 320, 20, 20, WHITE);

        DrawRectangle(440, 10, 120, 40, PURPLE);
        DrawText("Supprimer", 450, 20, 20, WHITE);

        DrawRectangle(570, 10, 160, 40, ORANGE);
        DrawText("Rechercher", 580, 20, 20, WHITE);

        // Dessiner le tableau
        DrawText("Tableau:", 10, 70, 20, BLACK);
        for (int i = 0; i < tableau.size; i++) {
            DrawText(TextFormat("%d ", tableau.data[i]), 10 + i * 40, 100, 20, BLACK);
        }

        EndDrawing();
    }

    // Fermer raylib
    CloseWindow();

    return 0;
}

// Fonction pour trier le tableau en ordre croissant
void trierTableauCroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour trier le tableau en ordre décroissant
void trierTableauDecroissant(Array *arr) {
    // Utilisation de l'algorithme de tri à bulles pour cet exemple
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] < arr->data[j + 1]) {
                // Échanger les éléments
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

// Fonction pour chercher une valeur dans le tableau
int chercherValeur(Array *arr, int valeur) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == valeur) {
            return i; // La valeur a été trouvée à l'indice i
        }
    }
    return -1; // La valeur n'a pas été trouvée dans le tableau
}

// Fonction pour ajouter un élément au tableau
void ajouterElement(Array *arr, int element) {
    if (arr->size < MAX_ELEMENTS) {
        arr->data[arr->size++] = element;
    }
}

// Fonction pour supprimer un élément du tableau à un indice donné
void supprimerElement(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        // Décaler les éléments vers la gauche à partir de l'indice
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    }
}