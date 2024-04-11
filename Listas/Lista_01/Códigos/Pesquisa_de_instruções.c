#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold an instruction
typedef struct {
    int key;
    char value[30];
} Instruction;

// Function to sort an array of instructions using insertion sort
void insertionSort(Instruction *instructions, int size) {
    for (int i = 1; i < size; i++) {
        Instruction temp = instructions[i];
        int j = i - 1;
        while (j >= 0 && instructions[j].key > temp.key) {
            instructions[j + 1] = instructions[j];
            j--;
        }
        instructions[j + 1] = temp;
    }
}

// Function to perform binary search for an instruction by key in a sorted array of instructions
char *binarySearch(Instruction *instructions, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (instructions[mid].key == key) {
            return instructions[mid].value;
        } else if (instructions[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return "undefined";
}

int main() {
    int numInstructions;
    scanf("%d", &numInstructions);

    Instruction *instructions = (Instruction *)malloc(numInstructions * sizeof(Instruction));

    for (int i = 0; i < numInstructions; i++) {
        scanf("%d %s", &instructions[i].key, instructions[i].value);
    }

    insertionSort(instructions, numInstructions);

    int code;
    while (scanf("%d", &code) == 1) {
        printf("%s\n", binarySearch(instructions, numInstructions, code));
    }

    free(instructions);
    return 0;
}