/**
1.  LPS exists in range [1, n]; n = length of string
2.  Define a function with the help of hashing strategy
    as existsPalindrome(str, len).
3.  existsPalindrome(str, len) = returns TRUE if there
    is any palindromic substring in `str` of length `len`.
4.  As we observed that, the LPS length follows a binary property,
    we can run binary search over the length of our desired answer.
5.  We can divide the binary search into two groups. One for even,
    one for odd length.
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int BASE = 129;

/// po[i] = (BASE ^ i) % MOD
vector<long long> generateExponents(int N) {
    vector<long long> po(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        po[i] = (po[i - 1] * BASE) % MOD;
    }
    return po;
}

vector<long long> generatePrefixHash(string &s) {
    vector<long long> H(s.size(), 0);
    H[0] = s[0];
    for (int i = 1; i < s.size(); i++) {
        H[i] = ((H[i - 1] * BASE) + s[i]) % MOD;
    }
    return H;
}

long long getRangeHash(int L, int R, vector<long long> &H, vector<long long> &po) {
    if (!L) return H[R];
    return (H[R] - (H[L - 1] * po[R - L + 1] % MOD) + MOD) % MOD;
}

bool existsPalindrome(int len, vector<long long> &sH, vector<long long> &rsH, vector<long long> &po) {
    int N = sH.size();
    for (int i = 0; i + len <= sH.size(); i++) {
        int L1 = i;
        int R1 = i + len - 1; /// [0,1,2,3,4,5]
        int R2 = N - 1 - L1;
        int L2 = R2 - R1 + L1;
        if (getRangeHash(L1, R1, sH, po) == getRangeHash(L2, R2, rsH, po)) {
            return true;
        }
    }
    return false;
}

int findLPS(int L, int R, bool isOdd, vector<long long> &sH, vector<long long> &rsH, vector<long long> &po) {
    while(L < R) {
        int M = (L + R + 1) / 2;
        if (!existsPalindrome(M + M + isOdd, sH, rsH, po)) {
            R = M - 1;
        }
        else {
            L = M;
        }
    }
    return R + R + isOdd;
}

int main() {
    int cs = 1, T = 1;
    while(T--) {
        string rs, s;
        int N;
        cin >> N >> s;
        rs = s;
        reverse(rs.begin(), rs.end());
        auto sH = generatePrefixHash(s);
        auto rsH = generatePrefixHash(rs);
        auto po = generateExponents(s.size());

        // ODD, 1, 3, 5, 7, 9, 11, 13, 15
        // 2x + 1; x = 0, 1, 2, 3, 4, 5, 6, 7
        int L = 1, R = N - (N % 2 == 0), LPS = 1;
        L = 0, R = (R - 1) / 2;
        LPS = max(LPS, findLPS(L, R, true, sH, rsH, po));

        // EVEN
        L = 0, R = N - (N % 2 == 1);
        R = R / 2;
        LPS = max(LPS, findLPS(L, R, false, sH, rsH, po));
        printf("%d\n", LPS);
    }
    return 0;
}
/**
5
ababa
7
xaaaaaa

**/
