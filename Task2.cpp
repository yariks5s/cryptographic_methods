#include <iostream>
#include <vector>

using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Функція для знаходження модульного інверсу за допомогою розширеного алгоритму Евкліда
long long mod_inverse(long long a, long long m) {
    long long x, y;
    extended_gcd(a, m, x, y);
    return (x % m + m) % m;
}

long long chinese_remainder_theorem(const vector<long long> &rem, const vector<long long> &mod) {
    int n = rem.size();
    long long prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= mod[i];
    }

    long long result = 0;

    for (int i = 0; i < n; i++) {
        long long pp = prod / mod[i];
        result += rem[i] * mod_inverse(pp, mod[i]) * pp;
    }

    return result % prod;
}

int main() {
    cout << "Введіть кількість порівнянь: ";
    int n;
    cin >> n;

    vector<long long> rem(n), mod(n);
    for (int i = 0; i < n; i++) {
        cout << "Введіть лишок і модуль для порівняння " << i + 1 << " (розділених пробілом): ";
        cin >> rem[i] >> mod[i];
    }

    long long result = chinese_remainder_theorem(rem, mod);
    cout << "Розв'язок системи порівнянь за модулем: " << result << endl;

    return 0;
}
