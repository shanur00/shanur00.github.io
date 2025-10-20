#include <stdio.h>
int main(){
  FILE *fp;

  char data[50] = "GeeksforGeeks-A Computer "
                  "Science Portal for Geeks";
  
  fp = fopen("test.txt", "w");
  if(fp==nullptr){
    printf("The file is not opened\n");
  }
  else{
    printf("File is created\n");
    fputs(data, fp);
    fputs("\n", fp);

    fclose(fp);
    printf("Data is written");
    printf("File is closed now\n");
  }



  // printf("fd: %p\n", fp);

  // printf("File description: %d\n", fileno(fp));
  // printf("File position: %ld\n", ftell(fp));
  // printf("Buffer size: %ld\n", (long)fp->_IO_buf_end - (long)fp->_IO_buf_base);
  // printf("Buffer base address: %p\n", fp->_IO_buf_base);
  // printf("Buffer end address: %p\n", fp->_IO_buf_end);

  // fputs(data, fp);

  // printf("Buffer size: %ld\n", (long)fp->_IO_buf_end - (long)fp->_IO_buf_base);
  // printf("Buffer base address: %p\n", fp->_IO_buf_base);
  // printf("Buffer end address: %p\n", fp->_IO_buf_end);
  return 0;
}

