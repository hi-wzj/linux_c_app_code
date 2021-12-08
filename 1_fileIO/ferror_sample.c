#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = NULL;
    int ret;
    char buf[20] = {0};

    fp = fopen("./fcntl_sample.c", "r");
    if(NULL == fp) {
        perror("fopen error");
        exit(-1);
    }   
    printf("文件打开成功!\n");
    ret = fseek(fp, 0, SEEK_END);
    if(ret < 0) {
        perror("fseek error");
        fclose(fp);
        exit(-1);        
    }

    ret = fread(buf, 1, 10, fp);
    if(ret < 10) {
        if(feof(fp))
            printf("end-of-file 标志被设置,已到文件末尾!\n");
        clearerr(fp);
    }

    fclose(fp);
    exit(0);
}
