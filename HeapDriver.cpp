//***************************************************************************
//	Driver File for Templated Binary Heap
//	Programmed by: Houston Brown
//	Last Compiled Date: 7/31/2022
//***************************************************************************

#include "BinaryHeap.h"
#include <limits>
#include <sstream>



void printMenu();

template <class T>
void choose(BinaryHeap<T> &myHeap);

template <class T>
T validateInput(T &value);



int main()
{
	BinaryHeap<int> myHeap;
	printMenu();
	choose(myHeap);
	
	return 0;
}





//***************************************************************************
//		Function to display the available options to the user.
//
//	Parameters:
//		N/A.
//***************************************************************************

void printMenu()
{
    cout << " _____________________________" << endl;
    cout << "| +Item  | Insert Item        | " << endl;
	cout << "|   -    | Delete Item        | " << endl;
    cout << "| ?Item  | Search Item        | " << endl;
    cout << "|   @    | Extract Min Value  | " << endl;
	cout << "|   D    | Destory the Heap   | " << endl;
    cout << "|________|____________________| " << endl << endl;
    cout << "Please choose an operation to perform on the heap." << endl;
    cout << "Enter Q to quit." << endl;	
}




//***************************************************************************
//		This function will prompt and accept the user's choice.  If the
//	choice is invalid, a message will be displayed.  Otherwise, the action
//	will be executed and the updated heap will be displayed along with the
//	menu.  The user will continue to be prompted until they enter the 
//	stopping condition.
//
//	Parameters:
//		myHeap: templated binary heap.
//***************************************************************************

template <class T>
void choose(BinaryHeap<T> &myHeap)
{
	T    data;
	char choice;
	bool hasInserted = false;
	
	cout << "\n>> ";
	cin >> choice;
	
	while(choice != 'q' || choice != 'Q')
    {
        switch (choice)
        {
			case '+':
				validateInput(data);
				myHeap.Insert(data);
				hasInserted = true;
				break;
				
			case '-':
				if (hasInserted)
			    	myHeap.Delete();
				else
				{
					cerr << "\nPlease insert data into the heap." << endl;
					system("pause");
				}
				break;
				
			case '?':
				if (hasInserted)
				{
	                validateInput(data);
	                if (myHeap.Search(data))
						cout << endl << data << " is in the heap!" << endl;
					else
						cerr << endl << data << " is not in the heap." << endl;
					system("pause");
				}
				else
				{
					cerr << "\nPlease insert data into the heap." << endl;
					system("pause");
				}
				break;
				
			case '@' :
				if (hasInserted)
				{
					cout << "\nThe minimum value is: " << myHeap.GetMin();
					cout << endl;
					system("pause");
				}
				else
				{
					cerr << "\nPlease insert data into the heap." << endl;
					system("pause");
				}
				break;
				
			case 'd': case 'D':
				if (hasInserted)
				{
					myHeap.Clear();
					hasInserted = false;
					system("pause");
				}
				else
				{
					cerr << "\nPlease insert data into the heap." << endl;
					system("pause");
				}
				break;
				
            case 'q': case 'Q':
                exit(1);
                
			default:
				cout << "\nInvalid choice. Please try again." << endl;
				cout << endl;
                system("pause");
		}
        system("cls");
        printMenu();
        cout << endl;
        
        if (hasInserted)
        	myHeap.Print();
        cout << ">> ";
        cin >> choice;
    }
}
/* End of choose function */




//***************************************************************************
//		This function will validate the input from the user.  If the user
//	enters an invalid option for the value, then a message will be displayed
//	and the user will be asked to try again.  Otherwise, the function will
//	return the value to the caller.
//
//	Parameters:
//		value: the value entered by the user.
//***************************************************************************

template <class T>
T validateInput(T &value)
{
	while (true)
	{
		if (cin >> value)
			break;
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			printMenu();
			cerr << endl << "Please enter a valid item for the heap." << endl;
        	cout << endl << ">> value: ";
		}
	}
	return value;
}
