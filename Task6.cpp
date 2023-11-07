#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef pair<long long, long long> Complex;

long long modular_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

Complex multiply(Complex a, Complex b, long long p, long long w) {
    long long x = (a.first * b.first + a.second * b.second % p * w) % p;
    long long y = (a.first * b.second + a.second * b.first) % p;
    return Complex(x, y);
}

Complex pow(Complex a, long long n, long long p, long long w) {
    Complex result = Complex(1, 0);
    while (n > 0) {
        if (n & 1) {
            result = multiply(result, a, p, w);
        }
        a = multiply(a, a, p, w);
        n >>= 1;
    }
    return result;
}

long long chipolla_sqrt(long long n, long long p)
{
    if (modular_pow(n, (p - 1) / 2, p) != 1)
        return -1;  // no square root exists

    long long a;
    long long w;
    while (true)
    {
        a = rand() % p;
        w = (a * a - n + p) % p;
        if (modular_pow(w, (p - 1) / 2, p) == p - 1)
            break;
    }

    Complex res = pow(Complex(a, 1), (p + 1) / 2, p, w);
    return res.first;
}

int main()
{
    long long n, p;
    cout << "Введіть число та модуль (розділені пробілом): ";
    cin >> n >> p;

    long long root = chipolla_sqrt(n, p);
    if (root == -1)
        cout << "Квадратний корінь не існує в даному модулі." << endl;
    else
        cout << "Дискретний квадратний корінь: " << root << endl;

    return 0;
}
