/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	mirror(root);

}

//Helper function for mirror
template <typename T>
void BinaryTree<T>::mirror(Node* node)
{
	if(node == NULL)
	return;
	else{
	// your code here
	mirror(node->left);
	mirror(node->right);
	Node * temp = node->left;
	node->left = node->right;
	node->right = temp;}
	

}


/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
  bool m = false;
    return isOrdered(root,m);
}

template <typename T>
bool BinaryTree<T>::isOrdered(Node* node,bool t) const
{

	if(node == NULL)
	{return true;}

	else{
	  isOrdered(node->left,t);
	if(rightofleft(node)->elem <= node->elem && node->elem <= leftofright(node)->elem)
	  t = true;
	else
	  t = false;
       	isOrdered(node->right,t);
	}
	
	return t;
}

template <typename T>
typename  BinaryTree<T>::Node * BinaryTree<T>::rightofleft(Node * node) const
{
	if (node == NULL)
	  return NULL;

	if(node->left == NULL)
	  return node;

	Node * temp = node->left;
	while(temp->right != NULL)
	  {
	    temp = temp->right;
	  }

	return temp;
}

//Helper get left node of right subtree
template <typename T>
typename  BinaryTree<T>::Node * BinaryTree<T>::leftofright(Node * node) const
{
	if (node == NULL)
	  return NULL;

	if(node->right == NULL)
	  return node;
	
	Node * temp = node->right;
	while(temp->left != NULL)
	  {
	    temp = temp->left;
	  }
	return temp;
}



/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
    // your code here
  vector<T> path;
  printPaths(root,path);
}

template <typename T>
void BinaryTree<T>::printPaths(Node * node, vector<T> path) const
{
  if(node == NULL)
    return;

  path.push_back(node->elem);
  
  if(node->left == NULL && node->right == NULL)
    {
        printvector(path);
    }
  else
    {
      printPaths(node->left,path);
      printPaths(node->right,path);
    }
  

}

template <typename T>
void BinaryTree<T>::printvector(vector<T> path) const
{
  cout<<"Path:";
  for (typename vector<T>::iterator it = path.begin(); it != path.end(); ++it)
    {
    cout<<' '<<*it;
    }
  cout<<endl;
}

/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */

template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
  int depth = 0;
  return sumDistances(root,depth) ;
}

template <typename T>
int BinaryTree<T>::sumDistances(Node * node, int depth) const
{
  
  if (node == NULL)
    return 0;
  return depth + sumDistances(node->left,depth+1) + sumDistances(node->right,depth+1);
}

