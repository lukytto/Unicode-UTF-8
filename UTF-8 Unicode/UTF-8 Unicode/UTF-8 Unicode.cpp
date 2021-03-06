// UTF-8 Unicode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <map>


void Map();
void File_in_out();
void Utf8_funkcija(unsigned long long int code, unsigned char chars[5]);
unsigned long long converter(unsigned long long int);
void Pirmos_dalies_funkcija();


wchar_t map[256];

void Pirmos_dalies_funkcija() {
	unsigned long long int a;
	std::cout << "Iveskite simbolio int skaciu" << std::endl;
	std::cin >> a;
	std::cout << "Unicode:U+";
	std::cout << std::hex << a << std::endl;
	a = converter(a);
	std::cout << "Simbolio UTF-8 kodas: " << std::hex << a << std::endl;

}


void Map() {
	map[128] = L'Ç';
	map[129] = L'ü';
	map[130] = L'é';
	map[131] = L'â';
	map[132] = L'ä';
	map[133] = L'à';
	map[134] = L'å';
	map[135] = L'ç';
	map[136] = L'ê';
	map[137] = L'ë';
	map[138] = L'è';
	map[139] = L'ï';
	map[140] = L'î';
	map[141] = L'ì';
	map[142] = L'Ä';
	map[143] = L'Å';
	map[144] = L'É';
	map[145] = L'æ';
	map[146] = L'Æ';
	map[147] = L'ô';
	map[148] = L'ö';
	map[149] = L'ò';
	map[150] = L'û';
	map[151] = L'ù';
	map[152] = L'ÿ';
	map[153] = L'Ö';
	map[154] = L'Ü';
	map[155] = L'¢';
	map[156] = L'£';
	map[157] = L'¥';
	map[158] = L'₧';
	map[159] = L'ƒ';
	map[160] = L'á';
	map[161] = L'í';
	map[162] = L'ó';
	map[163] = L'ú';
	map[164] = L'ñ';
	map[165] = L'Ñ';
	map[166] = L'ª';
	map[167] = L'º';
	map[168] = L'¿';
	map[169] = L'⌐';
	map[170] = L'¬';
	map[171] = L'½';
	map[172] = L'¼';
	map[173] = L'¡';
	map[174] = L'«';
	map[175] = L'»';
	map[176] = L'░';
	map[177] = L'▒';
	map[178] = L'▓';
	map[179] = L'│';
	map[180] = L'┤';
	map[181] = L'╡';
	map[182] = L'╢';
	map[183] = L'╖';
	map[184] = L'╕';
	map[185] = L'╣';
	map[186] = L'║';
	map[187] = L'╗';
	map[188] = L'╝';
	map[189] = L'╜';
	map[190] = L'╛';
	map[191] = L'┐';
	map[192] = L'└';
	map[193] = L'┴';
	map[194] = L'┬';
	map[195] = L'├';
	map[196] = L'─';
	map[197] = L'┼';
	map[198] = L'╞';
	map[199] = L'╟';
	map[200] = L'╚';
	map[201] = L'╔';
	map[202] = L'╩';
	map[203] = L'╦';
	map[204] = L'╠';
	map[205] = L'═';
	map[206] = L'╬';
	map[207] = L'╧';
	map[208] = L'╨';
	map[209] = L'╤';
	map[210] = L'╥';
	map[211] = L'╙';
	map[212] = L'╘';
	map[213] = L'╒';
	map[214] = L'╓';
	map[215] = L'╫';
	map[216] = L'╪';
	map[217] = L'┘';
	map[218] = L'┌';
	map[219] = L'█';
	map[220] = L'▄';
	map[221] = L'▌';
	map[222] = L'▐';
	map[223] = L'▀';
	map[224] = L'α';
	map[225] = L'ß';
	map[226] = L'Γ';
	map[227] = L'π';
	map[228] = L'Σ';
	map[229] = L'σ';
	map[230] = L'µ';
	map[231] = L'τ';
	map[232] = L'Φ';
	map[233] = L'Θ';
	map[234] = L'Ω';
	map[235] = L'δ';
	map[236] = L'∞';
	map[237] = L'φ';
	map[238] = L'ε';
	map[239] = L'∩';
	map[240] = L'≡';
	map[241] = L'±';
	map[242] = L'≥';
	map[243] = L'≤';
	map[244] = L'⌠';
	map[245] = L'⌡';
	map[246] = L'÷';
	map[247] = L'≈';
	map[248] = L'°';
	map[249] = L'∙';
	map[250] = L'·';
	map[251] = L'√';
	map[252] = L'ⁿ';
	map[253] = L'²';
	map[254] = L'■';
	;
}



