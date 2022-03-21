#include"LuckyNumber.h"
int LuckyNumber::generate(std::string animal) {
    std::map<std::string, int> numbers = {
        {"Rat", 1469},
        {"Ox", 2057},
        {"Tiger", 1368},
        {"Rabbit", 1368},
        {"Dragon", 2507},
        {"Snake", 2378},
        {"Horse", 2378},
        {"Goat", 2570},
        {"Monkey", 4950},
        {"Rooster",4095},
        {"Dog", 2057},
        {"Pig", 1469}
    };
    if (numbers.find(animal) == numbers.end()) {
        return 0;
    }
    else {
        return numbers[animal];
    }
}