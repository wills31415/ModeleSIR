#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include "libTableauNoir.h"

#include "modele_SIR.h"



/* Déclaration des types. */


/* Déclaration des fonctions. */

/* Prendre en compte le taux de natalité. */


int main(int argc, char* argv[], char* arge[])
{
    FILE* out = fopen("resultats.dat", "w+");

    init_rand();

    size_t nb_iterations = 1e8;

    int taille_population = 1e6;
    int nb_malades = 10;

    int n_IR = 15;
    int n_RS = 90;
    double p_I = 34437. / 214562;
    double p_M = 2.6 / 100;

    population_t P = init_population(taille_population, nb_malades, n_IR, n_RS, p_I, p_M);

    for(size_t i = 0; i <= nb_iterations; ++i)
    {
        fprintf(out, "%d     %d     %d     %d\n", P.N[S], P.N[I], P.N[R], P.N[M]);
        if(P.N[I] == 0 && P.N[R] == 0) break;
        P = transition(P);
    }

    fclose(out);


    return EXIT_SUCCESS;
}


// Définition des fonctions.
