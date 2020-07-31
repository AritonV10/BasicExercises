#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* Reseziable */
typedef struct {
    
    uint32_t u32Size;
    uint32_t u32Index;
    char *pucStr;

}String;


String *
String__stMakeString(uint32_t size) {
    
    String *stString;
    
    stString = malloc(sizeof(String));
    
    if(stString == 0) {
        return(NULL);
    }
    
    stString->pucStr = malloc(sizeof(char) * size);
    stString->u32Size = size;
    stString->u32Index = 0;
    
    return(stString);
}


uint32_t 
u32GetIntegerLenght(int32_t i32Integer) {
    uint32_t u32Length;
    
    u32Length = 1;
    
    for(;;) {
        
        if(i32Integer >= 1000) {
            u32Length += 3;
        } else if(i32Integer >= 100) {
            u32Length += 2;
        } else if(i32Integer >= 10) {
            u32Length+= 1;
        } else {
            return(u32Length);
        }
        
        i32Integer /= 1000;
    }
    
    
}

void
String__vReallocBuffer(String *pstString) {
    
    pstString->pucStr = realloc(pstString->pucStr, pstString->u32Size * 2);
    
    pstString->u32Size *= 2;
    
}

void
String__vReallocBufferSize(String *pstString, uint32_t u32Size) {
    
    pstString->pucStr = realloc(pstString->pucStr, u32Size);
    
    pstString->u32Size = u32Size;
    
}

void
String__vRemoveChar(String *pstString) {
    
    *(pstString->pucStr + (pstString->u32Index - 1)) = 0;
    
    --pstString->u32Size;
    
}

void
String__vAddCharacter(String *pstString, uint8_t u8Char) {
  
  /* Verify if we have enough space */  
  if((pstString->u32Index + 1) >= pstString->u32Size) {
      
    String__vReallocBuffer(pstString);
      
  }
  
  /* Append the character */
  *(pstString->pucStr + pstString->u32Index) = u8Char;
  
  ++pstString->u32Index;
  
  /* Place the \0 */
  *(pstString->pucStr + pstString->u32Index) = 0;
}

void
String__vAddInteger(String *pstString, int32_t i32Integer) {
    
    
  uint32_t u32BufIndex;
  
  int32_t  i32IntegerLen;
  
  int32_t  i32IntegerLenCopy;
  
  u32BufIndex = 0;
  
  i32IntegerLen = (u32GetIntegerLenght(i32Integer) - 1);
  i32IntegerLenCopy = i32IntegerLen;
  
  /* Verify if we have enough space for the integer */
  if((pstString->u32Index + i32IntegerLen) >= pstString->u32Size) {
      
    String__vReallocBuffer(pstString);
      
  }
  
  while(i32IntegerLen >= 0) {
    
    *((pstString->pucStr + pstString->u32Index) + i32IntegerLen) = (0x30 | (i32Integer % 10));
    
    --i32IntegerLen;
    
    i32Integer /= 10;
    
  }
  
  pstString->u32Index += (i32IntegerLenCopy + 1);
  *(pstString->pucStr + pstString->u32Index) = 0;

}

char *range_extraction(int32_t *args, size_t n) {
    
    uint32_t u32Size;
  
    uint32_t u32Index;
    
    String *pstString;
    
    pstString = String__stMakeString(1024);
    
    for(u32Index = 0; u32Index < (n - 1); ++u32Index) {
      
      
      if(args[u32Index] < 0) {
             
        String__vAddCharacter(pstString, '-');
             
      }
      
      String__vAddInteger(pstString, abs(args[u32Index]));
      
      if( (args[u32Index] + 1) != args[u32Index + 1]) {
        
         String__vAddCharacter(pstString, ',');
        
      } else {
          
          uint32_t u32TempIndex;
          uint32_t u32Streak;
          
          u32Streak = 1;
          
          /* Iterate until (a[i] + 1) != a[i + 1] */
          for(
                u32TempIndex = u32Index + 1; 
                u32TempIndex < (n) && ( (args[u32TempIndex] + 1) == args[u32TempIndex + 1] ); 
                ++u32TempIndex, ++u32Streak
              )
            ;
         if(u32Streak >= 2) {
            
            String__vAddCharacter(pstString, '-');
              
            if(args[u32TempIndex] < 0) {
             
                String__vAddCharacter(pstString, '-');
            }
         
            String__vAddInteger(pstString, abs(args[u32TempIndex]));
         
            u32Index = u32TempIndex;
         }
         
        String__vAddCharacter(pstString, ',');
             
      }
      
    }
    
    /* For the last character, in case It's not in a range */
    if(u32Index != n) {
       
        String__vAddInteger(pstString, args[n - 1]);
    } else {
        String__vRemoveChar(pstString);
    }
    
    /* Trim the bytes */
    if(pstString->u32Size != pstString->u32Index) {
        String__vReallocBufferSize(pstString, pstString->u32Index);
    }
    
    printf("%s %d %d", pstString->pucStr, pstString->u32Index, pstString->u32Size);
    
    return(pstString->pucStr);
}


int main()
{

    //1-n,5
    int32_t u32Arr[] = {61,71,81,89,91,93,99,105,115,122,130,134,137,147,153,159,163,170,175,177,182,192,200,206,210,214,223,230,235,240,249,252,256,262,269,271,277,280,287,291,297,299,305,310,318,326,335,337,342,345,354,360,369,374,382,384,391,395,402,410,417,423,430,438,446,450,458,462,465,467,473,480,490,498,508,515,520,526,531,537,542,544,553,556,561,567,577,585,594,601,606,611,620,629,638,644,646,651,657,667,672,680,686,688,691,694,702,707,712,721,730,738,747,752,759,762};
    
    
    range_extraction(u32Arr, sizeof(u32Arr)/sizeof(int32_t));
    
    return 0;
}

