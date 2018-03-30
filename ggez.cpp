// GGEZ 1.1 minimxl 3-30-18
// Use: Quickly building and executing apps.
// Note: Made in a hacky way.

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

void checkHelp() {
  std::cout << "GGEZ is a simple command line tool meant" << std::endl;
  std::cout << "for allowing quick and easy building and" << std::endl;
  std::cout << "execution of applications for those new" << std::endl;
  std::cout << "to C++ programming." << std::endl;
  std::cout << std::endl;
  std::cout << "Usage: ggez <nameOfFileWithoutExtension>" << std::endl;
}


int checkFile(char* argv[]) {
  // Add .cpp to the arg to reduce arg typing time.
  std::string fname = std::string(argv[1]) + ".cpp";
  // Assure file exists.
  std::ifstream file(fname);
  if (!file) {
  // If it doesn't exist, exit.
    std::cout << "That file doesn't exist. :(" << std::endl;
    exit(EXIT_FAILURE);
  }
  return 0;
}

int buildFile(char* argv[]) {
  int buildStatus;
  std::string warnDecision;

  std::cout << "Use warnings? (Y/N) ";
  std::cin >> warnDecision;

  if (warnDecision == "Y") {
    // Build file with warnings and store output in variable.
    buildStatus = system((std::string("g++ -Wall -Wextra -Wpedantic ") + argv[1] + (".cpp -o ") + argv[1] + (".o")).c_str());
  } else if (warnDecision == "N") {
      // Build file and store output in variable.
      buildStatus = system((std::string("g++ ") + argv[1] + (".cpp -o ") + argv[1] + (".o")).c_str());
    } else {
          std::cout << "Invalid input. :(" << std::endl;
        exit(EXIT_FAILURE);
      }
  if (!buildStatus) {
    // If no output was recieved, all is good.
      std::cout << "GGEZ built new file." << std::endl;
  } else {
      // Otherwise, an error occured, exit.
        std::cout << "There was an issue. :(" << std::endl;
      exit(EXIT_FAILURE);
    }
  return 0;
}

int executeFile(char* argv[]) {
    std::cout << "GGEZ is executing new file: " << std::endl;
  // Sleep for added executing suspense, haha.
  std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << std::endl;
  system((std::string("./") + argv[1] + (".o")).c_str());
    std::cout << std::endl;
    std::cout << "GGEZ executed new file." << std::endl;
  return 0;
}

int main(int argc, char* argv[]) {
  if (!argv[1]){
    // If the user inputs no arg.
    std::cout << "For help use: ggez -h." << std::endl;
} else if (std::string(argv[1]) == "-h") {
    // If the user asks for help.
    checkHelp();
} else {
    // If the user uses the app usage designated.
    checkFile(argv);
    buildFile(argv);
    executeFile(argv);
  }
  return 0;
}
