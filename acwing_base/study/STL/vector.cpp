//
// Created by quanhangbo on 2023/1/5 22:22.
//
#include<iostream>
#include<vector>
#include<algorithm> // for copy() and assign()
#include<iterator> // for back_inserter


using namespace std;
// Vectors are the sames as dynamic arrays with the ability to resize itself automatically when an element is inserted
// or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous
//(连续的) storage so that they can be accessed and traversed using iterator. In vectors, data is inserted at the end.
/**
 * begin(): returns an iterator pointing to the first element in the vector
 * end(): returns an iterator pointing to the theoretical element that follows the last element in the
 * rbegin(): returns a reverse iterator pointing to the last element in the vector. It moves from last to first element
 * rend(): returns a reverse iterator pointing to the theoretical element preceding the first element in the vector(considered as reverse end)
 * @return
 */

// 根据第二列值所在行 进行对矩阵升序排列
bool sortcol(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}

bool sortcol_descend_order(const vector<int>& v1, vector<int>& v2) {
    return v1[1] > v2[1];
}

bool sizecom(const vector<int>& v1, const vector<int>& v2) {
    return v1.size() < v2.size();
}

int main() {
    vector<int> a;
    for(int i = 1; i <= 5; i ++ ) {
        a.push_back(i);
    }

    for(auto i : a) {
        cout << i << " ";
    }

    cout << endl;
    for(auto i = a.begin(); i < a.end(); i ++ ) {
        cout << *i << " ";
    }

    cout << endl;
    for(auto i = a.end() - 1; i >= a.begin(); i -- ) {
        cout << *i << " ";
    }

    cout << endl;
    for(auto i =  a.rbegin(); i < a.rend(); i ++ ) {
        cout << *i << " ";
    }

    cout << endl;
    // begin()和cbegin()的区别是什么 -> const_iterator和iterator的区别是什么? iterator可以改元素值,
    // const_iterator元素值值不可更改
    // cbegin(): return a constant iterator pointing to the first element in the vector.
    for(auto i = a.cbegin(); i < a.cend(); i ++ ) {
        cout << *i << " ";
    }

    cout << endl;
    /**
     * size(): returns the number of elements in the vector.
     * max_size(): returns the maximum number of elements that the vector can hold.
     * capacity(): returns the size of storage space currently allocated to the vector expressed as number of elements.
     * resize(n): resize the container so that it contains 'n' elements.
     * empty(): return whether the container is empty.
     * reserve(): requests that the vector capacity be at least enough to contain n elements.
     */
     vector<int> b;
     for(int i = 0; i < 9; i ++ ) {
         b.push_back(i);
     }
     // 9 16 4611686018427387903
     cout << b.size() << " " << b.capacity() << " " << b.max_size() << endl;
     b.resize(4);

     // Size:4 16 4611686018427387903
     cout << "Size:" << b.size() << " " << b.capacity() << " " << b.max_size() << endl;
     // 0 1 2 3
     for(auto i : b) {
         cout << i << " ";
     }

     cout << endl;
     // bool的返回值 1true 0false -1error  0
     cout << (b.empty() == true) << endl;

     // 减少容器的容量以适应其大小 并销毁超出容量的所有元素
     b.shrink_to_fit();
     cout << b.size() << " "<< b.capacity() << endl;

     /**
      * reference operator[g]: returns a reference to the element at position 'g' in the vector
      * at(g): returns a reference to the element at position 'g' in the vector
      * front(): returns a reference to the first element in the vector
      * back(): returns a reference to the last element in the vector
      * data(): returns a direct pointer to the memory array used internally by the vector to store its owned elements
      * 返回指向vector内部使用的内存数组的直接指针，用于存储其拥有的元素
      */

     vector<int> c;

     for(int i = 1; i <= 10; i ++ ) {
         c.push_back(i * 2);
     }
     // c[2]等价于c.at(2) 返回第一个元素 和最后一个元素 6 6 2 20
     cout << c[2] << " " << c.at(2) << " " << c.front() << " " << c.back() << endl;
     int* pos = c.data();
     // 2 3 4
     cout << *pos << " " << *pos + 1 << " " << *pos + 2 << endl;

     /**
      * assign(): it assigns new value to the vector elements by replacing old ones 重新分配，覆盖逻辑
      * push_back(): it push the elements into a vector from the back 从vector后面添加元素
      * pop_back(): it is used to pop or remove elements from a vector from the back 从vector末尾删除元素，类似于栈
      * insert(): it inserts new elements before the element at the specified position
      * erase(): it is used to remove elements from a container from the specified position or range
      * swap(): it is used to swap the contents of one vector with another vector of same type. Sizes may differ
      * clear(): it is used to remove all the elements of the vector container
      */
     vector<int> d;
     for(int i = 0; i < 10; i ++ ) {
         d.push_back(i);
     }
     // fill the vector with 20 five times
     d.assign(5, 20);
     // vector d size(): 5
     cout << "vector d size(): " << d.size() << endl;
     for(int i = 0; i < 5; i ++ ) {
         d.push_back(i + 1);
     }
     // 20 20 20 20 20 1 2 3 4 5
     for(auto i : d){
         cout << i << " ";
     }
     d.pop_back();
     cout << endl;
     // 20 20 20 20 20 1 2 3 4
     for(auto i : d) {
         cout << i << " ";
     }
     cout << endl;
     d.insert(d.begin(), 1);
     d.insert(d.begin(), 2);
     d.insert(d.end(), 5);
     // 2 1 20 20 20 20 20 1 2 3 4 5
     for(auto i : d) {
         cout << i << " ";
     }
     cout << endl;
     d.erase(d.begin());
     d.erase(d.begin() + 6);

     // 1 20 20 20 20 20 2 3 4 5
     d.erase(d.end() - 2, d.end());
     // 1 20 20 20 20 20 2 3
     for(auto i : d) {
         cout << i << " ";
     }

     // 清空vector的元素
     d.clear();
     cout << "Size vector d: " << d.size() << endl;
     vector<int> e1, e2;
     e1.push_back(1);
     e1.push_back(2);
     e2.push_back(3);
     e2.push_back(4);
     e2.push_back(5);
     e2.push_back(6);
     // 1 2
     for(int i = 0; i < e1.size(); i ++ ) {
         cout << e1[i] << " ";
     }
     cout << endl;
     // 3 4 5 6
     for(int i = 0; i < e2.size(); i ++ ) {
         cout << e2[i] << " ";
     }
     cout << endl;
     e1.swap(e2);

     // 3 4 5 6
     for(int i = 0; i < e1.size(); i ++ ) {
         cout << e1[i] << " ";
     }
     cout << endl;
     // 1 2
     for(int i = 0; i < e2.size(); i ++ ) {
         cout << e2[i] << " ";
     }
     cout << endl;

     /**
      * emplace(): it extends the container by inserting new element at position
      * emplace_back(): it is used to insert a new element into the vector container, the new element is added to the end of the vector
      *
      * emplace()和insert()的区别? emplace_back()和push_back()区别?
      * 区别在于emplace()和emplace_back不需要创建临时变量 而insert和push_back()会创建临时变量
      */

     vector<int> f;
     f.push_back(1);
     f.push_back(3);
     f.emplace(f.begin(), -1);
     f.emplace_back(5);
     for(auto i : f) {
         cout << i << " ";
     }
     cout << endl;

     /**
      * ways to copy a vector in c++
      */

     // 1. iterative method
     vector<int> v1 {1, 2, 3, 4};
     vector<int> v2;

     for(int i = 0; i < v1.size(); i ++ ) {
         v2.push_back(v1[i]);
     }
     // 1 2 3 4
     for(int i = 0; i < v2.size(); i ++ ) {
         cout << v2[i] << " ";
     }
     cout << endl;
     v1[0] = 2;
     // 2 1
     cout << v1[0] << " " << v2[0] << endl;
     // 2. by assignment '=' operator
     vector<int> v3 {1, 3, 5, 7};
     vector<int> v4;
     v4 = v3;
     // 1 3 5 7
     for(int i = 0; i < v4.size(); i ++ ) {
         cout << v4[i] << " ";
     }
     cout << endl;
     v3[0] = 2;
     // 2 1
     cout << v3[0] << " " << v4[0] << endl;
     // 3.by passing vector as constructor 通过向vector构造器传参
     vector<int> v5 {2, 4, 6, 8};
     vector<int> v6(v5);

     for(auto i : v6) {
         cout << i << " ";
     }
     cout << endl;
     // 4. copy(first_iterator_o, last_iterator_o, back_inserter()): this is another way to copy old vector into new
     // one. This function takes 3 arguments, first, the first iterator of the old vector, second, the last iterator
     // of the old vector and third is back_inserter function to insert values from the back. This is also generated
     // a deep copy 这里说的深拷贝是什么意思?

     vector<int> v7 {1, 3, 6, 9};
     vector<int> v8;
     copy(v7.begin(), v7.end(), back_inserter(v8));
     // 1 3 6 9
     for(int i = 0; i < v8.size(); i ++ ) {
         cout << v8[i] << " ";
     }
     cout << endl;
     v7[0] = 2;
     // 2 1
     cout << v7[0] << " " << v8[0] << endl;

     // 5. assign(first_iterator_o, last_iterator_o): this method assigns the same value to the new vector as the
     // old one. this takes 2 arguments, the first iterator to the old vector and the last iterator to the old vector
     // this generates a deep copy.

     vector<int> v9 {0, 1, 2, 3};
     vector<int> v10;
     v10.assign(v9.begin(), v9.end());
     // 0 1 2 3
     for(auto i = v10.begin(); i != v10.end(); i ++ ) {
         cout << *i << " ";
     }
     cout << endl;
     // 6. by using insert function
     vector<int> v11 {8, 27, 36, 54};
     vector<int> v12;
     v12.insert(v12.begin(), v11.begin(), v11.end());
     // 8 27 36 54
     for(int i = 0; i < v12.size(); i ++ ) {
         cout << v12[i] << " ";
     }
     cout << endl;

     // A 2D vector is a vector of vectors. 2D vectors are used for creating matrices, tables, or any other structures,
     // dynamically. Basically, it is a matrix implemented with the help of vectors. They are created using the <vector>
     // header file

     vector<vector<int>> vect1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     for(int i = 0; i < vect1.size(); i ++ ) {
         for(int j = 0; j < vect1.size(); j ++ ) {
             cout << vect1[i][j] << " ";
         }
         cout << endl;
     }

     // ways to sort a 2D vector
     // 1. to sort a particular row of 2D vector 对2维向量特定的行进行排序
     vector<vector<int>> vect2 = {{3, 5, 1}, {4, 8, 6}, {7, 2, 9}};
     int m = vect2.size();
     int n = vect2[0].size();

     for(int i = 0; i < m; i ++ ) {
         for(int j = 0; j < n; j ++ ) {
             cout << vect2[i][j] << " ";
         }
         cout << endl;
     }

     // 对第一行和第二行进行升序排序
     sort(vect2[0].begin(), vect2[0].end());
     sort(vect2[1].begin(), vect2[1].end());

     // 对第一行和第二行进行降序排列
     /**
      * 5 3 1
      * 8 6 4
      * 7 2 9
      */
//     sort(vect2[0].rbegin(), vect2[0].rend());
//     sort(vect2[1].rbegin(), vect2[1].rend());



     /**
      * 1 3 5
      * 4 6 8
      * 7 2 9
      */
     for(int i = 0; i < m; i ++ ) {
         for(int j = 0; j < n; j ++ ) {
             cout << vect2[i][j] << " ";
         }
         cout << endl;
     }

     // 2. to sort the entire 2D vector on basis of a particular column 根据特定列对整个二维向量进行排序
     vector<vector<int>> vect3 = {{3, 5, 1}, {4, 8, 6}, {7, 2, 9}};
     int m1 = vect3.size();
     int n1 = vect3[0].size();
     sort(vect3.begin(), vect3.end(), sortcol);
     /**
      * 7 2 9
      * 3 5 1
      * 4 8 6
      */
     sort(vect3.begin(), vect3.end(), sortcol_descend_order);
     /**
      * 4 8 6
      * 3 5 1
      * 7 2 9
      */
     for(int i = 0; i < m1; i ++ ) {
         for(int j = 0; j < n1; j ++ ) {
             cout << vect3[i][j] << " ";
         }
         cout << endl;
     }

     /**
      * A 2D vector can also have rows with different number of columns. This property is unlike the 2D array
      * in which all rows have same number of columns.
      */

     /**
      * 1 2
      * 3 4 5
      * 6
      */
     vector<vector<int>> vect4 {{1, 2}, {3, 4, 5}, {6}};
     for(int i = 0; i < vect4.size(); i ++ ) {
         for(int j = 0; j < vect4[i].size(); j ++ ) {
             cout << vect4[i][j] << " ";
         }
         cout << endl;
     }
     sort(vect4.begin(), vect4.end(), sizecom);
     /**
      * 6
      * 1 2
      * 3 4 5
      */
     for(int i = 0; i < vect4.size(); i ++ ) {
         for(int j = 0; j < vect4[i].size(); j ++ ) {
             cout << vect4[i][j] << " ";
         }
         cout << endl;
     }




}
