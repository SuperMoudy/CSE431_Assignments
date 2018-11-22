#include "verifier.h"

/*
void handle_input_to_verifier(string received_message, unsigned int& received_message_val)
{
	received_message_val = bin_to_dec(received_message);
}
*/

void verify_message(unsigned int received_message_val, unsigned int polynomial_val)
{
	unsigned int remainder;
	//handle_input_to_verifier(received_message, received_message_val);

	remainder = crc(received_message_val, polynomial_val);

	if (remainder)
	{
		cout << "message is not correct" << endl;
	}
	else
	{
		cout << "message is correct" << endl;
	}
}
