#include<stdio.h>

double numerical(double,double,double);
double function(double);

double function(double x){
  return x*x*x;
}

double numerical(double a, double b, double delta){
  int count = 1;
  double sum = 0;
  // 分割幅の定義
  double dx;
  dx = (b - a) / delta;
  printf("dx = %f \n", dx);
  // 有限個の足し算
  while (a < b) {
    sum += function(a) * dx;
    printf("[%d] sum = %f \n", count, sum);
    a += dx;
    count ++;
  }
  return sum;
}

int main(){
  numerical(0,1,100);

  return 0;
}
