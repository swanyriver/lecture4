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

//global variables
float pointsEarnedTotal=0;
float pointsAvailableTotal=0;
const std::string ERROR = "E";

//Prompts user to input points earned
void getGrades(int numGrades);

//returns a letter grade equivalent after calculating a percentage
std::string convertToLetterGrade(float pointsEarnedTotal,
                                 float pointsAvailableTotal);


int main(){
	
    //local variables
	int numGrades;
    std::string letterGrade;
    float percentEarnedTotal;
    

	//Program Description and Input Prompt
	std::cout << "This program will calculate your average percent score on your class assignments and award you a Letter Grade" << std::endl;
	std::cout << "How many assignments did you have?";
    std::cin >> numGrades;
    
    getGrades(numGrades);
    letterGrade=convertToLetterGrade(98,99);

    std::cout << letterGrade;

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
    std::cout<<"num grades is" << numGrades << std::endl;
}

/**************************************************************
* Entry:
*
*Exit:Will return a grade on scale A,B,C,D,F unless:
*       -PointsEarnedTotal>PointsAvailableTotal  OR
*       -PointsAvailableTotal = 0
*       in wich case it will return an Error Code
*
* Purpose:To convert pointsEarned and PointsAvailable to a Letter Grade
*
 ***************************************************************/
std::string convertToLetterGrade(float pointsEarnedTotal,
                                 float pointsAvailableTotal){
    std::cout<<"points earned is" << pointsEarnedTotal << std::endl;
    std::cout<<"points total is" << pointsAvailableTotal << std::endl;
    
    return "A+";
}


