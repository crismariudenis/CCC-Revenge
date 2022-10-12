#include <bits/stdc++.h>
using namespace std;

int nrLines;

class Program
{

private:
    bool error = false;
    vector<string> output;
    map<string, string> variables;

public:
    Program() { Main(); }
    ~Program()
    {
        if (!error)
            for (const auto &line : output)
                cout << line;
        cout << '\n';
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

public:
    void debug()
    {
        for (const auto &[key, value] : variables)
            cout << key << " " << value << " ";
        cout << '\n';
    }
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
    if (variables.find(code) != variables.end())
        output.push_back(variables[code]);
    else
        output.push_back(code);
}
void Program::If()
{
    string code;
    cin >> code;

    if (code == "true")
        Program smallP = *this;
    else
        while (code != "end")
            cin >> code;
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