unsigned long long converter(unsigned long long int code) {
	unsigned long long result;
	char chars[5];
	std::string bytes[5], wbytes;
	if (code <= 0x7F)
	{
		chars[0] = (code & 0x7F);
		result = code;
	}
	else if (code <= 0x7FF)                   //testas su  int=291, hex=123
	{
		chars[1] = 0x80 | (code & 0x3F);   //antras baitas A3 // 10000000 | hnumb & 00111111 //( 80  uzdeda 10 priekyje baito, 3F issaugo 6 vietom gale vienentus)
		code = (code >> 6);

		chars[0] = 0xC0 | (code & 0x1F);   // pirmas baitas C4 //11000000 | hnumb & 00011111 // (  C0 uzdeda 11 priekyje baito, 1F issaugo 5 vietas vienetam)

		for (int i = 0; i < 2; i++) {
			bytes[i] = std::bitset<8>(chars[i]).to_string();
		}
		wbytes = bytes[0] + bytes[1];
		result = stoull(wbytes, 0, 2);             // rez= C4A3
	}
	else if (code <= 0xFFFF)                                     // testas su  int=2336, hex=920
	{
		chars[2] = 0x80 | (code & 0x3F); // trecias baitas A0 ( 80  uzdeda 10 priekyje baito, 3F issaugo 6 vietom gale vienentus)
		code = (code >> 6);

		chars[1] = 0x80 | (code & 0x3F);// antras baitas A4       --,,--
		code = (code >> 6);

		chars[0] = 0xE0 | (code & 0xF);	  //E0 pirmas baitas  E0
		for (int i = 0; i < 3; i++)
		{
			bytes[i] = std::bitset<8>(chars[i]).to_string();
		}
		wbytes = bytes[0] + bytes[1] + bytes[2];
		result = stoull(wbytes, 0, 2);
	}
	else if (code <= 0x10FFFF)
	{
		chars[3] = 0x80 | (code & 0x3F);
		code = (code >> 6);

		chars[2] = 0x80 | (code & 0x3F);
		code = (code >> 6);

		chars[1] = 0x80 | (code & 0x3F);
		code = (code >> 6);

		chars[0] = 0xF0 | (code & 0x7);
		for (int i = 0; i < 4; i++) {
			bytes[i] = std::bitset<8>(chars[i]).to_string();
		}
		wbytes = bytes[0] + bytes[1] + bytes[2] + bytes[3];
		result = stoull(wbytes, 0, 2);
	}
	
	return result;
}

void Utf8_funkcija(unsigned long long int code, unsigned char chars[5]) {
	if (code <= 0x7F) {
		chars[0] = (code & 0x7F); chars[1] = '\0';
	}
	else if (code <= 0x7FF) {

		chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[0] = 0xC0 | (code & 0x1F); chars[2] = '\0';
	}
	else if (code <= 0xFFFF) {

		chars[2] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[0] = 0xE0 | (code & 0xF); chars[3] = '\0';
	}
	else if (code <= 0x10FFFF) {

		chars[3] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[2] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[1] = 0x80 | (code & 0x3F); code = (code >> 6);
		chars[0] = 0xF0 | (code & 0x7); chars[4] = '\0';
	}

}


void File_in_out() {
	std::ifstream filein;
	filein.open("386intel.txt");
	if (filein.fail()) {
		std::cout <<"klaida atidarant faila" << std::endl;
	}
	
	std::ofstream fileout;
	fileout.open("rezultatai.txt", std::ios_base::binary);

	Map();
	char c;
	std::string bytes;
	unsigned char chars[5];
	unsigned long long n;

	while (!filein.eof()) {

		filein.get(c);
		bytes = std::bitset<8>(c).to_string();
		n = stoull(bytes, 0, 2);
		if (n <= 127) {
			Utf8_funkcija(n, chars);
			fileout << chars;
		}
		else {
			bytes = std::bitset<16>(map[n]).to_string();
			n = stoull(bytes, 0, 2);
			Utf8_funkcija(n, chars);
			fileout << chars;
		}
	}
	filein.close();
	fileout.close();
}


int main() {
	int a;

	
	std::cout << "1. Konvertuoti 386intel faila is senos 1 baito koduotes i unikodo" << std::endl
	          << "2. Konvertuoti int reiksme i Unicode uzkuoduota UTF-8" << std::endl;
	std::cin >> a;

	if (a == 1) {
		File_in_out();
		std::cout << "Konvertavimas ivykdytas!" << std::endl
			<< "Issaugota rezultatai.txt faile" << std::endl;
	}
	else if (a == 2) {
		Pirmos_dalies_funkcija();

	}

	return 0;
}

















//unsigned short Gauti_simb_koda(wchar_t);

////fileout.write(reinterpret_cast<char const*>(temp), sizeof(temp));

//unsigned short Gauti_simb_koda(wchar_t a) {
//
//	unsigned short temp;
//
//	temp = a;
//	return temp;
//}
//
//int main() {
//	short a;
//
//	File_in_out();
//	std::cout << "1-parodyti ivesto simbolio UNICODE ir UTF8" << std::endl
//		<< "2-Int reiksme parodyti UNICODU ir sukonvertuoti i UTF8" << std::endl;
//	std::cin >> a;
//
//	if (a == 1) {
//		wchar_t a = L'─';
//
//		unsigned short int b = Gauti_simb_koda(a);
//		std::cout << "Ivesto simbolio UNICOD'AS: ";
//		std::cout << std::uppercase << "U+" << b << std::endl;
//		std::cout << "Ivesto simbolio UTF8 kodas desimtaineje sistemoje yra: " << converter(b) << std::endl;
//		std::cout << "Ivesto simbolio UTF8 kodas siesioliktaineje sistemoje yra: ";
//		std::cout << std::uppercase << std::hex << converter(b) << std::endl;
//	}
//	else if (a == 2) {
//		Pirmos_dalies_funkcija();
//
//	}
//
//	return 0;
//}










