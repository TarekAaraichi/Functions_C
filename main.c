#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// #ifdef _WIN32
//     #define CLEAR_COMMAND "cls"
// #else
//     #define CLEAR_COMMAND "clear"
// #endif

// Function to add numbers less than 100 and return the result
int addNumbersLessThan100(int num1, int num2) {
    int sum = 0;

    // Check if num1 is less than 100 and add to sum
    if (num1 < 100) {
        sum += num1;
    }

    // Check if num2 is less than 100 and add to sum
    if (num2 < 100) {
        sum += num2;
    }

    return sum; // Return the calculated sum
}

// Function to calculate VAT at 25% and return the VAT value
float calculateVAT(float priceIncludingVat) {
    float vatAmount = priceIncludingVat * 0.25;
    return vatAmount; // Return the VAT amount
}

// Function to check if a user is an adult (age >= 18)
bool isAdult(int age) {
    return age >= 18; // Return true if age is 18 or older
}

// Function to find the longest of three strings and return it
// char* findLongestWord(char *str1, char *str2, char *str3) {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     int len3 = strlen(str3);

//     // Compare lengths and return the longest string
//     if (len1 >= len2 && len1 >= len3) {
//         return str1;
//     } else if (len2 >= len3) {
//         return str2;
//     } else {
//         return str3;
//     }
// }

char* findLongestWord(char *str1, char *str2, char *str3) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int maxLength = len1;

    // Determine the maximum length
    if (len2 > maxLength) maxLength = len2;
    if (len3 > maxLength) maxLength = len3;

    // Allocate memory for the result string (assuming max 100 characters for each word + commas and null terminator)
    char *result = malloc(3 * 100 * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    result[0] = '\0'; // Initialize result as an empty string

    // Concatenate each word that matches the maximum length
    if (len1 == maxLength) {
        strcat(result, str1);
    }
    if (len2 == maxLength) {
        if (result[0] != '\0') strcat(result, ", "); // Add comma if there's already a word
        strcat(result, str2);
    }
    if (len3 == maxLength) {
        if (result[0] != '\0') strcat(result, ", "); // Add comma if there's already a word
        strcat(result, str3);
    }

    return result;
}

// Function to calculate taxes based on salary and return the tax amount
float calculateTaxesOnSalary(float salary) {
    float taxRate;

    // Determine tax rate based on salary range
    if (salary >= 30000) {
        taxRate = 0.33;
    } else if (salary < 15000) {
        taxRate = 0.12;
    } else {
        taxRate = 0.28;
    }

    return salary * taxRate; // Return the calculated tax
}

