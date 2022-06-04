#include "randomaizer.h"
#include <cstdlib>
#include <ctime>
#include <random>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type>
    dist(-100000, 100000);

int Randomaizer::Random() {
  return dist(rng);
}
