# Const

```
	const int i = 9;
	// i = 6
	const int *ptr = &i; // data is const, ptr is not
	ptr++;

	int data = 1;
	int * const ptr2 = &data; // ptr is const, data is not
	// *ptr2 = 2;

	const int* const ptr3 = &data; // ptr and data are both const

	int const * ptr4 = &i;
	const int * ptr5 = &i;

	// if const is on the left of star, data is const
	// if const is on the right of star, ptr is const
```

## Cast
```
	const int i = 10;
	const_cast<int&>(i) = 6;

	int j(0);
	static_cast<const int&>(j) = 10;
```

Try to avoid cast as much as possible

## Benefits of using `const`

- Guards against inadvertent write to the variable
- Self documenting
- Enables compiler to do more optimization, making code tighter
- Const means the variable can be put in Read only memory (ROM, especially in embedded systems)