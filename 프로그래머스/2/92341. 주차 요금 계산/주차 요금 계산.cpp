#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> cars;
    map<string, int> time;
    
    for(int i = 0; i < records.size(); i++){
        string tm, car_num, status;
        istringstream iss(records[i]);
        iss >> tm >> car_num >> status;
        
        if (cars.find(car_num) != cars.end()){
            int st_hr = stoi(cars[car_num].substr(0,2));
            int st_mn = stoi(cars[car_num].substr(3,2));
            int en_hr = stoi(tm.substr(0,2));
            int en_mn = stoi(tm.substr(3,2));
            
            time[car_num] += (en_hr*60+en_mn) - (st_hr*60+st_mn);
            cars.erase(car_num);
        }
        else cars[car_num] = tm;
    }
    
    for (auto c : cars){
        int st_hr = stoi(c.second.substr(0,2));
        int st_mn = stoi(c.second.substr(3,2));
        int en_hr = 23;
        int en_mn = 59;
        int tot = (en_hr*60+en_mn) - (st_hr*60+st_mn);
        time[c.first] += tot;
    }
    
    
    for (auto t : time){
        if (t.second <= fees[0]){
            answer.push_back(fees[1]);
        }
        else{
            answer.push_back
            (fees[1] + ceil((t.second - fees[0]) / (double)fees[2]) * fees[3]);
        }
    }
    return answer;
}