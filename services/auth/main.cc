#include <drogon/drogon.h>
#include <cstdlib>
#include <iostream>

int main() {
    const char *dbHost = std::getenv("DB_HOST");
    const char *dbPort = std::getenv("DB_PORT");
    const char *dbName = std::getenv("DB_NAME");
    const char *dbUser = std::getenv("DB_USER");
    const char *dbPassword = std::getenv("DB_PASSWORD");

    const char *serverPort = std::getenv("SERVER_PORT");
    const char *threads = std::getenv("THREADS");

    if (!dbHost || !dbPort || !dbName ||
        !dbUser || !dbPassword ||
        !serverPort || !threads) {

        std::cerr << "Missing environment variables\n";
        return 1;
    }

    drogon::app()
        .addListener("0.0.0.0", std::stoi(serverPort))
        .setThreadNum(std::stoi(threads))
        .createDbClient(
            "postgresql",
            dbHost,
            std::stoi(dbPort),
            dbName,
            dbUser,
            dbPassword,
            10,
            "default"
        );

    drogon::app().registerBeginningAdvice([]() {
        std::cout << "Auth Service Started Successfully\n";

        auto client = drogon::app().getDbClient("default");

        client->execSqlAsync(
            "SELECT 1",
            [](const drogon::orm::Result &result) {
                std::cout << "Database Connected Successfully: "  << result[0][0].as<int>() << std::endl;
            },
            [](const drogon::orm::DrogonDbException &e) {
                std::cerr << "Database Connection Failed: " << e.base().what() << std::endl;
            }
        );
    });

    std::cout << "Auth Service Running on Port " << serverPort << std::endl;

    drogon::app().run();

    return 0;
}