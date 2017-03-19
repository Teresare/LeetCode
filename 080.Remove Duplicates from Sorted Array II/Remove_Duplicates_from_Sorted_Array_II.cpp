#include <vector>

using namespace std;

//方法一
int removeDuplicates(vector<int>& nums) {
	if(0 == nums.size()) return 0;
	bool secondNumber = false;
	int index = 0;
	for(int i = 1; i != nums.size(); ++i){
		if(nums[index] != nums[i]){
			nums[++index] = nums[i];
			secondNumber = false;
		}
		else if(!secondNumber){
			nums[++index] = nums[i];
			secondNumber = true;
		}
	}
	return index + 1;
}

//方法二
int removeDuplicates(vector<int>& nums) {
	if(2 >= nums.size()) return nums.size();
	int index = 2;
	for(int i = 2; i != nums.size(); ++i){
		if(nums[index -2] != nums[i]){
			nums[index++] = nums[i];
		}
	}
	return index;
}

//方法三
int removeDuplicates(vector<int>& nums) {
	int index = 0;
	for(int i = 0; i != nums.size(); ++i){
		if(i > 0 && i < nums.size() - 1 
			&& nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
				continue;
		nums[index++] = nums[i];
	}
	return index;
}