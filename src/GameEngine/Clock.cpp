#include "GameEngine/Clock.hpp"

double Clock::getCurrentTime()
{
    return (((double)clock()) / CLOCKS_PER_SEC * 1000.0);
}