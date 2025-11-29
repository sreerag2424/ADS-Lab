#include <stdio.h>

int main() {
    int num, rev_num = 0, rem, final_result;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Store the original number for display later
    int ori_num = num;

    // Logic to reverse the number
    while (num != 0) {
        rem = num % 10; // Get the last digit
        rev_num = rev_num * 10 + rem; // Append the digit to the reversed number
        num /= 10; // Remove the last digit from the original number
    }

    // Add 10 to the reversed number
    final_result = rev_num + 10;

    // Print the results
    printf("\nOriginal number = %d\n", ori_num);
    printf("Reversed number = %d\n", rev_num);
    printf("Result after adding 10 = %d\n", final_result);

    return 0;
}
