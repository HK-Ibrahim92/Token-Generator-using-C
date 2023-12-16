#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int tokenCount = 0;  // Counter variable to keep track of tokens


// Returns 'true' if the character is a DELIMITER.
bool isDelimiterHA(char character)
{
    if (character == ' ' || character == '+' || character == '-' || character == '*' ||
        character == '/' || character == ',' || character == ';' || character == '>' ||
        character == '<' || character == '=' || character == '(' || character == ')' ||
        character == '[' || character == ']' || character == '{' || character == '}')
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperatorHA(char character)
{
    if (character == '+' || character == '-' || character == '*' ||
        character == '/' || character == '>' || character == '<' ||
        character == '=')
        return (true);
    return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool isValidIdentifierHA(char* string)
{
	  // Trim leading whitespaces
    int start = 0;
    while (isspace(string[start]))
        start++;

    // Trim trailing whitespaces
    int end = strlen(string) - 1;
    while (end >= start && isspace(string[end]))
        end--;
        
     if (start > end) // All characters are whitespace
        return false;
        
    if (string[0] == '0' || string[0] == '1' || string[0] == '2' ||
        string[0] == '3' || string[0] == '4' || string[0] == '5' ||
        string[0] == '6' || string[0] == '7' || string[0] == '8' ||
        string[0] == '9' || isDelimiterHA(string[0]) == true)
        return (false);
    return (true);
}
// Extracts the SUBSTRING.
char* extractSubstringHA(char* string, int left, int right)
{
    int i;
    char* subString = (char*)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subString[i - left] = string[i];
    subString[right - left + 1] = '\0';
    return (subString);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeywordHA(char* string)
{
	  // Trim leading and trailing whitespaces
    int start = 0;
    while (isspace(string[start]))
        start++;

    int end = strlen(string) - 1;
    while (end >= start && isspace(string[end]))
        end--;

    char* trimmedString = extractSubstringHA(string, start, end);
if (trimmedString != NULL) {	
   
    if (!strcmp(trimmedString, "auto") || !strcmp(trimmedString, "break") ||
            !strcmp(trimmedString, "case") || !strcmp(trimmedString, "char") ||
            !strcmp(trimmedString, "const") || !strcmp(trimmedString, "continue") ||
            !strcmp(trimmedString, "default") || !strcmp(trimmedString, "do") ||
            !strcmp(trimmedString, "double") || !strcmp(trimmedString, "else") ||
            !strcmp(trimmedString, "enum") || !strcmp(trimmedString, "extern") ||
            !strcmp(trimmedString, "float") || !strcmp(trimmedString, "for") ||
            !strcmp(trimmedString, "goto") || !strcmp(trimmedString, "if") ||
            !strcmp(trimmedString, "inline") || !strcmp(trimmedString, "int") ||
            !strcmp(trimmedString, "long") || !strcmp(trimmedString, "register") ||
            !strcmp(trimmedString, "restrict") || !strcmp(trimmedString, "return") ||
            !strcmp(trimmedString, "short") || !strcmp(trimmedString, "signed") ||
            !strcmp(trimmedString, "sizeof") || !strcmp(trimmedString, "static") ||
            !strcmp(trimmedString, "struct") || !strcmp(trimmedString, "switch") ||
            !strcmp(trimmedString, "typedef") || !strcmp(trimmedString, "union") ||
            !strcmp(trimmedString, "unsigned") || !strcmp(trimmedString, "void") ||
            !strcmp(trimmedString, "volatile") || !strcmp(trimmedString, "while")
            || !strcmp(trimmedString, "main"))
   
        return (true);

    return (false);
    free(trimmedString); 
}}



// Returns 'true' if the string is an INTEGER.
bool isIntegerHA(char* string)
{
    int i, len = strlen(string);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (string[i] != '0' && string[i] != '1' && string[i] != '2'
            && string[i] != '3' && string[i] != '4' && string[i] != '5'
            && string[i] != '6' && string[i] != '7' && string[i] != '8'
            && string[i] != '9' || (string[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumberHA(char* string)
{
    int i, len = strlen(string);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (string[i] != '0' && string[i] != '1' && string[i] != '2'
            && string[i] != '3' && string[i] != '4' && string[i] != '5'
            && string[i] != '6' && string[i] != '7' && string[i] != '8'
            && string[i] != '9' && string[i] != '.' ||
            (string[i] == '-' && i > 0))
            return (false);
        if (string[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}



// Parsing the input STRING.
void parseInputStringHA(char* string)
{
    int left = 0, right = 0;
    int len = strlen(string);

    while (right <= len && left <= right) {
       // Skip whitespace characters
        while (right <= len && isspace(string[right]))
            right++;
            
	    if (isDelimiterHA(string[right]) == false)
            right++;

        if (isDelimiterHA(string[right]) == true && left == right) {
            if (isOperatorHA(string[right]) == true){
			
                printf("'%c' IS AN OPERATOR\n", string[right]);
                tokenCount++;

		}
            // Handle special characters like parentheses and curly braces
            else if (string[right] == '(' || string[right] == ')' || string[right] == '{' || string[right] == '}' ||
 string[right] == '[' || string[right] == ']' || string[right] == ';' || string[right] == ',' ||
 string[right] == '.' || string[right] == '?' || string[right] == '!' || string[right] == ':' ||
 string[right] == '@' || string[right] == '"' || string[right] == '#' || string[right] == '_' ||
 string[right] == '`' || string[right] == '~' || string[right] == '$' || string[right] == '&' ||string[right] == '%')

                printf("'%c' IS A SPECIAL CHARACTER\n", string[right]);
            right++;
            left = right;
        }
        else if (isDelimiterHA(string[right]) == true && left != right
            || (right == len && left != right)) {
            char* subString = extractSubstringHA(string, left, right - 1);
            tokenCount++;

            if (isKeywordHA(subString) == true)
                printf("'%s' IS A KEYWORD\n", subString);

            else if (isIntegerHA(subString) == true)
                printf("'%s' IS AN INTEGER\n", subString);

            else if (isRealNumberHA(subString) == true)
                printf("'%s' IS A REAL NUMBER\n", subString);

            else if (isValidIdentifierHA(subString) == true
                && isDelimiterHA(string[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subString);

            else if (isValidIdentifierHA(subString) == false
                && isDelimiterHA(string[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subString);
            else if (string[right] == '(' || string[right] == ')' ||
                     string[right] == '{' || string[right] == '}')
                printf("'%c' IS A SPECIAL CHARACTER\n", string[right]);

            
            left = right;
        }
    }
    return;
}

int main()
{

    char filename[100];

    // Get filename from the user
    printf("Enter the filename: ");
    if (scanf("%99s", filename) != 1) {
        fprintf(stderr, "Error reading filename\n");
        return 1;
    }
	FILE* file;
    char line[256];

	    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        parseInputStringHA(line);
    }
    printf("Total Number of Tokens: %d\n", tokenCount);

   
    fclose(file);

    return 0;

}
