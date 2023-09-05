/*
 * Author: Celine Wang
 * Date: 8/30/2023
 * Purpose: This program uses the console to get height and width of rectangle from the user.
            Then it calculate perimeter and area of the rectangle. And displays the result of
            the conversation.
 */


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Show the name of the program.
    cout << "Rectangle Calculator\n\n";
    
    //Read values from the consle.
    double height;
    double width;
    cout << "Enter height and width: ";
    cin >> height >> width;
    
    //Calculate the perimeter and area.
    double perimeter;
    double area;
    perimeter = (height + width) * 2;
    area = height * width;
    cout << "\n\nHeight: \t" << height << endl
         << "Width: \t\t" << width << endl
         << "Perimeter: \t" << perimeter << endl
         << "Area: \t\t" << area << endl;
    
    cout << "\n\nBye!\n\n"<< endl;
    
    return 0;
}

