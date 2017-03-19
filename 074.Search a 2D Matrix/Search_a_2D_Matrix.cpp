//Search a 2D Matrix
//
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix:
//
//[
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//Given target = 3, return true.

#include <vector>
#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.empty()) return false;
	const int row = matrix.size();
	const int col = matrix[0].size();
	int beg = 0;
	int end = row * col;
	while(beg < end){
		int mid = (end + beg) / 2;
		int cur = matrix[mid / col][mid % col];
		if(target > cur) beg = mid + 1;
		else if(target < cur) end = mid;
		else return true;
	}
	return false;
}

int main(){
	const int row = 3;
	const int col = 4;
	int aryTmp[row][col] = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};
	vector<vector<int> > matrix;
	for(int i = 0; i != row; ++i){
		vector<int> ary(aryTmp[i], aryTmp[i] + col);
		matrix.push_back(ary);
	}
	for(int i = 0; i != row; ++i){
		for(int j = 0; j != col; ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	while(true){
		int target = 0;
		cin >> target;
		cout<< boolalpha << searchMatrix(matrix, target) << endl;
	}
	return 0;
}