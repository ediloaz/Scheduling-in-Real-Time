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

void insertionSort(int arr[], int indx[], int n,  int actual )
{
    /* - arr es el arreglo con los datos que se usan como criterio para el ordenamiento
       - indx es un arreglo de enteros consecutivos de tamaño n (ej: {0,1,2})
       - actual es el proceso en ejecución. Se usa para desempates 
    	    (actual tiene prioridad) (si actual = -1, no se toma en cuenta)
    */
    
    //Orden arr y, al mismo tiempo, indx    
    int i, key, j, keyIndx;
    for(i = 1; i< n; i++){
    	key = arr[i];
    	keyIndx = indx[i];
    	j = i - 1;
    	
    	while(j >= 0 && (arr[j] > key || (arr[j] == key && i == actual))){
    	    
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
    int actual = -1;
    int arr[n];    
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
        for(int i=0; i< n; i++){ indx[i] = i; arr[i] = p[i] - j % p[i]; }
        
        insertionSort(arr, indx, n, actual);
        
        //Simulate Execution: cambiar orden para que sea el de EDF
        for (int i = 0; i < n && stop == 0; i++)
        {
            if (progress[indx[i]] > 0)
            {
                result[indx[i]][j] = 1;
                progress[indx[i]]--;
                actual = progress[indx[i]] == 0 ? -1 : indx[i];
                break;
            }
        }
    }    
    
}

//Least Laxity First
void leastLaxityFirst(int n, int m, int c[], int p[], int result[n][m])
{
    //Initialize Configuration
    int progress[n];
    int indx[n];
    int actual = -1;
    int arr[n];    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = 0;
        }
        progress[i] = 0;
    }

    //LLF
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
        for(int i=0; i< n; i++){
            indx[i] = i; 
            arr[i] = (p[i] - j % p[i]) - j - c[i];
        }
        
        insertionSort(arr, indx, n, actual);
        
        //Simulate Execution: cambiar orden para que sea el de EDF
        for (int i = 0; i < n && stop == 0; i++)
        {
            if (progress[indx[i]] > 0)
            {
                result[indx[i]][j] = 1;
                progress[indx[i]]--;
                actual = progress[indx[i]] == 0 ? -1 : indx[i];
                break;
            }
        }
    }    
    
}

int main()
{
    int n = 3;

    int c[] = {2,2,3};
    int p[] = {6,8,10};

    
    //Calculate MCM
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        m = MCM(p[i], p[i + 1]);
    }

    //Calculate Rate Monotonic
    int result[n + 1][m];
    leastLaxityFirst(n, m, c, p, result);

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
