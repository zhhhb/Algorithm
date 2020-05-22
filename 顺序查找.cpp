#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[6];
	int key;
	for(int i=1;i<6;i++) cin >> a[i];
	cin >> key;
	int flag = 0;
	for(int i=1;i<5;i++) {
		if(a[i] == key) {
			cout << i << endl;
			flag = 1;
			break;
		}
	}
	if(flag == 0) cout << "0" << endl;
	return 0;
} 
