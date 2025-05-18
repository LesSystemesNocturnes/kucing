#include <stdio.h>
#include <string.h>

// Global variable: accessible from all functions
char global_message[] = "I am global";

/*
 * Function: public_function
 * -------------------------
 * In C, all non-static functions are "public" by default,
 * meaning they are accessible from other files (if declared).
 * This function returns an int.
 */
int public_function() {
    return 42;
}

/*
 * Function: static_private_function
 * ---------------------------------
 * This is "private" to this file.
 * The `static` keyword limits its visibility to this file only.
 * It returns a string (const char *).
 */
static const char* static_private_function() {
    return "This is a private function (static)";
}

/*
 * Function: void_function
 * -----------------------
 * This function returns nothing (`void`).
 * It's used to perform an action, not return data.
 */
void void_function(const char *name) {
    printf("Hello, %s!\n", name);
}

/*
 * Function: sum
 * -------------
 * A simple function that returns the result of an operation.
 * Demonstrates return values (int).
 */
int sum(int a, int b) {
    return a + b;
}

/*
 * Function: main
 * --------------
 * The entry point of the program.
 * It must return an int.
 */
int main() {
    // Calling a function that returns an int
    int value = public_function();
    printf("public_function() returned: %d\n", value);

    // Calling a "private" static function
    const char *message = static_private_function();
    printf("static_private_function() returned: %s\n", message);

    // Calling a void function (no return value)
    void_function("James");

    // Using a function that returns a value
    int result = sum(7, 5);
    printf("sum(7, 5) = %d\n", result);

    // Accessing a global variable
    printf("Global message: %s\n", global_message);

    return 0; // Indicate success to the OS
}
