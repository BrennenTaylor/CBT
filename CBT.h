#pragma once

#include <vector>
#include <cstdint>

struct CBT {
    std::vector<uint32_t> m_values;
    uint32_t m_numNodes;

    CBT(uint32_t maxDepth);
    
    void PrintState();

    uint32_t MaxDepth() {
        return m_values[0];
    }

    uint32_t NodeCount() {
        return m_values[1];
    }

    bool IsLeafNode(uint32_t heapIdx) {
        return (m_values[heapIdx] == 1);
    }
};