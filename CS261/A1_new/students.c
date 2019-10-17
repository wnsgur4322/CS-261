/*
 * This is the file in which you will implement the functionality required by
 * the assignment.  Make sure to add your name and @oregonstate.edu email
 * address below:
 *
 * Name: Junhyeok Jeong
 * Email: jeongju@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>		//professor asked me insert this head for preventing warning message
#include <string.h>		//professor asked me insert this head for preventing warning message
#include "students.h"

/*
 * This function should initialize a single student struct with name, ID, and
 * GPA data.
 *
 * Params:
 *   student - a pointer to the student struct to be initialized.  The memory
 *     for this student will already be allocated before the function is
 *     called.  You simply need to fill its values.  When the function returns,
 *     the fields of this student struct should contain the corresponding
 *     values passed in the other arguments.  Note that this function must
 *     allocate space for the name field and copy the value from name into the
 *     newly-allocated name field.
 *   name - a string containing the student's name.  Note that you'll have to
 *     make a copy of this string to store in the student struct instead of
 *     storing this string directly.
 *   id - an integer ID for the student
 *   gpa - the student's GPA
 */
void init_student(struct student* student, char* name, int id, float gpa) {
	
	student->name = malloc(sizeof(char) * strlen(name)+1);

	for (int i = 0; i < strlen(name)+1; i++) {
		  student->name[i] = name[i];
	  }

	student->id = id;
	student->gpa = gpa;
}


/*
 * This function should free the memory allocated by init_student() for a
 * single student.
 *
 * Params:
 *   student - a pointer to the student whose memory should be freed.  Note
 *     that only memory stored *within* this struct should be freed.  The
 *     struct itself should not be freed.
 */
void free_student(struct student* student) {

	free(student->name);
	student->gpa = 0;
	student->id = 0;
	student->name = 0;
}



/*
 * This function should make a deep copy of a single student.  A deep copy is
 * a copy where pointer fields don't simply have their values (i.e. the memory
 * addresses they point to) copied, but the pointers are dereferenced and
 * copies made of the values themselves.  In other words, for each pointer
 * field in the object being copied, new memory is allocated for a copy of that
 * field to be created, and a pointer to this newly-allocated memory is stored
 * in the copied object.
 *
 * Params:
 *   student - a pointer to the student to be deep copied
 *
 * Return:
 *   Should return a pointer to a deep copy of student.  Memory for this copy
 *   should be allocated by this function.  This memory will have to be freed
 *   using a combination of free_student() and free().
 */
struct student* deep_copy_student(struct student* student) {
	
	struct student* copy;
	
	if (student != NULL) {
		copy = malloc(sizeof(student));
	}
  
	init_student(copy, student->name, student->id, student->gpa);

  return copy;
}


/*
 * This function should allocate space for an array of student structs and
 * initialize their fields using the provided information.  In particular, you
 * should create an array of student structs where the i'th student has the
 * i'th name, the i'th ID, and the i'th GPA from the arrays provided as
 * arguments.  You should use your init_student() function to perform the
 * initialization of each student in the new array.
 *
 * Params:
 *   num_students - the number of students to be stored in the newly allocated
 *     array
 *   names - an array of the names of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   ids - an array of the IDs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   gpas - an array of the GPAs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *
 * Return:
 *   Should return a pointer to the newly allocated and initialized array of
 *   student structs.  The i'th student in this array should have the i'th
 *   name, the i'th ID, and the i'th GPA from the arrays provided as arguments.
 */
struct student* create_student_array(int num_students, char** names, int* ids,
    float* gpas) {
    
	struct student* student_arr = malloc(sizeof(struct student) * num_students);
    
	for(int i = 0; i<num_students; i++){
		init_student(&student_arr[i],names[i],ids[i],gpas[i]);
    }
    
  return student_arr;
}


/*
 * This function should free all of the memory allocated to an array of
 * student structs, including the memory allocated to the array itself as
 * well as any memory allocated within the individual student structs.  You
 * should use free_student() to free the memory for each individual student.
 *
 * Params:
 *   students - a pointer to the array of student structs whose memory is to
 *     be freed
 *   num_students - the number of students in the array
 */
void destroy_student_array(struct student* students, int num_students) {
  
	for(int i = 0; i< num_students; i++){
    		free_student(&students[i]);
    }
    	free(students);
}


/*
 * This function should print the name, ID, and GPA of each student in an
 * array, one student per line.
 *
 * Params:
 *   students - the array of students to be printed
 *   num_students - the number of students in the array
 */
void print_students(struct student* students, int num_students) {
	
	for (int i = 0; i < num_students; i++) {
		printf("name: %s  ID: %d  GPA: %g\n", students[i].name, students[i].id, students[i].gpa);
	}
}


/*
 * This function should return a pointer to the student in a given array with
 * the highest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the highest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the highest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_max_gpa(struct student* students, int num_students) {
  
  int max_gpa_student;
  float max_gpa;
  
  for(int i =0; i< num_students; i++){
    if(max_gpa < students[i].gpa){
      max_gpa_student = i;
      max_gpa = students[i].gpa;
      }
     } 
  
  return &students[max_gpa_student];
}


/*
 * This function should return a pointer to the student in a given array with
 * the lowest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the lowest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the lowest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_min_gpa(struct student* students, int num_students) {
    
  int min_gpa_student;
  float min_gpa = students[0].gpa;
  
  for(int i =0; i< num_students; i++){
    if(min_gpa > students[i].gpa){
      min_gpa_student = i;
      min_gpa = students[i].gpa;
      }
     } 
     
  return &students[min_gpa_student];
}


/*
 * This function should sort students by descending GPA (i.e. highest GPAs
 * at the beginning of the array).  You may implement any sorting algorithm
 * you want, with the following constraints:
 *   - You must sort in place, i.e. you can't allocate additional memory.
 *   - You may not use built-in sorting functions like qsort(), i.e. you must
 *     implement the sort yourself.
 *
 * Params:
 *   students - the array of students to be sorted; when the function returns,
 *     this array will be sorted by descending GPA
 *   num_students - the number of students in the array
 */
void sort_by_gpa(struct student* students, int num_students) {
  
  for(int i =1; i<num_students; i++){
    if(students[i-1].gpa < students[i].gpa){
      struct student* temp = malloc(sizeof(struct student));
      temp->name = students[i-1].name;
      temp->id = students[i-1].id;
      temp->gpa = students[i-1].gpa;
      
      students[i-1].name = students[i].name;
      students[i-1].id = students[i].id;
      students[i-1].gpa = students[i].gpa;
      
      students[i].name = temp->name;
      students[i].id = temp->id;
      students[i].gpa = temp->gpa;
      
      i = 0 ;
      free(temp);
      }
    }
}
