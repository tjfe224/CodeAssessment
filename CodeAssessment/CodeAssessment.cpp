// CodeAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Code Assessment Problem 1 Solution to:
 *      Write a program that, takes a collection of numbers and returns the sum of the two lowest,
 *      positive numbers
 *
 * Parameters:
 *  * input
 *      array of values to be evaluated
 *  * size
 *      size of array since the array is actually a pointer, and the real size cannot be determined
 *      within the method
 * Return:
 *      integer of the sum of two lowest, positive numbers
 * Assumptions:
 *    * Input numbers are integers
 *    * Zero is NOT positive
 *    * Input arrays without 2 positive integers return -1
 */
int sumOfSmallestPositiveInts(int input[], int arrSize) {
    //Return -1 for invalid array size
    if (arrSize <= 1) {
        return -1;
    }
    //Set initial values
    int smallest, secondSmallest;
    if (input[0] < input[1]) {
        smallest = input[0];
        secondSmallest = input[1];
    }
    else {
        smallest = input[1];
        secondSmallest = input[0];
    }
    int iter = 2;
    int currVal;
    //ensure both values in returned sum are positive
    while (iter < arrSize && (smallest <= 0 || secondSmallest <= 0)) {
        currVal = input[iter];
        if (currVal > 0) {
            if (currVal < secondSmallest) {
                smallest = currVal;
            }
            else {
                smallest = secondSmallest;
                secondSmallest = currVal;
            }
        }
        iter++;
    }
    //Return -1 if both aren't positive
    if (smallest <= 0) {
        return -1;
    }
    //iterate rest of array
    while (iter < arrSize) {
        currVal = input[iter];
        if (currVal > 0 && currVal < secondSmallest) {
            if (currVal < smallest) {
                secondSmallest = smallest;
                smallest = currVal;
            }
            else {
                secondSmallest = currVal;
            }
        }
        iter++;
    }

    return smallest + secondSmallest;
}



/**
 * Code Assessment Problem 2 Solution to:
 *      Write a program that, when given a collection of numbers, removes duplicates and
 *      sorts in ascending order
 *
 * Parameters:
 *  * arr
 *      array of values to be evaluated
 *  * size
 *      size of array since the array is actually a pointer, and the real size cannot be determined
 *      within the method
 * Return:
 *      vector representation of the given array w/o duplicates and sorted
 * Assumptions:
 *    * Input numbers are integers
 *    * Data not large enough to not just input into map which has built in integration of this.
 *      If storage or efficiency was an issue, solution would be to write sorting and duplication
 *      removal manually and either adjust the given array or creating a new one while skipping
 *      the map step
 */
vector<int> sortAndRemoveDuplicates(int arr[], int size) {
    map<int, bool>  tempMap;
    //Put all values from input array into a map that solves given problem
    for (int x = 0; x < size; x++) {
        tempMap[arr[x]];
    }

    vector<int> retVect;
    //Put map values into a vector to be returned
    for (map<int, bool>::iterator iter = tempMap.begin(); iter != tempMap.end(); iter++) {
        retVect.push_back(iter->first);
    }
    return retVect;
}



/**
 * Code Assessment Problem 3 Solution to:
 *      Write a program that takes in a string that contains only parentheses, brackets,
 *      and curly braces: (), [], {}, determines if the order of the brackets follows
 *      the correct scope order, and returns both a Boolean indicating if the order
 *      was appropriate and the number of successful pairs.
 *
 *      If the order is broken or incomplete, return a value of zero (0) for the number
 *      of successful pairs
 *
 * Assumptions:
 *    * An empty string is considered incomplete
 *    * All characters given in string are either '(', ')', '[', ']', '{', '}'
 *    * Doesn't have to be enclosed. I.E. "(){}[]" is valid with a result of True, 3
 */
 /**
  * Recursive function designed to see if the string is valid based on given parameters
  *      by finding closure to first character, then checking if everything inside the
  *      closure is valid as well as if the rest of the string is valid
  *
  * Parameter:
  *  * check
  *      string to find if there's a closure to first character
  * Return:
  *      boolean representing if string is valid
  * Assumptions:
  *    * String will not be large enough to force a recursive overflow
  */
