//Single_Number_II
//
//Given an array of integers, every element appears three times except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	const int size = sizeof(int) * 8;
	int count[size] = {0};
	for(int i = 0; i != nums.size(); ++i){
		for(int j = 0; j != size; ++j){
			count[j] += (nums[i] >> j) & 1;
			count[j] %= 3;
		}
	}
	int result = 0;
	for(int j = 0; j != size; ++j){
		result += count[j] << j;
	}
	return result;
}

int singleNumber(vector<int>& nums) {
	int one = 0, two = 0, three = 0;
	for(int i = 0; i != nums.size(); ++i){
		two |= one & nums[i];
		one ^= nums[i];
		three = ~(one & two);
		one &= three;
		two &= three;
	}
	return one;
}