#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int removeElement(double *array, int size, int index) {
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size -= 1;

    return size;
}

int insertElement(double *arr, int size, int index, double value) {
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;

    size += 1;

    return size;
}

// const str
int hasBracket(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == ')') {
            return 1;
        }
    }

    return 0;
}

void enterExpression(char *expression) {
    printf("Enter your expression: ");
    if (fgets(expression, MAX_SIZE, stdin) != NULL) {
        size_t length = strlen(expression);
        if (length > 0 && expression[length - 1] == '\n') {
            expression[length - 1] = '\0';
        }
    } else {
        printf("ERROR occurs. Please enter again!\n");
    }
}

void removeCharAt(char *str, int k) {
    for (int i = k; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
}

void removeRange(char *str, int start, int end) {
    for (int i = 0; i <= end-start; i++) {
        removeCharAt(str, start);
    }
}

void getRange(char *sourceStr, char *destinationStr, int start, int end) {
    for (int i = start; i <= end; i++) {
        destinationStr[i-start] = sourceStr[i];
    }
    destinationStr[end-start+1] = '\0';
}

void appendChar(char *str, char c) {
    if (str == NULL) { return; }
    
    int length = strlen(str);
    str[length] = c;
    str[length + 1] = '\0';
}

void insertCharAt(char *str, int k, char charToInsert) {
    int length = strlen(str);

    for (int i = length; i >= k; i--) {
        str[i + 1] = str[i];
    }

    str[k] = charToInsert;
}

void insertStr(char *destinationStr, char *source, int index) {
    int length = strlen(source);

    while (length != 0) {
        insertCharAt(destinationStr, index, source[length-1]);
        length -= 1;
    }
}

void eraseString(char *str) {
    while (strlen(str) != 0) {
        removeCharAt(str, 0);
    }
}

void clearSpaces(char *str) {
    int i = 0;
    while (i < strlen(str)) {
        if (str[i] == ' ') {
            removeCharAt(str, i);
        } else {
            i++;
        }
    }
}

void double2Digits(double sourceNumber, char *destinationDigits) {
    snprintf(destinationDigits, MAX_SIZE, "%f", sourceNumber);

    if (sourceNumber == 0) {
        eraseString(destinationDigits);
        insertCharAt(destinationDigits, 0, '0');
        return;
    }

    int length = strlen(destinationDigits);
    while (length != 0) {
        if (destinationDigits[length-1] == '0') {
            removeCharAt(destinationDigits, length-1);
        } else {
            int currentLength = strlen(destinationDigits);
            if (destinationDigits[currentLength-1] == '.') {
                removeCharAt(destinationDigits, currentLength-1);
            }
            return;
        }

        length -= 1;
    }
}

// const str
int deepestBracketsLevel(char *str) {
    int level = 0;
    int tmpOpenBrackets = 0;

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            tmpOpenBrackets += 1;
            if (tmpOpenBrackets > level) {
                level = tmpOpenBrackets;
            }
        } else if (str[i] == ')') {
            tmpOpenBrackets -= 1;
        }
    }

    return level;
}

// const str
int deepestOpenBracketIndex(char *str) {
    int deepestLevel = deepestBracketsLevel(str);

    int level = 0;
    int tmpOpenBrackets = 0;

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            tmpOpenBrackets += 1;
            if (tmpOpenBrackets > level) {
                level = tmpOpenBrackets;
                if (level == deepestLevel) {
                    return i;
                }
            }
        } else if (str[i] == ')') {
            tmpOpenBrackets -= 1;
        }
    }

    return -1;
}

// const str
int deepestCloseBracketIndex(char *str) {
    int deepestLevel = deepestBracketsLevel(str);

    int level = 0;
    int tmpOpenBrackets = 0;

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            tmpOpenBrackets += 1;
            if (tmpOpenBrackets > level) {
                level = tmpOpenBrackets;
            }
        } else if (str[i] == ')') {
            if (level == deepestLevel) {
                return i;
            }
            tmpOpenBrackets -= 1;
        }
    }

    return -1;
}

// const digits
int hasFloatingPoint(char *digits) {
    int length = strlen(digits);
    for (int i = 0; i < length; i++) {
        if (digits[i] == '.') {
            return 1;
        }
    }

    return 0;
}

// const digits
int isNumberDigitsNegative(char *digits) {
    if (digits[0] == '-') {
        return 1;
    } else {
        return 0;
    }
}

