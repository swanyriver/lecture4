/***********************************************************

* Author: Brandon Swanson
* Date Created: 06-22-2014
* Last Modification Date: 06-22-2014
* Filename: grades.cpp
*
* Overview:After inputing grade percentages caclulates average percent and
*	   gives a total letter grade
*
* Input:A seris of percentages
*
* Output:"Your Average percent is:%% for a grade of:AA"
*
***********************************************************/

#include <iostream>

int main(){
	
	std::string input;

	//Program Description and Input Prompt
	std::cout << "This program will calculate your average percent score on your class assignments and award you a Letter Grade" << std::endl;
	std::cout << "Please enter your the percentage you scored on each assignment followed by the return key" << std::endl;
	std::cin>>input;
	std::cout<<std::endl<<input<<std::endl;	



	return 0;
}
