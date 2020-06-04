/*
    Problem 2. Two arrays

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb

    Let A = (a1, a2, ..., aNa) and B = (b1, b2, ..., bNa)
    are sequences. Let ai <= aj and bi <= bj for any i, j.
    Find the number of common elements in A and B. For
    example, A = (0, 0, 1, 1, 2, 3) and B = (0, 1, 1, 2). Then
    the common elements are (0, 1, 1, 2) and their number
    equals 4.

    Input:
        Na Nb
        a1
        a2
        ...
        aNa
        b1
        b2
        ...
        bNb

    Output:
        The number of common elements
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