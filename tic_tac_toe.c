#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void hide_cursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

void color(int x) {
    if (x >= 0 && x <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  

int get_key() {
    int input = 0;
    while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '6' && input != '7' && input != '8' && input != '9' && input != '0' && input != 27 && input != 8 && input != 13) {
    input = getch();
    }
    if (input == '1') {
        return 1;
    } else if (input == '2') {
        return 2;
    } else if (input == '3') {
        return 3;
    } else if (input == '4') {
        return 4;
    } else if (input == '5') {
        return 5;
    } else if (input == '6') {
        return 6;
    } else if (input == '7') {
        return 7;
    } else if (input == '8') {
        return 8;
    } else if (input == '9') {
        return 9;
    } else if (input == '0') {
        return 0;
    //escape
    } else if (input == 27) {
        return 10;
    //backspace
    } else if (input == 8) {
        return 11;
    //enter
    } else if (input == 13) {
        return 12;
    }
}

int get_pointer() {
    int input = 0;
    while (input != 13 && input != 80 && input != 72 && input != 75 && input != 77 && input != 27) {
    input = getch();
    //escape
    if (input == 27) {
        return 0;
    //enter
    } else if (input == 13) {
        return 5;
    //стрелка вверх
    } else if (input == 72) {
        return 1;
    //стрелка вниз
    } else if (input == 80) {
        return 2;
    //стрелка влево
    } else if (input == 75) {
        return 3;
    //стрелка вправо
    } else if (input == 77) {
        return 4;
    }
    }
}
//переделать через get_key()
int get_option(int option) {
    int input = getch();
    while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != 27 && input != 13 && input != 80 && input != 72) {
    input = getch();
    }
    if (input == '1') {
        option = 1;
        return option;
    } else if (input == '2') {
        option = 2;
        return option;
    } else if (input == '3') {
        option = 3;
        return option;
    } else if (input == '4') {
        option = 4;
        return option;
    } else if (input == '5') {
        option = 5;
        return option;
    //escape    
    } else if (input == 27) {
        return 11;
    //enter
    } else if (input == 13) {
        if (option == 1) {
            return option + 5;
        } else if (option == 2) {
            return option + 5;
        } else if (option == 3) {
            return option + 5;
        } else if (option == 4) {
            return option + 5;
        } else if (option == 5) {
            return option + 5;
        }
    //стрелка вниз
    } else if (input == 80) {
        option += 1;
        if (option > 5) {
            option = 1;
        }
        return option;
    //стрелка вниз
    } else if (input == 72) {
        option -= 1;
        if (option < 1) {
            option = 5;
        }
        return option;
    } 

}

void size_menu(int option) {
    if (option == 6) {
        printf("\n============================\n");
        printf("Введите ширину поля\n");
        printf("2 <= Ширина <= 14\n");
        printf("============================\n");
        printf("Backspace - Стереть значение\n");
        printf("============================\n");
    } else if (option == 7) {
        printf("\n============================\n");
        printf("Введите высоту поля\n");
        printf("2 <= Высота <= 14\n");
        printf("============================\n");
        printf("Backspace - Стереть значение\n");
        printf("============================\n");
    } else if (option == 8) {
        printf("\n======================================\n");
        printf("Введите число - условие победы крестиков\n");
        printf("2 <= Число <= 14\n");
        printf("========================================\n");
        printf("Backspace - Стереть значение\n");
        printf("========================================\n");
    } else if (option == 9) {
        printf("\n====================================\n");
        printf("Введите число - условие победы ноликов\n");
        printf("2 <= Число <= 14\n");
        printf("======================================\n");
        printf("Backspace - Стереть значение\n");
        printf("======================================\n");
    }
}

int size_increase(int input, int size) {
    int add = input;
    int size_new = size * 10 + add;
    if (size_new <= 14) {
        size = size_new;
        return size;
    } else {
        size = size;
        return size;
    }
    
}

int size_input(int option) {
    system("cls");
    int size = 0, key = 0;
    printf("%d", size);

    while (key != 12 || size < 2) {
        size_menu(option);
        key = get_key();
        system("cls");

        if (key == 1) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 2) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 3) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 4) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 5) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 6) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 7) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 8) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 9) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 0) {
            size = size_increase(key, size);
            printf("%d", size);
        } else if (key == 11) {
            size = 0;
            printf("%d", size);
        } else {
            printf("%d", size);
        }
        

    }
    return size;

}

void options_menu(int option, int width, int height, int x_condition, int o_condition) {
    if (option == 1) {
        printf(" 1) Ширина поля - %d <--\n", width);
    } else {
        printf("1) Ширина поля - %d\n", width);
    }

    if (option == 2) {
        printf(" 2) Высота поля - %d <--\n", height);
    } else {
        printf("2) Высота поля поля - %d\n", height);
    }

    if (option == 3) {
        printf(" 3) Условие победы для крестиков - %d <--\n", x_condition);
    } else {
        printf("3) Условие победы для крестиков - %d\n", x_condition);
    }

    if (option == 4) {
        printf(" 4) Условие победы для ноликов - %d <--\n", o_condition);
    } else {
        printf("4) Условие победы для ноликов - %d\n", o_condition);
    }

    if (option == 5) {
        printf(" 5) Играть <--\n", o_condition);
    } else {
        printf("5) Играть\n", o_condition);
    }

}

