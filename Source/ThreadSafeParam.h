/*
  ==============================================================================

    ThreadSafeParam.h
    Created: 2 Jun 2026 3:08:04pm
    Author:  Charlie Mayo

  ==============================================================================
*/

#pragma once
#include <atomic>

class ThreadSafeParam {
    std::atomic<float> param;
    
public:
    ThreadSafeParam(float initialValue = 0.0f) : param (initialValue) {}
    float get() const {
        return param.load(std::memory_order_relaxed);
    }
    
    void set(float x) {
        param.store(x, std::memory_order_relaxed);
    }
};
