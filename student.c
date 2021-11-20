#include "student.h"

typedef struct student {
	char firstName[20];
  char lastName[20];
  int studentId;
  char nationality[25];
} student;

/* Create student */
student_t student_create(char* firstName, char* lastName, int studentId, char* nationality) {
  student_t _newStudent = calloc(sizeof(student), 1);

	if (NULL == _newStudent) {
		return NULL;
	}

	strncpy(_newStudent->firstName, firstName, sizeof(_newStudent->firstName) - 1);
	strncpy(_newStudent->lastName, lastName, sizeof(_newStudent->lastName) - 1);
  _newStudent->studentId = studentId;
  strncpy(_newStudent->nationality, nationality, sizeof(_newStudent->nationality) - 1);
	return _newStudent;
}

/* Destroy student */
void student_destroy(student_t student) {
	if (NULL != student) {
		free(student);
	}
}

/* Print student */
void student_print(student_t student) {
  printf("Name: %s %s\nId: %d\nNationality: %s\n", student->firstName, student->lastName, student->studentId, student->nationality);
}
