#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint8_t i, temp1, temp2;
    uint8_t a = 0;
    uint8_t bd_addr[6], buff[17];
    char data[18] = "00:00:AB:CF:5F:A5";
    char *p = data;
    for(i = 0; i < strlen(p); i++)
    {
        printf("%c", p[i]);    
    }
    printf("\n");
    
    for(i = 0; i < strlen(p); i++)
    {
        buff[i] = (uint8_t) p[i];
        printf("%u ", buff[i]);
    }
    printf("\n");
    
    for(i = 0; i < strlen(p); i++)
    {
        buff[i] = (uint8_t) p[i];
        printf("%x ", buff[i]);
    }
    printf("\n");
    
    //printf("\nlength = %ld\n", strlen(p));

    for(i = 0; i < 6; i++)
    {
        if((buff[a] <= 70) && (buff[a] >= 65))
        {
            buff[a] = buff[a] - 55; 
            buff[a] = buff[a] << 4;
        }
        else if((buff[a] <= 57) && (buff[a] >= 30))
        {
            buff[a] = buff[a] - 48;
            buff[a] = buff[a] << 4;
        }
        
        bd_addr[i] = buff[a];
        a++;
        
        if((buff[a] <= 70) && (buff[a] >= 65))
        {
            buff[a] = buff[a] - 55; 
        }
        else if((buff[a] <= 57) && (buff[a] >= 48))
        {
            buff[a] = buff[a] - 48;
        }
        
        bd_addr[i] = bd_addr[i] | buff[a];
        printf("%x ", bd_addr[i]);
        
        a = a + 2;
    }
    
    return 0;
}
