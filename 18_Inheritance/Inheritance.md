# Inheritance

```
class B
{
public:
	void f_pub()
	{
		std::cout << "f_pub is called\n";
	}
protected:
	void f_prot()
	{
		std::cout << "f_prot is called\n";
	}
private:
	void f_priv()
	{
		std::cout << "f_priv is called\n";
	}
};

class D_pub: public B
{
public:
	void function()
	{
		f_pub();  // OK. D_pub's public function
		f_prot(); // OK. D_pub's protected function
		f_pub();  // Error! B's private function
	}
};

class D_prot: protected B
{
public:
	void function()
	{
		f_pub();  // OK. D_prot's protected function
		f_prot(); // OK. D_prot's protected function
		f_pub();  // Error! B's private function
	}
};

class D_priv: private B
{
public:
	void function()
	{
		f_pub();  // OK. D_priv's private function
		f_prot(); // OK. D_priv's private function
		f_pub();  // Error! B's private function
	}
};
```

## Public

```
int main()
{
	D_pub d_pub;
	d_pub.f_pub();
	return 0;
}
```

That's OK. `f_pub()` is D-pub's public function

## Protected

```
int main()
{
	D_prot d_prot;
	d_prot.f_pub();
	return 0;
}
```

Error. `f_pub()` is D_prot's protected function

## Casting 

1. Public -- OK

```
int main()
{
	D_pub d_pub;
	B* pb = &d_pub;
	return 0;
}
```

2. Protected -- Error

```
int main()
{
	D_prot d_prot;
	B* pb = &d_prot;
	return 0;
}
```

## Using keyword

```
class D_prot: protected B
{
public:
	using B::f_pub;
	void function()
	{
		f_pub();  // OK. D_prot's protected function
		f_prot(); // OK. D_prot's protected function
		f_pub();  // Error! B's private function
	}
};

int main()
{
	D_prot d_prot;
	d_prot.f_pub();
	//B* pb = &d_prot;
	return 0;
}
```

That's OK

## Composition

```
class Ring
{
public:
	void bark()
	{
		std::cout << "Woof\n";
	}
};

// Composition

class Dog
{
	Ring m_ring;
public:
	void bark()
	{
		m_ring.bark(); // call forwarding
	}
};
```

## Private inheritance

```
// Private inheritance

class Dog: private Ring
{
public:
	using Ring::bark;
};
```

## Virtual functions in Base & Derived classes

```
class Ring
{
private:
	virtual void tremble()
	{
		std::cout << "Tremble\n";
	}
public:
	void bark()
	{
		std::cout << "Woof\n";
		tremble();
	}
};

// Private inheritance

class Dog: private Ring
{
private:
	virtual void tremble()
	{
		std::cout << "Dog is trembling\n";
	}
public:
	using Ring::bark;
};


// --------------------------------------------------------------------

int main()
{
	Dog dog;
	dog.bark();
	return 0;
}
```