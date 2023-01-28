#include "json/Util.h"
#include <cstdio>

const std::string Buffer1 = "{\n"
                            "  \"default-registry\": {\n"
                            "    \"kind\": \"git\",\n"
                            "    \"repository\": \"https://github.com/microsoft/vcpkg.git\",\n"
                            "    \"baseline\": \"e69dd972ba64840955f46704ecce6241bf607c0f\"\n"
                            "  },\n"
                            "  \"registries\": [\n"
                            "    {\n"
                            "      \"kind\": \"git\",\n"
                            "      \"repository\": \"https://github.com/libsese/vcpkg-registry.git\",\n"
                            "      \"baseline\": \"bab756fa7276653a1c48f7c7d873a9ce3a088ac1\",\n"
                            "      \"packages\": [\n"
                            "        \"simpleuuid\",\n"
                            "        \"sstring\"\n"
                            "      ]\n"
                            "    }\n"
                            "  ]\n"
                            "}";

int main() {
//    auto tokens = makeTokens(Buffer1);
//    while(!tokens.empty()) {
//        puts(tokens.front().c_str());
//        tokens.pop();
//    }

    auto object = getJsonObjectFromBuffer(Buffer1);
    return 0;
}