#include <string>
#include <map>
#include <list>
#include <memory>
#include <utility>

enum class Type {
    Value,
    Object,
    Array
};

// 基础类型，所有的值类型都从这里派生
class BasicType {
public:
    explicit BasicType(Type type) {
        this->type = type;
    }

    virtual ~BasicType() = default;

    Type getType() const { return type; }

protected:
    Type type;
};

class ValueType : public BasicType {
public:
    ValueType() : BasicType(Type::Value) {
    }

    const std::string &getValue() const {
        return value;
    }

    void setValue(const std::string &v) {
        ValueType::value = v;
    }

private:
    std::string value;
};

class ObjectType : public BasicType {
public:
    ObjectType() : BasicType(Type::Object) {
    }

    std::shared_ptr<BasicType> get(const std::string &key) {
        auto iterator = map.find(key);
        if (iterator != map.end()) {
            return iterator->second;
        } else {
            return nullptr;
        }
    }

    void set(const std::string &key, std::shared_ptr<BasicType> value) {
        map[key] = std::move(value);
    }

private:
    std::map<std::string, std::shared_ptr<BasicType>> map;
};

class ArrayType : public BasicType {
public:
    ArrayType() : BasicType(Type::Array) {
    }

    [[nodiscard]] inline size_t size() const noexcept { return list.size(); }
    [[nodiscard]] inline bool empty() const noexcept { return list.empty(); }
    void push(const std::shared_ptr<BasicType> &data) noexcept { list.emplace_back(data); }
    inline std::list<std::shared_ptr<BasicType>>::iterator begin() noexcept { return list.begin(); }
    inline std::list<std::shared_ptr<BasicType>>::iterator end() noexcept { return list.end(); }

private:
    std::list<std::shared_ptr<BasicType>> list;
};