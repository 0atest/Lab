/* เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน GetMatrix() 
เพื่อรับจำนวนแถวคอลัมน์ 
และค่าของแต่ละสมาชิกในเมทริกซ์จากคีย์บอร์ดตามโปรโตไทป์ต่อไปนี้ */
#include <stdio.h>

void GetMatrix( int value[], int *row, int *col ) ;

int main() {
    int *data, m, n ;
    GetMatrix( &data, &m, &n ) ;
    return 0 ;
}//end function

void GetMatrix( int value[], int *row, int *col ){
    printf("How many row ?: ");
    scanf("%d", row);
    printf("How many col ?: ");
    scanf("%d", col);
    
    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *col; ++j) {
            printf("Membership fee [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &value[i * *col + j]);
        }
    }
    
    printf("Number of members : [%d][%d]", *row, *col);
    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j <= *col; ++j) {
            printf("\n");
            printf("Member [%d][%d] : %d", i + 1, j + 1, value[i * *col + j]);
        }
    }
}