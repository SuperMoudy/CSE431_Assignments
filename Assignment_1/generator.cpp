#include "generator.h"

void handle_input_to_generator(string& msg, string& poly, unsigned int& i_msg, unsigned int& i_poly)
{
	read_input_file(msg, poly);

	i_msg = bin_to_dec(msg);

	i_poly = bin_to_dec(poly);
}


string generate_message(string& msg, string& poly, unsigned int& i_msg, unsigned int& i_poly)
{
	string sent_message;
	unsigned int remainder;

	handle_input_to_generator(msg, poly, i_msg, i_poly);
	remainder = crc(i_msg, i_poly);

	if (remainder)
	{
		sent_message = msg + dec_to_bin(remainder);
	}

	cout << "Message Transmitted: " << sent_message << endl;
	cout << "Generator Key: " << poly << endl;

	return sent_message;
}

//ofstream out("result.txt");
//cout.rdbuf(out.rdbuf());