//include statements and neccessary packages
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <unordered_set>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

//depth first search through an inputted adjacency list given two people
void DFS(map<string, vector<string>> mapPassed, string person1, string person2)
{
    //starts the clock at the beginnning of the function
    auto start = std::chrono::high_resolution_clock::now();

    //a set marks which nodes are visitied while a stack represents the neighbors of each node/person
    //a counter is initialized to 1 to print each person in alphabetical order based on the traversal
    int counter = 1;
    set<string> visited;
    stack<string> s;

    //first person is inserted into the set and the stack
    visited.insert(person1);
    s.push(person1);

    //they are printed and counter is incremented
    cout << "Depth First Search:" << endl;
    cout << counter << ") " << person1 << endl;
    counter++;

    //while the stack still has items in it pop and push
    while(!s.empty())
    {
        //access the friends of the person at the top of the stack and add them into the stack and the visitied set
        bool doElse = true;
        string top = s.top();
        for (int i = 0; i < mapPassed[top].size(); i++)
        {
            string myFriend = mapPassed[top][i];
            if (visited.count(myFriend) == 0)
            {
                cout << counter << ") " << myFriend << endl;
                counter++;

                //if the traversed friend matches the second inputted person, the program breaks out of the loop and
                //stops printing/traversing
                if (myFriend == person2)
                {
                    break;
                }
                //otherwise continue inserting people into the set and stack
                visited.insert(myFriend);
                s.push(myFriend);
                doElse = false;
                break;
            }
        }

        //pop people off the stack if the boolean is true and continue
        if (doElse)
        {
            s.pop();
        }
    }

    //clock is stopped, duration is calculated and printed
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken for Depth First Search to execute in microseconds: " << duration.count() << endl;
}

//performs a breadth first search using an inputted adjacency list given two people
void BFS (map <string, vector<string>> mapPassed, string person1Passed, string person2Passed) {
    //starts the clock at the beginnning of the function
    auto start = std::chrono::high_resolution_clock::now();

    //once again, a set marks which people have been visited and a queue is used to track the neighbors
    //a counter is initialized to 1 to print each person in alphabetical order based on the traversal
    int counter = 1;
    std::set<string> visitedPeople;
    std::queue<string> tempPeopleQ;

    //the first person that is inputted is inserted into the set and pushed into the queue
    visitedPeople.insert(person1Passed);
    tempPeopleQ.push(person1Passed);

    cout << "Breadth First Search: " << endl;

    //while the queue is not empty, push and pop neighbors from the queue
    while(!tempPeopleQ.empty())
    {
        //a temporary variable is assigned to the person at the front of the queue
        string person = tempPeopleQ.front();

        //if the temporary variable node is equal to the second inputted person, print person and break out of program
        if (person == person2Passed) {
            cout << counter << ") " << person << endl;
            counter++;
            break;
        }

        //otherwise pop the person off the queue and increment the counter
        else {
            cout << counter << ") " << person << endl;
            counter++;
            tempPeopleQ.pop();
        }

        //set the neighbors vector equal to the friends of the person and sort the vector
        vector<string> neighbors = mapPassed[person];
        std::sort(neighbors.begin(), neighbors.begin() + neighbors.size());

        //for each item in the neighbor, insert the item with no neighbors into the vector and the set
        for(string v: neighbors)
        {
            if(visitedPeople.count(v) == 0)
            {
                visitedPeople.insert(v);
                tempPeopleQ.push(v);
            }
        }
    }

    //stop clock and calculate the duration of the function
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken for Breadth First Search to execute in microseconds: " << duration.count() << endl;
}

//heap code, we didn't end up using this!
void heapifyUp(pair<string, int> a[], int& size, int index)
{
    int parentIndex = (index - 1) / 2;

    if (a[index].second >= a[parentIndex].second)
    {
        swap(a[index], a[parentIndex]);
        heapifyUp(a, size, parentIndex);
    }
}

void insertHeap(pair<string, int> a[], int& size, pair <string, int> pairPassed)
{
    a[size - 1].first = pairPassed.first;
    a[size - 1].second = pairPassed.second;
    size++;

    heapifyUp(a, size, size - 1);
}


int main() {
    //necessary data structures and variables
    map<string, vector<string>> mapOfFriends;
    vector<string> associatedFriends;
    string tempName = "";
    string exampleFriend = "";
    string numberOfInputs;


    //reads in sample data file with over 100,100 nodes
    fstream file("project 3 small graph csv.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line))
        {
            // MAKE GRAPH
            tempName.clear();
            istringstream stream(line);
            getline(stream, tempName, ',');
            mapOfFriends[tempName];

            //creates graph with first word in each line as name and all the following values as friends in the vector
            while (getline(stream, exampleFriend, ','))
            {
                mapOfFriends[tempName].push_back(exampleFriend);
            }
        }
    }


    //print intro menu
    cout << "***********************************" << endl;
    cout << "*          GATOR CONNECT          *" << endl;
    cout << "***********************************" << endl;
    cout << "GatorConnect is designed to help you find mutual friends to expand your social circle and to find out how other students are connected with each other." << endl;
    cout << endl;
    //ask user for number of operations to perform
    cout << "Input how many operations you wish to perform: " << endl;
    getline(cin, numberOfInputs);
    int temp = stoi(numberOfInputs);
    while (temp != 0) {

        //print menu and ask for user input temp number of times
        cout << "Menu:" << endl;
        cout << "1) Find out how 2 gators are connected using Breadth First Search" << endl;
        cout << "2) Find out how 2 gators are connected using Depth First Search" << endl;
        cout << "3) Find how many friends a gator has" << endl;
        cout << "4) Exit program" << endl;
        cout << endl;

        //take in user input for menu options
        cout << "Enter a menu option to proceed:" << endl;
        string menuOption;
        getline(cin, menuOption);
        cout << endl;

        // if 1 is entered, perform BFS between two people and output execution time
        if (menuOption == "1") {
            cout << "Please enter Person 1's name: " << endl;
            string person1;
            getline(cin, person1);
            cout << endl;
            cout << "Please enter Person 2's name: " << endl;
            string person2;
            getline(cin, person2);
            cout << endl;

            BFS(mapOfFriends, person1, person2);
            cout << endl;
            temp --;
        }

        //if two is entered, perform DFS between two people and output execution time
        else if (menuOption == "2") {
            cout << "Please enter Person 1's name: " << endl;
            string person1;
            getline(cin, person1);
            cout << endl;
            cout << "Please enter Person 2's name: " << endl;
            string person2;
            getline(cin, person2);
            cout << endl;

            DFS(mapOfFriends, person1, person2);
            cout << endl;
            temp --;
        }

        // if 3 is entered, input a gator and find how many friends they have
        // prints size of vector associated with each key
        else if (menuOption == "3") {
            string tempName;
            cout << "Enter a gator to find how many friends they have: " << endl;
            getline(cin, tempName);
            cout << tempName << " has " << mapOfFriends[tempName].size() << " friends!" << endl;
            cout << endl;
            temp --;
        }

        // if 4 is entered, exit out of the program
        else if (menuOption == "4") {
            exit(0);
        }
    }

    return 0;
}
