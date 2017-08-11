

def secant(x1,x0,count):
    print('f(xi) is {}, and xi is {}'.format(f(x1),x1))
    print('f(xi-1) is {}, and xi-1 is {}'.format(f(x0),x0))
    x2=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1)
    count+=1
    print('In the {} iteration, value of x{} is {}'.format(count,count+1,x2))
    if f(x2)==0:
    	print('Breaking out f({}) equals zero'.format(x2))
    	return x2
    elif abs(x2-x1)<0.0001:
    	print('Breaking out, {}-{} is less than 0.0001'.format(x2,x1))
    	return x2
    else:
    	return(secant(x2,x1,count))






def f(x):
	return x**3-4*x-9



def main():
	upper=3
	lower=2
	count=0
	root=secant(upper,lower,count)
	print(root)


if __name__ == '__main__':
	main()