#include<bits/stdc++.h>
using namespace std;

struct AP{ int x, y, c, p;};

int M, A;
int userA[100];
int userB[100];
vector<AP> aps;
int answer = 0;

int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

int getMaxPower(int Ay, int Ax, int By, int Bx){
    vector<int> AList;
    vector<int> BList;
    
    for(int i = 0; i < A; i++){
        int distA = abs(Ay - aps[i].y) + abs(Ax - aps[i].x);
        int distB = abs(By - aps[i].y) + abs(Bx - aps[i].x);
        if (distA <= aps[i].c) AList.push_back(i);
        if (distB <= aps[i].c) BList.push_back(i);
    }
    
    int maxPower = 0;
    
    for(int i = 0; i < AList.size(); i++){
        for(int j = 0; j < BList.size(); j++){
            int aIdx = AList[i];
            int bIdx = BList[j];
            if (aIdx == bIdx){
                maxPower = max(maxPower, aps[aIdx].p / 2 + aps[bIdx].p / 2);
            }
            else{
                maxPower = max(maxPower, aps[aIdx].p + aps[bIdx].p);
            }
        }
    }
    
    for(int i : AList) maxPower = max(maxPower, aps[i].p);
    for(int i : BList) maxPower = max(maxPower, aps[i].p);
    
    return maxPower;
}

void runAround(){
   int Ay = 0, Ax = 0;
   int By = 9, Bx = 9;
   
   answer += getMaxPower(Ay, Ax, By, Bx);
   
   for(int i = 0; i < M; i++){
       Ay += dy[userA[i]];
       Ax += dx[userA[i]];
       By += dy[userB[i]];
       Bx += dx[userB[i]];
       
       answer += getMaxPower(Ay, Ax, By, Bx);
   }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
	    answer = 0;
	    aps.clear();
	    
		cin >> M >> A;
        for(int i = 0; i < M; i++){
            cin >> userA[i];
        }
        for(int i = 0; i < M; i++){
            cin >> userB[i];
        }
    
        
        for(int i = 0; i < A; i++){
            int x, y, c, p;
            cin >> x >> y >> c >> p;
            aps.push_back({x-1,y-1,c,p});
        }

        runAround();
        cout << "#" << test_case << " " << answer << '\n';
        
	}

	return 0;
}