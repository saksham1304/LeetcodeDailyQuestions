class Solution {
public:
    string maximumOddBinaryNumber(string s) {
     
       const   int n=s.length();
        char* arr=new char[n+1];
        strcpy(arr,s.c_str());
        sort(arr,arr+n);
        int seclast=n-2;
        for(int i=0;i<n/2;i++){
            char temp=arr[i];
            arr[i]=arr[seclast-i];
            arr[seclast-i]=temp;
        }
        return arr;
    }
};