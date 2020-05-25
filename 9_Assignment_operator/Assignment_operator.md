# Assignment operator

## Self assignment

```
dog dd;
dd = dd; // looks silly
dogs[i] = dogs[j]; // looks less silly
```
## Regular assignment

```
class Collar
{
	std::string name;
};

class Dog
{
	Collar* pcollar;
public:
	Dog()
	{
		pcollar = new Collar;
	}
	Dog& operator=(const Dog& rhs)
	{
		delete pcollar;
		pcollar = new Collar(*rhs.pcollar);
		return * this;
	}
};

// --------------------------------------------------------------------

int main()
{
	Dog Ruby;
	Dog Lord;
	Ruby = Lord;
	return 0;
}
```

The problem occurs on delete operator when during a self assignment
Solution:

```
	Dog& operator=(const Dog& rhs)
	{
		if(this == &rhs)
			return *this;
		delete pcollar;
		pcollar = new Collar(*rhs.pcollar);
		return * this;
	}
```

There is still a problem: copy constructor can throw an exception  
So `pcollar` may be deleted twice. 
## Solution 1
is in reordering
and making a copy of pcolor:

```
	Dog& operator=(const Dog& rhs)
	{
		if(this == &rhs)
			return *this;
		Collar* originalPcollar = pcollar;
		pcollar = new Collar(*rhs.pcollar);
		delete originalPcollar;
		return * this;
	}
```

## Solution 2: delegating
Member by member copying

```
	Dog& operator=(const Dog& rhs)
	{
		*pcollar = * rhs.pcollar;
		return * this;
	}
```
