#pragma once

#include <iostream>
#include <enet/enet.h>

#include "Json.hpp"

class client_connection {
public:

	ENetHost* Client;
	ENetAddress Address;

	ENetPeer* Peer;

	ENetEvent Event;

	client_connection() {};

	void Init() {

		Client = enet_host_create(NULL, 1, 2, 0, 0);

		if (Client) std::cout << "Cliente iniciado com sucesso\n";
		else {

			std::cerr << "Erro ao iniciar o Cliente\n";

		}

		enet_address_set_host(&Address, "127.0.0.1");
		Address.port = 1234;

		Peer = enet_host_connect(Client, &Address, 2, 0);

		if (Peer)  std::cout << "Conectado com sucesso\n";
		else {

			std::cout << "Nao foi possivel conectar-se ao servidor\n";

		}
	};

	void FireServer(nlohmann::json Json, enet_uint8 Channel) {

		std::string StringData = Json.dump();

		ENetPacket* Data = enet_packet_create(StringData.c_str(), StringData.size(), 0);

		enet_peer_send(Peer, Channel, Data);

		std::cout << "Enviando mensagem do cliente para servidor\n";

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
};

extern client_connection Connection;