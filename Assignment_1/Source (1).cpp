#include "utilities.h"
#include "generator.h"
#include "verifier.h"
using namespace std;


/*
Procedure:
1) Take input and convert it to numbers
2) Generate the message from sender side
	- Apply CRC algorithm
	- do the necessary concatenation
3) Verify the message on the receiver side
	- Apply CRC algorithm
	- if no reamainder then the message is sent correctly
	- otherwise, sending the message failed

4) Apply the altering function if necessary

*/


int main()
{
	string message, polynomial, received_message;
	unsigned int message_val, polynomial_val, received_message_val;
	unsigned int index;
	cout << "Welcome to Data Link Layer\n";
	cout << "We are using a default \"input.txt\" file\n\n";
	cout << "Available commands: \n\n";
	cout << "<command> [<argument>]\ngenerate\nverify\nalter index\nquit(or exit)\n\n";
	string command;
	do
	{
		cout << ">> ";
		cin >> command;
		if (command == "generate")
		{
			received_message = generate_message(message, polynomial, message_val, polynomial_val);
			received_message_val = bin_to_dec(received_message);
		}
		else if (command == "alter")
		{
			cin >> index;
			alter(received_message_val, index);
			cout << "message is altered" << endl;
		}
		else if (command == "verify")
		{
			verify_message(received_message_val, polynomial_val);
		}
		else if((command != "quit") && (command != "exit"))
		{
			cout << "invalid command" << endl;
		}
		cout << "\n";
		
	} while ((command != "quit") && (command != "exit"));


	return 0;
}
