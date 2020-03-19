#pragma once
#include "Transaction.h"
class Repo
{
private:
	Transaction* transactions;
	int transactions_count;
public:
	/*
	Blank constructor.
	*/
	Repo();

	/*
	Deconstructor
	*/
	~Repo();

	/*
	Returns the number of items stored in the repo.
	Out: number of items.
	*/
	int getSize();

	/*
	Adds a 'Transaction' object to repo array.
	In: Object to be added.
	*/
	void addItem(const Transaction t);
	
	/*
	Returns a pointer to the object array.
	Out: object pointer to first element in repo array.
	*/
	Transaction* getAll();
};

