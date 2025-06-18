#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

// Adding colrs to terminal
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;2;255;165;0m"
#define PINK "\033[38;2;255;182;193m"
using namespace std;
int row = 8;
int col = 10;
vector<vector<int>> arr(row, vector<int>(col, 0)); // declaring the 2d array for the grid
class nodeHistory
{
public:
    string data;
    nodeHistory *next;
    nodeHistory(string op)
    {
        data = op;
        next = NULL;
    }
};

class QueueHistory
{
    nodeHistory *front;

public:
    int count = 0;
    QueueHistory()
    {
        front = NULL;
    }
    void enQueue(string val)
    {
        count++;
        nodeHistory *n = new nodeHistory(val);
        if (front == NULL)
        {
            front = n;
            return;
        }
        n->next = front;
        front = n;
    }
    //
    string deQueue()
    {
        string temp = front->data;
        front = front->next;
        return temp;
    }

    void displayHistory()
    {
        nodeHistory *temp = front;
        int i = count;
        cout << RED << "HISTORY of recent action" << RESET << endl;
        while (temp != NULL)
        {
            cout << RED << i-- << ". " << YELLOW << temp->data << RESET << endl;
            temp = temp->next;
        }
        cout << RED << "Thats all till  now" << RESET << endl;
    }
};

