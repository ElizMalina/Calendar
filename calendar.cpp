#include <iostream>
#include <fstream>

const char* name_month(int month);
int** create2dArray(int rows, int cols);
int end_day(int month, int year);
int ves_year(int year);
int one_day(int month, int year);


int main(int argc, char* argv[])
{
    if (argc == 2) {
        int year = atoi(argv[1]);
        int rows = 6;
        int cols = 21;

        int** M = create2dArray(rows, cols);
        if (M == nullptr) {
            std::cout << "Error" << std::endl;
            return 1;
        }

        std::cout << year << std::endl;
        std::cout << "January               February              March" << std::endl;
        std::cout << "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa" << std::endl;


        int start_1 = one_day(1, year);
        int end_1 = end_day(1, year);
        int start_2 = one_day(2, year);
        int end_2 = end_day(2, year);
        int start_3 = one_day(3, year);
        int end_3 = end_day(3, year);

        int number_1 = 1;
        int number_2 = 1;
        int number_3 = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j < 7) {
                    if ((j < start_1 && i == 0) || (i != 0 && number_1 > end_1)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_1;
                        ++number_1;
                    }
                }

                else if (j > 6 && j < 14) {
                    if ((j - 7 < start_2 && i == 0) || (i != 0 && number_2 > end_2)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_2;
                        ++number_2;
                    }
                }

                else {
                    if ((j - 14 < start_3 && i == 0) || (i != 0 && number_3 > end_3)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_3;
                        ++number_3;
                    }
                }

            }
        }

        int count_end{};
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((j <= 6 && M[i][j] == end_1) || (j >= 7 && j <= 13 && M[i][j] == end_2) || (j >= 14 && M[i][j] == end_3)) {
                    ++count_end;
                }
                if (count_end == 3) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == end_3 && j >= 14) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == 0) {
                    if (j == 6 || j == 13) {
                        std::cout << "    ";
                    }
                    else {
                        std::cout << "   ";
                    }
                }
                else if (M[i][j] < 10) {
                    if (j == 6 || j == 13) {
                        std::cout << ' ' << M[i][j] << "  ";
                    }
                    else if (j == 20) {
                        std::cout << ' ' << M[i][j];
                    }
                    else {
                        std::cout << ' ' << M[i][j] << ' ';
                    }
                }
                else {
                    if (j == 6 || j == 13) {
                        std::cout << M[i][j] << "  ";
                    }
                    else if (j == cols - 1) {
                        std::cout << M[i][j];
                    }
                    else {
                        std::cout << M[i][j] << ' ';
                    }
                }
            }
            std::cout << "\n";
            if (count_end == 3) {
                break;
            }
        }
        std::cout << "\n";


        std::cout << "April                 May                   June" << std::endl;
        std::cout << "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa" << std::endl;

        int start_4 = one_day(4, year);
        int end_4 = end_day(4, year);
        int start_5 = one_day(5, year);
        int end_5 = end_day(5, year);
        int start_6 = one_day(6, year);
        int end_6 = end_day(6, year);

        int number_4 = 1;
        int number_5 = 1;
        int number_6 = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j < 7) {
                    if ((j < start_4 && i == 0) || (i != 0 && number_4 > end_4)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_4;
                        ++number_4;
                    }
                }

                else if (j > 6 && j < 14) {
                    if ((j - 7 < start_5 && i == 0) || (i != 0 && number_5 > end_5)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_5;
                        ++number_5;
                    }
                }

                else {
                    if ((j - 14 < start_6 && i == 0) || (i != 0 && number_6 > end_6)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_6;
                        ++number_6;
                    }
                }

            }
        }

        count_end = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((j <= 6 && M[i][j] == end_4) || (j >= 7 && j <= 13 && M[i][j] == end_5) || (j >= 14 && M[i][j] == end_6)) {
                    ++count_end;
                }
                if (count_end == 3) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == end_6 && j >= 14) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == 0) {
                    if (j == 6 || j == 13) {
                        std::cout << "    ";
                    }
                    else {
                        std::cout << "   ";
                    }
                }
                else if (M[i][j] < 10) {
                    if (j == 6 || j == 13) {
                        std::cout << ' ' << M[i][j] << "  ";
                    }
                    else if (j == 20) {
                        std::cout << ' ' << M[i][j];
                    }
                    else {
                        std::cout << ' ' << M[i][j] << ' ';
                    }
                }
                else {
                    if (j == 6 || j == 13) {
                        std::cout << M[i][j] << "  ";
                    }
                    else if (j == cols - 1) {
                        std::cout << M[i][j];
                    }
                    else {
                        std::cout << M[i][j] << ' ';
                    }
                }
            }
            std::cout << "\n";
            if (count_end == 3) {
                break;
            }
        }
        std::cout << "\n";


        std::cout << "July                  August                September" << std::endl;
        std::cout << "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa" << std::endl;

        int start_7 = one_day(7, year);
        int end_7 = end_day(7, year);
        int start_8 = one_day(8, year);
        int end_8 = end_day(8, year);
        int start_9 = one_day(9, year);
        int end_9 = end_day(9, year);

        int number_7 = 1;
        int number_8 = 1;
        int number_9 = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j < 7) {
                    if ((j < start_7 && i == 0) || (i != 0 && number_7 > end_7)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_7;
                        ++number_7;
                    }
                }

                else if (j > 6 && j < 14) {
                    if ((j - 7 < start_8 && i == 0) || (i != 0 && number_8 > end_8)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_8;
                        ++number_8;
                    }
                }

                else {
                    if ((j - 14 < start_9 && i == 0) || (i != 0 && number_9 > end_9)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_9;
                        ++number_9;
                    }
                }

            }
        }

        count_end = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((j <= 6 && M[i][j] == end_7) || (j >= 7 && j <= 13 && M[i][j] == end_8) || (j >= 14 && M[i][j] == end_9)) {
                    ++count_end;
                }
                if (count_end == 3) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == end_9 && j >= 14) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == 0) {
                    if (j == 6 || j == 13) {
                        std::cout << "    ";
                    }
                    else {
                        std::cout << "   ";
                    }
                }
                else if (M[i][j] < 10) {
                    if (j == 6 || j == 13) {
                        std::cout << ' ' << M[i][j] << "  ";
                    }
                    else if (j == 20) {
                        std::cout << ' ' << M[i][j];
                    }
                    else {
                        std::cout << ' ' << M[i][j] << ' ';
                    }
                }
                else {
                    if (j == 6 || j == 13) {
                        std::cout << M[i][j] << "  ";
                    }
                    else if (j == cols - 1) {
                        std::cout << M[i][j];
                    }
                    else {
                        std::cout << M[i][j] << ' ';
                    }
                }
            }
            std::cout << "\n";
            if (count_end == 3) {
                break;
            }
        }
        std::cout << "\n";


        std::cout << "October               November              December" << std::endl;
        std::cout << "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa" << std::endl;

        int start_10 = one_day(10, year);
        int end_10 = end_day(10, year);
        int start_11 = one_day(11, year);
        int end_11 = end_day(11, year);
        int start_12 = one_day(12, year);
        int end_12 = end_day(12, year);

        int number_10 = 1;
        int number_11 = 1;
        int number_12 = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j < 7) {
                    if ((j < start_10 && i == 0) || (i != 0 && number_10 > end_10)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_10;
                        ++number_10;
                    }
                }

                else if (j > 6 && j < 14) {
                    if ((j - 7 < start_11 && i == 0) || (i != 0 && number_11 > end_11)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_11;
                        ++number_11;
                    }
                }

                else {
                    if ((j - 14 < start_12 && i == 0) || (i != 0 && number_12 > end_12)) {
                        M[i][j] = 0;
                    }
                    else {
                        M[i][j] = number_12;
                        ++number_12;
                    }
                }

            }
        }

        count_end = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((j <= 6 && M[i][j] == end_10) || (j >= 7 && j <= 13 && M[i][j] == end_11) || (j >= 14 && M[i][j] == end_12)) {
                    ++count_end;
                }
                if (count_end == 3) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == end_12 && j >= 14) {
                    std::cout << M[i][j];
                    break;
                }
                if (M[i][j] == 0) {
                    if (j == 6 || j == 13) {
                        std::cout << "    ";
                    }
                    else {
                        std::cout << "   ";
                    }
                }
                else if (M[i][j] < 10) {
                    if (j == 6 || j == 13) {
                        std::cout << ' ' << M[i][j] << "  ";
                    }
                    else if (j == 20) {
                        std::cout << ' ' << M[i][j];
                    }
                    else {
                        std::cout << ' ' << M[i][j] << ' ';
                    }
                }
                else {
                    if (j == 6 || j == 13) {
                        std::cout << M[i][j] << "  ";
                    }
                    else if (j == cols - 1) {
                        std::cout << M[i][j];
                    }
                    else {
                        std::cout << M[i][j] << ' ';
                    }
                }
            }
            std::cout << "\n";
            if (count_end == 3) {
                break;
            }
        }
        for (int i = 0; i < rows; ++i) {
            delete[] M[i];
        }

        delete[] M;
    }
    else if (argc == 3) {
        int month = atoi(argv[1]);
        int year = atoi(argv[2]);

        std::cout << year << std::endl;
        std::cout << name_month(month) << std::endl;
        std::cout << "Su Mo Tu We Th Fr Sa" << std::endl;

        int rows = 6;
        int cols = 7;

        int** M = create2dArray(rows, cols);
        if (M == nullptr) {
            std::cout << "Error" << std::endl;
            return 2;
        }
        int start = one_day(month, year);
        int end = end_day(month, year);
        int number = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i == 0 && j < start) || (i != 0 && number > end)) {
                    M[i][j] = 0;
                }
                else {
                    M[i][j] = number;
                    ++number;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (M[i][j] == end) {
                    std::cout << M[i][j];
                    flag = false;
                }
                else if (M[i][j] == 0 && !flag) {
                    std::cout << "";
                }
                else if (M[i][j] == 0) {
                    std::cout << "   ";
                }
                else if (M[i][j] < 10) {
                    if (j == cols - 1) {
                        std::cout << ' ' << M[i][j];
                    }
                    else {
                        std::cout << ' ' << M[i][j] << ' ';
                    }
                }
                else {
                    if (j == cols - 1) {
                        std::cout << M[i][j];
                    }
                    else {
                        std::cout << M[i][j] << ' ';
                    }
                }
            }
            if (flag) {
                std::cout << "\n";

            }
            else {
                std::cout << "\n";
                break;
            }
        }
        for (int i = 0; i < rows; ++i) {
            delete[] M[i];
        }

        delete[] M;
    }
}

