# Hurley_CSCI2270_FinalProject
add test_repository.txt

Project	Summary
This project consists of four files: main.cpp, Inventory.cpp, Inventory.h, and sampleItems.txt. Main.cpp is the driver file, Inventory.cpp is the source file, Inventory.h is the header file, and sampleItems.txt is a csv file that contains information specifically formatted to be entered into the main function. Upon running the driver file, the user will be presented with a menu of eight options. The program utilizes a hash table to simulate an inventory of all the items in a grocery store, where each item is stored in the hash table as a struct with a item name, item quantity, and item category. Collisions in the hash table are resolved using linked lists. One of the menu options allows you to read in a file. If you select this option, some smaple items will be read in from the sampleItems.txt file and will be stored in the hash table. This allows for more rapid testing of the program as you will not have to manually enter items using the add item functionality. The user can view the entire inventory using the print inventory functionality, add items, delete items, view all items in a given category, buy items, and read in files. 

How	to	Run
I recommend starting your VM, downloading the main.cpp, Inventory.cpp, Inventory.h, and sampleItems.txt files and saving them in all in the same project within codeblocks. Once you have ensured that all four files are saved in the same project, hit the "build and run" button within codeblocks. You will be presented with the main menu from where you can operate the program. The sample items.txt file is provided, and selection option 7 from the main menu will read the data from that file and store it in the hash table so you do not have to manually enter the entire inventory. This allows for easier testing of each aspect of the program. To set the txt file as the programs argument, go to the project dropdown menu, select set program's arguments, and type sampleItems.txt into the program arguments box. If the file is accessed successfully, upon selecting option #7 in the main menu the program will output "File opened successfully" to the terminal. You must have the file saved in the same folder as the rest of the project to access it through the progrram.

Dependencies
The only necessary elements are that you download all four files and run them on a code editor.

System	Requirements
If you run this in the VM you will have the necessary requirements

Group	Members
Channing Hurley

Contributors:
none

Open	issues/bugs:
None known
