#include "HealthCheckController.h"

void HealthCheckController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string timeStr = std::ctime(&now);
    
    Json::Value json;
    json["success"] = true;
    json["message"] = "API Gateway is healthy";
    json["timestamp"] = timeStr.substr(0, timeStr.length() - 1); 

    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_APPLICATION_JSON);
    resp->setBody(json.toStyledString());
    callback(resp);
}
