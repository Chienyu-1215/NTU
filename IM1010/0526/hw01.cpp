#include<iostream>
#include<string>
#include<stdexcept>
#include<queue>

using namespace std;

template<class ItemType>
class BinaryNode
{   
	private:
	   ItemType              item;           // Data portion
	   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
	   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child
	
	public:
	   BinaryNode();
	   BinaryNode(const ItemType& anItem): item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {};
	   BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr): item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {};
	
	   void setItem(const ItemType& anItem) {this->item = anItem; };
	   ItemType getItem() const {return this->item; };
	   
	   bool isLeaf() const {return (this->leftChildPtr == nullptr && this->rightChildPtr == nullptr);};
	
	   BinaryNode<ItemType>* getLeftChildPtr() const {return this->leftChildPtr; };
	   BinaryNode<ItemType>* getRightChildPtr() const {return this->rightChildPtr; };
	   
	   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {this->leftChildPtr = leftPtr; };
	   void setRightChildPtr(BinaryNode<ItemType>* rightPtr) {this->rightChildPtr = rightPtr; };            
}; // end BinaryNode


template<class ItemType>
class BinaryTreeInterface
{
	public:
	   /** Tests whether this binary tree is empty.
	    @return True if the binary tree is empty, or false if not. */
	   virtual bool isEmpty() const = 0;
	   
	   /** Gets the height of this binary tree.
	    @return The height of the binary tree. */
	   virtual int getHeight() const = 0;
	   
	   /** Gets the number of nodes in this binary tree.
	    @return The number of nodes in the binary tree. */
	   virtual int getNumberOfNodes() const = 0;
	   
	   /** Gets the data that is in the root of this binary tree.
	    @pre  The binary tree is not empty.
	    @post  The root’s data has been returned, and the binary tree is unchanged.
	    @return  The data in the root of the binary tree. */
	   virtual ItemType getRootData() const = 0;
	   
	   /** Replaces the data item in the root of this binary tree
	       with the given data, if the tree is not empty. However, if
	       the tree is empty, inserts a new root node containing the
	       given data into the tree.
	    @pre  None.
	    @post  The data in the root of the binary tree is as given.
	    @param newData  The data for the root. */
//	   virtual void setRootData(const ItemType& newData) = 0;
	   
	   /** Adds a new node containing the given data to this binary tree.
	    @param newData  The data for the new node.
	    @post  The binary tree contains a new node.
	    @return  True if the addition is successful, or false not. */
	   virtual bool add(const ItemType& newData) = 0;
	   
	   /** Removes the node containing the given data item from this binary tree.
	    @param data  The data value to remove from the binary tree.
	    @return  True if the removal is successful, or false not. */
//	   virtual bool remove(const ItemType& data) = 0;
	   
	   /** Removes all nodes from this binary tree. */
//	   virtual void clear() = 0;
	   
	   /** Gets a specific entry in this binary tree.
	    @post  The desired entry has been returned, and the binary tree
	       is unchanged. If no such entry was found, an exception is thrown.
	    @param anEntry  The entry to locate.
	    @return  The entry in the binary tree that matches the given entry.
	    @throw  NotFoundException if the given entry is not in the tree. */
//	   virtual ItemType getEntry(const ItemType& anEntry) const throw(logic_error) = 0;
	   
	   /** Tests whether a given entry occurs in this binary tree.
	    @post  The binary search tree is unchanged.
	    @param anEntry  The entry to find.
	    @return  True if the entry occurs in the tree, or false if not. */
//	   virtual bool contains(const ItemType& anEntry) const = 0;
	   
	   /** Traverses this binary tree in preorder (inorder, postorder) and
	       calls the function visit once for each node.
	    @param visit A client-defined function that performs an operation on
	       or with the data in each visited node. */
//	   virtual void preorderTraverse(void visit(ItemType&)) const = 0;
//	   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
//	   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
}; // end BinaryTreeInterface


