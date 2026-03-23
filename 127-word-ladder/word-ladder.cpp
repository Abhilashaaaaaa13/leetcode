class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end())return 0;
        int steps =1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();
            while(n--){
    string curr = q.front();
    q.pop();
    if(curr==endWord)return steps;
    for(int i=0;i<curr.size();i++){
        char original = curr[i];
        for(char ch= 'a';ch<='z';ch++){
            curr[i]=ch;
            if(st.find(curr)!=st.end()){
                q.push(curr);
                st.erase(curr);
            }
        }
        curr[i]=original;
    }
            }
            steps++;
        }

return 0;
    }
};