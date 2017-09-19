#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    int testCase;   // number of test case
    string input;
    int length;     // length of the integer
    long long int quotient;
    long long int dividend;
    long long int remainder;
    long long int divisor;

    /* take input */
    //cin >> testCase;
   // string s;
   // getline(cin, s);

    //for(int k = 0; k < testCase; k++) {
        getline(cin, input);
        length = input.length();

        divisor = 1;
        int flag = 1;
        dividend = input[0]-48;

        if(length%2 == 0) {
            flag = 2;
            dividend = dividend*10 + (input[1]-48);
        }
        while(divisor*divisor <= dividend)
            divisor++;
        divisor--;

        remainder = dividend % divisor;
        quotient = divisor;

        int i = 1;
        if(flag == 2) i = 2;
        int n;

        while(i != length) {
            dividend = remainder*100 + (input[i]-48)*10 + (input[++i]-48);
            divisor = quotient * 10 * 2;
            if(dividend == 0) {
                quotient = quotient * 10;
                remainder = 0;
            }
            else {
                n = 1;
                while((divisor+n) * n <= dividend)
                    n++;
                n--;
                divisor = divisor + n;
                quotient = quotient*10 + n;
                remainder = dividend % divisor;
            }
            ++i;
        }
        cout << quotient << endl << endl;
        //getline(cin, s);
    //}

    return 0;
}

