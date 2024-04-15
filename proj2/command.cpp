#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Function Prototypes

void InterpretCommands(istream &);

void InterpretUpdate(istream &);

void InterpretList(istream &);

void InterpretBatch(istream &);

void InterpretQuit(istream &);

/**
 * Driver Function
 */
int main()
{
    InterpretCommands(cin);
    return 0;
}

/**
 * Interpret and Validate commands including update, list, batch, quit
 */
void InterpretCommands(istream &cmds)
{
    string line, lineInWord;
    // TODO: Declare other variables here.

    while (getline(cmds, line)) // TODO: Get a line.
    {
        istringstream lineIn(line.c_str());

        if (!(lineIn >> lineInWord)) // TODO: Get the line's first word.
        {
            cerr << "No word in the input command" << endl; // TODO: Do something if there weren't any words.
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate(lineIn);
        }
        else if (lineInWord == "list")
        {
            InterpretList(lineIn);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch(lineIn);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}

/*
 * Update the word with number.
 * The update command must be followed by a word—a sequence of nonblanks—
 * and an integer, with no other nonblank characters on the line.
 * Example: update word number
*/
void InterpretUpdate(istream &input)
{
    cout << "-------"
         << "Update"
         << "-------" << endl;
    string word;
    int number;
    if (input >> word >> number)
    {
        cout << "word: " << word << "\tnumber: " << number << endl;
    }
    else
    {
        cerr << "Invalid input arguments." << endl;
    }

    string temp;
    if (input >> temp)
    {
        cerr << "Too many arguments." << endl;
    }
    return;
}

/*
 * List names and quantities.
 * The list command must be followed by either the word names or the word quantities.
 * Example: list names / list quantities
*/
void InterpretList(istream &input)
{
    cout << "-------"
         << "List"
         << "-------" << endl;
    string word, temp;
    if (input >> word)
    {
        if (word == "names" || word == "quantities")
        {
            if (input >> temp)
            {
                cerr << "Too many arguments." << endl;
            }
            else
            {
                cout << "Successful" << endl;
            }
        }
        else
        {
            cerr << "Arguments must be \"names\" or \"quantities\"" << endl;
        }
    }
    else
    {
        cerr << "Invalid input arguments." << endl;
    }
    return;
}

/**
 * Read, Recognize, and Process commands from the specified file, 
 * then (assuming that a quit command has not been read) resume reading commands from cin. 
 * Assume that the file does not contain any batch commands.
 * The batch command must be followed by the name of an existing file.
 * Example: batch file-name
 */
void InterpretBatch(istream &input)
{
    cout << "-------"
         << "Batch"
         << "-------" << endl;

    string filename;
    if (!(input >> filename))
    {
        cerr << "Not found file name" << endl;
        return;
    }
    else
    {
        ifstream file_stream;
        file_stream.open(filename.c_str());
        if (file_stream.fail())
        {
            cout << "could not open file " << filename << endl;
        }
        else
        {
            InterpretCommands(file_stream);
        }
    }
}

/**
 * Terminate the program. 
 * The quit command must appear by itself on the line.
 * Example: quit
 */
void InterpretQuit(istream &input)
{
    cout << "-------"
         << "Quit"
         << "-------" << endl;
    string temp;
    if (input >> temp)
    {
        cerr << "Too many arguments." << endl;
    }
    exit(1);
}
