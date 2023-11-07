#include <iostream>

using namespace std;

int legendreSymbol(int a, int p)
{
    int legendre = static_cast<int>(std::pow(a, (p - 1) / 2)) % p;
    return (legendre == 1) ? 1 : ((legendre == (p - 1)) ? -1 : 0);
}

int jacobiSymbol(int a, int n)
{
    if (n <= 0 || n % 2 == 0) return 0;  // Обробка виключень

    int js = 1;
    if (a < 0)
    {
        a = -a;
        if (n % 4 == 3)
            js = -js;
    }

    while (a != 0) 
    {
        while (a % 2 == 0) 
        {
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5)
                js = -js;
        }
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3)
            js = -js;
        a = a % n;
    }

    if (n == 1) return js;
    return 0;
}

int main()
{
    int a, n;
    cout << "Введіть числа a та n: ";
    cin >> a >> n;

    if (n <= 0 || n % 2 == 0)
    {
        cout << "n повинен бути додатнім непарним" << endl;
        return 1;
    }

    if (n > 2 && n % 2 == 1)
        cout << "Символ Якобі (" << a << "/" << n << ") = " << jacobiSymbol(a, n) << endl;

    if (n > 2 && n % 2 == 1 && n < 1000000) // Обмеження для простоти перевірки
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << "n не просте число. Не можна порахувати Символ Лежандра." << endl;
                return 0;
            }
        }
        cout << "Символ Лежандра (" << a << "/" << n << ") = " << legendreSymbol(a, n) << endl;
    }

    return 0;
}
