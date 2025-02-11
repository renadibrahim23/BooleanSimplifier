/*
	 Renad Sameh Ahmed Assem Ibrahim
	 ID: 23P0292
	 Group 7 task 2
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <conio.h>
#include <iomanip>
using namespace std;

bool output[8][2];                     //2D array to store the outputs
bool A[10], B[10], C[10];              //arrays to store the boolean values of A B C

bool flagA = true, flagB = true, flagC = true;    //checking if the variable doesn't change everytime the output is 1
int rightout[10];                                 //array to store the indexes of the times the times the output is 1
bool sameA, sameB, sameC;                         //storing the value that doesn't change
bool simplified;                                  //storing the simplified expression
void truthtablesimp();                            //function to generate the truth table of the simplified expression
bool table2[2][2] = { 0 };                        //2D array of the truth table
bool simpoutput[2];                               //array to store the outputs of the simplified truth table
bool originalexpression;                          //the original expression
void truthtable();                                //function to generate the truth table, simplify the expression and check for equivalency



int main() {

	truthtable();   //truthtable and simplification
	cout << endl;
	if (simplified == !C && !flagA && !flagB) {
		cout << "Truthtable of ~C" << endl;
		truthtablesimp();
	}    //calling the function for the simplified truth table

}







void truthtable() {   //function to generate the truth table of the given expression
	char choice;
	cout << "Choose the relation between the first part and the second part of the expression: 'v' for OR gate, '^' for AND gate \n";

	choice = _getch();         //this is only to let the user choose the type of gate without having to press enter
	int table[8][3] = { 0 };     //declaring the 2D array of the truth tables where the boolean values will be stored
	cout << "\t____________________________________________________________________________________\n \tA" << setw(8) << "B" << setw(8) << "C" << setw(8) << "~C";
	cout << "     ~(Av~B)   A^B    ~(Av~B)^(A^B) ";  //formatting the table
	switch (choice) {
	case 118: {    //if the user chose OR gate it will output this expression in the truth table
		cout << setw(8) << "  ~Cv(~(Av~B) ^ (A ^ B))\n";
		cout << "\t____________________________________________________________________________________\n";
		originalexpression = (!C || (!(A || !B) && (A && B)));
		break;
	}
	case 94: {      //if the user chose AND gate it will output this expression in the truth table
		cout << setw(8) << "  ~C^(~(Av~B)^(A^B))\n";
		cout << "\t____________________________________________________________________________________\n";
		originalexpression = (!C && (!(A || !B) && (A && B)));
		break;
	}
	}
	for (int i = 0; i < 8; i++) //looping over the rows of the truth table 
	{
		if (i < 4) {                                      //for the first 4 rows, declaring the inputs
			table[i][2] = 0;                             //the last columns for input of variable C will be equal to 0
			C[i] = false;                                //the value of boolean variable C will be false
			if (i % 2 == 0) {                            //if the row index is even the input for the column of the variable A will be equal to 0
				table[i][0] = 0;
				A[i] = false;                            //setting the boolean value of the variable A to false
			}
			else {
				table[i][0] = 1;                                //if the row index is odd the input for the column of the variable A will be equal to 1
				A[i] = true;

			}
			if (i < 2) {
				table[i][1] = 0;                               //if the row index is less than 2 then the value of the column of variable B will be equal to 0
				B[i] = false;                                  //setting the boolean value of variable B to false
			}
			else {
				table[i][1] = 1;                            //if the row index is more than 2 then the value of the column of variable B will be equal to 1
				B[i] = true;                                //setting the boolean value of variable B to true
			}
			cout << "\t" << table[i][0] << setw(8) << table[i][1] << setw(8) << table[i][2] << setw(8);   //printing the values of the input for each column

			switch (choice) {
			case 118: { // if the user chose OR gate 
				if (!C[i] || (!(A[i] || !B[i]) && (A[i] && B[i])))  //the boolean expression will be calculated for each row according to this ecpression
				{
					output[i][1] = true;
					//if the boolean calculation equates to 1 the output of this row will be equal to true or 1 
					//then it will be printed
				}
				else {
					output[i][1] = false;
					//if the boolean calculation equates to 0 then the output of this row will be equal to false
											  //then it will be printed
				}
				cout << (!C[i]) << setw(8) << (!(A[i] || !B[i])) << setw(8) << (A[i] && B[i]) << setw(12) << (!(A[i] || !B[i]) && (A[i] && B[i])) << setw(15) << output[i][1] << "\n";
				break;
			}
			case 94: { //if the user chose AND gate then the same algorithm that happened for OR will happen here but the connective in the boolean expression is changed
				if (!C[i] && (!(A[i] || !B[i]) && (A[i] && B[i])))
				{
					output[i][1] = true;


				}
				else {
					output[i][1] = false;


				}
				cout << (!C[i]) << setw(8) << (!(A[i] || !B[i])) << setw(8) << (A[i] && B[i]) << setw(12) << (!(A[i] || !B[i]) && (A[i] && B[i])) << setw(15) << output[i][1] << "\n";
				break;

			}
			}

		}
		//the same algorithm that happened when the row index was less than 4 will haopen again
		else {
			table[i][2] = 1;
			C[i] = true;                 //but here the values of C will be equal to 1
			if (i % 2 == 0) {
				table[i][0] = 0;
				A[i] = false;
			}
			else {
				table[i][0] = 1;
				A[i] = true;
			}
			if (i < 6) {
				table[i][1] = 0;
				B[i] = false;
			}
			else {
				table[i][1] = 1;
				B[i] = true;
			}
			cout << "\t" << table[i][0] << setw(8) << table[i][1] << setw(8) << table[i][2] << setw(8);
			if (!C[i]) {
				output[i][0] == true;

			}
			else { output[i][0] == false; }
			switch (choice) {
			case 94: {
				if (!C[i] && (!(A[i] || !B[i]) && (A[i] && B[i])))
				{
					output[i][1] = true;



				}
				else {
					output[i][1] = false;




				}
				cout << (!C[i]) << setw(8) << (!(A[i] || !B[i])) << setw(8) << (A[i] && B[i]) << setw(12) << (!(A[i] || !B[i]) && (A[i] && B[i])) << setw(15) << output[i][1] << "\n";
				break;

			}
			case 118: {
				if (!C[i] || (!(A[i] || !B[i]) && (A[i] && B[i])))
				{
					output[i][1] = true;



				}
				else {
					output[i][1] = false;



				}
				cout << (!C[i]) << setw(8) << (!(A[i] || !B[i])) << setw(8) << (A[i] && B[i]) << setw(12) << (!(A[i] || !B[i]) && (A[i] && B[i])) << setw(15) << output[i][1] << "\n";

				break;
			}
			}





		}
	}//simplification
	int rightcount = 0;                //variable to count the number of times the output was equal to 1
	for (int ex = 0; ex < 7; ex++)     //looping over the rows
	{
		if (output[ex][1] == true) {

			rightout[ex] = ex;
			rightcount++;   //if the output of the row is equal to 1 then the counting variable will increment
		}
	}

	int x = 0;

	//here we will check for what's common between the variables inputs when the output is equal to 1
	for (rightout[x]; x < rightcount - 1; x++)   //looping over all the outputs which are equal to 1
	{
		if (flagA == true) {    //making sure all the values of A are the same for the rows where the output is true          
			if (A[rightout[x]] == A[rightout[x] + 1])  //checking if the value of A in this index row is equal to the A after it in the index when the output is equal to 1
				flagA = true;
			else {
				flagA = false; //once this variable is set to false it can't be changed again
			}
		}
		if (flagB == true) {  //same check we did for variable A
			if (B[rightout[x]] == B[rightout[x] + 1]) {
				flagB = true;
			}
			else {
				flagB = false;

			}
		}
		if (flagC == true) {  //same check we did for the other variables
			if (C[rightout[x]] == C[rightout[x] + 1]) {
				flagC = true;

			}
			else {
				flagC = false;
			}
		}
	}


	if (rightcount != 0) {   //making sure that there are outputs that are true
		if (flagA) {
			for (rightout[x]; x < rightcount - 1; x++) {    //looping over the values that output 1
				sameA = A[rightout[x]];    //the value which doesn't change for A 

			}
			if (sameA == 0) {   //if the repeated value of A is 0 then output ~A 
				cout << "~A";
				simplified = !A;
			}
			else {     //if the repeated value of A is 1 then output is A
				cout << "A";
				simplified = A;
			}
		}
		if (flagB) {
			for (rightout[x]; x < rightcount - 1; x++) {
				sameB = B[rightout[x]];    //same check that happened for variable A

			}
			if (sameB == 0) {
				cout << "~B";
				simplified = !B;
			}
			else {
				cout << "B";
				simplified = B;
			}

		}


		if (flagC)
		{
			for (rightout[x]; x < rightcount - 1; x++) {
				sameC = C[rightout[x]];
			}
			if (sameC == 0) {    //same check that happened for variable C
				cout << "The simplified expression is ~C" << endl;
				simplified = !C;


			}
			else {
				cout << "C";
				simplified = C;

			}
		}
	}
	else {
		simplified = 0;     //if there are no outputs that are equal to 1 then the simplification is zero
		cout << "Simplified expression is " << simplified;
	}

	bool equivalency = true;
	// checking equivalency 
	if (simplified = !C) {
		for (int eq = 0; eq < 7; eq++)
		{
			if (equivalency) {
				if (output[eq][1] == output[eq][0]) {
					equivalency = true;

				}
			}
			else cout << "Not equivalent";
		}
	}
	if (equivalency) {
		cout << "\nYes, they are equivalent.";
	}


}


// truth table of simplified ~C
void truthtablesimp() {
	cout << "C  ~C \n";
	for (int k = 0; k < 2; k++)
	{

		table2[k][0] = k;
		C[k] = table2[k][0];
		cout << table2[k][0] << " ";

		if (!C[k]) {
			simpoutput[k] = true;
			cout << simpoutput[k] << "\n";
		}
		else {
			simpoutput[k] = false;
			cout << simpoutput[k] << "\n";
		}
	}
}
//end of main code here





//bool lamp;
//bool outcome;
//string boolean;
//This is my attempt at a completely generic truth table. It generates the inputs right but the outputs are wrong because I couldn't perform operations on the string input by the user
//char expression[100];
//bool analyzeboolean(const string& boolean, const vector<bool>& inputs);   
/*void gentruthtable(const string& booleanfunction) {//const means that the function won't modify the contents of the string
   // const int numvar = 3;                        //number of variables because we are working with 3 variables
	int numrows = pow(2, 3);              //possible number of combinations/ rows
	cout << "TRUTH TABLE:\n ";
	cout << "_____________________________";
	cout << "\tA B C " << booleanfunction << endl;
												 //calculating all the possible combinations for the truth table inputs
	for (int row = 0; row < numrows; row++)
	{
		vector<bool>inputs;
		for (int col = 0; col < 3; col++)
		{
			inputs.push_back((row >> (3 - 1 - col)) & 1);     //bitwise AND operation to calculate the binary value of the inputs

		}
		lamp = analyzeboolean(booleanfunction, inputs);

		for (bool outcome : inputs)
		{
			cout << outcome << '\t';
		}
		cout << lamp<<"\n";
	}
	cout << "_____________________________";

} */

