#include "json/Util.h"

std::shared_ptr<ObjectType> getJsonObjectFromBuffer(const std::string &buffer) {
    auto tokens = makeTokens(buffer);

    // pop '{'
    tokens.pop();
    auto object = makeObject(tokens);

    return object;
}

std::queue<std::string> makeTokens(const std::string &buffer) {
    std::queue<std::string> tokens;

    size_t len = buffer.length();
    for (int j = 0; j < len; j++) {
        switch (buffer[j]) {
            case '{':
            case '}':
            case ':':
            case ',':
                tokens.push({buffer[j]});
                break;
            case '"':
                j++;
                int i = 0;
                while (true) {
                    if (buffer[j + i] != '"') {
                        i++;
                        continue;
                    } else {
                        tokens.push(buffer.substr(j, i));
                        j += i;
                        break;
                    }
                }
                break;
        }
    }

    return tokens;
}

std::shared_ptr<ObjectType> makeObject(std::queue<std::string> &tokens) {
    auto result = std::make_shared<ObjectType>();

    while (true) {
        auto key = tokens.front();
        tokens.pop(); // key
        tokens.pop(); // :
        auto value = tokens.front();
        tokens.pop(); // value

        auto valueType = std::make_shared<ValueType>();
        valueType->setValue(value);
        result->set(key, valueType);

        if (tokens.front() == "}") {
            break;
        }
        tokens.pop();
    }

    return result;
}