template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
	private:
	   BinaryNode<ItemType>* rootPtr;
	   
	protected:
	   //------------------------------------------------------------
	   // Protected Utility Methods Section:
	   // Recursive helper methods for the public methods.
	   //------------------------------------------------------------
	   
	   int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	   int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	   
	   // Recursively deletes all nodes from the tree.
	   void destroyTree(BinaryNode<ItemType>* subTreePtr);
	   
	   // Recursively adds a new node to the tree in a left/right fashion to
	   // keep the tree balanced.
	   BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	   
	   // Removes the target value from the tree by calling moveValuesUpTree
	   // to overwrite value with value from child.
	   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
	   
	   // Copies values up the tree to overwrite value in current node until
	   // a leaf is reached; the leaf is then removed, since its value is
	   // stored in the parent.
	   BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	   
	   // Recursively searches for target value in the tree by using a
	   // preorder traversal.
	   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;
	   
	   // Copies the tree rooted at treePtr and returns a pointer to
	   // the copy.
	   BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
	   
	   // Recursive traversal helper methods:
	   void preorder(BinaryNode<ItemType>* treePtr) const;
	   void inorder(BinaryNode<ItemType>* treePtr) const;
	   void postorder(BinaryNode<ItemType>* treePtr) const;
	   
	public:
	   //------------------------------------------------------------
	   // Constructor and Destructor Section.
	   //------------------------------------------------------------
	   BinaryNodeTree();
	   BinaryNodeTree(const ItemType& rootItem);
	   BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr);
	   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
	   virtual ~BinaryNodeTree();
	   
	   //------------------------------------------------------------
	   // Public BinaryTreeInterface Methods Section.
	   //------------------------------------------------------------
//	   bool isEmpty() const;
//	   int getHeight() const;
//	   int getNumberOfNodes() const;
//	   ItemType getRootData() const throw(logic_error);//PrecondViolatedExcep
//	   void setRootData(const ItemType& newData);
	   bool add(const ItemType& newData); // Adds a node
