#include<stdio.h>

int main()
{
    int num;
    char byte1, byte2, byte3, byte4;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    byte1 = (num >> 24) & 0xFF; 
    byte2 = (num >> 16) & 0xFF;
    byte3 = (num >> 8) & 0xFF;
    byte4 = num & 0xFF;         
    
    printf("\nOriginal number: %d\n", num);
    printf("Byte 1 (MSB): %d (0x%02X)\n", byte1, byte1 & 0xFF);
    printf("Byte 2: %d (0x%02X)\n", byte2, byte2 & 0xFF);
    printf("Byte 3: %d (0x%02X)\n", byte3, byte3 & 0xFF);
    printf("Byte 4 (LSB): %d (0x%02X)\n", byte4, byte4 & 0xFF);
    
    return 0;
}