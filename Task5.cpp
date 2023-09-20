#include <iostream>
#include <cmath>
#include <map>
#include <cstdint>

using namespace std;

uint64_t modular_pow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

uint64_t discrete_log_shanks(uint64_t g, uint64_t h, uint64_t p) {
    uint64_t m = static_cast<uint64_t>(sqrt(p) + 1);
    map<uint64_t, uint64_t> valueMap;

    // "малий крок"
    for (uint64_t j = 0; j < m; ++j) {
        uint64_t value = modular_pow(g, j, p);
        valueMap[value] = j;
    }

    // обчислюємо g^(-m) mod p
    uint64_t coeff = modular_pow(g, p - 1 - m, p);

    uint64_t curr = h;
    // "великий крок"
    for (uint64_t i = 0; i < m; ++i) {
        if (valueMap.find(curr) != valueMap.end()) {
            return i * m + valueMap[curr];
        } else {
            curr = (curr * coeff) % p;
        }
    }

    // якщо дискретний логарифм не знайдений
    return -1;
}

int main() {
    uint64_t p, g, h;
    cout << "Введіть значення p (просте число): ";
    cin >> p;
    cout << "Введіть значення g: ";
    cin >> g;
    cout << "Введіть значення h: ";
    cin >> h;

    uint64_t result = discrete_log_shanks(g, h, p);

    if (result != static_cast<uint64_t>(-1)) {
        cout << "Значення дискретного логарифма x: " << result << endl;
    } else {
        cout << "Не вдалося знайти дискретний логарифм." << endl;
    }

    return 0;
}
