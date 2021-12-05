
/**
 * 
 *                           !-- MAPS --!   
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


// FUCNTION DECLARATION
void printMap ( map<int,string> &m);
void printUnorderedMap ( unordered_map<int,string> &m);



int main (void ) 
{
    /**
     * MAPS: (Maps and Unordered Map)
     * It is a data structure that stores key and value data (like a dictionary)
     * Helps to map data from key to value
     * Each element of a Map is a Pair of Key and Value
     * Internal Implementation of Maps uses Red Black Trees
     * Elements of Map are not stored in a Continuous fashion but are stored in discrete places unlike vectors
     * Hence, we can't use it+1 on iterators to access the next element in a map
     * */





    // MAPS


    // Declaration
    map <int,string> m;   // Syntax: map <key_data_type,value_data_type> variable_name


    // Intialisation
    m[1] = "abc";         // Syntax: variable_name [key_data] = value_data
    m[5] = "cdc";         // Time Complexity = O(logn)
    m[3] = "acd"; 

    m.insert({4,"afg"});  // Another way of inserting elements to map


    // Printing the Map  
    cout  << "MAP:(Key,Value)\n";
    cout << "Size: " << m.size() << endl;
    map<int,string> :: iterator it;
    for (it = m.begin();it!=m.end();it++) {
        // Time Complexity (accessing elements): O(logn)
        cout << "(" << it->first << "," << it->second << ")\n";     
    }
    cout << endl;


    // Time Complexity (printing the whole map) : O(nlogn)
    // Time Complexity (inserting n elements) : O(nlogn)


    /**
     * One thing to notice about map is that map stores key in a sorted order
     * We have inserted key 5 first but still it is at the end of the map
     * If the key is Numerical data type then it is stored in a sorted order
     * And if the key is a string, it is stored in a lexiographical order which means
     * in the same order as it will appear in a dictionary
     * 
     * 
     * We can also use Range Order Loops and Auto keyword with Map just like Vectors
     * */


    /**
     * In addition to storing keys in a sorted manner, it also stores unique keys only
     * In case you try to insert an element with an already used key, it will just 
     * update the element with that key with the newly provided value
     * */

    m[5] = "xyz";
    printMap(m);


    


    // FUNCTIONS RELATED TO MAP CONTAINER


    /**
     * .find()
     * 
     * This function finds the pair with the specified key from the map
     * Returns an iterator to the pair with the particular key if the key is present in the map
     * Else it returns m.end() iterator
     * 
     * Time Complexity: O(logn)
     * */

    auto itf = m.find(3);

    cout << "Find Operation: \n";
    if (itf == m.end()) {
        cout << "Not present \n";
    }
    else {
        cout << "(" << itf->first << "," << itf->second << ")\n";     
    }
    cout << "\n";



    /**
     * .erase()
     * 
     * This function erases the specified pair from the map
     * We can specify the pair using either the key or the iterator to the pair
     * If we input a key that doesn't exist in the map, then it erases nothing
     * But if we input a invalid iterator (eg: m.end() ), then it gives us segmentation fault
     * 
     * Time Complexity: O(logn)
     * */

    m.erase(itf);
    printMap(m);


    /**
     * .clear()
     * 
     * deletes and clears the whole map
     * works on all the containers
     * */
    m.clear();
    printMap(m);   // prints a map of size 0


    /**Time Complexity of Insertion Operation
     * 
     * Time Complexity of Insertion Operation depends also on the key
     * If we use key of data type string, then the time for string comparsion 
     * will also show up in the Insertion Operation
     * Time Complexity of Comparision of String: O(s.size())
     * Overall Time Complexity : O ( s.size() * logn )
     * */








    /**
     *      QUESTION-1:
     * 
     * */


    /**
     * 1. Given N strings, print unique strings in lexiographical order 
     *    with their frequency
     *    N <= 10^5
     *    |S| <= 100
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
    map<string,int> mp;
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        string str;
        cin >> str;
        auto itt = mp.find(str);
        if (itt == mp.end()) {
            mp.insert({str,1});
        }
        else {
            itt->second ++;
        }
    }
    // Printing the Map
    cout  << "ANSWER-1 \nMAP:(Key,Value)\n";
    cout << "Size: " << mp.size() << endl;
    for (auto mpp : mp) {
        cout << "(" << mpp.first << "," << mpp.second << ")\n";
    }
    cout << endl;
    //End of Solution





    // UNORDERED MAPS


    /**
     * Difference between MAP and UNORDERED MAP
     * 
     * All the functionality of both the container is same.
     * Both are different in:
     *      - Ordering of elements
     *      - Inbuilt implementation
     *      - Time Complexity
     *      - Valid key datatypes
     * */


    cout << "    UNORDERED MAPS \n\n";
    // Declaration
    unordered_map <int,string> um;   // Syntax: unordered_map <key_data_type,value_data_type> variable_name


    // Intialisation
    um[1] = "abc";         // Syntax: variable_name [key_data] = value_data
    um[5] = "cdc";         // Time Complexity = O(logn)
    um[3] = "acd"; 
    um[4] = "afg";

    printUnorderedMap(um);

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
     * As Unordered Map uses Hash Table and stores the hash value of the key 
     * there is restriction on the data types allowed as the key of Unordered Map
     * All the data types whose hash value exists, can be used as a key for Unordered Map
     * Valid Key data types: int, float, long long, short, string
     * */


    /**
     * * When to use Map and when to use Unordered Map?
     * 
     * If you need to store the pair of key and value in sorted/lexiographical order 
     * then use Map, else use Unordered Map in every other case as time complexity of operations are 
     * better, i.e, O(1) in case of Unordered Map
     * */




    /**
     *      QUESTION-2: 
     * 
     * */


    /**
     * 2.   Given N strings and Q queries.
     *      In each query you are given a string, print the 
     *      frequency of that string
     * 
     * N <= 10^6
     * |S| <= 100
     * Q <= 10^6
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

    // Start of the Solution:
    unordered_map<string,int> ump;
    int unp; cin >> unp;
    for (int i=0;i<unp;i++) {
        string str; cin >> str;
        ump[str] ++;
    }
    cout << "ANSWER-2: \n";
    int q; cin >> q;
    for (int i=0;i<q;i++) {
        string s;
        cin >> s;
        cout << s << ":" << ump[s] << endl;
    }
    // Solution ends here




    // MULTIMAP (hardly used in CP)

    /**
     * The only difference a multimap and a map is that in contrast to map, multimap can store
     * multiple instances of the same key. 
     * Like the map, it also stores keys in a sorted/lexiographical manner.
     * It is not used generally because instead of using Multimap, we can use map and get the 
     * same functionality by using maps like this:
     *  
     * */

    map<int,vector<int>> mm;

    /**
     * Now we can store the different values related to that key in a vector. Same functionality
     * */

    // Declaration of Multimaps
    multimap<int,string> mmp;


    return 0;   
} 


// FUNCTION DEFINATION

void printMap ( map<int,string> &m) {
    // Printing the Map
    cout  << "MAP:(Key,Value)\n";
    cout << "Size: " << m.size() << endl;
    for (auto mp : m) {
        cout << "(" << mp.first << "," << mp.second << ")\n";
    }
    cout << endl;
    return;
}

void printUnorderedMap ( unordered_map<int,string> &m) {
    // Printing the Map
    cout  << "MAP:(Key,Value)\n";
    cout << "Size: " << m.size() << endl;
    for (auto mp : m) {
        cout << "(" << mp.first << "," << mp.second << ")\n";
    }
    cout << endl;
    return;
}
