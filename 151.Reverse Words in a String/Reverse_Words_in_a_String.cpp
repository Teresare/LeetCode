//Reverse_Words_in_a_String
//
//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space.
//
//Clarification:
//What constitutes a word?
//A sequence of non-space characters constitutes a word.
//Could the input string contain leading or trailing spaces?
//Yes. However, your reversed string should not contain leading or trailing spaces.
//How about multiple spaces between two words?
//Reduce them to a single space in the reversed string.

#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void reverseWords(string &s) {
	istringstream input(s);
	vector<string> str;
	string temp;
	while(input >> temp){
		str.push_back(temp);
	}
	s.clear();
	for(vector<string>::reverse_iterator iter = str.rbegin(); iter != str.rend(); ++iter){
		s += *iter;
		if(iter + 1 != str.rend()){
			s += " ";
		}
	}
}