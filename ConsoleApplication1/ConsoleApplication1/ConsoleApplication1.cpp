﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Структура для хранения информации о кандидате
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

/// <summary>
/// Функция рандомного числа
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
int GetRandomNumber(int min, int max)
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    return min + rand() % (max - min + 1);
}

//bool UnitTest()
//{
//    bool *bools{ new bool[100] {} };
//
//    for (int i = 0; i < sizeof(bools); i++)
//    {
//        if (GetRandomNumber(0, 100) > 70)
//            bools[i] = false;
//    }
//    return false;
//}

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    setlocale(LC_ALL, "");
    cout << "Голосование за выбор старосты!" << endl;

    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // Увеличение количества голосов кандидата
        candidates[choice - 1].votes++;
    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

    // Вывод результатов голосования
    int n = GetRandomNumber(0, 100);
    if (GetRandomNumber(0, 100) > 70)
    {
        cout << "Результаты голосования:" << endl;
        for (int i = 0; i < candidates.size(); i++) {
            cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << endl;
        }
    }
    else
    {
        cout << "Голосование отменено" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    // Ввод количества кандидатов
    int numCandidates;
    cout << "Введите количество кандидатов: ";
    cin >> numCandidates;

    // Ввод имён кандидатов
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Введите имя кандидата #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}