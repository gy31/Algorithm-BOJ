#include<stdio.h>
int arr[1001];
int main()
{
    int n, i, key, min = 1000, max = 0, top = 0, answer = 0, t;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
       scanf("%d", &key);
       scanf("%d", &arr[key]);
       if(key < min) min = key;
       if(key > max) max = key;
       if(arr[key] > top) top = arr[key];
    }

    t = 0;
    for(i = min; i <= max; i++) {
        if(arr[i] == top) break;
        if(arr[i] > t) t = arr[i];
        answer += t;
    }

    t = 0;
    for(i = max; i >= min; i--) {
        if(arr[i] == top) break;
        if(arr[i] > t) t = arr[i];
        answer += t;
    }

    answer += top;
    printf("%d", answer);

    return 0;
}