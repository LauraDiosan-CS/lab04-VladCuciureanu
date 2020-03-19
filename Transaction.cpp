#include "Transaction.h"
#include <string>
#include <iostream>

Transaction::Transaction()
{
	this->day = 0;
	this->desc = nullptr;
	this->sum = 0;
	this->type = 0;
}

Transaction::Transaction(unsigned short day, unsigned int sum, short type, const char* desc)
{
	this->day = day;
	this->sum = sum;
	this->type = type;
	int desc_size = strlen(desc);
	this->desc = new char[desc_size + 1];
	strcpy_s(this->desc, desc_size + 1, desc);
}

Transaction::Transaction(const Transaction& s)
{
	this->day = s.day;
	this->sum = s.sum;
	this->type = s.type;
	int desc_size = strlen(s.desc);
	this->desc = new char[desc_size + 1];
	strcpy_s(this->desc, desc_size + 1, s.desc);
}

Transaction::~Transaction()
{
	if (this->desc)
	{
		delete[] this->desc;
		this->desc = nullptr;
	}
}

unsigned short Transaction::getDay()
{
	return this->day;
}

unsigned int Transaction::getSum()
{
	return this->sum;
}

short Transaction::getType()
{
	return this->type;
}

const char* Transaction::getDesc()
{
	return this->desc;
}

void Transaction::setDay(unsigned short day)
{
	this->day = day;
}

void Transaction::setSum(unsigned int sum)
{
	this->sum = sum;
}

void Transaction::setType(short type)
{
	this->type = type;
}

void Transaction::setDesc(const char* desc)
{
	if (this->desc)
	{
		delete[] this->desc;
		this->desc = nullptr;
	}
	int desc_size = strlen(desc);
	this->desc = new char[desc_size + 1];
	strcpy_s(this->desc, desc_size + 1, desc);
}

Transaction& Transaction::operator=(const Transaction& s)
{
	if (this->desc)
	{
		delete[] this->desc;
		this->desc = nullptr;
	}
	this->day = s.day;
	this->sum = s.sum;
	this->type = s.type;
	int desc_size = strlen(s.desc);
	this->desc = new char[desc_size + 1];
	strcpy_s(this->desc, desc_size + 1, s.desc);
	return *this;
}

bool Transaction::operator==(const Transaction& s)
{
	if (this->getDay() != s.day)
		return false;
	if (this->getSum() != s.sum)
		return false;
	if (this->getType() != s.type)
		return false;
	if (strcmp(this->getDesc(), s.desc) != 0)
		return false;
	return true;
}

char* Transaction::toString()
{
	char result[256] = "";
	strcat_s(result, 256, "Day: ");
	strcat_s(result, 256, std::to_string(this->day).c_str());
	strcat_s(result, 256, " | Sum: ");
	strcat_s(result, 256, std::to_string(this->sum).c_str());
	strcat_s(result, 256, " | Type: ");
	strcat_s(result, 256, std::to_string(this->type).c_str());
	strcat_s(result, 256, " | Desc: ");
	strcat_s(result, 256, this->getDesc());
	strcat_s(result, 256, "\0");
	char* output = new char[strlen(result) + 1];
	strcpy_s(output, strlen(result) + 1, result);
	return output;
}