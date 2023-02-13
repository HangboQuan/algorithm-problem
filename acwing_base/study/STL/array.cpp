//
// Created by quanhangbo on 2023/2/13 21:11.
//
#include<iostream>
#include<array>
using namespace std;

/**
 * Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence
 * @return
 */
int main(void) {
    //begin、end、rbegin、rend、cbegin、cend、crbegin、crend
    //size、max_size、empty
    //at front back data
    //fill swap
    array<int, 6> myArray;
    myArray.fill(0);

    for (int& x : myArray) {
        cout << x << " ";
    }
    cout << endl;
}