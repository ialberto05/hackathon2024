#include <iostream>
#include <string>


int askQuestion(const std::string& question) {
    int score = 0;
    std::string answer;

    std::cout << question << "\n";
    std::cout << "Options: (strongly agree, agree, neutral, disagree, strongly disagree): ";
    std::getline(std::cin, answer);

    
    for (char& c : answer) {
        c = std::tolower(c);
    }

   
    if (answer == "strongly agree") {
        score = 2;
    } else if (answer == "agree") {
        score = 1;
    } else if (answer == "neutral") {
        score = 0;
    } else if (answer == "disagree") {
        score = -1;
    } else if (answer == "strongly disagree") {
        score = -2;
    } else {
        std::cout << "Invalid response. Please answer with one of the given options.\n";
        return askQuestion(question); 
    }

    return score;
}


std::string determinePersonalityType(int eScore, int sScore, int tScore, int jScore) {
    std::string personality = "";
    personality += (eScore >= 0) ? "E" : "I";
    personality += (sScore >= 0) ? "S" : "N"; 
    personality += (tScore >= 0) ? "T" : "F"; 
    personality += (jScore >= 0) ? "J" : "P"; 
    return personality;
}

int main() {
    int eScore = 0, sScore = 0, tScore = 0, jScore = 0;


    eScore += askQuestion("You enjoy socializing with large groups of people.");
    eScore += askQuestion("You often start conversations with strangers.");

   
    sScore += askQuestion("You prefer concrete facts over abstract theories.");
    sScore += askQuestion("You are more focused on the present than future possibilities.");

 
    tScore += askQuestion("You prioritize logic over emotions when making decisions.");
    tScore += askQuestion("You believe justice is more important than mercy.");

   
    jScore += askQuestion("You prefer to have a detailed plan rather than being spontaneous.");
    jScore += askQuestion("You like to finish tasks well ahead of a deadline.");

   
    std::string personalityType = determinePersonalityType(eScore, sScore, tScore, jScore);

  
    std::cout << "\nYour personality type is: " << personalityType << "\n";

    return 0;
}
