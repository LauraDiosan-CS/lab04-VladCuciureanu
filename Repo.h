#pragma once
#include "Transaction.h"
class Repo
{
private:
	Transaction* transactions;
	int transactions_count;
public:
	Repo();
	~Repo();
	int getSize();
	void addItem(const Transaction t);
	Transaction* getAll();
};

