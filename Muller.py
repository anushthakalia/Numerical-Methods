from math import sqrt

def muller(x2,x1,x0,count):
	
	a=a0(x2,x1,x0)
	b=a1(x2,x1,x0)
	c=a2(x2)
	print(b**2-4*a*c)
	x3a=x2-((2*c)/(b+ sqrt(b**2-4*a*c)))
	x3b=x2-((2*c)/(b- sqrt(b**2-4*a*c)))

	if abs(f(x3a))<abs(f(x3b)):
		approx=x3a
	else:
		approx=x3b

	count+=1
	print('In the {} iteration, value of x{} is {}'.format(count,count+2,approx))
	if f(approx)==0:
		print('Breaking out f({}) equals zero'.format(approx))
		return approx

	elif abs(approx-x2)<0.0001:
		print('Breaking out, {}-{} is less than 0.0001'.format(approx,x2))
		return approx
	elif count>=15:
		print('Exiting')
		return approx
	else:
		return muller(approx,x2,x1,count)


def f(x):
	return x**3-13*x-12

def a2(x2):
	return f(x2)

def a1(x2,x1,x0):
	D=(x1-x2)*(x0-x2)*(x1-x0)
	return (1/D)*(((x2-x0)**2)*(f(x2)-f(x1))-((x2-x1)**2)*(f(x2)-f(x0)))

def a0(x2,x1,x0):
	D=(x1-x2)*(x0-x2)*(x1-x0)
	return (1/D)*((x2-x0)*(f(x2)-f(x1))-(x2-x1)*(f(x2)-f(x0)))

def main():
    
    count=0
    root=muller(5,5.5,4.5,count)
    
   
if __name__ == '__main__':
	main()