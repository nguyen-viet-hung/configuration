#include <filesystem>
#include <iostream>
#include <vector>
#include <tao/config.hpp>
#include <tao/config/internal/try_catch.hpp>

#include "Yaml.hpp"

int main(int argc, char** argv) {
    tao::config::internal::try_catch([=]() {
        const tao::config::value v = tao::config::from_file(std::filesystem::path("config.json"));
        //tao::json::jaxn::to_stream(std::cout, v, 3);
        std::cout << tao::config::access(v, tao::config::key("ip"));
        std::cout << std::endl;
        });

    Yaml::Node root;
    try {
        Yaml::Parse(root, "config.yml");

        // Print all scalars.
        for (auto it = root.Begin(); it != root.End(); it++) {
            if ((*it).first == std::string("camera_url"))
                std::cout << "key: " << (*it).first << " value: " << root["camera_url"].As<std::string>() << std::endl;
            if ((*it).first == std::string("server_url"))
                std::cout << "key: " << (*it).first << " value: " << root["server_url"].As<std::string>() << std::endl;
            if ((*it).first == std::string("username"))
                std::cout << "key: " << (*it).first << " value: " << root["username"].As<std::string>() << std::endl;
            if ((*it).first == std::string("password"))
                std::cout << "key: " << (*it).first << " value: " << root["password"].As<std::string>() << std::endl;
            if ((*it).first == std::string("camera_id"))
                std::cout << "key: " << (*it).first << " value: " << root["camera_id"].As<std::string>() << std::endl;
            if ((*it).first == std::string("timeout"))
                std::cout << "key: " << (*it).first << " value: " << root["timeout"].As<std::size_t>() << std::endl;
            if ((*it).first == std::string("hearbeat"))
                std::cout << "key: " << (*it).first << " value: " << root["hearbeat"].As<std::size_t>() << std::endl;
            if ((*it).first == std::string("submit_short"))
                std::cout << "key: " << (*it).first << " value: " << root["submit_short"].As<std::size_t>() << std::endl;
            if ((*it).first == std::string("submit_long"))
                std::cout << "key: " << (*it).first << " value: " << root["submit_long"].As<std::size_t>() << std::endl;
            if ((*it).first == std::string("threshold"))
                std::cout << "key: " << (*it).first << " value: " << root["threshold"].As<int>() << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cout << "Got exception. Detail: " << e.what() << std::endl;
    }
}