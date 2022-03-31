#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 5e6 + 10;
int N,M;
int a[maxn];
int B = 464;
inline int bel(int x){ return (x - 1) / B + 1;}
struct query{
	int l,r,id,tim,ans;
	query(int a = 0,int b = 0,int c = 0):l(a),r(b),id(c),ans(0),tim(0){};
	bool operator < (const query &oth) const {
		if(bel(l) != bel(oth.l)) return l < oth.l;
		if(bel(r) != bel(oth.r)) return r < oth.r;
		return id < oth.id;
	}
} que[maxn];
int cnt[maxn],pos[maxn],val[maxn],tim[maxn],cur,tot,tot1,pre[maxn];
int pl = 1,pr = 0,ans;

void change_add(int cur){
	if(pos[cur] >= pl && pos[cur] <= pr){
		cnt[a[pos[cur]]]--;
		if(!cnt[a[pos[cur]]]) ans--;	
	}	
	pre[cur] = a[pos[cur]];
	a[pos[cur]] = val[cur];
	if(pos[cur] >= pl && pos[cur] <= pr){
		if(!cnt[a[pos[cur]]]) ans++;
		cnt[a[pos[cur]]]++;
	}
}

void change_del(int cur){
	if(pos[cur] >= pl && pos[cur] <= pr){
		cnt[a[pos[cur]]]--;
		if(!cnt[a[pos[cur]]]) ans--;
	}
	a[pos[cur]] = pre[cur];
	if(pos[cur] >= pl && pos[cur] <= pr){
		if(!cnt[a[pos[cur]]]) ans++;
		cnt[a[pos[cur]]]++;
	}
}
void change(int now){
	while(cur < tot1 && tim[cur + 1] <= now) change_add(++cur);
	while(cur && tim[cur] > now) change_del(cur--);	
}
void add(int x){
	if(!cnt[x]) ans++;
	cnt[x]++;
}
void del(int x){
	cnt[x]--;
	if(!cnt[x]) ans--;
}
bool cmp(query a,query b){ return a.id < b.id;}
int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= N; i++) scanf("%d",&a[i]);
	for(int i = 1; i <= M; i++){
		char opt[2];
		scanf("%s",opt);
		int l,r;
		scanf("%d%d",&l,&r);
		if(opt[0] == 'Q') ++tot,que[tot].l = l,que[tot].r = r,que[tot].id = tot, que[tot].tim = i;
		else pos[++tot1] = l, val[tot1] = r,tim[tot1] = i; 
	}
	sort(que + 1,que + 1 + tot);
	for(int i = 1; i <= tot; i++){
		change(que[i].tim);
		while(pl < que[i].l) del(a[pl++]);
		while(pl > que[i].l) add(a[--pl]);
		while(pr < que[i].r) add(a[++pr]);
		while(pr > que[i].r) del(a[pr--]);	
		que[i].ans = ans;
	}	
	sort(que + 1, que + 1 + tot,cmp);
	for(int i = 1; i <= tot; i++) printf("%d\n",que[i].ans);
	return 0;
}
