class Solution {
public:

    vector<vector<string>> backtrack(map<string, vector<string>> parent, string endWord, string beginWord)
    {
        cout << endWord  << " " << beginWord << endl;
        vector<vector<string>> res;
        vector<string> lst;
        lst.push_back(endWord);
        queue<pair<string, vector<string>>> q;
        q.push({endWord, lst});
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                string node = q.front().first;
                vector<string> tmp = q.front().second;
                q.pop();
                if(node == beginWord)
                {
                    reverse(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                    continue;
                }
                for(auto it: parent[node])
                {
                    tmp.push_back(it);
                    q.push({it, tmp});
                    tmp.pop_back();
                }
            }
        }
        return res;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> res;

        map<string, vector<string>> parent;
        map<string, int> visited;

        for(auto it: wordList)
        {
            visited[it] = INT_MAX;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;
        parent[beginWord].push_back(beginWord);

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                string node = q.front();
                q.pop();
                // cout << node << ' ';
                if(node == endWord)
                {
                    res = backtrack(parent, endWord, beginWord);
                    return res;
                }
                int len = node.size();
                for(int j=0;j<len;j++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        if(node[j] == c)
                            continue;
                        
                        string tmp = node;
                        tmp[j] = c;
                        if(!(visited.find(tmp) == visited.end()))
                        {
                            if(visited[tmp] == visited[node]+1)
                            {
                                parent[tmp].push_back(node);
                            }
                            if(visited[tmp] > visited[node]+1)
                            {
                                visited[tmp] = visited[node]+1;
                                vector<string> p;
                                p.push_back(node);
                                parent[tmp] = p;
                                q.push(tmp);
                            }
                        }
                    }
                }
            }
        }

        return res;
        
               
    }
};