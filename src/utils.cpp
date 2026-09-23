#include "utils.h"
#include <cstdlib>

std::unique_ptr<Result> get_divisor_rs(unsigned int number) {
	std::unique_ptr<Result> result(new Result());
	std::tuple<unsigned int, unsigned int> val = get_divisor(number);
	result->first_multiplier = std::get<0, unsigned int>(val);
	result->second_multiplier = std::get<1, unsigned int>(val);
	
	return result;
}

unsigned int get_first_multiplier(const Result& result) { return result.first_multiplier;}
unsigned int get_second_multiplier(const Result& result) { return result.second_multiplier;}

std::tuple<unsigned int, unsigned int> get_divisor(unsigned int number) {
	unsigned int close_distance = number;
	unsigned int row_num = 0;
	unsigned int col_num = 0;

	for ( unsigned int i = 2; i < number / 2;  ++ i) {
		if ( number % i == 0 ) {
			// get another divisor
			unsigned int aDivisor = number / i;
			// get distance between 2 divisors
			unsigned int current_distance = std::abs( (double)aDivisor - (double)i );
			// if current distance shorter than the cloest value, then chang ethe value
			if ( current_distance < close_distance ) {
				close_distance = current_distance;
				row_num = i;
				col_num = aDivisor;
			}
		}
	}

	return std::tuple<unsigned int, unsigned int> (row_num, col_num);
}
