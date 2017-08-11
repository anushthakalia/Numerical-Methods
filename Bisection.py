
 def bisection(upper,m,lower,count):
	count+=1
	print('The iteration is :{} and the value of m is {} and upper-lower is {}'.format(count,m,(upper-lower)))
	
	if count>20:
		print('Breaking out')
		return m
	if f(m)==0:
		print('Breaking out')
		return m
	elif (upper-lower)<0.0001:
		print('Breaking out')
		return m

	elif f(lower)*f(m)<0:
		return bisection(m,(m+lower)/2,lower,count)

	elif f(upper)*f(m)<0:
		return bisection(upper,(m+upper)/2,m,count)
    


def f(x):
	return x**3-4*x-9

def main():
	upper=3
	lower=2
	m=(upper+lower)/2
	root=0
	count=0
	root=bisection(upper,m,lower,count)
	print('The final value of m is: {}'.format(root))
	

if __name__ == '__main__':
	main()