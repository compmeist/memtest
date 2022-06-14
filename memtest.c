
#include <stdio.h>
#include <malloc.h>



int main (void )

{
  int iMemSize,iArySize;
  int i,j,k,iMA,iStrp,iStrpSize,nStrps,iNumTimes;
  int *memBuf;

  printf("Simple Integrity Test for RAM memory (tested in strips) \n");
  printf("Enter size (in megabytes) of memory to be tested (e.g. 256):\n");
  scanf ("%d",&iMemSize);
  iMemSize *= 1048576;
  iArySize = iMemSize / sizeof(int);
  memBuf = malloc(iArySize * sizeof(int));
  if (memBuf == NULL) return 1;
  printf("Number of times to test each address:\n");
  scanf("%d",&iNumTimes);
  /* test memory in strips */
  nStrps = 100;
  iStrpSize = iArySize / nStrps;

  /* main loop */
  for (k=0;k<iNumTimes;k++)
  { printf("\niteration %d",k);
    printf("\nWrite\n");
    for (j=0;j< (nStrps/2);j++)
    {
     /* test high strip */ printf("'");
     iStrp = (nStrps-1) - j;
     for (i=0;i<iStrpSize;i++)
     { iMA = i+ iStrp* iStrpSize;
       memBuf[iMA] = iMA;
     }
     /* test low strip */ printf(",");
     iStrp = j;
     for (i=0;i<iStrpSize;i++)
     { iMA = i+ iStrp* iStrpSize;
       memBuf[iMA] = iMA;
     }
    }
    printf("\nRead\n");
    for (j=0;j< (nStrps/2);j++)
    {
     /* test high strip */ printf("O");
     iStrp = (nStrps-1) - j;
     for (i=0;i<iStrpSize;i++)
     { iMA = i+ iStrp* iStrpSize;
       if (memBuf[iMA] != iMA) printf("\nError at %d\n",iMA);
     }
     /* test low strip */ printf("o");
     iStrp = j;
     for (i=0;i<iStrpSize;i++)
     { iMA = i+ iStrp* iStrpSize;
       if (memBuf[iMA] != iMA) printf("\nError at %d\n",iMA);
     }
    }
  }
  return 0;
}

