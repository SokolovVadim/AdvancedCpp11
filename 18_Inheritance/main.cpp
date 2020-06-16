#include <iostream>
#include <string>

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
	using B::f_pub;
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