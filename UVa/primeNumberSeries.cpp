#include<iostream>
#include<cmath>

using namespace std;

void seive(bool *prime, int n);

int main(void)
{
    int range;  // prime numbers from 1 to range

    cin >> range;

    bool prime[range+1];

    /* assume all numbers are prime */
    for(int i = 0; i < range+1; i++)
        prime[i] = true;

    seive(prime, range);

    /*print the prime numbers */
    for(int i = 0; i < range+1; i++)
        if(prime[i])
            cout << i << " ";

    cout << endl;

    return 0;
}
/*
Seive of Eratosthenes;
put false in all of the multiples of a prime number
*/
void seive(bool *prime, int n)
{
    prime[0] = false;
    prime[1] = false;

    int root = sqrt(n);

    for(int i = 2; i <= root; i++)
        if(prime[i])
            for(int k = i*i; k <= n; k += i)
                prime[k] = false;
}
