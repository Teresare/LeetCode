//Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs){
	if(strs.empty()) return "";
	for(int index = 0; index != strs[0].size(); ++index){
		for(int i = 1; i != strs.size(); ++i){
			if(strs[i][index] != strs[0][index]){
				return strs[0].substr(0, index);
			}
		}
	}
	return strs[0];
}


string longestCommonPrefix(vector<string>& strs){
	if(strs.empty()) return "";
	int rightMost = strs[0].size();
	for(int i = 1; i != strs.size(); ++i){
		for(int j = 0; j < rightMost; ++j){
			if(strs[i][j] != strs[0][j]){
				rightMost = j;
			}
		}
	}
	return strs[0].substr(0, rightMost);
}

int main(){
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
	string res = longestCommonPrefix(strs);
	cout << res << endl;
	return 0;
}