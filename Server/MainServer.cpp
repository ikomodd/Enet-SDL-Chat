#include <iostream>
#include <enet/enet.h>

#include "ServerConnection.hpp"
#include "User.hpp";

server_connection Connection;

int main() {

	if (enet_initialize() != 0) return EXIT_FAILURE;
	atexit(enet_deinitialize);

	Connection.Init();

	while (true) {

		while (enet_host_service(Connection.Server, &Connection.Event, 1000) > 0) {

			switch (Connection.Event.type) {

			case ENET_EVENT_TYPE_CONNECT: {

				std::cout << "Cliente Connectado\n";

				std::string IP = Connection.GetIP();

				user* User = new user(IP, Connection.Event.peer);

				ConnectedUsers[IP] = User;

			}
			break;
			case ENET_EVENT_TYPE_RECEIVE: {

				nlohmann::json Data = Connection.GetData();

				std::cout << "Mensagem recebida do cliente pelo canal " << Data["Channel"] << ": " << Data["Text"] << "\n";

			}
			break;
			case ENET_EVENT_TYPE_DISCONNECT: {

				std::cout << "Cliente Desconectado\n";

				std::string IP = Connection.GetIP();

				auto it = ConnectedUsers.find(IP);

				if (it != ConnectedUsers.end()) {

					delete ConnectedUsers[IP];
					ConnectedUsers.erase(it);
				}
			}
			break;
			}
		}
	}

	return 1;
}