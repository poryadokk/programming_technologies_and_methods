#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BitString {
public:
    char str1[9], str2[9];
    char resultat[9];
    char temp1[9], temp2[9];
    int len1, len2, MaxLen, addzero1, addzero2;

    void vvodPervoiStroki();
    void vvodVtoroiIzFile();
    void obrabotka();
    void vivodRezultatov();
    void zapisVFile();

private:
    // Объявляем вспомогательные методы в классе
    void buildup0(const char* str, char* temp, int& addzero);
    void vychconjunction(const char* temp1, const char* temp2, char* resultat);
};

// ввод первой строки с клавиатуры
void BitString::vvodPervoiStroki() {
    cout << "Введите первую строку: ";
    cin >> str1;

    int len = 0;
    while (str1[len] != '\0') {
        if (str1[len] != '0' && str1[len] != '1') {
            cout << "Недопустимый символ в первой строке" << endl;
            exit(1);
        }
        len++;
    }
    len1 = len;
}

// ввод второй строки из файла
void BitString::vvodVtoroiIzFile() {
    ifstream file("b.txt");
    if (file.is_open()) {
        file >> str2;
        file.close();
    }

    int len = 0;
    while (str2[len] != '\0') {
        if (str2[len] != '0' && str2[len] != '1') {
            cout << "Недопустимый символ во второй строке" << endl;
            exit(1);
        }
        len++;
    }
    len2 = len;
}

// наращивание недостающими ведущими нулями
void BitString::buildup0(const char* str, char* temp, int& addzero) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    addzero = 8 - len;
    for (int i = 0; i < addzero; i++) {
        temp[i] = '0';
    }
    for (int i = 0; i < len; i++) {
        temp[addzero + i] = str[i];
    }
    temp[8] = '\0';
}

// вычисление конъюнкции
void BitString::vychconjunction(const char* temp1, const char* temp2, char* resultat) {
    for (int i = 0; i < 8; i++) {
        if (temp1[i] == '1' && temp2[i] == '1') {
            resultat[i] = '1';
        }
        else {
            resultat[i] = '0';
        }
    }
    resultat[8] = '\0';
}

// обработка данных
void BitString::obrabotka() {
    MaxLen = max(len1, len2);

    buildup0(str1, temp1, addzero1);
    buildup0(str2, temp2, addzero2);

    vychconjunction(temp1, temp2, resultat);
}

// вывод результатов
void BitString::vivodRezultatov() {
    cout << "Первая строка: " << temp1 << endl;
    cout << "Вторая строка: " << temp2 << endl;
    cout << "Результат конъюкции: " << resultat << endl;
}

// запись в файл
void BitString::zapisVFile() {
    ofstream file("c.txt");
    if (file.is_open()) {
        file << resultat;
        file.close();
        cout << "Результат записан в файл c.txt" << endl;
    }
}

int main() {
    BitString bitStr;

    bitStr.vvodPervoiStroki();
    bitStr.vvodVtoroiIzFile();
    bitStr.obrabotka();
    bitStr.vivodRezultatov();
    bitStr.zapisVFile();

    return 0;
}

