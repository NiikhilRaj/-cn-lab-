#include<stdio.h>

struct pkt{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    struct pkt packet;
    int num, reconstructed;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // store number across structure members
    packet.ch1 = (num >> 24) & 0xFF;
    packet.ch2[0] = (num >> 16) & 0xFF;
    packet.ch2[1] = (num >> 8) & 0xFF;
    packet.ch3 = num & 0xFF;
    
    printf("\nOriginal number: %d\n", num);
    printf("\nStructure contents:\n");
    printf("ch1: %d\n", packet.ch1);
    printf("ch2[0]: %d\n", packet.ch2[0]);
    printf("ch2[1]: %d\n", packet.ch2[1]);
    printf("ch3: %d\n", packet.ch3);
    
    // reconstruct the original number
    reconstructed = (packet.ch1 << 24) | (packet.ch2[0] << 16) | 
                   (packet.ch2[1] << 8) | packet.ch3;
    
    printf("\nReconstructed number: %d\n", reconstructed);
    
    if(num == reconstructed)
        printf("Success! Numbers match.\n");
    else
        printf("Error! Numbers don't match.\n");
    
    return 0;
}