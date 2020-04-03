#include "Test.h"
#include "Transaction.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>

void runTransactionTests()
{
	Transaction t1 = Transaction();
	assert(t1.getId() == 0);
	assert(t1.getDay() == 0);
	assert(t1.getSum() == 0);
	assert(t1.getType() == 0);
	assert(t1.getDesc() == nullptr);
	t1 = Transaction(1, 3, 2, 1, "Test");
	assert(t1.getId() == 1);
	assert(t1.getDay() == 3);
	assert(strcmp(t1.getDesc(), "Test")==0);
	assert(t1.getSum() == 2);
	assert(t1.getType() == 1);
	t1.setDay(6);
	t1.setSum(4);
	t1.setType(2);
	t1.setDesc("Fest");
	assert(t1.getDay() == 6);
	assert(strcmp(t1.getDesc(), "Fest") == 0);
	assert(t1.getSum() == 4);
	assert(t1.getType() == 2);
}

void runRepoTests()
{
	Repo r = Repo();
	assert(r.getSize() == 0);
	Transaction t = Transaction(r.getNextId(), 3, 2, 1, "Test");
	r.addItem(t);
	assert(r.getSize() == 1);
	assert(r.getAll()[0] == t);
	t = Transaction(r.getNextId(), 3, 2, 1, "Test");
	r.addItem(t);
	assert(r.getSize() == 2);
	t = Transaction(r.getNextId(), 6, 4, 2, "fest");
	r.addItem(t);
	int index = r.findItem(t);
	assert(index != -1);
	t.setDay(8);
	index = r.findItem(t);
	assert(index == -1);
	t = Transaction(2, 3, 2, 1, "Test");
	assert(r.getItemFromPos(1) == t);
	assert(r.getSize() == 3);
	r.delItem(t);
	assert(r.getSize() == 2);
	r.updateItem(2, 10, 11, 2, "Fest");
	t = r.getItemFromPos(0);
	Transaction* allTrans = r.getAll();
	std::cout << t.getDay();
	assert(t.getDay() == 3);
	assert(t.getSum() == 2);
	assert(t.getType() == 1);
	assert(strcmp(t.getDesc(), "Test")==0);
}