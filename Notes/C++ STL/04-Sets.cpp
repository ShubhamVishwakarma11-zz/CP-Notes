
/**
 * 
 *                           !-- SETS --!   
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


// FUNCTION DECLARATION 
void printUnorderedSet(unordered_set<string> &s);


int main (void ) 
{
    /**
     * SETS: (Sets, Unordered Set and Multiset)
     * 
     * It is a data structure used to store unique keys in sorted order
     * Internal Implementation of Maps uses Red Black Trees which is a self balancing tree
     * */

    // Declaration
    set<string> s;            // Syntax: set<data_type> variable_name
    
    // Intialisation
    s.insert("abc");          // Time Complexity = O(logn)
    s.insert("def");
    s.insert("bcd");
    s.insert("cde");

    // Accessing an element
    auto it = s.find("abc");   
    /**
     * s.find() returns an iterator to the corresponding element if present 
     * else returns s.end()
     * */

    // Printing the Set
    cout << "SET: \n";
    cout << "Size: " << s.size() << endl;
    for (string value:s) {
        cout << value << endl;
    }
    cout << endl;


    // Time Complexity (printing the whole set) : O(nlogn)
    // Time Complexity (inserting n elements) : O(nlogn)


    /**
     * One thing to notice about map is that map stores key in a sorted order
     * We have inserted element "def" first but still it is at the end of the map
     * If the key is Numerical data type then it is stored in a sorted order
     * And if the key is a string, it is stored in a lexiographical order which means
     * in the same order as it will appear in a dictionary
     * 
     * In addition to storing elements in a sorted manner, it also stores unique elements only
     * In case you try to insert an element with an already used data, there will be no affect on the set
     * */

    // s.erase() (can input an iterator and a data as well)


    /**
     *      QUESTION-1
     * 
     * */

    /**
     * 1. Given N strings, print unique strings in lexiographical order
     *    N <= 10^5
     *    |S| <= 100000
     * 
     * Input: 
     * 8
     * abc 
     * def
     * abc
     * ghj
     * jkl
     * ghj
     * ghj
     * abc 
     * */

    // Start of Solution
    set<string> sq;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        string str;
        cin >> str;
        sq.insert(str);
    }
    // Printing the Map
    cout << "ANSWER-1 \nSET: \n";
    cout << "Size: " << sq.size() << endl;
    for (auto it:sq) {
        cout << it << endl;
    }
    cout << endl;
    // End of Solution


    // UNORDERED SET

    /**
     * Same differences as the differences between set and unordered set
     * 
     *
     * Difference between SET and UNORDERED SET
     * 
     * All the functionality of both the container is same.
     * Both are different in:
     *      - Ordering of elements
     *      - Inbuilt implementation
     *      - Time Complexity
     * */


    cout << "    UNORDERED SET \n\n";
    // Declaration
    unordered_set <string> us;   // Syntax: unordered_set <data_type> variable_name


    // Intialisation
    us.insert("abc");         // Syntax: variable_name.insert(value_data)
    us.insert("cdc");         // Time Complexity = O(1)
    us.insert("acd"); 
    us.insert("afg");

    printUnorderedSet(us);

    /**
     * * Ordering and In-built implementation
     * You will notice that unordered map doesn't store keys in any specific order 
     * This difference in order arrises due to their difference in implementation
     * Maps are implemented using Red Black Trees, whereas, Unordered Map is implemented 
     * with the help of Hash Tables by storing the hash value of the key
     * 
     * * Time Complexity
     * The average time complexity of insertion and access operation on unordered map is O(1) in average case
     * It can be more than O(1) in case of collision but this situation hardly arrives
     * find and erase operation are also O(1) in average case
     * */


    /**
     * * Valid Key data types
     * 
     * As Unordered Set uses Hash Table and stores the hash value of the key 
     * there is restriction on the data types allowed as the key of Unordered Set
     * All the data types whose hash value exists, can be used as a key for Unordered Set
     * Valid Key data types: int, float, long long, short, string
     * */


    /**
     * * When to use Set and when to use Unordered Set?
     * 
     * If you need to store the data in sorted/lexiographical order then use Set,
     * else use Unordered Set in every other case as time complexity of operations are 
     * better, i.e, O(1) in case of Unordered Map (like if you want to check the presence of a data
     * in the set)
     * */





    /**
     *      QUESTION-2: 
     * 
     * */


    /**
     * 2.   Given N strings and Q queries.
     *      In each query you are given a string, print yes if string 
     *      is present else print no.
     * 
     * N <= 10^6
     * |S| <= 100
     * Q <= 10^6
     * 
     * INPUT: 
     * 8
     * abc 
     * def
     * abc
     * ghj
     * jkl
     * ghj
     * ghj
     * abc
     * 3
     * abc
     * ghj
     * abcdef
     * */

    // Start of Solution
    unordered_set<string> sqq;
    int nqq;
    cin >> nqq;
    for (int i=0;i<nqq;i++) {
        string str;
        cin >> str;
        sqq.insert(str);
    }
    cout << "ANSWER-2\n";
    int q;
    cin >> q;
    for (int i=0;i<q;i++) {
        string str;
        cin >> str;
        cout << str << ": ";
        if (sqq.find(str) == sqq.end()) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    cout << endl;
    // End of Solution




    // MULTISET

    /**
     * The only difference a multiset and a set is that in contrast to set, multiset can store
     * multiple instances of the same key. 
     * Like the set, it also stores keys in a sorted/lexiographical manner.
     * We can use multiset as an alternative to priority queue
     * */


    // Declaration of Multiset
    multiset<string> ms;

    // Initialisation of Multiset
    ms.insert("abc");         // Syntax: variable_name.insert(value_data)
    ms.insert("cdc");         // Time Complexity = O(logn)
    ms.insert("abc"); 
    ms.insert("afg");
    ms.insert("afg");
    ms.insert("afg");


    // Printing Multiset
    cout << "    MULTISET\n";
    cout << "SET: " << endl;
    cout << "Size: " << ms.size() << endl;
    for (auto it:ms) {
        cout << it << endl;
    }
    cout << endl;



    /**
     * Behaviour of .erase() function in Multiset
     * 
     * If we first use .find() function to find the iterator to the desired key which have multiple occurences,
     * then .find() will return the iterator to the first occurence of the key and passing this iterator
     * to .erase() function will result into erasing of the first occurence only
     * Whereas, passing the key directly to the .erase() function will result in erasing of all the occurence
     * of that key
     * */

    // Erasing by passing iterator
    auto itt = ms.find("abc");
    if (itt != ms.end()) {
        ms.erase(itt);
    }

    // Printing Multiset
    cout << "SET: " << endl;
    cout << "Size: " << ms.size() << endl;
    for (auto it:ms) {
        cout << it << endl;
    }
    cout << endl;


    // Erasing by passing data
    ms.erase("afg");

    // Printing Multiset
    cout << "SET: " << endl;
    cout << "Size: " << ms.size() << endl;
    for (auto it:ms) {
        cout << it << endl;
    }
    cout << endl;


    return 0;

}


// FUNCTION DEFINATION
void printUnorderedSet(unordered_set<string> &s) {
    cout << "SET: " << endl;
    cout << "Size: " << s.size() << endl;
    for (auto it:s) {
        cout << it << endl;
    }
    cout << endl;
    return;
}