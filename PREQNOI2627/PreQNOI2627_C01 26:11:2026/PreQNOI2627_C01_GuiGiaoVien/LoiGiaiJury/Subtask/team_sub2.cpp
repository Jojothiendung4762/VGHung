#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1000000;
long long cnt[2000005]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TEAM.INP", "r", stdin);
    freopen("TEAM.OUT", "w", stdout);

    int N;
    if (cin >> N) {
        vector<long long> A(N), B(N), D(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        long long total_pairs = 0;

        if (N <= 1000) {
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (A[i] + A[j] == B[i] + B[j]) {
                        total_pairs++;
                    }
                }
            }
        } 
        else {
            for (int i = 0; i < N; ++i) {
                D[i] = A[i] - B[i];
                long long target = -D[i];
                if (abs(target) <= OFFSET) {
                    total_pairs += cnt[target + OFFSET];
                }
                if (abs(D[i]) <= OFFSET) {
                    cnt[D[i] + OFFSET]++;
                }
            }
        }

        cout << total_pairs << "\n";
    }
    return 0;
}