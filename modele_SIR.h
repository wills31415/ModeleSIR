#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include "libTableauNoir.h"



/* Déclaration des types et structures. */
typedef enum {S = 0, I, R, M} etat_t;

typedef struct
{
    int N[4];
    int n_IR;
    int n_RS;
    double p_I;
    double p_M;
} population_t;



/* Déclaration des fonctions. */

void init_rand(void);

int rand_n(size_t n, double p);

population_t init_population(int taille_population, int nb_malades, int n_IR, int n_RS, double p_I, double p_M);


population_t transition(population_t P);
