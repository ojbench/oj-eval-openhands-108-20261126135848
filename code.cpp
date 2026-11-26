#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        int p, w, v;
        if (scanf("%d %d %d", &p, &w, &v) != 3) break;

        // Binary decomposition: split p items into groups of 1, 2, 4, ...
        int k = 1;
        while (k <= p) {
            int cw = k * w;
            int cv = k * v;
            for (int j = m; j >= cw; j--) {
                if (dp[j - cw] + cv > dp[j]) {
                    dp[j] = dp[j - cw] + cv;
                }
            }
            p -= k;
            k *= 2;
        }
        // Remaining items
        if (p > 0) {
            int cw = p * w;
            int cv = p * v;
            for (int j = m; j >= cw; j--) {
                if (dp[j - cw] + cv > dp[j]) {
                    dp[j] = dp[j - cw] + cv;
                }
            }
        }
    }

    printf("%d\n", dp[m]);
    return 0;
}
