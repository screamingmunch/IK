#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_
/*
Design And Implement LRU Cache


Problem Statement:

The LRU caching scheme removes the least recently used frame, when the cache is full and a new page is referenced which is not there in the cache. 

You are given one integer named capacity, denoting the maximum size possible of the LRU cache. Also you are given three integer arrays named query_type, key and value, each having size n.

query_type[i], key[i] and value[i] together denotes one query. So there are total n queries. 

query_type contains only 0 or 1. query_type[i] = 0 means ith query is GET query and query_type[i] = 1 means ith query is SET query. key and value arrays contain only positive integers.

You have to return array containing answers for GET queries.

GET query:

For GET query only key[i] matters, do not care what is stored in value[i]. 

For each GET query append one integer in the array to be returned. Append the value of the key[i], if the key[i] exists in the cache, otherwise append -1.

SET query:

If key[i] is already present in the cache then update its value to value[i], else add key[i] with value value[i] in the cache.

Input Format:

There are four arguments in the input. First is integer named capacity. Second is integer array named query_type. Third is integer array named key. Fourth is integer array named value. 

Output Format:

Return an array containing answers for GET queries.

Constraints:

1 <= n <= 10^5
1 <= capacity <= 10^5
0 <= query_type[i] <= 1
1 <= key[i] <= 10^5
1 <= value[i] <= 10^5

Sample Test Case:

Sample Input:

capacity = 2

index      query_type      key      value
0              1                      5          11
1              1                      10         22
2              0                      5      1
3              1                      15         33
4              0                      10     1
5              1                     5          55
6              0                      5      1

(
this is same as:
query_type = [1 1 0 1 0 1 0]
key = [5 10 5 15 10 5 5]
value = [11 22 1 33 1 55 1]
)

Sample Output:

[11 -1 55]

Explanation:

Initially cache is empty.

Step 1:
SET: 5 -> 11
Noe cache contains (5 ->11).

Step 2:
SET: 10 -> 22 
Now cache contains (5 -> 11) and (10 -> 22).

Step 3:
GET: 5
Cache contains (5 ->11), so append 11 to answer. 

Step 4:
SET: 15 -> 33
Now cache contains (5 -> 11) and (15 -> 33).
Note that here (10 -> 22) is removed because 10 is the least recently used. 5 was used in the previous query! 

Step 5:
GET: 10
Cache does not contain key 10 (it was removed in previous step), so append -1 to answer.

Step 6:
SET: 5 -> 55
Now cache contains (5 -> 55) and (15 -> 33). Note that (5 -> 11) is updated to (5 -> 55).

Step 7:
GET: 5
Cache contains (5 -> 55), so append 55 to answer. 
*/

#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

using std::list;
using std::unordered_map;
using std::pair;
using std::vector;

class LRUCache
{
	public:

		LRUCache(size_t capacity);

		int getQuery(int key);
		void setQuery(int key, int value);

	private:

		size_t 									m_capacity;
		list<pair<int,int>>						m_entries;
		unordered_map<int, list<pair<int,int>>::iterator> m_cache;

};


//HW PROBLEM 4
vector<int> implement_LRU_cache(int capacity, const vector<int>& query_type, const vector<int>& keys, const vector<int>& values);

#endif
