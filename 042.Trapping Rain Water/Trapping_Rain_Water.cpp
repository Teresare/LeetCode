//Given n non-negative integers representing an elevation map where the width of each bar is 1, 
//compute how much water it is able to trap after raining.
//
//For example, 
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
//6 units of rain water (blue section) are being trapped. 

#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
	const int n = height.size();
	int *max_left = new int[n]();
	int *max_right = new int[n]();

	for(int i = 1; i < n; ++i){
		max_left[i] = max(height[i - 1], max_left[i - 1]);
		max_right[n - 1 - i] = max(height[n - i], max_right[n - i]);
	}

	int sum = 0;

	for(int i = 0; i != n; ++i){
		int high = min(max_left[i], max_right[i]);
		if(high > height[i]){
			sum += high - height[i];
		}
	}

	return sum;
}

int trap(vector<int>& height) {
	const int n = height.size();
	int max = 0;
	for(int i = 1; i < n; ++i){
		if(height[i] > height[max]){
			max = i;
		}
	}
	int water = 0;
	for(int i = 0, peak = 0; i < max; ++i){
		if(height[i] > peak) peak = height[i];
		else water += peak - height[i];
	}
	for(int j = n - 1, peak = 0; j > max; --j){
		if(height[j] > peak) peak = height[j];
		else water += peak - height[j];
	}
	return water;
}

int trap(int a[], int n) {
	stack<pair<int, int>> s;
	int water = 0;
	for (int i = 0; i < n; ++i) {
		int height = 0;
		while (!s.empty()) { // 将栈里比当前元素矮或等高的元素全部处理掉
			int bar = s.top().first;
			int pos = s.top().second;
			// bar, height, a[i] 三者夹成的凹陷
			water += (min(bar, a[i]) - height) * (i - pos - 1);
			height = bar;
			if (a[i] < bar) // 碰到了比当前元素高的，跳出循环
				break;
			else
				s.pop(); // 弹出栈顶，因为该元素处理完了，不再需要了
		}
		s.push(make_pair(a[i], i));
	}
	return water;
}