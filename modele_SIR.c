#include "modele_SIR.h"



/* Définition des fonctions. */

void init_rand(void)
{
    srand(time(NULL) + clock());
    srand(rand() * clock() + time(NULL));
}


int rand_n(size_t n, double p)
{
    assert(0 <= p);
    assert(p <= 1);

    int nb_succes = 0;

    for(size_t i = 0; i < n; ++i) nb_succes += ((double)rand() / RAND_MAX <= p);

    return nb_succes;
}


population_t init_population(int taille_population, int nb_malades, int n_IR, int n_RS, double p_I, double p_M)
{
    assert(taille_population >= 0);
    assert(nb_malades >= 0);
    assert(nb_malades <= taille_population);
    assert(n_IR > 0);
    assert(n_RS > 0);
    assert(0 <= p_I);
    assert(p_I <= 1);
    assert(0 <= p_M);
    assert(p_M <= 1);

    population_t P;
    P.N[S] = taille_population - nb_malades;
    P.N[I] = nb_malades;
    P.N[R] = 0;
    P.N[M] = 0;
    P.n_IR = n_IR;
    P.n_RS = n_RS;
    P.p_I = p_I;
    P.p_M = p_M;

    return P;
}


population_t transition(population_t P)
{
    int nb_SI = rand_n(P.N[S], P.p_I * 4 * P.N[I] * (P.N[S] + P.N[R] + P.N[M]) / pow(P.N[S] + P.N[I] + P.N[R] + P.N[M], 2));
    int nb_IR = rand_n(P.N[I], 1. / P.n_IR);
    int nb_IM = rand_n(P.N[I] - nb_IR, P.p_M);
    int nb_RS = rand_n(P.N[R], 1. / P.n_RS);

    P.N[S] += nb_RS - nb_SI;
    P.N[I] += nb_SI - nb_IR - nb_IM;
    P.N[R] += nb_IR - nb_RS;
    P.N[M] += nb_IM;

    return P;
}
