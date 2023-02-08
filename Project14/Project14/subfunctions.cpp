#include <iostream>
#include<string>
#include "subfunctions.h"

using namespace std;

//the list of ready existing recipe
recipeForm recipeList[50] = { 
	{1, "Cinnamon Roll",{"milk","dry yeast","sugar","salt","ground cardamom","egg","flour","butter"},{500,16,180,4,4,50,1000,170},{"ml", "g","g","g","g","g","g","g"}},
	{2, "Lemon Curd", {"whole lemon","egg","sugar","butter"},{500,200,200,100},{"g","g","g","g"} },
	{3, "Scone", {"flour","baking powder","butter","milk","salt"}, {225,12.5,50,150,2}, {"g","g","g","ml","g"}},
	{4, "Yorkshire Pudding", {"flour","egg","milk","salt"}, {150,200,250,2}, {"g","g","ml","g"}}};


//printing the recipe list.
void printList(){
	for (int i = 0;recipeList[i].recipeNum > 0;i++) {
		cout << "  " << recipeList[i].recipeNum << "  " << recipeList[i].recipeName << "\n";
	}
}

//printing out the recipe content
void printRecipe(int x) {
	for (int i = 0;recipeList[x - 1].ingredientAmount[i] > 0;i++) {
		cout << "  *  " << recipeList[x - 1].ingredientName[i] << "      " << recipeList[x - 1].ingredientAmount[i]
			 << recipeList[x - 1].ingredientUnit[i] << "\n";
	}
}


//adding new recipe
void addRecipe() {
	int x=0, y;

	//for determining the last data number in the array. 
	//As the recipe array was set to have the max volume of 50, there's no point in determining the size of the array.
	//The point of numbering the item is 1.easier to run the functions, 2. to determin the number for new data.
	for (int i = 0; recipeList[i].recipeNum > 0;i++)
		x++;

	//the new array can be started here once the last position is determined.
	recipeList[x].recipeNum = x+1;
	cout << " Please enter the name of the new recipe: ";
	cin.ignore();
	getline(cin, recipeList[x].recipeName);
	cout << "\n Please enter the number of ingredients (max of 20): ";

	//this is to determin the length of the loop.
	//input validation for the correct data type together with function specified input range check
	bool check;
		do
		{
			check = false;
			y = checkInput();
			if  (y <= 0|| y>20) {
				cout << "\n  ---------------------------------------------  \n\n";
				cout << "\n **  Invalid input!  **\n\n Please enter again: ";
				check = true;
			}
		} while (check);

		cout << "\n  ---------------------------------------------  \n\n";
		cout << " Now please start to enter data accordingly: \n\n";

	

	for (int n = 0; n < y; n++) {
		cout << "\n  >> Name of ingredient (lower case only): ";
		cin >> recipeList[x].ingredientName[n];
		cout << "\n  >> Amount (numbers only): ";
		//input validation. Since the number part will effect the calculation and might cause problem, so the validation was targeting the numbers only.
		recipeList[x].ingredientAmount[n] = checkInput();
		cout << "\n  >> Unit (g / ml): ";
		cin >> recipeList[x].ingredientUnit[n];
	}

}


// so that each ingredient have a number (to let the user able to choose just by inputing number
void printRecipeCal(int x) {
	for (int i = 0;recipeList[x - 1].ingredientAmount[i] > 0;i++) {
		cout << "  " <<i+1 <<"  " << recipeList[x - 1].ingredientName[i] << "  " << recipeList[x - 1].ingredientAmount[i]
			<< recipeList[x - 1].ingredientUnit[i] << "\n";
	}
}

double percentageCalculation(int x, int y, double z) {
	double p;
	p= z/recipeList[x-1].ingredientAmount[y-1];
	return p;
}

void recipeCalculation(int x, double y) {
	for (int i = 0;recipeList[x - 1].ingredientAmount[i] > 0;i++) {
		cout << "  *  " << recipeList[x - 1].ingredientName[i] << "  " << recipeList[x - 1].ingredientAmount[i] * y
			<< recipeList[x - 1].ingredientUnit[i] << "\n";
	}
}


//search for certain ingredient in all recipes
void searchIngredient(string n) {
	cout << "\n  ---------------------------------------------  \n\n";
	cout << "\n The recipes containing << " << n << " >> : \n\n";
	bool ref=false; //reference indicator
	for (int i = 0; recipeList[i].recipeNum > 0; i++) {
		for (int x = 0; recipeList[i].ingredientAmount[x] > 0; x++) {
			if (recipeList[i].ingredientName[x]==n) {
				ref = true;
				cout <<"  *  "<< recipeList[i].recipeName << "\n";
				break;
			}
		}
	}
	if (ref == false)
		cout << "\n No recipe found!!" << "\n\n  ---------------------------------------------  \n\n";
	else
		cout << "\n The above are the recipes found.\n" << "\n  ---------------------------------------------  \n\n";

}

//search for **NOT** having certain ingredient in all recipes
void searchIngredientNo(string n) {
	cout << "\n  ---------------------------------------------  \n\n";
	cout << "\n The recipes do **NOT** contain << " << n << " >> : \n\n";
	bool ref = false; //reference indicator
	int p=0; //to verify if there's no recipe found
	for (int i = 0; recipeList[i].recipeNum > 0; i++) {
		for (int x = 0; recipeList[i].ingredientAmount[x] > 0; x++) {
			if (recipeList[i].ingredientName[x] == n) {
				ref = true;
			}
		}
		if (ref == false) {
			cout << "  *  " << recipeList[i].recipeName << "\n";
			p++;
		}
		else {
			ref = false;
		}
	}

	if (p==0)
		cout << "\n No recipe found!!" << "\n\n  ---------------------------------------------  \n\n";

	else
		cout << "\n The above are the recipes found.\n" << "\n  ---------------------------------------------  \n\n";

}

// input validation moved to subfunction.
int checkInput() {
	bool check;
	int x;
	do
	{
		check = false;
		cin >> x;
		if (cin.fail())
		{
			cout << "\n  ---------------------------------------------  \n\n";
			cout << "\n **  Invalid input!  **\n\n Please enter again: ";
			check = true;
			cin.clear();
			cin.ignore(80, '\n');
		}

	} while (check);
	return x;
}