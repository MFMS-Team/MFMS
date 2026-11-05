=========================================================

README.RDM

=========================================================

PROJECT NAME

\------------

ASSETS MANAGEMENT SYSTEM

\-----------

INSTITUTION

\-----------

Namibia University of Science and Technology (NUST)

QUALIFICATION

\-------------

Bachelor of Computer Science

=========================================================

PROJECT OVERVIEW

=========================================================

The Assets Management System is a console-based application

developed using the C Programming Language.



The system is designed to manage organizational assets by

allowing users to add, search, update, delete, display,

save and load asset records.

=========================================================

FUNCTIONALITIES IMPLEMENTED

=========================================================

1\. ADD ASSET

The system captures the following asset information:

\- Asset ID Number

\- Asset Name

\- Asset Type

\- Asset Department

\- Asset Condition

\- Purchase Value



\---------------------------------------------------------

2\. DISPLAY ASSETS



Displays all stored asset records.

\---------------------------------------------------------

3\. SEARCH ASSETS



Assets can be searched by:

\- Asset ID Number

\- Asset Name

\---------------------------------------------------------



4\. UPDATE ASSETS

The following information can be updated:

\- Asset ID

\- Asset Name

\- Asset Type

\- Asset Department

\- Asset Condition

\- Purchase Value

\---------------------------------------------------------



5\. DELETE ASSETS

Removes an asset record from the system.

\---------------------------------------------------------

6\. SAVE ASSETS

Stores all asset records in a file.

\---------------------------------------------------------



7\. LOAD ASSETS

Loads all asset records from a file into memory.

\---------------------------------------------------------



8\. RETURN TO MAIN MENU

Returns the user to the main system menu.

=========================================================

ASSET TYPES AVAILABLE

=========================================================

1\. Vehicle

2\. Computer

3\. Printer

4\. Building

5\. Office Furniture

6\. Equipment

7\. Generator

8\. Water Infrastructure

9\. Electrical Infrastructure

10\. Other

=========================================================

ASSET DEPARTMENTS AVAILABLE

=========================================================

1\. Finance

2\. Human Resources

3\. Information Technology

4\. Procurement

5\. Engineering

6\. Water Management

7\. Electricity Service

8\. Town Planning

9\. Customer Care

10\. Legal

=========================================================

ASSET CONDITIONS AVAILABLE

=========================================================

1\. Excellent

2\. Good

3\. Fair

4\. Poor

5\. Damage

=========================================================

VALIDATION RULES

=========================================================

ASSET ID

\- Cannot be empty

\- Digits only

ASSET NAME

\- Cannot be empty

\- Letters and spaces only

=========================================================

DATA STRUCTURES USED

=========================================================

The system uses arrays to store assets data.

Asset Identity Number

asset\_id\[MAX\_ASSETS]\[20]

Asset Name

asset\_name\[MAX\_ASSETS]\[50]

Asset Type

asset\_type\[MAX\_ASSETS]\[50]

Asset Department

asset\_department\[MAX\_ASSETS]\[50]

Asset Condition

asset\_condition\[MAX\_ASSETS]\[30]

Purchase Value

purchase\_value\[MAX\_ASSETS]

=========================================================

FILE HANDLING

=========================================================

The system uses text file handling to store and retrieve

asset records.

FILE USED

assets.txt

SAVE FUNCTION

The SaveAssets() function performs the following tasks:

\- Opens assets.txt in write mode.

\- Writes all asset records into the file.

\- Uses fprintf() to write data.

\- Closes the file using fclose().

Functions Used:

fopen()

fprintf()

fclose()

\---------------------------------------------------------

LOAD FUNCTION

The LoadAssets() function performs the following tasks:

\- Opens assets.txt in read mode.

\- Reads records from the file.

\- Loads records into arrays.

\- Uses fscanf() to extract asset information.

\- Closes the file using fclose().

Functions Used:

fopen()

fscanf()

fclose()

\---------------------------------------------------------

FILE FORMAT

Each asset record is stored as:

Asset ID,

Asset Name,

Asset Type,

Asset Department,

Asset Condition,

Purchase Value

Example:

1001, Laptop, Computer, Information Technology, Good, 25000.00

=========================================================

PROGRAM MODULES

=========================================================

AddAsset()

Adds new asset records.

DisplayAsset()

Displays all assets.

SearchAsset()

Searches assets using ID or Name.

UpdateAsset()

Updates asset information.

DeleteAsset()

Deletes asset records.

SaveAssets()

Saves asset records into assets.txt.

LoadAssets()

Loads asset records from assets.txt.

AssetMenu()

Main menu for asset management.

=========================================================

COMPILATION

=========================================================

Compile:

gcc assets.c -o assets

Run:

assets.exe

=========================================================

END OF DOCUMENT

=========================================================

