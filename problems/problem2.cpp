/*
    Problem 2. Two arrays

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb
*/
#include <bits/stdc++.h>

int main() {
    unsigned int start_time = clock();
    // start coding
    // int arrays_count = 0;
    int Na, Nb;
    std::cin >> Na >> Nb;

    std::map<int, int> firstArray;
    while (Na--) {
        int new_value;
        std::cin >> new_value;

        firstArray[new_value]++;
    }

    int arrays_count = 0;

    int temp;
    std::cin >> temp;
    int count = 1;
    if (firstArray[temp] > 0)
        arrays_count++;
    Nb--;

    while (Nb--) {
        int new_value;
        std::cin >> new_value;

        if (new_value == temp) {
            count++;
        } else {
            temp = new_value;
            count = 1;
        }

        if (firstArray[temp] >= count)
            arrays_count++;
    }

    std::cout << arrays_count << std::endl;
    // finish coding
    unsigned int finish_time =  clock();
    std::cout << "Time complexity = " << finish_time - start_time << std::endl;
    return 0;
}