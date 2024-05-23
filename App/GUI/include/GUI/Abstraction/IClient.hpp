/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** IClient
*/

#pragma once

#include <string>
#include <cstdint>

namespace gui {

    class IClient {

        public:

            virtual ~IClient() = default;

            virtual void connect(uint16_t port, const std::string& machineName) = 0;
            virtual void disconnect() = 0;
            virtual bool sendCommand(const std::string& cmd) = 0;
            virtual bool getResponse(const std::string& cmd) = 0;
            virtual std::string getResponse() = 0;
            virtual bool isConnected() = 0;

    }; // class IClient

} // namespace gui
