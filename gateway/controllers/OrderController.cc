#include "OrderController.h"
#include "../services/ProxyService.h"

void OrderContoller::getOrders(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    ProxyService::forwardRequest(req, "http://localhost:3003", std::move(callback));
}

void OrderContoller::createOrder(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    ProxyService::forwardRequest(req, "http://localhost:3003", std::move(callback));
}