#include <iostream>
#include <unistd.h>
using namespace std;

void create_copies(int level) {
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // child process
            for (int j = 0; j < level; j++) {
                cout << "  ";
            }
            cout << "Child PID: " << getpid() << endl;
            create_copies(level + 1);
            exit(0);
        } else if (pid > 0) {
            // parent process
            wait(NULL);
        } else {
            // fork failed
            cout << "Fork failed" << endl;
            exit(1);
        }
    }
}

int main() {
    cout << "Parent PID: " << getpid() << endl;
    create_copies(1);
    return 0;
}
