/* จงเขียนคำสั่งในการ Swap Node เพื่อสลับตำแหน่งระหว่างโหนด A และ B
เช่น Start > One > Two > Three > Four > Five

เรียกใช้คำสั่ง Swap ตำแหน่ง One และ Four ควรได้ผลลัพธ์
Start > Four > Two > Three > One > Five

สิ่งที่ควรจะทำได้
- สามารถ Swap ที่ตำแหน่งแรกได้
- ไม่สามารถ Swap ได้ ถ้าไม่มีข้อมูลใน Linkedlist
- ไม่สามารถ Swap ได้ ถ้ามีข้อมูลเพียงแค่ 1 ข้อมูล
- สามารถใส่ตำแหน่ง A และ B เพื่อเลือก Swap ข้อมูลได้ */

#include <stdio.h>
#include <string.h>

struct studentNode{
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
};

struct studentNode *AddNode( struct studentNode **, char name[], int age, char sex, float gpa ) ;
void ShowAll( struct studentNode *walk ) ;
void Swap( struct studentNode **walk, int A, int B ) ;
	
int main() {
	struct studentNode *start, *now, **walk ;
	start = NULL ;
	AddNode( &start, "one", 6, 'M', 3.11 ) ;
	AddNode( &start, "two", 8, 'F', 3.22 ) ;
	AddNode( &start, "three", 10, 'M', 3.33 ) ;
	AddNode( &start, "four", 12, 'F', 3.44 ) ;
	
	printf( "Before Swap : " ) ;
	ShowAll( start ) ;
	
	Swap( &start, 1, 4 ) ;
	
	printf( "After Swap : " ) ;
	ShowAll( start ) ;
	
	return 0 ;
}

struct studentNode *AddNode( struct studentNode **walk, char name[], int age, char sex, float gpa ) {
	
	while( ( *walk ) != NULL ){
		walk = &(( *walk )->next) ;
	}
	
	*walk = new struct studentNode ;
	strcpy( ( *walk )->name, name ) ;
	( *walk )->age = age ;
	( *walk )->sex = sex ;
	( *walk )->gpa = gpa ;
	( *walk )->next = NULL ;
	
	return *walk;
}

void Swap( struct studentNode **walk, int A, int B ) {
	if( *walk == NULL || ( *walk )->next == NULL ) {
		printf( "Empty node or less then one node.\n" ) ;
		return ;
	}
	
	if( A == B ) {
		printf( "Unable to swap positions.\n" ) ;
		return ;
	}
	
	struct studentNode *befA = NULL, *aftA = *walk ; //before / after
	for( int i = 1 ; aftA != NULL && i < A ; ++i ) {
		befA = aftA ;
		aftA = aftA->next ;
	}
	
	struct studentNode *befB = NULL, *aftB = *walk ;
	for( int i = 1 ; aftB != NULL && i < B ; ++i ) {
		befB = aftB ;
		aftB = aftB->next ;
	}
	
	if( aftA == NULL || aftB == NULL ) {
		printf( "Error.\n" ) ;
		return ;
	}
	
	if( befA != NULL ) {
		befA->next = aftB ;
	} else {
		*walk = aftB ;
	}
	
	if( befB != NULL ) {
		befB->next = aftA ;
	} else {
		*walk = aftA ;
	}
	
	struct studentNode *temp = aftA->next ;
	aftA->next = aftB->next ;
	aftB->next = temp ;
}

void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end function