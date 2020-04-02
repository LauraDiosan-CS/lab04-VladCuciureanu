#include <iostream>
#include "Test.h"
#include "Transaction.h"
#include "Repo.h"
#include "Service.h"
#include "UserInterface.h"

using namespace std;

/*
Handles inputting a transaction.
In: Reference to repo object.
*/
void handleTransactionInput(Service& service)
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
		service.addTransaction(day, sum, type, desc);
	}
	catch(exception e)
	{
		std::cout << "An error occured. Try again.";
	}
}

/*
Driver code
*/
int main()
{
	// Run tests
	runTransactionTests();
	runRepoTests();

	// Initializing necessary objects
	Repo mainRepo = Repo();
	Service mainService = Service(mainRepo);
	UserInterface userInterface = UserInterface(mainService);

	userInterface.init();

	/*
	Transaction* transactions = mainRepo.getAll();
	Transaction* t;
	bool trigger = false;
	int* results;
	int day, sum, type, index, counter;
	
	UI Loop
	
	while (!trigger)
	{
		showMenuOptions();
		char choice;
		std::cout << "Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case '1':
			handleTransactionInput(mainService);
			break;
		case '2':
			std::cout << "Transactions: \n";
			transactions = mainService.getTransactions();
			for (int x = 0; x < mainService.getSize(); x++)
			{
				std::cout << x+1 << ": " << transactions[x].toString() << '\n';
			}
			break;
		case '3':
			std::cout << "Day: ";
			std::cin >> day;
			mainService.delTransactionsByDay(day);
			break;
		case '4':
			int m, n;
			std::cout << "Start: ";
			std::cin >> m;
			std::cout << "Days: ";
			std::cin >> n;
			mainService.delTransactionsInInterval(m, m + n);
			break;
		case '5':
			std::cout << "Type: ";
			std::cin >> type;
			mainService.delTransactionsByType(type);
			break;
		case '6':
			std::cout << "Sum: ";
			std::cin >> sum;
			std::cout << "Day: ";
			std::cin >> day;
			std::cout << "Type: ";
			std::cin >> type;
			mainService.updateSumByDayAndType(day, type, sum);
			break;
		case '7':
			std::cout << "Type: ";
			std::cin >> type;
			t = mainService.getTransactionsByType(type);
			counter = mainService.getTransactionsByTypeCount(type);
			for (int i = 0; i < counter; i++)
				std::cout << t[i].toString() << std::endl;
			break;
		case '8':
			std::cout << "Sum: ";
			std::cin >> sum;
			t = mainService.getTransactionsWithSumGreaterThan(sum);
			counter = mainService.getTransactionsWithSumGreaterThanCount(sum);
			for (int i = 0; i < counter; i++)
				std::cout << t[i].toString() << std::endl;
			break;
		case '9':
			std::cout << "Sum: ";
			std::cin >> sum;
			t = mainService.getTransactionsWithSumEqualTo(sum);
			counter = mainService.getTransactionsWithSumEqualToCount(sum);
			for (int i = 0; i < counter; i++)
				std::cout << t[i].toString() << std::endl;
			break;
		case 'a':
			std::cout << "Day: ";
			std::cin >> day;
			results = mainService.getInOutByDay(day);
			std::cout << "In: " << results[0] << " | Out: " << results[1] << std::endl;
			break;
		case 'b':
			std::cout << "Type: ";
			std::cin >> type;
			std::cout << mainService.getSumByType(type);
			break;
		case 'c':
			std::cout << "Day: ";
			std::cin >> day;
			std::cout << "Type: ";
			std::cin >> type;
			index = mainService.getMaxSumByDayAndType(day, type);
			if(index!=-1)
			std::cout << mainService.getTransactionFromPos(index).toString();
			break;
		case 'd':
			std::cout << "Type: ";
			std::cin >> type;
			mainService.filterByType(type);
			break;
		case 'e':
			std::cout << "Type: ";
			std::cin >> type;
			std::cout << "Sum: ";
			std::cin >> sum;
			mainService.filterByTypeAndSumSmallerThan(type, sum);
			break;
		case '0':
			trigger = true;
			break;
		default:
			std::cout << "Please input a valid option.\n";
			break;
		}
		std::cout << "\n\n";
	}*/
	return 0;
}