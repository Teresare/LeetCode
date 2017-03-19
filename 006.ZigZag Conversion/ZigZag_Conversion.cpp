//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//(you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <string>

using namespace std;

string convert(string s, int numRows) {
	if(numRows <= 1) return s;
	string str;
	for(int i = 0; i != numRows; ++i){
		string::size_type base = i;
		while(base < s.size()){
			str.push_back(s[base]);
			if(i != 0 && i != numRows - 1){
				string::size_type temp = base + 2 * (numRows - 1 - i);
				if(temp < s.size()){
					str.push_back(s[temp]);
				}
			}
			base += 2 * numRows - 2;
		}
	}
	return str;
}

//标准答案
string convert(string s, int nRows) {
	if (nRows <= 1 || s.size() <= 1) return s;
	string result;
	for (int i = 0; i < nRows; i++) {
		for (int j = 0, index = i; index < s.size();
			j++, index = (2 * nRows - 2) * j + i) {
				result.append(1, s[index]); // 垂直元素
				if (i == 0 || i == nRows - 1) continue; // 斜对角元素
				if (index + (nRows - i - 1) * 2 < s.size())
					result.append(1, s[index + (nRows - i - 1) * 2]);
		}
	}
	return result;
}