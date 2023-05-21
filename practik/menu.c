#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_headers.h"
#include "structures.h"
#include "other_headers.h"

int file_opened(){
    FILE *in = fopen(main_file, "r");
    if(!in) {
        printf("Файл открыт!");
        getcharLock(2);
        return 0;
    }
    fclose(in);
    return 1;
}

void main_menu()
{
    remove(temp_file);
    while(1){
        clearscreen();

        printf("1. Файл\n");
        printf("2. Редактировать документ\n");
        printf("3. Отобразить документ\n");
        printf("4. Экспорт документа в файл txt\n");
        printf("5. Справочники\n");
        printf("6. О программе\n");
        printf("7. Выход\n\n");
        printf("Введите номер меню: ");

        int ch = getchar();
        clearscreen();

        switch(ch){
        case '1':
            file_menu();
            break;
        case '2':
            if(file_opened()) edit_menu();
            break;
        case '3':
            if(file_opened()) file_display();
            break;
        case '4':
            if(file_opened()) export_txt();
            break;
        case '5':
            dictionary_menu();
            break;
        case '6':
            about();
            break;
        case '7':
            remove(temp_file);
            return;
        }
    }
}

void file_menu(){
    while(1){
        clearscreen();

        printf("1. Открыть\n");
        printf("2. Сохранить\n");
        printf("3. Закрыть\n");
        printf("4. Назад\n\n");

        printf("Введите номер меню: ");
        int ch = getchar();
        clearscreen();

        switch(ch){
        case '1':
            read_file();
            break;
        case '2':
            if(file_opened()) save_file();
            break;
        case '3':
            if(file_opened()) close_file();
            break;
        case '4':
            return;
        }
    }
}

void edit_menu(){
    while(1){
        clearscreen();

        printf("1. Добавить запись \n");
        printf("2. Удалить запись \n");
        printf("3. Редактировать существующую запись\n");
        printf("4. Назад\n\n");

        printf("Введите номер меню: ");
        int ch = getchar();
        clearscreen();

        switch(ch){
        case '1':
            add_note();
            break;
        case '2':
            delete_note();
            break;
        case '3':
            edit_note();
            break;
        case '4':
            return;
        }
    }
}

void dictionary_menu(){
    char *dictionary = form_file;
    int dictionary_state = 1;
    while(1){
        clearscreen();

        printf("Выбранный справочник: %s\n\n", dictionary);

        printf("1. Выбрать справочник\n");
        printf("2. Вывести на экран\n");
        printf("3. Редактировать запись в справочнике \n");
        printf("4. Добавить запись в справочник \n");
        printf("5. Удалить запись\n");
        printf("6. Назад\n\n");

        printf("Выберите номер меню: ");
        int ch = getchar();
        clearscreen();

        switch(ch){
        case '1':
            if(dictionary_state == 1) {
                dictionary = sort_file;
                dictionary_state--;
            }
            else {
                dictionary_state++;
                dictionary = form_file;
            }
            break;
        case '2':
            display_dictionary(dictionary);
            break;
        case '3':
            edit_dictionary(dictionary);
            break;
        case '4':
            add_note_dictionary(dictionary);
            break;
        case '5':
            delete_element_dictionary(dictionary);
            break;
        case '6':
            return ;
        }


    }
}



