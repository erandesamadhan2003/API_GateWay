#include "./ProxyService.h"

void ProxyService::forwardRequest(const drogon::HttpRequestPtr &req, const std::string &targetBase, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    auto client = drogon::HttpClient::newHttpClient(targetBase);
    auto forwardReq = drogon::HttpRequest::newHttpRequest();

    forwardReq->setMethod(req->getMethod());
    forwardReq->setPath(req->getPath());
    forwardReq->setBody(std::string(req->getBody()));

    for (const auto& [key, value] : req->getHeaders()) 
        forwardReq->addHeader(key, value);

    client->sendRequest(forwardReq, [callback = std::move(callback)](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        if(result == drogon::ReqResult::Ok) {
            callback(response);
        } else {
            Json::Value err;
            err["success"] = false;
            err["message"] = "Upstream service unavailable";

            auto errorResp = drogon::HttpResponse::newHttpJsonResponse(err);
            errorResp->setStatusCode(drogon::k503ServiceUnavailable);

            callback(errorResp);
        } 
    });
    
}