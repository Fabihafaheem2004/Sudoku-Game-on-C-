import tkinter as tk
from tkinter import messagebox
import random

class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku")
        
        self.board = self.generate_board()
        self.cells = [[None for _ in range(9)] for _ in range(9)]
        
        self.create_board()
        self.create_buttons()

    def create_board(self):
        for i in range(9):
            for j in range(9):
                frame = tk.Frame(self.root, borderwidth=1, relief="solid", width=40, height=40)
                frame.grid(row=i, column=j)
                
                if self.board[i][j] != 0:
                    label = tk.Label(frame, text=str(self.board[i][j]), font=("Arial", 18))
                    label.pack()
                else:
                    entry = tk.Entry(frame, font=("Arial", 18), justify="center", width=2)
                    entry.pack()
                    self.cells[i][j] = entry

    def create_buttons(self):
        check_button = tk.Button(self.root, text="Check", command=self.check_solution)
        check_button.grid(row=9, column=4)

        solve_button = tk.Button(self.root, text="Solve", command=self.solve)
        solve_button.grid(row=9, column=5)

    def check_solution(self):
        solution = self.solve_board([row[:] for row in self.board])
        user_solution = self.get_user_solution()
        if user_solution == solution:
            messagebox.showinfo("Sudoku", "Correct solution!")
        else:
            messagebox.showerror("Sudoku", "Incorrect solution!")

    def get_user_solution(self):
        solution = [[self.board[i][j] for j in range(9)] for i in range(9)]
        for i in range(9):
            for j in range(9):
                if self.cells[i][j] is not None:
                    val = self.cells[i][j].get()
                    if val.isdigit():
                        solution[i][j] = int(val)
                    else:
                        solution[i][j] = 0
        return solution

    def solve(self):
        solution = self.solve_board([row[:] for row in self.board])
        if solution:
            for i in range(9):
                for j in range(9):
                    if self.cells[i][j] is not None:
                        self.cells[i][j].delete(0, tk.END)
                        self.cells[i][j].insert(0, str(solution[i][j]))
        else:
            messagebox.showerror("Sudoku", "No solution exists!")

    def generate_board(self):
        board = [[0 for _ in range(9)] for _ in range(9)]
        self.solve_board(board)
        self.remove_numbers(board)
        return board

    def remove_numbers(self, board):
        num_removed = 40  # Number of cells to remove
        while num_removed > 0:
            row, col = random.randint(0, 8), random.randint(0, 8)
            if board[row][col] != 0:
                board[row][col] = 0
                num_removed -= 1

    def solve_board(self, board):
        empty = self.find_empty(board)
        if not empty:
            return board
        row, col = empty

        for num in range(1, 10):
            if self.is_valid(board, num, row, col):
                board[row][col] = num
                if self.solve_board(board):
                    return board
                board[row][col] = 0

        return None

    def find_empty(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == 0:
                    return (i, j)
        return None

    def is_valid(self, board, num, row, col):
        for i in range(9):
            if board[row][i] == num or board[i][col] == num:
                return False

        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == num:
                    return False

        return True

if __name__ == "__main__":
    root = tk.Tk()
    gui = SudokuGUI(root)
    root.mainloop()
