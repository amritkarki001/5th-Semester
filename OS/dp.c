// Dining philosopher problem
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For abs()
int tph, philname[20], status[20], howhung, hu[20], cho; // Global variables
void one(); // Function declaration
void two(); // Function declaration
int main() {
 int i;
 printf("\n\nDINING PHILOSOPHER PROBLEM");
 printf("\nEnter the total no. of philosophers: ");
 scanf("%d", &tph);
 
 for (i = 0; i < tph; i++) {
 philname[i] = (i + 1); // Assigning philosopher numbers
 status[i] = 1; // Setting all philosophers' status as thinking (1)
 }
 
 printf("How many are hungry: ");
 scanf("%d", &howhung);
 
 if (howhung == tph) {
 printf("\nAll are hungry.. Deadlock stage will occur\n");
 printf("Exiting..\n");
 exit(0); // Exiting due to deadlock
 } else {
 for (i = 0; i < howhung; i++) {
 printf("Enter philosopher %d position: ", (i + 1));
 scanf("%d", &hu[i]);
 status[hu[i]] = 2; // Set status as hungry (2)
 }
 
 do {
 printf("\n1. One can eat at a time\t2. Two can eat at a time\t3. Exit\nEnter your choice: ");
 scanf("%d", &cho);
 
 switch (cho) {
 case 1:
 one();
 break;
 case 2:
 two();
 break;
 case 3:
 exit(0);
 default:
 printf("\nInvalid option..");
 }
 } while (1);
 }
 
 return 0;
}
void one() {
 int pos = 0, i, x;
 printf("\nAllow one philosopher to eat at any time\n");
 
 for (i = 0; i < howhung; i++, pos++) {
 printf("\nP %d is granted to eat", philname[hu[pos]]);
 status[hu[pos]] = 1; // After eating, status becomes thinking (1)
 
 for (x = pos + 1; x < howhung; x++) {
 printf("\nP %d is waiting", philname[hu[x]]);
 }
 
 printf("\nP %d finished eating", philname[hu[pos]]);
 }
}
void two() {
 int i, j, s = 0, t, r, x;
 printf("\nAllow two philosophers to eat at the same time\n");
 
 for (i = 0; i < howhung; i++) {
 for (j = i + 1; j < howhung; j++) {
 if (abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != tph - 1) {
 printf("\n\nCombination %d\n", (s + 1));
 t = hu[i];
 r = hu[j];
 s++;
 printf("\nP %d and P %d are granted to eat", philname[t], philname[r]);
 
 for (x = 0; x < howhung; x++) {
 if (hu[x] != t && hu[x] != r) {
 printf("\nP %d is waiting", philname[hu[x]]);
 }
 }
 
 printf("\nP %d and P %d finished eating", philname[t], philname[r]);
 }
 }
 }
}