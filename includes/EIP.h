#pragma once
#ifndef EIP_H
#define EIP_H

// C++ includes
#include <string>


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

		bool isArrayMember(const std::string& tagName);
		std::string getTagnameFromMember(const std::string &tagName);

		std::vector<std::string> getStructureMembers(const std::string& fullTagName);
		int getIndexFromArray(const std::string& tagName);

		std::vector<byte> buildMessageSection(bool rw, std::string fullTagName, UCCM_Message message);
		std::vector<std::string> convertFromBytes(UCCM_Message& response);

		bool isClosed();

	private:
		

		byte cmd[1000];
		byte res[1000];
		byte sessionHandle[4];
	};
}
#endif // EIP_H