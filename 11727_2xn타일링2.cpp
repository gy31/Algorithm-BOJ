#include<iostream>
using namespace std;
int n;
int t[1001]={0,1,3};

int main(){
	cin >> n;

	for(int i = 3; i <= n; i++){
		t[i] = (t[i-1] + t[i-2] * 2) % 10007;
	}
	
	cout << t[n];
	
    return 0;
}