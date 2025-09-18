// #include <iostream>
// #include <vector>
// #include <string>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;



// struct part{
//     int modelnumber;
//     int partnumber;
//     float cost;
// };



// int main()
// {   //setLocale(LC_ALL, "Russian");

//     part part1;
//     part1.modelnumber = 6244;
//     part1.partnumber = 373;
//     part1.cost = 217.55;

//     cout << "Модель: " << part1.modelnumber;
//     cout << "Деталь: " << part1.partnumber;
//     cout << "Стоимость: $" << part1.cost << endl;
//     return 0;
// }




// struct part{
//     int modelnumber;
//     int partnumber;
//     float cost;
// };
// struct part_new{
//     int modelnumber;
//     int partnumber;
//     float cost;
// };



// int main()
// {   //setLocale(LC_ALL, "Russian");

//     part part1 = {6244, 373, 217.55};
//     part_new part2;

//     cout << "Модель: " << part1.modelnumber;
//     cout << "Деталь: " << part1.partnumber;
//     cout << "Стоимость: $" << part1.cost << endl;

//     part2 = part1; // присваоение структурных переменных - ВЫЗОВЕТ ОШИБКУ

//     cout << "Модель: " << part2.modelnumber;
//     cout << "Деталь: " << part2.partnumber;
//     cout << "Стоимость: $" << part2.cost << endl;
//     return 0;
// }



// struct Distance{
//     int feet;
//     float inches;
// };



// int main()
// {   //setLocale(LC_ALL, "Russian");

//     Distance d1, d3;
//     Distance d2 = {11, 6.25};

//     cout << "\nВведите число футов: "; cin >> d1.feet;
//     cout << "\nВведите число дюймов (<12.0): "; cin >> d1.inches;

//     d3.inches = d1.inches + d2.inches;
//     d3.feet = 0;

//     if(d3.inches >= 12.0){
//         d3.inches -= 12.0;
//         d3.feet++;
//     }
//     d3.feet += d1.feet + d2.feet;

//     cout << d1.feet <<"\'"<<d1.inches<<"\" +";
//     cout << d2.feet <<"\'"<<d2.inches<<"\" =";
//     cout << d3.feet <<"\'"<<d3.inches<<"\"\n";
//     return 0;
// }



// struct Distance{
//     int feet;
//     float inches;
// };

// struct Room{
//     Distance lenght;
//     Distance width;
// };


// int main()
// {   //setLocale(LC_ALL, "Russian");

//     Room dining;
//     dining.lenght.feet = 13;
//     dining.lenght.inches = 6.5;
//     dining.width.feet = 10;
//     dining.width.inches = 0.0;

//     float l = dining.lenght.feet + dining.lenght.inches / 12;
//     float w = dining.width.feet + dining.width.inches / 12;

//     cout << "Площадь команты равна " << l*w << " квадратных футов\n";
//     return 0;
// }