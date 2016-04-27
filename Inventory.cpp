#include <iostream>
#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{
    //ctor
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = NULL;
    }
}

Inventory::~Inventory()
{
    //dtor
}

int Inventory::hashSum(std::string name, int tableSize){
    int sum = 0;
    for(int i = 0; i < name.size(); i++){
        sum = sum + name[i];
    }
    sum = sum % tableSize;
    return sum;
}

bool Inventory::isInInventory(std::string name){
    int index = hashSum(name, tableSize);
    item *head = hashTable[index];
    bool found  = false;
    while(head != NULL && found == false){
        if(head->name == name){
            found = true;
        }else{
            head = head->next;
        }
    }
    if(found == true){
        return true;
    }else{
        return false;
    }
}

item* Inventory::setPointerToItem(std::string name){
    int index = hashSum(name, tableSize);
    item *head = hashTable[index];
    bool found  = false;
    while(head != NULL && found == false){
        if(head->name == name){
            found = true;
        }else{
            head = head->next;
        }
    }
    return head;
}

void Inventory::insertItem(std::string name, int quantity, std::string category){
    if(isInInventory(name) == true){
        //If the item is already in the inventory, add the quantity of items to be added to the existing
        //item's quantity attribute
        item *addTo = setPointerToItem(name);
        cout << "Item already in inventory, incrementing amount" << endl;
        cout << quantity << " of " << name << " added to inventory" << endl;
        addTo->quantity = addTo->quantity + quantity;


    }else{
        //Create a new item node and insert it at the end of the linked list that is in the index
        //corresponding to the item's hash key
        int index = hashSum(name, tableSize);
        if(hashTable[index] == NULL){
            hashTable[index] = new item(name, quantity, category);
            cout << quantity << " of " << name << " added to inventory" << endl;
            hashTable[index]->previous = NULL;
            hashTable[index]->next = NULL;
        }else{
            item *head = hashTable[index];
            while(head->next != NULL){
                head = head->next;
            }
            head->next = new item(name, quantity, category);
            cout << quantity << " of " << name << " added to inventory" << endl;
            item *temp = head->next;
            temp->previous = head;
        }
    }
}

void Inventory::deleteItem(std::string name){
    if(isInInventory(name) == true){
        item *toDelete = setPointerToItem(name);
        int index = hashSum(name, tableSize);
        if(toDelete->previous == NULL && toDelete->next == NULL){
            hashTable[index] = NULL;
            toDelete = NULL;
            delete toDelete;
        }else if(toDelete->previous == NULL){
            toDelete->next->previous = NULL;
            hashTable[index] = toDelete->next;
            delete toDelete;
        }else if(toDelete->next == NULL){
            toDelete->previous->next = NULL;
            delete toDelete;
        }else{
            toDelete->next->previous = toDelete->previous;
            toDelete->previous->next = toDelete->next;
            delete toDelete;
        }
    }
}

void Inventory::findItem(std::string name){
    if(isInInventory(name) == false){
        cout << "Item not in inventory" << endl;
    }else if(isInInventory(name) == true){
        cout << "Item in stock" << endl;
        item* searchItem = setPointerToItem(name);
        cout << "Category: " << searchItem->category << " | Item: " << searchItem->name << " | Amount: " << searchItem->quantity << endl;
    }
}

void Inventory::buyItem(std::string name, int amount){
    int index = hashSum(name, tableSize);
    item *head = hashTable[index];
    bool found  = false;
    while(head != NULL && found == false){
        if(head->name == name){
            found = true;
        }else{
            head = head->next;
        }
    }
    if(found == true){
        if(amount < head->quantity){
            //If the amount desired is less than the amount in stock, sell the desired amount
            cout << amount << " of item " << head->name << " sold" << endl;
            head->quantity = head->quantity - amount;
        }else if(amount == head->quantity){
            //If the amount desired matches the amount in stock, sell the amount desired and
            //delete the item from the inventory because it will be out of stock
            cout << amount << " of item " << head->name << " sold" << endl;
            deleteItem(head->name);
        }else if(amount > head->quantity){
            //If the desired amount is greater than the amount in stock, display the amount in stock
            cout << "Only " << head->quantity << " items left in stock" << endl;
            cout << "Please enter a lower amount" << endl;
        }
    }else{
        cout << "Item is out of stock" << endl;
    }
}

void Inventory::printCategory(std::string category){
    bool isEmpty = true;
    for(int i = 0; i < tableSize; i++){
        if(hashTable[i] != NULL){
            isEmpty = false;
        }
    }
    if(isEmpty == true){
        cout << "There are no items in the inventory" << endl;
    }else{
        cout << "All " << category << " items:" << endl;
        bool categoryFill = false;
        for(int i = 0; i < tableSize; i++){
            item *walker = hashTable[i];
            while(walker != NULL){
                if(walker->category == category){
                    categoryFill = true;
                    cout << "Item: " << walker->name << " | Amount: " << walker->quantity << endl;
                }
                walker = walker->next;
            }
        }
        if(categoryFill == false){
            cout << "No items in category" << endl;
        }
    }
}

bool Inventory::isEmpty(){
    for(int i = 0; i < tableSize; i++){
        if(hashTable[i] != NULL){
            return false;
        }
    }
    return true;
}

void Inventory::printTableContents(){
    if(isEmpty() == true){
        cout << "There are no items in the inventory" << endl;
    }else{
        for(int i = 0; i < tableSize; i++){
            item *walker = hashTable[i];
            while(walker != NULL){
                cout << "Category: " << walker->category << " | Item: " << walker->name << " | Amount: " << walker->quantity << endl;
                walker = walker->next;
            }
        }
    }
}
