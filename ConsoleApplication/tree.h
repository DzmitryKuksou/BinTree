const int N = 256;
struct Node
{
	char* eng;
	char* russ;
	Node* right, *left;
};
class TreeNode
{
	public:
		Node* root = NULL;
		TreeNode();
		TreeNode(int);
		TreeNode(const TreeNode&);
		void PushWord(Node*&, char*, char*);
		void DisplayTree(Node*)const;
		void DisplayTree()const;
		void CopyTree(Node*&,const Node*);
		void DeleteTree(Node*);
		void DisplayNode(Node*)const;
		bool SortByAlpabet(char*, char*)const;
		Node* SearchByWord(Node*, char*)const;
		~TreeNode();
		
};