//определяем название месяца 

const char* name_month(int month) { 
    if (month == 1) {
        return "January";
    }
    if (month == 2) {
        return "February";
    }
    if (month == 3) {
        return "March";
    }
    if (month == 4) {
        return "April";
    }
    if (month == 5) {
        return "May";
    }
    if (month == 6) {
        return "June";
    }
    if (month == 7) {
        return "July";
    }
    if (month == 8) {
        return "August";
    }
    if (month == 9) {
        return "September";
    }
    if (month == 10) {
        return "October";
    }
    if (month == 11) {
        return "November";
    }
    return "December";
}

// создаем двумерный массив

int** create2dArray(int rows, int cols) {
    int** M = new int* [rows];
    if (M == nullptr) {
        return M;
    }

    for (int i = 0; i < rows; ++i) {
        M[i] = new int[cols];
        if (M[i] == nullptr) {
            for (int j = 0; j < i; ++j) {
                delete[] M[j];
            }
            delete[] M;
            return nullptr;
        }
    }
    return M;
}

//вычисляем день недели для первого числа этого месяца

int one_day(int month, int year) {
    int q = (14 - month) / 12;
    int w = year - q;
    int s = month + 12 * q - 2;
    int one_day = (1 + w + w / 4 - w / 100 + w / 400 + (31 * s) / 12) % 7;
    return one_day;
}

//считаем сколько дней в данном месяце и году 

int end_day(int month, int year) {
    int K[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (ves_year(year) == 1) {
        K[1] = 29;
    }
    return K[month - 1];
}

//проверка на весокосный год

int ves_year(int year) {
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

