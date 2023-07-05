#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>

//function declaration
std:: string player();
std:: string computer();

void showChoice(std:: string player, std:: string computer);
void declareWinner(std:: string player, std:: string computer);

void countdown(int seconds)
{
    for (int i = seconds; i >= 1; i--)
    {
        std::cout << i << "..." << std::endl;
        sleep(1); // Pause for 1 second
    }
}

int main() {

    //declaring variable
    std:: string user;
    std:: string opponent;

    user = player();
    opponent = computer();
    showChoice(user, opponent);
    declareWinner(user, opponent);
    
    return 0;
}

std:: string player() {
    //declare variable
    std:: string choice;

    do {
        std:: cout << "====== Rock, Paper, Scissor ======" << std:: endl;

        //input method
        std:: cout << "\nEnter your choice: ";
        std:: cin >> choice;

        if(choice == "Rock" || choice == "rock") {
            std:: cout << "\nYour choice: 🪨" << std:: endl;
        }

        else if(choice == "Paper" || choice == "paper") {
            std:: cout << "\nYour choice: 📃" << std:: endl;
        }

        else if(choice == "Scissor" || choice == "scissor") {
            std:: cout << "\nYour choice: ✂️" << std:: endl;
        }

        else {
            std:: cout << "\nError! 404! ❌\n" << std:: endl;
        } 

    } while(choice != "Rock" && choice != "rock" && choice != "Paper" && choice != "paper" && choice != "Scissor" && choice != "scissor");
    
    return choice;
}

std:: string computer() {
    srand(time(NULL)); // Seeds the random number
    int randNum = rand() % 3 + 1; //Generates number from 1-3, usually computer always starts from 0 counting number that is why I put + 1 to represent as a starting value of "1"

    if(randNum == 1) {
        return "🪨";
    }

    else if(randNum == 2) {
        return "📃";
    }

    else {
        return "✂️";
    }
}

void showChoice(std:: string player, std:: string computer) {
    std:: cout << std:: endl;
    std:: cout << "Computer is thinking in.. " << std:: endl;
    std:: cout << std:: endl;
    int countdownSeconds = 3; //counts down in 3 seconds
    countdown(countdownSeconds);
    std:: cout << "\nComputer's choice: " << computer << std:: endl;
}
void declareWinner(std:: string player, std:: string computer) {
    if(player == "Rock" || player == "rock") {
        if(computer == "🪨") {
            std:: cout << "\nIt's a tie! 👔" << std:: endl;
        }

        else if(computer == "📃") {
            std:: cout << "\nYou lose! 😓" << std:: endl;
        }

        else {
            std:: cout << "\nYou win! 🎉" << std:: endl;
        }
    }

    else if(player == "Paper" || player == "paper") {
        if(computer == "🪨") {
            std:: cout << "\nYou win! 🎉" << std:: endl;
        }

        else if(computer == "📃") {
            std:: cout << "\nIt's a tie! 👔" << std:: endl;
        }

        else {
            std:: cout << "\nYou lose! 😓" << std:: endl;
        }
    }

    else if(player == "Scissor" || player == "scissor") {
        if(computer == "🪨") {
            std:: cout << "\nYou lose! 😓" << std:: endl;
        }

        else if(computer == "📃") {
            std:: cout << "\nYou win! 🎉" << std:: endl;
        }

        else {
            std:: cout << "\nIt's a tie! 👔" << std:: endl;
        }
    }
}