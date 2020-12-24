#include <stdio.h>
#include <stdlib.h>

#define numofStudents 15
int students[numofStudents][2] = {{18060311,40},{20060045,50},{19061091,75},{20060134,90},{20060678,40},{18061086,75},{20060032,50},{20060067,60},{19060456,60},{18060245,75},{20060110,40},{20060234,90},{20060141,60},{20060011,50},{20060012,60}};

typedef struct Student{
  int index;
  struct Student* left;
  struct Student* right;
}Student;

typedef Student newStudent;
newStudent *studentList = NULL;

void addBinarySearchTree(Student * rootstudent, int ind){//Function that adds student to BinarySearchTree
  if(rootstudent == NULL){
    rootstudent = (newStudent*)malloc(sizeof(newStudent));
    rootstudent->left = NULL;
    rootstudent->right = NULL;
    rootstudent->index = ind;
    studentList = rootstudent;
  }
  else if(students[rootstudent->index][1] > students[ind][1]){
    if(rootstudent->left != NULL){
      addBinarySearchTree(rootstudent->left,ind);
    }
    else{
      newStudent * student = (newStudent*)malloc(sizeof(newStudent));
      student->right = NULL;
      student->left = NULL;
      student->index = ind;
      rootstudent->left = student;
    }
  }
  else if(students[rootstudent->index][1] < students[ind][1]){
    if(rootstudent->right != NULL){
      addBinarySearchTree(rootstudent->right,ind);
    }
    else{
      newStudent * student = (newStudent*)malloc(sizeof(newStudent));
      student->right = NULL;
      student->left = NULL;
      student->index = ind;
      rootstudent->right = student;
    }
  }
  else if(students[rootstudent->index][1] == students[ind][1]){
    if(students[rootstudent->index][0] < students[ind][0]){
      if(rootstudent->right != NULL){
        addBinarySearchTree(rootstudent->right,ind);
      }
      else{
        newStudent * student = (newStudent*)malloc(sizeof(newStudent));
        student->right = NULL;
        student->left = NULL;
        student->index = ind;
        rootstudent->right = student;
      }
    }
    else{
      if(rootstudent->left != NULL){
        addBinarySearchTree(rootstudent->left,ind);
      }
      else{
        newStudent * student = (newStudent*)malloc(sizeof(newStudent));
        student->right = NULL;
        student->left = NULL;
        student->index = ind;
        rootstudent->left = student;
      }
    }  
  }
}

newStudent * findBSTStudent(Student * rootstudent,int grade){//Function that returns the first student node greater than or equal to the grade value searched for in BinarySearchTree
  if(students[rootstudent->index][1] >= grade){
    return rootstudent;
  }
  else{
    if(students[rootstudent->index][1] > grade && rootstudent->left !=NULL){
      return findBSTStudent(rootstudent->left,grade);
    }
    else if(students[rootstudent->index][1] < grade && rootstudent->right !=NULL){
      return findBSTStudent(rootstudent->right,grade);
    }
    else if(students[rootstudent->index][1] == grade){
      if(students[rootstudent->index][0] > grade && rootstudent->left !=NULL){
        return findBSTStudent(rootstudent->left,grade);
      }
      else if(students[rootstudent->index][0] < grade && rootstudent->right !=NULL){
        return findBSTStudent(rootstudent->right,grade);
      }
    }
    return NULL;
  }
}

newStudent * findSuccessor(Student * parent){//The function that finds the successor from the right and returns the successor node.
  Student * tempSuccessor = parent->right;
  while(tempSuccessor->left != NULL){
    tempSuccessor = tempSuccessor->left;
  }
  return tempSuccessor;
}

