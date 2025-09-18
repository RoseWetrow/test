#include <iostream>

using namespace std;



// void inc(int);

// int main()
// {   //setLocale(LC_ALL, "Russian");

//     int n1 = 99;
//     cout<<"n1="<<n1<<endl;
//     inc(n1);
//     cout<<"n1="<<n1<<endl;
//     return 0;
// }

// void inc(int &numb1){ // знак амперсанта для передачи не по значению, а по ссылке (значение n1 увеличитс на 1)
//     numb1++;
// }



// void intfrac(float, float&, float&);

// int main()
// {   //setLocale(LC_ALL, "Russian");

//     float number, intpart, fracpart;
//     do{
//         cout<<"\nвведите вещественное числ, используя . :";
//         cin>>number;
//         intfrac(number, intpart, fracpart);
//         cout<<"целая часть равна "<<intpart;
//         cout<<"дробная часть равна "<<fracpart;
//     } while(number != 0.0);
//     return 0;
// }

// void intfrac(float n, float& intp, float& fracp){ // увычисление целой и дробной часть вещественного числа
//     long temp = static_cast<long>(n);
//     intp = static_cast<float>(temp);
//     fracp = n - intp;
// }



// Неполная
// struct Distcnce{
//     int feet;
//     float inches;
// }

// void scale(Disctance&, float);
// void engldisp(Disctancet);

// int main()
// {   
//     Distcnce d1 = {12, 6.5};
//     Distcnce d2 = {10, 5.5};

//     cout<<"d1 = "; engldisp(d1);
//     cout<<"\nd2 = "; engldisp(d2);

//     scale(d1, 0.5);
//     scale(d2, 0.25);

//     cout<<"\nd1 = "; engldisp(d1);
//     cout<<"\nd2 = "; engldisp(d2);

//     return 0;
// }

// void scale(Distcnce& dd, float factor){ // увычисление целой и дробной часть вещественного числа
//     float inches = (dd.feet*12 + dd.inches)*factor;
// }



// void repchar();
// void repchar(char);
// void repchar(char, int);

// int main()
// {   
//     repchar();
//     repchar('=');
//     repchar('+', 30); // С одним названием функции с разными интерфейсами
//     return 0;
// }

// void repchar(){ // увычисление целой и дробной часть вещественного числа
//     for(int j=0; j<45; j++)
//         cout<<"*";
//     cout<<endl;
// }

// void repchar(char ch){ // увычисление целой и дробной часть вещественного числа
//     for(int j=0; j<45; j++)
//         cout<<ch;
//     cout<<endl;
// }

// void repchar(char ch, int n){ // увычисление целой и дробной часть вещественного числа
//     for(int j=0; j<n; j++)
//         cout<<ch;
//     cout<<endl;
// }



// struct Distcnce{
//     int feet;
//     float inches;
// }

// void engldisp(Distcnce);
// void engldisp(float);

// int main(){
//     setlocale(LC_ALL, "Russian");
//     Distcnce d1;
//     float d2;

//     cout<<"\nВведите число футов: "; cin >> d1.feet;
//     cout<<"\nВведите число дюймов: "; cin >> d1.inches;

//     cout<<"Введите длину в дюймах: "; cin>>d2;
//     cout<<"\nd1 = ";
//     // Незаконченная
// }



// Рекурсии
// unsigned long factfunc(unsigned long);

// int main(){
//     setlocale(LC_ALL, "Russian");
//     int n;
//     unsigned long fact;
//     cout<<"Введите целое число: ";;
//     cin>>n;
//     fact = factfunc(n);
//     cout<<"факториал числа "<<n<<"равен "<<fact<<endl;

//     return 0;
// }

// unsigned long factfunc(unsigned long n){
//     if (n>1)
//         return n* factfunc(n-1);
//     else
//         return 1;
// }




// void repchar(char='*', int=45); // аргументы по умолчанию

// int main()
// {   
//     repchar();
//     repchar('=');
//     repchar('+', 30); // С одним названием функции с разными интерфейсами
//     return 0;
// }


// void repchar(char ch, int n){ // увычисление целой и дробной часть вещественного числа
//     for(int j=0; j<n; j++)
//         cout<<ch;
//     cout<<endl;
// }



// int glob;
// void somefunc();
// void otherfunc();

// main(){
//     glob = 10;
//     somefunc();
//     otherfunc();
// }

// void somefunc(){
//     int somevar;
//     float ohervar;
//     somevar = 10;
//     ohervar = 11;
//     // nextvar = 12;
//     cout<<glob<<endl;
//     int glob = 8;
//     glob = 6;
//     cout<<glob<<endl;
// }

// void otherfunc(){
//     int nextvar;
//     // somevar = 20;
//     // ohervar = 21;
//     nextvar = 22;

//     cout<<glob<<endl;
//     glob = 7;
//     cout<<glob;
// }


// Статические переменные
// float getavg(float);

// int main(){
//     setlocale(LC_ALL, "Russian");
//     float data = 1, avg;

//     while(data !=0){
//         cout<<"Введите число: ";
//         cin >> data;
//         avg = getavg(data);
//         cout<<"Среднее значение: "<<avg<<endl;
//     }
//     return 0;
// }

// float getavg(float newdata){ // возвращает среднее значение
//     static float total = 0; // Статические переменные создаются один раз при первом вызове (инициилизируются один раз). При завершении функци переменные сохраняются.
//     static int count = 0;
//     count++;
//     total += newdata;
//     return total/count;
// }



void aFunc(int& a, const int& b)

int main(){
    int alpha = 7;
    int beta = 11;
    cout<<alpha<<" "<<beta<<endl;
    aFunc(alpha, beta);
    cout<<alpha<<" "<<beta<<endl;
    return 0;
}

void aFunc(int& a, const int& b){ // возвращает среднее значение
   a = 107;
   b = 111; // нельзя изменить, так как константа
}
