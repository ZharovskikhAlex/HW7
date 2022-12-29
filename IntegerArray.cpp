#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : _length(length)
{
	if (length < 0)
	{
		throw bad_length("Error: Length of array is less than zero.", length);
	}

	_data = new int[length];
	for (size_t i = 0; i < length; ++i)
	{
		_data[i] = 0;
	}
}

IntegerArray::IntegerArray(const IntegerArray& integerArray)
{
	_length = integerArray._length;

	_data = new int[_length] {};

	for (size_t i = 0; i < _length; ++i)
	{
		_data[i] = integerArray._data[i];
	}
}

IntegerArray::~IntegerArray()
{
	delete[] _data;
}

int IntegerArray::getLength() const noexcept
{
	return _length;
}

void IntegerArray::erase() noexcept
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}

void IntegerArray::reallocate(int newLength)
{
	if (newLength < 0)
	{
		throw bad_length("Error: Length of array is less than zero.", newLength);
	}

	erase();

	_length = newLength;
	_data = new int[_length];
}

void IntegerArray::resize(int newLength)
{
	if (newLength == _length)
	{
		return;
	}
	else if (newLength == 0)
	{
		erase();
		return;
	}
	else if (newLength < 0)
	{
		throw bad_length("Error: Length of array is less than zero.", newLength);
	}
	else if (newLength < _length)
	{
		_length = newLength;
		return;
	}

	int* data = new int[newLength];

	if (_length > 0)
	{
		int elementsToCopy = { newLength > _length ? _length : newLength };

		for (size_t i = 0; i < elementsToCopy; ++i)
		{
			data[i] = _data[i];
		}
	}

	delete[] _data;

	_data = data;
	_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0 || index >= _length)
	{
		throw bad_range("Error: Index out of range", _length, index);
	}

	int* data = new int[_length + 1];

	for (size_t beforeIndex = 0; beforeIndex < index; ++beforeIndex)
	{
		data[beforeIndex] = _data[beforeIndex];
	}
	data[index] = value;
	for (size_t afterIndex = index; afterIndex < _length; ++afterIndex)
	{
		data[afterIndex + 1] = _data[afterIndex];
	}

	delete[] _data;
	_data = data;
	++_length;
}

void IntegerArray::insertBeforeFirst(int value) noexcept
{
	int* data = new int[_length + 1];

	data[0] = value;
	for (size_t i = 0; i < _length; ++i)
	{
		data[i + 1] = _data[i];
	}

	delete[] _data;
	_data = data;
	++_length;
}

void IntegerArray::insertAfterLast(int value) noexcept
{
	int* data = new int[_length + 1];

	for (size_t i = 0; i < _length; ++i)
	{
		data[i] = _data[i];
	}
	data[_length] = value;

	delete[] _data;
	_data = data;
	++_length;
}

void IntegerArray::remove(int index)
{
	if (index < 0 || index >= _length)
	{
		throw bad_range("Error: Index out of range", _length, index);
	}

	if (_length == 1)
	{
		erase();
		return;
	}

	int* data = new int[_length - 1];

	for (size_t beforeIndex = 0; beforeIndex < index; ++beforeIndex)
	{
		data[beforeIndex] = _data[beforeIndex];
	}
	for (size_t afterIndex = index + 1; afterIndex < _length; ++afterIndex)
	{
		data[afterIndex - 1] = _data[afterIndex];
	}

	delete[] _data;
	_data = data;
	--_length;
}

void IntegerArray::copy(const IntegerArray& integerArray)
{
	erase();

	_length = integerArray._length;

	try
	{
		_data = new int[_length];
	}
	catch (std::bad_alloc& ba)
	{
		throw ba;
	}

	for (size_t i = 0; i < _length; ++i)
	{
		_data[i] = integerArray._data[i];
	}
}

const int IntegerArray::search(int value) noexcept
{
	for (size_t i = 0; i < _length; ++i)
	{
		if (_data[i] == value)
		{
			return i;
		}
	}

	return -1;// value - not found
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= _length)
	{
		throw bad_range("Error: Index out of range", _length, index);
	}
	return _data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& integerArray)
{
	_length = integerArray._length;

	_data = new int[_length] {};

	for (size_t i = 0; i < _length; ++i)
	{
		_data[i] = integerArray._data[i];
	}

	return *this;
}

bad_range::bad_range(const char* msg, int length, int index) :
	exception(msg), _length(length), _index(index)
{
}

int bad_range::getLength() const noexcept
{
	return _length;
}

int bad_range::getIndex() const noexcept
{
	return _index;
}

bad_length::bad_length(const char* msg, int length) :
	exception(msg), _length(length)
{
}

int bad_length::getLength() const noexcept
{
	return _length;
}