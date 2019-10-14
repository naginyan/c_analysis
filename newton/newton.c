#include <stdio.h>

/*  n乗根の真値をnewton法で近似しよう
  cons    : Nth root
  first   : 初期値
  delta   : 許容誤差
  num     : 数

  Example (４の３乗根，初期値は２，誤差0.001以下)
  cons  : 4
  first : 2
  delta : 0.001
  num   : 3
*/

#define cons  5
#define first 1000
#define delta 0.000001
#define num   4

// x^cons
double sisuu(double, double);
// f(x) = x^cons - num
double func_sqrt(double);
// derivative of f(x)
double d_func_sqrt(double);


double sisuu(double x, double n){
  double i;
  double y;
  y = x;
  for (i=1; i<n; i++){
    x *= y;
  }
  return x;
}

double func_sqrt(double x){
  return sisuu(x,cons) - num;
}

double d_func_sqrt(double x){
  return cons * sisuu(x,(cons - 1));
}

int main(){
  int count = 1;
  double x_now = first;
  double x_new;
  double ans;
  double confirm;

  // 0 < f(x) < delta までループ
  while(func_sqrt(x_now) >= delta){
    // 値の更新
    x_new = x_now - (func_sqrt(x_now) / d_func_sqrt(x_now));
    ans = x_new;
    x_now = x_new;

    // 適度に様子を出力
    if(count % 5 == 0 || count <= 10){
      printf("[%d] exception = %f \n", count, ans);
    }
    count ++;
  }

  printf("\n");
  // 近似できたかの確認
  confirm = sisuu(ans, cons);
  printf("num is = %f ? \n",confirm);

  printf("\n");
  printf("result is [%d]: '%f' \n", (count - 1), ans);

  printf("\nProgram finished! \n");
}
