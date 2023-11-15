This kernel has four major sections. First, an offset is computed for the chunk of data that belongs
to this thread block, relative to the global input:
int *idata = g_idata + blockIdx.x * blockDim.x;
Next, the kernel performs an in-place reduction using global memory into 32 elements:
// in-place reduction in global memory
if (blockDim.x >= 1024 && tid < 512) idata[tid] += idata[tid + 512];
__syncthreads();
if (blockDim.x >= 512 && tid < 256) idata[tid] += idata[tid + 256];
__syncthreads();
if (blockDim.x >= 256 && tid < 128) idata[tid] += idata[tid + 128];
__syncthreads();
if (blockDim.x >= 128 && tid < 64) idata[tid] += idata[tid + 64];
__syncthreads();
Then, the kernel performs an in-place reduction using only the first warp of each thread block.
Note in the loop unrolling section, the use of a volatile qualifi er is used to ensure that as the warp
executes in lock step, only the latest values are read.
volatile int *vsmem = idata;
vsmem[tid] += vsmem[tid + 32];
vsmem[tid] += vsmem[tid + 16];
vsmem[tid] += vsmem[tid + 8];
vsmem[tid] += vsmem[tid + 4];
