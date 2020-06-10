/*
    Problem 5. Two heaps

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    2 sec
    Memory complexity:  64 Mb

    There are 2 <= N <= 23 stones with integer
    weights W1, W2, ..., WN. Partition 
    the set W = {W1, W2, ..., WN} into two subsets
    such that the difference of subset sums is minimum.

    Input:
        N
        W1 W2 W3 ... WN

    Output:
        Minimal difference of subsets sums
*/
#include <bits/stdc++.h>

int findMin(const std::vector<uint32_t>& w, uint32_t sum) {
    /*
        Let A = {A1, A2, ..., An} be a set with positive
        integer numbers;

        Let d[i][j] = 1, if some subset B in {A1, A2, ..., Ai}
                         has sum equals j,
                      0, owherwise
        0 <= i <= n, 0 <= j <= S, where S = Sum(A) := A1 + A2 + ... + An.

        Note that
            d[i][j] = d[i - 1][j] or
                      d[i - 1][j - Ai]

        If S1 and S2 be partition of A, then
            Sum(S1) = j and Sum(S2) = S - j.

        We find
            Min{S - 2 * j}, where 0 <= j <= S / 2 and
                                  d[n][j] = 1.
    */
    bool d[w.size() + 1][sum + 1];

    // d[i][0] = 1, because
    // 0 = S(empty set)
    for (int i = 0; i <= w.size(); i++) {
        d[i][0] = true;
    }

    // d[0][j] = 0, because
    // S(empty set) = 0 :)
    for (int j = 1; j <= sum; j++) {
        d[0][j] = false;
    }

    // using recurrence relation
    // d[i][j] = d[i - 1][j] or d[i - 1][j - Ai]
    for (int i = 1; i <= w.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            d[i][j] = d[i - 1][j];

            if (w[i - 1] <= j) {
                d[i][j] |= d[i - 1][j - w[i - 1]];
            }
        }
    }

    int32_t diff = INT_MAX;

    // S - 2 * j is minimal when
    // j is maximal
    for (int j = sum / 2; j >= 0; j--) {
        if (d[w.size()][j]) {
            diff = sum - 2 * j;
            break;
        }
    }

    return diff;
};


int main() {
    uint8_t N;
    std::cin >> N;

    std::vector<uint32_t> weights(N);
    uint32_t sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> weights[i];
        sum += weights[i];
    }

    std::cout << findMin(weights, sum) << std::endl;

    return 0;
}