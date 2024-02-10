#include <iostream>
#include <string>

struct chest {
    short s; //колбаса в холодельнике
    short b; //хлеб в холодельнике
    short c; //сыр в холодельнике
    short sPrice; //колбаса цена
    short bPrice; //хлеб цена
    short cPrice; //сыр цена
    bool sTick = false;
    bool bTick = false;
    bool cTick = false;
};
void BurgerMath();

void BurgerMath(short &frozenZ,short &frozenPZ,short z ,long long &bank, bool &tick){
    while(tick == false){
        if (frozenZ - z >= 0 ) {
            frozenZ -= z;
            tick = true;
        } else {
            if (bank - frozenPZ>= 0){
                bank -= frozenPZ;
                frozenZ ++;
            }
            else{
                bank = -1;
                break;
            }
        }

    }
};

int main(){

    bool skip = true;
    long long bank = 0, count = 0;
    char test[50] = "";
    short s=0,b=0,c = 0;
    chest frozen{};
    char recept[105] = "";
    std::cin.getline(recept,200);

    for (auto ch:recept) {
        switch (ch) {
            case 'S':
                s++;
                break;
            case 'B':
                b++;
                break;
            case 'C':
                c++;
                break;
            default:
                break;
        }
    }
    std::cin >> frozen.b >> frozen.s >> frozen.c;
    std::cin >> frozen.bPrice >>frozen.sPrice >> frozen.cPrice;
    std::cin >> bank;

    b == 0 ? frozen.b = 0 : b = b;
    c == 0 ? frozen.c = 0 : c = c;
    s == 0 ? frozen.s = 0 : s = s;

    while (bank>=0){

        BurgerMath(frozen.b,frozen.bPrice,b,bank,frozen.bTick);
        BurgerMath(frozen.s,frozen.sPrice,s,bank,frozen.sTick);
        BurgerMath(frozen.c,frozen.cPrice,c,bank,frozen.cTick);

        if (frozen.b == 0 & frozen.s == 0 & frozen.c == 0 & skip ){
            count += (bank)/(frozen.bPrice*b + frozen.cPrice*c + frozen.sPrice*s);
            bank = (bank)%(frozen.bPrice*b + frozen.cPrice*c + frozen.sPrice*s);
            skip = false;
        }

        if (frozen.bTick && frozen.cTick && frozen.sTick)
        {
            frozen.sTick = false;
            frozen.bTick = false;
            frozen.cTick = false;
            count++;
        }
    }
    std::cout << count;
    return 0;
}
