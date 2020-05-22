//Kruskal
#include<bits/stdc++.h>
using namespace std;

struct node {
	int a,b; //边的起点为a，终点为b
	int len; //边的长度
};

node edge[10005];
int father[10005];
int n,m;  //n为顶点数，m为边数

int cmp(node x, node y) { //按边长由小到大排序
	return x.len < y.len;
}

int getfather(int x) { //判断两个顶点是否同属一棵生成树
	if(x != father[x]) father[x] = getfather(father[x]);
	return father[x];
}

void kruskal() {
	int x,y;
	int k=0,cnt=0,tot=0;  //cnt统计合并次数，为n-1次时得到最小生成树 
	while(cnt < n-1) {
		k++;
		x = getfather(edge[k].a);
		y = getfather(edge[k].b);
		if(x != y) {
			father[x] = y;
			tot += edge[k].len;
			cnt++;
		}
	}
	cout << tot;
}

int main() {
	cin >> n; //农场个数
	int temp = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int t;
			cin >> t;
			if(i != j) {
				temp++;
				edge[temp].a = i;
				edge[temp].b = j;
				edge[temp].len = t;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		father[i] = i;
	}
	sort(edge+1,edge+1+temp,cmp);
	kruskal();
	return 0;
}
