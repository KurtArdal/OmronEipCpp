#pragma once
#ifndef PLCDATA_H
#define PLCDATA_H

// C++ includes
#include <string>
namespace OmronEipCpp {
	class PLCData {
	public:
		PLCData::PLCData(const std::string &name, const std::string &protocol, const std::string &ip, const std::string &port, const std::string &SNA, const std::string &DNA, const std::string &DA1);
		std::string getName();
		std::string getProtocol();
		std::string getIP();
		std::string getPort();
		std::string getSNA();
		std::string getDNA();
		std::string getDA1();

	private:
		std::string _name;
		std::string _protocol;
		std::string _ipaddress;
		std::string _port;
		std::string _SNA;
		std::string _DNA;
		std::string _DA1;
	};

}

#endif // PLCDATA_H