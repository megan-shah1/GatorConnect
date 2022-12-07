#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

int main() {
    //create a csv file to read in data
    ofstream myFile;
    myFile.open("names.csv"); //names friends

    //word bank with developer inputted first names
    vector<string> firstNames = {"Tara" ,"Gisselle", "Axel", "Nathanial", "Wendy", "Anya", "Landon", "Macie", "Chaya" ,"Sienna",
                                 "Luciana", "Amber", "Nina", "Jordyn", "Xiomara", "Elena", "Mina", "Ezra",
                                 "Saul", "Yasmine", "Bernard", "Jade", "Mckayla", "Madison", "Ahmend", "Janet",
                                 "Gavven", "Ian", "Ryleigh", "Kaeden", "Caylee", "Arielle", "Lara", "Abigail", "Kamrym",
                                 "Tiana", "Carolyn", "Adrien", "Mitchell", "Katelyn", "Devyn", "Jaime", "Veronica",
                                 "Giana", "Richard", "Romeo", "Mallory", "Nolan", "Heidi", "Raven", "Francesca",
                                 "Frederick", "Troy", "Kara", "Rafael", "Ayaan", "Dominick", "Coby", "Carly", "Christinia",
                                 "Evelyn", "Juliet", "Carina", "Dwayne", "Kathleen", "Kane", "Mollie", "James", "John",
                                 "Robert", "Michael", "William", "David", "Richard", "Charles", "Joseph", "Thomas",
                                 "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth", "Steven",
                                 "Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason", "Matthew", "Gary", "Timothy",
                                 "Jose", "Larry", "Jeffrey", "Frank", "Scott", "Eric", "Stephen", "Andrew", "Raymond", "Gregory",
                                 "Joshua", "Jerry", "Dennis", "Walter", "Patrick", "Peter", "Harold", "Douglas", "Henry",
                                 "Carl", "Arthur", "Ryan", "Roger", "Joe", "Juan", "Jack", "Albert", "Jonathan", "Justin",
                                 "Terry", "Gerald", "Keith", "Samuel", "Willie", "Ralph", "Lawrence", "Nicholas", "Roy",
                                 "Benjamin", "Bruce", "Brandon", "Adam", "Harry", "Fred", "Wayne", "Billy", "Steve",
                                 "Louis", "Jeremy", "Aaron", "Randy", "Howard", "Eugene", "Carlos", "Russell", "Bobby",
                                 "Victor", "Martin", "Ernest", "Phillip", "Todd", "Jesse", "Craig", "Alan", "Shawn",
                                 "Clarence", "Sean", "Philip", "Chris", "Johny", "Earl", "Jimmy", "Antonio", "Danny",
                                 "Bryan", "Tony", "Olivia", "Emma", "Charlotte", "Amelia", "Ava", "Sophia", "Isabella",
                                 "Mia", "Evelyn", "Harper", "Luna", "Camila", "Gianna", "Elizabeth", "Eleanor", "Ella",
                                 "Abigail", "Sofia", "Avery", "Scarlett", "Emily", "Aria", "Penelope", "Chloe", "Layla",
                                 "Mila", "Nora", "Hazel", "Madison", "Ellie", "Lily", "Nova", "Isla", "Grace", "Violet",
                                 "Aurora", "Riley", "Zoey", "Willow", "Emilia", "Stella", "Zoe", "Victoria", "Hannah",
                                 "Addison", "Leah", "Lucy", "Eliana", "Ivy", "Everly", "Lilian", "Paisley", "Elena",
                                 "Naomi", "Maya", "Natalie", "Kinsley", "Delilah", "Claire", "Audrey", "Aaliyah", "Ruby",
                                 "Brooklyn", "Alice", "Aubrey", "Autumn", "Leilani", "Savannah", "Valentina", "Kennedy",
                                 "Madelyn", "Josephine", "Bella", "Skylar", "Genesis", "Sophie", "Hailey", "Sadie",
                                 "Natalia", "Quinn", "Caroline", "Allison", "Gabriella", "Anna", "Serenity", "Cora", "Ariana",
                                 "Emery", "Lydia", "Jade", "Sarah", "Eva", "Adeline", "Madeline", "Piper", "Rylee", "Athena",
                                 "Peyton", "Vivian", "Clara", "Maria", "Iris", "Julia", "Jasmine"};

    //vector with developer created last names
    vector<string> lastNames = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez",
                                "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor",
                                "Moore", "Jackson", "Martin", "Lee", "Perez", "Thompson", "White", "Harris", "Sanchez",
                                "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young", "Allen", "King", "Wright",
                                "Scott", "Torres", "Nguyen", "Hill", "FLores", "Green", "Adams", "Nelson", "Baker", "Hall",
                                "Rivera", "Campbell", "Mitchell", "Carter", "Roberts", "Gomez", "Phillips", "Evans", "Turner",
                                "Diaz", "Parker", "Cruz", "Edwards", "Collins", "Reyes", "Stewart", "Morris", "Morales", "Murphy",
                                "Cook", "Rogers", "Morgan", "Cooper", "Peterson", "Bailey", "Reed", "Kelly", "Howard",
                                "Ramos", "Kim", "Cox", "Ward", "Richardson", "Watson", "Brooks", "Chavez", "Wood", "James",
                                "Bennett", "Gray", "Mendoza", "Ruiz", "Hughes", "Price", "Alvarez", "Castillo", "Sanders",
                                "Patel", "Myers", "Long", "Ross", "Foster", "Jimenez", "Powell", "Jenkins", "Perry", "Russell",
                                "Sullivan", "Bell", "Coleman", "Butler", "Henderson", "Barnes", "Gonzales", "Fisher",
                                "Vasquez", "Simmons", "Romero", "Jordan", "Patterson", "Alexander", "Hamilton", "Graham",
                                "Reynolds", "Griffin", "Wallace", "Moreno", "West", "Cole", "Hayes", "Bryant", "Herrera",
                                "Gibson", "Ellis", "Tran", "Medina", "Stevens", "Murray", "Ford", "Castro", "Marshall", "Owens"};


    //create each person using a first and last name
    for (int i = 0; i < lastNames.size(); i++)
    {
        for (int j = 0; j < firstNames.size(); j++)
        {
            myFile << firstNames[j] << " " << lastNames[i] << endl;
        }
    }

    //create certain amount of people with middle names

    for (int i = 0; i < 50; i++)
    {
        for (int j = 40; j > 0; j--)
        {
            for (int k = 0; k < 40; k++)
            {
                if (i != j)
                {
                    myFile << firstNames[i] << " " << firstNames[j] << " " << lastNames[k] << endl;
                }
            }
        }
    }
    myFile.close();


    //reopen file and push back each created person into a vector, assign them a random number of friends
    vector<string> people;
    ifstream file;
    file.open("names.csv");
    string line;
    while(getline(file, line))
    {
        people.push_back(line);
    }
    file.close();

    myFile.open("friends.csv");
    srand(time(0));

    /*
    for (int i = 1; i <= 100100; i++)
    {
        int popularity = (rand() % 2000) + 1; // random number from 1 - 2000
        cout << popularity << endl;
        string friends = "";

        for (int j = 0; j <= popularity; j++)
        {
            int person = (rand() % 100100);
            friends += people[person];
            friends += ",";
        }
        friends.pop_back();

        myFile << friends << endl;
    }
     */

    //assigns unique number of friends to each person
    vector<set<int>> friends;

    // assigns friends to each person and puts it in a vector of sets, each set contains the indexes of the friends
    for (int i = 0; i < 100100; i++)
    {
        int popularity = (rand() % 700) + 1; // random number from 1 - 2000 (number of friends each person has)
        set<int> temp;
        for (int j = 0; j <= popularity; j++)
        {
            int person = (rand() % 100100);
            temp.insert(person);
        }
        friends.push_back(temp);
        cout << 100100 - i << endl;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        set<int> :: iterator itr;
        for (itr = friends[i].begin(); itr != friends[i].end(); ++itr)
        {
            friends[*itr].insert(i);
        }
        cout << 100100 - i << endl;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        string line = "";
        line += people[i];
        line += ",";
        set<int> :: iterator itr;
        for (itr = friends[i].begin(); itr != friends[i].end(); ++itr)
        {
            line += people[*itr];
            line += ",";
        }
        //line.pop_back();
        myFile << line << endl;
    }

    myFile.close();
    return 0;

}