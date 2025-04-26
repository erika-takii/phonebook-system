# Phonebook Management System in C
A clean implementation of phonebook management system demonstrating core C programming skills.

## Project Structure
phonebook_project/
├── include/
│ └── phonebook.h # Public interface declarations
├── src/
│ ├── phonebook.c # Core implementation
│ └── main.c # Application entry point
└── tests/
├── test1.c # Unit tests (basic operations)
└── test2.c # Integration tests (full workflow)


## How to Build
# Compile main application
gcc src/main.c src/phonebook.c -o phonebook

# Run program
./phonebook

# Compile and run test1 (basic functionality)
gcc tests/test1.c src/phonebook.c -o test1 && ./test1

# Compile and run test2 (extended features)
gcc tests/test2.c src/phonebook.c -o test2 && ./test2

## Key Features
Memory Safety: Proper allocation/deallocation
Modularity: Clear header/source separation
Error Handling: Robust input validation
Search Function: Efficient name lookup

## Next Steps
Implement Hash Table Backend
Develop CLI Version with Readline
