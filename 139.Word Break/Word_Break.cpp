//Given a string s and a dictionary of words dict, 
//determine if s can be segmented into a space-separated sequence 
//of one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".

#include <string>
#include <unordered_set>

using namespace std;


//深搜
static bool dfs(const string &s, unordered_set<string> &dict,size_t start, size_t cur) {
	if (cur == s.size()) {
		return dict.find(s.substr(start, cur-start+1)) != dict.end();
	}
	if (dfs(s, dict, start, cur+1)) return true;
	if (dict.find(s.substr(start, cur-start+1)) != dict.end())
		if (dfs(s, dict, cur+1, cur+1)) return true;
	return false;
}

bool wordBreak(string s, unordered_set<string> &dict) {
	return dfs(s, dict, 0, 0);
}

//动态规划
bool wordBreak(string s, unordered_set<string>& wordDict) {
	vector<bool> f(s.size() + 1, false);
	f[0] = true; // 空字符串
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (f[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
				f[i] = true;
				break;
			}
		}
	}
	return f[s.size()];
}