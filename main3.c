#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
/* Мы будем запускать команду cat c аргументом командной строки 03-2.с без изменения параметров среды,
т.е. фактически выполнять команду "cat 03-2.c", которая должна выдать содержимое данного файла на экран.
Для функции execle в качестве имени программы мы указываем ее полное имя с путем от корневой директории.
Первое слово в командной строке у нас должно совпадать с именем запускаемой программы. Второе слово в командной строке - это имя файла, содержимое которого мы хотим распечатать.*/

(void) execle("/bin/cat", "/bin/cat", "03-2.c", 0, envp);

/* Сюда попадаем только при возникновении ошибки */

printf("Error on program start\n");
exit(-1);

return 0; /* Никогда не выполняется, нужен для того, чтобы компилятор не выдавал warning */
}
