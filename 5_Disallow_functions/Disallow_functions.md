# Disallow functions

## Specialize constructor with parameter

Openning file requires filename

```
class OpenFile
{
public:
	OpenFile(std::string filename)
	{
		std::cout << "Open a file " << filename << std::endl;
	}
};

// --------------------------------------------------------------------

int main()
{
	OpenFile f();
	return 0;
}
```

That will cause a compilation error and default constructor is not generated. User has to use the following

`OpenFile f(std::string("Vadim_file"));`

## Dangerous use of copy constructor

```
int main()
{
	OpenFile f(std::string("Vadim_file"));
	OpenFile f1(f);
}
```

This will allow two writings into one file.

## Solutions

#### Delete (C++11)

To disallow copy constructor it is necessary to delete it

`OpenFile(OpenFile& rhs) = delete;`

#### Make private

```
class OpenFile
{
public:
	OpenFile(std::string filename)
	{
		std::cout << "Open a file " << filename << std::endl;
	}
private:
	OpenFile(OpenFile& rhs);
};
```

## Private Destructor

In shared pointers it's useful to use private destructor. But this code won't compile:

```
private:
	~OpenFile() { std::cout << "File destructed!" << std::endl; };
```

The solution is to use public interface

```
public:
	OpenFile(std::string filename)
	{
		std::cout << "Open a file " << filename << std::endl;
	}
	void destroyMe() { delete this; }
private:
	~OpenFile() { std::cout << "File destructed!" << std::endl; };
```

The problem still exists because `file` is stored on the `stack`

```
	OpenFile f(std::string("Vadim_file"));
	f.destroyMe();
```

So we are to use a heap allocation

```
	OpenFile* f = new OpenFile(std::string("Vadim_file"));
	f->destroyMe();
```

It's also may be useful in embedded system programming
