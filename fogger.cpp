#include <iostream>
#include <algorithm>

#define N 101
#define MAX 10001

using namespace std;
int GetResult(int bridge_len,int min_hops,int max_hops,int stone_num,int* stone_pos);

int main(){
	int L,S,T,M,re;
	int stone_pos[N];

	cin >> L >> S >> T >> M;
	for(int i=1;i<=M;i++){
		cin >> stone_pos[i];
	}
	re = GetResult(L,S,T,M,stone_pos);
	cout << re << endl;
	return 0;
}

int GetResult(int bridge_len,int min_hops,int max_hops,int stone_num,int*stone_pos){
	int re = 0;//得到的结果。
	/***************1.如果步长为一常数，那么石子的位置只要在min_hop的倍数上，则一定可达。*******/
	if(min_hops == max_hops){
		for(int i=1;i<=stone_num;i++){
			if(stone_pos[i]%min_hops == 0){
				re++;
			}
		}
		return re;
	}

	/******************2.步长在一定范围内，那么就将桥的长度进行压缩,然后计算相应结果。*************************/
	int reL = 0;//reL->压缩后桥的长度。
	int exist[MAX] = {0};//exist->每个位置是否存在石子。
	int result[MAX] = {0};//result->到达每个位置需要经历的最少的石子数目。
	sort(stone_pos+1,stone_pos+stone_num+1);

	reL = stone_pos[1]%90;
	exist[reL] = 1;
	for(int i=2;i<=stone_num;i++){
		reL = reL + (stone_pos[i] - stone_pos[i-1])%90;
		exist[reL] = 1;
	}
	//cout << reL << endl;

	for(int i=reL;i>=0;i--){
		result[i] = 100;
		for(int j=min_hops;j<=max_hops;j++){
			//cout << i << "," << j << ":" << " " << result[i] << " " << result[i+j] << " " << exist[i] << " " << result[i+j]+exist[i] << endl;
			result[i] = min(result[i+j]+exist[i],result[i]);
		}
		//cout << i << ": " << result[i] << endl;
	}

	re = result[0];
	return re;
}
