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
	In: day
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
	/*
	Get transactions of type
	In: type
	*/
	Transaction* getTransactionsByType(short type);
	/*
	Get transactions with sum greater than given sum
	In: sum
	Out: array of transactions
	*/
	Transaction* getTransactionsWithSumGreaterThan(unsigned int sum);
	/*
	Get transactions with sum equal to given sum
	In: sum
	Out: array of transactions
	*/
	Transaction* getTransactionsWithSumEqualTo(unsigned int sum);
	/*
	Get transactions made in given day and of given type
	In: day
	In: type
	Out: array of transactions
	*/
	Transaction* getTransactionsByDayAndType(unsigned short day, short type);
	/*
	Count method for non-counter method
	*/
	int getTransactionsByTypeCount(short type);
	/*
	Count method for non-counter method
	*/
	int getTransactionsWithSumGreaterThanCount(unsigned int sum);
	/*
	Count method for non-counter method
	*/
	int getTransactionsWithSumEqualToCount(unsigned int sum);
	/*
	Count method for non-counter method
	*/
	int getTransactionsByDayAndTypeCount(unsigned short day, short type);
	/*
	Get total in and out for a given day
	In: day
	Out: [0] - in | [1] - out
	*/
	int* getInOutByDay(unsigned short day);
	/*
	Get sum of all transactions for type
	In: type
	Out: sum
	*/
	int getSumByType(short type);
	/*
	Get max sum of transactions in given day and of given type
	In: type
	Out: max sum
	*/
	int getMaxSumByDayAndType(unsigned short day, short type);
	/*
	Remove records that aren't of given type.
	In: type
	*/
	void filterByType(short type);
	/*
	Remove records that aren't of given type and of given sum.
	In: type
	In: sum
	*/
	void filterByTypeAndSumSmallerThan(short type, unsigned int sum);
};

