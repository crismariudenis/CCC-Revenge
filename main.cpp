#include <bits/stdc++.h>
using namespace std;
int nrLines;

class Program
{

public:
    Program() { Main(); }

private:
    enum Type
    {
        PRINT,
        IF,
        WHILE,
        END
    };
    Type hashIt(string const &s)
    {
        if (s == "print")
            return PRINT;
        if (s == "if")
            return IF;
        if (s == "while")
            return WHILE;
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
        case END:
            return;
        }
       
        Main();
    }
    void Print()
    {
        string code;
        cin >> code;
        cout << code;
    };
    void If(){};
    void While(){};
};

signed main()
{
    cin >> nrLines;
    while (nrLines)
    {
        string code;
        cin >> code;
        nrLines--;
        if (code == "start")
            Program p;
    }
}