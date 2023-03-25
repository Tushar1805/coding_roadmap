// https://practice.geeksforgeeks.org/problems/ef5111156686a3136c6a0df8bbda17f952947e17/1

// Redundant Parenthesis

// Given a valid expression containing only binary operators '+', '-', '*', '/' and operands, 
// remove all the redundant parenthesis.

// A set of parenthesis is said to be redundant if, removing them, does not change the value of the expression.

// Note: The operators '+' and '-' have the same priority. '*' and '/' 
// also have the same priority. '*' and '/' have more priority than '+' and '-'.


// Example 1:

// Input:
// Exp = (A*(B+C))
// Output: A*(B+C)
// Explanation: The outermost parenthesis
// are redundant.
// Example 2:

// Input:
// Exp = A+(B+(C))
// Output: A+B+C
// Explanation: All the parenthesis
// are redundant.

// Your Task:  
// You don't need to read input or print anything. 
// Your task is to complete the function removeBrackets() 
// which takes the string Exp as input parameters and returns the updated expression.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 < Length of Exp < 105
// Exp contains uppercase english letters, '(' , ')', '+', '-', '*' and '/'.

#include<bits/stdc++.h>
using namespace std;

string removeBrackets(string s){    
    int n = s.length();
    
    // int ans[n+1];
    // memset(ans, 1, sizeof(ans));
    // int lasta[n+1];
    // int nxta[n+1];
    
    // int l = -1;
    // for(int i=0;i<n;i++){
    //     lasta[i] = l;
    //     if(s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*')
    //         l = s[i];
    // }
    // l = -1;
    // for(int i=n-1;i>=0;i--){
    //     nxta[i] = l;
    //     if(s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*')
    //         l = s[i];
    // }
    
    // stack<char> st;
    // int sign[256];
    // int mp[256];
    // memset(sign, -1, sizeof(sign));
    // char operand[] = {'*', '+', '-', '/'};
    
    // for(int p=0;p<n;p++){
    //     for(char x: operand){
    //         mp[x] = 0;
    //         if(x==s[p]) 
    //             sign[x] = p;
    //     }
    //     if(s[p] == '(')
    //         st.push(p);
            
    //     else if(s[p] == ')'){
    //         int i=st.top();
    //         st.pop();
    //         int j = p;
            
    //         int nxt=nxta[j];
    //         int last = lasta[i];
            
    //         for(char x:operand){
    //             if(sign[x] >=i)
    //                 mp[x] = 1;
    //         }
    //         int ok = 0;
            
    //         if(i>0 and j+1<n and s[i-1] == '(' and s[j+1] ==')')
    //             ok = 1;
    //         if(mp['+'] == 0 and mp['-'] == 0 and mp['*'] == 0 and mp['/'] == 0)
    //             ok = 1;
    //         if(last == -1 and nxt == -1)
    //             ok = 1;
            
    //         if(last == '/'){
                
    //         }else if(last == '-' and (mp['+'] == 1 or mp['-'] == 1)){
                
    //         }else if(mp['+'] == 0 and mp['-'] == 0){
    //             ok=1;
    //         }else{
    //             if((last == -1 or last == '+' or last == '-') and (nxt == -1 or nxt == '+' or nxt == '-'))
    //                 ok = 1;
    //         }
    //         if(ok == 1){
    //             ans[i] = 0; 
    //             ans[j] = 0;
    //         }
    //     }  
    // }
    // string res = "";
    // for(int i=0; i<n; i++){
    //     if(ans[i] > 0)
    //         res += s[i];
    // }
    // return res;
    
    stack<char> st;
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++){
        if(s[i] == '(' or s[i] == '*' or s[i] =='/' or s[i] == '-' or s[i]  == '+')
            st.push(i);
        else if(s[i] == ')'){
            bool plus = false, min = false, divi = false, mul = false;
            while(!st.empty() and s[st.top()] != '('){
                int curr = st.top();
                st.pop();
                if(s[curr] == '*') mul =true;
                if(s[curr] == '/') divi = true;
                if(s[curr] == '+') plus = true;
                if(s[curr] == '-') min = true;
            }
            
            int j = st.top();
            st.pop();
            
            int prev = i;
            i++;
            while(i<n && !st.empty() && s[st.top()] == '(' && s[i] == ')'){
                vis[i] = vis[st.top()] = true;
                st.pop();
                i++;
            }
            i--;
            if(i+1<n && s[i+1] == '*')
                if(divi || plus || min) continue;
            if(i+1<n && s[i+1] == '/')
                if(divi || plus || min || mul) continue;
            
            if(st.empty() || (!plus && !min && !mul && !divi))
                vis[prev] = vis[j] =true;
            else if(s[st.top()] == '+')
                vis[prev] = vis[j] =true;
            else if(s[st.top()] == '-' && !plus && !min)
                vis[prev] = vis[j] = true;
            else if(s[st.top()] == '*' && (!divi && !plus && !min))
                vis[prev] = vis[j] =true;
            else if(s[st.top()] == '/' && (!divi && !plus && !min && !mul))
                vis[prev] = vis[j] =true;
        }
    }
    string res = "";
    for(int i=0;i<n; i++){
        if(!vis[i])
            res += s[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
	string s;
	cout<<"Enter any expression to check parenthesis redundancy: ";
	cin>>s;
	string res = removeBrackets(s);
	cout<<"\nResultant string after removing redundant brackets: "<<res;
	return 0;
}