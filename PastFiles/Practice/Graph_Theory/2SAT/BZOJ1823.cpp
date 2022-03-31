//This code is written by Hzwer I lost my own
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,n,m;
int cnt,ind,scc,top;
int last[1005],dfn[1005],low[1005],q[1005],belong[1005];
bool inq[1005];
struct edge{
	int to,next;
}e[20005];
int get()
{
	int x;
	char c=getchar();
	while(c!='m'&&c!='h')c=getchar();
	if(c=='m')x=read()*2;
	else x=read()*2-1;
	return x;
}
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
void tarjan(int x)
{
	low[x]=dfn[x]=++ind;
	inq[x]=1;q[++top]=x;
	for(int i=last[x];i;i=e[i].next)
		if(!dfn[e[i].to])
		{
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if(inq[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x])
	{
		scc++;
		int now=0;
		while(now!=x)
		{
			now=q[top--];
			belong[now]=scc;
			inq[now]=0;
		}
	}
}
int main()
{
	T=read();
	while(T--)
	{
		top=ind=cnt=scc=0;
		n=read();m=read();
		for(int i=1;i<=2*n;i++)
			last[i]=dfn[i]=0;
		int x,y,xp,yp;
		for(int i=1;i<=m;i++)
		{
			x=get();y=get();
			if(x%2==0)xp=x--;
			else xp=x++;
			if(y%2==0)yp=y--;
			else yp=y++;
			insert(xp,y);insert(yp,x);
		}
		bool flag=0;
		for(int i=1;i<=2*n;i++)
			if(!dfn[i])tarjan(i);
		for(int i=1;i<=n;i++)
			if(belong[2*i]==belong[2*i-1])
			{puts("BAD");flag=1;break;}
		if(!flag)puts("GOOD");
	}
	return 0;
}
