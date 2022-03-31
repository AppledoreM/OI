#include <iostream>
#include <math.h>
#include <string>

using namespace std;
typedef long long ll;


ll prim[105];
ll num[105];
int ks[105];

int main()
{
    ll res = 0;
    int T;
    cin >> T;
    int caseCnt = 0;
    while(T--)
    {
        ++caseCnt;
        int M;
        cin >> M;
        ll C = 0;
        for(int j = 0; j < M; ++j)
        {
            cin >> prim[j] >> num[j];
            C += prim[j] * num[j];
        }
        ll res = 0;
        for(int i = 2; i <= 30000 && i < C; ++i)
        {
            ll val = 1;

			ll rem = C - i;
            ll sum = 0;

			for (int j = 0; j < M; ++j)
            {
                ks[j] = 0;
                while (rem % prim[j] == 0)
                {
                    ks[j]++;
                    rem /= prim[j];
                    if (ks[j] >= num[j]) break;
                }
                sum += ks[j] * prim[j];
            }
            
            if (rem != 1) continue;
            ll prod = C - i;
            if (C == prod + sum)
            {
                res = max(res, prod);
            }
		}
        cout << "Case #" << caseCnt << ": " << res << endl;
    }
}
