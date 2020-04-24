# Logic and bitwise constness

## Conflict in logic and bitwise constness

It is logically clear to programmer that `getItem()` is supposed to be const function.

However compiler disagrees.

```
class BigArray{
	std::vector<int> v; // huge array
	int accessCounter;
public:
	int getItem(int index) const{
		accessCounter++;
		return v[index];
	}
};

... 
error: increment of member ‘BigArray::accessCounter’ in read-only object
   accessCounter++;

```

## Solution

### 1) Mutable keyword
```
mutable int accessCounter;
```

### 2) Const cast (should be avoided)

```
	int getItem(int index) const{
		const_cast<BigArray*>(this)->accessCounter++;
		return v[index];
	}
```

## Another conflict

Compiler accepts a const specificator in `setAnotherVItem()`, but logically it is not right.

```
#include <iostream>
#include <vector>

class BigArray{
	std::vector<int> v; // huge array
	int accessCounter;
	int* another_v;
public:
	int getItem(int index) const{
		const_cast<BigArray*>(this)->accessCounter++;
		return v[index];
	}

	void setAnotherVItem(int index, int x) const
	{
		*(another_v + index) = x;
	}
};

// --------------------------------------------------------------------

int main()
{
	BigArray array;

	return 0;
}
```

## Solution

Just remove const in function

```
	void setAnotherVItem(int index, int x)
	{
		*(another_v + index) = x;
	}
```

## FUN

What the heck is this???

`const int* const fun (const int* const & p) const;`

### Explanation

1. the return value of fun is a constant pointer pointing to a constant integer value
2. the parameter of fun is a reference of a constant pointer pointing to a constant integer
the reference cannot refer to a different pointer (nature of references)
the referred pointer cannot point to a different value
the pointed value of the referred pointer cannot be changed
3. fun is also a const function, meaning that it cannot directly modify members unless they are marked mutable, also it can only call other const functions
