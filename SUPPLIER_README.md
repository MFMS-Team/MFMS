Supplier Management Module

Name: Aina N Kuume
Student Number:225168448
Course: PAP521S - Programming in Practice
Project: Project A - Municipal Financial Management System
My Part: Supplier Management

---

 What This Module Does

This is the supplier part of our MFMS project. It lets the user add suppliers,
list all suppliers, and search for a supplier using their ID.

I also added validation so the program doesn't accept wrong input like letters
in the ID field or an email without an @ sign.



 Features I Built

- Add a new supplier (ID, name, email, phone, town)
- Show all suppliers that were added
- Search for a supplier using their ID
- Stop the user from adding the same ID twice
- Check each field before saving:
  - Name = letters and spaces only
  - ID = numbers only
  - Email = must have @ and a dot after it
  - Phone = numbers only
  - Town = letters and spaces only



 Functions I Wrote

 Function and  What it does :
 ValidateSupplierName : Checks the name has only letters and spaces 
 ValidateSupplierTown : Checks the town has only letters and spaces 
ValidateSupplierPhone : Checks the phone has only numbers 
 ValidateSupplierIDNumber : Checks the ID has only numbers 
 ValidateSupplierEmail : Checks the email has @ and a dot after it 
 isDuplicateID : Stops the same ID being added twice 
 displaySuppliers : Shows all suppliers 
 searchSupplier : Finds a supplier by their ID 



 C Things I Used

- Arrays to store the supplier information
- String functions: strlen, strcmp, strcspn
- Functions (each task has its own function)
- For loops and do-while loops
- If-else for validation
- Switch for the menu


Files

- supplier.c - the code
- supplier.h - the function list



 How to Compile
gcc -std=c99 -Wall -Wextra -pedantic supplier.c -o supplier



 How to Run
supplier

text


 What I Tested

- Added a supplier with correct details -> worked
- Tried letters in the ID -> got rejected
- Tried the same ID twice -> got rejected
- Tried an email without @ -> got rejected
- Tried letters in the phone -> got rejected
- Left the name empty -> got rejected
- Listed all suppliers -> worked
- Searched for an existing ID -> found it
- Searched for a wrong ID -> said not found

Screenshots are in the screenshots folder.



 My Contribution

I (Aina N Kuume, 225168448) did this whole supplier module by myself. I wrote
all the validation functions, the display, the search, and the duplicate check.
I also tested everything and pushed it to GitHub.


