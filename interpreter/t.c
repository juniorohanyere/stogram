#include <stdio.h>
#include <string.h>

int main() {
    // Define a hexadecimal string representing ASCII characters
    char hexString[] = "2f"; // Hexadecimal representation of "home"

    // Calculate the length of the hexadecimal string
    size_t hexLen = strlen(hexString);

    // Ensure the length is even (each pair of characters represents one byte)
    if (hexLen % 2 != 0) {
        printf("Invalid input: Hexadecimal string length must be even.\n");
        return 1;
    }

    // Calculate the length of the resulting string
    size_t strLen = hexLen / 2;

    // Create a character array to store the result
    char resultString[strLen + 1]; // +1 for null terminator

    // Loop through pairs of characters in the hexadecimal string and convert to ASCII
    for (size_t i = 0, j = 0; i < hexLen; i += 2, j++) {
        char hexPair[3] = {hexString[i], hexString[i + 1], '\0'};
        int byteValue;
        sscanf(hexPair, "%02x", &byteValue);
        resultString[j] = (char)byteValue;
    }

    // Null-terminate the result string
    resultString[strLen] = '\0';

    // Print the resulting string
    printf("Original String: %s\n", resultString);

    return 0;
}