// const digits
int countDigitsAfterPoint(char *digits) {
    int length = strlen(digits);

    int didSeePoint = 0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (digits[i] == '.') {
            didSeePoint = 1;
        } else if (didSeePoint) {
            count += 1;
        }
    }

    return count;
}

// const digits
double digits2Double(char *digits) {
    char digitsWithoutNegativeSign[MAX_SIZE] = "";
    
    if (isNumberDigitsNegative(digits)) {
        strcpy(digitsWithoutNegativeSign, digits);
        removeCharAt(digitsWithoutNegativeSign, 0);
    } else {
        strcpy(digitsWithoutNegativeSign, digits);
    }

    int ten = 1;
    int numberWithoutPoint = 0;

    int length = strlen(digitsWithoutNegativeSign);
    for (int i = length - 1; i >= 0; i--) {
        if (digitsWithoutNegativeSign[i] != '.') {
            numberWithoutPoint += (digitsWithoutNegativeSign[i] - 48) * ten;
            ten *= 10;
        }
    }

    if (isNumberDigitsNegative(digits)) {
        numberWithoutPoint *= -1;
    }

    int nDigitsAfterPoint = countDigitsAfterPoint(digitsWithoutNegativeSign);

    int divisor = 1;
    for (int i = 0; i < nDigitsAfterPoint; i++) {
        divisor *= 10;
    }

    double doubleNum = (double)numberWithoutPoint/(double)divisor;

    return doubleNum;
}

// const digits
int digits2Integer(char *digits) {
    char digitsWithoutNegativeSign[MAX_SIZE] = "";
    
    if (isNumberDigitsNegative(digits)) {
        strcpy(digitsWithoutNegativeSign, digits);
        removeCharAt(digitsWithoutNegativeSign, 0);
    } else {
        strcpy(digitsWithoutNegativeSign, digits);
    }

    int ten = 1;
    int integer = 0;

    int length = strlen(digitsWithoutNegativeSign);
    for (int i = length - 1; i >= 0; i--) {
        integer += (digitsWithoutNegativeSign[i] - 48) * ten;
        ten *= 10;
    }

    if (isNumberDigitsNegative(digits)) {
        integer *= -1;
    }

    return integer;
}

double digits2Number(char *digits) {
    double number;

    if (hasFloatingPoint(digits)) {
        number = digits2Double(digits);
    } else {
        number = digits2Integer(digits);
    }

    return number;
}

// const expressionWithoutBrackets
int getOperatorsFromExpressionWithoutBrackets(char *expressionWithoutBrackets, char *destinationOperators) {
    char *str = expressionWithoutBrackets;
    int length = strlen(str);
    int operatorIndex = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (str[i] == '-') {
                if (i > 0 && str[i-1] >= 48 && str[i-1] <= 57) {
                    // destinationOperators[operatorIndex] = str[i];
                    destinationOperators[operatorIndex] = '+';
                    operatorIndex += 1;
                }
            } else {
                destinationOperators[operatorIndex] = str[i];
                operatorIndex += 1;
            }
        }
    }

    int numberOfOperators = operatorIndex;
    destinationOperators[numberOfOperators] = '\0';
    return numberOfOperators;
}

// const expressionWithoutBrackets
int getOperandsFromExpressionWithoutBrackets(char *expressionWithoutBrackets, double *destinationOperands) {
    char *str = expressionWithoutBrackets;
    int length = strlen(str);
    int operandIndex = 0;
    char tmpOperandDigits[MAX_SIZE] = "";

    for (int i = 0; i < length; i++) {
        if (str[i] == '-' && (i == 0 || str[i-1] == '*' || str[i-1] == '/')) {
            appendChar(tmpOperandDigits, str[i]);
        } else if (str[i] == '.') {
            appendChar(tmpOperandDigits, str[i]);
        } else if (str[i] >= 48 && str[i] <= 57) {
            appendChar(tmpOperandDigits, str[i]);
        } else {
            if (strlen(tmpOperandDigits) != 0) {
                double operand = digits2Number(tmpOperandDigits);
                destinationOperands[operandIndex] = operand;

                eraseString(tmpOperandDigits);
                operandIndex += 1;
            }

            if (str[i] == '-') { // new
                appendChar(tmpOperandDigits, str[i]); // new
            }
        }
    }

    if (strlen(tmpOperandDigits) != 0) {
        double operand = digits2Number(tmpOperandDigits);
        destinationOperands[operandIndex] = operand;

        eraseString(tmpOperandDigits);
        operandIndex += 1;
    }

    int numberOfOperands = operandIndex;
    return numberOfOperands;
}

