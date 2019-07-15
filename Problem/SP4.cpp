#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
using namespace std;

int pri(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2; 
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string change(string s) {
    stack<char> st;
    string res;
    int len = s.length();
    
    for(int i = 0; i < len; i++) {
        if(s[i] == '(') {
            st.push('(');
        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            if(!st.empty()) {
                while(!st.empty() && pri(s[i]) <= pri(st.top())) {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        } else {
            res.push_back(s[i]);
        }
    }
    
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    
    //res.push_back('@');
    
    return res;
}

int main() {
    int n;

    cin >> n;
    
    while(n--) {
        string s;
    
        cin >> s;
    
        cout << change(s) << endl;
    }
    
    return 0;
}