class Solution {
public:
    int pivotInteger(int n) {
        
        for(int k=1;k<=n;k++){
            int sum=0;//sum left
        int sum2=0;//sum right
        for(int i=1;i<=k;i++){
            sum+=i;}
            for(int j=k;j<=n;j++){
                sum2+=j;
            }
            if(sum==sum2){return k;}
        }
            
        return -1;
    }
};