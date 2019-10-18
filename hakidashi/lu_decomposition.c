#include<stdio.h>
#include<stdlib.h>

// 行数
#define row 3
// 列数
#define col 3

// 行ベクトルを出力する関数
double print_vector(double arr[row][col], int factor){
  int num;
  printf("vector[%d] = [", factor);
  for(num=0; num<col; num++){
    printf("%f ",arr[factor][num]);
  }
  printf("]\n");
}

// 行列を出力する関数(LU.ver.)
double print_matrix(double arr[row][col]){
  int num1;
  int num2;
  for(num1=0; num1<row; num1++){
    printf("[ ");
    for(num2 = 0; num2<col; num2++){
      printf("%f ",arr[num1][num2]);
    }
    printf("]\n");
  }
  printf("\n");
}

int main(){
/* -- 変数解説 --
      arr[row][col]  : 求めたい連立一次方程式
      temp_arr[col]  : 行を入れ替える時の数値確保列
      i : 配列操作の基準変数
      j : 行ループ操作に関する束縛変数
      k : 列要素ループ操作に関する束縛変数
      count : 掃き出し回数.
      pivot : ０でない主変数候補のうち最大数である成分の行数
      alpha : 主変数候補の最大値候補
      beta  : 主変数を１にする逆数.betaに関して該当行を正規化
      gamma : 掃き出す際の基準となる変数
*/

  double arr[row][col+1] = {
/*    {1,3,4,13},
    {2,1,-3,5},
    {6,5,-23,5}
    */
    {1,3,4,10},
    {2,1,5,7},
    {6,5,1,11}
  };
  //double temp_arr[col] = {0,0,0,0};
  int i;
  int j;
  int k;
  int count;
  int pivot;
  double alpha;
  double beta;
  double gamma;

  // 係数行列Uを拡大係数行列Arrから取り出す
  double U[row][col];
    for(j=0; j<row; j++){
      for(k=0; k<col; k++){
        U[j][k] = arr[j][k];
      }
    }
  // debug
    print_matrix(U);

  // Identity matrix
  double L[row][col];
    for(j=0; j<row; j++){
      for(k=0; k<col; k++){
        if(j == k) {
          L[j][k] = 1;
        } else {
          L[j][k] = 0;
        }
      }
    }
  // debug
    print_matrix(L);


  for(i=0; i<row; i++){
    // L_ii に U_ii を代入する
      L[i][i] = U[i][i];

    // 正規化処理
    beta = U[i][i];
    for(k=0; k<col; k++){
      U[i][k] = U[i][k] / beta;
    }
    // debug
    // printf("U(正規化) = \n");
    // print_matrix(U);

    // Lにメモする処理
    int l;
    for(l=i+1; l<row; l++){
      L[l][i] = U[l][i];
    }
    // printf("L=\n");
    // print_matrix(L);

    // 掃き出し処理
    for(j=i; j<row; j++){
      if(j == i){continue;}
      gamma = U[j][i];
      for(k=0; k<col; k++){
        U[j][k] -= U[i][k] * gamma;
      }
    }

    // debug 掃き出しの様子
    count = i;
    printf("掃き出し%d回目\n", count);
    // print_matrix(U);
    // print_matrix(L);

    // LUしたあとに代入しよう
    double y[row];
    y[0] = arr[0][col] / L[0][0];
    printf("%f", y[0]);
  }

 return 0;
}
