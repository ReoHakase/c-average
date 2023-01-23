#include <stdio.h>
#include <stdlib.h>

struct DATA_SCAN
{
  char str[10];
  int score_math;
  int score_eng;
};

int main(void)
{
  int n;
  // 学生の人数を入力
  printf("学生の人数を入力してください: ");
  scanf("%d", &n);

  struct DATA_SCAN data[n];

  FILE *fp, *fi;

  double sum_math = 0, sum_eng = 0;

  fp = fopen("average.txt", "w");
  fi = fopen("data.txt", "r");

  if (fp == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  printf("ファイルを開きました。\n");

  for (int k = 0; k < n; k++)
  {
    fscanf(fi, "%s %d %d", data[k].str, &data[k].score_math, &data[k].score_eng);
    printf("読み込みました: %s %d %d\n", data[k].str, data[k].score_math, data[k].score_eng);
    sum_math += data[k].score_math;
    sum_eng += data[k].score_eng;
  }

  // 平均点を計算してfpに書き込む
  if (fprintf(fp, "Score average of math is %lf\n", sum_math / n) < 0 || fprintf(fp, "Score average of English is %lf\n", sum_eng / n) < 0)
  {
    printf("ファイルに書き込めませんでした。\n");
    exit(1);
  }
  else
  {
    printf("ファイルに書き込みました。\n");
  }

  fclose(fp);
  fclose(fi);

  return 0;
}