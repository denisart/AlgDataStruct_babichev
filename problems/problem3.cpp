/*
    Problem 3. Evaluation of polynomial

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    1 sec
    Memory complexity:  16 Mb
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

        for (int i = 0; i < N + 1; i++) {
            poly_value = (poly_value + coefs[i] * pow) % MOD;
            pow = (pow * x) % MOD;
        }

        std::cout << poly_value << std::endl;
    }

    return 0;
}