#include "CBT.h"

#include <FMath/FMath.h>

#include <cmath>
#include <iostream>

CBT::CBT(uint32_t maxDepth) 
    : m_values(std::pow(2, maxDepth + 1), 0)
    , m_numNodes(std::pow(2, maxDepth + 1))
{
    m_values[0] = maxDepth;
}

void CBT::PrintState()
{
    if (m_values[0] == 0) return;

    std::cout << "Sums: ";
    for (uint32_t idx = 0; idx < std::pow(2, m_values[0]); idx++)
    {
        std::cout << m_values[idx];
        std::cout << (idx == (std::pow(2, m_values[0]) - 1) ? "" : ":");
    }
    std::cout << std::endl;

    std::cout << "Bitfield: ";
    for (uint32_t idx = std::pow(2, m_values[0]); idx < (2 * std::pow(2, m_values[0])); idx++)
    {
        std::cout << m_values[idx];
        std::cout << (idx == (2 * std::pow(2, m_values[0]) - 1) ? "" : ":");
    }
    std::cout << std::endl;
}