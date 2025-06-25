// Temp conversion program.
// Really simple, just a step back from the previous, more difficult questions.

#include <stdio.h>

int main() {
    double fahrenheit, celsius;

    // Prompt user for Fahrenheit temperature
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    // Convert to Celsius with type casting
    celsius = ((double)fahrenheit - 32) * 5 / 9;

    // Display result
    printf("%.2lf°F is equal to %.2lf°C\n", fahrenheit, celsius);

    return 0;
}