# Student-Database-with-C

This repository contains a C program designed to manage a student database. The project demonstrates the use of structures, 2D arrays, and advanced file operations to track student grades and performance.

---

## 🛠 Features

The program is structured to handle data for **10 students** and perform the following automated tasks:

* 
**Student Data Structuring**: Stores student names, IDs, a 2D array of marks for three subjects (Attendance, CT, Mid, and Final), and overall CGPA.


* 
**File-Based Input**: Populates student records by reading data from `input.txt` using file operations.


* **Detailed Reporting**: Generates a comprehensive `output.txt` file containing:
* Full student profiles.


* Calculated total marks for each subject per student.


* Class-wide statistics, including the **Maximum** and **Minimum CGPA**.





---

## 📁 File Structure

| File | Description |
| --- | --- |
| `Program.c` | The core source code containing the logic for file I/O and data processing. |
| `Assignment.pdf` | The original project specification and requirements.

 |
| `input.txt` / `DATAS.txt` | Sample input files containing raw student data.

 |
| `output.txt` | The final generated report including student details and statistics.

 |

---

## 💻 Technical Details

### Structure Definition

The program utilizes a custom `struct` to organize data efficiently:

```c
struct student {
    char name[50], id[50];
    float marks[3][4]; // Rows: Subjects, Cols: Assessment types
    float cgpa;
};

```

### Core Functions

* `write_input()`: Interactively takes user input and writes it to the initial data file.
* 
`print()`: Formats and writes the basic student info to the output file.


* 
`printtotal()`: Calculates the sum of all four assessment marks for each of the three subjects.


* 
`maxCGPA()` / `minCGPA()`: Iterates through the student array to identify the highest and lowest performers.



---

## 🚀 How to Run

1. Ensure you have a C compiler installed (e.g., GCC).
2. Place `input.txt` in the same directory as the source code.
3. Compile the program:
`gcc Program.c -o student_db`
4. Run the executable:
`./student_db`
5. Check `output.txt` for the generated results.