void main_menu(int option, int width, int height, int x_condition, int o_condition) {
    system("cls");
    printf("Добро пожаловать в ");
    color(4);
    printf("КРЕСТИКИ");
    color(7);
    printf("-");
    color(3);
    printf("НОЛИКИ\n");
    color(7);
    printf("Пожалуйста, задайте параметры игры\n");
    printf("=====================================\n");
    options_menu(option, width, height, x_condition, o_condition);
    printf("=====================================\n");
    printf("Enter - Подтвердить выбор\n");
    printf("Escape - Выйти из игры\n");
}

void game_menu(int turn, int part) {
    if (part == 1) {
        if (turn % 2 == 0) {
            printf("Ходят ");
            color(4);
            printf("КРЕСТИКИ!\n");
            color(7);
            printf("==========================================\n");
            printf("Перемещение осуществляется через стрелки\n");
            printf("Enter - Подтвердить ход\n");
            printf("==========================================\n");
        } else {
            printf("Ходят ");
            color(3);
            printf("НОЛИКИ!\n");
            color(7);
            printf("==========================================\n");
            printf("Перемещение осуществляется через стрелки\n");
            printf("Enter - Подтвердить ход\n");
            printf("==========================================\n");
        }
    } else if (part == 2) {
        printf("\n\n==========================================\n");
    }
}

