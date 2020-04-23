# Const and functions

## Const parameter
```
class Dog
{
	int age;
	std::string name;
public:
	Dog() { age = 3; name = "dummy"; }
	void setAge(const int& a) { age = a; }
};

// --------------------------------------------------------------------

int main()
{
	Dog d;
	int age = 9;
	d.setAge(age);
	std::cout << age << std::endl;
	return 0;
}
```

Can't be overloaded

```
	void setAge(const int a) { age = a; }
	void setAge(const int& a) { age = a; }
```

## Const return value

```
const std::string & getName() { return name; }
...
...
const std::string & name = dog.getName();
```

## Const function

```
void printDogName() const { std::cout << name << std::endl; }
```

## Const overloading

```
	void printDogName() const { std::cout << name << " const" << std::endl; }
	void printDogName() { std::cout << getName() << " non-const" << std::endl; }
	...
	...
	Dog dog;
	dog.printDogName();

	const Dog doggy;
	doggy.printDogName();
```