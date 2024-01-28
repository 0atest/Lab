/* เมื่อลิงค์ลิสมีจุดเริ่มต้น (start) และโหนดปัจจุบัน (now)
เป็นพอยน์เตอร์ 1 ระดับ ถูกประกาศใน main แล้ว...
ฟังก์ชัน AddNode() ทำหน้าที่เพิ่มโหนดต่อท้ายลิงค์ลิส ให้ now ชี้ node ใหม่
ส่วนฟังก์ชัน InsertNode() ทำหน้าที่แทรกโหนดใหม่ต่อจากโหนดปัจจุบัน
และฟังก์ชัน DelNode() มีหน้าที่ลบโหนดที่ต่อจากโหนดปัจจุบัน
จะทำงานเป็นขั้นตอนอย่างไร? จงนำทฤษฏีดังกล่าว
มาสร้างฟังก์ชัน AddNode(), InsNode() และ DelNode() รองรับการเรียกใช้งาน */
#include <stdio.h>
#include <string.h>

struct studentNode
{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

struct studentNode *AddNode(struct studentNode **start, char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *walk, char name[], int age, char sex, float gpa, struct studentNode **begin);
void DelNode(struct studentNode **walk, struct studentNode **begin);
void ShowAll(struct studentNode *walk);

int main()
{
    struct studentNode *start, *now;
    start = NULL;
    now = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    now = AddNode(&start, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44, &start);
    ShowAll(start);

    now = start->next->next;
    DelNode(&now, &start);
    ShowAll(start);

    return 0;
}// end function

struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa)
{
    struct studentNode *temp = NULL;

	while (*walk != NULL)
	{
		temp = *walk;
		walk = &(*walk)->next;
	} // end while

	*walk = new struct studentNode;

	strcpy((*walk)->name, name);
	(*walk)->age = age;
	(*walk)->sex = sex;
	(*walk)->gpa = gpa;

	(*walk)->next = NULL;
	(*walk)->back = temp;

	return *walk;
}// end function

void InsNode(struct studentNode *walk, char name[], int age, char sex, float gpa, struct studentNode **begin)
{
	if (walk->back != NULL)
	{
		walk->back->next = new struct studentNode;

		strcpy(walk->back->next->name, name);
		walk->back->next->next = walk;
		walk->back->next->back = walk->back;
		walk->back = walk->back->next;
	}
	else
	{
		*begin = new struct studentNode;

		strcpy((*begin)->name, name);
		(*begin)->next = walk;
		(*begin)->back = NULL;
		walk->back = *begin;
	}
    
}

void DelNode(struct studentNode **walk, struct studentNode **begin)
{
    struct studentNode *temp;

    if ((*walk)->back != NULL)
    {
        (*walk)->back->next = (*walk)->next;
    }
    else
    {
        *begin = (*walk)->next;
    }

    if ((*walk)->next != NULL)
    {
        (*walk)->next->back = (*walk)->back;
        temp = (*walk)->next;
    }
    else
    {
        temp = (*walk)->back;
    }
    delete *walk;
    *walk = temp;
}// end function

void ShowAll(struct studentNode *walk)
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}// end function