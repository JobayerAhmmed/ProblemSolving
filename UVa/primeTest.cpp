#include<iostream>
#include<cmath>

using namespace std;

void seive(bool *prime, int n);
bool isPrime(bool *prime, int n);
bool isPrime2(int n);

int main(void)
{
    int n;  // number to check prime
    bool answer;

    cin >> n;

    bool prime[n+1];
    for(int i = 0; i < n+1; i++)
        prime[i] = true;

    answer = isPrime(prime, n);
    if(answer)
        cout << n << " is prime." << endl;
    else
        cout << n << " is not prime." << endl;

    answer = isPrime2(n);
    if(answer)
        cout << n << " is prime." << endl;
    else
        cout << n << " is not prime." << endl;

    return 0;
}

/* generate prime numbers from 1 to root of n */
void seive(bool *prime, int n)
{
    prime[0] = false;
    prime[1] = false;

    int root = sqrt(n);
    for(int i = root; i <= root; i++)
        if(prime[i])
            for(int k = i*i; k <= n; k += i)
                prime[k] = false;
}

/* check number for prime: O(sqrt(n)/2) */
bool isPrime2(int n)
{
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    int root = sqrt(n);
    for(int i = 3; i <= root; i += 2)
        if(n%i == 0)
            return false;
    return true;
}

/* more efficient : O( |#primes <= sqrt(n)| ) */
bool isPrime(bool *prime, int n)
{
    int root = sqrt(n);
    seive(prime, n);

    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;

    for(int i = 3; i <= root; i += 2)
        if(prime[i])
            if(n%i == 0)
                return false;
    return true;
}
