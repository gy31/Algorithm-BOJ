#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string arr[5];
int main()
{
    int i, j;
    
    for(i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for(i = 0; i < 16; i++) {
        for(j = 0; j < 5; j++) {
            if(arr[j][i] != 0) {
                cout << arr[j][i];
            }
        }
    }

    return 0;
}