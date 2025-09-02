#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione per verificare se una parola è palindroma
int is_palindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // non è una parola palindroma
        }
        start++;
        end--;
    }
    return 1; // è una parola palindroma
}

// Funzione che calcola la media di un array di numeri interi
double calculate_average(int *arr, int length) {
    if (arr == NULL || length == 0) {
        return 0; // Gestione errore
    }
    
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (double)sum / length;
}

// Funzione che restituisce un array di numeri primi fino ad un certo limite
int* get_primes(int limit, int *num_primes) {
    *num_primes = 0;
    int *primes = malloc(limit * sizeof(int));

    for (int i = 2; i <= limit; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            primes[*num_primes] = i;
            (*num_primes)++;
        }
    }

    return primes;
}

// Funzione che libera la memoria allocata per l'array dei numeri primi
void free_primes(int *primes) {
    free(primes);
}

int main() {
    // Esempio di utilizzo della funzione is_palindrome
    char word[] = "racecar";
    if (is_palindrome(word)) {
        printf("La parola '%s' è un palindromo.\n", word);
    } else {
        printf("La parola '%s' non è un palindromo.\n", word);
    }

    // Esempio di utilizzo della funzione calculate_average
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    double avg = calculate_average(numbers, length);
    printf("La media dei numeri è: %.2f\n", avg);

    // Esempio di utilizzo della funzione get_primes
    int num_primes;
    int *primes = get_primes(50, &num_primes);
    printf("Numeri primi fino a 50: ");
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Liberazione della memoria
    free_primes(primes);

    return 0;
}