int array_search(int number_1, int number_2, int X[], int Y[], size_t size_X, size_t size_Y) {
    for (int i = 0; i < size_Y; i++) {
        for (int j = 0; j < size_X; j++) {
            if (i == j && X[j] == number_1 && Y[i] == number_2) {
                if (i % 2 == 0) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int victory_check(int X[], int Y[], int x_condition, int o_condition, int width, int height, int len_x, int len_y, int turn) {
    int victory_1_x = 0, victory_1_o = 0;
    int victory_2_x = 0, victory_2_o = 0;
    int victory_3_x = 0, victory_3_o = 0;
    int victory_4_x = 0, victory_4_o = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (array_search(j, i, X, Y, len_x, len_y) == 2) {
                for (int h_x = 0; h_x < x_condition; h_x++) {
                    //диагональ 1 (крестики)
                    if (array_search(j + h_x, i + h_x, X, Y, len_x, len_y) == 2) {
                        victory_1_x += 1;
                        if (victory_1_x == x_condition) {
                            return 2;
                        }
                    }
                    //дигональ 2 (крестики)
                    if (array_search(j - h_x, i + h_x, X, Y, len_x, len_y) == 2) {
                        victory_2_x += 1;
                        if (victory_2_x == x_condition) {
                            return 2;
                        } 
                    }    
                    //горизонталь (крестики)
                    if (array_search(j + h_x, i, X, Y, len_x, len_y) == 2) {
                        victory_3_x += 1;
                        if (victory_3_x == x_condition) {
                            return 2;
                        } 
                    }
                    //вертикаль (крестики)
                    if (array_search(j, i + h_x, X, Y, len_x, len_y) == 2) {
                        victory_4_x += 1;
                        if (victory_4_x == x_condition) {
                            return 2;
                        } 
                    }

                }

                victory_1_x = 0;
                victory_2_x = 0;
                victory_3_x = 0;
                victory_4_x = 0;

            } else {
            for (int g_x = 0; g_x < x_condition; g_x++) {
                //дигональ 1 (нолики)
                if (array_search(j + g_x, i + g_x, X, Y, len_x, len_y) == 1) {
                    victory_1_o += 1;
                    if (victory_1_o == o_condition) {
                        return 1;
                    }
                }
                //диагональ 2 (нолики)
                if (array_search(j - g_x, i + g_x, X, Y, len_x, len_y) == 1) {
                    victory_2_o += 1;
                    if (victory_2_o == o_condition) {
                        return 2;
                    } 
                }
                //горизонталь (нолики)
                if (array_search(j + g_x, i, X, Y, len_x, len_y) == 1) {
                        victory_3_o += 1;
                        if (victory_3_o == o_condition) {
                            return 1;
                        } 
                    }
                //вертикаль (нолики)
                if (array_search(j, i + g_x, X, Y, len_x, len_y) == 1) {
                    victory_4_o += 1;
                    if (victory_4_o == o_condition) {
                        return 1;
                    } 
                }
            }

            victory_1_o = 0;
            victory_2_o = 0;
            victory_3_o = 0;
            victory_4_o = 0;

            }
        }
    }

    if (turn == height * width - 1) {
        return 3;
    }

    return 0;
}

void game(int width, int height, int X_coord_x, int X_coord_y, int O_coord_x, int O_coord_y, int x_condition, int o_condition) {
    system("cls");
    int pointer_coord_x = 0, pointer_coord_y = 0;
    int pointer = 0, victory = 0, turn = 0;
    char const* A[height][width];
    int X[height * width], Y[height * width];
    int cnt = 0, len_x = 0, len_y = 0;
    int confirm = 0, quit = 0;

    for (int i = 0; i < height * width; i++) {
        X[i] = 15;
    }

    for (int i = 0; i < height * width; i++) {
        Y[i] = 15;
    }

    

    while (quit == 0) {
        system("cls");
        game_menu(turn, 1);

        len_x = sizeof(X)/sizeof(int);
        len_y = sizeof(Y)/sizeof(int);
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width ; ++j) {
                if (j == pointer_coord_x && i == pointer_coord_y) {
                    A[i][j] = "|*|";
                } else if (array_search(j, i, X, Y, len_x, len_y) == 2) {
                    A[i][j] = "|X|";
                } else if (array_search(j, i, X, Y, len_x, len_y) == 1) {
                    A[i][j] = "|O|";
                } else {
                    A[i][j] = "|_|";
                }
            }
        }

        //вывод поля
        for (int i = 0; i < height; ++i) {
            printf("\n");
            for (int j = 0; j < width; ++j) {
                if (A[i][j] == "|X|") {
                    color(4);
                    printf("%3s", A[i][j]);
                    color(7);
                } else if  (A[i][j] == "|O|") {
                    color(3);
                    printf("%3s", A[i][j]);
                    color(7);
                } else if (array_search(pointer_coord_x, pointer_coord_y, X, Y, len_x, len_y) == 2 && A[i][j] == "|*|") {
                    color(4);
                    printf("%3s", A[i][j]);
                    color(7);
                } else if (array_search(pointer_coord_x, pointer_coord_y, X, Y, len_x, len_y) == 1 && A[i][j] == "|*|") {
                    color(3);
                    printf("%3s", A[i][j]);
                    color(7);
                } else {
                    printf("%3s", A[i][j]);
                }
            }
        }
        
        //нижняя часть меню
        game_menu(turn, 2);

        if (victory == 1) {
            color(3);
            printf("ПОБЕДИЛИ НОЛИКИ!!!\n");
            color(7);
            printf("==========================================\n");
            printf("Нажмите Enter чтобы продолжить...");
            while (confirm != 12) {
                confirm = get_key();
            }
            break;
        } else if (victory == 2) {
                color(4);
                printf("ПОБЕДИЛИ КРЕСТИКИ!!!\n");
                color(7);
                printf("==========================================\n");
                printf("Нажмите Enter чтобы продолжить...");
                while (confirm != 12) {
                    confirm = get_key();
                }
                break;
        } else if (victory == 3) {
            color(2);
            printf("НИЧЬЯ!!!\n");
            color(7);
            printf("==========================================\n");
            printf("Нажмите Enter чтобы продолжить...");
            while (confirm != 12) {
                confirm = get_key();
            }
            break;
        }
        
        //перемещение
        pointer = get_pointer();
        if (pointer == 1) {
            if (pointer_coord_y > 0) {
            pointer_coord_y -= 1;
            }
        } else if (pointer == 2) {
            if (pointer_coord_y < height - 1) {
            pointer_coord_y += 1;
            }
        } else if (pointer == 3) {
            if (pointer_coord_x > 0) {
            pointer_coord_x -= 1;
            }
        } else if (pointer == 4) {
            if (pointer_coord_x < width - 1) {
            pointer_coord_x += 1;
            }
        } else if (pointer == 5) {
            if (array_search(pointer_coord_x, pointer_coord_y, X, Y, len_x, len_y) > 0) {
                color(4);
                printf("Эта клетка уже занята\n");
                printf("Пожалуйста, выберите другой ход...\n");
                getch();
                color(7);
            } else {

            X[turn] = pointer_coord_x;
            Y[turn] = pointer_coord_y;

            if (pointer_coord_y == height - 1) {
                pointer_coord_y -= 1;
            } else {
                pointer_coord_y += 1;
            }

            //проверка на победу
            victory = victory_check(X, Y, x_condition, o_condition, width, height, len_x, len_y, turn);
            
            turn++;
            }
        } else if (pointer == 0) {
            break;
        }
        
        
    }
}

int main() {
    static int option = 1, width = 2, height = 2;
    static int x_condition = 2, o_condition = 2;
    int quit = 0;

    hide_cursor();

    while (quit == 0) {
        main_menu(option, width, height, x_condition, o_condition);
        option = get_option(option);

        int X_coord_x = 1, X_coord_y = 1;
        int O_coord_x = width, O_coord_y = height;

        if (option == 11) {
            quit = 1;
        } else if (option == 6) {
            width = size_input(option);
            option -= 5;
        } else if (option == 7) {
            height = size_input(option);
            option -= 5;
        } else if (option == 8) {
            x_condition = size_input(option);
            option -= 5;
        } else if (option == 9) {
            o_condition = size_input(option);
            option -= 5;
        }   else if (option == 10) {
            game(width, height, X_coord_x, X_coord_y, O_coord_x, O_coord_y, x_condition, o_condition);
            option -= 5;
        }
    }

    return 0;
}
