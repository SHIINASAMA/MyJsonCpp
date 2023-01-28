# MyJsonCpp - 教学用途

## 要求

- 能够解析一般的 Json 对象
- 值类型只解析字符串
- 字符串不支持空白转义字符 \n \r

## 开发步骤

1. 描述数据结构
2. 分词
3. 解析分词（填充数据结构）

## 开发阶段测试

1

```json
{
  "kind": "git",
  "repository": "https://github.com/microsoft/vcpkg.git",
  "baseline": "e69dd972ba64840955f46704ecce6241bf607c0f"
}
```

2

```json
{
  "kind": "git",
  "repository": "https://github.com/libsese/vcpkg-registry.git",
  "baseline": "bab756fa7276653a1c48f7c7d873a9ce3a088ac1",
  "packages": [
    "simpleuuid",
    "sstring"
  ]
}
```

3

```json
{
  "default-registry": {
    "kind": "git",
    "repository": "https://github.com/microsoft/vcpkg.git",
    "baseline": "e69dd972ba64840955f46704ecce6241bf607c0f"
  },
  "registries": [
    {
      "kind": "git",
      "repository": "https://github.com/libsese/vcpkg-registry.git",
      "baseline": "bab756fa7276653a1c48f7c7d873a9ce3a088ac1",
      "packages": [
        "simpleuuid",
        "sstring"
      ]
    }
  ]
}

```