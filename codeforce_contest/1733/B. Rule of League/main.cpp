#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) { 
        // timeline, key, quantity
        multimap<int, pair<char, int> > m;
        map<char,int> letters;
        for(int i=0;i<tasks.size();i++){
            if(letters.find(tasks[i]) == letters.end()){
                letters[tasks[i]] = 0;
            } else {
                letters[tasks[i]]++;
            }
        }
        for(auto it=letters.begin();it!=letters.end();it++) m.insert(make_pair(0, *it));
        
        int timeLine = 2;
        while(not m.empty()){
            auto lower = m.lower_bound(timeLine-n);
            multimap<int, pair<char, int> > :: reverse_iterator it(lower)
            
            if(lower != m.end()){
                lower->second.second--;
                if(lower->second.second >0){
                    m.insert(make_pair(timeLine, lower->second));
                }
                m.erase(lower);
            }
            timeLine++;
        }
        return timeLine-2;
    }
};

            // auto lower = m.lower_bound(timeLine-n);
            // multimap<int, pair<char, int> > :: reverse_iterator it_reverse(lower);
            // for(;it_reverse != m.rend() && timeLine-it_reverse->first >= n;it_reverse++)
            // cout << "timeLine: " << timeLine <<endl;
            // cout << "it_reverse->first: " << it_reverse->first <<endl;
            // cout << "n: " << n <<endl << endl;
            // if(it_reverse != m.rend()){
            //     cout << "entrou aqui" << endl;
            //     it_reverse->second.second--;
            //     if(it_reverse->second.second>0){
            //         m.insert(make_pair(timeLine, it_reverse->second));
            //     }
            //     cout << "size m: " << m.size() << endl;
            //     m.erase(next(it_reverse).base());
            //     cout << "size m: " << m.size() << endl;
                
            // }
            // timeLine++;