#include <iostream>
// #include <cstring>
#include <windows.h>
using namespace std;



// структура для дробных чисел
struct fraction {
    double value;
};

// Вычисление среднего значения дробных чисел
void task1() {
    int n;
    cout << "\nВведите количество чисел: ";
    cin >> n;
    fraction arr[n];
    double sum = 0;

    // ввод чисел
    for (int i = 0; i < n; i++) {
        cout << "Введите дробное число " << i + 1 << ": ";
        cin >> arr[i].value; 
        sum += arr[i].value;   // складывание значений
    }

    double average = sum / n;  // вычисление среднего
    cout << "Среднее значение: " << average << endl;
}



// Поиск максимального элемента в массиве
int maxint(int arr[], int size) {
    int maxIndex = 0; 
    for (int i = 1; i < size; i++) {    // перебор элементов массива 
        if (arr[i] > arr[maxIndex]) {   // и сравнение его с maxIndex
            maxIndex = i; 
        }
    }
    return maxIndex;
}

void task2() {
    int n;
    cout << "\nВведите количество элементов: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {  // ввод целых чисел
        cout << "Введите число " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    int maxIndex = maxint(arr, n); // находим индекс максимального элемента
    cout << "Максимальный элемент: " << arr[maxIndex] << " с индексом " << maxIndex << endl;
}



// Реверс строки
void reversit(char str[]) {
    int len = strlen(str);               // получаем длину строки
    for (int i = 0; i < len / 2; i++) {  // меняем местами четное количество слов в строке
        swap(str[i], str[len - i - 1]);  // вначале первый с последним, второй с предпоследним...
    }
    cout << str << endl;
}

void task3() {
    setlocale(LC_ALL, "Russian"); // getline не работает с русскими символами всеравно

    char str[100];
    cout << "\nВведите строку: ";
    cin.ignore();             // игнорируем предыдущий перевод строки
    cin.getline(str, 100);   // считываем строку с пробелами
    cout << "Введенная строка: " << str << endl; // выводим введенную строку для проверки
    reversit(str);
    cout << "Перевернутая строка: " << str << endl;
}



struct employee {
    char name[50]; // массив для хранения имени
    long number;   // номер служащего
};

// Получение данных от пользователя и сохранение в struct
void getdata(employee &e) {
    cout << "Введите имя: ";
    cin.ignore();            // очищаем от ненужных символов
    cin.getline(e.name, 50); // ввод с учетом пробелов
    cout << "Введите номер: ";
    cin >> e.number;
}

// Вывод данных
void putdata(const employee &e) {
    cout << "Имя: " << e.name << ", Номер: " << e.number << endl;
}

void task4() {
    employee employees[3]; // массив из трех работников
    
    cout << "\nВведите данные работников" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Сотрудник " << i + 1 << ". ";
        getdata(employees[i]); // ввод данных 
    }

    cout << "\nДанные всех работников:" << endl;
    for (int i = 0; i < 3; i++) {
        putdata(employees[i]); // вывод данных 
    }
}



struct Distance {
    int feet;      // футы
    int inches;  // дюймы
};

// Вычисление среднего значения интервалов
Distance averageDistance(Distance arr[], int size) {
    int totalFeet = 0;
    int totalInches = 0;

    // суммируем все интервалы
    for (int i = 0; i < size; i++) {
        totalFeet += arr[i].feet;
        totalInches += arr[i].inches;
    }

    int totalAllInches = totalFeet * 12 + totalInches; // переводим всё в дюймы
    int avgTotalInches = totalAllInches / size; // вычисляем среднее значение в дюймах

    // Конвертируем обратно в футы и дюймы
    int avgFeet = avgTotalInches / 12;    // получаем футы
    int avgInches = avgTotalInches % 12;  // остаток от деления 
                                          // равносильно, как остаток (долю от футов) умножить на 12

    return {avgFeet, avgInches}; // делим общее количество
}

void task5() {
    Distance distances[5]; // массив из 5 интервалов типа struct
    
    for (int i = 0; i < 5; i++) { // ввод данных
        cout << "Введите расстояние " << i + 1 << " (футы и дюймы через пробел): ";
        cin >> distances[i].feet >> distances[i].inches;
    }
    
    Distance avgDistances = averageDistance(distances, 5); // вычисляем среднее значение
    cout << "Среднее расстояние: " << avgDistances.feet << " футов " << avgDistances.inches << " дюймов" << endl;
}



int main() {
    
    int choice;
    do {
        cout << "Выберите задание (1-5, 0 для выхода): ";
        cin >> choice;
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: cout << "Выход..." << endl; break;
            default: cout << "Неверный ввод!" << endl;
        }
    } while (choice != 0);
    return 0;
}
