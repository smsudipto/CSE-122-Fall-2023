#include <bits/stdc++.h>
using namespace std;

bool isKeyword(const string& word) {
    const vector<string> keywords = { "if", "else", "for", "while", "return", "int", "float", "char", "double", "main" };
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

string classifyToken(const string& token) {
    if (isKeyword(token)) {
        return "KEYWORD";
    } else if (isalpha(token[0]) || token[0] == '_') {
        return "IDENTIFIER";
    } else if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
        // Check if it's a floating-point number
        bool hasDecimal = token.find('.') != string::npos;
        return hasDecimal ? "FLOATING VALUE" : "NUMBER";
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

        if (isdigit(c) || (c == '.' && i + 1 < code.length() && isdigit(code[i + 1]))) {
            currentToken.clear();
            if (c == '.') {
                currentToken += '0'; // Handle cases like ".5" as "0.5"
            }
            while (isdigit(c) || c == '.') {
                currentToken += c;
                c = code[++i];
            }
            i--;
            tokens.push_back(make_pair(classifyToken(currentToken), currentToken));
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
    string code;

    cout << "Enter code: ";
    getline(cin, code);  // Get user input

    vector<pair<string, string>> tokens = tokenize(code);

    printTokens(tokens);

    return 0;
}
