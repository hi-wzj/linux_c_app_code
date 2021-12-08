#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    int ret;
    long cur_offset;

    fp = fopen("./fcntl_sample.c", "r");
    if(NULL == fp) {
        perror("fopen error");
        exit(-1);
    }

    ret = fseek(fp, 0, SEEK_END);
    if(ret < 0) {
        perror("fseek error");
        fclose(fp);
        exit(-1);        
    }

    cur_offset = ftell(fp);
    if(cur_offset < 0) {
        perror("fseek error");
        fclose(fp);
        exit(-1);          
    }

    printf("cur_offset: %ld\n", cur_offset);

    fclose(fp);
    return 0;
}















