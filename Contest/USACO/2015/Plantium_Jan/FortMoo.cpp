#include <bits/stdc++.h>
using namespace std;
const int N=205;
char a[N][N];
int n,m,i,j,k,x,y,ans,b[N][N];
int main()
{
    freopen("fortmoo.in","r",stdin);
    freopen("fortmoo.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(j=1;j<=m;j++)
     for(i=1;i<=n;i++)
     if(a[i][j]=='X') b[i][j]=b[i-1][j]+1;else b[i][j]=b[i-1][j];
    for(i=1;i<=n;i++)
     for(j=i;j<=n;j++)
    {
        x=0;y=0;
        for(k=1;k<=m;k++)
            if(b[j][k]-b[i-1][k]==0)
        {
            x=max(x,k);
            y=x;
            while(x<m&&a[i][x+1]=='.'&&a[j][x+1]=='.')
            {
                x++;
                if(b[j][x]-b[i-1][x]==0) y=x;
            }
            ans=max(ans,(j-i+1)*(y-k+1));
        }
    }
    cout<<ans;
    return 0;
}
