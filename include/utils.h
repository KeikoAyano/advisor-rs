#include <tuple>
#include <memory>


struct Result {
unsigned int first_multiplier;
unsigned int second_multiplier;
};

std::unique_ptr<Result> get_divisor_rs(unsigned int);
std::tuple<unsigned int, unsigned int> get_divisor(unsigned int number);
unsigned int get_first_multiplier(const Result& );
unsigned int get_second_multiplier(const Result& );
