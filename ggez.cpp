// GGEZ 1.0 minimxl 3-30-18
// Use: Quickly building and executing apps.
// Note: Made in a hacky way.

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

void checkHelp() {
  cout << "GGEZ is a simple command line tool meant" << endl;
  cout << "for allowing quick and easy building and" << endl;
  cout << "execution of applications for those new" << endl;
  cout << "to C++ programming." << endl;
  cout << endl;
  cout << "Usage: ggez <nameOfFileWithoutExtension>" << endl;
}


int checkFile(int argc, char* argv[]) {
  // Add .cpp to the arg to reduce arg typing time.
  string fname = string(argv[1]) + ".cpp";
  // Assure file exists.
  ifstream file(fname);
  if (!file) {
  // If it doesn't exist, exit.
    cout << "That file doesn't exist. :(" << endl;
    exit(EXIT_FAILURE);
  }
}

int buildFile(int argc, char* argv[]) {
  // Build file and store output in variable.
  int buildStatus = system((string("g++ ") + argv[1] + (".cpp -o ") + argv[1] + (".o")).c_str());

  if (!buildStatus) {
    // If no output was recieved, all is good.
    cout << "GGEZ built new file." << endl;
  } else {
      // Otherwise, an error occured, exit.
      cout << "There was an issue. :(" << endl;
      exit(EXIT_FAILURE);
    }
}

int executeFile(int argc, char* argv[]) {
    cout << "GGEZ is executing new file: " << endl;
  // Sleep for added executing suspense, haha.
  sleep(2);
    cout << endl;
  system((string("./") + argv[1] + (".o")).c_str());
    cout << endl;
    cout << "GGEZ executed new file." << endl;
}

int main(int argc, char* argv[]) {
  if (!argv[1]){
    // If the user inputs no arg.
    cout << "For help use: ggez -h." << endl;
} else if (string(argv[1]) == "-h") {
    // If the user asks for help.
    checkHelp();
} else {
    // If the user uses the app usage designated.
    checkFile(argc, argv);
    buildFile(argc, argv);
    executeFile(argc, argv);
  }
  return 0;
}
