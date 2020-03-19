#include "Test.h"
#include "Transaction.h"
#include "Repo.h"
#include <assert.h>

void runTransactionTests()
{
	Transaction t1 = Transaction();
	assert(t1.getDay() == 0);
	assert(t1.getSum() == 0);
	assert(t1.getType() == 0);
	assert(t1.getDesc() == nullptr);
	t1 = Transaction(3, 2, 1, "Test");
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
	Transaction t = Transaction(3, 2, 1, "Test");
	r.addItem(t);
	assert(r.getSize() == 1);
	assert(r.getAll()[0] == t);
	r.addItem(t);
	assert(r.getSize() == 2);
	assert(r.getAll()[0] == r.getAll()[1]);
}