// Implementation file for the CourseGrades class
#include <iostream>
#include "CourseGrades.h"
using namespace std;

void CourseGrades::print() const
{
	// Display the lab score and grade.
	cout << "Lab score: "
		 << grades[LAB]->getScore()
	     << "\tGrade: "
		 << grades[LAB]->getLetterGrade()
		 << endl;

	// Display the pass/fail exam score 
	// and grade.
	cout << "Pass/Fail Exam score: "
		 << grades[PASS_FAIL_EXAM]->getScore()
	     << "\tGrade: "
		 << grades[PASS_FAIL_EXAM]->getLetterGrade()
		 << endl;

	// Display the essay score and grade.
	cout << "Essay score: "
		 << grades[ESSAY]->getScore()
	     << "\tGrade: "
		 << grades[ESSAY]->getLetterGrade()
		 << endl;

	// Display the final exam score and grade.
	cout << "Final exam score: "
		 << grades[FINAL_EXAM]->getScore()
	     << "\tGrade: "
		 << grades[FINAL_EXAM]->getLetterGrade()
		 << endl;
}