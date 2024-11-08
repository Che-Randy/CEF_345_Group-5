#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_DRIVERS 100
#define MAX_RIDES 100

typedef struct {
    char name[50];
    char phone[15];
} User;

typedef struct {
    char name[50];
    char car[50];
} Driver;

typedef struct {
    User user;
    Driver driver;
    char destination[100];
} Ride;

User users[MAX_USERS];
Driver drivers[MAX_DRIVERS];
Ride rides[MAX_RIDES];
int userCount = 0, driverCount = 0, rideCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", users[userCount].name);
    printf("Enter your phone number: ");
    scanf("%s", users[userCount].phone);
    userCount++;
    printf("User registered successfully!\n");
}

void registerDriver() {
    if (driverCount >= MAX_DRIVERS) {
        printf("Driver limit reached.\n");
        return;
    }

    printf("Enter driver's name: ");
    scanf("%s", drivers[driverCount].name);
    printf("Enter driver's car: ");
    scanf("%s", drivers[driverCount].car);
    driverCount++;
    printf("Driver registered successfully!\n");
}

void requestRide() {
    if (rideCount >= MAX_RIDES) {
        printf("Ride limit reached.\n");
        return;
    }

    printf("Enter your name for the ride: ");
    char userName[50];
    scanf("%s", userName);

    // Find the user
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not found!\n");
        return;
    }

    // Assign a driver (simple logic: first available driver)
    if (driverCount == 0) {
        printf("No drivers available!\n");
        return;
    }

    rides[rideCount].user = users[userIndex];
    rides[rideCount].driver = drivers[0]; // Assign the first driver
    printf("Enter your destination: ");
    scanf("%s", rides[rideCount].destination);

    rideCount++;
    printf("Ride requested successfully!\nDriver: %s, Car: %s\n", rides[rideCount - 1].driver.name, rides[rideCount - 1].driver.car);
}

int main() {
    int choice;

    while (1) {
        printf("\nLET'S GO!\n");
        printf("1. Register User\n");
        printf("2. Register Driver\n");
        printf("3. Request Ride\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                registerDriver();
                break;
            case 3:
                requestRide();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
