#include<iostream>

using namespace std;

int main(void)
{
    int number;

    cin >> number;

    while(number != 0) {

        int input[number];

        for(int i = 0; i < number; i++)
            cin >> input[i];

        for(int i = 0; i < number; i++) {
            if(input[i] > 0)
                cout << input[i] << " ";
        }

        cin >> number;
        cout << endl;
    }

    return 0;
}
