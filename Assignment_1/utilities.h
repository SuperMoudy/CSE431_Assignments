#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void read_input_file(string& msg, string& polynomial);

unsigned int bin_to_dec(string bin_val);

string dec_to_bin(unsigned int dec_val);

unsigned int measure_message_len(unsigned int msg);

unsigned int crc(unsigned int message, unsigned int polynomial);

void alter(unsigned int& message, unsigned int index);
