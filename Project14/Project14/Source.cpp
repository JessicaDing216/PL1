#include <iostream>
#include<string>
#include "subfunctions.h"

using namespace std;

int main() {
	int inPut;
	string ingredient;
	bool error;


	cout << "\n    *************************************    \n" ;	
	cout << "                Baking Recipes              \n\n";
	cout << "    *************************************    \n\n";
	cout << "  ---------------------------------------------\n\n";



	do {
		cout << "\n Choose the function you want ot use: \n\n   1  Display the list of contents.\n  "
			" 2  Show recipe.\n   3  Input new recipe.\n   4  Ingredient calculation accordingly.\n  "
			" 5  Search accoding to ingredient.\n   6  Quit.\n\n >> Your Choice: ";

		//input validation for the correct data type. There will be the default switch for invalid number
		inPut = checkInput();


		cout << "\n  ---------------------------------------------  \n\n";


				switch (inPut) {
				case 1://print list of recipe

					cout << "\n The recipes are: \n\n";
					printList();
					cout << "\n ** The above are all the recipes we have! **\n";
					cout << "\n  ---------------------------------------------  \n\n";
					break;

				case 2://print the choosen recipe
					int a;
					cout << "\n Please choose which recipe you want to view by entering the recipe number: \n\n";
					printList(); //showing the choices
					cout << "\n  ---------------------------------------------  \n\n";
					cout << ">> Your Choice: ";

					//input validation for the correct data type together with function specified input range check
					do
					{
						error = false;
						a = checkInput();
						if (recipeList[a - 1].recipeNum <= 0) {
							cout << "\n  ---------------------------------------------  \n\n";
							cout << "\n **  Invalid input!  **\n\n Please enter again: ";
							error = true;
						}
					} while (error);

					cout << "\n  ---------------------------------------------  \n\n";
					cout <<"  " << recipeList[a - 1].recipeName << ":\n\n";

					printRecipe(a);

					cout << "\n  ---------------------------------------------  \n\n";

					break;

				case 3://input new recipe

					addRecipe();

					break;

				case 4://calculate according to certain amout of certain ingredient.
					int b, c;
					double amount, percentage;
					cout << "\n Please choose which recipe you want to view by entering the recipe number: \n\n";
					printList(); //showing the choices
					cout << "\n>> Your Choice: ";

					//input validation for the correct data type together with function specified input range check
					do
					{
						error = false;
						b = checkInput();
						if (recipeList[b - 1].recipeNum <= 0) {
							cout << "\n  ---------------------------------------------  \n\n";
							cout << "\n **  Invalid input!  **\n\n Please enter again: ";
							error = true;
						}
					} while (error);

					cout << "\n  ---------------------------------------------  \n\n";

					cout << " Please choose the desired ingredient:\n";
					printRecipeCal(b);//display the ingredients in a recipe

					cout << "\n>> Your Choice: ";

					//input validation for the correct data type together with function specified input range check
					do
					{
						error = false;
						c = checkInput();
						if (recipeList[b - 1].ingredientAmount[c - 1] <= 0) {
							cout << "\n  ---------------------------------------------  \n\n";
							cout << "\n **  Invalid input!  **\n\n Please enter again: ";
							error = true;
						}
					} while (error);


					cout << "\n Please enter the amount of the ingredient (number between 1 and 10000): ";

					//input validation for the correct data type together with function specified input range check
					//Here I restricted the max amout of 10000. in case of inputing unreasonable amount, although upper limit is not necessory.
					do
					{
						error = false;
						amount = checkInput();
						if  (amount <= 0 || amount > 10000) {
							cout << " Invalid input!\n\n Please enter again: ";
							error = true;
						}
					} while (error);					
					

					//calculating the percentage of the ingredient
					cout << "\n  ---------------------------------------------  \n\n";

					cout << "  ** The recipe of " << recipeList[b - 1].recipeName 
						<< " using << "<< recipeList[b - 1].ingredientName[c-1] << " >> " << amount << recipeList[b - 1].ingredientUnit[c - 1] <<":\n\n";


					percentage= percentageCalculation(b, c, amount);

					//output the recipe after calculation
					recipeCalculation(b, percentage);
					cout << "\n  ---------------------------------------------  \n\n";

					break;

				case 5://search recipe for certain ingredient  (or not containing)
					int d;
					cout << "\n Please enter the ingredient name (lower case only): ";
					cin >> ingredient;
					cout << "\n Do you want to list out recipes \n\n    1  containing or \n    2  **NOT** containing \n\n the ingredient << " << ingredient << " >>: ";
		
					//prevent invalid input
					do
					{
						error = false;
						d = checkInput();
						if (d <= 0 || d > 2) {
							cout << "\n  ---------------------------------------------  \n\n";
							cout << "\n **  Invalid input!  **\n\n Please enter again: ";
							error = true;
						}
					} while (error);



					//to choose whether to search for containing or not containing the ingredient.
					switch (d){
					case 1:
						searchIngredient(ingredient);
						break;
					case 2:
						searchIngredientNo(ingredient);
						break;
					default:
						cout << "\nInvalid input.";
						break;
					}

					break;

				case 6://exiting
					cout << "\n    *************************************    \n";
					cout << "\n        Hope you enjoy the recipe!\n\n";
					cout << "    *************************************    \n\n";
					cout << "  ---------------------------------------------\n\n";
					break;

				default:
					cout << "\n  ** Invalid input!! **\n";
					cout << "\n  ---------------------------------------------  \n\n";
					break;
				}

	} while (inPut != 6);


	return 0;
}


