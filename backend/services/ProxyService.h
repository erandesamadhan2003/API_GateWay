#pragma once 

#include <drogon/drogon.h>
#include <string>

class ProxyService {
public: 
    static void forwardRequest(const drogon::HttpRequestPtr& req, const std::string& targetBase, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
};