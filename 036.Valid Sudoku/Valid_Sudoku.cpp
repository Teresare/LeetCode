//Determine if a Sudoku is valid
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. 
//	Only the filled cells need to be validated.

#include <vector>

using namespace std;

bool check(char ch, bool used[]){
	if(ch == '.') return true;
	if(used[ch - '1']) return false;
	return used[ch - '1'] = true;
}

bool isValidSudoku(vector<vector<char>>& board) {
	const int num = 9;
	bool used[num];
	for(int i = 0; i != num; ++i){
 		fill(used, used + num, false);
		for(int j = 0; j != num; ++j){
			if(!check(board[i][j], used))
				return false;
		}
		fill(used, used + num, false);
		for(int j = 0; j != num; ++j){
			if(!check(board[j][i], used))
				return false;
		}
	}
	const int n = 3;
	for(int r = 0; r != n; ++r){
		for(int c = 0; c != n; ++c){
			fill(used, used + num, false);
			for(int i = r * n; i != r * n + n; ++i){
				for(int j = c * n; j != c * n + n; ++j){
					if(!check(board[i][j], used))
						return false;
				}
			}
		}
	}
	return true;
}