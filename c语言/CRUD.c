#include <stdio.h>
#include <string.h>

#define MAX_STU 100

typedef struct {
    int id;
    char name[20];
    int age;
} Student;

Student stuArr[MAX_STU];
int count = 0;

// 创建-新增
void create()
{
    if(count >= MAX_STU)
    {
        printf("数据库已满，无法添加！\n");
        return;
    }
    int id, age;
    char name[20];
    printf("请输入学号：");
    scanf("%d", &id);
    printf("请输入姓名：");
    scanf("%s", name);
    printf("请输入年龄：");
    scanf("%d", &age);

    stuArr[count].id = id;
    strcpy(stuArr[count].name, name);
    stuArr[count].age = age;
    count++;
    printf("添加成功！\n");
}

// 查询全部
void read_all()
{
    if(count == 0)
    {
        printf("暂无学生数据\n");
        return;
    }
    printf("\n================学生信息列表================\n");
    printf("%-8s %-12s %-6s\n","学号","姓名","年龄");
    for(int i = 0; i < count; i++)
    {
        printf("%-8d %-12s %-6d\n", stuArr[i].id, stuArr[i].name, stuArr[i].age);
    }
    printf("============================================\n");
}

// 按学号查询单个
void read_by_id()
{
    int id;
    printf("输入要查询的学号：");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(stuArr[i].id == id)
        {
            printf("查询结果：学号:%d 姓名:%s 年龄:%d\n",stuArr[i].id,stuArr[i].name,stuArr[i].age);
            return;
        }
    }
    printf("未找到该学号学生\n");
}

// 修改
void update()
{
    int id, new_age;
    char new_name[20];
    printf("输入要修改的学号：");
    scanf("%d", &id);
    for(int i = 0; i < count; i++)
    {
        if(stuArr[i].id == id)
        {
            printf("输入新姓名：");
            scanf("%s", new_name);
            printf("输入新年龄：");
            scanf("%d", &new_age);
            strcpy(stuArr[i].name, new_name);
            stuArr[i].age = new_age;
            printf("修改完成\n");
            return;
        }
    }
    printf("找不到该学号，修改失败\n");
}

// 删除
void delete_by_id()
{
    int id;
    printf("输入要删除的学号：");
    scanf("%d", &id);
    int pos = -1;
    for(int i = 0; i < count; i++)
    {
        if(stuArr[i].id == id)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        printf("找不到该学号，删除失败\n");
        return;
    }
    //元素前移覆盖
    for(int i = pos; i < count-1; i++)
    {
        stuArr[i] = stuArr[i+1];
    }
    count--;
    printf("删除成功\n");
}

//打印主菜单
void show_menu()
{
    printf("\n==========学生CRUD管理系统==========\n");
    printf("1.新增学生\n");
    printf("2.查看全部学生\n");
    printf("3.按学号查询\n");
    printf("4.修改学生信息\n");
    printf("5.删除学生\n");
    printf("0.退出程序\n");
    printf("====================================\n");
    printf("请输入操作序号：");
}

int main(void)
{
    int op;
    while(1)
    {
        show_menu();
        scanf("%d",&op);
        switch(op)
        {
            case 1: create();break;
            case 2: read_all();break;
            case 3: read_by_id();break;
            case 4: update();break;
            case 5: delete_by_id();break;
            case 0: printf("程序退出\n");return 0;
            default: printf("输入无效，请重新选择！\n");
        }
    }
    return 0;
}
