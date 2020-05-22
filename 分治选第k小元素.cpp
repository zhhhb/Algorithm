int select_kth_smallest(vector<int> q, size_t k);
int choose_mid(vector<int>& q, int left, int right);
int selection(vector<int> v);
 
int select_kth_smallest(vector<int> q, size_t k){
	int bot = 0, top = q.size();
	while(bot < top){
		int left = bot, right = bot, i;
		int index = choose_mid(q, bot, top);
		while(right < top){
			if(q[right] < index){
				int temp = q[left];
				q[left] = q[right];
				q[right] = temp;
				left++;
			}
			if(q[right] == index)
				i = right;
			right++;
		}
		q[i] = q[left];
		q[left] = index;
		/*
		for(int a=0; a<q.size(); a++)
			cout<< q[a]<< ' ';
		cout<< endl;
		cout<< index<< endl;
		cout<< bot<< ' '<< top<< endl;
		cout<< left<< ' '<< right<< endl; 
		*/
		if(left+1 < k)
			bot = left + 1;
		else if(left+1 > k)
			top = left;
		else
			return index;
	}
	return -1;
}
 
int choose_mid(vector<int>& q, int left, int right){
	vector<int> v;
	while(left+5 < right){
		int mid = selection(vector<int>(&q[left], &q[left+5]));
		v.push_back(mid);
		left += 5;
	}
	int mid = selection(vector<int>(&q[left], &q[right]));
	v.push_back(mid);
	
	return selection(v);
}
 
int selection(vector<int> v){
	int size = v.size();
	for(int a=1; a<size; a++){
		int b = a;
		int temp = v[b];
		while(b>0 && temp<v[b-1]){
			v[b] = v[b-1];
			b--;
		}
		v[b] = temp;
	}
	int mid = (size-1)/2;
	
	return v[mid];
}

int main() {
	
	return 0;
} 
