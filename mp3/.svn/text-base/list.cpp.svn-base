/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
	ListNode * ptr = head;
	ListNode * temp;

	while (ptr!=NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
	
	

}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{
	ListNode * insertfront = new ListNode(ndata);

    /// @todo Graded in MP3.1
	if(head!=NULL){
		ListNode * temp = head;
		head = insertfront;
		head->next = temp;
		temp->prev = head;
		head->prev = NULL;
	}
	else
	{
		head = insertfront;
		tail = insertfront;	
		head->next = NULL;
		head->prev = NULL;
	}
	length += 1;
	
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    /// @todo Graded in MP3.1
	ListNode * insertback = new ListNode(ndata);
	if (tail!=NULL){
	ListNode * temp = tail;
	tail = insertback;
	temp->next = insertback;
	tail->prev = temp;
	tail->next = NULL;
	}
	else{
	head = insertback;
	tail = insertback;
	head->next = NULL;
	head->prev = NULL;
	}
	length += 1;
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{
    /// @todo Graded in MP3.1
	ListNode * s = startPoint;
	ListNode * e = endPoint->next;

	// When there is no item or just one item
	if(startPoint == endPoint)
		return;
	
	//Exchange middle items 
	while (s!=e)
	{	
		ListNode *temp = s->next;	
		s->next = s->prev;
		s->prev = temp;	
		s = temp;
		temp = NULL;
	} 
	
	// From head to tail
 	 if (startPoint== head &&  endPoint == tail)
	{
		ListNode * tt = startPoint;
		startPoint = endPoint;
		endPoint = tt;
		tt = NULL;
	}
	 // No head and tail
	 if (startPoint!=head && endPoint !=tail)
	{
		ListNode *t1 = startPoint;
		ListNode *t2 = endPoint;
		ListNode *t3 = t2->prev;
		t1->next->next = t2;
		t2->prev = t1->next;
		t1 ->next = t3;
		t3->prev = t1;
		
		t1 = NULL;
		t2 = NULL;
		t3 = NULL;
	}
	 //Tail but not head
	if (startPoint!=head && endPoint == tail)
	  {
	    ListNode * u = startPoint;
	    ListNode *v = endPoint;
	    u->next->next = v;
	    v->prev = u->next;
	    u->next = NULL;
	    tail = u;
	    u = NULL;
	    v = NULL;
	    
	  }
	// Head but not tail
	if(startPoint == head && endPoint !=tail)
	  {
	    ListNode *k = endPoint;
	    ListNode * v = startPoint;
	    v->next = k->prev;
	    k->prev ->prev= v;
	    k->prev = NULL;
	    head = k;
	    k = NULL;
	    v = NULL;
	  }
	
		s = NULL;
		e= NULL;	
		
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{
    /// @todo Graded in MP3.1
      
	int left = length%n;
	int numberofblocks = (length-left)/n;

	if(n<1)
	  cout<<"error. N should be larger than length"<<endl;
	if (n >= length)
	  {
	  reverse(head,tail);
	  }
	
	if (n==1)
	  return;

	if (1<n<length)
	  {
	      ListNode *s = head;
	      ListNode *e = s;
	      for(int j = 0; j < numberofblocks;j++)
	    {
	        for (int i = 0; i < n; i++)
	        {
	    	ListNode *k = e->next;
	    	e = k;
	    	k = NULL;
	        }
		if(e!=NULL)
		  {
		    reverse(s,e->prev);
		    s = e;
		  }
		else
		  {
		    ListNode *t = s;
		    for (int i = 0; i < n-1; i++)
		      {
			t = t->next;
		      }
		    reverse(s,t); 
		    t = NULL;
		  }
	      }

	      
	      if (e!=NULL)
		{
		  reverse(e,tail);
		}
	      s = NULL;
	      e = NULL;
	   }


      
}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1
  if (length>2){
    ListNode * s = head->next;
    ListNode * e = tail;

    while(s!=tail &&  s!=NULL){
      ListNode *left = s->prev;
      ListNode *right = s->next;
      left->next = right;
      right->prev = left;

      s->prev = NULL;
      s->next = NULL;
      tail->next = s;
      s->prev = tail;
      s->next = NULL;
      tail = s;

      s = right->next;
      right = NULL;
      left = NULL;
    }
  
    s = NULL;
    e = NULL;
  }
  else
    {
      return;
    }

  
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head)
    {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    }
    else
    {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL)
    {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint)
{
    /// @todo Graded in MP3.2
  ListNode * secondhead= start;
  
  if (secondhead !=NULL){
    for (int i = 0 ; i < splitPoint; i ++)
      {
	if (secondhead!=NULL){
	  secondhead = secondhead->next;}
      }

    secondhead->prev->next = NULL;
    secondhead->prev = NULL;
  }
  

    return secondhead; // change me!
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if(tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second)
{
  if(first==NULL)
    return second;
  else if(second==NULL)
    return first;
  

  //  ListNode * t1 = NULL;
  // ListNode * t2 = NULL;

  if(first->data < second->data)
    {
      first->next = merge(first->next,second);
      first->next->prev = first;
      first->prev = NULL;
      return first;
    }
  else
    {
      second->next = merge(first,second->next);
      second->next->prev = second;
      second->prev = NULL;
      return second;
    }

}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode * List<T>::mergesort(ListNode * start, int chainLength)
{
    /// @todo Graded in MP3.2
	int half = chainLength/2;
	if(start==NULL || start->next == NULL)
		return start;

	ListNode * second = split(start,half);
	
	start = mergesort(start,half);
	if(chainLength%2==0)
	second = mergesort(second,half);
	else
	second = mergesort(second,chainLength-half);


	
	return merge(start,second); // change me!
}
