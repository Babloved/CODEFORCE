#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

const char cEnChars[26]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

using namespace std;

struct coordinate {
    int row{0};
    int column{0};
};

bool IsR1C1(const string &);

coordinate AddressCell(const string &, bool isR1C1);

string CoordinateToA1(const coordinate &);

string CoordinateToR1C1(const coordinate &);

int main() {
    int n = 0;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    for (const auto &el: input) {
        bool isR1C1 = IsR1C1(el);
        coordinate elCell = AddressCell(el, isR1C1);
//        cout << "ROW:" << elCell.row << " COLUMN:" << elCell.column << endl;
        if (isR1C1) {
            cout << CoordinateToA1(elCell) << endl;
        } else {
            cout << CoordinateToR1C1(elCell) << endl;
        }
    }
    return 0;
}

bool IsR1C1(const string &str) {
    bool bFirstR{false}, t3{false};
    if (str[0] == 'R' and isdigit(str[1])) {
        for (int i = 2; i < str.size(); ++i) {
            if (str[i] == 'C') {
                return true;
            }
        }
    } else {
        return false;
    }
    return false;
}

coordinate AddressCell(const string &str, bool isR1C1) {
    string firstDigit, secondDigit;
    if (isR1C1) {
        bool nextDigit{false};
        for (int i = 1; i < str.size(); ++i) {
            if (isalpha(str[i])) {
                nextDigit = true;
                continue;
            } else if (!nextDigit) {
                firstDigit.push_back(str[i]);
            } else {
                secondDigit.push_back(str[i]);
            }
        }
        return {stoi(firstDigit), stoi(secondDigit)};
    } else {
        for (int i = 0; i < str.size(); ++i) {
            if (isalpha(str[i])) {
                firstDigit.push_back(str[i]);
            } else {
                secondDigit.push_back(str[i]);
            }
        }
        int column = 0;
        for (int j = 0, i = firstDigit.size() - 1; i >= 0; ++j, --i) {

            column += pow(26, i) * (firstDigit[j] - 64);
        }
        return {stoi(secondDigit), column};
    }

}

string CoordinateToA1(const coordinate &cell) {
    string result;
    int temp = cell.column;
    for (int i = 0; temp > 0; i++) {
        result.push_back('A' + ((temp - 1) % 26));
        temp = (temp - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result + to_string(cell.row);
}

string CoordinateToR1C1(const coordinate &cell) {
    return "R" + to_string(cell.row) + "C" + to_string(cell.column);
};