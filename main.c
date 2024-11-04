/*
function to add numbers
Should take two parameters of type int.
Add all numbers that are less than 100.
*/

#include <stdio.h>

// Void function to add numbers less than 100 and print the result
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

    // Print the result directly
    printf("The result is: %d\n", sum);
}

/*
Function to calculate VAT at 25% and return the VAT value
*/

float calculateVAT(float priceIncludingVat) {
    float vatAmount; 

    // Call the function and store the result
    vatAmount = priceIncludingVat * 0.25;

    // Print the result
    printf("\nThe VAT amount is: %.2f\n", vatAmount);      
}

/*
Funtion that prompts the user to enter their age.
Checks if the user is an adult (over 18) and returns true or false.
*/

#include <stdbool.h>

bool isAdult(int age) {
    return age >= 18;
}

/*
Method named findLongestWord.
Takes three strings and return the longest one (char *).
*/

#include <string.h>

char* findLongestWord(char *str1, char *str2, char *str3) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int maxLen = len1;

    // Find the maximum length among the three strings
    if (len2 > maxLen) maxLen = len2;
    if (len3 > maxLen) maxLen = len3;

    printf("\nThe longest word(s):\n");

    // Print each string that has the maximum length
    if (len1 == maxLen) printf("%s\n", str1);
    if (len2 == maxLen) printf("%s\n", str2);
    if (len3 == maxLen) printf("%s\n", str3);
}

/*
Function to calculate taxes on salary
*/

float calculateTaxesOnSalary(float salary) {
    float taxRate, taxes;

    // Determine the tax rate based on the salary
    if (salary >= 30000) {
        taxRate = 0.33;
    } else if (salary < 15000) {
        taxRate = 0.12;
    } else { // 15000 < salary < 30000
        taxRate = 0.28;
    }

    // Calculate the taxes based on the salary
    taxes = salary * taxRate;

    // Print the result
    printf("The calculated taxes on your salary is: %.2f\n", taxes);
}

/*
Function to check if a character is a vowel
*/

#include <ctype.h>

int isVowel(char letter) {
    // Convert the letter to lowercase for easier comparison
    letter = tolower(letter);
    // Check if the letter is a vowel
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

/*
function that translates a given text to "Rövarspråket".
"Robber's Language" is a language alteration popular in Sweden. 
The main idea is to transform the original text by doubling every consonant 
and inserting the letter 'o' between the consonants. Vowels are left unchanged
*/

// Function to check if a character is a consonant
int isConsonant(char letter) {
    letter = tolower(letter); // Convert to lowercase for uniformity
    return (letter >= 'a' && letter <= 'z' && !strchr("aeiou", letter));
}

// Function to translate text to Rövarspråket
void translate(char *input, char *output) {
    int i, j = 0; // i for input index, j for output index

    // Loop through each character in the input string
    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i]; // Copy the original character

        // If the character is a consonant, add "o" and the consonant again
        if (isConsonant(input[i])) {
            output[j++] = 'o';     // Insert 'o'
            output[j++] = input[i]; // Insert the consonant again
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void SafeInput(char *input, int size) {
    printf("Enter a string: ");
    fgets(input, size, stdin); // Read user input
    input[strcspn(input, "\n")] = 0; // Remove newline character if present
}

/*
function that swaps the values of two integer variables using pointers
*/

void Swap(int *p1, int *p2) {

    printf("\nBefore swapping: num 1 = %d, num 2 = %d\n", *p1, *p2);

    int temp = *p1; // Store the value at p1 in a temporary variable
    *p1 = *p2;      // Assign the value at p2 to the location pointed by p1
    *p2 = temp;     // Assign the temporary value to the location pointed by p2

    printf("After swapping: num 1 = %d, num 2 = %d\n", *p1, *p2);
}

/*
function addBonus takes a pointer to an integer (salary) and an integer (age).
Returns a boolean value.
When true, increases the salary by 10% if the age is over 50 and salary > 30,000.
Otherwise, it will return false.
*/

bool addBonus(int *salary, int age) {
    // Check conditions for bonus
    if (age > 50 && *salary > 30000) {
        // Increase salary by 10%
        *salary += (*salary * 0.10);
        return true; // Bonus added
    }
    return false; // No bonus added
}


// Main
int main() {
    // Call the void function directly in main
    //addNumbersLessThan100(130, 90);

    //calculateVAT(120);

    // Call the function and display the result
    // if (isAdult(16)) {
    //     printf("\nYou are an adult.\n");
    // } else {
    //     printf("\nYou are not an adult.\n");
    // }

    // findLongestWord
    // char str1[100], str2[100], str3[100];

    // // Prompt the user to enter three strings
    // printf("\nEnter first string: ");
    // fgets(str1, sizeof(str1), stdin);
    // str1[strcspn(str1, "\n")] = '\0';  // Remove newline character if present

    // printf("Enter second string: ");
    // fgets(str2, sizeof(str2), stdin);
    // str2[strcspn(str2, "\n")] = '\0';

    // printf("Enter third string: ");
    // fgets(str3, sizeof(str3), stdin);
    // str3[strcspn(str3, "\n")] = '\0';

    // // Call the function and print the longest word
    // findLongestWord(str1, str2, str3);

    //calculateTaxesOnSalary(30000);

    // calls isVowel funtion
    // char text[256]; // Array to hold the input text
    // int vowelCount = 0; // Variable to count the vowels
    // int charCount = 0; // Variable to count the characters (excluding spaces)

    // // Prompt the user to enter a text
    // printf("\nEnter a text: ");
    // fgets(text, sizeof(text), stdin); // Read the input text
    // text[strcspn(text, "\n")] = 0; // This line removes the newline character

    // // Calculate the total characters and the number of vowels
    // for (int i = 0; i < strlen(text); i++) {
    //     if (text[i] != ' ') { // Ignore spaces
    //         charCount++; // Count the character
    //         if (isVowel(text[i])) { // Check if the character is a vowel
    //             vowelCount++; // Increment the vowel count
    //         }
    //     }
    // }
    // // Print the results
    // printf("\nYour text is %d characters and there are %d vowels.\n", charCount, vowelCount);

    // Translate to Rövarspråket"
    // char input[100];
    // char output[100];

    // SafeInput(input, 100); // Safely read input
    // translate(input, output); // Translate the input to Rövarspråket

    //printf("%s\n", output); // Print the translated output

    // Call the Swap function, passing the addresses of i and j
    // int i = 1;
    // int j = 2;
    // Swap(&i, &j);

    // 
    int salary;
    int age;

    // Input salary and age from the user
    printf("\nEnter salary: ");
    scanf("%d", &salary);
    printf("Enter age: ");
    scanf("%d", &age);

    // Call the addBonus function
    if (addBonus(&salary, age)) {
        printf("\nBonus added. New salary: %d\n", salary);
    } else {
        printf("\nNo bonus added. Salary remains: %d\n", salary);
    }

    return 0;
}