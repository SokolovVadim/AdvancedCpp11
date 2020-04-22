#include <iostream>


int main()
{
	// --------------------------------------------------------------------
	// const int i = 9;
	// i = 6
/*	const int *ptr = &i; // data is const, ptr is not
	ptr++;

	int data = 1;
	int * const ptr2 = &data; // ptr is const, data is not
	// *ptr2 = 2;

	const int* const ptr3 = &data; // ptr and data are both const

	int const * ptr4 = &i;
	const int * ptr5 = &i;*/

	// if const is on the left of star, data is const
	// if const is on the right of star, ptr is const

	// --------------------------------------------------------------------

	const int i = 10;
	int q = const_cast<int&>(i) = 6;
	std::cout << q;
	int j(0);
	/// static_cast<const int&>(j) = 10; // doesn't compile


	return 0;
}