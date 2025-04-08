#include "Client.h"

int Client::count = 0;

Client::Client(int c, string n) : code(c), name(n) {
    count++;
}

int Client::GetCode() { return code; }
string Client::GetName() { return name; }
int Client::GetCount() { return count; }