// generate the grid
void displayGrid()
{
    // Display the elements
    for (int i = 0; i <= col; i++)
    {
        cout << RED << i << ".\t" << RESET;
    }
    cout << endl;
    // for(int i = 0; i<=col;i++){
    //     cout<<RED<<"-\t"<<RESET;
    // }
    cout << endl;
    // initialized to zero
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << RED << i + 1 << ".\t" << RESET;
        for (int j = 0; j < arr[i].size(); ++j)
        {
            cout << YELLOW << arr[i][j] << RESET << "\t";
        }
        cout << endl
             << endl;
    }
}
void makeNewGrid()
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            arr[i][j] = 0;
        }
    }
    displayGrid();
}
// function for animation
void animation(string operation)
{
    for (int i = 1; i <= 100; i = i + 3)
    {
        Sleep(5);
        system("cls");
        cout << RED << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t" + operation + " " << i << "%" << RESET << endl;
        if (i == 100)
            Sleep(2000);
    }
}
void loadingScreen()
{
    cout << GREEN << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMINI EXCEL SHEET" << RESET;
    Sleep(3000);
    system("cls");
    for (int i = 1; i <= 100; ++i)
    {
        Sleep(5);
        system("cls");
        cout << RED << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING " << i << "%" << RESET << endl;
        if (i == 100)
            Sleep(2000);
    }
    system("PAUSE");
    system("cls");
}
// check a cell existed or not
int check(int r1, int c1)
{
    if (r1 > row || c1 > col)
    {
        cout << ORANGE << "\t\t Wrong Input Cell Does not exist \t" << RESET << endl;
        getch();
        return -1;
    }
    return 1;
}
// SET a cell
void setCell()
{
    int r;
    int c;
    cout << ORANGE << "Input the row and col of cell to Set \t" << RESET << endl;
    cin >> r >> c;
    if (check(r, c) == -1) // checking if the given cell address existy
        return;
    else
    {
        cout << ORANGE << "\t\t Enter the data = " << RESET;
        int data;
        cin >> data;
        arr[r - 1][c - 1] = data;
    }
}
// to delete a cell
void delCell()
{
    int r;
    int c;
    cout << ORANGE << "Input the row and col of cell to Delete \t" << RESET << endl;
    cin >> r;
    cin >> c;

    if (check(r, c) == -1) // checking if the given cell address exist
        return;
    else
    {
        arr[r - 1][c - 1] = 0;
    }
}
// check the cell address exist or not
// sort by the row or column
// Sort the grid
void sortGrid()
{
    cout << "For ROW Press:1 for Column Press:2" << endl;
    int sortByRow;
    cin >> sortByRow;
    cout << "Enter the Starting Index" << endl;
    int index;
    cin >> index;
    if (sortByRow == 1)
    {
        sort(arr[index - 1].begin(), arr[index - 1].end());
    }
    else
    {
        vector<int> column;
        for (int i = 0; i < arr.size(); ++i)
        {
            column.push_back(arr[i][index - 1]);
        }

        sort(column.begin(), column.end());

        for (int i = 0; i < arr.size(); ++i)
        {
            arr[i][index - 1] = column[i];
        }
    }

    cout << ORANGE << "\nGrid sorted successfully.\n"
         << RESET;
}
// copy paste
void copyPaste()
{
    int r1, c1, r2, c2;
    cout << ORANGE << "Input the row and col of the cell to copy: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of the cell to paste: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r1, c1) == -1)
        return;

    arr[r2 - 1][c2 - 1] = arr[r1 - 1][c1 - 1];
}
// cut pate
void cutPaste()
{
    int r1, c1, r2, c2;
    cout << ORANGE << "Input the row and col of the cell to cut: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of the cell to paste: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r1, c1) == -1)
        return;

    arr[r2 - 1][c2 - 1] = arr[r1 - 1][c1 - 1];
    arr[r1 - 1][c1 - 1] = 0;
}
// save to file
void saveToFile(const string &filename)
{
    string filePath = "C:/Users/Abdullah ilyas/Desktop/DSA/" + filename;
    ofstream outFile(filePath);

    if (outFile.is_open())
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = 0; j < arr[i].size(); ++j)
            {
                outFile << arr[i][j] << " ";
            }
            outFile << "\n";
        }
        // for displaying animation
        animation("SAVING");
        cout << ORANGE << "\t\t\t\t\t\t\t\tGrid saved to file successfully.\n"
             << RESET;
    }
    else
    {
        cerr << RED << "Error: Unable to open the file for saving.\n"
             << RESET;
    }

    outFile.close();
}
// load from file
void loadFromFile(const string &filename)
{
    string filePath = "C:/Users/Abdullah ilyas/Desktop/DSA/" + filename;
    ifstream inFile(filePath);

    if (inFile.is_open())
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = 0; j < arr[i].size(); ++j)
            {
                inFile >> arr[i][j];
            }
        }
        // animmation
        animation("DOWNLOADING");
        cout << ORANGE << "\t\t\t\t\t\t\t\tGrid loaded from file successfully.\n"
             << RESET;
    }
    else
    {
        cerr << RED << " Unable to open the file for loading.\n"
             << RESET;
    }

    inFile.close();
}
// having all arthimetic functions
void sum()
{
    int r1, c1, r2, c2, r3, c3;
    cout << ORANGE << "Input the row and col of 1st cell: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of 2nd cell: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r2, c2) == -1)
        return;
    cout << ORANGE << "Input the row and col of to store Output: " << RESET << endl;
    cin >> r3 >> c3;
    if (check(r3, c3) == -1)
        return;

    arr[r3 - 1][c3 - 1] = arr[r2 - 1][c2 - 1] + arr[r1 - 1][c1 - 1];
}
// subtratction
void sub()
{
    int r1, c1, r2, c2, r3, c3;
    cout << ORANGE << "Input the row and col of 1st cell: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of 2nd cell: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r2, c2) == -1)
        return;
    cout << ORANGE << "Input the row and col of to store Output: " << RESET << endl;
    cin >> r3 >> c3;
    if (check(r3, c3) == -1)
        return;

    arr[r3 - 1][c3 - 1] = arr[r2 - 1][c2 - 1] - arr[r1 - 1][c1 - 1];
}
// Multiply
void multi()
{
    int r1, c1, r2, c2, r3, c3;
    cout << ORANGE << "Input the row and col of 1st cell: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of 2nd cell: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r2, c2) == -1)
        return;
    cout << ORANGE << "Input the row and col of to store Output: " << RESET << endl;
    cin >> r3 >> c3;
    if (check(r3, c3) == -1)
        return;
    arr[r3 - 1][c3 - 1] = arr[r2 - 1][c2 - 1] * arr[r1 - 1][c1 - 1];
}
// divides
void divide()
{
    int r1, c1, r2, c2, r3, c3;
    cout << ORANGE << "Input the row and col of 1st cell: " << RESET << endl;
    cin >> r1 >> c1;
    if (check(r1, c1) == -1)
        return;
    cout << ORANGE << "Input the row and col of 2nd cell: " << RESET << endl;
    cin >> r2 >> c2;
    if (check(r2, c2) == -1)
        return;
    cout << ORANGE << "Input the row and col of to store Output: " << RESET << endl;
    cin >> r3 >> c3;
    if (check(r3, c3) == -1)
        return;

    arr[r3 - 1][c3 - 1] = arr[r2 - 1][c2 - 1] / arr[r1 - 1][c1 - 1];
}

