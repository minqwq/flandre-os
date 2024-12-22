#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 200

/* 修复：
 * 1. 主函数中的死循环不应使用return 0，应该继续循环
 * 2. 不需要声明自定义的scanf，直接使用标准库的即可
 */
void execute(char *cmd) {
  if (strcmp(cmd, "st") == 0) {
    // 可以添加st命令的处理逻辑
    // 但请不要使用 return 0;
    // 因为使用 void 定义的函数是不能有返回值的
    exit(0);
  } else if (strcmp(cmd, "about") == 0) {
    printf("Flandre OS v0.1 DR1\n");
  } else if (strcmp(cmd, "help") == 0) {
    printf("about\nst\nnull");
  } else if (strcmp(cmd, "") == 0) {
    printf("");
  } else {
    printf("Unknown command >.<\n");
  }
}

int main() {
  char cmd[MAX_CMD_LENGTH];

  printf("Flandre OS v0.1\nDevelopment Release 1\n");

  /* 死循环，继续读取用户输入 */
  while (1) {
    printf("nouser > ");
    if (fgets(cmd, MAX_CMD_LENGTH, stdin) == NULL) {
      // 如果输入错误，不处理并继续
      continue;
    }
    cmd[strcspn(cmd, "\n")] = '\0'; // 删除输入中的换行符

    execute(cmd); // 执行命令
  }

  return 0; // 程序结束时返回
}
