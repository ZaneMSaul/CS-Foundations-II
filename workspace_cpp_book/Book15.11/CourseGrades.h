#ifndef COURSE_GRADES_H
#define COURSE_GRADES_H
#include <iostream>
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "FinalExam.h"
#include "Essay.h"
using namespace std;

// Constant for the number of grades
const int NUM_GRADES = 4;

// Constants for the subscripts
const int LAB = 0;            // Lab score is at subscript 0
const int PASS_FAIL_EXAM = 1; // Pass/fail exam is at subscript 1
const int ESSAY = 2;          // Essay is at subscript 2
const int FINAL_EXAM = 3;     // Final exam is at subscript 3

class CourseGrades {
private:
	// Array of GradedActivity pointers to
	// reference the different types of grades
	GradedActivity *grades[NUM_GRADES];

public:
	// Default constructor
	CourseGrades() {
		for (int i = 0; i < NUM_GRADES; i++)
			grades[i] = nullptr;
	}

	// Mutators
	void setLab(GradedActivity *activity) {
		grades[LAB] = activity;
	}

	void setPassFailExam(PassFailExam *pfexam) {
		grades[PASS_FAIL_EXAM] = pfexam;
	}

	void setEssay(Essay *essay) {
		grades[ESSAY] = essay;
	}

	void setFinalExam(FinalExam *finalExam) {
		grades[FINAL_EXAM] = finalExam;
	}

	// print function
	void print() const;
};

#endif
