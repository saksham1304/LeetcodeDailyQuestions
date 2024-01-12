class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
            int c=0;
        for(int i=0;i<s.size()/2;i++){
            char ch=s.at(i);
            
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            count++;
            }
        }
        for(int i=s.size()/2;i<s.size();i++){
            char ch=s.at(i);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            c++;
            }
        }
        
        if(c==count){
            return true;
        }
            return false;
    }

};