#include<iostream>
using namespace std;

const int N = 1e5 + 10;

// head 表示头节点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点next指针的值(也可以理解为下标值)
// idx 表示当前指向的元素(也可以理解为下标)
int head, e[N], ne[N], idx;


void init(){
    // head = -1 表示元素为null
    head = -1;
    idx = 0;
}

// 头插法
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

// 给第k个元素后面 添加元素
void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

// 删除第k个元素 后面第一个元素
void remove(int k){
    ne[k] = ne[ne[k]];
}


int main(void){
    int m;
    cin >> m;
    init();
    while(m -- ){
        char op;
        int k, x;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'I'){
            cin >> k >> x;
            add(k - 1, x);
        }else if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head];
            remove(k - 1);
        }

    }

    for(int i = head; i != -1; i = ne[i]){
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}