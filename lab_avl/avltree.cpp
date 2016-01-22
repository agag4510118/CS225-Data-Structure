/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K & key) const
{
	return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node * subtree, const K & key) const
{
	if (subtree == NULL)
		return V();
	else if (key == subtree->key)
		return subtree->value;
	else
	{
		if (key < subtree->key)
			return find(subtree->left, key);
		else
			return find(subtree->right, key);
	}
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    // from the slides on class
    Node * y = t->right;
    t->right = y->left;
    y->left = t;
    t = y;

    // Change Height
    t->left->height = max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right))+1;  
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;     
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	// Implemented for you:
	rotateLeft(t->left);
	rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node * y = t->left;
    t->left = y->right;
    y->right = t;
    t = y;

    // Change height
    t->right->height = max(heightOrNeg1(t->right->left), heightOrNeg1(t->right->right)) + 1;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right)) + 1;  
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    	rotateRight(t->right);
	rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
	insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node* & subtree, const K & key, const V & value)
{
    // your code here
    // From slides on class

	//Base case
    if(subtree==NULL)
	subtree = new Node(key,value);
    else if (key<subtree->key)
	{
		insert(subtree->left,key,value);
		 int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);	
		int leftBalance = heightOrNeg1(subtree->left->right)-heightOrNeg1(subtree->left->left);
		if(balance == -2)
		{
			if(leftBalance ==-1)
				rotateRight(subtree);
			else
				rotateLeftRight(subtree);
		}	
	}
	
    else if (key > subtree->key)
	{
	insert(subtree->right,key,value);
	int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
	int rightBalance = heightOrNeg1(subtree->right->right)-heightOrNeg1(subtree->right->left);
	if(balance ==2)
	{
		if (rightBalance ==1)
			rotateLeft(subtree);
		else
			rotateRightLeft(subtree);
	}
	}

	subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;
}

