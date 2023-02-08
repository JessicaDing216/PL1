#pragma once
#include <iostream>
#include<string>
using namespace std;

struct recipeForm {
	int recipeNum;
	string recipeName;
	string ingredientName[20];
	double ingredientAmount[20];
	string ingredientUnit[20];
};
//concept is to use array inside the struct to store the ingredients. The arrarys are paralelle and resctricted to 20 sets.

recipeForm recipeList[];

void printList();
void printRecipe(int);
void addRecipe();
void printRecipeCal(int);
double percentageCalculation(int, int, double);
void recipeCalculation(int, double);
void searchIngredient(string);
void searchIngredientNo(string);
int checkInput();

