/*
** EPITECH PROJECT, 2024
** Zappy_gui
** File description:
** PluginLoader.hpp
*/

#include <unordered_map>
#include <vector>

#include "GUI/Abstraction/IRenderer.hpp"

namespace gui {

    class PluginLoader {

        public:

            using PluginCreator = std::unique_ptr<IPlugin> (*)();

            ~PluginLoader() = default;


            static PluginLoader &getInstance() {
                static PluginLoader instance;
                return instance;
            }

            template <typename T>
            std::unique_ptr<T> getPlugin(const std::string &pluginName);

            void closePlugins();

            class PluginLoaderException : public std::exception{

                public:

                    explicit PluginLoaderException(std::string msg) : m_msg(std::move(msg)) {};
                    [[nodiscard]] const char* what() const noexcept override { return m_msg.data(); };

                private:

                    std::string m_msg;

            }; // class PluginLoaderException

        private:

            PluginLoader() { loadPlugins(); };

            void loadPlugins();

            std::unordered_map<std::string, PluginCreator> m_plugins{};
            std::vector<void*> m_handles{nullptr};

    }; // class PluginLoader

} // namespace gui
