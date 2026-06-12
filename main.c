#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/stat.h"

#define MAXBUFF 10000

int main(int argc, char *argv[]){


  int f1, f2, n, m;
  char buff[MAXBUFF];

  if (argc != 4){ 
    
    printf("Usage: cln path1 path2\n");

    return -1; 
  }
  

  if ((f1 = open(argv[2], O_RDONLY, 0)) == -1){
    printf("Cant open %s\n", argv[2]);
  }

  if ((f2 = creat(argv[3], 666)) == -1){
    printf("Cant create %s\n", argv[3]);
  }

  while ((n = read(f1, buff, MAXBUFF)) > 0){
    if ((m = write(f2, buff, n)) != n){
      printf("Error while copy\n");
    }
  }

  close(f1);
  close(f2);
  
  return 0;

}
