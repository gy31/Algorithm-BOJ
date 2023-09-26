#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string arr[500001];
string answer[500001];
int main()
{
    int i, n, m, cnt = 0;

    scanf("%d%d", &n, &m);

    for(i = 0; i < n+m; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n+m);

    for(i = 1; i < n+m; i++) {
        if(arr[i] == arr[i-1])
            answer[cnt++] = arr[i];
    }

    cout << cnt << "\n";

    for(i = 0; i < cnt; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}