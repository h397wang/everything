template<typename ComplexT>
void dft(ComplexT* restrict y, ComplexT* restrict x, uint N) {
	for (int k = 0; k < N; k++) {
		ComplexT sum = 0;
		for (int i = 0; i < N; i++) {
			sum += x[i]*exp(-IMAG*2*PI*k*i/N);
		y[k] = sum;
	}
}




