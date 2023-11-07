#include<iostream>
#include<math.h>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
    int n,p;
    cout << "Введіть P:" << endl;
    cin >> p;
    n = p;
    int LHS[2][n],RHS[2][n],a,b,i,j;
    cout << "Введіть a: " << endl;
    cin >> a;
    cout << "Введіть b: " << endl;
    cin >> b;
    cout << "еліптична крива: y^2 mod " << p << " = (x^3  + "<<a<<"*x + "<<b<<") mod p" << endl;

    vector <int> arr_x;
    vector <int> arr_y;

    for (int i = 0; i <	 n; i++)
    {
        LHS[0][i] = i;
        RHS[0][i] = i;
        LHS[1][i] = ((i*i*i) + a*i + b) % p;
        RHS[1][i] = (i*i) % p;
    }

    int in_c = 0;
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j++)
        {
            if(LHS[1][i] == RHS[1][j])
            {
                in_c++;
                arr_x.push_back(LHS[0][i]);
                arr_y.push_back(RHS[0][j]);
            }
        }
    }

    cout << endl << "точки:" << endl;
    for(i = 0; i < in_c; i++) {
        cout << i + 1 << "\t" << arr_x[i] << " , " << arr_y[i] << endl;
    }
    cout<<"Base: " << arr_x[0] << "," << arr_y[0] << endl;
    int k, d, M;
    cout << "Введіть випадкове число d" << endl;
    cin >> d;
    int Qx = d*arr_x[0];
    int Qy = d*arr_y[0];

    cout << "Введіть випадкове число k" << endl;
    cin >> k;

    cout << "Введіть повідомлення яке збираєтесь надіслати" << endl;
    cin >> M;
    cout << "Повідомлення: " << M << endl;

    int c1x = k*arr_x[0];
    int c1y = k*arr_y[0];
    cout << "Значення C1: " << c1x << ", " << c1y << endl;

    int c2x = k*Qx+M;
    int c2y = k*Qy+M;
    cout << "Значення C2: " << c2x << ", " << c2y << endl;

    cout << "Отримане повідомлення:" << endl;
    int Mx = c2x-d*c1x;
    cout << Mx;
}