#include <iostream>
#include <cmath>
using namespace std;

// Вывод пирамиды
void task1() {
    int height = 20;

    for (int i = 1; i <= height; i++) {                           // запускаем цикл от 1 до 20 
        for (int j = 1; j <= height - i; j++) cout << " ";        // начало с 19 пробелов и одного Х, 
        for (int j = height; j > height - i ; j--) cout << "X";   // каждую внещнюю итерацию уменьшаем на пробел и добавляем Х
        cout << endl;
    }
}

// Вычисление факториала
void task2() {
    int num;
    long long factorial;

    while (true) {
        cout << "Введите число (0 для выхода): ";
        cin >> num;
        if (num == 0) break;

        factorial = 1;
        for (int i = 1; i <= num; i++) factorial *= i;
        
        cout << "Факториал " << num << " = " << factorial << endl;
    }
}
 
// Расчет вклада с процентами
void task3() {
    double dep, rate, income;
    int years;
    
    cout << "Введите начальный вклад: ";
    cin >> dep;
    cout << "Введите число лет: ";
    cin >> years;
    cout << "Введите процентную ставку: ";
    cin >> rate;

    cout << "\nЧерез " << years << " год(а) вы получите: " << ((dep * rate) / 100) * years << " рублей." << endl;

    for (int i = 1; i <= years; i++) {
        income += (dep * rate) / 100; // расчет по пропорции, где вклад - 100%, а прибыль - Х
        cout << "В конце " << i << "-го года процентный доход: " << income << " рублей." << endl;
    }
}

// Расчет ипотеки
void task4() {
    double price, downPayment, rate, monthlyPayment, totalAmount = 0;
    int years;
    
    cout << "Введите стоимость квартиры: ";
    cin >> price;
    cout << "Введите начальный взнос: ";
    cin >> downPayment;
    cout << "Введите число лет ипотеки: ";
    cin >> years;
    cout << "Введите процентную ставку: ";
    cin >> rate;
    cout << "\n";
    
    double credit = price - downPayment;   // расчет суммы оставшейся от стоимости квартиры за вычетом начального взноса
                                           // (суммы, облагаемой процентной ставкой)
    for (int i = 1; i <= years; i++) {
        monthlyPayment = (credit * rate) / 100;  // расчет ежемесясной процентной суммы по пропорции, где кредит - 100%, а проценты - Х
        totalAmount += monthlyPayment;                // подсчет общей суммы выплат 
        printf("Платеж за %d-й год: %.0f рублей.\n", i, monthlyPayment); // спецификатор %.0f для вывода monthlyPayment без лишних знаков
    }
    printf("Общая сумма выплат: %.0f рублей.\n", totalAmount);
}

// Сложение денежных сумм в старом формате
void task5() {
    char choice;
    do {
        int prod, pounds1, shillings1, pence1, pounds2, shillings2, pence2, sumPounds, sumShillings, sumPence;
        char dot;

        cout << "\nВведите первую денежную сумму в формате фунты.шиллинги.пенсы: ";
        cin >> pounds1 >> dot >> shillings1 >> dot >> pence1;
        cout << "Введите вторую денежную сумму в формате фунты.шиллинги.пенсы: ";
        cin >> pounds2 >> dot >> shillings2 >> dot >> pence2;

        sumPence = pence1 + pence2;
        sumShillings = shillings1 + shillings2;
        sumPounds = pounds1 + pounds2;

        if (sumPence > 11){        // заем одного шиллинга, если пенсов более 11
            sumShillings += 1;
            sumPence = 0;
        }
        if (sumShillings > 19){    // заем одного фунта, если шиллингов более 19
            sumPounds += 1;
            sumShillings = 0;
        }

        cout << "Сумма: " << sumPounds << "." << sumShillings << "." << sumPence << endl;

        cout <<"\nДля продолжения работы программы введите 1..."; // по условию после каждой итерации вопрос о продолжении
        cin >> prod;
        if (prod != 1) break;
    } while (true);
}

int main() {
    int choice;
    do {
        cout << "\nВыберите задание (1-5) или 0 для выхода: ";
        cin >> choice;
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: cout << "Выход...\n"; break;
            default: cout << "Некорректный ввод!\n";
        }
    } while (choice != 0);
    
    return 0;
}