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
            case '[':
            case ']':
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

        if (tokens.front() == "[") {
            tokens.pop();
            auto array = makeArray(tokens);
            result->set(key, array);
        } else if (tokens.front() == "{") {
            tokens.pop();
            auto object = makeObject(tokens);
            result->set(key, object);
        } else {
            auto value = tokens.front();
            tokens.pop(); // value
            auto valueType = std::make_shared<ValueType>();
            valueType->setValue(value);
            result->set(key, valueType);
        }

        if (tokens.front() == "}") {
            tokens.pop();
            break;
        } else {
            tokens.pop();
        }
    }

    return result;
}

std::shared_ptr<ArrayType> makeArray(std::queue<std::string> &tokens) {
    auto result = std::make_shared<ArrayType>();

    while (true) {
        if (tokens.front() == "[") {
            tokens.pop();
            auto array = makeArray(tokens);
            result->push(array);
        } else if (tokens.front() == "{") {
            tokens.pop();
            auto object = makeObject(tokens);
            result->push(object);
        } else {
            auto valueData = std::make_shared<ValueType>();
            valueData->setValue(tokens.front());
            result->push(valueData);
            tokens.pop();
        }

        if (tokens.front() == "]") {
            tokens.pop();
            break;
        } else {
            tokens.pop();
        }
    }

    return result;
}