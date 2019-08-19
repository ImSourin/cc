#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define p(x) printf("%lld\n", x)
#define sl(x) scanf("%lld", &x)
#define INF 1e18+9
#define endl '\n'
#define FIO ios_base::sync_with_stdio(false)
using namespace std;
#define MOD 1000000007
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define S6 6000006

//string scan
void ss(string &i){
	int temp=getchar_unlocked();
	while((temp < 'a' || temp > 'z') && (temp < 'A' || temp > 'Z'))
		temp=getchar_unlocked();
	while((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')){
		i.pb((char)temp);
		temp = getchar_unlocked();
	}
}

//long long scan
void ls(ll &x){
	register ll c = getchar_unlocked();
	x = 0;
	for(; (c<48 || c>57); c = getchar_unlocked());
	for(; c>47 && c<58; c = getchar_unlocked()){
		x = (x<<1) + (x<<3) + c - 48;
	}
}

//binary exponentiation
ll binexp(ll a, ll b, ll m){
	ll result = 1;
	while(b>0){
		if(b & 1){
			result = result * a;
			result %= m;
		}
		a = a * a;
		a %= m;
		b = b >> 1;
	}
	return result;
}

//seive
bool isprime[S6];
void sieve(){
	for(int i = 2; i < 10000001; ++i){
		if(isprime[i] == 0){
			for(int j = 2; i*j < 10000001; ++j){
				isprime[i*j] = 1;
			}
		}
	}
}

//etf
int phi[S6];
void etf(){
	for(int i=0; i < 1000001; ++i)
		phi[i] = i;
	for(int i=2; i < 1000001; ++i){
		if(phi[i] == i ){
			for(int j=1; i*j < 1000001; ++j){
				phi[i*j] /= i;
				phi[i*j] *= (i-1);
			}
		}
	}
}

//segment tree
int a[S6];
struct segnode{
    segnode *l,*r;
    int val;
    segnode()
    {
        l=r=NULL;
        val=0;
    }
};
struct segnode *root;
void build(segnode *&node,int st,int en)
{
	if(st==en)
	{
		node = new segnode();
		node->val = a[st];
		return;
	}
	node = new segnode();
	int mid = st + (en-st)/2;
    build(node->l,st,mid);
    build(node->r,mid+1,en);
	node->val = max(node->l->val,node->r->val);
}
int query(segnode *&node,int st,int en,int qs,int qe)
{
    if(qe<st||qs>en)
        return 0;
    if(node==NULL)
        return 0;
    if(st>=qs&&en<=qe)
        return node->val;
    int mid = st + (en-st)/2;
    return max(query(node->l,st,mid,qs,qe),query(node->r,mid+1,en,qs,qe));
}
void update(segnode *&node,int st,int en,int id,int val)
{
    if(id<st||id>en)
        return;
    if(!node)
        node=new segnode();
    node->val = max(node->val,val);
    if(st==en)
        return;
    int mid = st + (en-st)/2;
    update(node->l,st,mid,id,val);
    update(node->r,mid+1,en,id,val);
}

//dsu
int parent[S6], rnk[S6];
void make(int v){
	parent[v] = v;
	rnk[v] = 0;
}

int find(int v){
	if(parent[v] != v)
		parent[v] = find(parent[v]);
	return parent[v];
}
void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(rnk[a] < rnk[b])
			swap(a, b);
		parent[b] = a;
		if(rnk[a] == rnk[b])
			rnk[a]++;
	}
}

//matrix expo
void matmul(ll a[3][3], ll b[3][3], ll c[3][3]){
	int i, j, k;
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 3; ++j){
			c[i][j] = 0;
			for(k = 0; k < 3; ++k){
				c[i][j] += (a[i][k]*b[k][j]) % MOD;
				c[i][j] %= MOD;
			}
		}
	}
}

void matexp(ll a[3][3], ll b, ll ans[3][3]){
	int i, j;
	ll tmp[3][3];
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 3; ++j){
			if(i == j){
				ans[i][j] = 1;
			}
			else{
				ans[i][j] = 0;
			}
		}
	}
	while(b > 0){
		if(b&1){
			matmul(ans, a, tmp);
			for(i = 0; i < 3; ++i)
				for(j = 0; j < 3; ++j)
					ans[i][j] = tmp[i][j];
		}
		matmul(a, a, tmp);
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j)
				a[i][j] = tmp[i][j];
		b >>= 1;
	}
}

int main()
{
	cout<<"gg"<<endl;
	return 0;
}