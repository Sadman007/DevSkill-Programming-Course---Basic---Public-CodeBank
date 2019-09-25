#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")
#define isprime(x) prm::miller_rabin(x)

bool isPrime(char c)
{
    return (c == '2' || c == '3' || c == '5' || c == '7');
}

void decrease(string& s, int i)
{
    if (s[i] <= '2')
    {
        s.erase(i, 1);
        s[i] = '7';
    }

    else if (s[i] == '3')
        s[i] = '2';
    else if (s[i] <= '5')
        s[i] = '3';
    else if (s[i] <= '7')
        s[i] = '5';
    else
        s[i] = '7';

    return;
}

string primeDigits(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isPrime(s[i]))
        {
            while (s[i] <= '2' && i >= 0)
                i--;
            if (i < 0)
            {
                i = 0;
                decrease(s, i);
            }
            else
                decrease(s, i);
            for (int j = i + 1; j < s.length(); j++)
                s[j] = '7';
            break;
        }
    }
    return s;
}

ll to_Int(string &s)
{
    stringstream ss;
    ss << s;
    ll num;
    ss >> num;
    return num;
}


namespace prm  /// hash = 130793
{
bitset <MAX> flag;
long double op = 0.0;
int p = 0, prime[78777];
const int base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

void Sieve()
{
    int i, j, x;
    for (i = 3; i < MAX; i += 2) flag[i] = true;
    for (i = 3, flag[2] = true; (i * i) < MAX; i += 2)
    {
        if (flag[i])
        {
            for (j = (i * i), x = i << 1; j < MAX; j += x)
            {
                flag[j] = false;
            }
        }
    }

    for (i = 2; i < MAX; i++)
    {
        if (flag[i]) prime[p++] = i;
    }
}

void init()
{
    if (!flag[2]) Sieve();
}

inline long long mul(long long a, long long b, long long MOD)
{
    if ((MOD < 3037000500LL)) return ((a * b) % MOD);
    long double res = a;
    res *= b;
    long long c = (long long)(res * op);
    a *= b;
    a -= c * MOD;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}

inline long long expo(long long x, long long n, long long m)
{
    long long res = 1;

    while (n)
    {
        if (n & 1) res = mul(res, x, m);
        x = mul(x, x, m);
        n >>= 1;
    }

    return (res % m);
}

inline bool miller_rabin(long long p)
{
    if (p < MAX) return flag[p];
    if ((p + 1) & 1) return false;
    for (int i = 1; i < 10; i++)  /// basic iterations
    {
        if (!(p % prime[i])) return false;
    }

    long long a, m, x, s = p - 1, y = p - 1;
    op = (long double)1 / p, s = s >> __builtin_ctzll(s);

    for (int i = 0; i < 7; i++)
    {
        x = s, a = (base[i] % y) + 1;
        m = expo(a, x, p);
        while ((x != y) && (m != 1) && (m != y)) m = mul(m, m, p), x <<= 1;
        if ((m != y) && !(x & 1)) return false;
    }
    return true;
}

inline long long countdiv(long long n)
{
    int i, j, c;
    long long x, res = 1;
    for (i = 0; i < p; i++)
    {
        x = prime[i];
        if ((x * x * x) > n) break;

        c = 1;
        while (!(n % x)) c++, n /= x;
        res *= c;
    }

    if (miller_rabin(n)) res <<= 1;
    else if (n > 1)
    {
        x = sqrt((long double)0.95 + n); /// may be change to sqrtl() ?
        if ((x * x) == n && miller_rabin(x)) res *= 3;
        else res <<= 2;
    }

    return res;
}
}

int main()
{
    prm::init();
    int test,cs=1;
    scanf("%d",&test);
    while(test--)
    {
        string str,prv;
        cin >> str;
        ll fin_res;
        while(1)
        {
            prv = str;
            str = primeDigits(str);
            ll num = to_Int(str);
            if(isprime(num))
            {
                fin_res = num;
                break;
            }
            if(prv == str)
            {
                num = to_Int(str);
                --num;
                stringstream ss;
                ss << num;
                ss >> str;
            }
        }
        printf("Case %d: %lld\n",cs++,fin_res);
    }
    return 0;
}
