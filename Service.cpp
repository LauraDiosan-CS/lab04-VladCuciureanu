#include "Service.h"

Service::Service()
{

}

Service::Service(const Repo &repo)
{
	this->repo = repo;
}

Service::~Service()
{

}

void Service::addTransaction(unsigned short day, unsigned int sum, short type, const char* desc)
{
	int id = this->repo.getNextId();
	Transaction t = Transaction(id, day, sum, type, desc);
	this->repo.addItem(t);
}

void Service::delTransaction(int id)
{
	int index = this->repo.findId(id);
	if (index != -1)
		this->repo.delItem(repo.getAll()[index]);
}

void Service::updateTransaction(int id, unsigned short new_day, unsigned int new_sum, short new_type, const char* new_desc)
{
	this->repo.updateItem(id, new_day, new_sum, new_type, new_desc);
}

Transaction* Service::getTransactions()
{
	return this->repo.getAll();
}

int Service::getSize()
{
	return this->repo.getSize();
}

Transaction Service::getTransactionFromPos(int pos)
{
	return this->repo.getItemFromPos(pos);
}

int Service::findTransaction(unsigned short day, unsigned int sum, short type, const char* desc)
{
	return this->repo.findItemValues(day, sum, type, desc);
}

void Service::delTransactionsByDay(unsigned short day)
{
	Transaction* t = repo.getAll();
	int count = repo.getSize();
	for (int i = count - 1; i >= 0; i--)
	{
		if (t[i].getDay() == day)
			repo.delItem(t[i]);
	}
}

void Service::delTransactionsInInterval(int m, int n)
{
	Transaction* t = repo.getAll();
	int count = repo.getSize();
	for (int i = count - 1; i >= 0; i--)
	{
		if (t[i].getDay() >= m && t[i].getDay()<=n)
			repo.delItem(t[i]);
	}
}

void Service::delTransactionsByType(short type)
{
	Transaction* t = repo.getAll();
	int count = repo.getSize();
	for (int i = count - 1; i >= 0; i--)
	{
		if (t[i].getType() == type)
			repo.delItem(t[i]);
	}
}

void Service::updateSumByDayAndType(unsigned short day, short type, unsigned int sum)
{
	Transaction* t = repo.getAll();
	int count = repo.getSize();
	for (int i = count - 1; i >= 0; i--)
	{
		if (t[i].getDay() == day && t[i].getType() == type)
			repo.updateItem(t[i].getId(), day, sum, type, t[i].getDesc());
	}
}

Transaction* Service::getTransactionsByType(short type)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type)
			counter++;
	if (counter < 1)
		return nullptr;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type)
			t[new_counter++] = repo.getItemFromPos(i);
	return t;
}

Transaction* Service::getTransactionsWithSumGreaterThan(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() > sum)
			counter++;
	if (counter < 1)
		return nullptr;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() > sum)
			t[new_counter++] = repo.getItemFromPos(i);
	return t;
}

Transaction* Service::getTransactionsWithSumEqualTo(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() == sum)
			counter++;
	if (counter < 1)
		return nullptr;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == sum)
			t[new_counter++] = repo.getItemFromPos(i);
	return t;
}

Transaction* Service::getTransactionsWithSumSmallerThan(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() < sum)
			counter++;
	if (counter < 1)
		return nullptr;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() < sum)
			t[new_counter++] = repo.getItemFromPos(i);
	return t;
}

Transaction* Service::getTransactionsByDayAndType(unsigned short day, short type)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getDay() == day && repo.getItemFromPos(i).getType() == type)
			counter++;
	if (counter < 1)
		return nullptr;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getDay() == day && repo.getItemFromPos(i).getType() == type)
			t[new_counter++] = repo.getItemFromPos(i);
	return t;
}

int Service::getTransactionsByTypeCount(short type)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type)
			counter++;
	return counter;
}

int Service::getTransactionsWithSumGreaterThanCount(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() > sum)
			counter++;
	return counter;
}

int Service::getTransactionsWithSumSmallerThanCount(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() < sum)
			counter++;
	return counter;
}

int Service::getTransactionsWithSumEqualToCount(unsigned int sum)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getSum() == sum)
			counter++;
	return counter;
}

int Service::getTransactionsByDayAndTypeCount(unsigned short day, short type)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getDay() == day && repo.getItemFromPos(i).getType() == type)
			counter++;
	return counter;
}

int* Service::getInOutByDay(unsigned short day)
{
	int sums[2];
	sums[0] = 0;
	sums[1] = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getDay() == day)
			sums[repo.getItemFromPos(i).getType() - 1] += repo.getItemFromPos(i).getSum();
	return sums;
}

int Service::getSumByType(short type)
{
	int sum = 0;
	int sizeOfRepo = this->repo.getSize();
	Transaction* t = this->repo.getAll();
	for (int i = 0; i < sizeOfRepo; i++)
	{
		if (t[i].getType() == type)
			sum += t[i].getSum();
	}
	return sum;
}

int Service::getMaxSumByDayAndType(unsigned short day, short type)
{
	int max_index = -1, max_value = 0;
	Transaction* t = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (t[i].getType() == type && t[i].getDay() == day)
			if (t[i].getSum() > max_value)
			{
				max_value = t[i].getSum();
				max_index = i;
			}
	}
	return max_index;
}

void Service::filterByType(short type)
{
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type)
			counter++;
	if (counter < 1)
		return;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type)
			t[new_counter++] = repo.getItemFromPos(i);
	this->repo.transactions = t;
	this->repo.transactions_count = counter;
}

void Service::filterByTypeAndSumSmallerThan(short type, unsigned int sum) {
	int counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type && repo.getItemFromPos(i).getSum()<sum)
			counter++;
	if (counter < 1)
		return;
	Transaction* t = new Transaction[counter];
	int new_counter = 0;
	for (int i = 0; i < repo.getSize(); i++)
		if (repo.getItemFromPos(i).getType() == type && repo.getItemFromPos(i).getSum()<sum)
			t[new_counter++] = repo.getItemFromPos(i);
	this->repo.transactions = t;
	this->repo.transactions_count = counter;
}