inline double Complex::real() const
{
	return re_;
}

inline double Complex::imag() const
{
	return im_;
}

inline void Complex::real(double re)
{
	re_ = re;
}

inline void Complex::imag(double im)
{
	im_ = im;
}
