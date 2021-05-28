#include <stdio.h>
#include <math.h>

//Compilar: gcc EDF.c -o edf -lm

//Máximo Común Divisor
int MCD(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

//Mínimo Común Múltiplo
int MCM(int x, int y)
{
    return (x * y) / MCD(x, y);
}

//Parte Izquierda de Schedulable
double U(int n, int c[], int p[])
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (double)c[i] / (double)p[i];
    }
    return result;
}

//Parte Derecha de Schedulable
double schedulable(double n)
{
    return 1;
}

void insertionSort(int p[], int n, int step, int indx[])
{
    //indx es un arreglo de enteros consecutivos de tamaño n (ej: {0,1,2})
    //step es el paso por donde va ejecutandose a lo largo de la matriz de largo m (es j)

    //calcula en arr tiempo restante hasta deadline de cada proceso
    //Es el criterio que usar para ordenar
    int arr[n];
    for(int k = 0; k<n; k++){
    	arr[k] = p[k] - step % p[k];        
    }    
    
    //Orden arr y, al mismo tiempo, los índices de arr en indx    
    int i, key, j, keyIndx;
    for(i = 1; i< n; i++){
    	key = arr[i];
    	keyIndx = indx[i];
    	j = i - 1;
    	
    	while(j >= 0 && arr[j] > key){
    	    arr[j + 1] = arr[j];
    	    indx[j + 1] = indx[j];
    	    j = j - 1;
    	}
    	arr[j + 1] = key;
    	indx[j + 1] = keyIndx;
    }
}

//Earliest Deadline First
void earliestDeadlineFirst(int n, int m, int c[], int p[], int result[n][m])
{
    //Initialize Configuration
    int progress[n];
    int indx[n];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = 0;
        }
        progress[i] = 0;
    }

    //EDF
    int stop = 0;
    for (int j = 0; j < m && stop == 0; j++)
    {
        //Increase Progress and Check Error
        for (int i = 0; i < n; i++)
        {
            if (j % p[i] == 0)
            {
                //Check ERROR
                if (progress[i] > 0)
                {
                    result[n][j] = -1;
                    stop = 1;
                    break;
                }
                //Increase C in Progress
                progress[i] += c[i];
            }
        }
        
        //Set priorities
        for(int i=0; i< n; i++) indx[i] = i;
        insertionSort(p, n, j, indx);
        
        //Simulate Execution: cambiar orden para que sea el de EDF
        for (int i = 0; i < n && stop == 0; i++)
        {
            if (progress[indx[i]] > 0)
            {
                result[indx[i]][j] = 1;
                progress[indx[i]]--;
                break;
            }
        }
    }    
    
}

int main()
{
    int n = 3;

    int c[] = {1, 2, 6};
    int p[] = {5, 8, 19};

    
    //Calculate MCM
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        m = MCM(p[i], p[i + 1]);
    }

    //Calculate Rate Monotonic
    int result[n + 1][m];
    earliestDeadlineFirst(n, m, c, p, result);

    //Print Result
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", result[i][j]);
            if (j == m - 1)
            {
                printf("\n");
            }
        }
    }

    return 0;
}
