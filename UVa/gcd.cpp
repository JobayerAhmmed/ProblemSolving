#include<iostream>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);
int gcd(int a, int b);

int main(void)
{
    int a, b, gcd1, gcd2, lcm;

    cin >> a >> b;

    /* assume that a < b */
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    gcd1 = gcd(a, b);
    cout << "GCD : " << gcd1 << endl;

    gcd2 = GCD(a, b);
    cout << "GCD : " << gcd2 << endl;

    lcm = LCM(a, b);
    cout << "LCM : " << lcm << endl;

    return 0;
}

int gcd(int a, int b)
{
    for(int i = a; i >= 1; i--)
        if(a%i == 0 && b%i == 0)
            return i;
}

/*Euclid's algorithm; faster */
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int LCM(int a, int b)
{
    return (a*b)/GCD(a, b);
}
