#include <iostream>
#include <string>
using namespace std;

void tokenize(string input){
    char *start = &input[0];
    char *forward = &input[0];

    while (*forward !='\0')
    {

        if (*forward == ' ')
        {
            forward++;
            start = forward;
        }


        else if(isdigit(*forward)){
            start = forward;

            while (isdigit(*forward))
                forward++;

            cout << "Number: ";
            while (start < forward)
            {
                cout <<*start;
                start++;
            }
            cout<<endl;
        }


        else if (isalpha(*forward))
        {
            start = forward;

            while (isalpha(*forward))
                forward++;

            string word = "";
            char *temp = start;

            while (temp < forward)
            {
                word += *temp;
                temp++;
            }

            if (word == "cout" || word == "cin" ||
                word == "int" || word == "float" ||
                word == "double")
            {
                cout<< "Keyword: " << word << endl;
            }
              else{
                cout << "Identifier: " << word << endl;
            }
        }


        else if (*forward == '<' && *(forward + 1) == '<')
        {
            cout << "Operator: <<" << endl;
            forward += 2;
        }


        else if (*forward == '>' && *(forward + 1) == '>'){
            cout << "Operator: >>" << endl;

            forward += 2;
        }


        else if (*forward== '+' || *forward== '-' ||
                 *forward == '*' || *forward== '/' ||
                 *forward == '=')
        {
            cout << "Operator: " << *forward << endl;
            forward++;
        }

        else if (*forward == ';' || *forward == ',' ||
                 *forward == '(' || *forward == ')')
        {
            cout << "Punctuation: " << *forward << endl;
            forward++;
        }

        else{
            cout << "Lexical Error: " << *forward << endl;
            forward++;
        }
    }
}

int main()
{
    string input = "cout << 20 + student * 60 ;";
    tokenize(input);
    return 0;
}
