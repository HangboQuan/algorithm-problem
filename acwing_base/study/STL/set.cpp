//
// Created by quanhangbo on 2023/2/9 9:30.
//

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

// a structure to represent a Triangle with three sides as a, b, c
struct Triangle {
    int a, b, c;
};

// asc sort
void sort3(int& a, int& b, int& c) {
    vector<int> vec = {a, b, c};
    sort(vec.begin(), vec.end());
    a = vec[0]; b = vec[1]; c = vec[2];
}

// problem
vector<int> findDuplicateElements(int arr[], int n) {
    unordered_set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i ++ ) {
        s.insert(arr[i]);
        ans.push_back(arr[i]);
    }

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> printDuplicateElements(int arr[], int n) {
    unordered_set<int> input;
    unordered_set<int> duplicateEle;

    vector<int> ans;

    for (int i = 0; i < n; i ++ ) {
        // never insert into set
        if (input.find(arr[i]) == input.end()) {
            input.insert(arr[i]);
        } else {
            duplicateEle.insert(arr[i]);
        }
    }

    for (auto& x : duplicateEle) {
        ans.push_back(x);
    }
    return ans;
}
int countUniqueTriangles(struct Triangle arr[], int n) {
    set<pair<int, iPair>> s;
    for (int i = 0; i < n; i ++ ) {
        int a = arr[i].a; int b = arr[i].b; int c = arr[i].c;
        sort3(a, b, c);
        s.insert({a, {b, c}});
    }
    return s.size();
}
/**
 * sets are a type of associative container(关联容器，即非线性数据结构) in which each element has to be unique because
 * the value of the element identifies it.The values are sorted in a specific sorted order i.e. ascending or descending.
 * 底层实现为红黑树，红黑树具有自动排序的功能，map内部所有的数据都是有序的
 * @return
 */
int main(void) {
    set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    a.insert('g');
    for (auto& x : a) {
        cout << x << " ";
    }
    // F G g
    cout << endl;
    /**
     * diff: auto& auto
     *
     * auto 是通过x遍历字符串str的值，但是无法影响str的值
     * auto& 增加了引用符号，是可以直接修改str的值
     */

    string str = "hello, world";
    for (auto x : str) {
        x = 'x';
    }
    // hello, world
    cout << str << endl;

    for (auto& x : str) {
        x = 'x';
    }
    // xxxxxxxxxxxx
    cout << str << endl;


    set<int> b;
    b.insert(1);
    b.insert(b.begin(), 2);
    b.insert(8);
    b.insert(6);
    // asc sort 1 2 6 8
    for (auto x : b) {
        cout << x << " ";
    }
    cout << endl;
    set<int, greater<int>> c;
    c.insert(10);
    c.insert(5);
    c.insert(12);
    c.insert(4);
    // desc 12 10 5 4
    for (auto x : c) {
        cout << x << " ";
    }
    cout << endl;
    /**
     * properties:
     * 1. sorting order: the set stores that elements in sorted order
     * 2. values characteristics: all the elements in a set have unique values
     * 3. values nature: the value of the element cannot be modified once it is added to the set, though it is
     * possible to remove and then add the modified value of that element. Thus, the values are immutable
     * 4. search technique: sets follow the binary search tree implementation
     * 5. arraying order: the values in a set are unindexed
     */


    /**
     * begin(): Returns an iterator to the first element in the set
     * end(): Returns an iterator to the theoretical(理论上的) element that follows the last element in the set.
     * insert(): O log(N)
     * erase(const g): removes the value 'g' from the set
     * erase(iterator position, const g): removes the element at the position pointed by the iterator
     */
     // desc
    set<int, greater<int>> s1;
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    s1.insert(50);
    s1.insert(10);

    set<int, greater<int>> :: iterator itr;
    // 60 50 40 30 20 10
    for (itr = s1.begin(); itr != s1.end(); itr ++ ) {
        cout << *itr << " ";
    }
    cout << endl;

    set<int> s2(s1.begin(), s1.end());
    // 10 20 30 40 50 60
    for (auto& x : s2) {
        cout << x << " ";
    }
    cout << endl;

    int num = s2.erase(50);
    // 10 20 30 40 60
    for (auto& x : s2) {
        cout << x << " ";
    }
    cout << endl;

    // 40 迭代器是一个变量 容器和操作容器之间的中介 迭代器指向容器中的某个元素 *迭代器名：表示迭代器指向的元素，通过非常量迭代器还能修改
    // 其指向的元素
    cout << *s1.lower_bound(40) << endl;
    cout << *s1.find(40) << endl;

    /**
     * it also has the following methods:
     * cbegin():
     * cend():
     * rbegin():
     * rend():
     * crbegin():
     * crend():
     * find(const g): returns an iterator to the element 'g' in the set if found, else returns the iterator to the end
     * count(const g): returns 1 or 0 based on whether the element 'g' is present in the set or not
     * lower_bound(const g): returns an iterator to the first element that is equivalent to 'g' or definited will not go
     * before the element
     * upper_bound(const g): returns an iterator to the first element that will go after the element 'g' in the set
     */

    int arr[3][3] = {{1, 2, 2}, {4, 5, 6}, {4, 5, 6}};
    int row = 3;
    int col = 3;
    set<set<int>> ds;
    for (int i = 0; i < row; i ++ ) {
        set<int> s;
        for (int j = 0; j < col; j ++ ) {
            s.insert(arr[i][j]);
        }
        ds.insert(s);
    }
    cout << ds.size() << endl;

    struct Triangle array[] = {{9,8,7}, {7, 8 , 9}, {5, 4, 3}, {3, 4, 5}, {8, 9, 5}};
    int n = sizeof(array) / sizeof(Triangle);
    // time complexity O nlog(n)
    cout << countUniqueTriangles(array, n) << endl;
    // we can improve time complexity to O(n) using unordered_set, but using unordered_set requires writing of a hash function
    // as hash function is not defined in library for pairs

    // implemented using hash table(开链寻址法), 插入和查找和删除元素的平均时间复杂度为O(1), 缺点是浪费内存，无自动排序，插入元素的
    // 时候造成乱序
    unordered_set<string> us1;

    us1.insert("c++");
    us1.insert("code");
    us1.insert("in");
    us1.insert("is");
    us1.insert("fast");

    string key = "slow";

    // find returns end iterator if  key is not found, else it returns iterator to that key
    // the key not found
    if (us1.find(key) == us1.end()) {
        cout << "the key not found" << endl;
    }

    string key1 = "fast";
    // the key is fast
    if (us1.find(key1) == us1.end()) {
        cout << "the key not found" << endl;
    } else {
        cout << "the key is " << key1 << endl;
    }

    // fast is in c++ code
    unordered_set<string> :: iterator itr1;
    for(itr1 = us1.begin(); itr1 != us1.end(); itr1 ++ ) {
        cout << *itr1 << " ";
    }
    cout << endl;

    // give an array, implement a method to find all the duplicates among them
    int arr1[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> vec = printDuplicateElements(arr1, n1);

    // 5 1 2
    for(auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;

    unordered_set<string> set1;

    set1.bucket("eee");

    /**
     * unordered_set other methods:
     * bucket(g): returns the bucket number of a specific element 返回特定元素所在的桶
     * bucket_count(): returns the total number of buckets present in an unordered_set container
     * and so on
     */
}


