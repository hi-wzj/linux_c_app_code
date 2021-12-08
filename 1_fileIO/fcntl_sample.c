#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd1, flag;
    int ret;

    fd1 = open("./test_file", O_RDWR);
    if(-1 == fd1) {
        perror("fd1 open error");
        exit(-1);
    }
    
    /* 获取文件状态标志 */
    flag = fcntl(fd1, F_GETFL);
    if(-1 == flag) {
        perror("F_GETFL error");
        close(fd1);
        exit(-1);
    }

    printf("fd1: %d\nflag: 0x%x\n", fd1, flag);

    /* 设置文件状态标志,添加 O_APPEND 标志 */
    ret = fcntl(fd1, F_SETFL, flag | O_APPEND);
    if (-1 == ret) {
        perror("fcntl F_SETFL error");
        close(fd1);
        exit(-1);
    }  

    /* 获取文件状态标志 */
    flag = fcntl(fd1, F_GETFL);
    if(-1 == flag) {
        perror("F_GETFL error");
        close(fd1);
        exit(-1);
    }    
    printf("fd1: %d\nflag: 0x%x\n", fd1, flag);

    close(fd1);
    return 0;
}















