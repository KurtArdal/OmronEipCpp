#pragma once
#ifndef EIP_H
#define EIP_H

// C++ includes
#include <string>
#include <WinSock2.h>

// Local includes
#include "Types.h"
#include "UCCM.h"

namespace OmronEipCpp {
	class EIP {
	public:
		bool openSocket(std::string ip);
		bool connected();

		void registerSession();
		void unregisterSession();
		void close();

		UCCM_Message readTagUCCM(std::string fullTagName);
		UCCM_Message writeTagUCCM(std::string fullTagName, UCCM_Message data);

		byte lowByte(int myInt);
		byte highByte(int myInt);

		bool isArrayMember(std::string tagName);
		std::string getTagnameFromMember(std::string &tagName);

		std::vector<std::string> getStructureMembers(std::string fullTagName);
		int getIndexFromArray(std::string tagName);

		std::vector<byte> buildMessageSection(bool rw, std::string fullTagName, UCCM_Message message);
		std::vector<std::string> convertFromBytes(UCCM_Message repsonse);

		bool isClosed();

	private:
		SOCKET EipSocket;

		byte cmd[1000];
		byte res[1000];
		byte sessionHandle[4];
	};
}
#endif // EIP_H