#include <bits/stdc++.h>
using namespace std;

int nrLines;

class Program
{

private:
    bool error = false;
    bool lastIF = false;
    vector<string> output;
    map<string, string> variables;
    bool lastIF=false;

public:
    Program() { Main(); }
    ~Program()
    {
        if (!error)
        {
            for (const auto &line : output)
                cout << line;
            cout << '\n';
        }
    }
    Program(const Program &p)
    {
        variables = p.variables;
        Main();
    }

private:
    enum Type
    {
        PRINT,
        IF,
        WHILE,
        END,
        VAR,
        SET,
        ELSE
    };
    Type hashIt(string const &s)
    {
        if (s == "print")
            return PRINT;
        if (s == "if")
            return IF;
        if (s == "while")
            return WHILE;
        if (s == "var")
            return VAR;
        if (s == "set")
            return SET;
        if (s == "else")
            return ELSE;
        return END;
    }

    void Main()
    {
        string token;
        cin >> token;
        nrLines--;
        lastIF = false;
        switch (hashIt(token))
        {
        case PRINT:
            Print();
            break;
        case IF:
            If();
            break;
        case WHILE:
            While();
            break;
        case VAR:
            Var();
            break;
        case SET:
            Set();
            break;
        case ELSE:
            Else();
            break;
        case END:
            return;
        }
        Main();
    }
    void Print();
    void If();
    void While();
    void Error();
    void Var();
    void Else();
    void Set();
    void LoopThroughEnd(string &token);
};
void Program::Error()
{
    cout << "ERROR";
    error = 1;
    return;
}
void Program::LoopThroughEnd(string &token)
{

    //Todo: Read lines not just strings
    while (token != "end")
    {
        cin >> token;
        nrLines--;
    }
    nrLines--;
}
void Program::Print()
{
    string token;
    cin >> token;
    if (variables.find(token) != variables.end())
        output.push_back(variables[token]);
    else
        output.push_back(token);
}
void Program::Else()
{
    //Todo
    if (lastIF == false)
        Program smallP = *this;
    else{

    }
}
void Program::If()
{
    string token;
    cin >> token;
    if ((variables.find(token) != variables.end() && variables[token] == "true") || token == "true")
    {
        lastIF = true;
        Program smallP = *this;
    }
    else
    {
        lastIF = false;
        LoopThroughEnd(token);
    }
}
void Program::Else()
{
    string token;
    cin >> token;
    while (token != "end")
        cin >> token;
}
void Program::While() {}
void Program::Var()
{
    string name, value;
    cin >> name >> value;
    if (variables.find(name) != variables.end())
        Error();
    else
        variables[name] = value;
}
void Program::Set()
{
    string name, value;
    cin >> name >> value;
    if (variables.find(name) == variables.end())
        Error();
    else
        variables[name] = value;
}