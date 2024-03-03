#include <stdio.h>

int maxPulse(int age);
float calculateBMI(float weight, float height);
void ageAccumulator(int z);
void weightAccumulator(float x);
void heightAccumulator(float y);

int totalAges = 0;
int patientCount = 0;
float totalWeight = 0;
float totalHeight = 0;

int main() {
    int age;
    float height;
    float weight;
    int choice = 1;
    int underweightCount = 0;
    int normalWeightCount = 0;
    int overweightCount = 0;
    int obeseCount = 0;
    
    while (choice == 1) {
        printf("Please enter your age: ");
        scanf("%d", &age);
        patientCount++;
        ageAccumulator(age);
        
        int maxHeartRate = maxPulse(age);
        printf("Your maximum heart rate is: %d\n", maxHeartRate);
        
        printf("Please enter your weight (kg): ");
        scanf("%f", &weight);
        totalWeight += weight;
        
        printf("Please enter your height (m): ");
        scanf("%f", &height);
        totalHeight += height;
        
        float bmi = calculateBMI(weight, height);
        printf("Your body mass index (BMI) is: %f\n", bmi);

        if (bmi <= 18.5) {
            printf("You are underweight.\n");
            underweightCount++;
        } else if (bmi > 18.5 && bmi <= 24.9) {
            printf("You have a normal weight.\n");
            normalWeightCount++;
        } else if (bmi > 24.9 && bmi <= 29.9) {
            printf("You are overweight.\n");
            overweightCount++;
        } else if (bmi > 29.9) {
            printf("You are obese.\n");
            obeseCount++;
        }
        
        printf("To exit the program, press 0, to continue press 1.\n");
        scanf("%d", &choice);
                
        if (choice == 0) {
            printf("You have successfully exited the program.\n");
        }
    }
    
    printf("Results based on the data collected:\n");
    printf("Total number of patients: %d\n", patientCount);
    printf("Number of underweight patients: %d\n", underweightCount);
    printf("Number of normal weight patients: %d\n", normalWeightCount);
    printf("Number of overweight patients: %d\n", overweightCount);
    printf("Number of obese patients: %d\n", obeseCount);
    float averageWeight = totalWeight / patientCount;
    printf("Average weight: %f kg\n", averageWeight);
    float averageHeight = totalHeight / patientCount;
    printf("Average height: %f m\n", averageHeight);
    float averageAge = totalAges / patientCount;
    printf("Average age: %f\n", averageAge);
        
    return 0;
}

int maxPulse(int age) {
    int maxPulse = 220 - age;
    return maxPulse;
}

float calculateBMI(float weight, float height) {
    float BMI = weight / (height * height);
    return BMI;
}

void ageAccumulator(int z) {
    totalAges += z;
}

void weightAccumulator(float x) {
    totalWeight += x;
}

void heightAccumulator(float y) {
    totalHeight += y;
}
