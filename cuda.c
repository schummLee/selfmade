#include <cuda_runtime.h>
#include <stdio.h>

void sumArraysOnHost(float *A, float *B, float *C, const int N)
{
	for (size_t i = 0; i < N; i++)
		C[i] = A[i] + B[i];
}

__global__ void sumArraysOnGPU(float *A, float *B, float *C) 
{
	int i = threadIdx.x;
	C[i] = A[i] + B[i];
}

#define CHECK(call) \
{ \
	const cudaError_t error = call; \
	if (error != cudaSuccess) \
	{ \
	printf("Error: %s:%d, ", __FILE__, __LINE__); \
	printf("code:%d, reason: %s\n", error, cudaGetErrorString(error)); \
	exit(1); \
	}	 \
}

__global__ void sumArraysOnGPU(float *A, float *B, float *C) 
{
	int i = threadIdx.x;
	C[i] = A[i] + B[i];
}

double cpuSecond() 
{
	struct timeval tp;
	gettimeofday(&tp,NULL);
	return ((double)tp.tv_sec + (double)tp.tv_usec*1.e-6);
}

__global__ void matrix_vector_product(float *A, float *v1, float *v2, size_t matrix_size)
{
	int row = blockIdx.x * blockDim.x + threadIdx.x;
	int col = blockIdx.y * blockDim.y + threadIdx.y;

	if (col == 0 && row < (int)martrix_size) 
	{
		float sum = 0.0f;
		for(int i = 0; i < (int)matrix_size; i++)
		{
			sum += A[row * matrix_size + i] * v1[i];
		}
	}
}

__global__ void sumMatrixOnGPU1D(float *MatA, float *MatB, float *MatC, int nx, int ny) 
{
	unsigned int ix = threadIdx.x + blockIdx.x * blockDim.x;
	if (ix < nx ) 
	{
		for (int iy=0; iy<ny; iy++) 
		{
			int idx = iy*nx + ix;
			MatC[idx] = MatA[idx] + MatB[idx];
		}
	}
}

// using dim3

__global__ void sumMatrixOnGPUMix(float *MatA, float *MatB, float *MatC, int nx, int ny) 
{
	unsigned int ix = threadIdx.x + blockIdx.x * blockDim.x;
	unsigned int iy = blockIdx.y;
	unsigned int idx = iy*nx + ix;
	if (ix < nx && iy < ny) MatC[idx] = MatA[idx] + MatB[idx];
}


