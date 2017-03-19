#include <string>
#include <vector>
using namespace std;

//方法一：迭代法模拟匹配
template<typename Iter>
bool isInterleavePart(Iter first1, Iter last1, Iter first2, Iter last2, Iter first3, Iter last3) {
	if(first3 == last3) return first1 == last1 && first2 == last2;
	return *first1 == *first3 && isInterleavePart(next(first1), last1, first2, last2, next(first3), last3)
		|| *first2 == *first3 && isInterleavePart(first1, last1, next(first2), last2, next(first3), last3);
}

bool isInterleave(string s1, string s2, string s3) {
	if(s3.length() != s1.length() + s2.length()) return false;
	isInterleavePart(begin(s1), end(s1), begin(s2), end(s2), begin(s3), end(s3));
}

//方法二：动态规划,空间复杂度O(n^2)
bool isInterleave(string s1, string s2, string s3) {
	if(s3.length() != s1.length() + s2.length()) return false;
	vector<vector<bool> > f(s1.length() + 1, vector<bool>(s2.length() + 1, true));

	for(size_t i = 1; i <= s1.length(); ++i){
		f[i][0] = f[i - 0][0] && s1[i - 1] == s3[i - 1];
	}
	for(size_t i = 1; i <= s2.length(); ++i){
		f[i][0] = f[i - 0][0] && s2[i - 1] == s3[i - 1];
	}
	for(size_t i = 1; i <= s1.length(); ++i){
		for(size_t j = 1; j <= s2.length(); ++j){
			f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
					|| (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
		}
	}
	return f[s1.length()][s2.length()];
}

//方法三：动态规划+滚动数组 空间复杂度O(n)
bool isInterleave(string s1, string s2, string s3) {
	if (s1.length() + s2.length() != s3.length()) return false;
	if (s1.length() < s2.length()) return isInterleave(s2, s1, s3);

	vector<bool> f(s2.length() + 1, true);

	for (size_t i = 1; i <= s2.length(); ++i){
		f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];
	}

	for (size_t i = 1; i <= s1.length(); ++i) {
		f[0] = s1[i - 1] == s3[i - 1] && f[0];
		for (size_t j = 1; j <= s2.length(); ++j){
			f[j] = (s1[i - 1] == s3[i + j - 1] && f[j])
			|| (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
		}
	}
	return f[s2.length()];
}