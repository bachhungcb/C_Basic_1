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
            struct Polynomial* poly1 = polynomials[polyId];
            struct Polynomial* poly2 = polynomials[exp];
            struct Polynomial* resultPoly = createPolynomial(resultPolyId);

            struct Term* term1 = poly1 ? poly1->head : NULL;
            struct Term* term2 = poly2 ? poly2->head : NULL;

            while (term1 || term2) {
                if (term1 && term2) {
                    if (term1->exponent == term2->exponent) {
                        addTerm(resultPoly, term1->coefficient + term2->coefficient, term1->exponent);
                        term1 = term1->next;
                        term2 = term2->next;
                    } else if (term1->exponent > term2->exponent) {
                        addTerm(resultPoly, term1->coefficient, term1->exponent);
                        term1 = term1->next;
                    } else {
                        addTerm(resultPoly, term2->coefficient, term2->exponent);
                        term2 = term2->next;
                    }
                } else if (term1) {
                    addTerm(resultPoly, term1->coefficient, term1->exponent);
                    term1 = term1->next;
                } else {
                    addTerm(resultPoly, term2->coefficient, term2->exponent);
                    term2 = term2->next;
                }
            }

            // Update the polynomials array with the new polynomial
            polynomials[resultPolyId] = resultPoly;
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
