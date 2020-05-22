#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int edge[9][9] ={
	{-1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1,  0,  1,inf,inf,inf,inf,inf,inf},
	{-1,inf,  0,inf,  2,inf,inf,inf,inf},
	{-1,  2,inf,  0,inf,inf,inf,inf,inf},
	{-1,inf,inf,  1,  0,inf,  8,inf,inf},
	{-1,inf,inf,inf,  2,  0,inf,  2,inf},
	{-1,inf,inf,inf,inf,  2,  0,inf,inf},
	{-1,inf,inf,inf,inf,inf,  3,  0,  3},
	{-1,inf,inf,inf,inf,inf,  3,inf,  0}
};
int main() {
	const int n = 8;//点的数量
	int dis[n+1];//当前各点到源点的距离
	int book[n+1];//各点到源点是否为最小值
 
	//初始化，设源点为n1
	for (int i = 1; i <= n; ++i)
		dis[i] = edge[1][i];
 
	//book数组初始化
	memset(book, 0, sizeof(book));
	book[1] = 1;
 
	int min;//当前，未确定最短路径的点，到源点的最小距离大小
	//Dijkstra算法核心语句
	for (int i = 1; i <= n - 1; ++i) {
		//找到离1号顶点最近的顶点
		min = inf;
		int u;
		for (int j = 1; j <= n; ++j) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		//每轮迭代都可以确定一个点到源点的最短距离，因此只要迭代n-1轮
		book[u] = 1;
		//通过已经确定的点，对dis数组进行更新
		//（未确定的点通过点u，缩小了到源点的距离）
		for (int v = 1; v <= n; ++v) {
			if (edge[u][v] < inf) {
				if (dis[v] > dis[u] + edge[u][v])
					dis[v] = dis[u] + edge[u][v];
			}
		}
	}
	//输出结果
	for (int i = 1; i <= n; ++i) cout << dis[i] << ' ';
	return 0;
} 
