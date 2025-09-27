#pragma once

#include <iostream>
#include <enet/enet.h>

#include "json.hpp"
#include "user.hpp"

class server_connection {
public:

	ENetHost* Server;
	ENetAddress Address;

	ENetEvent Event;

	server_connection() {};

	void Init() {

		Address.host = ENET_HOST_ANY;
		Address.port = 1234;

		Server = enet_host_create(&Address, 32, 2, 0, 0);

		if (Server) std::cout << "Servidor iniciado com sucesso\n";
		else {

			std::cerr << "Erro ao iniciar o servidor\n";

		}
	};

	void FireClient(std::string IP, nlohmann::json Json, enet_uint8 Channel) {

		std::string StringData = Json.dump();

		ENetPacket* Data = enet_packet_create(StringData.c_str(), StringData.size(), 0);

		user* User = ConnectedUsers[IP];

		enet_peer_send(User->Peer, Channel, Data);

		std::cout << "Envianndo mensagem do servidor para o cliente\n";

	}

	nlohmann::json GetData() {
		try {

			std::string StringData(reinterpret_cast<char*>(Event.packet->data), Event.packet->dataLength);

			nlohmann::json JsonData = nlohmann::json::parse(StringData);

			JsonData["Channel"] = Event.channelID;

			return JsonData;

		}
		catch (nlohmann::json::parse_error& ParseError) {

			std::cerr << "Parse error: " << ParseError.what() << "\n";

		}
	}

	std::string GetIP() {

		char strIP[46];

		if (enet_address_get_host_ip(&Event.peer->address, strIP, sizeof(strIP)) == 0) {

			return std::string(strIP);

		}
	}
};

extern server_connection Connection;