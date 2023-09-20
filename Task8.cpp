#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


bool isPrime( long int prime) {
    long int i, j;
    j = (long int)sqrt((long double)prime);

    for ( i = 2; i <= j; i++) {
        if ( prime % i == 0 ) {
            return false;
        }
    }

    return true;
}

long int greatestCommonDivisor( long int e, long int t ) {
    while ( e > 0 ) {
        long int myTemp;

        myTemp = e;
        e = t % e;
        t = myTemp;
    }

    return t;
}

long int calculateE( long int t ) {
    long int e;
    for ( e = 2; e < t; e++ ) {
        if (greatestCommonDivisor( e, t ) == 1 ) {
            return e;
        }
    }
    return -1;
}

long int calculateD( long int e, long int t) {
    long int d;
    long int k = 1;

    while (true) {
        k = k + t;
        if ( k % e == 0) {
            d = (k / e);
            return d;
        }
    }

}

long int encrypt( long int i, long int e, long int n ) {
    long int current = i - 97;
    long int result = 1;

    for ( long int j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
    }

    return result;
}

long int decrypt(long int i, long int d, long int n) {
    long int current, result;

    current = i;
    result = 1;

    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }

    return result + 97;
}

int main() {
    long int p, q, n, t, e, d;

    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));

    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));

    bool flag;
    std::string message;

    do {
        std::cout << "Enter a Prime number  p :" << std::endl;
        std::cin >> p;
        flag = isPrime( p );

        if (!flag)
        {
            std::cout << "WRONG INPUT" << std::endl;
        }
    } while (!flag);

    do {
        std::cout << "Enter a Prime number  q :" << std::endl;
        std::cin >> q;
        flag = isPrime( q );

        if (!flag) {
            std::cout << "WRONG INPUT" << std::endl;
        }
    } while (!flag);

    n = p * q;
    std::cout << "\nResult of computing n = p*q = " << n << std::endl;

    t = ( p - 1 ) * ( q - 1 );
    std::cout << "Result of computing Euler's totient function: " << t << std::endl;

    e = calculateE( t );
    d = calculateD( e, t );

    std::cout << "RSA public key is n = " << n << ", e = " << e << std::endl;
    std::cout << "RSA private key is n = " << n << ", d = " << d << std::endl;
    std::cout << "Enter Message: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, message );
    std::cout << "\nThe message is: " << message << std::endl;

    for (long int i = 0; i < message.length(); i++)
    {
        encryptedText[i] = encrypt(message[i], e, n);
    }

    std::cout << "ENCRYPTED: " << std::endl;

    for (long int i = 0; i < message.length(); i++ )
    {
        printf("%c",(char)encryptedText[i] );
    }

    for (long int i = 0; i < message.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }

    std::cout << "DECRYPTED: " << std::endl;

    for (long int i = 0; i < message.length(); i++)
    {
        printf("%c",(char)decryptedText[i] );
    }

    std::cout << std::endl << std::endl;

    return 0;
}
