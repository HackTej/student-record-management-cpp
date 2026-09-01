# Student Record Management System

A lightweight, Command Line Interface (CLI) application built in C++ that performs rapid data entry and retrieval operations for student records. Designed to demonstrate core software engineering fundamentals including file I/O operations, memory management, and structured data handling.

**Tech Stack:** C++, Standard Template Library (STL), `fstream`

**Core Features**
* **Persistent File Storage:** Securely reads and writes sequential student data to a localized `.txt` database using the `fstream` library.
* **String Manipulation & Search:** Parses comma-separated values to isolate and retrieve specific records in O(N) time complexity.
* **Menu-Driven CLI:** Provides an infinite-loop navigational menu to add records, view the complete directory, and search by unique identifiers.

**How to Run Locally**
1. Clone this repository to your local machine.
2. Open your terminal in the project directory.
3. Compile the source code: `g++ main.cpp -o student_app`
4. Run the executable: `./student_app` (Mac/Linux) or `student_app.exe` (Windows).