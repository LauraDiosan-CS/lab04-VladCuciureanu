#include "UserInterface.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <time.h>

UserInterface::UserInterface(const Service& service)
{
	this->service = service;
}

UserInterface::~UserInterface(){}

template <typename Out>
void split(const std::string& s, char delim, Out result) {
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

void showMenuOptions()
{
	std::cout << "ex. adauga 100 out pizza - este adaugata o tranzacie de tip out în valoarea de 100 RON pentru ziua curenta cu descrierea 'pizza'  \nex. insereaza 25 100 in salar - insereaza o tranzactie de tip in pentru ziua 25 în valaorea de 100 RON cu descrierea salar \nex. eliminare 15 - se elimina toate tranzactiile din ziua 15 \nex. eliminare 5 la 10 - se elimina toate tranzactiile din ziua 10 pâna în ziua 15 \nex. eliminare in - se elimina toate tranzactiile de tip in din luna curenta \nex. inlocuire 12 in salar cu 2000 - se inlocuieste suma vechea tranzactiei de tip in din ziua 12 cu descrierea 'salar' cu suma 2000 \nex. listeaza - afiseaza toate tranzactiile din lista \nex. listeaza in - afiseaza toate tranzactiile de tip in din lista \nex. listeaza > 100 - afiseaza toate tranzactiile din lista cu suma mai mare decât 100 \nex. listeaza = 60 - afiseaza toate tranzactiile din lista cu suma egala cu 60 \nex. listeaza sol 10 - afiseaza sold-ul tranzactiilor din ziua 10 (diferenta între suma tranzactiilor de tip in si suma tranzactiilor de tip out) \nex. sum in - afiseaza suma totala a tranzactiilor de tip in \nex. max out 15 - afiseaza cea mai valoroasa tranzactie de tip out din ziua 15 \nex. filtru in - se pastreaza doar tranzactiile de tip in \nex. filtru in 100 - se pastreaza doar tranzactiile de tip in cu valoare mai mica decat 100 \nex undo  -  reface  ultima  operatie.\n";
}

void UserInterface::init()
{
	while (!this->exitTrigger)
	{
		std::cout << std::endl;
		showMenuOptions();
		std::cout << std::endl;
		std::string userInput;
		std::getline(std::cin, userInput);
		parseUserInput(userInput);
		
	}
}

void UserInterface::parseUserInput(std::string input)
{
	// Placeholder pointers
	Transaction* phTrans;

	// Splitting string into words
	std::vector<std::string> words;
	split(input, ' ', std::back_inserter(words));
	if (words[0] == "adauga" && words.size()==4)
	{
		int val_add = std::stoi(words[1]);

		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		int day_add = newtime.tm_mday;
		this->service.addTransaction(day_add, val_add, words[2] == "in" ? 1 : 2, words[3].c_str());
	}
	if (words[0] == "insereaza")
	{
		int val_add = std::stoi(words[2]);

		this->service.addTransaction(stoi(words[1]), val_add, words[3] == "in" ? 1 : 2, words[4].c_str());
	}
	if (words[0] == "eliminare")
	{
		if (words.size() == 2)
		{
			if (words[1] == "in" || words[1] == "out")
			{
				this->service.delTransactionsByType(words[1] == "in" ? 1 : 2);
			}
			else
			{
				this->service.delTransactionsByDay(stoi(words[1]));
			}
		}
		else
		{
			this->service.delTransactionsInInterval(stoi(words[1]), stoi(words[3]));
		}
	}
	if (words[0] == "inlocuire")
	{
		int type_replace = words[3] == "in" ? 1 : 2;
		int new_replace_sum = stoi(words[5]);
		int replace_day = stoi(words[1]);
		this->service.updateSumByDayAndType(replace_day, type_replace, new_replace_sum);
	}
	if (words[0] == "listeaza")
	{
		switch (words.size())
		{
		case 1:
			phTrans = this->service.getTransactions();
			for (int i = 0; i < this->service.getSize(); i++)
			{
				std::cout << phTrans[i].toString()<<std::endl;
			}
			break;
		case 2:
			phTrans = this->service.getTransactionsByType(words[1] == "in" ? 1 : 2);
			for (int i = 0; i < this->service.getSize(); i++)
			{
				std::cout << phTrans[i].toString() << std::endl;
			}
			break;
		case 3:
			if (words[2] == ">")
			{
				phTrans = this->service.getTransactionsWithSumGreaterThan(stoi(words[3]));
				for (int i = 0; i < this->service.getTransactionsWithSumGreaterThanCount(stoi(words[3])); i++)
				{
					std::cout << phTrans[i].toString() << std::endl;
				}
			}
			if (words[2] == "=")
			{
				phTrans = this->service.getTransactionsWithSumEqualTo(stoi(words[3]));
				for (int i = 0; i < this->service.getTransactionsWithSumEqualToCount(stoi(words[3])); i++)
				{
					std::cout << phTrans[i].toString() << std::endl;
				}
			}
			if (words[2] == "<")
			{
				phTrans = this->service.getTransactionsWithSumSmallerThan(stoi(words[3]));
				for (int i = 0; i < this->service.getTransactionsWithSumSmallerThanCount(stoi(words[3])); i++)
				{
					std::cout << phTrans[i].toString() << std::endl;
				}
			}
			if (words[2] == "sol")
			{
				int* sums = this->service.getInOutByDay(stoi(words[3]));
				std::cout << "Sold: " << sums[0] - sums[1] << std::endl;
			}
			break;
		}
	}
	if (words[0] == "sum")
	{
		int type_sum = words[1] == "in" ? 1 : 2;
		std::cout << "Sum: " << this->service.getSumByType(type_sum)<<std::endl;
	}
	if (words[0] == "max")
	{
		int type_max = words[1] == "in" ? 1 : 2;
		int max_sum_type_index = this->service.getMaxSumByDayAndType(stoi(words[2]), type_max);
		std::cout << this->service.getTransactionFromPos(max_sum_type_index).toString();
	}
	if (words[0] == "filtru")
	{
		int type_filter = words[1] == "in" ? 1 : 2;
		if (words.size() == 2)
			this->service.filterByType(type_filter);
		else
			this->service.filterByTypeAndSumSmallerThan(type_filter,stoi(words[3]));
	}
	if (words[0] == "undo")
	{
		// insereaza tree
	}
	if (words[0] == "exit")
	{
		this->exitTrigger = 1;
	}
}