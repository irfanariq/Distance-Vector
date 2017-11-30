
#include <bits/stdc++.h>
using namespace std;

int Mt[1001][1001][2];
int N, M;

void solve(int a, int b){
	for(int i=1; i<=N; i++){
		if(i==a || i==b || Mt[a][i][0]==-1) continue;
		int c = Mt[a][i][0]+1;
		int d = Mt[b][i][0];
		if(c <= d || Mt[b][i][0]==-1){
			Mt[b][i][0] = Mt[a][i][0]+1;
			Mt[b][i][1] = (c==d)?min(Mt[b][i][1],a):a;
		}
	}
}

void output(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d %d\n", Mt[i][j][0], Mt[i][j][1]);
		}
	}
}

int main(){
	int a, b, S;

	for(int i=0; i<1001; i++){
		for(int j=0; j<1001; j++){
			Mt[i][j][0] = (i==j?0:-1);
			Mt[i][j][1] = (i==j?i:-1);
		}
	}
	cin >> N >> M;
	while(M--){
		scanf("%d %d", &a, &b);
		Mt[a][b][0]=Mt[b][a][0]=1;
		Mt[a][b][1]=b;Mt[b][a][1]=a;
	}
	cin >> S;
	while(S--){
		scanf("%d %d", &a, &b);
		solve(a,b);
	}
	output();


	return 0;
}