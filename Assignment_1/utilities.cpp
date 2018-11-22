#include "utilities.h"


void read_input_file(string& msg, string& polynomial)
{
	ifstream in("input.txt");
	in >> msg;
	in >> polynomial;
}

// function converts from string binary or int to handle input(done)
// input: string
// output: unsigned int

unsigned int bin_to_dec(string bin_val)
{
	unsigned int dec_val = 0;
	unsigned int bin_val_len = bin_val.length();

	for (unsigned int i = 0; i < bin_val_len; i++)
	{
		dec_val <<= 1;
		if (bin_val[i] == '1')
		{
			dec_val |= 1;
		}
	}
	return dec_val;
}



// function converts from binary or int to string to output(done)
// input: unsigned int
// output: string

string dec_to_bin(unsigned int dec_val)
{
	string bin_val;
	string temp_val;
	if (dec_val == 0)
	{
		return "0";
	}

	while (dec_val > 0)
	{
		if (dec_val % 2)
		{
			temp_val += '1';
		}
		else
		{
			temp_val += '0';
		}
		dec_val /= 2;
	}

	int temp_val_len = temp_val.length();
	int last_index = temp_val_len - 1;
	for (int i = last_index; i > -1; i--)
	{
		bin_val += temp_val[i];
	}
	return bin_val;

}



unsigned int measure_message_len(unsigned int msg)
{
	if (msg == 0)
	{
		return 1;
	}
	else
	{
		unsigned int msb_index = sizeof(msg) * 8 - 1;
		while ((msg & (1 << msb_index)) == 0)
		{
			msb_index--;
		}
		unsigned int msg_len = msb_index + 1;
		return msg_len;
	}
}

// function to do CRC
// input: unsigned int message, unsigned int polynomial
// output: unsigned int remainder
unsigned int crc(unsigned int message, unsigned int polynomial)
{
	unsigned int polynomial_len = measure_message_len(polynomial);
	message <<= (polynomial_len - 1);
	unsigned int temp_polynomial = polynomial;
	unsigned int temp_msg = message;

	unsigned int msg_len = measure_message_len(message);
	while ((polynomial_len < msg_len) && (message != 0))
	{
		temp_polynomial <<= (msg_len - polynomial_len);
		message ^= temp_polynomial;
		temp_polynomial = polynomial;
		msg_len = measure_message_len(message);
	}
	return message;
}


void alter(unsigned int& message, unsigned int index)
{
	unsigned int message_len = measure_message_len(message);
	message ^= (1 << (message_len - index));
}

