# Struct vs class

## Struct and class

```
// Small passive objects that carry public date and have no or few basic member functions 
// Data container
struct Person_t
{
	std::string name; // public
	unsigned age;
}

// Bigger active objects that carry private data, interfacced through public member functions
// Complex data structure
class Person
{
	std::string name_; // private
	unsigned age_; // m_age, _age
}
```

## Object-oriented programming

```
class Person
{
	std::string name_; // private
	unsigned age_;
public:
	unsigned age() const { return age_; }      // getter or accessor
	void set_age(unsigned age) { age_ = age; } // settor or mutator
};
```

## Too many setter or getter functions indicate problems in design
