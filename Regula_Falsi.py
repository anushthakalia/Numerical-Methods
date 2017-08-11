

def falsi(x1,x0,count):

    x2=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1)
    print(x2)
    print('f(x2),f(x1),f(x0):{},{},{} and x2,x1,x0:{},{},{}'.format(f(x2),f(x1),f(x0),x2,x1,x0))
    count+=1
    print('In the {} iteration, value of x{} is {}'.format(count,count+1,x2))
    if f(x2)==0:
    	print('Breaking out f({}) equals zero'.format(x2))
    	return x2
    
    elif abs(x2-x1)<0.0001:
    	print('Breaking out, {}-{} is less than 0.0001'.format(x2,x1))
    	return x2
    elif f(x2)*f(x1)<0:
    	return(falsi(x2,x1,count))
    elif f(x2)*f(x0)<0:
        return(falsi(x2,x0,count))






def f(x):
	return x**3-4*x-9



def main():
	upper=3
	lower=2
	count=0
	root=falsi(upper,lower,count)
	print(root)


if __name__ == '__main__':
	main()