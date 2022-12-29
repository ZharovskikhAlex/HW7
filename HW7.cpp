#include "IntegerArray.h"
#include <iostream>
#include <string>

using namespace std;

void test();
void print(IntegerArray& ia);

int main()
{
	test();

	return 0;
}

void test()
{
	//Test #1: Negative array
	{
		cout << "Test #1: Negative array" << endl;
		try
		{
			IntegerArray arr(-2);
			arr[4];
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Length value: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what();
		}
		cout << "Test#1:End" << endl << endl;
	}

	//Test #2:Out fo range
	{
		cout << "Test#2:Out fo range" << endl;
		try
		{
			IntegerArray arr(2);
			arr[4];
			arr[0] = 3;
			arr[1] = -8;
			cout << "Arr {" << arr[0] << " , " << arr[1] << "}";
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#2.End" << endl << endl;
	}

	//Test #3: Simple
	{
		cout << "Test#3:Simple test" << endl;
		try
		{
			IntegerArray arr(2);
			arr[0] = 3;
			arr[1] = -8;
			cout << "IntegerArray {" << arr[0] << ", " << arr[1] << "}" << endl;
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#3.End" << endl << endl;
	}

	//Test #4: =, insertBeforeFirst, insertAfterLast, Search
	{
		cout << "Test#4: = , insertBeforeFirst, insertAfterLast, Search" << endl;
		try
		{
			IntegerArray arr(3);

			arr[0] = 3;
			arr[1] = 4;
			arr[2] = -8;

			cout << "arr1 = ";
			print(arr);

			cout << "Try copy" << endl;
			IntegerArray arr2;
			arr2 = arr;
			cout << "arr2 = ";
			print(arr2);

			cout << "Try insert before first (arr1)" << endl;
			arr.insertBeforeFirst(10);
			cout << "arr1 = ";
			print(arr);

			cout << "Try insert after last (arr2)" << endl;
			arr2.insertAfterLast(100);
			cout << "arr2 = ";
			print(arr2);

			cout << "Try get index of number \"-8\" in arr1" << endl;
			int index = arr.search(-8);
			cout << "Index of number \"-8\": "
				<< ((index == -1) ? "Number not found" : to_string(index)) << endl;

			cout << "Try get index of number \"43\" in arr2" << endl;
			index = arr2.search(43);
			cout << "Index of number \"43\": "
				<< ((index == -1) ? "Number not found" : to_string(index)) << endl;
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#4.End" << endl << endl;
	}

	//Test #5: insertBeforeFirst into empty array
	{
		cout << "Test#5:insertBeforeFirst \"3\" into empty array" << endl;
		try
		{
			IntegerArray arr;

			arr.insertBeforeFirst(3);
			print(arr);
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#5.End" << endl << endl;
	}

	//Test #6: Test#6:insertAfterLast into empty array
	{
		cout << "Test#6:insertAfterLast \"6\" into empty array" << endl;
		try
		{
			IntegerArray arr;

			arr.insertAfterLast(6);
			print(arr);
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#6.End" << endl << endl;
	}

	//Test #7: copy(IntegerArray)
	{
		cout << "Test#7: Copy" << endl;
		{
			try
			{
				IntegerArray arr(3);

				arr[0] = 3;
				arr[1] = 4;
				arr[2] = -8;

				cout << "arr1 = ";
				print(arr);

				cout << "Try copy" << endl;
				IntegerArray arr2;
				arr2.copy(arr);
				cout << "arr2 = ";
				print(arr2);
			}
			catch (bad_range& br)
			{
				cout << br.what() << endl
					<< "Range: [0.." << br.getLength() - 1 << "]" << endl
					<< "Index: " << br.getIndex() << endl;
			}
			catch (bad_length& bl)
			{
				cout << bl.what() << endl
					<< "Value of length: " << bl.getLength() << endl;
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
		}
		cout << "Test#7:End" << endl << endl;
	}

	//Test #8: Search (-1)
	{
		cout << "Test#8: = Search index of element \"-1\"" << endl;
		try
		{
			IntegerArray arr(3);

			arr[0] = 3;
			arr[1] = 4;
			arr[2] = -8;

			cout << "arr1 = ";
			print(arr);

			cout << "Try get index of number \"-1\" in arr1" << endl;
			int index = arr.search(-1);
			cout << "Index of number \"-1\": "
				<< ((index == -1) ? "Number \"-1\" not found" : to_string(index)) << endl;
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#8.End" << endl << endl;
	}

	//Test #9: resize, insertBeforeFirst, insertAfterLast, Search
	{
		cout << "Test#9: = resize, insertBeforeFirst, insertAfterLast, Search" << endl;
		try
		{
			IntegerArray arr(3);

			arr[0] = 3;
			arr[1] = 4;
			arr[2] = -8;

			cout << "arr1 = ";
			print(arr);

			arr.resize(1);
			cout << "After resize (1) arr1 = ";
			print(arr);

			cout << "Try insert before first" << endl;
			arr.insertBeforeFirst(10);
			cout << "arr1 = ";
			print(arr);

			cout << "Try insert after last" << endl;
			arr.insertAfterLast(100);
			cout << "arr2 = ";
			print(arr);

			cout << "Try get index of number \"-8\" in arr1" << endl;
			int index = arr.search(-8);
			cout << "Index of number \"-8\": "
				<< ((index == -1) ? "Number not found" : to_string(index)) << endl;

			cout << "Try get index of number \"-1\" in arr" << endl;
			index = arr.search(-1);
			cout << "Index of number \"-1\": "
				<< ((index == -1) ? "Number not found" : to_string(index)) << endl;
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#9.End" << endl << endl;
	}
}

void print(IntegerArray& ia)
{
	cout << "{ ";
	for (int i = 0; i < ia.getLength() - 1; ++i)
	{
		cout << ia[i] << ", ";
	}
	cout << ia[ia.getLength() - 1] << " }" << endl;
}