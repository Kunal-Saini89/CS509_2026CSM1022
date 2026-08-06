main : GEMM_Simple.cpp GEMM_Blocking.cpp CSR_Implementation.cpp

gemm : 
	g++ GEMM.cpp -o GEMM_Simple
	./GEMM_Simple

	rm -f GEMM

csr :
	g++ CSR_Implementation.cpp -o CSR_Implementation
	./CSR_Implementation

	rm -f CSR_Implementation