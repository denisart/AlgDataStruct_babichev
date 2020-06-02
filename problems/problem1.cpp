/*
    Problem 1. Symmetric difference

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb
*/
#include <bits/stdc++.h>

int main() {
    unsigned int start_time =  clock();
    // start coding
    std::set<int> numbers;

    int new_value = -1;
    std::cin >> new_value;

    if (new_value != 0) {
        do {
            numbers.insert(new_value);
            std::cin >> new_value;
        } while (new_value != 0);
    }

    std::cin >> new_value;
    if (new_value != 0) {
        do {
            if (numbers.count(new_value) == 0)
                numbers.insert(new_value);
            else
                numbers.erase(new_value);

            std::cin >> new_value;
        } while (new_value != 0);
    }

    if (numbers.size() == 0) {
        std::cout << 0;
    } else {
        for (const auto& i : numbers)
            std::cout << i << " ";
    }

    std::cout << std::endl;

    // finish coding
    unsigned int finish_time =  clock();
    std::cout << "Time complexity = " << finish_time - start_time << std::endl;
    return 0;
}