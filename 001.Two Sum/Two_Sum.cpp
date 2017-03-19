//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2. 
//Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> imap;
	vector<int> result;
	for(int i = 0; i != nums.size(); ++i){
		const int gap = target - nums[i];
		if(gap == nums[i] && imap.find(gap) != imap.end()){
			result.push_back(imap[gap] + 1);
			result.push_back(i + 1);
			return result;
		}
		imap[nums[i]] = i;
	}
	for(int i = 0; i != nums.size(); ++i){
		const int gap = target - nums[i];
		if(gap != nums[i] && imap.find(gap) != imap.end()){
			result.push_back(i + 1);
			result.push_back(imap[gap] + 1);
			break;
		}
	}
	return result;
}