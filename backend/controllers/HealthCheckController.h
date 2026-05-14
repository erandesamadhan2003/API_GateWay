#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class HealthCheckController : public drogon::HttpSimpleController<HealthCheckController> {
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/api/health", Get);
    PATH_LIST_END
};
