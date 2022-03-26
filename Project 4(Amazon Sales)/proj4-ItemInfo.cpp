/*
 * file:  proj4-itemInfo.cpp
 * author: Adam Abid
 * course: CSI 1440
 * assignment:  project 4
 * due date:  2/28/2022
 * date modified:  2/28/2022
 *
 * This is the test driver file and
 * will test the opening of a data file and insert data
 * values in
 * an an item array
 * then output the data
 *
 */

#include <stdio.h>
#include "proj4-ItemInfo.hpp"
//this function is finished
void ItemInfo::setItemId(const char *str){
    int result = 0;
    int divison = 1;
    int count2 =0;
    int neg = 1;
    int dp =0;
    int i =0;
    
    while(str[i] != '\0'){
        if(str[i] == '.'){
            dp = i;
        }
        i++;
        
    }
    count2 = i - dp;
    
    for (int i =0; str[i] != '\0'; i++){
        
        if(str[i] == '-'){
            neg = -1;
            
        }
        
        if ( str[i] - '0' >=0 && str[i] - '0' <=9 ){
            
            result =  (result * 10) + (str[i] - '0');
            
            
        }
        
    }
    if( dp !=0){
        for ( int i=1; i< count2; i++){
            divison *= 10;
        }
    }
    
    result *= neg;
    result = result/divison;
   
    itemId = result;
     
}
//this function is finished
void ItemInfo::setDescription(const char *cstr){
    
    stuCstrCpy(description, cstr);
    
}
//function is finished
void ItemInfo::setManCost(const char *str){
    manCost = stuCstrToDbl(str);
    

    
}
//this function is finisned
void ItemInfo::setSellPrice(const char *str){
    sellPrice = stuCstrToDbl(str);
}
//funciton is finished
int ItemInfo::getItemId(){
    return this->itemId;
    
}
//function is finished
const char* ItemInfo::getDescription(){
    return description;
    
}
//funciton is finised
double ItemInfo::getManCost(){
    return manCost;
}
//funciton is finished
double ItemInfo::getSellPrice(){
    return sellPrice;
}
void ItemInfo::toAmazonJSON(ostream &out){
    
    char c [40] = "           “ItemId”:";
    printCString(out, c);
    out.put(' ');
    
    char itemId[6];
    double x = this-> itemId;
    
    stuDblToCstr( itemId, x);
    printCString(out, itemId);
    out.put('\n');
   
    
    char n [50] = "           \"Description\":";
    printCString(out, n);
    out.put(' ');
    printCString(out, description);
    out.put('\n');
  
    
    char m [50] = "           \"ManCost\":";
    printCString(out, m);
    out.put(' ');
    
    char ManCost[16];
    double y = this-> manCost;
    
    stuDblToCstr( ManCost, y);
    printCString(out, ManCost);
    out.put('\n');
    
    
    char d [1000] = "           \"SellPrice\":";
    printCString(out, d);
    out.put(' ');
    
    char sellPrice[181];
    double z = this-> sellPrice;
    
    stuDblToCstr( sellPrice, z);
    printCString(out, sellPrice);
    out.put('\n');
    out.put('\n');
    
    
    
  
    
    
    
    
    
    
    
    
    
    


    
    
}
void ItemInfo::displayItemInfo(ostream &out){
    
    char a [10] = "itemId:";
    printCString(out, a);
    out.put(' ');
    
    char itemId[6];
    double x = this-> itemId;
    
    stuDblToCstr( itemId, x);
    printCString(out, itemId);
    out.put('\n');

    
    
    char b [13] = "description:";
    printCString(out, b);
    out.put(' ');
    printCString(out, description);
    out.put('\n');
   
    
    char c [10] = "manCost:";
    printCString(out, c);
    out.put(' ');
    
    char ManCost[750];
    double y = this-> manCost;
    
    stuDblToCstr( ManCost, y);
    printCString(out, ManCost);
    out.put('\n');
    
    
    
    char d [1000] = "sellPrice:";
    printCString(out, d);
    out.put(' ');
    
    char sellPrice[300];
    double z = this-> sellPrice;
    
    stuDblToCstr( sellPrice, z);
    printCString(out, sellPrice);
    out.put('\n');
    out.put('\n');
    
    
    
    
}


//funciton is finished
double ItemInfo::calcProfit(){
    double x = getManCost() - getSellPrice();
    
    return x;
}




//funciton is finished
double stuCstrToDbl(const char *num){
    double result = 0;
    int divison = 1;
    int count2 =0;
    int neg = 1;
    int dp =0;
    int i =0;
    
    while(num[i] != '\0'){
        if(num[i] == '.'){
            dp = i;
        }
        i++;
        
    }
    count2 = i - dp;
    
    for (int i =0; num[i] != '\0'; i++){
        
        if(num[i] == '-'){
            neg = -1;
            
        }
        
        if ( num[i] - '0' >=0 && num[i] - '0' <=9 ){
            
            result =  (result * 10) + (num[i] - '0');
            
            
        }
        
    }
    if( dp !=0){
        for ( int i=1; i< count2; i++){
            divison *= 10;
        }
    }
    
    result *= neg;
    result = result/divison;
    return result;
}
//function is finished
void stuDblToCstr(char *cstr, double num){
    int beforeDecimal = static_cast<int>(num);
    int i =1;
    int size=0;
    
    
    
    char t;
    
    int temp = beforeDecimal;
    
    while (temp > 0){
        temp/=10;
        size++;
    }
    
    
    num -= beforeDecimal;
    
    
    if( num > 0 ){
        while (cstr[size +i] != '\0'){
            t = '0';
            num *= 10;
            temp = static_cast<int>(num);
            for ( int i=0; i < temp; i++){
                t++;
            }
            cstr[size +i ] = t;
            i++;
            num -= temp;
        }
        cstr[size] = '.';
        
    }
    i = 1;
    
    while(beforeDecimal > 0){
        t = '0';
        int cap = beforeDecimal % 10;
        for ( int i =0; i < cap; i++){
            t++;
            
        }
        cstr[size - i] = t;
        i++;
        beforeDecimal /= 10;
    }
    
    
    
    

    
    
    
  
    
}
//function is function
void stuCstrCpy(char *dest, const char *src){
    

    
    while (*src != '\0')
        {
            *dest = *src;
            dest++;
            src++;
        }
    *dest = '\0';
    
    
    
     


  
}
//function is finished
int stuCstrLen(const char *src){
    int length =0;
    int i =0;
    
    while ( src[i] != '\0'){
        i++;
        length++;
    }
    return length;
    
}

//function is finished
ostream& printCString(ostream &out, const char *src){
    for (int j =0; src[j] != '\0'; j++){
        cout.put(src[j]);
    }
    return cout;
}


