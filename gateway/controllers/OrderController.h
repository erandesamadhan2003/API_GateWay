#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class OrderContoller : public drogon::HttpController<OrderContoller> {
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(OrderContoller::getOrders, "/api/orders", drogon::Get);
    ADD_METHOD_TO(OrderContoller::createOrder, "/api/orders", drogon::Post);
    METHOD_LIST_END

    void getOrders(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void createOrder(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};
