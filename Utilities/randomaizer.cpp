#include "randomaizer.h"
#include <cstdlib>
#include <ctime>

int random_seed = time(0);

int Randomaizer::Random() {
  srand(time(0));
  int result = rand(); // NOLINT
  result %= random_seed;
  result += random_seed;
  result *= random_seed;
  random_seed = rand(); // NOLINT
  srand(random_seed);
  random_seed = rand() + result; // NOLINT
  return result;
}
