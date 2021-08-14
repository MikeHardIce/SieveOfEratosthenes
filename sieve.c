#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool* createNumbers (int limit) {
  
  bool *numbers = calloc(limit, sizeof *numbers);

  for(int i = 2; i < limit; i++){
    numbers[i] = true;
  }

  return numbers;
}

void crossOut (int prime, bool* numbers, int limit) {
  for(int i=(2 * prime); i <= limit; i += prime) {
    numbers[i] = false;
  }
}

unsigned int* listOfPrimes (bool* numbers, int limit, int* prime_size) {
  unsigned int array_size = 100;
  unsigned int *primes = calloc(array_size, sizeof *primes);
  unsigned int size = 0;
  
  for(int i = 2; i < limit; i++) {
    if (numbers[i]) {

      if(size > array_size-1) {
        array_size += 100;
        unsigned int *new_block = realloc(primes, array_size * sizeof(unsigned int));

        if(new_block) {
          primes = new_block;
        } 
        else {
          printf("Out of Memory!\n");
          break;
        }

      }
      primes[size++] = i;
    }
  }

  *prime_size = size;

  return primes;
}

void sieve (bool* numbers, int limit) {
  int cut_limit = (int)sqrt((double)limit) + 1;

  for(int i = 2; i <= cut_limit; i++) {
    if(numbers[i]) {
      crossOut(i, numbers, limit);
    }
  } 
}

int main () {
  const int limit = 1000000;

  bool *numbers = createNumbers(limit);
  int *prime_size;

  sieve(numbers, limit);

  unsigned int* primes = listOfPrimes(numbers, limit, prime_size);

  printf("primes: ");
  for(int i = 0; i < *prime_size; i++){
    printf(" %d ", primes[i]);
  }
  printf("\n");
  
  return 0;
}
