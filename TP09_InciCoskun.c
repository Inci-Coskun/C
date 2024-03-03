#include <stdio.h>
#define N 10
#define M 3

struct date {
    int day;
    char month[N];
    int year;
};

struct student {
    char name[30];
    char surname[30];
    float grades[M];
    struct date birth_date;
};

struct date getDateOfBirth(void);
void printDateOfBirth(struct date);
struct student getStudentInfo(void);
void printStudentInfo(struct student s);
float calculateAverageGrade(struct student s);

int main(void) {
    struct student x;
    x = getStudentInfo();
    printStudentInfo(x);
    printf("Average of grades: %.2f\n", calculateAverageGrade(x));
    
    return 0;
}

struct date getDateOfBirth(void) {
    struct date temp;
    printf("Please enter a valid date of birth. (DD.month.YYYY)\n");
    printf("Day: ");
    scanf("%d", &temp.day);
    printf("Month: ");
    scanf("%s", temp.month);
    printf("Year: ");
    scanf("%d", &temp.year);
    return temp;
}

void printDateOfBirth(struct date d) {
    printf("Date of birth: %d %s %d\n", d.day, d.month, d.year);
}

struct student getStudentInfo(void) {
    struct student temp;
    
    printf("Please enter a name: ");
    scanf("%s", temp.name);
    
    printf("Please enter a surname: ");
    scanf("%s", temp.surname);
    
    temp.birth_date = getDateOfBirth();
    
    printf("Please enter grades of the student: \n");
    for(int i = 0; i < M; i++) {
        printf("Grade %d of the student: ", i + 1);
        scanf("%f", &temp.grades[i]);
    }
    
    return temp; 
}

void printStudentInfo(struct student s) {
    printf("\nName Surname: %s %s\n", s.name, s.surname);
    printDateOfBirth(s.birth_date);
    printf("Grades of %s %s: \n", s.name, s.surname);
    for (int i = 0; i < M; i++) {
        printf("Grade %d: %.2f\n", i + 1, s.grades[i]);
    }
}

float calculateAverageGrade(struct student s) {
    float sum = 0;
    for (int i = 0; i < M; i++) {
        sum += s.grades[i];
    }
    float average = sum / M;
    return average;
}
