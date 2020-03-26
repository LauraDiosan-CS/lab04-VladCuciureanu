#pragma once
#include <string>
class Transaction
{
private:
	unsigned int id;
	unsigned short day;
	unsigned int sum;
	short type;
	char* desc;
public:
	// Constructors and Deconstructor

	/*
	Blank constructor
	*/
	Transaction();

	/*
	Constructor
	In: day - Day of transaction.
	In: sum - Sum of transaction.
	In: type - Type of transaction (1-In, 2-Out).
	In: desc - Description of transaction.
	*/
	Transaction(unsigned int id, unsigned short day, unsigned int sum, short type, const char* desc);

	/*
	Copy constructor
	In: Transaction to be copied
	*/
	Transaction(const Transaction& s);

	/*
	Deconstructor
	*/
	~Transaction();

	// Getters
	/*
	Returns id of transaction
	Out: id of transaction.
	*/
	unsigned int getId();

	/*
	Returns day of transaction
	Out: day of transaction.
	*/
	unsigned short getDay();
	
	/*
	Returns sum of transaction.
	Out: sum of transaction.
	*/
	unsigned int getSum();

	/*
	Returns type of transaction.
	Out: type of transaction.
	*/
	short getType();

	/*
	Returns a char array containing description of transaction.
	Out: description of transaction.
	*/
	const char* getDesc();

	// Setters
	/*
	Sets the day of the transaction to given value.
	In: given value.
	*/
	void setDay(unsigned short day);

	/*
	Sets the sum of the transaction to given value.
	In: given value.
	*/
	void setSum(unsigned int sum);

	/*
	Sets the type of the transaction to given value.
	In: given value.
	*/
	void setType(short type);

	/*
	Sets the description of the transaction to given value.
	In: given 'char' array.
	*/
	void setDesc(const char* desc);

	// Operators
	/*
	Equal operator
	In: Object to be copied.
	*/
	Transaction& operator=(const Transaction& s);
	
	/*
	Equal operator
	In: Object to be compared to current object.
	*/
	bool operator==(const Transaction& s);

	// Utils
	/*
	Returns a formatted string containing human-readable info about current transaction.
	Out: formatted 'char' array.
	*/
	char* toString();
};

