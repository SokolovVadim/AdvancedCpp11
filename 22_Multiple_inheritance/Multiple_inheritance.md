# Multiple inheritance

## Inheritance problem

```
class InputFile
{
public:
	void read();
	void open();
};

class OutputFile
{
public:
	void write();
	void open();
};

class IOFile: public InputFile, public OutputFile
{};

int main()
{
	IOFile file;
	file.open();
}
```

Here `file.open()` will cause an error.

Solution:

```
int main()
{
	IOFile file;
	file.OutputFile::open();
}
```

## Diamond shape of hierarchy

```
class File
{
public:
	std::string name;
	void open();
};

class InputFile: public File
{};

class OutputFile: public File
{};

class IOFile: public InputFile, public OutputFile
{};

int main()
{
	IOFile file;
	file.open();
}
```

		File
		/  \
    InputFile   OutputFile
		\   /
	       IOFile

## Virtual inheritance:

```
class File
{
public:
	std::string name;
	void open();
};

class InputFile: virtual public File
{};

class OutputFile: virtual public File
{};

class IOFile: public InputFile, public OutputFile
{};

int main()
{
	IOFile file;
	file.open();
}
```

## Problem with initialization

```
class File
{
public:
	File(std::string name);
};

class InputFile: virtual public File
{
	InputFile(std::string name):
		File(name)
	{}
};

class OutputFile: virtual public File
{
	OutputFile(std::string name):
		File(name)
	{}
};

class IOFile: public InputFile, public OutputFile
{
	IOFile(std::string name):
		OutputFile(name),
		InputFile(name),
		File(name)
	{}
};

int main()
{
	IOFile file;
}
```

## Interface segregation principle

```
class Engineer
{
	// 40 APIs
};

class Son
{
	// 50 APIs
};

...

class Andy: public Engineer, Son
{
	// 500 APIs
};
```

## Pure abstract classes

1. Abstract class: a class has one or more virtual functions
2. Pure abstract class:
- no data
- no concrete functions

```
class OutputFile{
	public:
	void write() = 0;
	void open() = 0;
};
```

## Summary

1. Multiple Inheritance is an important technique, e.g. ISP
2. Derive only from PACs when using Multiple Inheritance
