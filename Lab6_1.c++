/* เมื่อลิงค์ลิสต์มีจุดเริ่มต้น (start) และโหนดปัจจุบัน (now) เป็นพอยน์เตอร์ 1 ระดับ ถูกประกาศใน main()
AddNode() ทำหน้าที่เพิ่มโหนดใหม่ต่อท้ายลิงค์ลิสต์ และส่งออกโหนดใหม่มาให้โหนดปัจจุบัน
InsertNode() มีหน้าที่แทรกโหนดใหม่อยู่ก่อนโหนดปัจจุบัน 
DelNode() มีหน้าที่ลบโหนดปัจจุบันพร้อมทั้งเปลี่ยนโหนดปัจจุบันให้ชี้ไปที่โหนดถัดไป 
แต่ถ้าไม่มีก็ให้ชี้โหนดก่อนหน้า
ฟังก์ชันเหล่านี้จะทำงานเป็นขั้นตอนอย่างไร?
สร้างฟังก์ชัน GoBack(), AddNode(), InsertNode() และ DelNode() รองรับการเรียกใช้งานดังต่อไปนี้ */

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

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *walk, char name[], int age, char sex, float gpa, struct studentNode **begin) ;
void DelNode(struct studentNode **walk, struct studentNode **begin) ;
void GoBack(struct studentNode **walk) ;

int main()
{
    struct studentNode *start, *now;
    start = NULL;
    now = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33,&start);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44,&start);
    ShowAll(start);
    GoBack(&now);
    DelNode(&now,&start);
    ShowAll(start);
    DelNode(&now,&start);
    ShowAll(start);
    DelNode(&now,&start);
    ShowAll(start);
    return 0;
} // end function

void ShowAll(struct studentNode *walk)
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    } // end while
    printf(" \n");
} // end function

void GoBack(struct studentNode **walk) {
    if ( (*walk)->next != NULL) {
        // เปลี่ยน now1 ให้ชี้ไปที่โหนดถัดไป
        *walk = (*walk)->next;
    }
}

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