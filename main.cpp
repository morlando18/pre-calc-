#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

bool TryParse(const string &symbol){
    bool isNumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++){
        if(!isdigit(symbol[i])){
            isNumber = false;
        }else{
            isNumber = true;
        }
    }
    return isNumber;
}
int Priority(const string &c) {
    if (c == "rt")return 3;
    if (c == "*" || c == "/")return 2;
    if (c == "+" || c == "-"){return 1;
    }else return 0;
}
bool isOperator(const string &c){
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "rt");
}
void toPostfix (string infix){

    istringstream stringStream(infix);
    vector<string> tokens;
    while(stringStream){
        string temp;
        stringStream >>temp;
        tokens.push_back(temp);
    }
    vector<string> postFix;
    stack<string> stack1;

    //operator: +, -, *, /, rt, ()
    //operands: 1234567890
    for(unsigned int i = 0; i < tokens.size(); i++){
        if(TryParse(tokens[i])){
            postFix.push_back(tokens[i]);
        }
        if(tokens[i] == "("){
            stack1.push(tokens[i]);
        }
        if(tokens[i] == ")"){
            while(!stack1.empty() && stack1.top() != "("){
                postFix.push_back(stack1.top());
                stack1.pop();
            }
            stack1.pop();
        }
        if(isOperator(tokens[i]) == true){
            while(!stack1.empty() && Priority(stack1.top()) >= Priority(tokens[i])){
                postFix.push_back(stack1.top());
                stack1.pop();
            }
            stack1.push(tokens[i]);
        }
    }
    while(!stack1.empty()){
        postFix.push_back(stack1.top());
        stack1.pop();
    }

    for(unsigned int i = 0; i < postFix.size(); i++){
        cout<<postFix[i] << " ";
    }
}



int main(){
    //string infix = "67 + ( 32 / 8 ) * 3 rt 8";
    cout << "> ";
    string infix;
    getline (cin,infix);

    toPostfix(infix);
    return 0;
}