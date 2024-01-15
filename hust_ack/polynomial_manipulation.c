#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Structure to represent a polynomial
struct Polynomial {
    int id;
    struct Term* head;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to create a new polynomial
struct Polynomial* createPolynomial(int id) {
    struct Polynomial* polynomial = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    polynomial->id = id;
    polynomial->head = NULL;
    return polynomial;
}

// Function to add a term to a polynomial
void addTerm(struct Polynomial* polynomial, int coefficient, int exponent) {
    struct Term* term = createTerm(coefficient, exponent);
    
    if (polynomial->head == NULL) {
        polynomial->head = term;
    } else {
        struct Term* current = polynomial->head;
        struct Term* prev = NULL;
        
        while (current != NULL && current->exponent > exponent) {
            prev = current;
            current = current->next;
        }
        
        if (current == NULL) {
            prev->next = term;
        } else if (current->exponent == exponent) {
            current->coefficient += coefficient;
            free(term);
        } else {
            if (prev == NULL) {
                term->next = polynomial->head;
                polynomial->head = term;
            } else {
                prev->next = term;
                term->next = current;
            }
        }
    }
}

// Function to print a polynomial
void printPolynomial(struct Polynomial* polynomial) {
    struct Term* current = polynomial->head;
    
    while (current != NULL) {
        printf("%d %d ", current->coefficient, current->exponent);
        current = current->next;
    }
    
    printf("\n");
}

// Function to evaluate a polynomial
int evaluatePolynomial(struct Polynomial* polynomial, int variableValue) {
    int result = 0;
    struct Term* current = polynomial->head;
    
    while (current != NULL) {
        result += current->coefficient * pow(variableValue, current->exponent);
        current = current->next;
    }
    
    return result;
}

// Function to destroy a polynomial
void destroyPolynomial(struct Polynomial* polynomial) {
    struct Term* current = polynomial->head;
    
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
    
    free(polynomial);
}

int main() {
    struct Polynomial* polynomials[10001] = {NULL};
    char command[20];
    int polyId, coef, exp, resultPolyId, variableValue;
    
    while (1) {
        scanf("%s", command);
        
        if (command[0] == '*') {
            break;
        }
        
        if (strcmp(command, "Create") == 0) {
            scanf("%d", &polyId);
            
            if (polynomials[polyId] == NULL) {
                polynomials[polyId] = createPolynomial(polyId);
            }
        }
        
        if (strcmp(command, "AddTerm") == 0) {
            scanf("%d %d %d", &polyId, &coef, &exp);
            
            if (polynomials[polyId] == NULL) {
                polynomials[polyId] = createPolynomial(polyId);
            }
            
            addTerm(polynomials[polyId], coef, exp);
        }
        
        if (strcmp(command, "EvaluatePoly") == 0) {
            scanf("%d %d", &polyId, &variableValue);
            
            if (polynomials[polyId] == NULL) {
                printf("0\n");
            } else {
                int result = evaluatePolynomial(polynomials[polyId], variableValue);
                printf("%d\n", result);
            }
        }
        
        if (strcmp(command, "AddPoly") == 0) {
            scanf("%d %d %d", &polyId, &resultPolyId, &exp);
            
            if (polynomials[polyId] == NULL && polynomials[resultPolyId] == NULL) {
                polynomials[resultPolyId] = createPolynomial(resultPolyId);
            } else if (polynomials[polyId] != NULL && polynomials[resultPolyId] == NULL) {
                polynomials[resultPolyId] = createPolynomial(resultPolyId);
                struct Term* current = polynomials[polyId]->head;
                
                while (current != NULL) {
                    addTerm(polynomials[resultPolyId], current->coefficient, current->exponent);
                    current = current->next;
                }
            } else if (polynomials[polyId] != NULL && polynomials[resultPolyId] != NULL) {
                struct Term* current = polynomials[polyId]->head;
                
                while (current != NULL) {
                    addTerm(polynomials[resultPolyId], current->coefficient, current->exponent);
                    current = current->next;
                }
            }
        }
        
        if (strcmp(command, "PrintPoly") == 0) {
            scanf("%d", &polyId);
            
            if (polynomials[polyId] != NULL) {
                printPolynomial(polynomials[polyId]);
            }
        }
        
        if (strcmp(command, "Destroy") == 0) {
            scanf("%d", &polyId);
            
            if (polynomials[polyId] != NULL) {
                destroyPolynomial(polynomials[polyId]);
                polynomials[polyId] = NULL;
            }
        }
    }
    
    return 0;
}
