student_list = []

def add_student():
    name = input("请输入学生姓名：")
    while True:
        try:
            score = int(input("请输入学生分数："))
            # 校验分数范围
            if 0 <= score <= 100:
                break
            else:
                print("分数必须在0‑100之间，请重新输入！")
        except ValueError:
            print("请输入合法数字！")

    stu_dict = {"name": name, "score": score}
    student_list.append(stu_dict)
    print("学生添加完成")

def show_all():
    # 判断有没有学生数据
    if len(student_list) == 0:
        print("暂无学生数据！")
        return
    print("========学生成绩列表========")
    for stu in student_list:
        print(f"姓名：{stu['name']}  分数：{stu['score']}")

def search_student():
    name = input("请输入要查询的学生姓名：")
    for stu in student_list:
        if stu["name"] == name:
            print(f"查询成功：姓名:{stu['name']}，分数:{stu['score']}")
            return
    # 循环走完没有return，代表没找到
    print("没有找到该学生")

def modify_score():
    name = input("请输入要修改分数的学生姓名：")
    for stu in student_list:
        if stu["name"] == name:
            while True:
                try:
                    new_score = int(input("请输入新的分数："))
                    if 0 <= new_score <= 100:
                        break
                    else:
                        print("分数必须0‑100！")
                except ValueError:
                    print("请输入数字！")
            stu["score"] = new_score
            print("分数修改完成")
            return
    print("未找到该学生，修改失败")

def del_student():
    name = input("请输入要删除的学生姓名：")
    # i 是列表下标
    for i in range(len(student_list)):
        stu = student_list[i]
        if stu["name"] == name:
            student_list.pop(i)
            print("学生删除成功")
            return
    print("未找到该学生，删除失败")

def save_data():
    """保存数据到data.txt"""
    with open("data.txt", "w", encoding="utf-8") as f:
        for stu in student_list:
            line = f"{stu['name']}|{stu['score']}\n"
            f.write(line)
    print("数据已保存")


def load_data():
    """从文件加载数据到student_list"""
    import os
    if not os.path.exists("data.txt"):
        # 文件不存在，直接返回，列表保持空
        return
    student_list.clear()
    with open("data.txt", "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            name, score_str = line.split("|")
            stu = {"name": name, "score": int(score_str)}
            student_list.append(stu)

def main():
    # 程序启动，加载文件数据
    load_data()
    while True:
        print("\n===== 简易学生成绩管理系统 =====")
        print("1. 添加学生")
        print("2. 查看全部学生")
        print("3. 查询学生")
        print("4. 修改成绩")
        print("5. 删除学生")
        print("0. 退出系统")

        op = input("请输入功能序号：")

        if op == "1":
            add_student()
            save_data()   # 添加完立刻保存
        elif op == "2":
            show_all()
        elif op == "3":
            search_student()
        elif op == "4":
            modify_score()
            save_data()   # 修改完保存
        elif op == "5":
            del_student()
            save_data()   # 删除完保存
        elif op == "0":
            print("程序退出，再见！")
            break
        else:
            print("输入无效，请输入0‑5之间的数字！")

if __name__ == "__main__":
    main()