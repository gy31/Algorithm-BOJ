#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
vector<pair<int,int>> days;
int answer;
bool cmp(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first) return i.second < j.second;
    return i.first < j.first;
}
int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        days.push_back({a, b});
    }

    sort(days.begin(), days.end(), cmp);

    for(int i = 0; i < M; i++) {
        if(days[i].second < days[i+1].first)
    }

    return 0;
}