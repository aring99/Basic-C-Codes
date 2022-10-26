#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* FileName = "exam.bin";

typedef struct
{
    unsigned int id; // student id
    char name[20]; // student name
    char surname[20]; // student surname
    char department[20]; // department of student
    int grade; // grade of student
} studentData;

void showRecords(FILE *filePtr);

int updateGrade(FILE *filePtr, unsigned int id, int newGrade);
int addStudent(FILE *filePtr, unsigned int id, char name[], char surname[], char department[], int grade);
int deleteStudent(FILE *filePtr, unsigned int id);
int showDepartmentRecord(FILE *filePtr, char department[]);

int main()
{
    unsigned int id;
    int newGrade;
    int status;
    char name[20];
    char surname[20];
    char department[20];
    int grade;

    int count;

    FILE *filePtr;
    filePtr = fopen("exam.bin","rb+");
    if (filePtr == NULL)
    {
        printf("Could not open exam.bin");
        return;
    }

    showRecords(filePtr);

    int option;

    printf("\nPlease choose an operation:\n");
    printf("1 : Update Grade\n");
    printf("2 : Add Student\n");
    printf("3 : Delete Student\n");
    printf("4 : Show Department Record\n");
    printf("> ");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("\nStudent id: ");
        scanf("%d",&id);
        printf("New grade: ");
        scanf("%d",&newGrade);
        status = updateGrade(filePtr, id, newGrade);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No student with id %d\n", id);
        break;
    case 2:
        printf("\nStudent id: ");
        scanf("%d",&id);
        printf("Name: ");
        scanf("%s",name);
	printf(" Surname: ");
        scanf("%s",surname);
        printf("Department: ");
        scanf("%s",department);
        printf("Grade: ");
        scanf("%d",&grade);
        status = addStudent(filePtr, id, name, surname, department, grade);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("There is already a student with id %d\n", id);
        break;
    case 3:
        printf("\nStudent id: ");
        scanf("%d",&id);
        status = deleteStudent(filePtr, id);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No student with id %d\n", id);
        break;
    case 4:
        printf("\nDepartment: ");
        scanf("%s",department);
        count = showDepartmentRecords(filePtr, department);
        if (count == 0)
            printf("No student in department %s\n", department);
        else
            printf("There are %d students in department %s\n", count, department);
        break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);

    printf("\n%-3s %-20s %-20s %-20s %s\n",
                   "ID",
                   "Name",
		           "Surname",
                   "Department",
                   "Grade");

    while (!feof(filePtr))
    {
        studentData student;
        int result = fread(&student, sizeof(studentData), 1, filePtr);
        if (result != 0 && student.id != 0)
        {
            printf("%-3d %-20s %-20s %-20s %d\n",
                   student.id,
                   student.name,
		   student.surname,
                   student.department,
                   student.grade);
        }
    }
}

int updateGrade(FILE *filePtr, unsigned int id, int newGrade)
{
    FILE* inputFile = fopen(FileName,"r+b");

    studentData* buffer = malloc(sizeof(studentData));

    fseek(inputFile,(id - 1) * sizeof(studentData),SEEK_SET);

    int x = fread(buffer,sizeof(studentData),1,inputFile);


    if(x > 0)
    {
        if(buffer->id > 0){

            buffer->grade = newGrade;

        fseek(inputFile, ftell(inputFile) - sizeof(studentData), SEEK_SET);

        fwrite(buffer, sizeof(studentData), 1, inputFile);

        fclose(inputFile);
        free(buffer);

        return 1;
    }}


    fclose(inputFile);


    free(buffer);


    return 0;

}

int addStudent(FILE *filePtr, unsigned int id, char name[], char surname[], char department[], int grade)
{
FILE* inputFile = fopen(FileName,"r+b");

    studentData* buffer = malloc(sizeof(studentData));

    fseek(inputFile,(id - 1) * sizeof(studentData),SEEK_SET);

    int x = fread(buffer,sizeof(studentData),1,inputFile);


//    if(x > 0)
//    {
//
//        fclose(inputFile);
//        free(buffer);
//
//        return 0;
//    }
if(buffer->id == 0){

            buffer->grade = grade;
            buffer->id = id;
            strcpy(buffer->name,name);
            strcpy(buffer->surname,surname);
            strcpy(buffer->department,department);

        fseek(inputFile, ftell(inputFile) - sizeof(studentData), SEEK_SET);

        fwrite(buffer, sizeof(studentData), 1, inputFile);

        fclose(inputFile);
        free(buffer);
        return 1;
}
    fclose(inputFile);


    free(buffer);


    return 0;


}

int deleteStudent(FILE *filePtr, unsigned int id)
{
FILE* inputFile = fopen(FileName,"r+b");

    studentData* buffer = malloc(sizeof(studentData));

    fseek(inputFile,(id - 1) * sizeof(studentData),SEEK_SET);

    int x = fread(buffer,sizeof(studentData),1,inputFile);

    if(x > 0)
    if(buffer->id > 0){

        {
        strcpy(buffer->name,"");

        buffer->id = 0;

        strcpy(buffer->surname,"");

        buffer->grade = 0;

        strcpy(buffer->department,"");

        fseek(inputFile, ftell(inputFile) - sizeof(studentData), SEEK_SET);

        fwrite(buffer, sizeof(studentData), 1 , inputFile);


        fclose(inputFile);


        free(buffer);

        return 1;
    }}
    fclose(inputFile);


    free(buffer);

    return 0;

}

int showDepartmentRecords(FILE *filePtr, char department[])
{
    int counter = 0;
 FILE* inputFile = fopen(FileName,"rb");

    studentData* buffer = (studentData*) malloc(sizeof(studentData));

    fseek(inputFile,0,SEEK_SET);

     printf("\n%-3s %-20s %-20s %-20s %s\n",
                   "ID",
                   "Name",
		           "Surname",
                   "Department",
                   "Grade");

    while(fread(buffer,sizeof(studentData), 1,inputFile) > 0)
    {
        if((buffer->id != 0)&& strcmp(buffer->department,department) == 0 )
        { counter++;
            printf("%-3d %-20s %-20s %-20s %d\n",
                   buffer->id,
                   buffer->name,
		   buffer->surname,
                   buffer->department,
                   buffer->grade);

        }
    }
return counter;

    fclose(inputFile);


    free(buffer);


}
