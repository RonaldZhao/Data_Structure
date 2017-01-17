/*
有时候会出错，暂时搞不定= =
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
	int i, j;
	ElemType e;
} Triple;

typedef struct {
	Triple *data;
	int mu, nu, tu;
} TSMatrix;

void CreateMatrix(ElemType ***, int, int);								//随机创建稀疏矩阵
void RandMatrix(ElemType ***, int, int);									//为创建的初始化矩阵添加随机值
void MatrixToArray(ElemType **, TSMatrix *, int, int);				//矩阵转换数组
void ArrayToMatrix(TSMatrix, ElemType ***);							//三元组转换为矩阵
void transpose(TSMatrix, TSMatrix *);										//矩阵转置
void AddMatrixArray(TSMatrix, TSMatrix, TSMatrix *);			//将三元组相加
void PrintMatrix(ElemType **, int, int);									//输出矩阵
void PrintArray(TSMatrix);
void freeMatrix(ElemType ***, int);											//释放空间
void freeArray(TSMatrix *);

int main()
{
	int row, column;
	ElemType **matrixa, **matrixb, **matrixadd, **matrixtran;	//矩阵 
	TSMatrix arraya, arrayb, arrayadd, arraytran;							//三元组
	while (scanf("%d%d", &row, &column) != EOF && row*column)
	{
		CreateMatrix(&matrixa, row, column);					//随机生成矩阵A
		printf("正在生成稀疏矩阵......\nDone!\nA矩阵:\n");
		PrintMatrix(matrixa, row, column);						//输出矩阵 
		printf("A矩阵的三元组:\n");								//输出A的三元组 
		MatrixToArray(matrixa, &arraya, row, column);			//矩阵A转换为三元组 
		freeMatrix(&matrixa, row);
		PrintArray(arraya);
		printf("A矩阵的转置矩阵(快速转置得到):\n");
		transpose(arraya, &arraytran);
		ArrayToMatrix(arraytran, &matrixtran);
		freeArray(&arraytran);
		PrintMatrix(matrixtran, column, row);
		freeMatrix(&matrixtran, column);
		
		CreateMatrix(&matrixb, row, column);					//随机生成矩阵B
		printf("正在生成稀疏矩阵......\nDone!\nB矩阵:\n");
		PrintMatrix(matrixb, row, column);
		printf("B矩阵的三元组:\n");
		MatrixToArray(matrixb, &arrayb, row, column);
		freeMatrix(&matrixb, row);
		PrintArray(arrayb);
	
		printf("C矩阵(C=A+B):\n");
		AddMatrixArray(arraya, arrayb, &arrayadd);
		freeArray(&arraya);
		freeArray(&arrayb);
		ArrayToMatrix(arrayadd, &matrixadd);
		freeArray(&arrayadd);
		PrintMatrix(matrixadd, row, column);
		freeMatrix(&matrixadd, row);
	}

	return 0;
}

void CreateMatrix(ElemType ***m, int r, int c)
{
	int i, j, temp, t;
	srand((unsigned)time(0));
	(*m) = (ElemType **)calloc(r, sizeof(ElemType*));
	for (i = 0; i < r; ++i)
	{
		(*m)[i] = (ElemType*)calloc(c, sizeof(int));
	}
	for (i = 0; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			temp = rand() % 500;
			t = rand() % r*c;
			if (t == r || t == c)
				(*m)[i][j] = temp;
		}
	}
}

void RandMatrix(ElemType ***m, int r, int c)
{
	int i, j, temp, t;
	srand((unsigned)time(0));
	for (i = 0; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			temp = rand() % 100;
			t = rand() % 5;
			if (t == 2)
				(*m)[i][j] = temp;
		}
	}
}

void MatrixToArray(ElemType **Matrix, TSMatrix *MatrixArray, int r, int c)
{
	int col = 0, i, j;
	MatrixArray->mu = r;//矩阵的行数
	MatrixArray->nu = c;//矩阵的列数
	MatrixArray->tu = 0;//矩阵的非零元素个数
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (Matrix[i][j])
			{
				if (MatrixArray->tu == 0)
				{
					MatrixArray->data = (Triple*)malloc(++MatrixArray->tu * sizeof(Triple));//当输入非方阵的时候有问题
				}
				else
				{
					Triple *data = MatrixArray->data;
					MatrixArray->data = (Triple*)realloc(data, (++MatrixArray->tu) * sizeof(Triple));
					if(!data)
						free(data);
				}
				MatrixArray->data[col].i = i;
				MatrixArray->data[col].j = j;
				MatrixArray->data[col++].e = Matrix[i][j];
			}
		}
	}
	if (!MatrixArray->tu)
		MatrixArray->data = NULL;
}

void ArrayToMatrix(TSMatrix T, ElemType ***Matrix)
{
	(*Matrix) = (ElemType**)calloc(T.mu, sizeof(ElemType*));
	for (int i = 0; i < T.mu; ++i)
	{
		(*Matrix)[i] = (ElemType*)calloc(T.nu, sizeof(ElemType));
	}
	for (int i = 0; i < T.tu; ++i)
	{
		(*Matrix)[T.data[i].i][T.data[i].j] = T.data[i].e;
	}
}

void transpose(TSMatrix M, TSMatrix *T)
{
	int *num = NULL, *cpot = NULL;
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	num = (int*)calloc(M.nu, sizeof(int));
	cpot = (int*)calloc(M.nu, sizeof(int));
	T->data = (Triple*)malloc(T->tu * sizeof(Triple));
	if (T->tu)
	{
		for (int t = 0; t < M.tu; ++t)			//求M中每一列非零元素的个数
			++num[M.data[t].j];
		cpot[0] = 0;
		for (int col = 1; col < M.nu; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (int p = 0; p < M.tu; ++p)
		{
			int col = M.data[p].j;
			int q = cpot[col];
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].e = M.data[p].e;
			++cpot[col];
		}
	}
	free(num);
	free(cpot);
}

void AddMatrixArray(TSMatrix A, TSMatrix B, TSMatrix *ADD)
{
	int i, j;
	ADD->nu = A.nu;
	ADD->mu = A.mu;
	ADD->tu = 0;
	ADD->data = (Triple*)calloc(ADD->mu + ADD->nu, sizeof(Triple));//可以再展开优化一下,这样会有空间的浪费
	for (i = 0, j = 0; i < A.tu, j < B.tu;)
	{
		if (A.data[i].i > B.data[j].i)
		{
			ADD->data[ADD->tu].i = B.data[j].i;
			ADD->data[ADD->tu].j = B.data[j].j;
			ADD->data[ADD->tu++].e = B.data[j++].e;
		}
		else if (A.data[i].i < B.data[j].i) {
			ADD->data[ADD->tu].i = A.data[i].i;
			ADD->data[ADD->tu].j = A.data[i].j;
			ADD->data[ADD->tu++].e = A.data[i++].e;
		}
		else {
			if (A.data[i].j > B.data[j].j)
			{
				ADD->data[ADD->tu].i = B.data[j].i;
				ADD->data[ADD->tu].j = B.data[j].j;
				ADD->data[ADD->tu++].e = B.data[j++].e;
			}
			else if (A.data[i].j < B.data[j].j) {
				ADD->data[ADD->tu].i = A.data[i].i;
				ADD->data[ADD->tu].j = A.data[i].j;
				ADD->data[ADD->tu++].e = A.data[i++].e;
			}
			else {
				ADD->data[ADD->tu].i = A.data[i].i;
				ADD->data[ADD->tu].j = A.data[i].j;
				ADD->data[ADD->tu++].e = A.data[i++].e + B.data[j++].e;
			}
		}
	}
}

void PrintMatrix(ElemType **Matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%5d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintArray(TSMatrix Array)	//输出三元组
{
	printf("\ti\tj\te\n");
	for (int i = 0; i < Array.tu; i++)
	{
		printf("\t%d\t%d\t%d\n", Array.data[i].i+1, Array.data[i].j+1, Array.data[i].e);
	}
	printf("\n");
}

void freeMatrix(ElemType ***Matrix, int r)
{
	if (*Matrix)
	{
		for (int i = 0; i < r; ++i)
		{
			free((*Matrix)[i]);				//释放第二维指针
		}
		free(*Matrix);						//释放第一维指针
	}
}

void freeArray(TSMatrix *Array)
{
	if((*Array).data)
		free((*Array).data);
}
