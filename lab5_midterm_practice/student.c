#include <stdio.h>

struct student{
        int id;
        int age;
        double creditHours;
};

struct student makeStudent(int id, int age, double creditHours){
        struct student tempstudent;
        tempstudent.id = id;
        tempstudent.age = age;
        tempstudent.creditHours = creditHours;
        return tempstudent;
}

int main(){
    struct student s1 = makeStudent(1001, 20, 30);
    struct student s2 = makeStudent(1002, 21, 50);

    printf("StudentID: %d, Age: %d, Hours: %f\n", s1.id, s1.age, s1.creditHours);
    return 0;
}