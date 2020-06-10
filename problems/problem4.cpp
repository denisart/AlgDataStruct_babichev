/*
    Problem 4. Count comments

    Input file:         std::cin
    Output file:        std::cout
    Time complexity:    1 sec
    Memory complexity:  256 Mb

    The programming language Object Pascal has three comment type:

    Type 1. Starts with symbols (*. Ends with symbols *).
    Type 2. Starts with symbol {. Ends with symbols }.
    Type 3. Starts with symbols //. Ends when we have the
            end line symbol.
    Type 4. Literal strings. Starts and ends with symbol '.
            The literal strings haven't the end line symbols.

    Let Nci be the number of type i comments in correct Object
    Pascal program, where i \in {1, 2, 3, 4}.

    Input:
        line 1
        line 2
        line 3
        ...
        line N
    Output:
        Nc1 Nc2 Nc3 Nc4
*/
#include <bits/stdc++.h>

int main() {
    /*
        Conver main symbols to int
            ' ---> 39
            " ---> 34
            ( ---> 40
            ) ---> 41
            / ---> 47
            / ---> 47
            { ---> 123
            } ---> 125
            * ---> 42
            s ---> 115
            | ---> 124
    */
    uint32_t count_c1 = 0; // for (* ... *)
    uint32_t count_c2 = 0; // for { ... }
    uint32_t count_c3 = 0; // for // ...
    uint32_t count_c4 = 0; // for ' ... '
    
    std::string str;
    uint32_t last_sym = 115; // 's'
    uint32_t new_sym;

    while(std::getline(std::cin, str)) {
        for (char c : str) {
            new_sym = uint32_t(c);

            // comment of type 1 (* ... *)
            if (last_sym == 40) { // if last_sym == '('
                if (new_sym == 42) { // if c == '*'
                    last_sym = 124; // support symbol '|' if we start comment (* ... *)
                } else {
                    last_sym = 115; // last_sym = 's'
                    if (new_sym == 40 or new_sym == 47 or new_sym == 123 or c == 39) {
                        // if c == '(' or c == '/' or c == '{' or c == '\''
                        last_sym = new_sym;
                    }
                }
            } else if (last_sym == 124) { // if last_sym == '|'
                if (new_sym == 42) { // c == '*'
                    last_sym = 42;
                }
            } else if (last_sym == 42) { // if last_sym == '*'
                if (new_sym == 41) { // if c == ')'
                    count_c1++;
                    last_sym = 115; // last_sym = 's'
                } else {
                    last_sym = 124; // last_sym = '|'
                }
            } else if (last_sym == 47) { // last_sym == '/'
                if (new_sym == 47) { // c == '/'
                    count_c3++;
                    last_sym = 115; // last_sym = 's'
                    break;
                } else {
                    last_sym = 115;
                    if (new_sym == 40 or new_sym == 123 or c == 39) {
                        // if c == '(' or c == '/' or c == '{' or c == '\''
                        last_sym = new_sym;
                    }
                }
            } else if (last_sym == 123) { // if last_sym == '{'
                if (new_sym == 125) { // c == '}'
                    count_c2++;
                    last_sym = 115; // last_sym = 's'
                }
            } else if (last_sym == 39) { // if last_sym == '\''
                if (new_sym == 39) { // if c == '\''
                    count_c4++;
                    last_sym = 115; // last_sym = 's'
                }
            } else {
                if (new_sym == 40 or new_sym == 47 or new_sym == 123 or c == 39) {
                    // if c == '(' or c == '/' or c == '{' or c == '\''
                    last_sym = new_sym;
                }
            }
        }
    }

    std::cout << count_c1 << " " << count_c2 << " " << count_c3 <<
        " " << count_c4 << std::endl;

    return 0;
}