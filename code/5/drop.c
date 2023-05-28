#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define PORT 1111


// below for debugging

void printByte(char* p){
    //for (int i=0; i<8; i++)
    for (int i=7; i>=0; i--)
        if (*p & (1 << i)) printf("1");
        else               printf("0");
    printf("\n");
}

//void printSockAddr(struct sockaddr_in* sa){
//    size_t sz = sizeof(struct sockaddr_in);
void printSockAddr(struct sockaddr* sa){
    size_t sz = sizeof(struct sockaddr);
    char *p = (char*)sa;
    for(int i=0; i<sz; i++)
        printByte(p++);
}


int main (void) {
  int                s, l;
  unsigned char      buf[BUF_SIZE];

//  printf("size sock addr %zu \n", sizeof (struct sockaddr));
//  printf("size sock addr in %zu \n", sizeof (struct sockaddr_in));

  // not sure the below line works
  //unsigned long      addr =  0x0100007f11110002; // Define IP the hacker way :)
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  //addr.sin_addr = inet_addr("127.0.0.1");
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  //printSockAddr(&addr);
  //printSockAddr((struct sockaddr*) &addr);


  if ((s = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) return -2;
  if (connect (s, (struct sockaddr*)&addr, 16) < 0)         return -3;
  
  while (1) {
    if ((l = read (s, buf, BUF_SIZE) ) <= 0) break;
    write (1, buf, l);
    if (l < BUF_SIZE) break;
  }
  close (s);
  
  return 0;
  
}