/*#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool evaluateExpression(const string& expression, const vector<bool>& inputValues) {
	vector<bool> stack;

	for (char c : expression) {
		if (c == 'A') {
			stack.push_back(inputValues[0]);
		}
		else if (c == 'B') {
			stack.push_back(inputValues[1]);
		}
		else if (c == 'C') {
			stack.push_back(inputValues[2]);
		}
		else if (c == '&') {
			if (stack.size() >= 2) {
				bool operand2 = stack.back();
				stack.pop_back();
				bool operand1 = stack.back();
				stack.pop_back();
				stack.push_back(operand1 && operand2);
			}
			else {
				return false; // Handle error or provide appropriate feedback
			}
		}
		else if (c == '|') {
			if (stack.size() >= 2) {
				bool operand2 = stack.back();
				stack.pop_back();
				bool operand1 = stack.back();
				stack.pop_back();
				stack.push_back(operand1 || operand2);
			}
			else {
				return false; // Handle error or provide appropriate feedback
			}
		}
		else if (c == '~') {
			if (!stack.empty()) {
				bool operand = stack.back();
				stack.pop_back();
				stack.push_back(!operand); // Negate the operand
			}
			else {
				return false; // Handle error or provide appropriate feedback
			}
		}
	}

	return !stack.empty() ? stack.back() : false;
}

void printTruthTable(const string& expression) {
	const int numVariables = 3;
	int numCombinations = pow(2, numVariables);

	cout << "Truth Table for Expression: " << expression << std::endl;
	cout << string(45, '-') << std::endl;

	// Print header
	cout << "A\tB\tC\t| Result" << std::endl;
	cout << string(45, '-') << std::endl;

	// Generate all possible combinations of input values
	for (int i = 0; i < numCombinations; ++i) {
		vector<bool> inputValues;

		// Generate binary representation of the current combination
		for (int j = 0; j < numVariables; ++j) {
			inputValues.push_back((i >> (numVariables - 1 - j)) & 1);
		}

		// Evaluate the expression for the current combination of input values
		bool result = evaluateExpression(expression, inputValues);

		// Print the current row of the truth table
		for (bool value : inputValues) {
			cout << value << '\t';
		}
	   cout << "| " << result << std::endl;
	}
	cout << std::string(45, '-') << std::endl;
}

int main() {
	string booleanExpression;

	// Prompt the user to enter a boolean expression
	cout << "Enter a boolean expression: ";
	getline(cin, booleanExpression);

	// Print the truth table
	printTruthTable(booleanExpression);

	return 0;
}*/
/*bool analyzeboolean(const string& boolean, const vector<bool>& inputs) {
	vector <bool>stack;


	bool A = inputs[0];
	bool B = inputs[1];
	bool C = inputs[2];
	for (char l: boolean )
	{
		if (l == 'A') {
			stack.push_back(A);

		}
		else if (l == 'B') {
			stack.push_back(B);
		}
		else if (l == 'C') {
			stack.push_back(C);
		}
		else if (l == '^') {
			if (stack.size() >= 2) {
				bool literal2 = stack.back();
				stack.pop_back();
				bool literal1 = stack.back();
				stack.pop_back();
				stack.push_back(literal1 && literal2);
				if (literal1 && literal2 == 1) {
					return true;
				}
				else return false;
			}
			else { return false; }
		}
		else if (l == 'v') {
			if (stack.size() >= 2) {
				bool literal2 = stack.back();
				stack.pop_back();
				bool literal1 = stack.back();
				stack.pop_back();
				stack.push_back(literal1 || literal2);
			}
			else { return false; }
		}
		else if (l == '~') {
			if (!stack.empty()) {
				bool literal = stack.back();
				stack.pop_back();
				stack.push_back(!literal);
			}

			else { return false; }
		}

	}
	return !stack.empty() ? stack.back() : false;
}*/
