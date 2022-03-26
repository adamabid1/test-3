/*
 * file:  proj4-testmain.cpp
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

#include <iostream>

#include <fstream>
#include <string>


#include "proj4-ItemInfo.hpp"
using namespace std;


int main(){
    char buffer[500];
    int count =0;
    //json capacity resize
    ItemInfo *a = new ItemInfo [6];
    
    ifstream inputFile;
    
    inputFile.open("FILE.csv");
    //test to see if the file is not opened and outputs a no
    if(!inputFile){
        char no [3] = "no";
        puts(no);
    }
    if(inputFile){
        char yes [4] = "yes";
        puts(yes);
    }
    cout.put('\n');
    
    while( inputFile.get(buffer[count])){
        if( buffer[count] == ','){
            buffer[count] = '\0';
            cout << buffer << endl;
            count = 0;
        }
        else{
            count++;
        }
    }
    
    
    
    
    
    
    
    //Test setItemId to 12345
    a[0].setItemId("12345");
    //test setItemId to 12346
    a[1].setItemId("12346");
    
    //test setDescription Mens L Graphic Tee
    a[0].setDescription("Mens L Graphic Tee");
    //test setDescription Kids M Jacket
    a[1].setDescription("Kids M Jacket");
    
    //test manCost
    a[0].setManCost("5.356");
    //test manCost
    a[1].setManCost("4.334");
    
    //test sellPrice
    a[0].setSellPrice("12.991");
    //test sellPrice
    a[1].setSellPrice("16.991");
    
    //testing display and all getters
    a[0].displayItemInfo(cout);
    
    a[1].displayItemInfo(cout);
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    //outputs the first item in the json format
    char one[20] =
    "“AarsStore”: [";
    char two[40] =
    "      “firstItem”: {";
    printCString(cout, one);
    cout.put('\n');
    printCString(cout, two);
    cout.put('\n');
    a[0].toAmazonJSON(cout);
    char three[40] =
    "}\n      \"secondItem\": {";
    printCString(cout, three);
    cout.put('\n');
    a[1].toAmazonJSON(cout);
    
    
    
    
    
    a[2].setItemId("12347");
    a[3].setItemId("12348");
    a[2].setDescription("Mens xs Graphic Tee");
    a[3].setDescription("Kids xl Jacket");
    a[2].setManCost("3.326");
    a[3].setManCost("3.394");
    a[2].setSellPrice("14.991");
    a[3].setSellPrice("12.991");
    char fi[40] =
    "}\n      \"thirdItem\": {";
    printCString(cout, fi);
    cout.put('\n');
    a[2].toAmazonJSON(cout);
    char four[40] =
    "}\n      \"fourthItem\": {";
    printCString(cout, four);
    cout.put('\n');
    a[3].toAmazonJSON(cout);
    char kap[40] =
    "}\n      \"fifthItem\": {";
    printCString(cout, kap);
    cout.put('\n');
    a[4].setItemId("12349");
    a[4].setDescription("Womens xs Graphic Tee");
    a[4].setManCost("5.326");
    a[4].setSellPrice("12.991");
    a[4].toAmazonJSON(cout);
    char ka[40] =
    "}\n";
    printCString(cout, ka);
    cout.put('\n');
    
    
    delete [] a;
    return 0;
    
}
