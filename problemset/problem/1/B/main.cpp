#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
int main(){
    char excelNameChar [27]{  0,'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' ,
                           'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , -'P' , 'Q' ,
                           'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y', 'Z'  };
    int nLine = 0, cIndex = 0,numIndex = 0,R = 0, C=0;
    char input [32] = "", result[256] = "";
    bool R1C1  = true ,trigerR  = false, trigerC= false;
    std::string answer;

    std::cin >> nLine;
    std::cin.ignore();

    for (int i = 0; i < nLine; ++i) {
        std::cin.getline(input,64);
        for (int j = 0; j < 512 && input[j] != '\0' && R1C1 ; ++j){
            switch (input[j]) {
                case 'R':
                    trigerR = true;
                    break;
                case 48 ... 57:
                    if(numIndex == 0){
                        numIndex = j;
                    }
                    break;
                case 'C':
                    cIndex  = j;
                    trigerC = true;
                    break;
                default:
                    R1C1 = false;
                    break;
            }
        }
        if (!trigerC || !trigerR || !(input[1] >= 49 &&  input[1] <=57 )){
            R1C1 =false;
        }
        if (R1C1){
            char buff[256] ="";
            memcpy(buff,&input[1],cIndex-1);
            R = atoi(buff);
            memset(buff, 0, sizeof buff);
            memcpy(buff,&input[cIndex+1], sizeof(buff));
            C = atoi(buff);
            std::cout <<"R="<<R << " C="<< C << std::endl;
            int temp  = C;
            std::string resultMath = "";
            while (double (temp)/26 >= 1){
                resultMath.insert(0,1,excelNameChar[temp%26 == 0 ? 26 : temp%26]);
                temp =  temp/26;

            }

            resultMath.insert(0,1,excelNameChar[temp%26 == 0 ? 26 : temp%26]);



            std::cout << C/26 << " десятка\n";
            std::cout << C/(26*26) << " сотен\n";


            answer += excelNameChar[C%26];
            answer += std::to_string(R);
            answer.append("\n");
        }else{

        }
    }




    std::cout << answer;

    return 0;
}