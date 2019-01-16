//Michelle Czyzewicz
//Programming II Game - Take Care of the Baby
//Date: 09/04/2018


#include <iostream>
#include <string>
using namespace std;

//Main Menu
void mainmenu();

//Feed the baby
int baba(int);

//Search Array
int searchList(const int [], int, int);
const int SIZE = 10;

//Selection Sort
void selectionSort(int [], int);

//Show Array
void showArray(const int [], int);

//Pointers and dynamically allocating array integers
int *errandsfunction(int);


int main()
{
	//Assign variables
	string name;
	int age;

	//Output - welcome message
	cout << "Welcome to the game!" << endl;

	//Ask for name, input name
	cout << "What is your name? " << endl;
	cin >> name;
	cout << "It's nice to meet you, " << name << "!" << endl;

	//Ask for age, input age
	cout << "How old are you?" << endl;
	cin >> age;

	while (age > 100 || age < 0)
	{
		cout << "Please enter a number between 1 and 100." << endl;
		cin >> age ;
	}
	if (age < 13)
		cout << "You are too young to play!" << endl;
		
	//Main Menu


    mainmenu();
    
    int number;
    cin >> number;
    	
    //Choice number 1 - Instructions
	if (number == 1)
	{
		cout << "Instructions are simple." << endl;
		cout << "You will need to keep the baby happy by making choices." << endl;
		cout << "Good luck!" << endl;
		mainmenu();
		cin >> number;
	}
	
    //Choice number 2 - Start Game
	if (number == 2)
	{
		cout << "Baby is crying, what would you like to do?" << endl;
		cout << "1.  Feed the baby." << endl;
		cout << "2.  Put the baby down for a nap. " << endl;
		cout << "3.  Play with the baby." << endl;
		cout << "4.  Take the baby for a car ride to run errands." << endl;
	}	
		int babynumber;
		
		//Choice 1.  Feed the baby.
		cin >> babynumber;
		if (babynumber == 1)
		    {
		        cout << "How many ounces would you like to feed the baby?" << endl;
		
		        int ounces;
		        cin >> ounces;
		        int minounces = 4;
		        int totalounces;
		        totalounces = baba(minounces);
		        
		        if (ounces < 4 )
		        {
		        cout << "Baby is not happy.  Try again." << endl;
		        cout << "How many ounces would you like to feed the baby?" << endl;
		        cin >> ounces;
		        }
		        if (ounces >= 4)
		        {
		        cout << "Baby drank " << totalounces << " ounces!  She is happy." << endl;
		        }
	
		    }


		
		
		//Choice 2.  Put the baby down for a nap.
	if (babynumber == 2)
		{
		    cout << "You have chosen to put the baby down for a nap." << endl;
		    cout << "In order to get the baby to sleep, you must guess one of the correct four-digit numbers between 1000 and 1050." << endl;
		    
		   
		    
		    int fourdigitnumber;
		    cin >> fourdigitnumber;
		    
		    int tennumbers[SIZE] = {1001, 1041, 1032, 1045, 1011, 1012, 1009, 1025, 1040, 1030} ;
		    int results;
		   
		    
            results = searchList (tennumbers, SIZE, fourdigitnumber);
            
                if ( results == -1 )
                {
                    cout << "Sorry, baby did not go to sleep." << endl;
                    cout << "Try one of the numbers below." << endl;
                    selectionSort(tennumbers, SIZE);
                    showArray(tennumbers, SIZE);
                }
                else
                {
                 cout << "Congratulations, the baby has fallen asleep!" << endl;
                
                }
		    
		}
		//Choice 3.  Play with the baby.
		if (babynumber == 3)
        {     
            cout << "Please choose a number from the options below." << endl;
            cout << "1.  Tummy Time" << endl;
            cout << "2.  Mat Time with Toys" << endl;
            cout << "3.  Bouncy Time" << endl;
        
        
            int activity, timelength;
            
            cin >> activity;
            

                if (activity == 1)
                {
                cout << "Please choose a time length for tummy time and enter the number:"  << endl;
                cout << "1.  1 minute" << endl;
                cout << "2.  2 minutes" << endl;
                cout << "3.  5 minutes" << endl;
                cin >> timelength;
                }
            
                else if (activity == 2)
                {
                cout << "Please choose a time length for mat time with toys and enter the number:"  << endl;
                cout << "1.  5 minutes" << endl;
                cout << "2.  7 minutes" << endl;
                cout << "3.  10 minutes" << endl;
                cin >> timelength;
                }
                
                else if (activity == 3)
                {
                cout << "Please choose a time length for bouncy time and enter the number:"  << endl;
                cout << "1.  2 minutes" << endl;
                cout << "2.  4 minutes" << endl;
                cout << "3.  6 minutes" << endl;
                cin >> timelength;
                }
                
                   
            //Two-Dimensional Array 
            const int PLAYCHOICE = 3;
            const int TIMEOPTIONS = 3; 
            int playtime[3][3] = {{1, 2, 5},
                                {5, 7, 10},
                                {2, 4, 6}};
                                
           cout << "You have chosen to do this activity for " << playtime[--activity][--timelength] << " minute(s).  Baby is happy!" << endl;
        }

                
        //Choice 4.  Take baby for a car ride to run errands.
            if (babynumber == 4)
            {
                cout << "Enter the number of errands you need to run." << endl;
                //Pointers and dynamically allocating array integers
                int size;
                cin >> size;
                int *arrayerrands = nullptr; 
                arrayerrands = errandsfunction(size); //Send size into function
                int total = 0;
                int count;
                
                for (count = 0; count < size; count++)
                {
                total += arrayerrands[count];
                }
                   
                cout << "You have chosen to run errands for a total of " << total << " minutes." << endl;
                
                if (total < 10 )
                {
                    cout << "Baby is not happy.  He did not get to sleep long enough in the car." << endl;
                }
                
                else if (total > 30)
                {
                    cout << "Baby is not happy.  He did not like being in the car for that long." << endl;
                }
                
                else
                {
                    cout << "Baby is happy!! Good job." << endl;
                }
    
                delete [] arrayerrands; //Clear memory
                arrayerrands = 0;
            }
                
    //Choice number 3 - Exit Game
	if (number == 3)
	{
		cout << "Thank you, come again!" << endl;
	}	

	return 0;
}


