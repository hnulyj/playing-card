#pragma once

#include <algorithm>
#include <vector>

/**
 * @brief Vector通用工具类。
 */
class VectorUtils {
public:
    /**
     * @brief 从vector移除指定值。
     * @tparam T 元素类型。
     * @param values 容器。
     * @param value 待删除值。
     */
    template <typename T>
    static void removeValue(std::vector<T>& values, const T& value) {
        values.erase(std::remove(values.begin(), values.end(), value), values.end());
    }
};
