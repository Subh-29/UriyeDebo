N = 4

def printSolution(board):
    for row in board:
        print(" ".join("Q" if x else "." for x in row))

def isSafe(board, row, col):
    for i in range(col):
        if board[row][i] or any(board[r][c] for r, c in zip(range(row, -1, -1), range(col, -1, -1))) or \
           any(board[r][c] for r, c in zip(range(row, N), range(col, -1, -1))):
            return False
    return True

def solveNQU(board, col):
    if col >= N:
        return True
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            if solveNQU(board, col + 1):
                return True
            board[i][col] = 0
    return False

def solveNQ():
    board = [[0] * N for _ in range(N)]
    if not solveNQU(board, 0):
        print("No solution exists")
        return
    printSolution(board)

if __name__ == "__main__":
    solveNQ()