//	   bool remove(const ItemType& data); // Removes a node
//	   void clear();
//	   ItemType getEntry(const ItemType& anEntry) const throw(logic_error);//PrecondViolatedExcep
//	   bool contains(const ItemType& anEntry) const;
	   
	   //------------------------------------------------------------
	   // Public Traversals Section.
	   //------------------------------------------------------------
	   void preorderTraverse() const;
	   void inorderTraverse() const;
	   void postorderTraverse() const;
	   
	   //------------------------------------------------------------
	   // Overloaded Operator Section.
	   //------------------------------------------------------------
	   BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if(subTreePtr == nullptr)
    	return 0;
   	else
    	return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if(subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr){
		return 1;
	}
	else if(subTreePtr->getRightChildPtr() == nullptr ){
		return getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + 1;
	}
	else if(subTreePtr->getLeftChildPtr() == nullptr ){
		return getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) + 1;
	}
	else{
		return getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) + 1;
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
	if(subTreePtr == nullptr)
    	return newNodePtr;
	else
	{
    	BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
    	BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
      
    	if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
    	{
			rightPtr = balancedAdd(rightPtr , newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr );
   		}
    	else
    	{
        	leftPtr = balancedAdd(leftPtr, newNodePtr);
        	subTreePtr->setLeftChildPtr(leftPtr);
      	}	// end if
    	return subTreePtr;
	}  // end if
}  // end balancedAdd

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;
   
	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr)
	{
    	// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    	newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}  // end if
   
	return newTreePtr;
}  // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
    	destroyTree(subTreePtr->getLeftChildPtr());
    	destroyTree(subTreePtr->getRightChildPtr());
    	delete subTreePtr;
	}  // end if
}  // end destroyTree

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr) const
{
	if(treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		cout << " " << theItem;
		preorder(treePtr->getLeftChildPtr());
		preorder(treePtr->getRightChildPtr());
	}
}  //end preorder

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
    	inorder(treePtr->getLeftChildPtr());
    	ItemType theItem = treePtr->getItem();
    	cout << " " << theItem;
   		inorder(treePtr->getRightChildPtr());
	}  // end if
}  // end inorder

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
    	postorder(treePtr->getLeftChildPtr());
   		postorder(treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
    	cout << " " << theItem;
	}  // end if
}  // end inorder

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}	// end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}	// end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}	// end destructor

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;  // end add
}  // end contains

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse() const
{
	preorder(rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse() const
{
	inorder(rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse() const
{
	postorder(rootPtr);
}  // end postorderTraverse


template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
	private:
		BinaryNode<ItemType>* rootPtr;
		int leaves;
	   
	protected:
		//------------------------------------------------------------
		// Protected Utility Methods Section:
		// Recursive helper methods for the public methods.
		//------------------------------------------------------------
		// Recursively finds where the given node should be placed and
		// inserts it in a leaf at that point.
		BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	   
		// Removes the given target value from the tree while maintaining a binary search tree.
		BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
	   
		// Removes a given node from a tree while maintaining a binary search tree.
		BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
	   
		// Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
		// Sets inorderSuccessor to the value in this node.
		// Returns a pointer to the revised subtree.
		BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
	   
		// Returns a pointer to the node containing the given value,
		// or nullptr if not found.
		BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;
	   
	public:
		//------------------------------------------------------------
		// Constructor and Destructor Section.
		//------------------------------------------------------------
		BinarySearchTree() : rootPtr(nullptr), leaves(0) {};
		BinarySearchTree(const ItemType& rootItem) : rootPtr(rootItem), leaves(1) {};
		BinarySearchTree(const BinarySearchTree<ItemType>& tree)
		{
	   		;
		};
		virtual ~BinarySearchTree()
		{
			this->destroyTree(rootPtr);
		};
		
		//------------------------------------------------------------
		// Public Methods Section.
		//------------------------------------------------------------
		bool isEmpty() const { return (rootPtr == nullptr); };
		int getHeight() const {return this->getHeightHelper(rootPtr); };
		int getNumberOfNodes() const {return this->getNumberOfNodesHelper(rootPtr); };
		int getLeaves(BinaryNode<ItemType>* subTreePtr) const;
		ItemType getRootData() const throw(logic_error)
		{
			if(rootPtr == nullptr){
				logic_error e("cannot get the root data");
				throw(e);
			}
			else{
				return rootPtr->getItem();
			}
		}
		;//PrecondViolatedExcep
		void setRootData(const ItemType& newData) const throw(logic_error)
		{
			if(rootPtr == nullptr){
				rootPtr->setItem(newData);
			}
			else{
				logic_error e("the root has data");
				throw(e);
			}
		};
		bool add(const ItemType& newEntry);
//		bool remove(const ItemType& anEntry);
//		void clear();
		ItemType getEntry(const ItemType& anEntry) const throw(logic_error);//PrecondViolatedExcep
//		bool contains(const ItemType& anEntry) const;
	   
		//------------------------------------------------------------
		// Public Traversals Section.
		//------------------------------------------------------------
		void preorderTraverse() const;
		void inorderTraverse() const;
		void postorderTraverse() const;
		void print() const;
		//------------------------------------------------------------
		// Overloaded Operator Section.
		//------------------------------------------------------------
		BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);   
}; // end BinarySearchTree

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
	if(subTreePtr == nullptr){
		return newNodePtr;
	}
	else if(subTreePtr->getItem() > newNodePtr->getItem()){
		BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else{
		BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	if(rootPtr == nullptr){
		rootPtr = newNodePtr;
		return true;
	}
	rootPtr = insertInorder(rootPtr, newNodePtr);
	return true;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getLeaves(BinaryNode<ItemType>* subTreePtr) const
{
	if(subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr){
		return 1;
	}
	else if(subTreePtr->getRightChildPtr() == nullptr ){
		return getLeaves(subTreePtr->getLeftChildPtr());
	}
	else if(subTreePtr->getLeftChildPtr() == nullptr ){
		return getLeaves(subTreePtr->getRightChildPtr());
	}
	else{
		return getLeaves(subTreePtr->getLeftChildPtr()) + getLeaves(subTreePtr->getRightChildPtr());
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
	this->preorder(rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
	this->inorder(rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
	this->postorder(rootPtr);
}  // end postorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::print() const
{
	cout << "Preorder:";
	this->preorderTraverse();
	cout << "\nInorder:";
	this->inorderTraverse();
	cout << "\nPostorder:";
	this->postorderTraverse();
	cout << "\nNumber of nodes: " << this->getNumberOfNodes();
	cout << "\nNumber of leaf nodes: " << this->getLeaves(rootPtr);
	cout << "\nHeight: " << this->getHeight();
}


int main(){
	BinarySearchTree<int> tree1, tree2;
	int input;
	int cnt = 0;
	queue<int> data;
	while(cin >> input){
		tree1.add(input);
		cnt++;
		data.push(input);
		if(cnt % 2 == 0){
			data.pop();
		}
	}
	while(!data.empty()){
		int n = data.front();
		tree2.add(n);
		data.pop();
	}
	tree1.print();
	cout << "\n** after removing " << (cnt - cnt%2)/2 << " nodes **\n";
	tree2.print();
	
	
	return 0;
}
