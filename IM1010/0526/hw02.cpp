#include<iostream>
#include<queue>
#include<stdexcept>
#include<cmath>

using namespace std;

template<class ItemType>
class HeapInterface
{
	public:
		/** Sees whether this heap is empty.
		@return True if the heap is empty, or false if not. */
		virtual bool isEmpty() const = 0;
	   
		/** Gets the number of nodes in this heap.
	    @return The number of nodes in the heap. */
		virtual int getNumberOfNodes() const = 0;
	   
		/** Gets the height of this heap.
	    @return The height of the heap. */
		virtual int getHeight() const = 0;
	   
		/** Gets the data that is in the root (top) of this heap.
	    For a maxheap, the data is the largest value in the heap;
	    for a minheap, the data is the smallest value in the heap.
	    @pre The heap is not empty.
	    @post The root’s data has been returned, and the heap is unchanged.
	    @return The data in the root of the heap. */
		virtual ItemType peekTop() const = 0;
	   
		/** Adds a new node containing the given data to this heap.
	    @param newData The data for the new node.
	    @post The heap contains a new node.
	    @return True if the addition is successful, or false if not. */
		virtual bool add(const ItemType& newData) = 0;
	   
		/** Removes the root node from this heap.
	    @return True if the removal is successful, or false if not. */
		virtual bool remove() = 0;
	   
		/** Removes all nodes from this heap. */
		virtual void clear() = 0;
}; // end HeapInterface


template<class ItemType>
class ArrayMinHeap : public HeapInterface<ItemType>
{
	private:
		static const int ROOT_INDEX = 0;        // Helps with readability
//		static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
		ItemType* items;                        // Array of heap items
		int itemCount;                          // Current count of heap items
//		int maxItems;                           // Maximum capacity of the heap
	   
		// ---------------------------------------------------------------------
		// Most of the private utility methods use an array index as a parameter
		// and in calculations. This should be safe, even though the array is an
		// implementation detail, since the methods are private.
		// ---------------------------------------------------------------------
	   
		// Returns the array index of the left child (if it exists).
		int getLeftChildIndex(const int nodeIndex) const;
	   
		// Returns the array index of the right child (if it exists).
		int getRightChildIndex(const int nodeIndex) const;
	   
		// Returns the array index of the parent node.
		int getParentIndex(const int nodeIndex) const;
	   
		// Tests whether this node is a leaf.
		bool isLeaf(int nodeIndex) const
		{
			if(getRightChildIndex(nodeIndex) > itemCount) return true;
			else return false;
		};
	   
		// Converts a semiheap to a heap.
		void heapRebuild(int subTreeRootIndex);
	   
		// Creates a heap from an unordered array.
		void heapCreate();
		void preorder(int currentIndex);
		void inorder(int currentIndex);
		void postorder(int currentIndex);
	   
	public:
		ArrayMinHeap() : itemCount(0){};
		ArrayMinHeap(int cnt) : itemCount(0){ items = new ItemType[2 * cnt]; };
		ArrayMinHeap(const ItemType someArray[], const int arraySize);
		virtual ~ArrayMinHeap(){ items = nullptr; };
	   
		// HeapInterface Public Methods:
		bool isEmpty() const
		{
			return (itemCount == 0);
		};
		int getNumberOfNodes() const {return itemCount;};
		int getLeaves() const
		{ 
			int cnt = 0;
			for(int i = 0 ; i < itemCount ; i++){
				if(isLeaf(i)) cnt++; 
			}
			return cnt;
		};
		int getHeight() const
		{
			if(itemCount == 0) return 0;
			int height = 1;
			for(int i = 1 ; pow(2 , i) <= itemCount ; i++){
				height++;
			}
			return height;
		};
		ItemType peekTop() const throw(logic_error);
		bool add(const ItemType& newData);
		bool remove();
		void clear()
		{
			itemCount = 0;
			delete[] items;
		};
		void preorderTraverse()
		{
			preorder(0);
		};
		void inorderTraverse()
		{
			inorder(0);
		};
		void postorderTraverse()
		{
			postorder(0);
		};
		void print();
}; // end ArrayMaxHeap

template<class ItemType>
int ArrayMinHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMinHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMinHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
	return (nodeIndex - 1)/2 ;
}  // end getParentIndex

