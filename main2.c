
/* Пример создания нового процесса с одинаковой работой процессов ребенка и родителя */


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main()
{
pid_t pid, ppid, chpid;
int a = 0, b = 0;
 
chpid = fork();
 
/* При успешном создании нового процесса с этого места псевдопараллельно начинают работать 2 процесса: старый и новый */

/* Перед выполнением следующего выражения a в обоих процессах равно 0 */


 
/* Узнаем идентификаторы текущего и родительского процесса (в каждом из процессов !!!) */
if(chpid==-1)
{
  printf("Error!\n");
}
else if(chpid==0)
{
  printf("Child!\n");
  b = b+1;
}
else 
{
  printf("Parent!\n");
  a = a+1; 
}
pid = getpid();
ppid = getppid();


/* Печатаем значения PID, PPID и вычисленное значение a (в каждом из процессов !!!) */

printf("My pid = %d, my ppid = %d, result = %d, result2 = %d\n", (int)pid, (int)ppid, a, b); 

return 0;
}
