#include <iostream>

#include "CBT.h"

#include <FMath/FMath.h>

#include <cstdint>
#include <vector>

int main()
{
    CBT m_terrainCBT(4);
    m_terrainCBT.PrintState();
    std::cout << std::endl;

    Farlor::Matrix3x3 m0(
        Farlor::Vector3(1.0f, 0.0f, 0.0f),
        Farlor::Vector3(0.5f, 0.0f, 0.5f),
        Farlor::Vector3(0.0f, 1.0f, 0.0f)
    );

    Farlor::Matrix3x3 m1(
        Farlor::Vector3(0.0f, 1.0f, 0.0f),
        Farlor::Vector3(0.5f, 0.0f, 0.5f),
        Farlor::Vector3(0.0f, 0.0f, 1.0f)
    );

    Farlor::Matrix3x3 triangle1(
        Farlor::Vector3(0.0f, 1.0f, 0.0f),
        Farlor::Vector3(0.0f, 0.0f, 0.0f),
        Farlor::Vector3(1.0f, 0.0f, 0.0f)
    );


    const uint32_t Depth = 5;
    const uint32_t NumElements = std::pow(2, Depth + 1);
    std::vector<Farlor::Matrix3x3> values(NumElements);
    values[0] = Farlor::Matrix3x3::s_Identity;
    values[1] = triangle1;

    for (uint32_t idx = 2; idx < NumElements; idx += 2)
    {
        values[idx] = m0 * values[idx / 2];
        values[idx + 1] = m1 * values[idx / 2];
    }

    for (uint32_t idx = 1; idx < NumElements; idx++)
    {
        std::cout << "Triangle " << idx << ": " << std::endl;
        std::cout << values[idx].m_rows[0] << "\n" << values[idx].m_rows[1] << "\n" << values[idx].m_rows[2] << std::endl;
        std::cout << std::endl;
    }
}