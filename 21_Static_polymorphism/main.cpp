#include <iostream>
#include <vector>

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
	TreeNode* root = new TreeNode;
	EmployeeChart_Parser ep;
	ep.parse_preorder(root);

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