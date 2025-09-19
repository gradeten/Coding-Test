#include <bits/stdc++.h>
using namespace std;
int n;
int lc[10005];
int rc[10005];
int num[10005];
int col = 1;
bool hasParent[10005];
int level[10005];
int minCol[10005];
int maxCol[10005];
int ansLv = -1;
int ansCol = -1;

void setLevel(int cur, int lv){
    if (cur == 0) return;
    level[cur] = lv;
    setLevel(lc[cur],lv+1);
    setLevel(rc[cur],lv+1);
}

void inorder(int cur){
    if (lc[cur] != 0){
        inorder(lc[cur]);
    }
    num[cur] = col;
    col++;
    if (rc[cur] != 0){
        inorder(rc[cur]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int c, l, r;
        cin >> c >> l >> r;
        if (l != -1){
            lc[c] = l;
            hasParent[l] = true; 
        }
        if (r != -1){
            rc[c] = r;
            hasParent[r] = true; 
        }
    }
    
    int root;
    for(int i = 1; i <= n; i++){
        if (!hasParent[i]) root = i;
    }
    
    inorder(root);
    setLevel(root, 1);
    
    for(int i = 1; i <= n; i++){
        minCol[i] = 9999999;
        maxCol[i] = -1;
    }
    
    for(int i = 1; i <= n; i++){
        int lv = level[i];
        int col = num[i];
        minCol[lv] = min(minCol[lv], col);
        maxCol[lv] = max(maxCol[lv], col);
    }
    
    for(int i = 1; i <= n; i++){
        if (maxCol[i] == -1) continue;
        int cur = maxCol[i] - minCol[i] + 1;
        if (ansCol < cur){
            ansLv = i;
            ansCol = cur;
        }
    }
    
    cout << ansLv << ' ' << ansCol;
}