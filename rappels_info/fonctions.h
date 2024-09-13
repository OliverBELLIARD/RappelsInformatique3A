//
// Created by oliver on 10/09/24.
//

#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define TAILLE 10  // Taille du tableau, modifiable

void lireTableauDepuisFichier(const char *nomFichier, int **tableau, int *taille) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s.\n", nomFichier);
        exit(EXIT_FAILURE);
    }

    // Lire les nombres du fichier
    int capacite = 10;  // Capacité initiale du tableau
    *tableau = (int *)malloc(capacite * sizeof(int));
    if (*tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    int valeur;
    *taille = 0;
    while (fscanf(fichier, "%d", &valeur) == 1) {
        if (*taille >= capacite) {
            capacite *= 2;
            *tableau = (int *)realloc(*tableau, capacite * sizeof(int));
            if (*tableau == NULL) {
                fprintf(stderr, "Erreur de réallocation mémoire.\n");
                exit(EXIT_FAILURE);
            }
        }
        (*tableau)[*taille] = valeur;
        (*taille)++;
    }

    fclose(fichier);
}

void ecrireTableauDansFichier(const char *nomFichier, int *tableau, int taille) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s.\n", nomFichier);
        exit(EXIT_FAILURE);
    }

    fprintf(fichier, "Tableau après tri : ");
    for (int i = 0; i < taille; i++) {
        fprintf(fichier, "%d ", tableau[i]);
    }
    fprintf(fichier, "\n");

    fclose(fichier);
}

void remplirTableau(int *tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        tableau[i] = rand() % 100;  // Génère un nombre entre 0 et 99
    }
}

void afficherTableau(int *tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

void trouverMax(int *tableau, int taille, int *max, int *indiceMax) {
    *max = tableau[0];
    *indiceMax = 0;

    for (int i = 1; i < taille; i++) {
        if (tableau[i] > *max) {
            *max = tableau[i];
            *indiceMax = i;
        }
    }
}

void trouverMin(int *tableau, int taille, int *min, int *indiceMin) {
    *min = tableau[0];
    *indiceMin = 0;

    for (int i = 1; i < taille; i++) {
        if (tableau[i] < *min) {
            *min = tableau[i];
            *indiceMin = i;
        }
    }
}

void trierTableau(int *tableau, int taille) {
    int temp;
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - 1 - i; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }
}

void boucles_algos_simples() {
    int tableau[TAILLE];

    remplirTableau(tableau, TAILLE);
    printf("Tableau avant tri : ");
    afficherTableau(tableau, TAILLE);
    printf("Le tableau se trouve à l'adresse : %p\n", tableau);

    int max, indiceMax;
    printf("Les variables 'max' et 'indiceMax' se trouvent respectivement aux adresses : %p et %p\n",
        &max, &indiceMax);
    trouverMax(tableau, TAILLE, &max, &indiceMax);
    printf("Valeur maximale : %d à l'indice %d\n", max, indiceMax);

    int min, indiceMin;
    printf("Les variables 'min' et 'indiceMin' se trouvent respectivement aux adresses : %p et %p\n",
        &min, &indiceMin);
    trouverMin(tableau, TAILLE, &min, &indiceMin);
    printf("Valeur minimale : %d à l'indice %d\n", min, indiceMin);

    trierTableau(tableau, TAILLE);
    printf("Tableau après tri : ");
    afficherTableau(tableau, TAILLE);
}

void alloc_memoire() {
    int taille;

    // Demander à l'utilisateur la taille du tableau
    printf("Entrez la taille du tableau : ");
    if (scanf("%d", &taille) != 1 || taille <= 0) {
        fprintf(stderr, "Taille invalide.\n");
        exit(EXIT_FAILURE);
    }

    // Allouer de la mémoire pour le tableau
    int *tableau = (int *)malloc(taille * sizeof(int));
    if (tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Remplir, afficher, trouver les min et max, trier
    remplirTableau(tableau, taille);
    printf("Tableau avant tri : ");
    afficherTableau(tableau, taille);

    int max, indiceMax;
    printf("Les variables 'max' et 'indiceMax' se trouvent respectivement aux adresses : %p et %p\n",
        &max, &indiceMax);
    trouverMax(tableau, taille, &max, &indiceMax);
    printf("Valeur maximale : %d à l'indice %d\n", max, indiceMax);

    int min, indiceMin;
    printf("Les variables 'min' et 'indiceMin' se trouvent respectivement aux adresses : %p et %p\n",
        &min, &indiceMin);
    trouverMin(tableau, taille, &min, &indiceMin);
    printf("Valeur minimale : %d à l'indice %d\n", min, indiceMin);

    trierTableau(tableau, taille);
    printf("Tableau après tri : ");
    afficherTableau(tableau, taille);

    // Libérer la mémoire allouée
    free(tableau);
}

void manip_pointeurs() {
    int a;
    int * p;
    /* Parmi les deux lignes suivantes, laquelle est la bonne? Pourquoi?
     * reponse : p est de type pointeur d'entier, il n'acceptera donc que le pointeur de a, soit &a.
    * Commentez la ligne fausse.
    */
    //*p = a;
    p = &a;
    /* Que représente &p? Que représente p? Et *p?
     * &p représente l'adresse de p, p représente une adresse dans la mémoire
     * et *p représente le contenu pointé par p
     */
    /* Expliquer le comportement des lignes suivantes
     * réponse : Comme p pointe vers l'adresse de a (&a), écrire *p revient en pratique à écrire a.
     */
    printf("%d %d\n", a, *p);
    *p = 5;
    printf("%d %d\n", a, *p);
    a = 12;
    printf("%d %d\n", a, *p);
    /* Faites vérifier par l'encadrant */
}

void manip_fichiers() {
    int *tableau;
    int taille;

    // Lire le tableau depuis le fichier
    lireTableauDepuisFichier("nombres.txt", &tableau, &taille);

    printf("Tableau avant tri : ");
    afficherTableau(tableau, taille);

    int max, indiceMax;
    trouverMax(tableau, taille, &max, &indiceMax);
    printf("Valeur maximale : %d à l'indice %d\n", max, indiceMax);

    int min, indiceMin;
    trouverMin(tableau, taille, &min, &indiceMin);
    printf("Valeur minimale : %d à l'indice %d\n", min, indiceMin);

    trierTableau(tableau, taille);
    printf("Tableau après tri : ");
    afficherTableau(tableau, taille);

    // Écrire les résultats dans un autre fichier
    ecrireTableauDansFichier("resultats.txt", tableau, taille);

    // Libérer la mémoire allouée
    free(tableau);
}
#endif //FONCTIONS_H
