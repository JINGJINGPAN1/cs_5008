#include <stdio.h>
#include <string.h>

// Define the Student struct
struct Student {
    char name[50];
    int grades[3];
    float average;  // To store the average grade
    float weightedAverage;
};

// Function to calculate the average (pass-by-reference)

void calculateAverage(struct Student *student) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        //TODO: calculate the sum;
        sum += student->grades[i];
    }
    student->average = sum / 3.0;  // Calculate and update the average
}

void calculateWeightedAverage(struct Student *student, float weighted[3]){
    float weightedSum = 0;
    for(int i = 0; i < 3; i++){
        weightedSum += student->grades[i] * weighted[i];
    }
    student->weightedAverage = weightedSum;
}


// Main function
int main() {
    // Create and initialize an array of 3 students
    struct Student students[3] = {
        {"Andy", {85, 90, 78}, 0},
        {"Randy", {88, 76, 92}, 0},
        {"Sandy", {70, 80, 75}, 0}
    };

    float weighted[3] = {0.4, 0.3, 0.3};
    // Call calculateAverage for each student
    for (int i = 0; i < 3; i++) {
        //TODO;  // Pass each student by reference
        struct Student *student = &students[i];
        calculateAverage(student);
        calculateWeightedAverage(student, weighted);
    }

    // Print student details
    for (int i = 0; i < 3; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Grades: %d, %d, %d\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Average: %.2f\n", students[i].average);
        printf("Weighted Average: %.2f\n", students[i].weightedAverage);
    }

    struct Student *topStudent = &students[0];
    for(int i = 1; i < 3; i++){
        if (students[i].average > topStudent->average){
            topStudent = &students[i];
        }
    }

    printf("Top Student: %s with a Top Average Score of %.2f\n", topStudent -> name, topStudent -> average);

    return 0;
}