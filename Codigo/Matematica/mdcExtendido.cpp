int mdce(int a, int b, int *x, int *y){
	if(!a){
		*x = 0;
		*y = 1;
		return b;
	}

	int X, Y;
	int mdc = mdce(b%a, a, &X, &Y);
	*x = Y - (b/a)*X;
	*y = X;

	return mdc;
}