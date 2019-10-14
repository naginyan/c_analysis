#include<stdio.h>
#include<stdlib.h>

// 行数
#define row 3
// 列数
#define col 4

// 行ベクトルを出力する関数
double print_vector(double arr[row][col], int factor){
  int num;
  printf("vector[%d] = [", factor);
  for(num=0; num<col; num++){
    printf("%f ",arr[factor][num]);
  }
  printf("]\n");
}

// 行列を出力する関数
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

// 行列のコピーを生成する関数
double copy_matrix(double arr[row][col]){
  double copy_arr[row][col];
  int i;
  int j;
  for(j=0; j<row; j++){
    for(i=0; i<col; i++){
      copy_arr[j][i] = arr[j][i];
    }
  }
  return copy_arr[row][col];
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

  double arr[row][col] = {
    {1,3,4,13},
    {2,1,-3,5},
    {6,5,-23,5}
  };
  double temp_arr[col] = {0,0,0,0};
  int i;
  int j;
  int k;
  int count;
  int pivot;
  double alpha;
  double beta;
  double gamma;
  double debug_arr[row][col];
    for(j=0; j<row; j++){
      for(i=0; i<col; i++){
       debug_arr[j][i] = arr[j][i];
      }
    }


  for(i=0; i<row; i++){
    // ピボットの摘出
    pivot = i;
    alpha = abs(arr[i][i]);
    for(k=i; k<row - 1; k++){
      if(abs( arr[k+1][i] ) > alpha){
        alpha = arr[k+1][i];
        pivot++;
      }
    }
    // debug
    // printf("alpha = %f, pivot = %d \n",alpha,pivot);


    // 行の入れ替え
    if (i != pivot){
      for(k=0; k<col ;k++){
        temp_arr[k] = arr[pivot][k];
        arr[pivot][k] = arr[i][k];
        arr[i][k] = temp_arr[k];
      }
    }
    // debug
    // print_matrix(arr);


    // 正規化処理
    beta = arr[i][i];
    for(k=0; k<col; k++){
      arr[i][k] = arr[i][k] / beta;
    }
    // debug
    // print_matrix(arr);


    // 掃き出し処理
    for(j=0; j<row; j++){
      if(j == i){continue;}
      gamma = arr[j][i];
      for(k=0; k<col; k++){
        arr[j][k] -= arr[i][k] * gamma;
      }
    }
    // debug 掃き出しの様子
    count = i;
    printf("掃き出し%d回目\n", count);
    print_matrix(arr);
  }

  // 答えがあっているか確認
  printf("もとの連立一次方程式\n");
  print_matrix(debug_arr);

  double answer[row] = {0,0,0};
  for(j=0; j<row; j++){
    for(k=0; k<col-1; k++){
      answer[j] += debug_arr[j][k] * arr[k][col-1];
    }
    printf("confirm_%d = %f, 誤差 = %f \n",j, answer[j], answer[j] - debug_arr[j][col-1]);
  }

  printf("\n答え\n");
  for(j=0; j<row; j++){
   printf("x_%d = %f, ",j ,arr[j][col-1]);
  }

  printf("\n \n");
  printf("Program finished. \n");
  return 0;
}