void delBinarySearchTree(Student * rootstudent, int studentNum){//Function to delete student from BinarySearchTree
  Student * parent = rootstudent;
  Student * deleteStudent = rootstudent;

  int ind = -2;
  for(int i = 0; i < numofStudents; i++){
    if(students[i][0] == studentNum){
      ind = i;
    }    
  }
  if(ind == -2){
    printf("\nThe student number %d you want to delete is not found in the tree.\n",studentNum);
  }
  else{
    while(deleteStudent->index != ind){
      parent = deleteStudent;
      if(students[deleteStudent->index][1] > students[ind][1] && deleteStudent->left !=NULL){
        deleteStudent = deleteStudent->left;
      }
      else if(students[deleteStudent->index][1] < students[ind][1] && deleteStudent->right !=NULL){
        deleteStudent = deleteStudent->right;
      }
      else if(students[deleteStudent->index][1] == students[ind][1]){
        if(students[deleteStudent->index][0] > students[ind][0] && deleteStudent->left !=NULL){
          deleteStudent = deleteStudent->left;
        }
        else if(students[deleteStudent->index][0] < students[ind][0] && deleteStudent->right !=NULL){
          deleteStudent = deleteStudent->right;
        }
      }
      if(deleteStudent == NULL){
        break;
      }
    }
    if(deleteStudent->left == NULL && deleteStudent->right == NULL){//If the node to delete has no children
      if(deleteStudent == rootstudent){
        studentList = NULL;
      }
      else if(parent->left == deleteStudent){
        parent->left = NULL;
      }
      else{
        parent->right = NULL;
      }
    }
    else if(deleteStudent->left == NULL){//If the node to be deleted has only one child
      if(deleteStudent == rootstudent){//If the child is on the left
        studentList = deleteStudent->right;
      }    
      else if(parent->left == deleteStudent){
        parent->left = deleteStudent->right;
      }
      else{
        parent->right = deleteStudent->right;
      }
    }
    else if(deleteStudent->right == NULL){//If the child is on the right
      if(deleteStudent == rootstudent){
        studentList = deleteStudent->left;
      }
      else if(parent->left == deleteStudent){
        parent->left = deleteStudent->left;
      }
      else{
        parent->right = deleteStudent->left;
      }
    }
    else{//If the node to be deleted has two children
      Student * successor = findSuccessor(deleteStudent);
      if(deleteStudent == rootstudent){
        studentList = successor;
      }
      else if(parent->left == deleteStudent){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      delBinarySearchTree(deleteStudent,students[successor->index][0]);
      successor->left = deleteStudent->left;
      successor->right = deleteStudent->right;
    }
  } 
}

void replaceBinarySearchTree(Student * rootStudent,int studentNum, int newGrade){//The function that updates the grade of the student in the given student number
  int ind = -2;
  for(int i = 0; i < numofStudents; i++){
    if(students[i][0] == studentNum){
      ind = i;
    }    
  }
  if(ind == -2){
    printf("\nThe student number %d you want to update was not found in the tree.\n",studentNum);
  }
  else{
    delBinarySearchTree(rootStudent,studentNum);
    students[ind][1] = newGrade;
    addBinarySearchTree(studentList,ind);    
  }  
}

int ab = 0;
void listBinarySearchTree(Student * rootStudent, int grade){//Function that lists students who are higher than the given grade value in descending order and prints them
  Student * temproot = findBSTStudent(rootStudent,grade);//This function returns the first node in the tree that is greater than or equal to the note given to the function.
  if(temproot == NULL){
    printf("\n###  There are no students with a grade of %d or higher.\n",grade);
    return;
  }
  if(ab == 0){//Once drawn table to inform the user
    printf("\n#### Students with a grade of %d or higher ####\n\n",grade);
    printf("STUDENT NUMBER | GRADE\n---------------------\n");
    ab += 1;
  }
  if(temproot->right != NULL && students[temproot->right->index][1] >= grade){
    listBinarySearchTree(temproot->right,grade);
  }
  printf("%d          %d\n",students[temproot->index][0],students[temproot->index][1]);
  if(temproot->left != NULL && students[temproot->left->index][1] >= grade){
    listBinarySearchTree(temproot->left,grade);
  }
}

int main(){
  for(int i = 0; i < numofStudents; i++){
    addBinarySearchTree(studentList,i);
  }    
  listBinarySearchTree(studentList,60);
  delBinarySearchTree(studentList,20060141);
  printf("\nNew list after the student is deleted:\n---------------------------------------\n");
  listBinarySearchTree(studentList,60);
  replaceBinarySearchTree(studentList,19061091,100);
  printf("\nThe new list after the student is updated:\n-----------------------------------------\n");
  listBinarySearchTree(studentList,60);
  printf("\n");
}