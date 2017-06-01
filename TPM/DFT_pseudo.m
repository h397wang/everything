


dft(y, x, N)
	for k = 0 to N-1
		sum = 0;
		for i = 0 to N-1
			sum += x[i]*exp(-2*pi*j*k*i/N)
		y[k] = floatingSum
