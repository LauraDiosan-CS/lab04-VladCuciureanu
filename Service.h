#pragma once
#include "Repo.h"
class Service
{
private:
	Repo repo;
public:
	/*
	Blank constructor
	*/
	Service();
	/*
	Constructor
	*/
	Service(const Repo &repo);
	/*
	Deconstructor
	*/
	~Service();
	/*
	Method to add transaction
	In: day
	In: sum
	In: type
	In: desc
	*/
	void addTransaction(unsigned short day, unsigned int sum, short type, const char* desc);
	/*
	Method to delete transaction by id
	In: id
	*/
	void delTransaction(int id);
	/*
	Method to update transaction by id.
	In: id
	In: day
	In: sum
	In: type
	In: desc
	*/
	void updateTransaction(int id, unsigned short new_day, unsigned int new_sum, short new_type, const char* new_desc);
	/*
	Method to get all transactions
	Out: array of transactions
	*/
	Transaction* getTransactions();
	/*
	Method to get count of items in repo
	Out: count of items.
	*/
	int getSize();
	/*
	Method to get transaction at index
	In: index
	Out: transaction
	*/
	Transaction getTransactionFromPos(int pos);
	/*
	Find transaction with given values
	In: day
	In: sum
	In: type
	In: desc
	Out: index
	*/
	int findTransaction(unsigned short day, unsigned int sum, short type, const char* desc);
	/*
	Delete transactions with given day
	in: day
	*/
	void delTransactionsByDay(unsigned short day);
	/*
	Delete transactions in interval [m, m+n]
	In: m
	In: n
	*/
	void delTransactionsInInterval(int m, int n);
	/*
	Delete transactions of given type
	In: type
	*/
	void delTransactionsByType(short type);
	/*
	Update sum of items with given day and type
	In: day
	In: type
	In: sum
	*/
	void updateSumByDayAndType(unsigned short day, short type, unsigned int sum);
	Transaction* getTransactionsByType(short type);
	Transaction* getTransactionsWithSumGreaterThan(unsigned int sum);
	Transaction* getTransactionsWithSumEqualTo(unsigned int sum);
	Transaction* getTransactionsByDayAndType(unsigned short day, short type);
	int getTransactionsByTypeCount(short type);
	int getTransactionsWithSumGreaterThanCount(unsigned int sum);
	int getTransactionsWithSumEqualToCount(unsigned int sum);
	int getTransactionsByDayAndTypeCount(unsigned short day, short type);
	int* getInOutByDay(unsigned short day);
	int getSumByType(short type);
	int getMaxSumByDayAndType(unsigned short day, short type);
	void filterByType(short type);
	void filterByTypeAndSumSmallerThan(short type, unsigned int sum);
};

