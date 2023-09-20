#include <iostream>
#include <cstdint>
#include <vector>
#include <random>

using namespace std;

// Функція для обчислення (a * b) % mod з уникненням переповнення
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

// Функція для обчислення (a ^ b) % mod за допомогою методу бінарного піднесення до степеня
uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 1;
    while (b > 0) {
        if (b & 1) {
            result = mul_mod(result, a, mod);
        }
        a = mul_mod(a, a, mod);
        b >>= 1;
    }
    return result;
}

// Функція для перевірки числа на простоту за допомогою тесту Міллера-Рабіна
bool miller_rabin(uint64_t n, int k) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    // Представлення числа n - 1 як 2^r * d
    uint64_t d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d >>= 1;
        r++;
    }

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < k; i++) {
        uniform_int_distribution<uint64_t> dis(2, n - 2);
        uint64_t a = dis(gen);
        uint64_t x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }
        for (int j = 1; j < r; j++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                break;
            }
        }
        if (x != n - 1) {
            return false; // n - складене число
        }
    }
    return true; // n - можливо просте число
}

int main() {
    uint64_t number;
    int k = 10; // Кількість ітерацій тесту Міллера-Рабіна (збільшити для більшої точності)

    cout << "Введіть число для перевірки на простоту: ";
    cin >> number;

    if (miller_rabin(number, k)) {
        cout << number << " є простим числом." << endl;
    } else {
        cout << number << " не є простим числом." << endl;
    }

    return 0;
}
