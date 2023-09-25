#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Function Prototypes
void getData();
void bubbleSort(vector<int> creditCardData, int size, int value);
int binarySearch(int first, int last, int value, vector<int> creditCardData);
void swap(int& a, int& b);
void checking(int binarySearchResult);

// creditCard Data Vector
vector<int> creditCardData;


int main()
{
    bool working = true;
    int inputCreditCard;
    char work;

    getData();
    int size = creditCardData.size();
   
    
    // Starter output
    cout << "\nCredit Card Account Checker ... " << endl;

    do {
        
        cout << "\nEnter a 7-digit account number:\t";
        cin >> inputCreditCard;
        bubbleSort(creditCardData, size, inputCreditCard);
        cout << "\nWould you like to check another account number (y/n)?\t"; 
        cin >> work;
        if (work == 'y') { 
            working = true;
        }
        else {
            cout << "\nGood Bye ...";
            working = false;
        }
    } while (working);
}

// A function that opens up file accNumbers.txt, puts it in a vector and closes the file.
void getData() {
    ifstream dataIn;
    dataIn.open("accNumbers.txt");
    string line;

    while (getline(dataIn, line)) {
        istringstream iss(line);
        int n;
        while (iss >> n)
        {
            creditCardData.push_back(n);
        }
    }

    dataIn.close();
}

// A function that sorts the data into ascending order.
void bubbleSort(vector<int> creditCardData, int size, int value) {
    int maxElement; 
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (creditCardData[index] > creditCardData[index + 1])
            {
                swap(creditCardData[index], creditCardData[index + 1]);
            }
        }
    }

    checking(binarySearch(0, (size - 1), value, creditCardData));
        
}

// A function that aids the sorting function to swap the values throughout the vector.
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// A function that gives the location of the value if it is found in the vector.
int binarySearch(int first, int last, int value, vector<int> creditCardData) {
    bool found = false;
    int position = -1;

    while (found == false && first <= last) {
        int midpoint = (first + last) / 2;
        if (creditCardData[midpoint] == value) {
            found = true;
            position = midpoint;
        }
        else if (creditCardData[midpoint] > value) {
            last = midpoint - 1;
        }
        else {
            first = midpoint + 1;
        }
    }
   
    return position;
}

// A function that reports if the credit card is valid or invalid to the user
void checking(int binarySearchResult) {
    if (binarySearchResult == -1)
    {
        cout << "=> The credit card number is invalid." << endl;
    }
    else {
        cout << "=> The credit card number is valid." << endl;
    }
}