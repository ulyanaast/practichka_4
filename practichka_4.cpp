#include <iostream>
#include <string>
using namespace std;

void delete_simvols(string &text, char simvol, int &n) 
{
    n = text.length();
    int index = text.find(simvol);
    if (index > -1) 
    {
        for (int i = index; i < n; i++)
        {
            int count = 0;
            
            if (text[i] == simvol)
            {
                while (text[i + count] == simvol)
                {
                    ++count;
                    --n;
                }
                if (count > 0)
                    text = text.erase(i + 1, count - 1);
            }
        }
    }
}
void checking_numbers(string text, string clearWords, int &i, bool flag_number) 
{
    int n = text.length();
    char si = '...';
    while (((text[i] != ' ') && (text[i] != ',') && (text[i] != '!') && (text[i] != '?') && (text[i] != ';') && (text[i] != ':') && (text[i] != ')') && (text[i] != si) && (text[i] != '/')) && (i != n))
    {
        if (text[i] >= 48 && text[i] <= 57)
            flag_number = true;
        clearWords += text[i];
        ++i;
    }
    if (flag_number == false)
        cout << clearWords << ' ';
}

void line_search(string s) 
{
    string sub;
    int count_sub = 0;

    cout << "\nВведённая подстрока:  ";
    cin.ignore();
    getline(cin, sub);

    cout << "И\nндексы:\n";

    string s1 = "";
    for (int i = 0; i <= s.length() - sub.length(); i++) 
    {
        s1 = "";
        for (int j = i; j < sub.length() + i; j++) 
        {
            if (s[j] == sub[j - i])
                s1 = s1 + s[j];
            else 
                continue;
        }
        if (sub == s1) {
            cout << i + 1 << " ";
            count_sub += 1;
        }
    }
    cout << "\n\nНайдено: " << count_sub << " подстрок\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    bool flag = true;
    int point = 0;

    cout << "\n     МЕНЮ:\n\n Задание 1: Ввод последовательности с клавиатуры\n\n" \
        " 2 - Задание 2: Вывод отредактированного текста (удаление лишних пробелов, знаков препинания, исправление регистра букв\n" \
        " 3 - Задание 3: Вывод на экран слов последовательности, не содержащих цифр\n" \
        " 4 - Задание 4: Вывод на экран этой же последовательности, при этом удалив из всех слов заданный пользователем набор букв и (или) цифр\n" \
        " 5 - Задание 5: Линейный поиск подстроки\n" \
        " 6 - Выход из программы\n\n";

    cout << "Задание 1: Введите последовательность, пожалуйста\n";
    string text = {};
    getline(cin, text);

    while (flag)
    {
        cout << "\n  Какой пункт хотите увидеть?  ";
        cin >> point;
        switch (point)
        {
        case 2: 
        {
            int n = text.length();
            string simvols = " ,/)(!;:?";
            for (int i = 0; i < simvols.length(); i++) 
            {
                char simvol = simvols[i];
                delete_simvols(text, simvol, n);
            }
            char simvol = '.';
            int index = text.find(simvol);
            for (int i = index; i < n; i++)
            {
                int count_points = 0;
                int count_threetochie = 0;

                while (text[i + count_points] == simvol)
                    ++count_points;

                count_threetochie = count_points / 3;

                if (count_threetochie != 0)
                {
                    text = text.erase(i + 3, count_points - 3);
                    n -= count_points - 3;
                    i += 3;
                }
                if (count_points == 2)
                    text = text.erase(i + 1, 1);
            }

            for (int i = 0; i < n; i++)
                text[i] = tolower(text[i]);

            cout << "\nОтредактированный текст: " << text;
            cout << endl;
            break;
        }
        case 3:
        {
            int n = text.length();
            cout << "\nИсходный текст: " << text;
            cout << "\nСлова из последовательности без цифр: ";
            for (int i = 0; i < n; i++)
            {
                string clearWords{};
                bool flag_number = false;
                if (i == 0) 
                    checking_numbers(text,clearWords, i, flag_number);

                if (text[i] == ' ') 
                {
                    ++i;
                    checking_numbers(text,clearWords, i, flag_number);
                    --i;
                }
            }
            cout << endl;
            break;
        }
        case 4: 
        {
            int n = text.length();
            string mini_text = "";
            cout << "\nВведите набор букв и (или) цифр, который необходимо удалить из последовательности: ";
            cin >> mini_text;
            int index = -1;

            while ((index = text.find(mini_text)) != -1) 
            {
                text = text.erase(index, mini_text.length());
                n -= mini_text.length();
            }
            cout << "\nПоследовательность без заданной подстроки: " << text;
            cout << endl;
            break;
        }
        case 5: 
        {
            line_search(text);
            break;
        }
        case 6: 
        {
            cout << "\nВсего хорошего ^^\n";
            flag = false;
            break;
        }
        default:
            cout << "\nТакого пункта нет в предложенном меню, попробуйте другой :(\n";
        }
    }
    return 0;
}
