﻿#include <windows.h>
#include <iostream>
#include "hde32.h"
#include "hde64.h"

enum Arch
{
	kX86,
	kX64
};

__int64 __fastcall dercypt_buffer(__int64 a1, __int64 a2) {
	unsigned int v4; // er8
	unsigned __int64 i; // rdx
	__int64 result; // rax

	memset((void*)a2, 0, 0x44ui64);
	v4 = 0xFCE32921;
	for (i = 0i64; i < 0x44; i += 4i64) {
		v4 = ~(((v4 ^ (v4 << 0xD)) >> 0x11) ^ v4 ^ (v4 << 0xD) ^ (0x20 * (((v4 ^ (v4 << 0xD)) >> 0x11) ^ v4 ^ (v4 <<
			0xD))));
		result = a2;
		*(DWORD*)(a2 + i) = *(DWORD*)(a1 + i) ^ v4;
	}
	return result;
}


unsigned char inst_filter[512] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


static UINT32 s_CRC32Table[16][256];

VOID BuildCRC32Table(VOID) {
	UINT32 i, j;
	UINT32 crc;

	for (i = 0; i < 256; i++) {
		crc = i;
		for (j = 0; j < 8; j++) {
			if (crc & 1) {
				crc = (crc >> 1) ^ 0xEDB88320;
			}
			else {
				crc >>= 1;
			}
		}
		s_CRC32Table[0][i] = crc;
	}

	for (i = 0; i < 256; i++) {
		s_CRC32Table[1][i] = (s_CRC32Table[0][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[0][i] & 0xFF];
		s_CRC32Table[2][i] = (s_CRC32Table[1][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[1][i] & 0xFF];
		s_CRC32Table[3][i] = (s_CRC32Table[2][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[2][i] & 0xFF];
		s_CRC32Table[4][i] = (s_CRC32Table[3][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[3][i] & 0xFF];
		s_CRC32Table[5][i] = (s_CRC32Table[4][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[4][i] & 0xFF];
		s_CRC32Table[6][i] = (s_CRC32Table[5][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[5][i] & 0xFF];
		s_CRC32Table[7][i] = (s_CRC32Table[6][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[6][i] & 0xFF];
		s_CRC32Table[8][i] = (s_CRC32Table[7][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[7][i] & 0xFF];
		s_CRC32Table[9][i] = (s_CRC32Table[8][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[8][i] & 0xFF];
		s_CRC32Table[10][i] = (s_CRC32Table[9][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[9][i] & 0xFF];
		s_CRC32Table[11][i] = (s_CRC32Table[10][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[10][i] & 0xFF];
		s_CRC32Table[12][i] = (s_CRC32Table[11][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[11][i] & 0xFF];
		s_CRC32Table[13][i] = (s_CRC32Table[12][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[12][i] & 0xFF];
		s_CRC32Table[14][i] = (s_CRC32Table[13][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[13][i] & 0xFF];
		s_CRC32Table[15][i] = (s_CRC32Table[14][i] >> 8) ^ s_CRC32Table[0][s_CRC32Table[14][i] & 0xFF];
	}
}


UINT32 WINAPI CRC32(
	IN UINT32 InitValue,
	IN PVOID Buffer,
	IN UINT32 Size
) {
	UINT32 Result = InitValue ^ 0xFFFFFFFF;
	auto Uint32Ptr = static_cast<PUINT32>(Buffer);

	while (Size >= 16) {
		UINT32 C1 = Uint32Ptr[0] ^ Result;
		UINT32 C2 = Uint32Ptr[1];
		UINT32 C3 = Uint32Ptr[2];
		UINT32 C4 = Uint32Ptr[3];

		Result = s_CRC32Table[0][(C4 >> 24) & 0xFF] ^
			s_CRC32Table[1][(C4 >> 16) & 0xFF] ^
			s_CRC32Table[2][(C4 >> 8) & 0xFF] ^
			s_CRC32Table[3][C4 & 0xFF] ^
			s_CRC32Table[4][(C3 >> 24) & 0xFF] ^
			s_CRC32Table[5][(C3 >> 16) & 0xFF] ^
			s_CRC32Table[6][(C3 >> 8) & 0xFF] ^
			s_CRC32Table[7][C3 & 0xFF] ^
			s_CRC32Table[8][(C2 >> 24) & 0xFF] ^
			s_CRC32Table[9][(C2 >> 16) & 0xFF] ^
			s_CRC32Table[10][(C2 >> 8) & 0xFF] ^
			s_CRC32Table[11][C2 & 0xFF] ^
			s_CRC32Table[12][(C1 >> 24) & 0xFF] ^
			s_CRC32Table[13][(C1 >> 16) & 0xFF] ^
			s_CRC32Table[14][(C1 >> 8) & 0xFF] ^
			s_CRC32Table[15][C1 & 0xFF];

		Uint32Ptr += 4;
		Size -= 16;
	}

	auto CharPtr = (PUCHAR)Uint32Ptr;

	while (Size--) {
		Result = (Result >> 8) ^ s_CRC32Table[0][(Result & 0x000000FF) ^ *CharPtr++];
	}

	return (Result ^ 0xFFFFFFFF);
}

void scan_memory(void* buffer, int len) {
	unsigned crc = 0;
	int func_len = 0;
	for (int i = 0; i < len;) {
		const auto rip = static_cast<unsigned char*>(buffer) + i;

		if (func_len) {
			hde64s hs{0};
			hde64_disasm(rip, &hs);
			if ((hs.flags & F_ERROR) == 0 && hs.len) {
				func_len += hs.len;
				i += hs.len;
				int crc_len = 0;
				if (*rip == 0xF || (crc_len = 1, *rip == 0x48))
					crc_len = 2;
				crc = CRC32(crc, rip, crc_len);
				if (!inst_filter[*rip]) continue;
				printf("add crc:%08x,size:%x to list\n", crc, func_len);
			}
			func_len = 0;
		}

		int inst_len = 0x10;
		if ((*(WORD*)rip == 0x8348 && *(rip + 2) == 0xEC) || *(DWORD*)rip == 0xE5894855) {
			//printf("[x] find start %x\n", *(DWORD*)rip);
			func_len = 4;
			crc = CRC32(0, rip, func_len);
			inst_len = func_len;
		}

		i += inst_len;
	}
}

int main() {


	BuildCRC32Table();


	HANDLE hFile = CreateFileA("ntdll.dll", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, NULL, nullptr);
	if (hFile == INVALID_HANDLE_VALUE) {
		return 0;
	}

	auto data_size = GetFileSize(hFile, nullptr);
	auto m_pBuf = static_cast<BYTE*>(VirtualAlloc(nullptr, data_size, MEM_COMMIT, PAGE_READWRITE));
	DWORD dwRead = 0;
	ReadFile(hFile, m_pBuf, data_size, &dwRead, nullptr);
	CloseHandle(hFile);

	auto m_pImageDosHeader = (PIMAGE_DOS_HEADER)(m_pBuf);
	auto dwE_lfanew = m_pImageDosHeader->e_lfanew;
	auto dwNtHeader = (DWORD64)(m_pBuf) + dwE_lfanew;
	auto m_pImageNtHeader = static_cast<PIMAGE_NT_HEADERS>((LPVOID)(dwNtHeader));
	auto m_pImageSectionHeader = IMAGE_FIRST_SECTION(m_pImageNtHeader);

	std::string sc;

	sc.append((char*)m_pBuf + m_pImageSectionHeader[0].PointerToRawData, m_pImageSectionHeader[0].SizeOfRawData);
	scan_memory((void*)sc.c_str(), sc.size());

	Sleep(-1);
	for (int i = 0; i < 0xff; i++) {
		if (inst_filter[i]) {
			printf("%02x \n", i);
		}
	}
	Sleep(-1);


	int buffer[18];
	buffer[0] = 0x5E9D0226;
	buffer[1] = 0x72FCD4E8;
	buffer[2] = 0xB7D5BE8F;
	buffer[3] = 0xFA15D9C9;
	buffer[4] = 0xDD55444B;
	buffer[5] = 0x95C36392;
	buffer[6] = 0x3C36449C;
	buffer[7] = 0x95199981;
	buffer[8] = 0x987C02E6;
	buffer[9] = 0xE82E4ECA;
	buffer[0xA] = 0xE55C2804;
	buffer[0xB] = 0xD231CB79;
	buffer[0xC] = 0xDB11ED81;
	buffer[0xD] = 0xC1399667;
	buffer[0xE] = 0x183A3293;
	buffer[0xF] = 0x680F7394;
	buffer[0x10] = 0xBDFCFB16;

	char decrypt[0x44]{0};
	dercypt_buffer((__int64)buffer, (__int64)&decrypt);
	for (int i = 0; i < 0x44; i++) {
		printf("%02x ", decrypt[i]);
	}
}
