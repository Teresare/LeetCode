#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

//int differentBetweenWords(string first, string second){
//	assert(first.size() == second.size());
//	int wordSize = first.size();
//	int diffence = 0;
//	for(int i = 0; i != wordSize; ++i){
//		if(first[i] != second[i]){
//			++diffence;
//		}
//	}
//	return diffence;
//}
//
//int subLabberLength(string beg, string end, unordered_set<string>& candidate, 
//					unordered_set<string>& path, unordered_set<string>& father){
//	if(find(path.begin(), path.end(), end) != path.end()){
//		return 1;
//	}
//	unordered_set<string> son;
//	for(unordered_set<string>::iterator iter = candidate.begin(); iter != candidate.end(); ++iter){
//		string str = *iter;
//		if(differentBetweenWords(beg, str) == 1 
//			&& find(path.begin(), path.end(), str) == path.end() 
//			&& find(father.begin(), father.end(), str) == father.end()){
//				son.insert(str);
//		}
//	}
//	path.insert(beg);
//	int min = INT_MAX;
//	for(unordered_set<string>::iterator iter = son.begin(); iter != son.end(); ++iter){
//		int number = subLabberLength(*iter, end, candidate, path, son) + 1;
//		if(min > number){
//			min = number;
//		}
//	}
//	return min;
//}
//
//int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
//	unordered_set<string> path, father;
//	path.insert(beginWord);
//	return subLabberLength(beginWord, endWord, wordDict, path, father);
//}

int ladderLength(const string& start, const string &end, const unordered_set<string> &dict) {
	queue<string> current, next; // 当前层，下一层
	unordered_set<string> visited; // 判重
	int level = 0; // 层次
	bool found = false;
	auto state_is_target = [&](const string &s) {return s == end;};
	auto state_extend = [&](const string &s) {
		vector<string> result;
		for (size_t i = 0; i < s.size(); ++i) {
			string new_word(s);
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == new_word[i]) continue;
				swap(c, new_word[i]);
				if (dict.count(new_word) > 0 && !visited.count(new_word)) {
					result.push_back(new_word);
					visited.insert(new_word);
				}
				swap(c, new_word[i]); // 恢复该单词
			}
		}
		return result;
	};
	current.push(start);
	while (!current.empty() && !found) {
		++level;
		while (!current.empty() && !found) {
			const string str = current.front();
			current.pop();
			const auto& new_states = state_extend(str);
			for (const auto& state : new_states) {
				next.push(state);
				if (state_is_target(state)) {
					found = true; //找到了
					break;
				}
			}
		}
		swap(next, current);
	}
	if (found) return level + 1;
	else return 0;
} 

int main()
{
	string begin = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	dict.insert("cog");
	int temp = ladderLength(begin, end, dict);
	return 0;
}