// Function to check if a character is a vowel, returning 1 if true, 0 otherwise
bool isVowel(char letter) {
    letter = tolower(letter); // Convert letter to lowercase
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

// Function to check if a character is a consonant
int isConsonant(char letter) {
    letter = tolower(letter); // Convert letter to lowercase
    return (letter >= 'a' && letter <= 'z' && !strchr("aeiou", letter));
}

// Function to translate text to "Rövarspråket" and store result in output
void translateToRobbers(char *input, char *output) {
    int i, j = 0; // i for input index, j for output index

    // Loop through each character in the input string
    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i]; // Copy original character

        // If the character is a consonant, add "o" and the consonant again
        if (isConsonant(input[i])) {
            output[j++] = 'o';     // Insert 'o'
            output[j++] = input[i]; // Insert the consonant again
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to safely read input into a buffer
void SafeInput(char *input, int size) {
    printf("Enter a string: ");
    fgets(input, size, stdin); // Read user input
    input[strcspn(input, "\n")] = 0; // Remove newline character if present
}

// Function to swap the values of two integer variables using pointers
void swapTwoNumbers(int *p1, int *p2) {
    printf("\nBefore swapping: num1 = %d, num2 = %d\n", *p1, *p2);

    int temp = *p1; // Store value of p1 in temp
    *p1 = *p2;      // Assign value of p2 to p1
    *p2 = temp;     // Assign temp value to p2

    printf("After swapping: num1 = %d, num2 = %d\n", *p1, *p2);
}

// Function to add a bonus to salary based on age and return the updated salary
float addBonusToSalary(float *salary, int age) {
    if (age > 50 && *salary > 30000) {
        *salary += (*salary * 0.10); // Increase salary by 10%
        printf("Bonus added! New salary: %.2f\n", *salary); // Print updated salary with bonus
    } else {
        printf("No bonus added. Salary remains: %.2f\n", *salary); // Print the same salary if no bonus
    }
    return *salary; // Return the updated or unchanged salary
}

// void clearTerminal() {
//     system(CLEAR_COMMAND); // Clears the terminal screen
// }

// Function prototypes
int addNumbersLessThan100(int num1, int num2);
float calculateVAT(float priceIncludingVat);
bool isAdult(int age);
char* findLongestWord(char *str1, char *str2, char *str3);
float calculateTaxesOnSalary(float salary);
bool isVowel(char text);
void translateToRobbers(char *text, char *output);
void swapTwoNumbers(int *a, int *b);
float addBonusToSalary(float *salary, int age);
//void clearTerminal(); 

int main() {
    int choice;

    // Infinite loop until user chooses to quit
    while (1) {
        printf("\nChoose a function to run:\n");
        printf("\n1. Add numbers less than 100\n");
        printf("2. Calculate VAT\n");
        printf("3. Check if adult\n");
        printf("4. Find longest word\n");
        printf("5. Calculate taxes on salary\n");
        printf("6. Count vowels in text\n");
        printf("7. Translate to Rövarspråket\n");
        printf("8. Swap two numbers\n");
        printf("9. Add bonus to salary\n");
        printf("0. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer after scanf

        if (choice == 0) {
            printf("Exiting the program.\n");
            break; // Exit the loop if user chooses to quit
        }

        // Clear terminal screen
        //clearTerminal();

        switch (choice) {
            case 1:
                // Example function call for Add numbers less than 100
                int num1, num2;
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                getchar(); // Clear newline from buffer after scanf
                printf("Sum: %d\n", addNumbersLessThan100(num1, num2));
                break;
            case 2:
                // Example function call for Calculate VAT
                float priceIncludingVat;
                printf("Enter the price including VAT: ");
                scanf("%f", &priceIncludingVat);
                getchar(); // Clear newline from buffer after scanf
                printf("VAT: %.2f\n", calculateVAT(priceIncludingVat));
                break;
            case 3:
                // Example function call for Check if adult
                int age1;
                printf("Enter your age: ");
                scanf("%d", &age1);
                getchar(); // Clear newline from buffer after scanf
                if (isAdult(age1)) {
                    printf("You are an adult.\n");
                } else {
                    printf("You are not an adult.\n");
                }
                break;
            case 4:
                // Example function call for Find longest word
                char str1[100], str2[100], str3[100];
                printf( "Enter first word: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                printf("Enter second word: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove newline
                printf("Enter third word: ");
                fgets(str3, sizeof(str3), stdin);
                str3[strcspn(str3, "\n")] = 0; // Remove newline
                printf("Longest word(s): %s\n", findLongestWord(str1, str2, str3));
                break;
            case 5:
                // Example function call for Calculate taxes on salary
                float salary;
                printf("Enter your salary: ");
                scanf("%f", &salary);
                getchar(); // Clear newline from buffer after scanf
                printf("Taxes: %.2f\n", calculateTaxesOnSalary(salary));
                break;
            case 6:
                // Example function call for Count vowels in text
                char text[100];
                printf("Enter text to count vowels: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline
                int vowelCount = 0;
                for (int i = 0; text[i] != '\0'; i++) {
                    if (isVowel(text[i])) {
                        vowelCount++;
                    }
                }
                printf("Vowel count: %d\n", vowelCount);
                break;
            case 7:
                // Example function call for Translate to Rövarspråket
                char textToTranslate[100];
                char outputText[200]; // Buffer for the translated text
                printf("Enter text to translate to Rövarspråket: ");
                fgets(textToTranslate, sizeof(textToTranslate), stdin);
                textToTranslate[strcspn(textToTranslate, "\n")] = 0; // Remove newline
                translateToRobbers(textToTranslate, outputText);
                printf("Translated text: %s\n", outputText);
                break;
            case 8:
                // Example function call for Swap two numbers
                int a, b;
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                getchar(); // Clear newline from buffer after scanf
                swapTwoNumbers(&a, &b);
                //printf("Swapped values: a = %d, b = %d\n", a, b);
                break;
            case 9:
                // Example function call for Add bonus to salary
                float baseSalary;
                int age2;
                printf("Enter your salary: ");
                scanf("%f", &baseSalary);
                printf("Enter your age: ");
                scanf("%d", &age2);
                getchar(); // Clear newline from buffer after scanf
                printf("Due Amount: %.2f\n", addBonusToSalary(&baseSalary, age2));
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Pause before showing the menu again
        //printf("\nPress Enter to return to the menu...\n");
        //getchar(); // Wait for the user to press Enter
        //system("clear"); // Clear terminal before showing the menu again
    }

    return 0;
}