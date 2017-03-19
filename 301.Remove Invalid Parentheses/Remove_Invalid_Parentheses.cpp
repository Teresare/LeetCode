#include <vector>
#include <string>
#include <stack>

using namespace std;

bool checkInvalidParentheses(string s){
	bool invalid = false;
	stack<char> istack;
	int i = 0;
	for(; i != s.size(); ++i){
		if('(' == s[i])
			istack.push(s[i]);
		else if(')' == s[i]){
			if(!istack.empty())
				istack.pop();
			else
				break;
		}
	}
	if(i != s.size() || !istack.empty())
		invalid = true;
	return invalid;
}

void Partition(string s, int index, vector<int> &ivec){

	ivec.push_back();
}

vector<string> removeInvalidParentheses(string s) {
	stack<char> istack;
	int leftNum = 0;
	int rightNum = 0;
	int i = 0;
	int invalidNum = 0;
	for(; i != s.size(); ++i){
		if('(' == s[i]){
			++leftNum;
			istack.push(s[i]);
		}
		else if(')' == s[i]){
			++rightNum;
			if(istack.empty()){
				break;
			}
			else{
				istack.pop();
			}
		}
		else{
			//do nothing;
		}
	}
	if(i != s.size() && istack.empty()){
		invalidNum = i;
	}
	else if(i == s.size() && !istack.empty()){

	}
}