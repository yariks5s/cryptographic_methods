#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

uint64_t f(uint64_t x, uint64_t c, uint64_t mod) {
    return (x * x + c) % mod;
}

uint64_t abs_diff(uint64_t a, uint64_t b) {
    return (a > b) ? (a - b) : (b - a);
}

uint64_t pollard_rho(uint64_t n) {
    if (n <= 1) return n;
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    if (n % 5 == 0) return 5;
    if (n % 7 == 0) return 7;

    srand(time(NULL));

    uint64_t x = rand() % (n - 2) + 2;
    uint64_t y = x;
    uint64_t c = rand() % (n - 1) + 1;
    uint64_t d = 1;

    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        d = gcd(abs_diff(x, y), n);
    }

    return (d == n) ? pollard_rho(n) : d;
}

int main() {
    uint64_t number;
    cout << "Введіть число для факторизації: ";
    cin >> number;

    while (number > 1) {
        uint64_t factor = pollard_rho(number);
        if (factor == number) {
            cout << "Дільник: " << factor << endl;
            break;
        } else {
            cout << "Дільник: " << factor << endl;
            number /= factor;
        }
    }

    return 0;
}
