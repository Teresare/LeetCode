//Given a set of distinct integers, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void subsetsFunc(vector<vector<int> > &result, vector<int> &row, vector<int> &nums, int level){
	if(level == nums.size()){
		result.push_back(row);
		return;
	}
	subsetsFunc(result, row, nums, level + 1);
	row.push_back(nums[level]);
	subsetsFunc(result, row, nums, level + 1);
	row.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int> > result;
	vector<int> row;
	subsetsFunc(result, row, nums, 0);
	return result;
}


//标准答案，迭代法
vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(), S.end()); // 输出要求有序
	vector<vector<int> > result(1);
	for (auto elem : S) {
		result.reserve(result.size() * 2);
		auto half = result.begin() + result.size();
		copy(result.begin(), half, back_inserter(result));
		for_each(half, result.end(), [&elem](decltype(result[0]) &e){
			e.push_back(elem);
		});
	}
	return result;
}

//标准答案，二进制法
vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(), S.end()); // 输出要求有序
	vector<vector<int> > result;
	const size_t n = S.size();
	vector<int> v;
	for (size_t i = 0; i < 1 << n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (i & 1 << j) v.push_back(S[j]);
		}
		result.push_back(v);
		v.clear();
	}
	return result;
}


//标准答案，位向量法
static void subsets(const vector<int> &S, vector<bool> &selected, int step,vector<vector<int> > &result) {
	if (step == S.size()) {
		vector<int> subset;
		for (int i = 0; i < S.size(); i++) {
			if (selected[i]) subset.push_back(S[i]);
		}
		result.push_back(subset);
		return;
	}
	// 不选 S[step]
	selected[step] = false;
	subsets(S, selected, step + 1, result);
	// 选 S[step]
	selected[step] = true;
	subsets(S, selected, step + 1, result);
}

vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(), S.end()); // 输出要求有序
	vector<vector<int> > result;
	vector<bool> selected(S.size(), false);
	subsets(S, selected, 0, result);
	return result;
}