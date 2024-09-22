#include<bits/stdc++.h>
using namespace std;

bool isKeyword(const string& word) {
    const vector<string> keywords = { "if", "else", "for", "while", "return", "int", "float", "char","double","main" };
    for (const auto& kw : keywords) {
        if (word == kw) {
            return true;
        }
    }
    return false;
}


string classifyToken(const string& token) {
    if (isKeyword(token)) {
        return "KEYWORD";
    } else if (isalpha(token[0]) || token[0] == '_') {
        return "IDENTIFIER";
    } else if (isdigit(token[0])) {
        return "NUMBER";
    } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "=") {
        return "OPERATOR";
    } else {
        return "SEPARATOR";
    }
}

vector<pair<string, string>> tokenize(const string& code) {
    vector<pair<string, string>> tokens;
    string currentToken;

    for (size_t i = 0; i < code.length(); ++i) {
        char c = code[i];

        if (isspace(c)) {
            continue;
        }


        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            tokens.push_back(make_pair("OPERATOR", string(1, c)));
            continue;
        }

        if (isalpha(c) || c == '_') {
            currentToken.clear();
            while (isalpha(c) || isdigit(c) || c == '_') {
                currentToken += c;
                c = code[++i];
            }
            i--;
            tokens.push_back(make_pair(classifyToken(currentToken), currentToken));
            continue;
        }


        if (isdigit(c)) {
            currentToken.clear();
            while (isdigit(c)) {
                currentToken += c;
                c = code[++i];
            }
            i--;
            tokens.push_back(make_pair("NUMBER", currentToken));
            continue;
        }

        tokens.push_back(make_pair("SEPARATOR", string(1, c)));
    }

    return tokens;
}


void printTokens(const vector<pair<string, string>>& tokens) {
    for (const auto& token : tokens) {
        cout << "Token: " << token.second << ", Type: " << token.first << endl;
    }
}

int main() {
    string code = "int a = 5 + 10; while (a > 0) { a = a - 1; } return a;";


    vector<pair<string, string>> tokens = tokenize(code);


    printTokens(tokens);

    return 0;
}
