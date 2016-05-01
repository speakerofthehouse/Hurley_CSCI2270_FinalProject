#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Inventory.h"

using namespace std;

//University of Colorado, Boulder
//CSCI 2270 Final Project
//Prof. Rhonda Hoenigman
//Created by Channing J. Hurley on 04/23/16
//
//This program keeps track of an inventory of items in a grocery store. Items are stored in a hash table as structs called "item".
//Each item has the attributes of name (a string, such as "apple"), category (also a string, such as "fruit), and quantity (an integer).
//The hash table handles collisions by creating a linked list of items that have the same hash key, with the head of the list at
//the index that corresponds to the hash key. For this reason, each item struct also has a next and previous pointer as an attribute
//
//The following code will display the menu, take user input for which function they would like to run, run the corresponding function,
//and continue displaying the menu until the user selects quit. The functions are further explained below.
//
//I recommend downloading the driver file, the header file, the source file, and the sample items text file and running them in Code::Blocks
//

int main(int argc, char * argv[])
{
    Inventory I1; //Initiate an instance of the Inventory class
    while(1){
        //Print the menu
        int selection;
        cout << "======Main Menu======" << endl;
        cout << "1. Print Inventory" << endl;
        cout << "2. Print all items in a category" << endl;
        cout << "3. Find item" << endl;
        cout << "4. Buy item" << endl;
        cout << "5. Add item" << endl;
        cout << "6. Delete item" << endl;
        cout << "7. Read in a CSV file" << endl;
        cout << "8. Quit" << endl;
        //cin >> selection;
        //cin.ignore(1000, '\n');

        while (!(cin>>selection) || selection < 1 || selection > 8){
            cout<<"Please select a listed option."<<endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

        if(selection == 1){
            //This option will print the entire contents of the inventory
            I1.printTableContents();
        }else if(selection == 2){
            //This option will search the entire hash table and print the items that are in the desired category
            string category;
            cout << "Valid categories are Dairy, Meat, Frozen foods, Baked goods, Beverages, Grains, Produce, Other" << endl;
            cout << "Enter a category:" << endl;
            getline(cin, category);
            I1.printCategory(category);
        }else if(selection == 3){
            //This option will find an item in the hash table and print the quantity in stock and the category
            string name;
            cout << "Enter an item:" << endl;
            getline(cin, name);
            I1.findItem(name);
        }else if(selection == 4){
            //This option will check if an item is in the inventory
            //If it is, it will subtract the quantity the user wants to buy from the amount in the inventory
            //If the user buys all of the items, the item will be deleted from the inventory
            //if the user attempts to buy more items than are in stock, they will be asked to enter a lower amount
            string name;
            int amount;
            cout << "Enter an item:" << endl;
            getline(cin, name);
            cout << "Enter the amount you would like to buy:" << endl;
            cin >> amount;
            I1.buyItem(name, amount);
        }else if(selection == 5){
            //This option will add an item to the inventory
            //If the item is already in the inventory, then the quantity will be added to the amount already in stock
            string name, category;
            int quantity;
            cout << "Enter an item:" << endl;
            getline(cin, name);
            cout << "Enter the quantity to add:" << endl;
            cin >> quantity;
            cin.ignore(1000, '\n');
            cout << "Valid categories are Dairy, Meat, Frozen foods, Baked goods, Beverages, Grains, Produce, Other" << endl;
            cout << "Enter a category:" << endl;
            getline(cin, category);
            I1.insertItem(name, quantity, category);
        }else if(selection == 6){
            //This option will delete an item from the inventory entirely
            string name;
            cout << "Enter an item to delete:" << endl;
            getline(cin, name);
            I1.deleteItem(name);
        }else if(selection == 7){
            //Read in  a file
            //File should be formatted with each line representing one item in the following format:
            //item name,item quantity,item category
            //Must be separated by commas, format is better if there are no spaces
            ifstream inFile;
            string data;
            inFile.open(argv[1]);
            if(inFile.good()){
                cout << "Reading file..." << endl;
                string line, word;
                string name, category;
                int quantity;
                while(getline(inFile, line)){
                    stringstream ss(line);
                    int counter = 0;
                    while(getline(ss, word, ',')){
                        if(counter == 0){
                            name = word;
                            counter++;
                        }else if(counter == 1){
                            quantity = atoi(word.c_str());
                            counter++;
                        }else if(counter == 2){
                            category = word;
                        }
                    }
                    I1.insertItem(name, quantity, category);
                }
            }else{
                cout << "File not found" << endl;
            }
        }else if(selection == 8){
            //Quit
            cout << "Goodbye!" << endl;
            break;
        }

    }
    return 0;
}
