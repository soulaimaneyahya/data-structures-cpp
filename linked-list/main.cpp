#include <iostream>

using namespace std;

struct UserNode {
    char name[50];
    char username[100];
    char email[255];
    UserNode* next;
};

void displayNodes(UserNode* head) {
    UserNode* current = head;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "Username: " << current->username << endl;
        cout << "Email: " << current->email << "\n" << endl;
        current = current->next;
    }
}

int main() {
    cout << "Friends List" << endl;

    // Creating user nodes dynamically
    UserNode* user1 = new UserNode{
        "Alice Johnson",
        "alicej",
        "alice@xmail.com",
        nullptr
    };

    UserNode* user2 = new UserNode{
        "Bob Smith",
        "bobsmith",
        "bob@xmail.com",
        nullptr
    };

    UserNode* user3 = new UserNode{
        "Charlie Brown",
        "charlieb",
        "charlie@xmail.com",
        nullptr
    };

    // Assigning the next pointer to link the users
    user1->next = user2;
    user2->next = user3;

    // Displaying the user list by passing first pointer
    displayNodes(user1);

    // Freeing up memory
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
