// เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชันตามอัลกอริทึม Binary Search
#include <stdio.h>

int BinSearch(int data[], int n , int find ) ;

int main() {
 int data[ 6 ] = { 1, 2, 3, 4, 5, 7 } ;
 
 printf("Found 5 at %d\n", BinSearch( data, 6, 5) );
 return 0 ;
}//end function

int BinSearch(int data[], int n , int find )  {
        int i , pos = -1;
        for( i = 0 ; i < n ; i++ ){
                if ( data[i] == find ){
                        pos = i;
                        break;
                }
        }
        return pos ; 
}