#include "rand32.h"

#include <limits>
#include <random>


extern "C" unsigned int rand32 ()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint32_t> dis(0, std::numeric_limits<uint32_t>::max());
  return dis(gen);
}
