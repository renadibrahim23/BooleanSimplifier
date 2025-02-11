# BooleanSimplifier
Project for Discrete Mathematics Class to simplify digital circuits using Discrete Math concepts.
Truth Table Simplifier

#Author

Renad Sameh Ahmed Assem IbrahimID: 23P0292Group: 7 Task 2

#Description

This program generates a truth table for a given Boolean expression, simplifies it, and verifies equivalency. It allows the user to choose between an AND (^) or OR (v) gate as part of the expression evaluation. The program then determines common patterns in the outputs to derive a simplified Boolean expression.

#Features

Generates a truth table for the given Boolean expression.

Allows the user to select between AND and OR operations interactively.

Simplifies the Boolean expression based on the truth table outputs.

Checks for logical equivalency between the original and simplified expressions.

#Implementation Details

Uses a 2D array to store the truth table values.

Boolean arrays A, B, and C store the respective variable states.

A user-defined function truthtable() generates the truth table based on the chosen gate.

Another function truthtablesimp() generates the simplified version.

The program checks for common values in the truth table to simplify the Boolean expression.

Utilizes _getch() for user input without requiring Enter key presses.

#How to Use

Compile the program using a C++ compiler (e.g., g++ filename.cpp -o output).

Run the executable.

Choose between OR (v) or AND (^) operation when prompted.

The program will generate and display the corresponding truth table.

It will simplify the Boolean expression and check for equivalency.

The simplified truth table will be displayed if applicable.

#Requirements

C++ Compiler (e.g., GCC, MSVC)

Standard C++ Libraries (iostream, cstring, vector, stack, etc.)

#Notes

The program currently supports expressions with three variables (A, B, C).

Uses console-based input/output for interaction.

The simplification logic is based on identifying stable values when the output is 1.

#Future Enhancements

Extend support for more than three variables.

Add graphical representation of the truth table.

Implement a more advanced simplification algorithm.

#License

This project is for educational purposes and is free to use and modify.