void menu()
{
    bool state = true;
    while (state)
    {
        system("cls");
        displayGrid();
        cout << PINK << "\nFUNCTIONS:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Exit to Main Menu" << endl;
        cout << "Enter your choice: " << RESET;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sum();
            displayGrid();
            break;
        case 2:
            sub();
            displayGrid();
            break;
        case 3:
            multi();
            displayGrid();
            break;
        case 4:
            divide();
            displayGrid();
            break;
        case 5:
            sortGrid();
            displayGrid();
            break;
        case 6:
            state = false;
            break;
        default:
            cout << "Wrong Selection of Option" << endl;
            getch();
        }
    }
}
// Creating of undo function in ana array
class node
{
public:
    vector<vector<int>> data;
    node *next;

    node(vector<vector<int>> &arr)
    {
        data = arr;
        next = NULL;
    }
};
// stack class
class STACK
{
    node *top;

public:
    STACK()
    {
        top = NULL;
    }

    void push(vector<vector<int>> &arr)
    {
        node *n = new node(arr);
        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }

    vector<vector<int>> pop()
    {
        if (top != NULL)
        {
            node *temp = top;
            top = top->next;
            return temp->data;
        }
    }
    vector<vector<int>> TOP()
    {
        return top->data;
    }

    node *toop()
    {
        return top;
    }
};

int main()
{
    STACK *undoStack;
    QueueHistory stack;
    system("cls");
    loadingScreen();
    bool state = true;
    while (state)
    {
        cout << PINK << "Choose from the options below" << endl;
        cout << "1. Make new sheet" << endl;
        cout << "2. Set Cell" << endl;
        cout << "3. Delete Cell" << endl;
        cout << "4. Copy Paste" << endl;
        cout << "5. Cut Paste" << endl;
        cout << "6. Apply arthimetic functions" << endl;
        cout << "7. Save the Sheet" << endl;
        cout << "8. Load Existing Sheet" << endl;
        cout << "9. Undo" << endl;
        cout << "10.History of Actions" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: " << RESET;
        cout << endl;
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            stack.enQueue("NEW SHEET...");
            makeNewGrid();
            break;
        case 2:
            stack.enQueue("SET CELL...");
            undoStack->push(arr);
            setCell();
            displayGrid();
            break;
        case 3:
            stack.enQueue("DELETE CELL...");
            undoStack->push(arr);
            delCell();
            displayGrid();
            break;
        case 4:
            stack.enQueue("COPY PASTE...");
            undoStack->push(arr);
            copyPaste();
            displayGrid();
            break;
        case 5:
            stack.enQueue("CUT PASTE...");
            undoStack->push(arr);
            cutPaste();
            displayGrid();
            break;
        case 6:
            stack.enQueue("ARTHEMATIC OPERATION...");
            undoStack->push(arr);
            menu();
            break;
        case 7:
            stack.enQueue("SAVED FILE...");
            saveToFile("excel.txt");
            break;
        case 8:
            stack.enQueue("LOADED FILE...");
            undoStack->push(arr);
            loadFromFile("excel.txt");
            displayGrid();
            break;
        case 9:
            stack.enQueue("UNDO ...");
            arr = undoStack->pop();
            break;
        case 10:
            stack.displayHistory();
            getch();
            break;
        case 11:
            state = false;
            break;

        default:
            cout << RED << "Invalid Option.. Try agian" << RESET << endl;
            getch();
        }
        system("cls");
        displayGrid();
    }
    system("cls");
    cout << RED << "\n\n\n\t\t\t\t\t\t\t\tSEE YOU LATER" << RESET << endl;

    return 0;
}