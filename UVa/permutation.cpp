/*
The following algorithm generates the
next permutation lexicographically.

1.Find the largest index k such that a[k] < a[k + 1].
 If no such index exists, the permutation is the last permutation.
2.Find the largest index l such that a[k] < a[l].
 Swap the value of a[k] with that of a[l].
3.Reverse the sequence from a[k + 1] up to and
 including the final element a[n].
*/

#include<iostream>

using namespace std;

void swapp(char *str, int a, int b);
int permute(char *str, int length);

int main(void)
{
    char text[50];
    char ch;
    int i = 0;
    int length;

    while(cin >> ch) {
        text[i] = ch;
        i++;
    }
    text[i] = '\0';
    length = i;

    /* sort the string
     * Bubble Sort
     */
     for(int j = 0; j < length-1; j++) {
        for(int k = 0; k < length-1-j; k++) {
            if(text[k] > text[k+1]) {
                char temp = text[k];
                text[k] = text[k+1];
                text[k+1] = temp;
            }
        }
     }

    /* call the method and print each
       permutation lexicographically */
    do{
        cout << text << endl;
    } while(permute(text, length));

    return 0;
}

/* This function divide the given string into three parts:
    head, key and tail;
*/
int permute(char *str, int length)
{
    int key;
    int swapKey;

    /* search key from right of the string */
    key = length - 1;
    while((key > 0) && (str[key] <= str[key-1]))
        key--;
    key--;

    /* This means all permutation have been produced */
    if(key < 0)
        return 0;

    /* searh the swapkey in tail from the right */
    swapKey = length - 1;
    while((swapKey > key) && (str[swapKey] <= str[key]))
        swapKey--;

    swapp(str, key, swapKey);

    /* sort the tail ascending order */
    key++;
    length--;
    while(key < length) {
        swapp(str, key, length);
        key++;
        length--;
    }
    return 1;
}

void swapp(char *str, int a, int b)
{
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}
