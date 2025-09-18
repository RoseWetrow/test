#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;



// enum days_of_week {Sun = 7, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6};

// int main()
// {   //setLocale(LC_ALL, "Russian");

//     days_of_week day1, day2;

//     day1 = Mon;
//     day2 = Thu;
//     cout << day1 << " " << day2 << endl;
//     int diff = day2 - day1;
//     cout << "Разница в днях: " << diff << endl;

//     if(day1<day2)
//         cout << "day1 наступит раньше, чем day2\n";
//     return 0;
// }



// Объединение
// union types{
//     int f;
//     unsigned char b[4];
// };

// int main()
// {   //setLocale(LC_ALL, "Russian");

//     types value;

//     printf("N = ");
//     scanf("%d", &value.f);
//     printf("%d = %x %x %x %x", value.f, value.b[0], value.b[1], value.b[2], value.b[3]);
//     //getchar();    
//     //getchar();    
//     return 0;
// }



// union types{
//     int f;
//     char c;
//     long double ld;
//     int i;
// };

// int main()
// {   //setLocale(LC_ALL, "Russian");

//     types value;

//     value.ld - 0; // Обнулим память (все 16 байт)
//     cout << sizeof (types)<<endl;
//     value.c = 33;
//     cout << value.c <<endl;
//     cout << value.i <<endl<<endl;

//     value.f = 256;
//     cout << value.f <<endl;
//     cout << value.ld <<endl;
//     cout << value.i <<endl<<endl;

//     value.ld = 257;
//     cout << value.ld <<endl;
//     cout << value.ld <<endl<<endl;

//     //getchar();    
//     //getchar();    
//     return 0;
// }



// void starline(); // объявление функции (прототип)


// int main()
// {   //setLocale(LC_ALL, "Russian");

//     starline();
//     cout << "Тип джанных Диапазон" << endl;
//     starline();
//     cout << "char        -128...127" << endl
//     << "short            -37,768...32,767" << endl
//     << "int              систмено-зависимый" << endl
//     << "long             -2,148,483...2,147,483,647" << endl;
//     starline();

//     return 0;
// }


// void starline(){
//     for(int j=0; j<45; j++)
//         cout << "*";
//     cout << endl;
// }



// void repchar(char ch, int n){
//     for(int j=0; j<n; j++)
//         cout << ch;
//     cout << endl;
// }


// int main()
// {   //setLocale(LC_ALL, "Russian");

//     repchar('-', 43);
//     cout << "Тип джанных Диапазон" << endl;
//     repchar('=', 43);
//     cout << "char        -128...127" << endl
//     << "short            -37,768...32,767" << endl
//     << "int              систмено-зависимый" << endl
//     << "long             -2,148,483...2,147,483,647" << endl;
//     repchar('-', 43);

//     return 0;
// }





