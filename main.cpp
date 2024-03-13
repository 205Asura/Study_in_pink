/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2023
 * Author: Vu Van Tien
 * Date: 02.02.2023
 */

// The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01()
{
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3))
    {
        return;
    }

    // getline(cin, email);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    // int result1 = firstMeet(EXP1, EXP2, E1);
    //  int result2 = traceLuggage(HP1, EXP1, M1, E2);
    // cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result1 << endl;
    //  cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << " M1:" << M1 << ", result: " << result2 << endl;
    int result3 = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", EXP2: " << EXP2 << ", HP2: " << HP2 << " "
         << "result: " << result3;
    // const char *email = "egccbbaahc#1c1@cehffcf$dbgc1h";
    // const char *s = "e[b!h#agBH1$aHf@$gF[";
    // cout << checkPassword(s, email);
    // const char *arr_pwds[] = {"votienXX", "votien10", "votien", "votien10", "votien", "votienXX", "votien"};
    // int num = 7;
    // cout << findCorrectPassword(arr_pwds, num);
}

int main(int argc, const char *argv[])
{
    sa_tc_01();

    return 0;
}