#include <drogon/drogon.h>
#include <iostream>

int main()
{
    drogon::app().loadConfigFile("../config.yaml");

    drogon::app().addListener("0.0.0.0", 3000);

    drogon::app().registerBeginningAdvice([](){
        std::cout << "App initialized successfully\n";
        auto client = drogon::app().getDbClient("default");
        client->execSqlAsync("SELECT 1", [](const drogon::orm::Result &r) {
            std::cout << "DB Connected: " << r[0][0].as<int>() << std::endl;
        },
        [](const drogon::orm::DrogonDbException &e) {
            std::cerr << e.base().what() << std::endl;
        }); 
    });
    std::cout << "Starting server on port 3000...\n";
    drogon::app().run();

    return 0;
}