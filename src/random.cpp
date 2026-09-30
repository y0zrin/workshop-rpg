#include "random.h"

#include <random>

int randomInt(int low, int high)
{
    static std::mt19937 engine{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(low, high);
    return dist(engine);
}
