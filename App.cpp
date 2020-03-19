#include <iostream>
#include "Test.h"
#include "Transaction.h"
#include "Repo.h"

using namespace std;

void showMenuOptions()
{
	std::cout << "Options: \n 1. Add Transaction\n 2. Show Transactions\n 0. Exit\n";
}

void handleTransactionInput(Repo& repo)
{
	try
	{
		unsigned short day;
		unsigned int sum;
		short type;
		char desc[256];
		std::cout << "Day: ";
		std::cin >> day;
		std::cout << "Sum: ";
		std::cin >> sum;
		std::cout << "Type: ";
		std::cin >> type;
		std::cout << "Desc: ";
		std::cin >> desc;
		Transaction t = Transaction(day, sum, type, desc);
		repo.addItem(t);
	}
	catch(exception e)
	{
		std::cout << "An error occured. Try again.";
	}
}

int main()
{
	runTransactionTests();
	runRepoTests();

	Repo mainRepo = Repo();
	Transaction* transactions = mainRepo.getAll();
	bool trigger = false;
	while (!trigger)
	{
		showMenuOptions();
		char choice;
		std::cout << "Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case '1':
			handleTransactionInput(mainRepo);
			break;
		case '2':
			std::cout << "Transactions: \n";
			transactions = mainRepo.getAll();
			for (int x = 0; x < mainRepo.getSize(); x++)
			{
				std::cout << x+1 << ": " << transactions[x].toString() << '\n';
			}
			break;
		case '0':
			trigger = true;
			break;
		default:
			std::cout << "Please input a valid option.\n";
			break;
		}
		std::cout << "\n\n";
	}
	return 0;
}