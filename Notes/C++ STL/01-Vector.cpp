/**
 * 
 *                           !-- VECTORS --!   
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
 * 				    begin(), end()
 * 
 *     - ALGORITHMS: upper_bound(), lower_bound(), sort(comparator)
 *                   reverse(), count(), find() etc.
 * 
 * */



// including header files
#include <bits/stdc++.h>     // includes all the header file
using namespace std;         // C++ have a predefined namespace class 
                             // named std so that we dont have to write std:: everytime



/**
 * This function prints the passed vector
 * We are passing the vector using pass by reference
 * Message is a small string to identify the vector
 * */
void printVector(vector<int> &vec, string message) {
	cout << message << ": (size:" << vec.size() << "\n";
	for (int i=0;i<vec.size();i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}


/**
 * This function prints the passed vector without any other information unlike printVector()
 * Arguments to passed: Reference to the array of vector, Number of columns
 * */
 void printVec(vector<int> vec) {
 	for (int i=0;i<vec.size();i++) {
 		cout << vec[i] << " ";
 	}
 	cout << "\n";
 }




int main (void) 
{
	/**
	 ******************* VECTOR **************************
	 * 
	 * can be interpreted as an array of dynamic size
	 * */


	// Declaration 
	vector<int> v;


	// Adding elements into the vector
	v.push_back(1);            // O(1)
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.emplace_back(5);         // emplace_back is similar to
	                           //push_back, but have better time complexity


	// Accessing elements 
	for (int i=0;i<5;i++) {
		cout << v[i] << " ";
	}
	cout << endl;


	// Travesing vector using iterators (.begin() and .end())
	// v.begin() points to the first element of the vector
	// v.end() points to the location after the end of the vector
	for (auto it = v.begin();it!=v.end();it++) {        // auto recognise the data type itself
		cout << *it << " ";
	}
	cout << endl;
	

	// Copying vectors is a lot easy task
	vector<int> v_copy = v;        // O(n)


	// Other ways to copy the entire vector
	vector<int> v_copy (v);
	vector<int> v_copy (v.begin(),v.end());          // inclusion of passed parameters works as [).


	// How to copy a part of vector
	vector<int> v_copy (v.begin(), v.end()+2);     // copies only first two elements of the vector 


	/*
	 * It's a good practice to pass vectors and arrays using pass by reference or pass by pointers
	 * because when we pass the whole vector or array to a function, a copy of the vector or array is 
	 * created which is O(n) process. So, by rather using pointer or refernce we can pass the same array 
	 * or vector we can achieve passing arguments in O(1) time 
	*/


	v.clear();        // erases all the elements at once


	// If you want to directly declare and initialise a vector of some size with some value then you can do that too
	vector<int> vec (4,0); // declares a vector of size 4 and initialise index with 0 
						   // and we can still add elements into this vector




	//    !-- NESTING IN VECTORS --!
	

	// Array of Vectors
	vector<int> v[5];      // This is an array of 5 vectors, i.e, v[0],v[1] and so on, all are vectors of 0 size.
	v[0].push_back(1);     // This will add 1 as the first element in the first vector ie vector v[0]
	v[0].push_back(2);	   // This will add 2 to the vector v[0]
	// This is similar to a 2D vector. Array of Vector just have dynamic size of number of columns but static number of rows


	// How will you input values into array of vector?
	/**
	 * 
	 * VALUES TO BE STORED: 1 2 3
	 *                      3 4 5
	 *                      1 2
	 * 
	 * INPUT: 
	 * 3
	 * 3
	 * 1 2 3
	 * 3 
	 * 3 4 5
	 * 2 
	 * 1 2
	 * */


	// Inserting values for array of vectors
	int N; cin >> N;
	vector<int> v[N];
	for (int i=0;i<N;i++) {
		int n; cin >> n;
		for (int j=0;j<n;j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	// printing the array of vectors
	cout << "Array of Vectors: \n";
	for (int i=0;i<N;i++) {
		printVec(v[i]);
	}
	cout << "\n";



	// Vector of Vectors
	vector<vector<int>> vec;   // Here, v represents a vector of vector, ie, v[0] is a vector itself
	

	// How will you input values into vector of vector?
	// Inserting the same values for vector of vectors
	int Nv; cin >> Nv;
	for (int i=0;i<Nv;i++) {
		int nv; cin >> nv;
		vector<int> temp;                // We will declare a temp vector
		for (int j=0;j<nv;j++) {    
			int x; cin >> x;
			temp.push_back(x);           // Add values of each row into temp vector in iteration
		}
		vec.push_back(temp);             // push_back whole vector temp into vector vec in iteration
	}

	// we can also push_back an empty vector in the starting and then push_back values into it
	vec.push_back(vector<int> () );      // This will add one more (empty) row into the 2D vector
	vec[3].push_back(9);
	vec[3].push_back(0);
	
	// printing the vector of vectors
	cout << "Vector of Vectors: \n";
	for (int i=0;i<vec.size();i++) {
		printVec(vec[i]);
	}
	cout << "\n";



	return 0;
}