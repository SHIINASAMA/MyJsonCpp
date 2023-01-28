#include "json/Util.h"
#include <cstdio>

const std::string Buffer1 = "{\n"
                            "  \"kind\": \"git\",\n"
                            "  \"repository\": \"https://github.com/microsoft/vcpkg.git\",\n"
                            "  \"baseline\": \"e69dd972ba64840955f46704ecce6241bf607c0f\"\n"
                            "}";

int main() {
    auto object = getJsonObjectFromBuffer(Buffer1);

    std::shared_ptr<BasicType> data =  object->get("baseline");
    std::shared_ptr<ValueType> valueData = std::dynamic_pointer_cast<ValueType>(data);
    printf("baseline = %s\n", valueData->getValue().c_str());

    return 0;
}