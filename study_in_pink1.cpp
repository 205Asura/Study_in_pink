#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int roundUp(double n)
{
    int x = n;
    double y = n;
    if (y - x < 0.00001)
        return x;
    else
        return ceil(y);
}
int sum2DigitTill1(int a)
{
    while (a >= 10)
    {
        string digit = to_string(a);
        int digit1 = digit[0] - '0';
        int digit2 = digit[1] - '0';
        a = digit1 + digit2;
    }
    return a;
}
void presetEXP(int &EXP)
{
    if (EXP > 600)
        EXP = 600;
    if (EXP < 0)
        EXP = 0;
}
void presetHP(int &HP)
{
    if (HP > 666)
        HP = 666;
    if (HP < 0)
        HP = 0;
}
void presetM(int &M)
{
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
}
double findP(int EXP)
{
    int S, x, y;
    double P;
    x = y = EXP;
    int sq = sqrt(x);
    while (pow(sq, 2) != x)
    {
        x++;
        sq = sqrt(x);
    }
    while (pow(sq, 2) != y)
    {
        y--;
        sq = sqrt(y);
    }
    if (abs(x - EXP) > abs(y - EXP))
        S = y;
    else
        S = x;
    if (EXP >= S)
        P = 1;
    else
        P = (double(EXP) / S + 80) / 123;
    return P;
}
void find3P(int &HP1, int &EXP1, int &M1, int E2, double &P1, double &P2, double &P3)
{
    // Street 1

    P1 = findP(EXP1);

    // Street 2
    double Mspent = 0;
    double Mcheck = M1 / 2.0;
    while (true)
    {

        if (E2 % 2 == 1)
        {
            if (M1 == 0)
                break;
            if (Mspent > Mcheck)
                break;
            if (HP1 < 200) // no
            {
                HP1 = roundUp(HP1 * 1.3);
                M1 -= 150;
                Mspent += 150;
            }
            else
            {
                HP1 = roundUp(HP1 * 1.1);
                M1 -= 70;
                Mspent += 70;
            }
            presetHP(HP1);
            presetM(M1);
            if (Mspent > Mcheck)
                break;

            if (EXP1 < 400) // yes
            {
                M1 -= 200;
                Mspent += 200;
            }
            else
            {
                M1 -= 120;
                Mspent += 120;
            }
            EXP1 = roundUp(EXP1 * 1.13);
            presetEXP(EXP1);
            presetM(M1);
            if (Mspent > Mcheck)
                break;

            if (EXP1 < 300) // no
            {
                M1 -= 100;
                Mspent += 100;
            }
            else
            {
                M1 -= 120;
                Mspent += 120;
            }
            presetM(M1);
            EXP1 = roundUp(EXP1 * 0.9);
            presetEXP(EXP1);
            if (Mspent > Mcheck)
                break;
        }
        if (E2 % 2 == 0)
        {
            if (M1 == 0)
                break;
            if (HP1 < 200)
            {
                HP1 = roundUp(HP1 * 1.3);
                M1 -= 150;
                Mspent += 150;
            }
            else
            {
                HP1 = roundUp(HP1 * 1.1);
                M1 -= 70;
                Mspent += 70;
            }
            presetHP(HP1);
            presetM(M1);
            if (M1 == 0)
                break;
            if (EXP1 < 400)
            {
                M1 -= 200;
                Mspent += 200;
            }
            else
            {
                M1 -= 120;
                Mspent += 120;
            }
            presetM(M1);
            EXP1 = roundUp(EXP1 * 1.13);
            presetEXP(EXP1);
            if (M1 == 0)
                break;
            if (EXP1 < 300)
            {
                M1 -= 100;
                Mspent += 100;
            }
            else
            {
                M1 -= 120;
                Mspent += 120;
            }
            presetM(M1);
            EXP1 = roundUp(EXP1 * 0.9);
            presetEXP(EXP1);
            if (M1 == 0)
                break;
            break;
        }
    }

    HP1 = roundUp(HP1 * 0.83);
    EXP1 = roundUp(EXP1 * 1.17);
    presetEXP(EXP1);
    presetHP(HP1);
    presetM(M1);
    P2 = findP(EXP1);

    // Street 3

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 < 10)
        P3 = P[E2] / 100.0;
    if (E2 >= 10)
    {
        string E = to_string(E2);
        int d1 = E[0] - '0', d2 = E[1] - '0';
        int sum = (d1 + d2) % 10;
        P3 = P[sum] / 100.0;
    }
}

