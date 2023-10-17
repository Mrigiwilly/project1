#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 5

// Structure to store student information
struct Student {
    char name[50];
    char reg_number[15];
    float grades[NUM_SUBJECTS];
};

// Function to calculate the average grade for a student
float calculateAverageGrade(float grades[], int numSubjects) {
    float sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += grades[i];
    }
    return sum / numSubjects;
}

int main() {
    struct Student students[NUM_STUDENTS];

    // Input student information
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter registration number for student %d: ", i + 1);
        scanf("%s", students[i].reg_number);
    }

    // Input grades for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter grades for %s (%s):\n", students[i].name, students[i].reg_number);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter grade for subject %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }
    }

    // Calculate and display average grades
    printf("\nAverage Grades:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        float average = calculateAverageGrade(students[i].grades, NUM_SUBJECTS);
        printf("%s (%s): %.2f\n", students[i].name, students[i].reg_number, average);
    }

    // Find the highest and lowest grade
    float highestGrade = students[0].grades[0];
    float lowestGrade = students[0].grades[0];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].grades[j] > highestGrade) {
                highestGrade = students[i].grades[j];
            }
            if (students[i].grades[j] < lowestGrade) {
                lowestGrade = students[i].grades[j];
            }
        }
    }
    printf("\nHighest Grade: %.2f\n", highestGrade);
    printf("Lowest Grade: %.2f\n", lowestGrade);

    // Search for a specific student's grade by registration number
    char searchRegNumber[15];
    printf("\nEnter a registration number to search for a specific student's grade: ");
    scanf("%s", searchRegNumber);

    int found = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (strcmp(searchRegNumber, students[i].reg_number) == 0) {
            printf("Grades for %s (%s):\n", students[i].name, students[i].reg_number);
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                printf("Subject %d: %.2f\n", j + 1, students[i].grades[j]);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with registration number %s not found.\n", searchRegNumber);
    }

    return 0;
}
