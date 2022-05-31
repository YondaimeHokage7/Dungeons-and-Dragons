#include "functions.hpp"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

int randomBetween(int num1, int num2)
{
    return std::uniform_int_distribution<>(num1, num2)(gen);
}