# Mini-Excel-Sheet
A C++ project and created a mini excel sheet console based
# 📊 Mini Excel Sheet – C++ Console Application

A console-based **spreadsheet simulator** built in C++, inspired by Microsoft Excel. This project allows users to interact with a 2D grid of cells and perform key spreadsheet operations like editing, arithmetic, sorting, file saving/loading, undo, and history tracking — all within the terminal.

---

## 🚀 Features

- 📋 **Editable Grid**: 8x10 dynamic 2D grid using vectors
- ✏️ **Cell Operations**: Set, delete, cut, copy, and paste cell values
- ➕ **Arithmetic Functions**: Perform addition, subtraction, multiplication, and division between cells
- 🔄 **Undo Support**: Revert changes using stack-based undo system
- 🕒 **History Log**: Track recent actions using a custom queue
- 🧹 **Sort Rows/Columns**: Alphabetically sort values by row or column
- 💾 **File Handling**: Save and load spreadsheets to/from `.txt` files
- 🎨 **Colorful UI & Loading Animations**: Terminal-based interface with color-coded output and animations (Windows only)

---

## 🛠️ Technologies Used

- **Language:** C++ (C++17)
- **Data Structures:** Stack (Undo), Queue (History), Vectors (Grid)
- **Libraries:** Windows.h, fstream, vector, conio.h, iostream
- **Platform:** Windows (console-based)

---

## 📁 Files in this Repo

- `Mini_Excel_Sheet.cpp` — Main source code file
- `excel.txt` — Sample file to load/save grid data (optional)

---

## 📸 Screenshots

> _You can add screenshots here once uploaded on GitHub or hosted publicly._

---

## 📚 How to Run

1. Compile using a C++17-compatible compiler (e.g., g++, MSVC)
2. Run the compiled `.exe` in a terminal
3. Use the numbered menu to perform operations on the grid

---

## 🎓 Educational Purpose

This project was developed as part of a university-level data structures assignment to apply concepts like:
- Stack and Queue implementation
- File handling
- Console interface design
- Real-world logic simulation using C++

---

## 👤 Author

**Abdullah Ilyas**  
 Aspiring C++ & Data Science Developer_

---

## 📌 Note

- This project is **Windows-only** due to the use of `windows.h` and terminal color codes.
- You can extend it by adding:
  - CSV file support
  - Formulas & expressions
  - Cell formatting or column headers