bool isValidStringClosure(string check) {
    if (check.empty()) {
        return true;
    }
    char start = check[0];
    int endPos = check.size();
    if (endPos == 2) {
        return
            (start == '(' && check[1] == ')') ||
            (start == '[' && check[1] == ']') ||
            (start == '{' && check[1] == '}');
    }
    char endChar;
    if (start == '(') {
        endChar = ')';
    }
    else if (start == '[') {
        endChar = ']';
    }
    else {//(start == '{')
        endChar = '}';
    }
    //Look for nearest char matching start closure that's an even number of positions from the start
    size_t foundPair = check.find(endChar);
    while (foundPair != string::npos && foundPair % 2 == 0) {
        foundPair = check.find(endChar, foundPair + 1);
    }
    //Unable to find closure matching start of string
    if (foundPair == string::npos) {
        return false;
    }
    if (foundPair == endPos - 1) {
        return true;
    }
    //Check string inside closure and string after closure
    return isValidStringClosure(check.substr(1, foundPair - 1)) && isValidStringClosure(check.substr(foundPair + 1));
}
/**
 * Function to check initial string and format returned pair
 *
 * Parameter:
 *  * input
 *      Initial, full stringto evaluate
 * Return:
 *      pair of:
 *          * boolean representing if string is valid
 *          * integer number of closures (zero if invalid)
 */
pair<bool, int> pairsOfClosures(string input) {
    int stringSize = input.size();
    if (stringSize == 0 || stringSize % 2 != 0) {
        return make_pair(false, 0);
    }

    if (isValidStringClosure(input)) {
        //Number of closures is always half the string length when characters are limited
        return make_pair(true, stringSize / 2);
    }
    else {
        return make_pair(false, 0);
    }
}



//Printing helpers
void printArray(int arr[], int size) {
    cout << "[";
    if (size > 0) {
        cout << arr[0];
    }
    for (int x = 1; x < size; x++) {
        cout << ", " << arr[x];
    }
    cout << "]";
}
void printVector(vector<int> vect) {
    cout << "[";
    if (vect.size() > 0) {
        cout << vect[0];
    }
    for (int x = 1; x < vect.size(); x++) {
        cout << ", " << vect.at(x);
    }
    cout << "]";
}
void printProblem1(int inputArr[], int arrSize) {
    cout << "Problem 1 solution for ";
    printArray(inputArr, arrSize);
    cout << " => " << sumOfSmallestPositiveInts(inputArr, arrSize) << "\n";
}
void printProblem2(int inputArr[], int arrSize) {
    cout << "Problem 2 solution for ";
    printArray(inputArr, arrSize);
    cout << " => ";
    printVector(sortAndRemoveDuplicates(inputArr, arrSize));
    cout << "\n";
}
void printProblem3(string input) {
    string boolText;
    pair<bool, int> problem3Pair;
    problem3Pair = pairsOfClosures(input);
    boolText = problem3Pair.first ? "True" : "False";
    cout << "Problem 3 solution for \"" << input << "\" => ";
    cout << boolText << ", " << problem3Pair.second << "\n";
}

//Main method
int main() {
    //Problem 1
    int problem1Arr1[] = { 19, 5, 42, 2, 77 };
    printProblem1(problem1Arr1, (sizeof(problem1Arr1) / sizeof(int)));
    int problem1Arr2[] = { 3453545353453, 10, 343445353, 3453445 };
    printProblem1(problem1Arr2, (sizeof(problem1Arr2) / sizeof(int)));
    int problem1Arr3[] = { 2, 9, 6, -1 };
    printProblem1(problem1Arr3, (sizeof(problem1Arr3) / sizeof(int)));
    int problem1Arr4[] = { 879, 953, 694, -847, 342, 221, -91, -723, 791, -587 };
    printProblem1(problem1Arr4, (sizeof(problem1Arr4) / sizeof(int)));
    int problem1Arr5[] = { 3683, 2902, 3951, -475, 1617, -2385 };
    printProblem1(problem1Arr5, (sizeof(problem1Arr5) / sizeof(int)));

    cout << "\n";

    //Problem2 
    int problem2Arr1[] = { 1, 2, 4, 3 };
    printProblem2(problem2Arr1, (sizeof(problem2Arr1) / sizeof(int)));
    int problem2Arr2[] = { 1, 4, 4, 4, 4, 4, 3, 2, 1, 2 };
    printProblem2(problem2Arr2, (sizeof(problem2Arr2) / sizeof(int)));
    int problem2Arr3[] = { 6, 7, 3, 2, 1 };
    printProblem2(problem2Arr3, (sizeof(problem2Arr3) / sizeof(int)));

    cout << "\n";

    //Problem 3
    string problem3String;

    problem3String = "()";
    printProblem3(problem3String);
    problem3String = "({[]})";
    printProblem3(problem3String);
    problem3String = "((){}())";
    printProblem3(problem3String);
    problem3String = "((}";
    printProblem3(problem3String);
    problem3String = "()(";
    printProblem3(problem3String);
}