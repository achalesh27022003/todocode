

final code

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r,d;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R')r.push(i);
            else
            d.push(i);
        }
        while(r.size() and d.size()){
            int rad=r.front(),dir=d.front();
            r.pop();
            d.pop();
            if(rad<dir){
                r.push(rad+senate.size());
            }
            else{
                d.push(dir+senate.size());
            }
        }
        if(r.size())return "Radiant";
        return "Dire";
    }
};
