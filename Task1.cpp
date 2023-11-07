#include <iostream>
#include <vector>

using namespace std;

// Функція Ейлера
int eulerPhi(int n)
{
    int result = n;

    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }

    if (n > 1) result -= result / n;
    return result;
}

// Функція Мьобіуса
int mebius(int n)
{
    if (n == 1) return 1;
    int primeFactors = 0;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0) {
            if (n % (p * p) == 0) return 0;
            while (n % p == 0) n /= p;
            primeFactors++;
        }
    }
    if (n > 1) primeFactors++;
    return (primeFactors & 1) ? -1 : 1;
}

// Знаходження найбільшого спільного дільника
int nsd(int a, int b)
{
    if (b == 0) return a;
    return nsd(b, a % b);
}

// Знаходження найменшого спільного кратного для двох чисел
int nsk(int a, int b)
{
    return abs(a * b) / nsd(a, b);
}

// Знаходження найменшого спільного кратного для набору чисел
int nskOfArray(const vector<int>& arr)
{
    int result = 1;
    for (int num : arr) {
        result = nsk(result, num);
    }
    return result;
}

int main()
{
    int n;
    cout << "Число для обчислення функцій Ейлера та Мьобіуса: ";
    cin >> n;
    cout << "Функція Ейлера: " << eulerPhi(n) << endl;
    cout << "Функція Мьобіуса: " << mebius(n) << endl;

    cout << "Кількість чисел для знаходження НСК: ";
    int size;
    cin >> size;
    vector<int> arr(size);
    cout << "Введіть числа через пробіл: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "Результат: " << nskOfArray(arr) << endl;

    return 0;
}
// довга арифметика і нормальні криві