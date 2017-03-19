//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 

#include <string>

using namespace std;

int titleToNumber(string s) {
	int result = 0, offset = 1;
	const int alphaNum = 26;
	for(auto iter = s.rbegin(); iter != s.rend(); ++iter){
		result += (*iter - 'A' + 1) * offset;
		offset *= alphaNum;
	}
	return result;
}