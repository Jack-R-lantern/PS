#include <iostream>
#include <algorithm>
#include <numeric>
 using namespace std;
 
int rope[100001];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];
    sort(rope, rope + N, greater<int>());
 
    long long result = 0;
    for (int i = 0; i < N; i++) {
        long long sum = rope[i] * (i + 1);
        if(sum > result)
            result = sum;
    }
    cout << result << endl;
    return 0;
}