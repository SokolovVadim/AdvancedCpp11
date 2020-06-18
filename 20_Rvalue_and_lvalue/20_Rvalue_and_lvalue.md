# Rvalue and Lvalue

## Definition

lvalue - An object that occupies some identifiable location in memory

rvalue - Any objects that is not a lvalue

## Examples 

```
int i;
int x = 2;
int x = i + 2;
int* p = &(i + 2); // error
i + 2 = 4; // error
2 = i; // error

class Dog;

Dog dog;
dog = Dog();

int sum(int x, int y)
{
	return x + y;
}

int i = sum(3, 4);

Rvalues: 2, i + 2, Dog(), sum(3, 4), x + y
Lvalues: x, i, dog
```

## Reference

```
int i;
int& r = i;
int& r = 5;; // error
```

Exception:

`const int& r = 5;`

```
int square(int& x)
{
	return x * x;
}

square(i);  // OK
square(40); // Error
```
Workaround:
```
int square(const int& x)
{
	return x * x;
}
```

`square(40)` and `square(i)` work!

## Creating references

Lvalue can be used to create an rvalue

```
int i = 1;
int x = i + 2;
int x = i;
```

Rvalue can be used to create an lvalue

```
int v[3];
*(v + 2) = 4;
```

## Misconception 1:

Functions or operators always yelds rvalues

```
int x = i + 2;
int y = sum(3, 4);

// Counterexample

int myglobal;
int& foo()
{
	return myglobal;
}

foo() = 50; // it works!

// A more common examle:
array[3] = 50;
```

## Misconception 2:

Lvalues are modifiable

C language: lvalue means "value suitable for left-hand-side of assignment"

```
const int c = 1; // c is a lvalue
c = 2; // Error, c is not modifiable
```

## Misconception 2:

Rvalues are not modifiable

```
i + 3 = 6;     // Error
sum(3, 4) = 7; // Error
```

Counterexample:

It is not true for user defined type (class)

```
class Dog;
Dog().bark(); // it may change the state of the Dog object
```

## Summary

1. Every C++ expression yield either an rvalue or a lvalue.
2. If the expression has an identifiable memory address, it's lvalue; otherwise, rvalue.
