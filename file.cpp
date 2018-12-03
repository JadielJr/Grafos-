#include "main.hpp"
using namespace std;

int isAlphaNum(const char c)
{
    if (c!=NULL){
        return (isNum(c)||isAlpha(c));
    }
}

int isNum(const char c){
    return (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9');
}
int isAlpha(const char c){
    return (c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||c=='u'||c=='i'||c=='o'||c=='p'\
            ||c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'||c=='k'||c=='l'\
            ||c=='z'||c=='x'||c=='c'||c=='v'||c=='b'||c=='n'||c=='m');
}
