#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool getTop3(int * &, int);
void readFile(string, ifstream &);
string adventDay1();
string adventDay2(string);
string adventDay2_2(string);

int main() {
    cout << "Day 1:\n";
    cout << adventDay1();
    cout << "\n\nDay 2:\n";
    cout << adventDay2("C:\\Users\\Stewart\\Desktop\\CPSC5005\\AdventOfCode"
                       "\\Adventcodeday2input.txt");
    cout << adventDay2_2("C:\\Users\\Stewart\\Desktop\\CPSC5005\\AdventOfCode"
                         "\\Adventcodeday2input.txt");
    return 0;
}

string adventDay2_2(string filepath){
    ifstream inFile;
    readFile(filepath, inFile);
    string line;
    int oppPlay, totalScore = 0, outcome;
    while (getline(inFile, line)){

        outcome = tolower(line[2]) - 'x' + 1;
        oppPlay = tolower(line[0]) - 'a' + 1;

        switch (outcome){
            case 3:
                totalScore += 6;
                switch (oppPlay){
                    case 3:
                        totalScore += 1;
                        break;
                    default:
                        totalScore += oppPlay + 1;
                        break;
                }
                break;
            case 2:
                totalScore += 3;
                totalScore += oppPlay;
                break;
            case 1:
                switch (oppPlay){
                    case 1:
                        totalScore += 3;
                        break;
                    default:
                        totalScore += oppPlay - 1;
                        break;
                }
                break;

        }
    }

    return "Total score (part two): " + to_string(totalScore) + "\n";
}

string adventDay2(string filepath){
//    stringstream ss;
    ifstream inFile;
    readFile(filepath, inFile);
    string line;
    int myPlay, oppPlay, totalScore = 0, outcome;
    while (getline(inFile, line)){

        myPlay = tolower(line[2]) - 'x' + 1;
        totalScore += myPlay;
        oppPlay = tolower(line[0]) - 'a' + 1;

        outcome = myPlay - oppPlay;
        switch (outcome){
            case 1:
                totalScore += 6;
                break;
            case -1:
                break;
            case 2:
                break;
            case -2:
                totalScore += 6;
                break;
            case 0:
                totalScore += 3;
        }

    }

    return "Total score: " + to_string(totalScore) + "\n";
}

void readFile(string filepath, ifstream & inFile){
    inFile.open(filepath);
}

bool getTop3(int * & arr, int cals){
    if (cals > arr[0]){
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = cals;
        return true;
    }
    else if (cals > arr[1]){
        arr[2] = arr[1];
        arr[1] = cals;
        return true;
    }
    else if (cals > arr[2]){
        arr[2] = cals;
        return true;
    }
    return false;
}

string adventDay1(){
    stringstream ss;
    ifstream inFile;
    readFile("C:\\Users\\Stewart\\Desktop\\CPSC5005\\AdventOfCode"
             "\\Advent of code day1input.txt", inFile);

    string calorieAmt;
    int calorieNum = 0;
    int indComp = 0, totalComp = 0, elfNum = 1, highestElf = 0;
    int * topThree = new int[3];
    for (int i = 0; i < 3; i++){
        topThree[i] = 0;
    }

    while(getline(inFile, calorieAmt)) {
        if (calorieAmt.compare("") == 0){
            elfNum++;
            totalComp = 0;
        }
        else{
            totalComp += stoi(calorieAmt);

            if (totalComp > calorieNum) {
                highestElf = elfNum;
                calorieNum = totalComp;
            }
            getTop3(topThree, totalComp);


        }
    }
    ss << "Elf Num: " << highestElf << endl;
    ss << "Elf Calories: " << calorieNum << endl;
    ss << "Top Three: ";
    int totalTopThree = 0;
    for (int i = 0; i < 3; i++){
        totalTopThree += topThree[i];
    }
    ss << totalTopThree;

    inFile.close();

    return ss.str();
}