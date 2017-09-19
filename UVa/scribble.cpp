#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    char givenChars[] = {'a', 'c', 't'};
    string words[] = {"cat", "act", "ac", "stop", "cac"};
    string charSet = "";
    int setLength, stringLength;
    string str;

    /* add char set into a string */
    charSet = charSet + givenChars[0] + givenChars[1] + givenChars[2];
    setLength = charSet.length();

    for(int i = 0; i < 5; i++) {

        str = words[i];
        stringLength = str.length();
        /* sort the word */
        for(int m = 0; m < stringLength - 1; m++) {
                for(int n = 0; n < stringLength-1-m; n++) {
                    if(str[n] > str[n+1]) {
                        char temp = str[n];
                        str[n] = str[n+1];
                        str[n+1] = temp;
                    }
                }
            }

        if(stringLength == setLength) {
            if(charSet.compare(str) == 0)
                cout << words[i] << " ";
        }

        else if(stringLength < setLength) {

            int index = 0;
            int flag = 0;

            for(int m = 0; m < stringLength; m++) {
                for(int n = index; n < setLength; n++) {
                    if(str[m] == charSet[n]) {
                        flag++;
                        index = n+1;
                    }
                }
            }

            if(flag == stringLength)
                cout << words[i] << " ";
        }

    }
    cout << endl;

    return 0;
}
