#include <stdio.h>
#include <stdlib.h>

int main() {
    // Execute the Python script to read text aloud
    int result = system("python read_aloud.py");
    if (result != 0) {
        perror("Error executing Python script");
        return 1;
    }

    // Rest of your C program here...

    return 0;
}
