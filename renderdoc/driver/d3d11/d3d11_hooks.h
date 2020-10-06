#pragma once

#include <functional>
#include "driver/dxgi/dxgi_wrapped.h"
#include "d3d11_device.h"

// this is the type of the lambda we use to route the call out to the 'real' function inside our
// generic wrapper.
// Could be any of D3D11CreateDevice, D3D11CreateDeviceAndSwapChain, or the nvapi equivalents
typedef std::function<HRESULT(IDXGIAdapter *, D3D_DRIVER_TYPE, HMODULE, UINT, CONST D3D_FEATURE_LEVEL *,
                              UINT FeatureLevels, UINT, CONST DXGI_SWAP_CHAIN_DESC *, IDXGISwapChain **,
                              ID3D11Device **, D3D_FEATURE_LEVEL *, ID3D11DeviceContext **)>
    RealD3D11CreateFunction;

HRESULT CreateD3D11_Internal(RealD3D11CreateFunction real, __in_opt IDXGIAdapter *pAdapter,
                             D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags,
                             __in_ecount_opt(FeatureLevels) CONST D3D_FEATURE_LEVEL *pFeatureLevels,
                             UINT FeatureLevels, UINT SDKVersion,
                             __in_opt CONST DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
                             __out_opt IDXGISwapChain **ppSwapChain,
                             __out_opt ID3D11Device **ppDevice,
                             __out_opt D3D_FEATURE_LEVEL *pFeatureLevel,
                             __out_opt ID3D11DeviceContext **ppImmediateContext);
