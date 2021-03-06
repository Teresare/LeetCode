//Single Number
//
//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int singleNumber(vector<int>& nums) {
	int result = 0;
	for(int i = 0; i != nums.size(); ++i){
		result ^= nums[i];
	}
	return result;
}

int singleNumber(vector<int>& nums) {
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}