// const str
int hasMultiplicationSignOrDivisionSign(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '*' || str[i] == '/') {
            return 1;
        }
    }

    return 0;
}

double calculate(double num1, double num2, char operator) {
    double result;

    if (operator == '+') {
        result = num1 + num2;
    } else if (operator == '-') {
        result = num1 - num2;
    } else if (operator == '*') {
        result = num1 * num2;
    } else if (operator == '/') {
        result = num1 / num2;
    }

    return result;
}

// const expressionWithoutBrackets
double calculateExpressionWithoutBrackets(char *expressionWithoutBrackets) {
    char operators[MAX_SIZE] = "";
    int nOperators = getOperatorsFromExpressionWithoutBrackets(expressionWithoutBrackets, operators);

    double operands[MAX_SIZE];
    int nOperands = getOperandsFromExpressionWithoutBrackets(expressionWithoutBrackets, operands);

    while (nOperators != 0) {
        
        char operator;
        int operatorIndex;
        
        if (hasMultiplicationSignOrDivisionSign(operators)) {
            for (int i = 0; i < nOperators; i++) {
                if (operators[i] == '*' || operators[i] == '/') {
                    operatorIndex = i;
                    operator = operators[operatorIndex];
                    break;
                }
            }
        } else {
            operatorIndex = 0;
            operator = operators[operatorIndex];
        }

        double leftOperand = operands[operatorIndex];
        double rightOperand = operands[operatorIndex+1];
        double newValue = calculate(leftOperand, rightOperand, operator);

        nOperands = removeElement(operands, nOperands, operatorIndex);
        nOperands = removeElement(operands, nOperands, operatorIndex);
        nOperands = insertElement(operands, nOperands, operatorIndex, newValue);
        
        removeCharAt(operators, operatorIndex);
        nOperators = strlen(operators);
    }

    double result = operands[0];
    return result;
}

// const expression
double calculateExpression(char *expression) {
    char expr[MAX_SIZE] = "";
    strcpy(expr, expression);

    while (hasBracket(expr)) {
        int deepestOpenBracketIndexVar = deepestOpenBracketIndex(expr);
        int deepestCloseBracketIndexVar = deepestCloseBracketIndex(expr);
        char expressionWithoutBrackets[MAX_SIZE] = "";
        getRange(expr, expressionWithoutBrackets, deepestOpenBracketIndexVar+1, deepestCloseBracketIndexVar-1);
        double newValue = calculateExpressionWithoutBrackets(expressionWithoutBrackets);
        
        int needToChangeSign = 0;
        int needToRemovePlusSign = 0;
        if (newValue < 0 && deepestOpenBracketIndexVar != 0 && expr[deepestOpenBracketIndexVar-1] == '-') {
            newValue *= -1;
            needToChangeSign = 1;
        } else if (newValue < 0 && deepestOpenBracketIndexVar != 0 && expr[deepestOpenBracketIndexVar-1] == '+') {
            needToRemovePlusSign = 1;
        }

        char newValueDigits[MAX_SIZE] = "";
        double2Digits(newValue, newValueDigits);
        removeRange(expr, deepestOpenBracketIndexVar, deepestCloseBracketIndexVar);
        insertStr(expr, newValueDigits, deepestOpenBracketIndexVar);

        if (needToChangeSign) {
            expr[deepestOpenBracketIndexVar-1] = '+';
        } else if (needToRemovePlusSign) {
            removeCharAt(expr, deepestOpenBracketIndexVar-1);
        }
    }
    
    double result = calculateExpressionWithoutBrackets(expr);
    return result;
}

int main() {
    char expression[MAX_SIZE] = "";

    while (1) {
        enterExpression(expression);
        clearSpaces(expression);
        double result = calculateExpression(expression);
        char resultDigits[MAX_SIZE] = "";
        double2Digits(result, resultDigits);
        printf("Result: %s\n\n", resultDigits);
    }

    return 0;
}

// Example 1: -1 + (2 + 3 + (3 - 2) + (3 * 3)) / -2.001 - (3 * -10.001)
// Example 2: -1 + 3 * 6 - 3 / 2 + 8.009 / -0.0002 + 0.003 + 0.3