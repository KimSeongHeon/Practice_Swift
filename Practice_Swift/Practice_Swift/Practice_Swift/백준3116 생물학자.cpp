//
//  백준3116 생물학자.cpp
//  Practice_Swift
//
//  Created by 김성헌 on 2020/08/03.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
struct ans{
    int x;
    int y;
    int duration;
    ans(int x,int y,int duration):x(x),y(y),duration(duration){}
    bool const operator ==(const ans &o) const{
        return x == o.x && y==o.y && duration == o.duration;
    }
    bool const operator <(const ans &o) const{
        return x < o.x || y<o.y || duration < o.duration;
    }
};
struct info{
    int x;
    int y;
    int dir;
    info(int x,int y,int dir):x(x),y(y),dir(dir){}
};
pair<int,int> matching(int x){
    switch (x) {
        case 1:
            return make_pair(-1, 1);
        case 2:
            return make_pair(0, 1);
        case 3:
            return make_pair(1, 1);
        case 4:
            return make_pair(1, 0);
        case 5:
            return make_pair(1, -1);
        case 6:
            return make_pair(0, -1);
        case 7:
            return make_pair(-1, -1);
        case 8:
            return make_pair(-1, 0);
        default:
            return make_pair(-909,-999);
    }
}
int main(){
    int num;
    set<info> check;
    map<ans,int> answer;
    vector<info> info_arr;
    cin >> num;
    for(int i=0;i<num;i++){
        int x,y,dir;
        cin >> x >> y >> dir;
        info_arr.push_back(info(x,y,dir));
    }

    for(int i=0;i<num-1;i++){
        int x = info_arr[i].x;
        int y = info_arr[i].y;
        int dir = info_arr[i].dir;
        for(int j=i+1;j<num;j++){
            int n = 0;
            int cx = info_arr[j].x;
            int cy = info_arr[j].y;
            int cdir = info_arr[j].dir;
            if(dir == cdir) continue;
            if (matching(dir).first == matching(cdir).first && cx != x) continue; // 가능성 없음
            if (matching(dir).second == matching(cdir).second && cy != y) continue;
            int bunja = cx - x;
            int bunmo = matching(dir).first - matching(cdir).first;
            if(bunmo == 0){
                if (matching(dir).second == matching(cdir).second) continue;
                if ((cy-y)%(matching(dir).second - matching(cdir).second) == 0){
                    n = (cy-y)/(matching(dir).second - matching(cdir).second);
                    if(check.find(info(i,j,n)) == check.end() && check.find(info(j,i,n)) == check.end()){
                        if(answer.find(ans(x+matching(dir).first * n, y+matching(dir).second*n,n)) == answer.end()){
                            answer.insert(make_pair(ans(x+matching(dir).first * n, y+matching(dir).second*n,n),2));
                        }else{
                            answer[ans(x+matching(dir).first * n, y+matching(dir).second*n,n)] += 1;
                        }
                        check.insert(info(i,j,n));
                    }
                    
                }
            }else{
                if(bunja % bunmo == 0 && bunja/bunmo > 0){
                    n = bunja/bunmo;
                }
                if(cy-y == n * (matching(dir).second - matching(cdir).second) && n != 0){
                    if(check.find(info(i,j,n)) == check.end() && check.find(info(j,i,n)) == check.end()){
                        if(answer.find(ans(x+matching(dir).first * n, y+matching(dir).second*n,n)) == answer.end()){
                            answer.insert(make_pair(ans(x+matching(dir).first * n, y+matching(dir).second*n,n),2));
                        }else{
                            answer[ans(x+matching(dir).first * n, y+matching(dir).second*n,n)] += 1;
                        }
                        check.insert(info(i,j,n));
                    }
                }
            }
        }
    }
    int maxx = -1;
    int time = -1;
    for(auto iter=answer.begin();iter!=answer.end();iter++){
        if(maxx < int(iter->second.size())){
            maxx = int(iter->second.size());
            time = iter->first.duration;
        }
        else if(maxx == int(iter->second.size())){
            if (time > iter->first.duration){
                time = iter->first.duration;
            }
        }
    }
    cout << maxx << endl;
    cout << time << endl;
    return 0;
}
