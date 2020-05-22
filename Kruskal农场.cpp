//Kruskal
#include<bits/stdc++.h>
using namespace std;

struct node {
	int a,b; //�ߵ����Ϊa���յ�Ϊb
	int len; //�ߵĳ���
};

node edge[10005];
int father[10005];
int n,m;  //nΪ��������mΪ����

int cmp(node x, node y) { //���߳���С��������
	return x.len < y.len;
}

int getfather(int x) { //�ж����������Ƿ�ͬ��һ��������
	if(x != father[x]) father[x] = getfather(father[x]);
	return father[x];
}

void kruskal() {
	int x,y;
	int k=0,cnt=0,tot=0;  //cntͳ�ƺϲ�������Ϊn-1��ʱ�õ���С������ 
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
	cin >> n; //ũ������
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
