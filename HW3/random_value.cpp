#include <iostream>
#include <cstdlib>
#include <ctime>

#include "random_value.h"

void get_random_value(int &random_value) {

	const int max_value = 100;
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	random_value = std::rand() % 100 + 1;
}