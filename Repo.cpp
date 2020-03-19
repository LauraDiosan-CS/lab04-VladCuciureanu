#include "Repo.h"
#include <iostream>

#define REPO_MAX 20

Repo::Repo()
{
	this->transactions_count = 0;
	this->transactions = new Transaction[REPO_MAX];
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
	if (transactions_count < REPO_MAX)
		this->transactions[transactions_count++] = t;
	else
		std::cout << "Couldn't add transaction. Repo is full!";
}

Transaction* Repo::getAll()
{
	return this->transactions;
}