template<class ItemType>
void ArrayMinHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
	if(!isLeaf(subTreeRootIndex)){
		int largerChildIndex = 2 * subTreeRootIndex + 1;
		if(getRightChildIndex(subTreeRootIndex) < itemCount){
			int rightChildIndex = getRightChildIndex(subTreeRootIndex);
			if(items[rightChildIndex] < items[largerChildIndex])
				largerChildIndex = rightChildIndex;
		}
		if(items[subTreeRootIndex] > items[largerChildIndex]){
			ItemType temp = items[subTreeRootIndex];
			items[subTreeRootIndex] = items[largerChildIndex];
			items[largerChildIndex] = temp;
		}
	}
}  // end heapRebuild

template<class ItemType>
void ArrayMinHeap<ItemType>::preorder(int currentIndex) 
{
	if(currentIndex < itemCount){
		cout << " " << items[currentIndex];
		preorder(getLeftChildIndex(currentIndex));
		preorder(getRightChildIndex(currentIndex));
	}
}  // end preorder

template<class ItemType>
void ArrayMinHeap<ItemType>::inorder(int currentIndex) 
{
	if(currentIndex < itemCount){
		inorder(getLeftChildIndex(currentIndex));
		cout << " " << items[currentIndex];
		inorder(getRightChildIndex(currentIndex));
	}
}  // end inorder

template<class ItemType>
void ArrayMinHeap<ItemType>::postorder(int currentIndex) 
{
	if(currentIndex < itemCount){
		postorder(getLeftChildIndex(currentIndex));
		postorder(getRightChildIndex(currentIndex));
		cout << " " << items[currentIndex];
	}
}  // end inorder

template<class ItemType>
void ArrayMinHeap<ItemType>::heapCreate() 
{
	for (int index = itemCount / 2; index >= 0; index--)
	{
		heapRebuild(index);  
	}  // end for
}  // end heapCreate

template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap(const ItemType someArray[], const int arraySize): itemCount(arraySize)
{
	// Allocate the array
	items = new ItemType[2 * arraySize];
	   
	// Copy given values into the array
	for (int i = 0; i < itemCount; i++)
		items[i] = someArray[i];
	   
		// Reorganize the array into a heap
	heapCreate();
} // end constructor

template<class ItemType>
ItemType ArrayMinHeap<ItemType>::peekTop() const throw(logic_error)
{
	if (isEmpty())
	    throw logic_error("Attempted peek into an empty heap.");
	   
	return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMinHeap<ItemType>::add(const ItemType& newData) 
{
	items[itemCount] = newData;
	int newDataIndex = itemCount;
	bool success = false;
	itemCount++;
	while(!success && newDataIndex > 0){
		int parentIndex = getParentIndex(newDataIndex);
		if(items[parentIndex] < items[newDataIndex]) success = true;
		else{
			ItemType temp = items[parentIndex];
			items[parentIndex] = items[newDataIndex];
			items[newDataIndex] = temp;
			newDataIndex  = parentIndex; 
		}
	}
} // end peekTop

template<class ItemType>
bool ArrayMinHeap<ItemType>::remove() 
{
	items[0] = items[itemCount - 1];
	itemCount--;
	for (int index = 0; index < itemCount ; index++)
	{
		heapRebuild(index);  
	} 
} // end remove

template<class ItemType>
void ArrayMinHeap<ItemType>::print()
{
	cout << "Preorder:";
	this->preorderTraverse();
	cout << "\nInorder:";
	this->inorderTraverse();
	cout << "\nPostorder:";
	this->postorderTraverse();
	cout << "\nNumber of nodes: " << this->itemCount;
	cout << "\nNumber of leaf nodes: " << this->getLeaves();
	cout << "\nHeight: " << this->getHeight();
}

int main(){
	
	int cnt = 0;
	int input;
	queue<int> data;
	while(cin >> input){
		cnt++;
		data.push(input);
	}
	ArrayMinHeap<int> minHeap(cnt);
	while(!data.empty()){
		int input = data.front();
		data.pop();
		minHeap.add(input);
	}
	minHeap.print();
	for(int i = 0 ; i < cnt / 2 ; i++){
		minHeap.remove();
	}
	cout << "\n** after removing " << cnt / 2 << " nodes **\n";
	minHeap.print();
	return 0;
}
