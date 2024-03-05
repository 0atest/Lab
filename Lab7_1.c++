#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode* next;
};

class LinkedList {
protected:
    studentNode* start;
    studentNode** now;

public:
    LinkedList() {
        start = nullptr;
        now = &start;
    }

    ~LinkedList() {
        studentNode* current = start;
        while (current != nullptr) {
            studentNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        studentNode* newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = nullptr;

        if (*now == nullptr) {
            *now = newNode;
        }
        else {
            studentNode* temp = *now;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        now = &(newNode->next);
    }

    void DelNode() {
        if (start == nullptr) {
            return;
        }

        studentNode* temp = start;
        studentNode* prev = nullptr;

        while (temp != *now && temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        if (temp == start) {
            start = start->next;
        }
        else {
            prev->next = temp->next;
        }

        if (temp == *now) {
            *now = prev;
        }

        delete temp;
    }

    void GoNext() {
        if (*now != nullptr) {
            now = &((*now)->next);
        }
    }

    virtual void ShowNode() {
        if (*now != nullptr) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
    virtual void ShowNode1() {
        if (*now != nullptr) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }

    void ShowNode() override {
        studentNode* temp = start;
        while (temp != nullptr) {
            printf("%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }

    void ShowNode1() override {
        studentNode* temp = start;
        while (temp != nullptr) {
            printf("%s\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList* listC = nullptr;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("six", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("two", 2, 'B', 2.2);
    listB.InsNode("six", 5, 'E', 5.5);
    listB.InsNode("one", 1, 'A', 1.10);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode1();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
