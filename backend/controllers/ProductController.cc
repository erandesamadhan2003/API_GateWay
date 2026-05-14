#include "ProductController.h"
#include "../services/ProxyService.h"

void ProductController::getProducts(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    ProxyService::forwardRequest(req, "http://localhost:3002", std::move(callback));
}

void ProductController::getProductById(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, int productId) {
    ProxyService::forwardRequest(req, "http://localhost:3002", std::move(callback));
}

void ProductController::createProduct(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    ProxyService::forwardRequest(req, "http://localhost:3002", std::move(callback));
}

void ProductController::updateProduct(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, int productId) {
    ProxyService::forwardRequest(req, "http://localhost:3002", std::move(callback));
}

void ProductController::deleteProduct(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, int productId) {
    ProxyService::forwardRequest(req, "http://localhost:3002", std::move(callback));
}