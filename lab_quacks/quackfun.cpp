/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T QuackFun::sum(stack<T> & s)
{
  if(s.empty())
  	  return 0;
  
  	T back = s.top();
	T t = s.top();
	s.pop();
	
	if(s.empty())
	{
		s.push(back);
		return t;
	}
	
	t = t + sum(s);
	s.push(back);
	return t;
   // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void QuackFun::scramble(queue<T> & q)
{
// IF the q is empty
	if (q.empty())
	return;
// IF q is not empty
	stack<T> s;
	queue<T> q2;
	int n = q.size();
	int i = 1;
	int sum = i;

// Reverse if i is even
	while(sum<=n)
	{
		if(i%2!=0)
		{
			for (int j = 0; j < i;j++)
			{
			q2.push(q.front());
			q.pop();
			}
		}

		if(i%2==0)
		{
			for(int k  =0; k < i; k++)
			{
			s.push(q.front());
			q.pop();
			}
		
			for(int m=0;m<i;m++)
			{
			q2.push(s.top());
			s.pop();
			}	
		}
	i +=1;
	sum +=i;
	}

	
// Left part
	int left = n -sum +i;
// NO change 
	if(i%2!=0)
	{
		for(int l = 0 ; l < left ; l++)
		{
			q2.push(q.front());
			q.pop();
		}
	}

// REverse
	if(i%2 == 0)
	{
		for(int a = 0; a < left; a++)
		{
		s.push(q.front());
		q.pop();
		}
		
		for(int b = 0;b < left; b++)
		{
		q2.push(s.top());
		s.pop();
		}	
	}

// Swap q and q2
	q.swap(q2);
 
}

/**
 * @return true if the parameter stack and queue contain only elements of exactly
 *  the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in your return statement,
 *      and you may only declare TWO local variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be sure to comment your code VERY well.
 */
template <typename T>
bool QuackFun::verifySame(stack<T> & s, queue<T> & q)
{
    bool retval = true; // optional
    if (s.empty()&&q.empty())
	return retval;

    T t1 = s.top(); // rename me
    T t2 = q.front(); // rename :)
    s.pop();
 
	
	if(s.empty())
	{
		if(t1 == t2)
			retval = true;
		else
			retval = false;	
	s.push(t1);	
	q.push(t2);
	q.pop();
	return retval;
	}
    retval = verifySame(s,q);
//    q.push(t2);
 //   q.pop();
    t2 = q.front();

    if(retval == true && t1 == t2)
    retval = true;
    else
    retval = false;	

    s.push(t1);
    q.push(t2);
    q.pop(); 
    return retval;
}

