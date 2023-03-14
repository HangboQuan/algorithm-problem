//
// Created by quanhangbo on 2023/3/14 22:00.
//

// Trie Tree
#include<iostream>
using namespace std;

const int N = 100010;
char str[N];

int son[N][26], cnt[N], idx;
void insert(char str[]) {
    // p 表示第p个节点, son[p][u] 表示第p个节点的儿子节点, cnt[p]表示以p节点结尾单词的个数, idx 表示当前节点的下标
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            son[p][u] = ++ idx;
//            cout << "son[" << p << "][" << u << "]" << " idx = " << idx << endl;
        }
        p = son[p][u];
//        cout << "p = " << p << endl;
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}
int main(void) {
    int n;
    char op[2];
    scanf("%d", &n);
    while (n --) {
        scanf("%s%s", op, str);
        if (op[0] == 'I') {
            insert(str);
        } else {
            printf("%d", query(str));
        }

    }
    return 0;

}

