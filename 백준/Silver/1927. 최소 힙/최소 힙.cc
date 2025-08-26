#include <bits/stdc++.h>
using namespace std;
int n, x;
int heap[100005];
int sz = 0;

void push(int x){
    heap[++sz] = x;
    int cur = sz;
    while(cur > 1 && heap[cur] < heap[cur/2]){
        swap(heap[cur], heap[cur/2]);
        cur /= 2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[sz];
    sz--;
    int cur = 1;
    
    while(true){
        int left = cur*2;
        int right = cur*2 + 1;
        int smallest = cur;
        
        if (left <= sz && heap[left] < heap[smallest]) smallest = left;
        if (right <= sz && heap[right] < heap[smallest]) smallest = right;
        
        if (smallest == cur) break;
        swap(heap[smallest], heap[cur]);
        cur = smallest;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        cin >> x;
        if (x != 0){
            push(x);
        }
        else{
            if (sz == 0){
                cout << 0 << '\n';
                continue;
            }
            cout << top() << '\n';
            pop();
        }
    }
}