
/**
 * 
 *                           !-- ITERATORS --!   
 * 
 * */




/**
 *  C++ STANDARD TEMPLATE LIBRARY (STL)
 * 
 *     - CONTAINERS: similar to data structures.
 *                   Sequential (vector, stack, queue), 
 *                   Ordered (map, multimap, set, multiset), 
 *                   Unordered (Unordered map, Unordered set)
 * 
 *     - ITERATORS: similar to pointers for pointing to containers
 *                  begin(), end()
 * 
 *     - ALGORITHMS: upper_bound(), lower_bound(), sort(comparator)
 *                   reverse(), count(), find() etc.
 * 
 * */



// including header files
#include <bits/stdc++.h>     // includes all the header file
using namespace std;         // C++ have a predefined namespace class 
                             // named std so that we dont have to write std:: everytime


int main (void ) 
{
    /**
     *ITERATORS: pointer like structures which points to the elements of containers
     * Iterators are useful as containers like map, set can't be accessed via indexing 
     * hence we use iterators to access the elements of containers like map and set
     * */


    vector<int> v = {2,4,6,8,10};


    /**
     *      [ 2 | 4 | 6 | 8 | 10 |   ]
     *        |                    | 
     *    v.begin()             v.end()
     * */
    

    // How to declare an Iterator?
    vector<int> :: iterator it = v.begin(); 


    // We can access the value at an iterator by just using * operator just like pointers
    // We can also move to the next element by incrementing the iterator just like pointers
    cout << "Vector: ";
    for (it = v.begin();it != v.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;


    /**
     * Difference between it+1 and it++ ?? 
     * 
     * it++ moves the iterator to the next element of the container
     * it+1 moves the iterator to the next memory location
     * 
     * For vectors, it++ and it+1 will produce the same result as vectors are also declared 
     * as a contiguous memory block like an array
     * 
     * But for containers like map and set, it++ will move the iterator to the next element 
     * but it+1 will move iterator to the next (invalid) memory location resulting compilation error
     * */



    // How to use iterators to access pairs (instead of int)??

    vector<pair<int,int>> vp = {{1,2},{3,4},{5,6}};

    vector<pair<int,int>> :: iterator itt;

    cout << "Vector of pairs: ";
    for (itt = vp.begin();itt != vp.end();itt++) {
        cout << "(" << (*itt).first << "," << itt->second << ") ";    // (*it).first <==> it->first
    }
    cout << endl;







    // How to write codes of Iterators in short?? (works only on C++11 or later)


    /**
     * Range Based Loops
     * 
     * By using range based loops we can directly iterate on the elements of the container
     * The value of element is directly copied into the iterator
     * */

    cout << "Range based loops: ";
    for (int value:v) {
        cout << value << " ";
    }
    cout << endl;

    /**
     * When we use range based loops, the actual values of the element is copied but not the actual value
     * So, if you change the values of the iterator, it won't reflect in the actual elements
     * In order to change the actual values of the elements via iterators, we can use references
     * */

    // Changing the actual values of the element via iterator
    for (int &value : v) {
        value ++;
    }
    // Simply printing the elements of the container
    cout << "Changing via Iterator: ";
    for (it = v.begin();it != v.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;





    /**
     * Auto Keyword
     * 
     * Dynamically assumes (determine) the data type
     * Very useful for Iterators
     * Instead of declaration statement as vector<int> :: iterator it = v.begin()
     * we can simply declare the iterator using auto keyword as auto it = v.begin()
     * This makes writing iterator codes very short
     * */

    return 0;
}