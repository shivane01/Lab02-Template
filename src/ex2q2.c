#include <stdio.h>
#include <math.h>
void comma(float num){
    int integer_part = (int)num;
 
    if (integer_part >= 1000) {
        int thousands = integer_part / 1000;
        int rest = integer_part % 1000;
	int decimals =(( num- integer_part)*100);
        printf("%d,%03d.%02d", thousands, rest, decimals);
    } else {
        printf("%.2f", num);
    }
}
int main(void){
    float x1,y1,x2,y2,x3,y3;
    printf("Point 1: ");
    if (scanf(" (%f , %f)",&x1,&y1)!= 2){
    return 1;
    }
    printf("Point 2: ");
    if (scanf(" (%f , %f)",&x2,&y2)!= 2){
    return 1;
    }
    printf("Point 3: ");
    if (scanf(" (%f , %f)",&x3,&y3)!= 2){
    return 1;
    }
    float a=sqrtf((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    float b=sqrtf((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    float c=sqrtf((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    if (a<b && a<c){
    printf("\nP1<->P2: ");
    comma(a);
    printf("\n");
    }
    if (b<a && b<c){
    printf("\nP2<->P3: ");
    comma(b);
    printf("\n");
    }
    if (c<a && c<b){
    printf("\nP1<->P3: ");
    comma(c);
    printf("\n");
    }
    if (a == b && b == c){
    printf("All points are equal distance: ");
    comma(a);
    printf("\n");
    }
    if (a==b && a!=c && b!=c){
    printf("\nP1<->P2: ");
    comma(a);
    printf("\n");
    printf("P2<->P3: ");
    comma(b);
    printf("\n");
    }
    if (b==c && b!=a && c!= a){
    printf("\nP2<->P3: ");
    comma(b);
    printf("\n");
    printf("P1<->P3: ");
    comma(c);
    printf("\n");
    }
    if (c==a && c!=b&& a!= b){
    printf("\nP1<->P2: ");
    comma(a);
    printf("\n");
    printf("P1<->P3: ");
    comma(c);
    printf("\n");
    }
    return 0;
}
