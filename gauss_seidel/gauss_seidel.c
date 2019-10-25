#include<stdio.h>

#define up 20.0
#define down 300.0
#define left 20.0
#define right 20.0
#define row 6
#define col 6

double print_vector(double vec[row]){
  int i;
  for(i=0;i<row;i++){
    printf("%f, ",vec[i]);
  }
}

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
  double array[row][col] = {
    {1,-1/4.,0,-1/4.,0,0},
    {-1/4.,1,-1/4.,0,-1/4.,0},
    {0,-1/4.,1,0,0,-1/4.},
    {-1/4.,0,0,1,-1/4.,0},
    {0,-1/4.,0,-1/4.,1,-1/4.},
    {0,0,-1/4.,0,-1/4.,1}
  };

  //print_matrix(array);
  double vector_x[row] = {0,0,0,0,0,0};
  double vector_b[row] = {
    (20/4.)+(20/4.),
    20/4.,
    (20/4.)+(20/4.),
    (20/4.)+(300/4.),
    300/4.,
    (20/4.)+(300/4.)
  };
  // confirm
  int i;
  int j;
  double sum_num;
  /*
  for(i=0;i<row;i++){
    printf("%f, ",vector_b[i]);
  }
  */
    for(i=0;i<row;i++){
      vector_x[i] = vector_b[i];
      // printf("%f, ",vector_x[i]);
    }
    int count = 1;
    for(count=1;count<=10000;count++){
      for(i=0;i<row;i++){
        sum_num = 0;
        for(j=0;j<row;j++){
          if(i == j){
            continue;
          } else {
            sum_num += array[i][j] * vector_x[j];
            //printf("sum_num = %f,  ",sum_num);
          }
        vector_x[i] = vector_b[i] - sum_num;
        }
      }
      printf("[%d] : ",count);
      print_vector(vector_x);
      printf("\n");
    }

  return 0;
}
