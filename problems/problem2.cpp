/*
    Problem 2. Two arrays

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb
*/
#include <bits/stdc++.h>

int main() {
    int Na, Nb;
    std::cin >> Na >> Nb;


    std::map<int, int> firstArray = {};
    int new_value;
    while (Na--) {
        std::cin >> new_value;
        firstArray[new_value]++;
    }

    int result = 0;
    int temp;
    std::cin >> temp;
    int count = 1;
    if (firstArray[temp])
        result++;
    Nb--;

    while (Nb--) {
        std::cin >> new_value;

        if (new_value == temp) {
            count++;
        } else {
            temp = new_value;
            count = 1;
        }

        if (firstArray[temp] >= count)
            result++;
    }

    std::cout << result << std::endl;
    return 0;
}