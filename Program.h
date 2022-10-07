#include <bits/stdc++.h>
using namespace std;

int nrLines;

class Program
{
private:
    bool error = 0;
    vector<string> output;
    map<string, string> values;

public:
    Program() { Main(); }
    ~Program()
    {
        if (!error)
            for (auto &line : output)
                cout << line;
    }

private:
    enum Type
    {
        PRINT,
        IF,
        WHILE,
        END,
        VAR,
        SET
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
        return END;
    }
    void Main()
    {
        string code;
        cin >> code;
        nrLines--;
        switch (hashIt(code))
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
    void Set();
};
void Program::Error()
{
    cout << "ERROR\n";
    error = 1;
    return;
}
void Program::Print()
{
    string code;
    cin >> code;
    output.push_back(code);
}
void Program::If() {}
void Program::While() {}
void Program::Var()
{
    string name, value;
    cin >> name >> value;
    if (values.find(name) != values.end())
        Error();
    else
        values[name] = value;
}
void Program::Set() {
    string name, value;
    cin >> name >> value;
    if (values.find(name) == values.end())
        Error();
    else
        values[name] = value;
}