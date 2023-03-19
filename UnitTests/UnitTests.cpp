#include "pch.h"
#include "CppUnitTest.h"
#include "../CodeAssessment/CodeAssessment.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests {
    TEST_CLASS(UnitTests) {
public:
    TEST_METHOD(Problem1) {
        //Minimum values
        int expected;
        int problem1Arr1[] = { 19, 5, 42, 2, 77 };
        expected = 7; //5+2
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(problem1Arr1, 5));

        int problem1Arr2[] = { 3453545353453, 10, 343445353, 3453445 };
        expected = 3453455; //3453445+10
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(problem1Arr2, 4));

        int problem1Arr3[] = { 2, 9, 6, -1 };
        expected = 8; //2+6
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(problem1Arr3, 4));

        int problem1Arr4[] = { 879, 953, 694, -847, 342, 221, -91, -723, 791, -587 };
        expected = 563; //342+221
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(problem1Arr4, 10));

        int problem1Arr5[] = { 3683, 2902, 3951, -475, 1617, -2385 };
        expected = 4519; //1617+2902
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(problem1Arr5, 6));

        //edge cases such that -1 is returned
        expected = -1;
        //Empty array
        int emptyArr[1] = {};
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(emptyArr, 0));
        //Array with one value
        int oneElement[1] = { 5 };
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(oneElement, 1));
        //Array with all negative
        int allNeg[] = { -1, -9, -15, -99 };
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(allNeg, 4));
        //Array with one positive, rest negative
        int onePositiveRestNeg[] = { -5, 8, -3, -1 };
        Assert::AreEqual(expected, sumOfSmallestPositiveInts(onePositiveRestNeg, 4));
    }//Problem1
    TEST_METHOD(Problem2) {
        vector<int> returnedVect;

        //Minimum values
        int problem2Arr1[] = { 1, 2, 4, 3 };
        int expectedArr1[] = { 1, 2, 3, 4 };
        returnedVect = sortAndRemoveDuplicates(problem2Arr1, 4);
        for (int x = 0; x < 4; x++) {
            Assert::AreEqual(expectedArr1[x], returnedVect.at(x));
        }

        int problem2Arr2[] = { 1, 4, 4, 4, 4, 4, 3, 2, 1, 2 };
        int expectedArr2[] = { 1, 2, 3, 4 };
        returnedVect = sortAndRemoveDuplicates(problem2Arr2, 10);
        for (int x = 0; x < 4; x++) {
            Assert::AreEqual(expectedArr2[x], returnedVect.at(x));
        }

        int problem2Arr3[] = { 6, 7, 3, 2, 1 };
        int expectedArr3[] = { 1, 2, 3, 6, 7 };
        returnedVect = sortAndRemoveDuplicates(problem2Arr3, 5);
        for (int x = 0; x < 5; x++) {
            Assert::AreEqual(expectedArr3[x], returnedVect.at(x));
        }

        //Extra tests ommitted due to feeling unnecessary
    }//Problem2
    TEST_METHOD(Problem3) {
        string problem3String;
        pair<bool, int> problem3Pair;
        pair<bool, int> expectedPair;

        //Minimum values
        vector<string> testStrs{
            "()",
            "({[]})",
            "((){}())",
            "((}",
            "()("
        };
        vector<pair<bool, int>> expectedPairs{
            make_pair(true, 1),
            make_pair(true, 3),
            make_pair(true, 4),
            make_pair(false, 0),
            make_pair(false, 0)
        };
        for (int x = 0; x < testStrs.size(); x++) {
            problem3String = testStrs.at(x);
            expectedPair = expectedPairs[x];
            problem3Pair = pairsOfClosures(problem3String);
            Assert::AreEqual(expectedPair.first, problem3Pair.first);
            Assert::AreEqual(expectedPair.second, problem3Pair.second);
        }

        //Extra tests
        vector<string> testStrs2{
            "",
            "[]",
            "{}",
            "(){}[]",
            "[([){]}]"
        };
        vector<pair<bool, int>> expectedPairs2{
            make_pair(false, 0),
            make_pair(true, 1),
            make_pair(true, 1),
            make_pair(true, 3),
            make_pair(false, 0)
        };
        for (int x = 0; x < testStrs2.size(); x++) {
            problem3String = testStrs2.at(x);
            expectedPair = expectedPairs2[x];
            problem3Pair = pairsOfClosures(problem3String);
            Assert::AreEqual(expectedPair.first, problem3Pair.first);
            Assert::AreEqual(expectedPair.second, problem3Pair.second);
        }
    }//Problem3
    };
}
