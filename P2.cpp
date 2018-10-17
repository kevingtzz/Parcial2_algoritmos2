#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>
using namespace std;

struct Tortuga
{
    int Peso, fueza;
};

bool comp(const Tortuga &t1, const Tortuga &t2)
{
   return t1.fueza < t2.fueza;
}

vector<Tortuga> T;
int dp[5607];

void solve()
{
    sort(T.begin(), T.end(), comp);

    fill(dp, dp + 5607, numeric_limits<int>::max());
    dp[0] = 0;
    
    int maxTortugas = 0;

    for (int i = 0; i < T.size(); ++i)
        for (int j = maxTortugas; j >= 0; --j)
            if (T[i].fueza >= dp[j] + T[i].Peso
                && T[i].Peso + dp[j] < dp[j + 1])
            {
                dp[j + 1] = dp[j] + T[i].Peso;
                maxTortugas = max(maxTortugas, j + 1);
            }
    
    cout << maxTortugas << endl;
}

int main()
{
    Tortuga t;
    while (cin >> t.Peso >> t.fueza)
        T.push_back(t);

    solve();
}
