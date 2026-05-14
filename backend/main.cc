#include <drogon/drogon.h>
#include <iostream>

int main() {
    std::cout << "Running Migrations...\n";

    int chmodResult = system("chmod +x ../scripts/migrate.sh");
    if (chmodResult != 0) {
        std::cerr << "Failed to set execute permission for migration script. Exit code: " << chmodResult << std::endl;
        return 1;
    }

    int migrationResult = system("bash ../scripts/migrate.sh");
    if (migrationResult != 0) {
        std::cerr << "Migration failed with exit code: " << migrationResult << std::endl;
        return 1;
    }
    std::cout << "Migrations completed successfully.\n";

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

    std::cout << "Server stopped.\n";
    return 0;
}