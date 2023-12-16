# Token-Generator-using-C

## Overview
Token Generator is a simple program written in C that tokenizes input source code, identifying keywords, operators, identifiers, integers, real numbers, and special characters.

## Features
- **Keyword Recognition:** Identifies keywords in the source code.
- **Operator Detection:** Recognizes common operators in the code.
- **Identifier Validation:** Determines the validity of identifiers.
- **Integer and Real Number Recognition:** Identifies numerical values.
- **Special Character Detection:** Recognizes special characters like parentheses and braces.

## Usage
1. **Compile the Program:**
        Copy the provided code and Paste it into a C compiler.
2. **Run the Program:**
        enter your filename.c.  
3. **View Token Output:**
   The program will display the identified tokens in the console.

## Example

// Sample filename.c
int main() {
    printf("Hello, Token Generator!");
    return 0;
}

## Output:

'int' IS A KEYWORD
' main' IS A VALID IDENTIFIER
'(' IS A SPECIAL CHARACTER
')' IS A SPECIAL CHARACTER
'{' IS A SPECIAL CHARACTER
'printf' IS A VALID IDENTIFIER
'(' IS A SPECIAL CHARACTER
'"Hello, Token Generator!"' IS A STRING
')' IS A SPECIAL CHARACTER
';' IS AN OPERATOR
'return' IS A KEYWORD
'0' IS AN INTEGER
';' IS AN OPERATOR
'}' IS A SPECIAL CHARACTER

## License:
This project is licensed under the MIT License - Feel free to modify and use it.



