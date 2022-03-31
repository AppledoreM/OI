#include <bits/stdc++.h>
using namespace std;
int wa[N],wb[N],wsf[N],wv[N],sa[N];
int rank[N],height[N],s[N],a[N],n;
char str1[N],str2[N];
int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void getsa(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++)  wsf[i]=0;
    for(i=0; i<n; i++)  wsf[x[i]=r[i]]++;
    for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];
    for(i=n-1; i>=0; i--)  sa[--wsf[x[i]]]=i;
    p=1;
    j=1;
    for(; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++)  y[p++]=i;
        for(i=0; i<n; i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;
        for(i=0; i<n; i++)  wv[i]=x[y[i]];
        for(i=0; i<m; i++)  wsf[i]=0;
        for(i=0; i<n; i++)  wsf[wv[i]]++;
        for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];
        for(i=n-1; i>=0; i--)  sa[--wsf[wv[i]]]=y[i];
        t=x;
        x=y;
        y=t;
        x[sa[0]]=0;
        for(p=1,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
void getheight(int *r,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)  rank[sa[i]]=i;
    for(i=0; i<n; i++)
    {
        if(k)
            k--;
        else
            k=0;
        j=sa[rank[i]-1];
        while(r[i+k]==r[j+k])
            k++;
        height[rank[i]]=k;
    }
}
int ans;
int fun(int k)
{
    int i,maxn,minn;
    maxn = minn = sa[1];
    UP(i,2,n)
    {
        if(height[i]>=k && i<n)
        {
            minn = min(minn,sa[i]);
            maxn = max(maxn,sa[i]);
            continue;
        }
        if(maxn-minn>=k) return 1;
        maxn = minn = sa[i];
    }
    return 0;
}
 
 
int main()
{
    int i,j,k;
    W((~scanf("%d",&n),n))
    {
        UP(i,0,n-1)
        {
            scanf("%d",&s[i]);
        }
        UP(i,0,n-2)
        {
            s[i] = s[i+1]-s[i]+100;
        }
        s[--n] = 0;
        getsa(s,sa,n+1,200);
        getheight(s,n);
        int l = 4,r = n;
        W(l<=r)
        {
            int mid = (l+r)/2;
            if(fun(mid))
            {
                ans = mid;
                l=mid+1;
            }
            else r = mid-1;
        }
        ans++;
        printf("%d\n",ans<5?0:ans);
    }
 
    return 0;
}
