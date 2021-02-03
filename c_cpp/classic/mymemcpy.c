// 考察，void* 各种类型都支持，const 表示不修改 src
// 第一版代码有问题
// 问题1：内存重叠问题，情况1 dst > 且覆盖 src
// 情况2 src > dst 且覆盖 dst
void mymemcpy(void* dst, const void* src，size_t num) {
    assert((dst != nullptr) && (src != nullptr));
    const char* psrc = (const char*)src;
    char* pdst = (char*)dst;
    while (num-- > 0) {
        *pdst++ = *psrc++;
    }
    // 上述代码有问题
}

// 正确代码处理两种重叠
// 情况1：               情况2：
//     ===dst===            ===dst===
// ===src===(src+num 尾端)     ===src===
void mymemcpy(void* dst, const void* src, size_t num) {
    assert((dst != nullptr) && src != nullptr);

    const char* psrc = (const char*)src;
    char* pdst = (char*)dst;

    if (pdst > psrc && pdst < psrc + num) {
        // dst > 且覆盖src后一段，从后向前复制
        for (size_t i = num - 1; i != -1; i--) {
            pdst[i] = psrc[i];
        }
    } else {
        // dst < src ，及其它情况从前面复制即可
        for (size_t i = 0; i < num; i++) {
            pdst[i] = psrc[i];
        }
    }
}

// 如何优化这个算法，一次拷贝的内容增多
// 只演示从前向后拷贝，从后向前拷贝待补充
void mymemcpy(void* dst, const void* src, size_t num) {
    assert((dst != nullptr) && src != nullptr);

    int wordNum = num / 4;
    int slice = num % 4;
    const int* pintsrc = (const int*)src;
    int* pintdst = (int*)dst;

    // copy 4 bytes
    while (wordNum--) {
        *pintdst++ = *pintsrc++;
    }

    // copy one byte
    const char* pcharsrc = (const char*)pintsrc;
    char* pchardst = (char*)pintdst;
    
    while (slice--) {
        *pchardst++ = *pcharsrc++;
    }
}
