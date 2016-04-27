#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct item{
	std::string name;
	int quantity;
	std::string category;
	item *next;
    item *previous;

	item(){};
	item(std::string in_name, int in_quantity, std::string in_category)
	{
		name = in_name;
		quantity = in_quantity;
		category = in_category;
		next = NULL;
		previous = NULL;
	}

};

class Inventory
{
	public:
		Inventory();
		~Inventory();
		void printTableContents();
		void insertItem(std::string name, int quantity, std::string category);
		void deleteItem(std::string name);
		void findItem(std::string name);
		void buyItem(std::string name, int amount);
		void printCategory(std::string category);
		bool isInInventory(std::string name);
		item* setPointerToItem(std::string name);
		int hashSum(std::string x, int s);

	private:
		int tableSize = 10;
		item* hashTable[10];

};

#endif
