//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
//	determine if the input string is valid.
//
//The brackets must close in the correct order, 
//"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<int> istack;
	for(int i = 0; i != s.size(); ++i){
		char ch = s[i];
		if(ch == '(' || ch == '[' || ch == '{'){
			istack.push(ch);
		}else{
			if(istack.empty()) return false;
			char temp = istack.top();
			if(temp == '(' && ch == ')'
			|| temp == '[' && ch == ']'
			|| temp == '{' && ch == '}')
				istack.pop();
			else{
				return false;
			}
		}
	}
	return istack.empty();
}

//±ê×¼´ð°¸
bool isValid(string s){
	string left = "([{";
	string right = ")]}";
	stack<char> istack;
	for(auto c : s){
		if(left.find(c) != string::npos){
			istack.push(c);
		}else{
			if(istack.empty() || istack.top != left[right.find(c)]){
				return false;
			}else{
				istack.pop;
			}
		}
	}
	return istack.empty();
}