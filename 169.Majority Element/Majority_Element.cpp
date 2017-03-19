#include <map>
#include <vector>
#include <iostream>
using namespace std;

//方法1:
int majorityElement(vector<int>& nums) {
	map<int, int> imap;
	for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
		++imap[*iter];
	}
	int maxNum = 0;
	int result = 0;
	for(map<int, int>::iterator iter = imap.begin(); iter != imap.end(); ++iter){
		if(iter->second > maxNum){
			result = iter->first;
			maxNum = iter->second;
		}
	}
	return result;
}

//方法2：当数据量大并且特殊时，会造成超时，只适合作为一种思路
int Partition(vector<int> &ivec, int beg, int end){
	int number = ivec[end - 1];
	int i = beg - 1;
	int j = beg;
	for(; j != end - 1; ++j){
		if(ivec[j] <= number){
			swap(ivec[++i], ivec[j]);
		}
	}
	swap(ivec[++i], ivec[j]);
	return i;
}

int majorityElement(vector<int>& nums){
	if(nums.size() <= 0) return 0;
	int middle = nums.size() >> 1;
	int start = 0;
	int end = nums.size();
	int index = Partition(nums, start, end);
	while(index != middle){
		if(middle < index){
			end = index;
			index = Partition(nums, start, end);
		}
		else{
			start = index;
			index = Partition(nums, start, end);
		}
	}
	return nums[middle];
}

//方法3：纯数学的方法
int majorityElement(vector<int>& nums){
	if(nums.size() <= 0) return 0;
	int result = nums[0];
	int time = 1;
	for(int i = 1; i != nums.size(); ++i){
		if(0 == time){
			result = nums[i];
			time = 1;
		}
		else if(nums[i] == result){
			++time;
		}
		else{
			--time;
		}
	}
	return result;
}