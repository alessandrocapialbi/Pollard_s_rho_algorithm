#include <stdio.h>
#include <stdlib.h>


// Calcolo massimo comune divisore
int gcd(int a, int b)
{
    int remainder;
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main (int argc, char *argv[])
{

    int number = 10403, loop = 1, count;
    int x_fixed = 2, x = 2, size = 2, factor;

    do {
        printf("----   loop %4i   ----\n", loop);
        count = size; //Serve a fare il ciclo un numero limitato di volte
        do {
            x = (x * x + 1) % number; /*Viene calcolato il resto della x con il numero di cui
 *          vogliamo trovare il fattore. Se il dividendo è più piccolo del divisore, il risultato
 *          sarà il dividendo stesso, altrimenti se è più grande viene calcolato il resto.*/

            factor = gcd(abs(x - x_fixed), number); /*Viene fatto il massimo comune divisore
 *          della differenza tra la x calcolata con il polinomio e la x_fixed che sarebbe il valore iniziale
 *          con cui iniziamo la pseudo-sequenza.*/
            printf("count = %4i  x = %6i  factor = %i\n", size - count + 1, x, factor);
        } while (--count && (factor == 1)); /*Il ciclo si ripete fino a quando il fattore
 *      risulterà essere 1, perché 1 non è un fattore valido e quando count è > 0.
 *     */
        size *= 2; //La dimensione raddoppia e vengono provati più valori.
        x_fixed = x; //La nuova x iniziale diventa la x calcolata con il polinomio.
        loop = loop + 1; //Si passa al ciclo successivo
    } while (factor == 1); //Quando il fattore risulterà essere diverso da 1, allora avremo trovato p.
    printf("factor is %i\n", factor);
    return factor == number ? EXIT_FAILURE : EXIT_SUCCESS;
}