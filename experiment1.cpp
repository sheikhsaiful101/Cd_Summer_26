#include <iostream>
#include <string>
using namespace std;

// Task 1
void checkNumeric(string input)
{
    bool isNumeric = true;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] < 48 || input[i] > 57)
        {
            isNumeric = false;
            break;
        }
    }

    if(isNumeric)
        cout << "This Number Is A Numeric Constant";
    else
        cout << "This Number Is Not A Numeric Constant";
}

// Task 2
void checkOperator(string input)
{
    int b = 0;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == 43 ||
           input[i] == 45 ||
           input[i] == 42 ||
           input[i] == 47 ||
           input[i] == 37 ||
           input[i] == 61)
        {
            b++;
            cout << "Operator " << b << " : " << input[i] << endl;
        }
    }
}

// Task 3
void checkComment(string str)
{
    if(str.length() >= 2)
    {
        if(str[0] == 47 && str[1] == 47)
            cout << "Single Line Comment";

        else if(str[0] == 47 && str[1] == 42)
            cout << "Multi Line Comment";

        else
            cout << "Not a Comment";
    }
    else
    {
        cout << "Not a Comment";
    }
}

// Task 4
bool isIdentifier(string str)
{
    if(!((str[0] >= 65 && str[0] <= 90) ||
         (str[0] >= 97 && str[0] <= 122) ||
          str[0] == 95))
    {
        return false;
    }

    for(int i = 1; i < str.length(); i++)
    {
        if(!((str[i] >= 65 && str[i] <= 90) ||
             (str[i] >= 97 && str[i] <= 122) ||
             (str[i] >= 48 && str[i] <= 57) ||
              str[i] == 95))
        {
            return false;
        }
    }

    return true;
}

// Task 5
double findingAverage(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return (double)sum / size;
}

// Task 6
void findMinMax(int arr[], int size)
{
    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
}

// Task 7
string fullName(string firstName, string lastName)
{
    return firstName + " " + lastName;
}

int main()
{
    int choice;

    cout << "                                            ==**************** MENU *****************==" << endl<<endl;
    cout << "1. Numeric Constant Check" << endl;
    cout << "2. Operator Check" << endl;
    cout << "3. Comment Check" << endl;
    cout << "4. Identifier Check" << endl;
    cout << "5. Average of Array" << endl;
    cout << "6. Min and Max of Array" << endl;
    cout << "7. Full Name Concatenation" << endl;
    cout<< endl;
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        string input;

        cout << "Enter a text: ";
        cin >> input;

        checkNumeric(input);
    }

    else if(choice == 2)
    {
        string input;

        cout << "Enter an expression: ";
        cin >> input;

        checkOperator(input);
    }

    else if(choice == 3)
    {
        string input;

        cin.ignore();

        cout << "Enter text: ";
        getline(cin, input);

        checkComment(input);
    }

    else if(choice == 4)
    {
        string input;

        cout << "Enter Identifier: ";
        cin >> input;

        if(isIdentifier(input))
            cout << "Valid Identifier";
        else
            cout << "Invalid Identifier";
    }

    else if(choice == 5)
    {
        int size;

        cout << "Enter Array Size: ";
        cin >> size;

        int arr[size];

        for(int i = 0; i < size; i++)
        {
            cout << "Enter Element " << i + 1 << " : ";
            cin >> arr[i];
        }

        cout << "Average = " << findingAverage(arr, size);
    }

    else if(choice == 6)
    {
        int size;

        cout << "Enter Array Size: ";
        cin >> size;

        int arr[size];

        for(int i = 0; i < size; i++)
        {
            cout << "Enter Element " << i + 1 << " : ";
            cin >> arr[i];
        }

        findMinMax(arr, size);
    }

    else if(choice == 7)
    {
        string firstName, lastName;

        cout << "Enter First Name: ";
        cin >> firstName;

        cout << "Enter Last Name: ";
        cin >> lastName;

        cout << "Full Name: " << fullName(firstName, lastName);
    }

    else
    {
        cout << "Invalid Choice!";
    }

    return 0;
}
