//
// Created by quanhangbo on 2023/2/9 9:30.
//

#include<iostream>
#include<set>
using namespace std;

/**
 * sets are a type of associative container(关联容器，即非线性数据结构) in which each element has to be unique because
 * the value of the element identifies it.The values are sorted in a specific sorted order i.e. ascending or descending.
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

    // 40
    cout << *s1.lower_bound(40) << endl;
}
