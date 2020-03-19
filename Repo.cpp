#include "Repo.h"

Repo::Repo()
{
	this->transactions_count = 0;
	this->transactions = new Transaction[10];
}

Repo::~Repo()
{
	if (this->transactions)
	{
		delete[] this->transactions;
		this->transactions = nullptr;
	}
}

int Repo::getSize()
{
	return this->transactions_count;
}

void Repo::addItem(const Transaction t)
{
	this->transactions[transactions_count++] = t;
}

Transaction* Repo::getAll()
{
	return this->transactions;
}