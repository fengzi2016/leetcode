#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int evalRPN(vector<string>& tokens);
    string arr[] = {
      "3","-4","+"
    };
    vector<string> exa(arr,arr+3);
    int res = evalRPN(exa);
    cout<<res;
}
 
    bool isFlag(string s){
        if(s == "+" || s == "-" || s == "/" || s == "*") {
            return true;
        }
        return false;
    }
    int stringToNumber(string a) {
        vector<char> s(a.begin(),a.end());
        int k=1;
        int res = 0;
        int end = 0;
        if(a[0]=='-') end = 1;
        for(int i=s.size()-1;i>=end;i--){
            res += (s[i]-'0' )* k;
            k *= 10;
        }
        if(end == 1) res*=-1;
        return res ;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res = 0;
        if(tokens.size()==0) return 0;
        if(tokens.size()==1) return stringToNumber(tokens[0]);
        for(int i=0;i<tokens.size();i++) {
            string cur = tokens[i];
            if(!isFlag(cur)){
                s.push(stringToNumber(cur));
            }else{
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    if(cur=="*") res = right * left;
                    if(cur=="/") res = left / right;
                    if(cur=="+") res = left + right;
                    if(cur=="-") res = left - right;
                     s.push(res);
                }
            }
        return res;
    }