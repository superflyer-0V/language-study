#include <iostream>
#include <vector>
#include <string>

// 学生结构体
struct Student
{
    int id;
    std::string name;
    int score;
};

// 1. 新增学生 Create
void addStudent(std::vector<Student>& stuList)
{
    Student s;
    std::cout << "请输入学号：";
    std::cin >> s.id;
    std::cout << "请输入姓名：";
    std::cin >> s.name;
    std::cout << "请输入分数：";
    std::cin >> s.score;

    stuList.push_back(s);
    std::cout << "添加成功\n\n";
}

// 2. 遍历查询所有 Read
void showAll(const std::vector<Student>& stuList)
{
    if (stuList.empty())
    {
        std::cout << "暂无学生数据\n\n";
        return;
    }

    std::cout << "=====学生列表=====\n";
    std::cout << "学号\t姓名\t分数\n";
    for (const auto& item : stuList)
    {
        std::cout << item.id << "\t" << item.name << "\t" << item.score << "\n";
    }
    std::cout << "\n";
}

// 根据学号查找单个学生
int findById(const std::vector<Student>& stuList, int id)
{
    for (int i = 0; i < stuList.size(); ++i)
    {
        if (stuList[i].id == id)
        {
            return i; // 返回下标
        }
    }
    return -1; // 未找到
}

// 3. 修改学生信息 Update
void updateStudent(std::vector<Student>& stuList)
{
    int id;
    std::cout << "输入要修改的学号：";
    std::cin >> id;

    int index = findById(stuList, id);
    if (index == -1)
    {
        std::cout << "未找到该学生\n\n";
        return;
    }

    std::cout << "输入新姓名：";
    std::cin >> stuList[index].name;
    std::cout << "输入新分数：";
    std::cin >> stuList[index].score;
    std::cout << "修改完成\n\n";
}

// 4. 删除学生 Delete
void deleteStudent(std::vector<Student>& stuList)
{
    int id;
    std::cout << "输入要删除的学号：";
    std::cin >> id;

    int index = findById(stuList, id);
    if (index == -1)
    {
        std::cout << "未找到该学生\n\n";
        return;
    }

    // vector删除：erase(迭代器)
    stuList.erase(stuList.begin() + index);
    std::cout << "删除成功\n\n";
}

// 菜单界面
void menu()
{
    std::cout << "========CRUD菜单=======\n";
    std::cout << "1.新增学生\n";
    std::cout << "2.查看全部\n";
    std::cout << "3.修改学生\n";
    std::cout << "4.删除学生\n";
    std::cout << "0.退出程序\n";
    std::cout << "请选择：";
}

int main()
{
    std::vector<Student> studentList;
    int op;

    while (true)
    {
        menu();
        std::cin >> op;
        switch (op)
        {
            case 1: addStudent(studentList); break;
            case 2: showAll(studentList); break;
            case 3: updateStudent(studentList); break;
            case 4: deleteStudent(studentList); break;
            case 0:
                std::cout << "程序结束";
                return 0;
            default:
                std::cout << "输入错误，请重新选择\n\n";
        }
    }
}