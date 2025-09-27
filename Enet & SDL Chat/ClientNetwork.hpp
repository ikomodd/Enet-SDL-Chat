#pragma once

#include <iostream>
#include <enet/enet.h>

#include "Json.hpp"
#include "ClientConnection.hpp"

void Network() {

	bool Running = true;

	while (Running) {

		while (enet_host_service(Connection.Client, &Connection.Event, 0) > 0) {

			switch (Connection.Event.type) {

			case ENET_EVENT_TYPE_CONNECT: {

				std::cout << "Cliente conectado\n";

			}
										break;
			case ENET_EVENT_TYPE_RECEIVE: {

				nlohmann::json Data = Connection.GetData();

				std::cout << "Mensagem recebida do servidor pelo canal " << Data["Channel"] << ": " << Data["Text"] << "\n";

			}
										break;
			case ENET_EVENT_TYPE_DISCONNECT: {

				std::cout << "Cliente desconectado\n";

				Running = false;

			}
										   break;
			}
		}
	}
}