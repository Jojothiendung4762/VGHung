#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TEAM.INP", "r", stdin);
    freopen("TEAM.OUT", "w", stdout);

    int N;
    if (cin >> N) {
        vector<long long> A(N), B(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        long long total_pairs = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (A[i] + A[j] == B[i] + B[j]) {
                    total_pairs++;
                }
            }
        }
        cout << total_pairs << "\n";
    }

    return 0;
}