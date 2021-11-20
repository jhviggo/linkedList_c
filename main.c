#include "student.h"
#include "studentList.h"

int main() {
  student_t stud1 = student_create("viggo", "petersen", 314400, "DK");
  student_t stud2 = student_create("mark", "johnson", 322213, "UK");
  student_t stud3 = student_create("mary", "fisher", 315234, "US");

  linkedList_t students = studentList_createStudentList();
  studentList_addStudent(students, stud1);
  studentList_addStudent(students, stud2);
  studentList_addStudent(students, stud3);
  studentList_printAllStudents(students);
  return 0;
}
