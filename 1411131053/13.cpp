﻿// 13.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>

int main(void)
{
    int a = 7;
    int *aPtr = &a;

    printf("The address of a is %p"
        "\nThe value of aPtr is %p", &a,aPtr);

    printf("\n\nThe value of a is %d"
        "\nThe value of *aPtr is %d", a,*aPtr);

    printf("\n\nShowing that * and & are complements of "
        "each other\n&*aPtr = %p"
        "\n*&aPtr = %p\n", &*aPtr, *&aPtr);
}
=================================================================
    #include <stdio.h>

int cubeByValue(int n);

int main(void)
{
    int number = 5;

    printf("The original value of number is %d", number);

    number = cubeByValue(number);

    printf("\nThe new value of number is %d\n", number);
}
int cubeByValue(int n)
{
    return n * n * n;
}
====================================================
    #include <stdio.h>

void cubeByReference(int *nPtr);

int main(void)
{
    int number = 5;

    printf("The original value of number is %d", number);

    cubeByReference(&number);

    printf("\nThe new value of number is %d\n", number);
}
void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;
}
=============================================================
    #include <stdio.h>
#define SIZE 10

void bubbleSort(int * const array, const size_t size);

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d",a[i]);
    }

    bubbleSort(a, SIZE);

    puts("\nData items in ascending order");

    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d",a[i]);
    }
    puts("");
}

void bubbleSort(int* const array, const size_t size)
{
    void swap(int *element1Ptr, int * element2Ptr);

    for (unsigned int pass = 0; pass < size - 1; ++pass) {
        for (size_t j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void swap(int* element1Ptr, int* element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
=================================================================
 #include <stdio.h>
#define STUDENTS 3 
#define EXAMS 6

void printArray (int grades[][EXAMS], int pupils, int tests);
void sort (int grades[][EXAMS], int pupils, int tests);
void swap (int *element1Ptr, int *element2Ptr);

int main(void)
{
    int studentGrades[STUDENTS][EXAMS] =
        { {012, 77, 68, 86, 73, 0 },
	  {006, 96, 87, 89, 78, 0 },
	  {004, 70, 90, 86, 81, 0 } };
    int student, i, total = 0, j;     
		  
    puts ("The array is:");
    printArray (studentGrades, STUDENTS, EXAMS);
	
    for (j = 0; j < STUDENTS; ++j){
	for (i = 1; i < EXAMS - 1; ++i) {
            total += studentGrades[j][i];
        }
        studentGrades[j][EXAMS - 1] = total / 4;
        total = 0;
    }
    
    printf("\n\n");
    sort (studentGrades, STUDENTS, EXAMS);
    printArray (studentGrades, STUDENTS, EXAMS);
	
}

void sort (int grades[][EXAMS], int pupils, int tests)
{
    int pass, i, j;
    for (pass = 1; pass < pupils; ++pass){
	for (i = 0; i < pupils - 1; ++i){
            if (grades[i][EXAMS - 1] < grades[i + 1][EXAMS - 1]){
		for (j = 0; j < EXAMS; j++){
		swap (&grades[i][j], &grades[i + 1][j]);
                }
            }
    	}	
    }
}

void swap (int *element1Ptr, int *element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

void printArray (int grades[][EXAMS], int pupils, int tests)
{
    int i, j;
    printf ("%s" , "                    [0]  [1]  [2]  [3]");
    for (i = 0; i < pupils; ++i) {
	printf ("\nstudentGrades[%u]", i);
	for (j = 0; j < tests; ++j) {
            printf ("%-5d", grades[i][j]);
        }
    }
}
========================================================================
	#include <stdio.h>
#define SIZE 20
void printarray(int a[][20]);
void swap(int* element1Ptr, int* element2Ptr);
void sort(int a[][SIZE], int size);
int main(void)
{
    
    int a[2][SIZE] = { { 12,13,14,15,16,17,19,21,22,23,24,26,27,28,29,31,32,33,36,37 } 
                      ,{ 66,67,66,70,73,74,75,75,62,32,44,46,27,12,80,63,66,90,11,66 } };
    puts("Data iteam in original order");

    printarray(a);
    

    sort(a, SIZE);
    printarray(a);
    

    
   
}

void printarray(int a[][SIZE]) {
    int i, j;
    for (i = 0; i <= 1; ++i) {
        for (j = 0; j <= 9; ++j) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }


}

void sort(int a[][SIZE],  int size)
{
    int hold;
    for (unsigned int pass = 1; pass < SIZE; ++pass) {
        for (size_t i = 0; i < size - pass; ++i) {
            if (a[1][i] > a[1][i + 1]) {
                swap(&a[1][i], &a[1][i+1]);
                swap(&a[0][i], &a[0][i + 1]);
            }
        }
    }
}


void swap(int * element1Ptr, int * element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
