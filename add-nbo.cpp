#include <stddef.h> // for size_t
#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf
#include <netinet/in.h> //ntohs, ntohl
#include <stdlib.h> // strtol

int main(void)
{
    char track[] ="포렌식";
    char name[] = "이광희";
    uint32_t n1=0;
    uint32_t n2=0;
    uint32_t sum=0;

    FILE* thousandFile = fopen("thousand.bin", "r"); //read mode
    if(thousandFile == NULL)
    {   printf("Error: No File");
        return 0; }

    FILE* fiveFile = fopen("five-hundred.bin", "r"); //read mode
    if(fiveFile == NULL)
    {    printf("Error: No File");
        return 0;  }

    fread(&n1, sizeof(uint32_t), 1 ,thousandFile);
    fread(&n2, sizeof(uint32_t), 1 ,fiveFile);
   // printf("%x\n%x\n",n1,n2);

    n1 = ntohl(n1);
   // printf("32 bit number=0x%x\n", n1);
    n2 = ntohl(n2);
   // printf("32 bit number=0x%x\n", n2);
    sum=n1+n2;
   // printf("32 bit number=0x%x\n",sum);



    printf("[bob10][%s]add-nbo[%s]\n", track, name);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n1, n1, n2, n2, sum, sum);    // 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)


    fclose(thousandFile);
    fclose(fiveFile);

    return 0;
}
