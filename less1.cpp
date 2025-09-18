// #include <iostream>
// #include <vector>
// #include <string>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;


int main()
{   //setLocale(LC_ALL, "Russian");


    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;


    // int x;
    // puts("Введите число");
    // scanf("%i", &x);
    // if(x>100){
    //     printf("Число %i больше, чем 100\n", x);
    //     // puts ("больше, чем 100\n");
    // }


    // int j, mass[5];

    // for(j=0; j>5; j++){
    //     mass[j] = j+1;
    // }
    // for(j=0; j<5; j++){
    //     printf("%i ", mass[j]);
    // }

    // return 0;


    // int j, del=10, mas[5] = {2, 4, 7, 0, 3};

    // for(j=0; j<5; j++){

    //     if(mas[j]!=0)
    //         printf("%f ", (float)del/mas[j]);
    // }


    // int j=0, del=10, mas[5] = {2, 4, 7, 0, 3};

    // while(j>5){ // ниразу

    //     if(mas[j]!=0){
    //         printf("%f ", (float)del/mas[j]);
    //     }
    //     j++;
    // }


    // int num;

    // do{ 
    //     printf("Введите число от 0 до 10: ");
    //     scanf("%d", &num);
    // } while ((num<0) || (num>10));

    // printf("Вы ввели число %d", num);\


    // int speed;
    // puts("Введите число 33, 45 или 78: ");
    // scanf("%i", &speed);
    // switch(speed)
    // {
    //     case 33:
    //         puts("Долгоиграющий формат\n");
    //         break;
    //     case 45:
    //         puts("Формат сигнала\n");
    //         break;
    //     case 78:
    //         puts("Устаревший формат патефона\n");
    //         break;
    //     default:
    //         puts("Ошибка, такой скорости нет.");

    // }


    unsigned int numb;
    unsigned long long fact = 1;
    cout << "Введите целое число: ";
    cin >> numb;

    for(int j=numb; j>0; j--)
        fact *= j;
    cout << "Факториал числа равен: " << fact << endl;


    

    return 0;
}
