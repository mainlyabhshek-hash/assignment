#include <stdio.h>

// Function to calculate total marks of a student
int calculateTotal(int marks[], int size) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += marks[i];
    }
    return total;
}

// Function to calculate average marks of a student
float calculateAverage(int total, int size) {
    return (float)total / size;
}

// Function to determine grade based on average
char calculateGrade(float avg) {
    if(avg >= 90) return 'A';
    else if(avg >= 75) return 'B';
    else if(avg >= 60) return 'C';
    else if(avg >= 40) return 'D';
    else return 'F';
}

int main() {
    int students = 8;
    int subjects = 5;
    int marks[students][subjects];
    char subjectNames[5][20] = {"English", "Hindi", "Math", "Science", "Computer"};

    int totalMarks[students];
    float avgMarks[students];
    char grade[students];
    float classAvg = 0;

    printf("Enter marks for %d students:\n", students);

    // Input marks
    for(int i = 0; i < students; i++) {
        printf("\n--- Enter marks for Student %d ---\n", i + 1);
        for(int j = 0; j < subjects; j++) {
            printf("Enter marks in %s: ", subjectNames[j]);
            scanf("%d", &marks[i][j]);
        }

        totalMarks[i] = calculateTotal(marks[i], subjects);
        avgMarks[i] = calculateAverage(totalMarks[i], subjects);
        grade[i] = calculateGrade(avgMarks[i]);
        classAvg += avgMarks[i];
    }

    classAvg /= students;

    // Output results
    printf("\n\n*********** STUDENT RESULT ***********\n");
    for(int i = 0; i < students; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Total Marks : %d\n", totalMarks[i]);
        printf("Average     : %.2f\n", avgMarks[i]);
        printf("Grade       : %c\n", grade[i]);
    }

    // Class performance
    printf("\n\n*********** CLASS PERFORMANCE ***********\n");
    printf("Class Average Marks: %.2f\n", classAvg);

    if(classAvg >= 90)
        printf("Performance: Excellent ✅\n");
    else if(classAvg >= 75)
        printf("Performance: Very Good 👍\n");
    else if(classAvg >= 60)
        printf("Performance: Good 🙂\n");
    else if(classAvg >= 40)
        printf("Performance: Average 😐\n");
    else
        printf("Performance: Poor ❌\n");

    return 0;
}
