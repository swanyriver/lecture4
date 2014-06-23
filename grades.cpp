/***********************************************************

* Author: Brandon Swanson
* Date Created: 06-22-2014
* Last Modification Date: 06-22-2014
* Filename: grades.cpp
*
* Overview:After inputing grade percentages caclulates average percent and
*	   gives a total letter grade
*
* Input:A seris of points out of total points
*
* Output:"Your Average percent is:%% for a grade of:AA"
*
***********************************************************/

#include <iostream>
using namespace std;


//global variables
float pointsEarnedTotal=0;
float pointsAvailableTotal=0;
float percentEarned;
const string ERROR = "ERROR";
const int EQUAL = 0; //defined by string.compare()


//Prompts user to input points earned
void getGrades(int numGrades);

//returns a letter grade equivalent after calculating a percentage
string convertToLetterGrade(float pointsEarnedTotal,
                                 float pointsAvailableTotal);


int main(){
	
    //local variables
	int numGrades;
    string letterGrade;
    float percentEarnedTotal;
    
    // Only display two places after the decimal point,
    // using the "magic formula" form Savitch, pg. 31
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

	//Program Description and Input Prompt
	cout << "This program will calculate your average percent score on your class assignments and award you a Letter Grade" << endl;
	cout << "How many assignments did you have?";
    cin >> numGrades;
    
    //Primary Calculations
    getGrades(numGrades);
    letterGrade=convertToLetterGrade(pointsEarnedTotal,pointsAvailableTotal);

    //check for error
    if (letterGrade.compare(ERROR) == EQUAL) {
        cout << "something has gone wrong please launch program again" << endl;
        return -1;
    }else {
        //ouput results
        cout << "You earned a total of " << pointsEarnedTotal << " out of ";
        cout << pointsAvailableTotal << " available points" << endl;
        cout << "for a total of ";
        cout << percentEarned*100 << " percent and a grade of: ";
        cout << letterGrade << endl;
    }

	return 0;
}

/**************************************************************
* Entry:a quantity of grades to be inputed
*
*Exit:Global variables pointsEarnedTotal and pointsAvailable totol
*     will be incremented acording to user input
*
* Purpose:Retrieve points earned on assignments for the calculaiton
*           of a letter grade
*
 ***************************************************************/
void getGrades(int numGrades){
    
    float pointsEarned;
    float pointsAvailable;
    bool succesfulInput;
    
    for (int i = 1; i <= numGrades; i++) {
        do{
            succesfulInput=false;
            
            //retrive points earned and available for each assignment
            cout << endl;
            cout << "On assignment " << i << " you earned how many points:";
            cin >> pointsEarned;
            cout << "  out of how many points available:";
            cin >> pointsAvailable;
            
            //check validity of input
            if (pointsEarned > pointsAvailable
                || pointsAvailable <= 0
                || pointsEarned < 0) {
                cout << endl << "Are you sure you entered that information correctly";
                cout << endl << "Be sure all values are positive, and that the points available are greater than the points earned" << endl;
            }else{
                succesfulInput = true;
            }
            
            
        }while (!succesfulInput);
        
        //incrememt totals
        pointsEarnedTotal += pointsEarned;
        pointsAvailableTotal += pointsAvailable;
    }
}

/**************************************************************
* Entry:
*
*Exit:Will return a grade on scale A,B,C,D,F unless:
*       -pointsEarnedTotal>pointsAvailableTotal  OR
*       -pointsAvailableTotal = 0
*       in wich case it will return an Error Code
*
* Purpose:To convert pointsEarned and PointsAvailable to a Letter Grade
*
 ***************************************************************/
string convertToLetterGrade(float pointsEarnedTotal,
                                 float pointsAvailableTotal){
    //calculate percent
    if (pointsAvailableTotal == 0  || pointsAvailableTotal<pointsEarnedTotal) {
        //somewhat redundant check, since these cases are checked during input
        return ERROR;
    } else {
        percentEarned = pointsEarnedTotal / pointsAvailableTotal;
    }
    
    //covert to letter grade
    if (percentEarned < 0 || percentEarned > 1) {
        return ERROR;
    }else if (percentEarned>=.98){
        return "A+";
    }else if (percentEarned>=.92){
        return "A";
    }else if (percentEarned>=.90){
        return "A-";
    }else if (percentEarned>=.88){
        return "B+";
    }else if (percentEarned>=.82){
        return "B";
    }else if (percentEarned>=.80){
        return "B-";
    }else if (percentEarned>=.78){
        return "C+";
    }else if (percentEarned>=.72){
        return "C";
    }else if (percentEarned>=.70){
        return "C-";
    }else if (percentEarned>=.68){
        return "D+";
    }else if (percentEarned>=.62){
        return "D";
    }else if (percentEarned>=.60){
        return "D-";
    }else if (percentEarned<.60){
        return "F";
    }
    
    
    return ERROR;  //this line should never be reached,
                   //but we will return nevertheless
}


