#pragma once
#include <exception>

class bad_range : public std::exception
{
public:
	bad_range(const char* msg, int length, int index);

	int getLength() const noexcept;
	int getIndex() const noexcept;

protected:
	int _length;
	int _index;
};

class bad_length : public std::exception
{
public:
	bad_length(const char* msg, int length);

	int getLength() const noexcept;

protected:
	int _length;
};

class IntegerArray
{
private:
	int _length = 0;
	int* _data = 0;

public:
	IntegerArray() = default;
	IntegerArray(int length);
	IntegerArray(const IntegerArray& integerArray);
	~IntegerArray();

	int getLength() const noexcept;

	void erase() noexcept;
	void reallocate(int newLength);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void insertBeforeFirst(int value) noexcept;
	void insertAfterLast(int value) noexcept;
	void remove(int index);
	void copy(const IntegerArray& integerArray);
	const int search(int value) noexcept;

	int& operator[](int index);
	IntegerArray& operator=(const IntegerArray& integerArray);
};