#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student* student_t;

student_t student_create(char* firstName, char* lastName, int studentId, char* nationality);

void student_destroy(student_t student);

void student_print(student_t student);