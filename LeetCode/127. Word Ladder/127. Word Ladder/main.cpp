//
//  main.cpp
//  127. Word Ladder
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


class Solution {
public:
    
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> distance;
    
    bool differences_count (const string& s1, const string& s2)
    {
        int count = 0;
        for (int i = 0; i < s1.length(); i++)
            if(s1[i] != s2[i])
                count++;
        
        return count == 1;
    }
    
    void bfs (int start, int end)
    {
        visited [start] = true;
        distance[start] = 1;
        queue <int> q;
        q.push(start);
        
        while(! q.empty())
        {
            int s = q.front();
            q.pop();
            
            for (auto const & a: adj[s])
            {
                if(!visited[a])
                {
                    q.push(a);
                    distance[a] = distance[s] + 1;
                    visited[a] = true;
                }
            }
        }
        
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        wordList.push_back(beginWord);
        int list_length = wordList.size();
        int start = list_length - 1;
        
        int end = - 1;
        for(int i = 0; i < list_length; i++)
        {
            if(endWord == wordList[i])
            {
                end = i;
                break;
            }
        }
        
        if (end == - 1)
            return 0;
        
        adj = vector<vector<int>> (list_length);
        visited = vector<bool> (list_length);
        distance = vector<int> (list_length);
        

        
        for(int i = 0; i < list_length; i++)
        {
            visited[i] = false;
            distance[i] = 0;
        }
        
        
        for (int i = 0; i < wordList.size(); i++)
            for (int k = 0; k < wordList.size(); k++)
            {
                string s1 = wordList[i];
                string s2 = wordList[k];
                if (i != k && s1.size() == s2.size() && differences_count(s1, s2))
                    {
                    adj[i].push_back(k);
                    //adj[s2].push_back(s1);
                }
            }
        
        bfs(start, end);
            
        return distance[end];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    string s1 = "hit";
    string s2 = "cog";
    vector<string> v {"hot","dot","dog","lot","log"};
    
    cout<<s.ladderLength(s1, s2, v);

    return EXIT_SUCCESS;
}
