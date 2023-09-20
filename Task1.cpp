#include <iostream>
#include <vector>

using namespace std;

// Функція для знаходження найбільшого спільного дільника
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Функція Ейлера
int eulerPhi(int n) {
    int result = n;

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }

    if (n > 1) result -= result / n;
    return result;
}

// Функція Мьобіуса
int mu(int n) {
    if (n == 1) return 1;
    int primeFactors = 0;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            if (n % (p * p) == 0) return 0;
            while (n % p == 0) n /= p;
            primeFactors++;
        }
    }
    if (n > 1) primeFactors++;
    return (primeFactors & 1) ? -1 : 1;
}

// Знаходження найменшого спільного кратника для двох чисел
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

// Знаходження найменшого спільного кратника для набору чисел
int lcmOfArray(const vector<int>& arr) {
    int result = 1;
    for (int num : arr) {
        result = lcm(result, num);
    }
    return result;
}

int main() {
    int n;
    cout << "Введіть число для обчислення функцій Ейлера та Мьобіуса: ";
    cin >> n;
    cout << "Функція Ейлера: " << eulerPhi(n) << endl;
    cout << "Функція Мьобіуса: " << mu(n) << endl;

    cout << "Введіть кількість чисел для знаходження НСК: ";
    int size;
    cin >> size;
    vector<int> arr(size);
    cout << "Введіть числа через пробіл: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "НСК: " << lcmOfArray(arr) << endl;

    return 0;
}
