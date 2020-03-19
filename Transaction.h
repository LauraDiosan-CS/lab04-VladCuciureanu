#pragma once
#include <string>
class Transaction
{
private:
	unsigned short day;
	unsigned int sum;
	short type;
	char* desc;
public:
	// Constructors and Deconstructor
	Transaction();
	Transaction(unsigned short day, unsigned int sum, short type, const char* desc);
	Transaction(const Transaction& s);
	~Transaction();
	// Getters
	unsigned short getDay();
	unsigned int getSum();
	short getType();
	const char* getDesc();
	// Setters
	void setDay(unsigned short day);
	void setSum(unsigned int sum);
	void setType(short type);
	void setDesc(const char* desc);
	// Operators
	Transaction& operator=(const Transaction& s);
	bool operator==(const Transaction& s);
	// Utils
	char* toString();
};

