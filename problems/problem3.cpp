/*
    Problem 3. Evaluation of polynomial

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    1 sec
    Memory complexity:  16 Mb

    Let
        p(x) = a_N x^N + a_{N-1} x^{N-1} + ... + a_1 x + a_0,
        where a_i is a integer number and 2 <= N <= 100000.

    Find p(x_i) (mod K) for 0 <= x_i <= 10^9 and 1 <= i <= M, where
    1 <= M <= 10000 and for 10 <= K <= 10^9.

    Input:
        N M K
        a_N
        a_{N-1}
        ...
        a_0
        x_1
        x_2
        ...
        x_{M}

    Output:
        p(x_1) (mod K)
        p(x_2) (mod K)
        ...
        p(x_M) (mod K)
*/
#include <bits/stdc++.h>

int main() {
    int N, M, MOD;
    std::cin >> N >> M >> MOD;

    std::vector<int> coefs(N + 1);
    int temp;
    for (int i = 0; i < N + 1; i++) {
        std::cin >> temp;
        coefs[N  - i] = temp;
    }

    int poly_value;
    int x;
    int pow;
    while (M--) {
        poly_value = 0;
        pow = 1;
        std::cin >> x;

        // x^n (mod K) = x * (x^{n-1} (mod K))
        for (int i = 0; i < N + 1; i++) {
            poly_value = (poly_value + coefs[i] * pow) % MOD;
            pow = (pow * x) % MOD;
        }

        std::cout << poly_value << std::endl;
    }

    return 0;
}