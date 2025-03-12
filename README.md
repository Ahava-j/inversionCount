# **Counting Inversions**

This program was developed for the CSC 3430 Algorithms & Design course.  
It calculates the number of inversions needed to sort an array using the **Divide and Conquer** approach.  The goal of this project is to deepen my understanding of Merge Sort-based inversion counting and how to implement it efficiently.

---

## **Explanation of the Algorithm**

Before diving into the implementation, it's important to understand what **inversions** are:  

- **An inversion** occurs when an element appears **before another larger element** in an unsorted array.  
- The goal is to **count these inversions** while sorting the array efficiently.  

### **Approach**
To solve this problem, I implemented the **Divide and Conquer** technique:

1️⃣ **Divide** the array into two halves recursively.  
2️⃣ **Count inversions** in the **left** and **right** halves.  
3️⃣ **Merge the two halves** while tracking the number of **inversions** in the combined array.  

This process is very similar to **Merge Sort**, but instead of just sorting the array, we also **count the number of inversions happening at each step**.

---

## **Installation**

### **Prerequisites**
To run this program, you will need:
- A **C++ compiler** (such as `g++`).
- A **terminal or command prompt**.
- (Optional) An **IDE** like **VS Code**, **CLion**, or **Code::Blocks**.

### **Installing `g++` (for Windows Users)**
Windows users should **install MinGW**:
1. Download **MinGW-w64** from [mingw-w64.org](https://www.mingw-w64.org/downloads/).
2. Install it following the instructions.
3. Verify the installation by running:

  ```bash
   g++ --version 
   ```


## User Manual

Once you have g++ installed, navigate to the project directory in your terminal and compile the program using:

```bash
  g++ main.cpp inversions.cpp -o myprogram
   ```
Then, run the program:


```bash
 ./myprogram
   ```

## How to Use the Program


1. The program will prompt you to enter the number of elements in the array.
2. You will then input the elements of the array.
3. The program will output the total number of inversions needed to sort the array.

**Example Run**

```bash
Enter the number of elements: 4
Enter the elements: 4 3 2 1
Total Inversions: 6
   ```

## Challenges I Faced
- Understanding why l + (r - l) / 2 is used to find the middle index.
Not grasping why l is added to (r - l) / 2.
- Difficulty understanding and implementing the combine step of the counts inversions.
- Setting up .gitignore properly to avoid tracking unnecessary files.

## Learnings 

- l + (r - l) / 2 ensures the middle index is relative to the subarray, not always based on the full array.
- The combine step counts how many elements in the left subarray are greater than elements in the right subarray.
- Implemented a proper .gitignore file


