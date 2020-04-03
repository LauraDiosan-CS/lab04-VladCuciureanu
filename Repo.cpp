#include "Repo.h"
#include <iostream>

#define REPO_MAX 20

Repo::Repo()
{
	this->transactions_count = 0;
	this->transactions = new Transaction[REPO_MAX];
	this->id_count = 1;
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
	{
		this->transactions[transactions_count++] = t;
		this->id_count++;
	}
	else
		std::cout << "Couldn't add transaction. Repo is full!";
}

int Repo::findItem(const Transaction t)
{
	Transaction* transactions = this->getAll();
	for (int i = 0; i < this->getSize(); i++)
	{
		if (transactions[i] == t)
			return i;
	}
	return -1;
}

int Repo::findItemValues(unsigned short day, unsigned int sum, short type, const char* desc)
{
	Transaction* t = this->getAll();
	for (int i = 0; i < this->getSize(); i++)
	{
		if (t[i].getDay() == day && t[i].getSum() == sum && t[i].getType() == type && strcmp(t[i].getDesc(), desc)==0)
			return i;
	}
	return -1;
}

int Repo::findId(const int id)
{
	Transaction* transactions = this->getAll();
	for (int i = 0; i < this->getSize(); i++)
	{
		if (transactions[i].getId() == id)
			return i;
	}
	return -1;
}

Transaction Repo::getItemFromPos(int pos)
{
	return this->getAll()[pos];
}

void Repo::delItem(const Transaction t)
{
	int index = this->findItem(t);
	if (index == -1)
		return;
	for (int i = index + 1; i < this->transactions_count; i++)
	{
		this->transactions[i - 1] = this->transactions[i];
	}
	this->transactions_count--;
}

void Repo::updateItem(int id, unsigned short day = 0, unsigned int sum = 0, short type = -1, const char* desc = nullptr)
{
	int index = this->findId(id);
	if (index == -1)
		return;
	if (day != 0)
		transactions[index].setDay(day);
	if (sum != 0)
		transactions[index].setSum(sum);
	if (type != -1)
		transactions[index].setType(type);
	if (strlen(desc) >= 1)
		transactions[index].setDesc(desc);
}

Transaction* Repo::getAll()
{
	return this->transactions;
}

int Repo::getNextId()
{
	return this->id_count;
}