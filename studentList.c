#include "studentList.h"

linkedList_t studentList_createStudentList() {
  return linkedList_create();
}

linkedList_return_codes_t studentList_addStudent(linkedList_t list, student_t student) {
  return linkedList_push(list, student);
}

student_t studentList_getStudent(linkedList_t list, uint16_t index) {
  void* _stud = linkedList_peekItemByIndex(list, index);
  return (student_t) _stud;
}

linkedList_return_codes_t studentList_removeStudent(linkedList_t list, student_t student) {
  return linkedList_removeItem(list, &student);
}

int studentList_noOfStudents(linkedList_t list) {
  linkedList_length(list);
}

void studentList_printAllStudents(linkedList_t list) {
  int studentCount = linkedList_length(list);
  for (int i = 0; i < studentCount; i++) {
    // I know it's slow to look-up the index every time, should have used an iterator :)
    student_t _stud = (student_t)linkedList_peekItemByIndex(list, i);
    student_print(_stud);
    printf("\n");
  }
}