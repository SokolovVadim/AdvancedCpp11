# Static polymorphism

## Dynamic polymorphism

```
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
};

class Generic_Parser
{
public:
	void parse_preorder(TreeNode* node)
	{
		if(node){
			process_node(node);
			parse_preorder(node->left);
			parse_preorder(node->right);
		}
	}
private:
	virtual void process_node(TreeNode* node)
	{
		std::cout << "virtual\n";
	}
};

class EmployeeChart_Parser: public Generic_Parser{
public:
	void process_node(TreeNode* node){
		std::cout << "Customized process_node for EmployeeChart_Parser\n";
	}
};

// --------------------------------------------------------------------

int main()
{
	TreeNode* root = new TreeNode;
	EmployeeChart_Parser ep;
	ep.parse_preorder(root);
	return 0;
}
```

## Things to be simulated

1. Is-a relationship between base class and derived class
2. Base class defines a "generic" algorithm that is used by derived class
3. The "generic" algorithm is customized by the derived class

## Static polymorphism

```
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
};

template<typename T>
class Generic_Parser
{
public:
	void parse_preorder(TreeNode* node)
	{
		if(node){
			process_node(node);
			parse_preorder(node->left);
			parse_preorder(node->right);
		}
	}
private:
	void process_node(TreeNode* node)
	{
		std::cout << "Generic Parser\n";
		static_cast<T*>(this)->process_node(node);
	}
};

class EmployeeChart_Parser: public Generic_Parser<EmployeeChart_Parser>{
public:
	void process_node(TreeNode* node){
		std::cout << "Customized process_node for EmployeeChart_Parser\n";
	}
};

// --------------------------------------------------------------------

int main()
{
	TreeNode* root = new TreeNode;
	EmployeeChart_Parser ep;
	ep.parse_preorder(root);
	return 0;
}
```

The output is:

```
Generic Parser
Customized process_node for EmployeeChart_Parser
```

This method is called Curiously recurring template pattern. It also uses TMP.

## Generalized Static Polymorphism

```
template<typename T>
T Max(std::vector<T> v)
{
	T max = v[0];
	for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it){
		if(*it > max)
			max = *it;
	}
	return max;
}

// --------------------------------------------------------------------

int main()
{
	std::vector<int> v;
	for(int i(0); i < 10; ++i)
		v.push_back(i * (i % 2 ? -1: 1));
	for(auto i:v)
	{
		std::cout << i << " ";
	}
	std::cout << "\nMax = " << Max(v) << std::endl;

	return 0;
}
```
