#include "json/Type.h"

#include <queue>

std::shared_ptr<ObjectType> getJsonObjectFromBuffer(const std::string &buffer);

std::queue<std::string> makeTokens(const std::string &buffer);

std::shared_ptr<ObjectType> makeObject(std::queue<std::string> &tokens);