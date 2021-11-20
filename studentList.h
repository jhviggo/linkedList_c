#pragma once

#include "list.h"
#include "student.h"

linkedList_t studentList_createStudentList();

linkedList_return_codes_t studentList_addStudent(linkedList_t list, student_t student);

student_t studentList_getStudent(linkedList_t list, uint16_t index);

linkedList_return_codes_t studentList_removeStudent(linkedList_t list, student_t student);

int studentList_noOfStudents();

void studentList_printAllStudents();
