#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false; // If the string length is odd, it can't be valid.
    }

    char stack[len];
    int top = 0; // Stack top

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == 0) {
                return false; // No matching opening bracket in the stack
            }
            char open = stack[--top];
            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) {
                return false; // Mismatched brackets
            }
        }
    }

    return top == 0; // If the stack is empty, all brackets were matched.
}