// Task 1
int firstMeet(int &EXP1, int &EXP2, int e1)
{
    // TODO: Complete this function

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    else if (e1 <= 3)
    {
        presetEXP(EXP1);
        presetEXP(EXP2);
        switch (e1)
        {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += (29 + 45 + 75);
            break;
        }
        presetEXP(EXP2);
        int D = e1 * 3 + EXP1 * 7;
        switch (D % 2)
        {
        case 0:
            EXP1 = roundUp(EXP1 + D / 200.0);
            break;
        case 1:
            EXP1 = roundUp(EXP1 - D / 100.0);
            break;
        }
        presetEXP(EXP1);
    }

    else if (e1 <= 99)
    {
        presetEXP(EXP1);
        presetEXP(EXP2);
        if (e1 <= 19)
            EXP2 = roundUp(EXP2 + e1 / 4.0 + 19);
        else if (e1 <= 49)
            EXP2 = roundUp(EXP2 + e1 / 9.0 + 21);
        else if (e1 <= 65)
            EXP2 = roundUp(EXP2 + e1 / 16.0 + 17);
        else if (e1 <= 79)
        {
            EXP2 = roundUp(EXP2 + e1 / 4.0 + 19);
            presetEXP(EXP2);
            if (EXP2 > 200)
                EXP2 = roundUp(EXP2 + e1 / 9.0 + 21);
        }
        else if (e1 <= 99)
        {
            EXP2 = roundUp(EXP2 + e1 / 4.0 + 19);
            EXP2 = roundUp(EXP2 + e1 / 9.0 + 21);
            presetEXP(EXP2);
            if (EXP2 > 400)
            {
                EXP2 = roundUp(EXP2 + e1 / 16.0 + 17);
                EXP2 = roundUp(EXP2 * 1.15);
            }
        }
        presetEXP(EXP2);
        EXP1 -= e1;
        presetEXP(EXP1);
    }

    presetEXP(EXP2);
    presetEXP(EXP1);
    EXP1 = roundUp(EXP1);
    EXP2 = roundUp(EXP2);

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{

    if (E2 < 0 || E2 > 99)
        return -99;
    presetEXP(EXP1);
    presetHP(HP1);
    presetM(M1);
    double P1 = 0, P2 = 0, P3 = 0;

    find3P(HP1, EXP1, M1, E2, P1, P2, P3);

    // After 3 streets
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = roundUp(EXP1 * 0.75);

        presetEXP(EXP1);
        presetHP(HP1);
        presetM(M1);
    }
    else
    {
        double PFinal;

        PFinal = (P1 + P2 + P3) / 3.0;
        if (PFinal < 0.5)
        {
            HP1 = roundUp(HP1 * 0.85);
            EXP1 = roundUp(EXP1 * 1.15);
        }
        else
        {
            HP1 = roundUp(HP1 * 0.9);
            EXP1 = roundUp(EXP1 * 1.2);
        }
    }
    presetEXP(EXP1);
    presetHP(HP1);
    presetM(M1);

    return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{

    if (E3 < 0 || E3 > 99)
        return -99;
    presetEXP(EXP1);
    presetEXP(EXP2);
    presetHP(HP1);
    presetHP(HP2);
    int taxiMap[10][10], pos = 0, neg = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (taxiMap[i][j] > E3 * 2)
                pos++;
            if (taxiMap[i][j] < -E3)
                neg++;
        }
    int i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);

    int max = taxiMap[i][j];

    for (i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);; i++, j--)
    {
        if (i == 10 || j == -1)
            break;
        if (taxiMap[i][j] > max)
            max = taxiMap[i][j];
    }

    for (i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);; i--, j++)
    {
        if (i == -1 || j == 10)
            break;
        if (taxiMap[i][j] > max)
            max = taxiMap[i][j];
    }

    for (i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);; i--, j--)
    {
        if (i == -1 || j == -1)
            break;
        if (taxiMap[i][j] > max)
            max = taxiMap[i][j];
    }

    for (i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);; i++, j++)
    {
        if (i == 10 || j == 10)
            break;
        if (taxiMap[i][j] > max)
            max = taxiMap[i][j];
    }
    i = sum2DigitTill1(pos), j = sum2DigitTill1(neg);
    if (abs(taxiMap[i][j]) > max)
    {
        EXP1 = roundUp(EXP1 * 0.88);
        EXP2 = roundUp(EXP2 * 0.88);
        HP1 = roundUp(HP1 * 0.9);
        HP2 = roundUp(HP2 * 0.9);
        presetEXP(EXP1);
        presetEXP(EXP2);
        presetHP(HP1);
        presetHP(HP2);
        return taxiMap[i][j];
    }
    else
    {
        EXP1 = roundUp(EXP1 * 1.12);
        EXP2 = roundUp(EXP2 * 1.12);
        HP1 = roundUp(HP1 * 1.1);
        HP2 = roundUp(HP2 * 1.1);
        presetEXP(EXP1);
        presetEXP(EXP2);
        presetHP(HP1);
        presetHP(HP2);
        return max;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string mail(email);
    string se(email, 0, mail.find('@'));

    string pass(s);
    if (pass.length() < 8)
        return -1;
    if (pass.length() > 20)
        return -2;
    int countspecchar = 0, countnot = 0;

    for (int i = 0; i < pass.length(); i++)
    {
        if (pass.substr(i, se.length()) == se)
            return -(300 + i);
    }
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass.substr(i, 1) == pass.substr(i + 1, 1) && pass.substr(i, 1) == pass.substr(i + 2, 1))
            return -(400 + i);
    }
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass.substr(i, 1) == "@" || pass.substr(i, 1) == "#" || pass.substr(i, 1) == "%" || pass.substr(i, 1) == "$" || pass.substr(i, 1) == "!")
        {
            countspecchar++;
        }
    }
    if (countspecchar == 0)
        return -5;
    //
    int falseIndex = 0;
    for (int i = 0; i < pass.length(); i++)
    {

        if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9') && (pass.substr(i, 1) != "@" && pass.substr(i, 1) != "#" && pass.substr(i, 1) != "%" && pass.substr(i, 1) != "$" && pass.substr(i, 1) != "!"))
        {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    string arr[num_pwds];

    int count = 0, i, j, max = 0, maxlength = 0, firstIndex;
    for (i = 0; i < num_pwds; i++)
    {
        arr[i] = arr_pwds[i];
    }
    for (i = 0; i < num_pwds; i++)
    {

        for (j = 0; j < num_pwds; j++)
            if (arr[i] == arr[j])
            {
                count++;
            }

        if (count == max)
        {
            if (arr[i].length() > maxlength)
            {
                maxlength = arr[i].length();
                firstIndex = i;
            }
        }
        if (count > max)
        {
            maxlength = arr[i].length();
            max = count;

            firstIndex = i;
        }

        count = 0;
    }

    return firstIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////