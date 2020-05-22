#include<stdio.h>
int m,n,sum,e[110][110],book[110],dis[110];
int inf = 99999999;
void Prim() {
	int i,j,k,min;
	for(i = 1; i <= n; i ++) {
		dis[i] = e[1][i];
		book[i] = 0;
	}
	dis[1] = 0;
	book[1] = 1;
	for(i = 1; i < n; i ++) {
		min = inf;
		for(j = 1; j <= n; j ++)
			if(book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				k = j;
			}
		sum += min;
		book[k] = 1;
		for(j = 1; j <= n; j ++)
			if(book[j] == 0 && dis[j] > e[k][j])
				dis[j] = e[k][j];
	}
}
int main()  {
	int i,j;
	while(scanf("%d",&n) != EOF) {
		sum = 0;
		for(i = 1; i <= n; i ++)
			for(j = 1; j <= n; j ++)
				scanf("%d",&e[i][j]);
		Prim();
		printf("%d\n",sum);
	}
	return 0;
}

