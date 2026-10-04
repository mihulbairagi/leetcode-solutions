class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        self.solve(board)

    def solve(self, board):
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    for num in range(1, 10):
                        char_num = str(num)
                        if self.is_valid(board, row, col, char_num):
                            board[row][col] = char_num
                            if self.solve(board):
                                return True
                            board[row][col] = '.'
                    return False
        return True

    def is_valid(self, board, row, col, num):
        for x in range(9):
            if board[row][x] == num: return False
            if board[x][col] == num: return False
            if board[3 * (row // 3) + x // 3][3 * (col // 3) + x % 3] == num: return False
        return True