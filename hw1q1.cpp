// Creaing processes with fork() system call in C/C++
int main()
{
/* fork a child process */
fork();
fork();
fork();
int i;
for (i = 0; i < 6; i++) fork();
/* fork another child process */
fork();
return 0;
}