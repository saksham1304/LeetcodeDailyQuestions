class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int c=0;
        for(int i=0;i<op.size();i++){
            if(op.at(i)=="--X" || op.at(i)=="X--")c-=1;
            if(op.at(i)=="X++" || op.at(i)=="++X")c+=1;         
        }      
        return c;
    }
};