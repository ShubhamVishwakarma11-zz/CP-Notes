/**
 * Problem Link:
 * 
 * https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
 * */

#include <bits/stdc++.h> 
using namespace std;

int main (void) {
    long long t; cin >> t;
    while (t--) {
        long long n,k; cin >> n >> k;
        multiset <long long> s;
        for (int i=0;i<n;i++) {
            long long data; cin >> data;
            s.insert(data);
        }
        long long sum = 0;
        for (int j=0;j<k;j++) {
            long long key;
            auto it = s.end();
            it --;
            key = *it;
            s.erase(it);
            sum += key;
            key = key / 2;
            s.insert(key);
        }

        cout << sum << endl;
             

    }

    return 0;
}