//Main Menu
void mainmenu()
{
    cout << "Please choose an option below and enter the number." << endl;
	cout << "1.  Instructions" << endl;
	cout << "2.  Start Game" << endl;
	cout << "3.  Exit" << endl;

}

//Feed the baby
int baba(int babaounces)
{
    return babaounces;
}


//Search Array
int searchList(const int list[], int numElems, int value)
{		    
    int index = 0;
    int position = -1;
	bool found = false;

    
    while (index < numElems && !found)
        {
            if (list[index] == value) 
                {
                    found = true;
                    position = index;
                   
                }
                index++;
    }
    return position;
} 
 
 
//Array Search
void selectionSort(int array[], int size)
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
        {
            minIndex = startScan;
            minValue = array[startScan];
            
            for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index] < minValue)
                        {
                            minValue = array[index];
                            minIndex = index;
                        }
                }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
        }
}

//Show Array
void showArray(const int array[], int size)
{
    for (int count = 0; count < size; count++)
    cout << array[count] << " ";
    cout << endl;
}

//Pointers and dynamically allocating array integers
int *errandsfunction(int num)
{
    
    cout << "You have chosen to run " << num << " errands.  Please enter the number of minutes each errand will take." << endl;
        
    int *errandsnumber = nullptr;
    errandsnumber = new int[num];
 
    int count;
    
    for (count = 0; count < num; count++)
    {
    cin >> errandsnumber[count];
    }

    return errandsnumber; //Return to pointer to array.
 
    
}


