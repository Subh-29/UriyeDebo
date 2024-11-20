
def isValidMove(board, row, col, num):

    if num in board[row]:
        return False
    if num in (board[i][col] for i in range(9)):
        return False
    
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False
    
    return True

def sudokuSolver(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if isValidMove(board, row, col, num):
                        board[row][col] = num

                        if sudokuSolver(board):
                            return True
                        
                        board[row][col] = 0


                return False
    return True


def printSudoku(board):
    for row in board:
        row_display = []
        for num in row:
            if num == 0:
                row_display.append(".")
            else:
                row_display.append(str(num))
        print(" ".join(row_display))

if __name__ == "__main__":
    sudoku_board = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    print("Initial sudoku puzzle:\n")
    printSudoku(sudoku_board)

    if sudokuSolver(sudoku_board):
        print("Sodoku has been solved:\n")
        printSudoku(sudoku_board)
    else:
        print("Solution doesn't exist!!")