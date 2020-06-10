/*
    Problem 1. Symmetric difference

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb

    Let A = {a1 a2 ... an} and B = {b1 b2 ... bm}
    are sets (maybe empty) and 1 <= ai, bj <= 20000.

    Input:
        a1 a2 ... an 0 b1 b2 ... bm 0
    Output:
        Sorted symmetric difference of A and B
*/
#include <bits/stdc++.h>

int main() {
    std::set<uint32_t> numbers;

    uint32_t new_value;
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
    return 0;
}