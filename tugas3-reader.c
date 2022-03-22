#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main () {

    int maxbyte = 5;
    FILE *file;
    char filename [MAX_LEN];
    unsigned char val[maxbyte];

    printf("Masukkan nama file (tanpa ekstensi/format): ");
    scanf("%s", filename);

    file = fopen(filename,"r");
    if (file != NULL){
        fread(val, maxbyte, 1, file);
        printf("%x %x %x %x %x\n", val[0],val[1],val[2],val[3],val[4]);

        if ((val[0] == 0x25) && (val[1] == 0x50) && (val[2] == 0x44)
            && (val[3] == 0x46) && (val[4] == 0x2d)){
            printf("Format file %s berupa pdf", filename);
        }
        else if ((val[0] == 0xFF) && (val[1] == 0xd8) && (val[2] == 0xFF)) {
            printf("Format file %s berupa jpg", filename);
        }
        else {
            printf("Format file %s unidentified", filename);
        }
    }

    fclose(file);

    return 0;
}