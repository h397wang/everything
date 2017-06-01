template<typename ComplexT>
void fft(ComplexT* x, uint N) {
	reorder(x, N);
	uint numStages = log2(N);
	for (uint stage = 0; stage < numStages; stage++) {
		uint numUniqueTwiddles = N >> (numStages - stage);
		uint numFftsThisStage = N >> stage;
		
		for (uint twiddleCount = 0; twiddleCount < numUniqueTwiddles; twiddleCount++) {
			uint twiddleIndex = numFftsThisStage*numUniqueTwiddles;
			ComplexT twiddleFactor = getTwiddleFactor(twiddleIndex);
			for (uint fftIndex = 0; fftIndex < numFftsThisStage; fftIndex++) {
				uint evenIndex = 2*twiddleCount*fftIndex + twiddleCount;
				uint oddIndex = evenIndex + numUniqueTwiddles;
				butterfly(&x[evenIndex], &x[oddIndex], twiddleFactor);
			} 
		}
	}
}

void fft(ComplexT* x, uint N) {
	reorder(x, N);
	
	
}


