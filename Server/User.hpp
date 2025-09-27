#pragma once

#include <iostream>
#include <enet/enet.h>

#include <unordered_map>

enum class connection_status {

	LOGGED,
	UNLOGGED,

};

class user {
public:

	std::string IP = "";

	ENetPeer* Peer = {};

	//

	connection_status ConnectionStatus = connection_status::UNLOGGED;

	//

	user(std::string ip, ENetPeer* peer): IP(ip), Peer(peer) {

		std::cout << "Cliente: " << IP << " registrado com sucesso\n";

	};

	~user() {

		std::cout << "Cliente: " << IP << " desvinculado com sucesso\n";

	}

};

std::unordered_map<std::string, user*> ConnectedUsers = {};