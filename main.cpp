// we will create our project here

#include "pch.h"

using namespace std;
 
 //functions
void main_program();
void asia();
int inputvalidation();
void africa();
void north_america();
void south_america();
void europe();

void main_menu();

//global variables
int choice, // used in the menue function
choice2; // used in asia function
string adish;
// used to read files
ifstream infile1; 
// used to read user input... extra
//string user_string_num0 = "";

int main()
{
    // will show menu to user
    main_menu();

    // input validation
    do
    {
        choice = inputvalidation();

    }while(choice <= 0 || choice > 5);
    
    //switch statementf for regions of food
    switch (choice)
    {
    case 1:
    {
        africa();
    }
    break;
    case 2:
    {
        asia();
    }
    break;
    case 3:
    {
        europe();
    }
    break;
    case 4:
    {
        south_america();
    }
    break;
    case 5:
    {
        north_america();
    }
    break;
    default:
    {
        cout << "\nPlease enter a valid choice\n\n";
        return 0;
    }
    }

    return 0;

}




void africa()
{
    cout << "African Dishes\n"
        << setw(15) << setfill('-') << " " << endl
        << "Select For Recipe:\n"
        <<"\n==PORK===\n";
    cout << "1 - West African Ribs\n"
        <<"2 - Pork & Peanut Stew\n"
        <<"3 - Tenderloins\n"
        <<"4 - Spicy North African Kebabs\n"
        <<"5 - Haitian Pork Griot\n"
        << ">>> ";
    choice2 = inputvalidation();

    switch (choice2)
    {
    case 1:
    {
        int count = 0;
        infile1.open("West_African_Ribs.txt"); // or fstream file to read

        //check for error
        if (infile1.fail())
        {
            cerr << "Error openning file" << endl;
            exit(1);
        }

        while (!infile1.eof())
        {
            getline(infile1, adish);
            cout << adish << endl;
            count++;
        }

        //cout << endl << count << " items found" << endl << endl;
    }
    break;
    case 2:
    {
        int count = 0;
        infile1.open("Nigerian Beef Stew.txt"); // or fstream file to read

        //check for error
        if (infile1.fail())
        {
            cerr << "Error openning file" << endl;
            exit(1);
        }

        while (!infile1.eof())
        {
            getline(infile1, adish);
            cout << adish << endl;
            count++;
        }

        cout << endl << count << " items found" << endl << endl;
    }break;

    default:
    {
        cout << "\n\nPlease enter a valid choice\n\n";
    }

    }
}




//asia main menu
void asia()
{
    cout << "nothing yet\n";
}


//europe main menu
void europe()
{
    cout << "nothing yet\n";
}

//south america main menu
void south_america()
{
    cout << "nothing yet\n";
}

// north america main menu
void north_america()
{
    cout << "nothing yet\n";
}


// main menu of the program
void main_menu()
{
    cout << right << setw(14) << setfill(' ') << endl << endl << "FoodX\n";

    cout << right << setw(24) << setfill('-') << " " << endl;

    cout << "| SELECT A REGION     |\n";
    cout << "| [1] - Africa        |\n"
        << "| [2] - North America |\n"
        << "| [3] - Asia          |\n"
        << "| [4] - Europe        |\n"
        << "| [5] - South America |\n";
    cout << right << setw(24) << setfill('-') << " " << endl;
    cout << ">>> ";
}

// this function checks for input validation.
int inputvalidation()
{
    string user_string_num = "";

    int is_num = 0,
        decimal_count = 0,
        user_converted_num;

    bool is_num_bool = 0,
        contains_spaces = false;

    do
    {
        cout << "Enter a choice: ";
        getline(cin, user_string_num);


        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isspace(user_string_num[i]))
                contains_spaces = true;
        }

        if (user_string_num[0] == '-') // -8
        {
            is_num++;

            if (user_string_num[1] == '0') // -0999 invalid
                is_num = 0;
        }

        if ((user_string_num[0] == '0' && isdigit(user_string_num[1]))) // 0934939
            is_num = 0;
        else
        {
            for (int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;
                if (user_string_num[i] == '.')
                    decimal_count++;
            }
        }

        if (decimal_count == 1) // 66.7 // 8..9.9.9..9.9
            is_num = 0;

        if (is_num == user_string_num.size() && contains_spaces == false)
        {
            stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;

            is_num_bool = 1;

            main_program();
        }
        else
        {
            cout << endl
                << "Number must NOT contain spaces.\n"
                << "Number must NOT contain letters.\n"
                << "Number must NOT contain symbols.\n"
                << "Number must NOT be a decimal number.\n"
                << endl;

            is_num_bool = 0;
            is_num = 0;
            decimal_count = 0;
            contains_spaces = false;

        }

    } while (is_num_bool == 0);

    return user_converted_num;


}

void main_program()
{
    // cout << "great job!\n";
}