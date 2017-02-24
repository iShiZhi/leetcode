class Solution {
 public:
	 void solveSudoku(vector<vector<char>>& board) {
		 vector<int> x;
		 vector<int> y;
		 vector<vector<char>> result;

		 for (int i = 0; i < 9; i++) {
			 for (int j = 0; j < 9; j++) {
				 if (board[i][j] == '.') {
					 x.push_back(i);
					 y.push_back(j);
				 }
			 }
		 }

		 fillDigit(board, result, x, y, 0);
		 board = result;
	 }

	 void fillDigit(vector<vector<char>>& board, vector<vector<char>>& result, vector<int>& x, vector<int>& y, int filledCount) {
		 if (filledCount <= x.size() - 1) {
			 set<char> filled;
			 getfilledNums(board, x[filledCount], y[filledCount], filled);
			 for (char i = '1'; i <= '9'; i++) {
				 if (filled.find(i) == filled.end()) {
					 board[x[filledCount]][y[filledCount]] = i;
					 fillDigit(board, result, x, y, filledCount + 1);
					 board[x[filledCount]][y[filledCount]] = '.';
				 }
			 }
		 } else {
			 for (int i = 0; i < 9; i++) {
				 vector<char> r;
				 for (int j = 0; j < 9; j++) {
					 r.push_back(board[i][j]);
				 }

				 result.push_back(r);
			 }
		 }
	 }

	 void getfilledNums(vector<vector<char>>& board, int x, int y, set<char>& filled) {
		 for (int i = 0; i < 9; i++) {
			 filled.insert(board[x][i]);
			 filled.insert(board[i][y]);
		 }

		 for (int i = 0; i < 3; i++) {
			 for (int j = 0; j < 3; j++) {
				 filled.insert(board[x / 3 * 3 + i][y / 3 * 3 + j]);
			 }
		 }
	 }
 };