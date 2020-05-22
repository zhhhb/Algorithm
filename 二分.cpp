#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[6];
	int key;
	for(int i=1;i<6;i++) cin >> a[i];
	cin >> key;
	int flag = 0;
	int low=1,mid,high=6;
	while(low <= high) {
		mid=(low+high)/2;
		if(key == a[mid]) {
			flag = 1;
			cout << mid << endl;
			break;
		}
		if(key > a[mid]) {
			low = mid + 1;
		}
		if(key < a[mid]) {
			high = mid - 1;
		}
	} 
	if(flag == 0) cout << "0" << endl;
	return 0;
} 
