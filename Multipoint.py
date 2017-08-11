# plot their functions too

from scipy import misc

def multipoint(x0,count):

    x1=x0-(f(x0)/f(x0-(1/2)*(f(x0)/fprime(x0))))   
    print('f(x1),f(x0):{},{} and x1,x0:{},{}'.format(f(x1),f(x0),x1,x0))
    count+=1
    print('In the {} iteration, value of x{} is {}'.format(count,count,x1))
    if f(x1)==0:
    	print('Breaking out f({}) equals zero'.format(x1))
    	return x1
    
    elif abs(x1-x0)<0.0001:
    	print('Breaking out, {}-{} is less than 0.0001'.format(x1,x0))
    	return x1
    elif count>=15:
        print('Exiting')
        return x1
    else:
        return multipoint(x1,count)

def f(x):
	return x**3-4*x-9

def fdprime(j):  
    return misc.derivative(f,j,n=2)

def fprime(j):
    return misc.derivative(f,j,n=1)

def initial_approx(upper,lower):
    if abs(f(upper))<abs(f(lower)):
        return upper
    else:
        return lower

def main():
    upper=3
    lower=2
    count=0
    initial=initial_approx(upper,lower)
    print(initial)
    root=multipoint(initial,count)
    
   
if __name__ == '__main__':
	main()

