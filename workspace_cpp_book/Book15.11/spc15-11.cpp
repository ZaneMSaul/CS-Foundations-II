// Chapter 15, Programming Challenge 11: CourseGrades Class
#include <iostream>
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "FinalExam.h"
#include "CourseGrades.h"
using namespace std;

int main()
{
	// Create a GradedActivity object for the lab.
	GradedActivity lab(80);

	// Create a PassFailExam object. 50 questions,
	// 5 missed questions, minimum passing score is 70.
	PassFailExam pfexam(50, 5, 70);

	// Create an Essay object and set the different
	// types of points.
	Essay essay;
	essay.setGrammerPoints(25);
	essay.setSpellingPoints(15);
	essay.setLengthPoints(20);
	essay.setContentPoints(30);
	cout << essay.getScore () << endl;

	// Create a FinalExam object.
	FinalExam finalExam(50, 5);

	// Create a CourseGrades object.
	CourseGrades myGrades;

	// Store the grade items in the
	// CourseGrades object.
	myGrades.setLab(&lab);
	myGrades.setPassFailExam(&pfexam);
	myGrades.setEssay(&essay);
	myGrades.setFinalExam(&finalExam);

	// Print the grade information.
	myGrades.print();
	return 0;
}
