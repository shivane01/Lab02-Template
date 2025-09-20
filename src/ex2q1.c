#include <stdio.h>
#define APPLE_PRICE 5.99
#define CARROT_PRICE 3.99
#define CHIP_PRICE 2.99
#define CANDY_PRICE 1.50
int main(void) {
    float discounted_candy_amount=0.0f;
    float overall_discount=0.0f;
    float subtotal=0.0f;
    float tax= 0.0f;
    float total=0.0f;
    float apple_quan, carrot_quan;
    int chip_quan, candy_quan;
    int apple_check, carrot_check, chips_check, candy_check;
    printf("Apples     (7.20  kg) : ");
    apple_check = scanf("%f",&apple_quan);
    if (apple_check != 1 || apple_quan > 7.20 || apple_quan < 0){ 
            return 1;}
    printf("Carrots    (4.10  kg) : ");
    carrot_check = scanf("%f", &carrot_quan);
    if (carrot_check != 1 || carrot_quan > 4.10 || carrot_quan < 0){
            return 1;}
    printf("Chips      (9  units) : ");
    chips_check = scanf("%d",&chip_quan);
    if (chips_check != 1 || chip_quan > 9 || chip_quan < 0){
            return 1;}
    printf("Candy      (3  units) : ");
    candy_check = scanf("%d",&candy_quan);
    if (candy_check != 1 || candy_quan > 3 || candy_quan < 0){
            return 1;}
    if (apple_quan == 0 && carrot_quan == 0 && chip_quan == 0 && candy_quan == 0){
            return 1;}
    float apple_cost = apple_quan * APPLE_PRICE;
    float carrot_cost = carrot_quan * CARROT_PRICE;
    float chip_cost = chip_quan * CHIP_PRICE;
    float candy_cost = candy_quan * CANDY_PRICE;
// DISCOUNT OFFER
    if (chip_quan >= 2 && candy_quan >= 1){
	int discounted_candies = (chip_quan / 2);
        if (discounted_candies > candy_quan) {
             discounted_candies = candy_quan;
}
    discounted_candy_amount = discounted_candies * (CANDY_PRICE * 0.5);
}
    printf("\n-------------------------------------------------------------------\n");
    printf("| Item     | Quantity     | Cost       | Discount    | Total      |\n");
    if (apple_quan > 0) {
    printf("| Apples   | %.2f      kg | $ %8.2f | -$ %8.2f | $ %8.2f |\n", apple_quan, apple_cost, 0.00, apple_cost);
    }
    if (carrot_quan > 0) {
    printf("| Carrots  | %.2f      kg | $ %8.2f | -$ %8.2f | $ %8.2f |\n", carrot_quan, carrot_cost, 0.00, carrot_cost);
    }
    if (chip_quan > 0) {
    printf("| Chips    | %d            | $ %8.2f | -$ %8.2f | $ %8.2f |\n", chip_quan, chip_cost, 0.00, chip_cost);
    }
    if (candy_quan > 0) {
    printf("| Candy    | %d            | $ %8.2f | -$ %8.2f | $ %8.2f |\n", candy_quan, candy_cost, discounted_candy_amount, candy_cost - discounted_candy_amount);
    }
    printf("-------------------------------------------------------------------\n");
// Cost Calcultions and promotions
   float table_sum = (apple_cost) + (carrot_cost) + (chip_cost) + (candy_cost-discounted_candy_amount);
    if (apple_quan >= 1 && carrot_quan >= 1 && chip_quan >= 1 && candy_quan >= 1){
        overall_discount = 0.10*table_sum;
    }
    subtotal = table_sum - overall_discount;
    tax = 0.05*subtotal;
    total = subtotal + tax;
    if (overall_discount == 0) {
    printf("\nSubtotal        : $%.2f\n", table_sum);
}  else {
    printf("\nSubtotal        : $%.2f - $%.2f = $%.2f\n",table_sum, overall_discount, subtotal);
		    }
     printf("Tax (5%%)        : $%.2f\n", tax);
     printf("----------------------------------------------------\n");
     printf("Total           : $%.2f\n", total);
     return 0;
}
