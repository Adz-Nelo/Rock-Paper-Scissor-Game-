#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>

//function declaration
std:: string player();
std:: string computer();

void showChoice(std:: string player, std:: string computer);
void declareWinner(std:: string player, std:: string computer);

void countdown(int seconds);

int main() { 

    //declaring variable
    std:: string user;
    std:: string opponent;
    int playerScore = 0;
    int computerScore = 0;

    do {
        user = player();
        opponent = computer();
        showChoice(user, opponent);
        declareWinner(user, opponent);

    } while(true);

    return 0;
}

std:: string player() {
    //declare variable
    std:: string choice;

    do {
        std:: cout << "\n====== Rock, Paper, Scissor ======" << std:: endl;

        //input method
        std:: cout << "\nEnter your choice ('x' to exit): ";
        std:: cin >> choice;

        if(choice == "x") {
            std:: cout << "\nAre you sure you want to exit?: ";
            std:: cin >> choice;

            do {
                if(choice == "Yes" || choice == "yes") {
                    std:: cout << "\nThank you! hoped you enjoyed the game! 😃\n" << std:: endl;
                    exit(0);
                }

                else if(choice == "No" || choice == "no") {
                    std:: cout << "\nGlad that you've changed your mind 🥹" << std:: endl;
                }

                else {
                    std:: cout << "\nI don't know what you're talking about\n" << std:: endl;
                    std:: cout << "Again, do you want to exit the program?: ";
                    std:: cin >> choice;

                    if(choice == "Yes" || choice == "yes") {
                        std:: cout << "\nThank you! hoped you enjoyed the game! 😃\n" << std:: endl;
                        exit(0);
                    }

                    else if(choice == "No" || choice == "no") {
                    std:: cout << "\nGlad that you've changed your mind 🥹" << std:: endl;
                    }   

                    while(choice != "Yes" && choice != "yes" && choice != "No" && choice != "no") {
                        std:: cout << "\nAre you really that stubborn? again, do you want to exit the program: ";
                        std:: cin >> choice;

                        if(choice == "Yes" || choice == "yes") {
                            std:: cout << "\nThank you! hoped you enjoyed the game! 😃\n" << std:: endl;
                            exit(0);
                        }

                        else if(choice == "No" || choice == "no") {
                            std:: cout << "\nGlad that you've changed your mind 🥹" << std:: endl;
                        }
                    }
                }

            } while(false);
        }

        else if(choice == "Rock" || choice == "rock") {
            std:: cout << "\nYour choice: 🪨" << std:: endl;
        }

        else if(choice == "Paper" || choice == "paper") {
            std:: cout << "\nYour choice: 📃" << std:: endl;
        }

        else if(choice == "Scissor" || choice == "scissor") {
            std:: cout << "\nYour choice: ✂️" << std:: endl;
        }

        else {
            std:: cout << "\nError! 404! ❌" << std:: endl;
        } 

    } while(choice != "Rock" && choice != "rock" && choice != "Paper" && choice != "paper" && choice != "Scissor" && choice != "scissor" && true);
    
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
    int countdownSeconds = 3; //counts down in 3 seconds
    countdown(countdownSeconds);
    std:: cout << "\n\nComputer's choice: " << computer << std:: endl;
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

void countdown(int seconds) {
    std:: cout << "\nComputer is thinking";

    for (int i = seconds; i >= 1; i--) {
        std::cout << ".";
        sleep(1); // Pause for 1 second
    }
}
