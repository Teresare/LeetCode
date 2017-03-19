#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//方法一
int removeDuplicates(vector<int>& nums) {
	if(0 == nums.size()) return 0;
	int index = 0;
	for(int i = 0; i != nums.size(); ++i){
		if(nums[index] != nums[i]){
			nums[++index] = nums[i];
		}
	}
	return index + 1;
}

//方法二
int removeDuplicates(vector<int>& nums) {
	return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

//方法三
template<typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last, OutIt output){
	while(first != last){
		*output++ = *first;
		first = upper_bound(first, last, *first);
	}
	return output;
}

int removeDuplicates(vector<int>& nums) {
	return removeDuplicates(nums.begin(), nums.end(), nums.begin()) - nums.begin();
}