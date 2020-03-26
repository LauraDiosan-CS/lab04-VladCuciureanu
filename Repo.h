#pragma once
#include "Transaction.h"
class Repo
{
private:
	int id_count;
public:
	Transaction* transactions;
	int transactions_count;
	/*
	Blank constructor.
	*/
	Repo();

	/*
	Deconstructor
	*/
	~Repo();

	/*
	Adds a 'Transaction' object to repo array.
	In: Object to be added.
	*/
	void addItem(const Transaction t);

	/*
	Returns the index of the given item if found in the array.
	In: Object to be found.
	*/
	int findItem(const Transaction t);

	/*
	Returns the index of the given item if found in the array.
	In: Object to be found.
	*/
	int findItemValues(unsigned short day, unsigned int sum, short type, const char* desc);

	/*
	Returns the index of the item with given id if found in the array.
	In: Id of the object to be found.
	*/
	int findId(const int id);

	/*
	Returns the item from given index in array.
	In: position in array.
	*/
	Transaction getItemFromPos(int pos);

	/*
	Deletes item from repo if found.
	In: Object to be deleted from repo.
	*/
	void delItem(const Transaction t);

	/*
	Updates given item if found in repo with given values.
	In: item to be updated.
	*/
	void updateItem(int id, unsigned short day, unsigned int sum, short type, const char* desc);
	
	/*
	Returns a pointer to the object array.
	Out: object pointer to first element in repo array.
	*/
	Transaction* getAll();

	/*
	Returns the number of items stored in the repo.
	Out: number of items.
	*/
	int getSize();

	/*
	Returns an unique id.
	In: id.
	*/
	int getNextId();

};

