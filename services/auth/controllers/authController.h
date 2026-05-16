#pragma once

#include <drogon/HttpController.h>


class authController : public drogon::HttpController<authController> {
public:
    METHOD_LIST_BEGIN
    
    ADD_METHOD_TO(authController::login, "/api/auth/login", drogon::Post);
    ADD_METHOD_TO(authController::registerUser, "/api/auth/register", drogon::Post);
    ADD_METHOD_TO(authController::getProfile, "/api/auth/profile", drogon::Get);

    METHOD_LIST_END
    void login(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
    void registerUser(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
    void getProfile(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
};
