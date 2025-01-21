#include <iostream>

using namespace std;

struct UserNode {
    char name[50];
    char username[100];
    char email[255];
    UserNode* next;
};

int main() {
    cout << "Friends List" << endl;

    // Creating user nodes dynamically
    UserNode* user1 = new UserNode{"Alice Johnson", "alicej", "alice@xmail.com", nullptr};
    UserNode* user2 = new UserNode{"Bob Smith", "bobsmith", "bob@xmail.com", nullptr};
    UserNode* user3 = new UserNode{"Charlie Brown", "charlieb", "charlie@xmail.com", nullptr};

    // assign the next pointer to the next user
    user1->next = user2;
    user2->next = user3;

    // Traversing and displaying the user list
    UserNode* current = user1;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "Username: " << current->username << endl;
        cout << "Email: " << current->email << "\n" << endl;
        current = current->next;
    }

    // Freeing up memory
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
