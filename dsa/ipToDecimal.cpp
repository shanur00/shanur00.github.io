#include <cmath>
#include <cstdio>

void convertToIp(unsigned long decimal){
  int a = (decimal>>24)&(0xFF);
  int b = (decimal>>16)&(0xFF);
  int c = (decimal>>8)&(0xFF);
  int d = (decimal)&(0xFF);

  printf("%d.%d.%d.%d\n", a,b,c,d);
}

void covertToDecimal(char* ip){
  int dp[20]; int index=0; int number=0;
  int size[4]; int sizeIndex=0;
  while(*(ip)!='\0'){
    if(*(ip)=='.'){
      size[sizeIndex++]=number;
      number=0;
    }
    else{
      number++;
      dp[index++]= *(ip) - '0';
    }
    ip++;
  }

  size[sizeIndex]=number;

  int arr[4]={0}; sizeIndex=0; int arrIndex=0;
  for(int i=0; i<index; ){
    int k=std::pow(10, size[sizeIndex]-1);
    // printf("k: %d\n", k);
    for(int j=i; j<i+size[sizeIndex]; j++){
      arr[arrIndex] += dp[j]*k;
      k=k/10;
    }
    arrIndex++;
    i+=size[sizeIndex++];
  }

  // for(int i=0; i<arrIndex; i++){
  //   printf("%d ", arr[i]);
  // }
  // printf("\n");
  unsigned long Ip;
  int lf = 24;
  for(int i=0; i<arrIndex; i++){
    if(i==0){
      Ip+=arr[i]*(1<<lf);
      lf=lf-8;
      continue;
    }
    Ip+=arr[i]*(1<<lf);
    lf=lf-8;
  }
  printf("Ip: %lu\n", Ip);
  
}

int main(){
  unsigned long decimal = 3232235786;
  convertToIp(decimal);
  char ip[20] = "192.168.1.10";
  covertToDecimal(ip);
  return 0;
}
